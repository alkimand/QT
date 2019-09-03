/*
  curlx.c  Authors: Peter Sylvester, Jean-Paul Merlin

  This is a little program to demonstrate the usage of

  - an ssl initialisation callback setting a user key and trustbases
  coming from a pkcs12 file
  - using an ssl application callback to find a URI in the
  certificate presented during ssl session establishment.

*/
/* <DESC>
 * demonstrates use of SSL context callback, requires OpenSSL
 * </DESC>
 */

/*
 * Copyright (c) 2003 The OpenEvidence Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions, the following disclaimer,
 *    and the original OpenSSL and SSLeay Licences below.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions, the following disclaimer
 *    and the original OpenSSL and SSLeay Licences below in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgments:
 *    "This product includes software developed by the Openevidence Project
 *    for use in the OpenEvidence Toolkit. (http://www.openevidence.org/)"
 *    This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (https://www.openssl.org/)"
 *    This product includes cryptographic software written by Eric Young
 *    (eay@cryptsoft.com).  This product includes software written by Tim
 *    Hudson (tjh@cryptsoft.com)."
 *
 * 4. The names "OpenEvidence Toolkit" and "OpenEvidence Project" must not be
 *    used to endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    openevidence-core@openevidence.org.
 *
 * 5. Products derived from this software may not be called "OpenEvidence"
 *    nor may "OpenEvidence" appear in their names without prior written
 *    permission of the OpenEvidence Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgments:
 *    "This product includes software developed by the OpenEvidence Project
 *    for use in the OpenEvidence Toolkit (http://www.openevidence.org/)
 *    This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (https://www.openssl.org/)"
 *    This product includes cryptographic software written by Eric Young
 *    (eay@cryptsoft.com).  This product includes software written by Tim
 *    Hudson (tjh@cryptsoft.com)."
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenEvidence PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenEvidence PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes software developed by the OpenSSL Project
 * for use in the OpenSSL Toolkit (https://www.openssl.org/)
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <openssl/x509v3.h>
#include <openssl/x509_vfy.h>
#include <openssl/crypto.h>
#include <openssl/lhash.h>
#include <openssl/objects.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/pkcs12.h>
#include <openssl/bio.h>
#include <openssl/ssl.h>

static const char *curlx_usage[]={
  "usage: curlx args\n",
  " -p12 arg         - tia  file ",
  " -envpass arg     - environment variable which content the tia private"
  " key password",
  " -out arg         - output file (response)- default stdout",
  " -in arg          - input file (request)- default stdin",
  " -connect arg     - URL of the server for the connection ex:"
  " www.openevidence.org",
  " -mimetype arg    - MIME type for data in ex : application/timestamp-query"
  " or application/dvcs -default application/timestamp-query",
  " -acceptmime arg  - MIME type acceptable for the response ex : "
  "application/timestamp-response or application/dvcs -default none",
  " -accesstype arg  - an Object identifier in an AIA/SIA method, e.g."
  " AD_DVCS or ad_timestamping",
  NULL
};

/*

./curlx -p12 psy.p12 -envpass XX -in request -verbose -accesstype AD_DVCS
-mimetype application/dvcs -acceptmime application/dvcs -out response

*/

/*
 * We use this ZERO_NULL to avoid picky compiler warnings,
 * when assigning a NULL pointer to a function pointer var.
 */

#define ZERO_NULL 0

/* This is a context that we pass to all callbacks */

typedef struct sslctxparm_st {
  unsigned char *p12file;
  const char *pst;
  PKCS12 *p12;
  EVP_PKEY *pkey;
  X509 *usercert;
  STACK_OF(X509) * ca;
  CURL *curl;
  BIO *errorbio;
  int accesstype;
  int verbose;

} sslctxparm;

/* some helper function. */

static char *ia5string(ASN1_IA5STRING *ia5)
{
  char *tmp;
  if(!ia5 || !ia5->length)
    return NULL;
  tmp = OPENSSL_malloc(ia5->length + 1);
  memcpy(tmp, ia5->data, ia5->length);
  tmp[ia5->length] = 0;
  return tmp;
}

