#ifndef UI_COMMON_STR_QS_UTILS_H
#define UI_COMMON_STR_QS_UTILS_H

#include <QTime>

//#include "../../../modules/core_lib/include/str_conv.h"
#include <qstring.h>

#define SS2Q(x) (QString::fromUtf8((x).c_str()))
//CString to QString
#define CS2Q(x) (QString::fromUtf16((const ushort *)(LPCWSTR)(x)))
//wstring to QString
#define ASCII2Q(x) (QString::fromLatin1((x).c_str()))

#define CS2US(x) ((const ushort *)(LPCWSTR)(x))
#define QS2W(x) ((const wchar_t *)((x).utf16()))

#define WC2Q(x) (QString::fromUtf16((const ushort *)(const wchar_t *)(x)))
#define WS2Q(x) (QString::fromUtf16((const ushort *)(x).c_str()))
//TS2Q
#   if defined(WIN32) || defined (_WIN32) || defined (_WIN64)
#       define TS2Q(x) (QString::fromUtf16((const ushort *)(x).c_str()))
#   else
#       define TS2Q(x) (QString::fromLatin1((x).c_str()))
#   endif

#ifndef QS_STR_MACRO_DEFINED
#define QS_STR_MACRO_DEFINED
#       define QS2S(s) std::string(((const char *)(s).toUtf8().data()))

#   if defined(WIN32) || defined (_WIN32) || defined (_WIN64)
#       define QS2T(s) std::wstring((const wchar_t *)(s).utf16())
#       define T2Q(s) QString::fromUtf16((const ushort *)(s).c_str())
#   else
#       define QS2T(s) std::string(((const char *)(s).toUtf8().data()))
#       define T2Q(s) QString::fromStdString(s)
#   endif
#endif

namespace s {

inline QString qsFromString(const std::string str) {
    return str.c_str();
}


inline const char * qs2chars(const QString& str) {
    return (const char *)str.toUtf8().data();
}


inline std::string qs2str(const QString& str) {
    return (const char *)str.toUtf8().data();
}

}


#endif // UI_COMMON_STR_QS_UTILS_H
