//lite_gamma.h
#ifndef COMMON_LITE_GAMMA_H
#define COMMON_LITE_GAMMA_H

#include <fcntl.h>
#include <cstring>
#include <stdlib.h>


namespace lite_gamma {

#define DEFAULT_WP "t h $V jk $#  fFF_78 M#!~  f l j;kl oem0xFFA345 "

//unsigned int aul = 60976; // authentification file length
//unsigned int aup = 986; // authentification data pos (in file)
//char *FNF_MSG = "File not found\r\n";

/*!
 * \fn  inline void ec(void *pData, size_t nBytes, const char *wp, char ca = 0)
 * \brief   Encrypt.
 * \param [in,out]  pData   The data.
 * \param   nBytes          Number of bytes to encrypt.
 * \param   wp              The password.
 * \param   ca              The algorithm.
 */
inline void ec(void *pData, size_t nBytes, const char *wp, char ca = 0) {
    if (pData == nullptr || nBytes == 0)
        return;

    char *awp; // actual pw
    size_t nawp, // pw length
        i1;
    size_t wp_len = strlen(wp),
        default_wp_len = strlen(DEFAULT_WP);
    nawp = (default_wp_len < wp_len) ? wp_len : default_wp_len;
    awp = new char[nawp + 1];
    memset(awp, 0, nawp - 1);
#pragma warning(push)
#pragma warning(disable: 4995)
    strcpy(awp, DEFAULT_WP);
#pragma warning(pop)


    if (*wp != 0) {
        if (strcmp(wp, DEFAULT_WP) != 0) {
            int nStepBy = 1;
            if ((default_wp_len / wp_len) > 1)
                nStepBy = 2;
            int nDWpPos = 0;
            for (size_t i = 0; i < wp_len; i++) {
                *(awp + nDWpPos) ^= *(wp + i);
                nDWpPos += nStepBy;
            }
        }
    }
    char *x = (char*)pData;
    switch (ca) {
    case 0:
        ec(x, nBytes, awp, 1);
        ec(x, nBytes, awp, 2);
        ec(x, nBytes, awp, 3);
        break;
    case 1:
        i1 = 0;
        *x = (char)~*x;
        for (unsigned long i = 1; i < nBytes; i++) {
            *(x + i) = *(x + i) ^ * (x + i - 1);
            *(x + i) = *(x + i) ^ * (awp + i1);
            if (i1 < nawp - 1)
                i1++;
            else
                i1 = 0;
        }
        break;
    case 2:
        char c1;
        for (unsigned long i = 8; i < nBytes; i++) {
            *(x + i) = *(x + i) ^ *(x + i - 7);
            c1 = *(x + i - 2);
            *(x + i - 2) = *(x + i - 7);
            *(x + i - 7) = c1;
        }
        break;
    case 3:
        for (unsigned long i = 2; i < nBytes; i++)
            if ((i^nawp) % 2)
                *(x + i) = *(x + i) ^ *(awp + i % nawp);
            else
                *(x + i) = (char)~*(x + i);
    }
    delete[] awp;
}


inline void dc(
                void *pData,
                size_t nBytes,
                const char *wp,
                char ca = 0) {
    if (pData == nullptr || nBytes == 0)
        return;

    char *awp; // actual pw
    size_t nawp; // pw length
    size_t i1;

    size_t wp_len = strlen(wp);
    size_t default_wp_len = strlen(DEFAULT_WP);
    nawp = (default_wp_len < wp_len) ? wp_len : default_wp_len;
    awp = new char[nawp + 1];
    memset(awp, 0, nawp - 1);
#pragma warning(push)
#pragma warning(disable: 4995)
    strcpy(awp, DEFAULT_WP);
#pragma warning(pop)

    if (*wp != 0) {
        if (strcmp(wp, DEFAULT_WP) != 0) {
            int nStepBy = 1;
            if ((default_wp_len / wp_len) > 1)
                nStepBy = 2;
            int nDWpPos = 0;
            for (size_t i = 0; i < wp_len; ++i) {
                *(awp + nDWpPos) ^= *(wp + i);
                nDWpPos += nStepBy;
            }
        }
    }

    char *x = (char*)pData;
    switch (ca) {
    case 0:
        dc(x, nBytes, awp, 3);
        dc(x, nBytes, awp, 2);
        dc(x, nBytes, awp, 1);
        break;
    case 1:
        if ((nBytes - 1) % (nawp) != 0)
            i1 = (nBytes - 1) % (nawp)-1;
        else
            i1 = nawp - 1;
        for (size_t i = nBytes; i > 1; --i) {
            *(x + i - 1) = *(x + i - 1) ^ *(awp + i1);
            *(x + i - 1) = *(x + i - 1) ^ *(x + i - 1 - 1);
            if (i1 > 0)
                i1--;
            else
                i1 = nawp - 1;
        }
        *x = (char)~*x;
        break;
    case 2:
        char c1;
        for (size_t i = nBytes - 1; i > 7; --i) {
            c1 = *(x + i - 7);
            *(x + i - 7) = *(x + i - 2);
            *(x + i - 2) = c1;
            *(x + i) = *(x + i) ^ *(x + i - 7);
        }
        break;
    case 3:
        for (size_t i = nBytes; i > 2; --i)
            if (((i - 1) ^ nawp) % 2)
                *(x + i - 1) = *(x + i - 1) ^ * (awp + (i - 1) % nawp);
            else
                *(x + i - 1) = (char)~*(x + i - 1);
    }
    delete[] awp;
}

}

#endif //COMMON_LITE_GAMMA_H