/* A convenience routine to get an access URI. */
static unsigned char *my_get_ext(X509 *cert, const int type,
                                 int extensiontype)
{
  int i;
  STACK_OF(ACCESS_DESCRIPTION) * accessinfo;
  accessinfo =  X509_get_ext_d2i(cert, extensiontype, NULL, NULL);

  if(!sk_ACCESS_DESCRIPTION_num(accessinfo))
    return NULL;
  for(i = 0; i < sk_ACCESS_DESCRIPTION_num(accessinfo); i++) {
    ACCESS_DESCRIPTION * ad = sk_ACCESS_DESCRIPTION_value(accessinfo, i);
    if(OBJ_obj2nid(ad->method) == type) {
      if(ad->location->type == GEN_URI) {
        return ia5string(ad->location->d.ia5);
      }
      return NULL;
    }
  }
  return NULL;
}

/* This is an application verification call back, it does not
   perform any addition verification but tries to find a URL
   in the presented certificate. If found, this will become
   the URL to be used in the POST.
*/

static int ssl_app_verify_callback(X509_STORE_CTX *ctx, void *arg)
{
  sslctxparm * p = (sslctxparm *) arg;
  int ok;

  if(p->verbose > 2)
    BIO_printf(p->errorbio, "entering ssl_app_verify_callback\n");

  ok = X509_verify_cert(ctx);
  if(ok && ctx->cert) {
    unsigned char *accessinfo;
    if(p->verbose > 1)
      X509_print_ex(p->errorbio, ctx->cert, 0, 0);

    accessinfo = my_get_ext(ctx->cert, p->accesstype, NID_sinfo_access);
    if(accessinfo) {
      if(p->verbose)
        BIO_printf(p->errorbio, "Setting URL from SIA to: %s\n", accessinfo);

      curl_easy_setopt(p->curl, CURLOPT_URL, accessinfo);
    }
    else if(accessinfo = my_get_ext(ctx->cert, p->accesstype,
                                    NID_info_access)) {
      if(p->verbose)
        BIO_printf(p->errorbio, "Setting URL from AIA to: %s\n", accessinfo);

      curl_easy_setopt(p->curl, CURLOPT_URL, accessinfo);
    }
  }
  if(p->verbose > 2)
    BIO_printf(p->errorbio, "leaving ssl_app_verify_callback with %d\n", ok);

  return ok;
}


/* The SSL initialisation callback. The callback sets:
   - a private key and certificate
   - a trusted ca certificate
   - a preferred cipherlist
   - an application verification callback (the function above)
*/

static CURLcode sslctxfun(CURL *curl, void *sslctx, void *parm)
{
  sslctxparm *p = (sslctxparm *) parm;
  SSL_CTX *ctx = (SSL_CTX *) sslctx;

  if(!SSL_CTX_use_certificate(ctx, p->usercert)) {
    BIO_printf(p->errorbio, "SSL_CTX_use_certificate problem\n");
    goto err;
  }
  if(!SSL_CTX_use_PrivateKey(ctx, p->pkey)) {
    BIO_printf(p->errorbio, "SSL_CTX_use_PrivateKey\n");
    goto err;
  }

  if(!SSL_CTX_check_private_key(ctx)) {
    BIO_printf(p->errorbio, "SSL_CTX_check_private_key\n");
    goto err;
  }

  SSL_CTX_set_quiet_shutdown(ctx, 1);
  SSL_CTX_set_cipher_list(ctx, "RC4-MD5");
  SSL_CTX_set_mode(ctx, SSL_MODE_AUTO_RETRY);

  X509_STORE_add_cert(SSL_CTX_get_cert_store(ctx),
                      sk_X509_value(p->ca, sk_X509_num(p->ca)-1));

  SSL_CTX_set_verify_depth(ctx, 2);
  SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, ZERO_NULL);
  SSL_CTX_set_cert_verify_callback(ctx, ssl_app_verify_callback, parm);

  return CURLE_OK;
  err:
  ERR_print_errors(p->errorbio);
  return CURLE_SSL_CERTPROBLEM;

}

