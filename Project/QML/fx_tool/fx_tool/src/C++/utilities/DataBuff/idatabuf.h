//idatabuf.h

#ifndef CORE_LIB__IDATABUF_H
#define CORE_LIB__IDATABUF_H

#include <string>


namespace sys {

class IDataBuff {
public:
    virtual bool resize(size_t size) = 0;

    virtual void free(void) = 0;

    virtual void set(void *pData, size_t size) = 0;

    virtual void set(const std::string& data) = 0;

    virtual void *data(void) = 0;

    virtual void attach(IDataBuff *pIBuf) = 0;

    virtual void attach(void *bytes, size_t size) = 0;

    virtual void detach(sys::IDataBuff& receiver) = 0;

    virtual void *detach(size_t& size) = 0;

    virtual void getStr(std::string& out_str) = 0;

    virtual void getStr(std::wstring& out_str) = 0;

    virtual std::string getString() = 0;

    virtual size_t size(void) = 0;

    virtual bool empty(void) = 0;
};


inline std::string getString(IDataBuff *ibuff) {
    std::string s;
    ibuff->getStr(s);
    return s;
}

}

#endif //CORE_LIB__IDATABUF_H
