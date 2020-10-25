#include "databuf.h"

#include <stdlib.h>


namespace sys {

char g_pszEmptyString[1];


DataBuff::DataBuff()
    : data_(nullptr)
    , size_(0) {
}


DataBuff::DataBuff(size_t size)
    : data_(nullptr)
    , size_(0) {
    this->resize(size);
}


DataBuff::DataBuff(const std::string &str)
    : data_(nullptr)
    , size_(0) {
    this->set(str);
}


DataBuff::DataBuff(DataBuff&& other)
    : size_(other.size_) {
    data_ = other.data_;
    other.data_ = nullptr;
    other.size_ = 0;
}


DataBuff& DataBuff::operator=(DataBuff&& rhs) {
    rhs.detach(*this);
    return *this;
}


DataBuff::~DataBuff() {
    free();
}


bool DataBuff::resize(size_t size) {
    if (this->size() == size) {
        return true;
    }
    else if (size <= 0) {
        size_ = 0;
        free();
        return true;
    }

    if (!data_)
        data_ = (char*)malloc(size);
    else
        data_ = (char*)realloc(data_, size);

    size_ = size;

    return data_ != nullptr;
}


void DataBuff::attach(IDataBuff *ibuff) {
    if (!ibuff)
        return;

    data_ = ibuff->detach(size_);
}


void DataBuff::attach(void *pBytes, size_t size) {
    if (!pBytes)
        return;

    data_ = pBytes;
    size_ = size;
}


void DataBuff::detach(sys::IDataBuff& receiver) {
    receiver.free();
    (dynamic_cast<sys::DataBuff *>(&receiver))->size_ = size_;
    (dynamic_cast<sys::DataBuff *>(&receiver))->data_ = data_;
    data_ = nullptr;
    size_ = 0;
}


void * DataBuff::detach(size_t& size) {
    size = size_;
    size_ = 0;
    void *pData = data_;
    data_ = nullptr;
    return pData;
}


void DataBuff::set(void *pBytes, size_t size) {
    this->resize(size);

    if (!pBytes)
        return;

    for (size_t i = 0; i < size; i++)
         *((char *)data_ + i) = *(((char*)pBytes) + i);
}


void DataBuff::set(const std::string& data) {
    if (data.empty()) {
        this->set(nullptr, 0);
        return;
    }

    size_t size = data.size();

    this->resize(size);
    for (size_t i = 0; i < size; i++)
        *((char *)data_ + i) = *(data.c_str() + i);
}


void DataBuff::append(void *pBytes, size_t size) {
    size_t oldSize = size_;
    this->resize(oldSize + size);

    if (!pBytes)
        return;

    for (size_t i = 0; i < size; i++)
         *((char *)data_ + oldSize + i) = *(((char*)pBytes) + i);
}


void DataBuff::free(void) {
    if (data_)
        ::free(data_);

    data_ = nullptr;
    size_ = 0;
}


void * DataBuff::data() {
    return data_;
}


void DataBuff::getStr(std::string& out_str) {
    if (!data_)
        return;
    out_str.assign((char *)data_, size_);
}


void DataBuff::getStr(std::wstring& out_str) {
    if (!data_)
        return;
    size_t char_count = size_ / 2;
    out_str.resize(char_count + 1);
    out_str[char_count] = 0;
    out_str.assign((wchar_t *)data_, char_count);
}


std::string DataBuff::getString() {
    if (!data_)
        return g_pszEmptyString;
    std::string s((char *)data_, size_);
    return std::move(s);
}


size_t DataBuff::size() {
    return size_;
}


bool DataBuff::empty() {
    return size_ == 0;
}

}
