//databuf.h

#ifndef CORE_LIB__DATABUF_H
#define CORE_LIB__DATABUF_H

#include "idatabuf.h"


namespace sys {

extern char g_pszEmptyString[1];


class DataBuff : public IDataBuff {
public:
    /*!
     * \fn  DataBuff::DataBuff()
     * \brief   Default constructor.
     */
    DataBuff();

    /*!
     * \fn  DataBuff::DataBuff(size_t size)
     * \brief   Constructor.
     * \param   size    The size.
     */
    DataBuff(size_t size);

    /*!
     * \fn  DataBuff::DataBuff(const std::string &str)
     * \brief   Constructor.
     * \param   str   The string.
     */
    DataBuff(const std::string &str);

    /*!
     * \fn  DataBuff::DataBuff(DataBuff&& other)
     * \brief   Move constructor.
     * \param [in,out]  other   The other.
     */
    DataBuff(DataBuff&& other);

    /*!
     * \fn  DataBuff& DataBuff::operator=(DataBuff&& rhs)
     * \brief   Move assignment operator.
     * \param [in,out]  rhs The right hand side.
     * \return  A shallow copy of this object.
     */
    DataBuff& operator=(DataBuff&& rhs);

    /*!
     * \fn  virtual DataBuff::~DataBuff()
     * \brief   Destructor.
     */
    virtual ~DataBuff();

    /*!
     * \fn  virtual bool DataBuff::resize(size_t size)
     * \brief   Resize.
     * \param   size    The size.
     * \return  true if it succeeds, false if it fails.
     */
    virtual bool resize(size_t size);

    /*!
     * \fn  virtual void DataBuff::attach(IDataBuff *pIBuf)
     * \brief   Attach data of another DataBuff object.
     * \param [in,out]  pIBuf   DataBuff object, its data will be detached.
     */
    virtual void attach(IDataBuff *ibuff);

    /*!
     * \fn  virtual void DataBuff::attach(void *bytes, size_t size)
     * \brief   Attach.
     * \param [in,out]  bytes  Pointed to the data (raw bytes) to attach. No copying will be done.
     * \param   size         Number of bytes to attach.
     */
    virtual void attach(void *bytes, size_t size);

    /*!
     * \fn  virtual void DataBuff::detach(sys::IDataBuff& receiver)
     * \brief   Detaches the given receiver.
     * \param [in,out]  receiver    The receiver.
     */
    virtual void detach(sys::IDataBuff& receiver);

    /*!
     * \fn  virtual void * DataBuff::detach(size_t& size)
     * \brief   Detaches the internal data, and returns them as pointer. Size of the detached data is returned through size.
     * \param [out]  size Size of detached data.
     * \return  Pointer to the detached data.
     */
    virtual void * detach(size_t& size);

    /*!
     * \fn  virtual void DataBuff::set(void *bytes, size_t size)
     * \brief   Set.
     * \param [in,out]      bytes  The bytes.
     * \param   size        Data size.
     */
    virtual void set(void *bytes, size_t size);

    /*!
     * \fn  virtual void DataBuff::set(const std::string& data)
     * \brief   Set the given s data.
     * \param   data   The data to set.
     */
    virtual void set(const std::string& data);

    /*!
     * \fn  virtual void DataBuff::append(void *bytes, size_t size)
     * \brief   Append.
     * \param [in,out]      bytes  The bytes.
     * \param   size        Data size.
     */
    virtual void append(void *bytes, size_t size);


    /*!
     * \fn  virtual void DataBuff::free(void)
     * \brief   Free this object.
     */
    virtual void free(void);

    /*!
     * \fn  virtual void DataBuff::*data()
     * \brief   Get the data.
     * \return  null if it fails, else a void*.
     */
    virtual void *data();

    /*!
     * \fn  virtual void DataBuff::getStr(std::string& out_str)
     * \brief                   Puts internal data into out string.
     * \param [in,out]  out_str String buffer.
     */
    virtual void getStr(std::string& out_str);

    /*!
     * \fn  virtual void DataBuff::getStr(std::wstring& str)
     * \brief                   Puts internal data into std::wstring.
     * \param [in,out]  out_str String buffer.
     */
    virtual void getStr(std::wstring& out_str);

    /*!
     * \fn  virtual void DataBuff::getString()
     * \brief   Copies internal data into std::string and returns it.
     */
    virtual std::string getString();

    /*!
     * \fn  virtual size_t DataBuff::size()
     * \brief   Get the size.
     * \return  Size of the data block.
     */
    virtual size_t size();

    /*!
     * \fn  virtual bool DataBuff::empty()
     * \brief   Indicates whether the buffer is empty.
     * \return  true if buf is empty, false if not empty.
     */
    virtual bool empty();

private:
    void       *data_;
    size_t      size_;
};

}

#endif //CORE_LIB__DATABUF_H
