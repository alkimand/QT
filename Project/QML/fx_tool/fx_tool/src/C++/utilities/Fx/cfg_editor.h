// cfg_editor.h
#ifndef COMMON__CFG_EDITOR_H
#define COMMON__CFG_EDITOR_H

//#include "../crypto/lite_gamma.h"
//#include "cfg_editor_defs.h"

//// core_lib
//#include <str_parse.h>
//#include <serialization.h>
//#include <file_utils.h>

#ifndef CS2T
#define CS2T(val)   str::utfToTString(val)
#endif
//Token To String
#define TTS(val) # val
//Token To TString
#define TTTS(val) str::utfToTString(TTS(val))


namespace fs {

class CConfig {
public:

     CConfig() { }


    CConfig(const tstring& path) :
        file_path_(path) {
    }


    ~CConfig() {}

    virtual void init(const tstring& path) {
        value_map_.clear();
        original_values_.clear();

        file_path_ = path;
    }


    virtual int save() {
        if (file_path_.empty())
            return ERR_FILE_NOT_FOUND;

        std::string serialized = serialize(value_map_);
        int result = 0;
        result = fs::writeText(file_path_, serialized.c_str());

        return result;
    };


    /*!
     * \fn  void erase(const std::string& key)
     * \brief   Removes the given entry.
     * \param   key     The key.
     */
    void erase(const std::string& key) {
        value_map_.erase(key);
    }


    size_t  size() const {
        return value_map_.size();
    }


    /*!
     * \fn  void clear()
     * \brief   Removes all entries.
     */
    void clear(bool clear_file_path = false) {
        value_map_.clear();
        original_values_.clear();
        if (clear_file_path)
            file_path_.clear();
    }


    /*!
     * \fn  void setString(const std::string& key, const std::string& value)
     * \brief   Add config string.
     * \param   key     The key.
     * \param   value  The value.
     */
    void setString(const std::string& key, const std::string& value) {
        auto it = value_map_.find(key);

        if (it == value_map_.end())
            value_map_.insert(std::pair<std::string, std::string>(key, value));
        else
            it->second = value;
    }


    /*!
     * \fn  bool isChanged()
     * \brief   Query if this object is changed.
     * \return  true if changed, false if not.
     */
    bool isChanged() const {
        return serialize(value_map_) != original_values_;
    };


    /*!
     * \fn  void setInt(const std::string& key, int value)
     * \brief   Add config strng.
     * \param   key     The key.
     * \param   value  The value.
     */
    void setInt(const std::string& key, int value) { setString(key, str::intToString(value)); };


    /*!
     * \fn  void setLongLong(const std::string& key, long long value)
     * \brief   Add config strng.
     * \param   key     The key.
     * \param   value  The value.
     */
    void setLongLong(const std::string& key, long long value) { setString(key, str::longLongToString(value)); };


    /*!
     * \fn  void setBool(const std::string& key, bool value)
     * \brief   Add config strng
     * \param   key     The key.
     * \param   value  true to value.
     */
    void setBool(const std::string& key, bool value) { setString(key, (value) ? "1" : "0"); };


    /*!
     * \fn  void setDouble(const std::string& key, double value)
     * \brief   Add config strng
     * \param   key     The key.
     * \param   value   The value.
     */
    void setDouble(const std::string& key, double value) { setString(key, str::doubleToString(value)); };


    /*!
     * \fn  int read()
     * \brief   Read.
     * \return  Error code.
     */
    virtual int read() {
        if (fs::fileExists(file_path_)) {
            if (fs::freadText(file_path_, original_values_) != 0)
                return ERR_FILE_ERROR;

            str::trimRight(original_values_, '\0');
            deserialize(original_values_, value_map_);
        }
        else {
            return ERR_FILE_NOT_FOUND;
        }

        return ERR_SUCCESS;
    }


    /*!
     * \fn  bool isPresent(const std::string& key) const
     * \brief   Query if 'key' is present.
     * \param   key The key.
     * \return  true if present, false if not.
     */
    bool isPresent(const std::string& key) const {
        return value_map_.find(key) != value_map_.end();
    }


    /*!
     * \fn  std::string getString(const std::string& key, std::string default = "")
     * \brief   Get a config string.
     * \param   key         The key.
     * \param   default     The default.
     * \return  The string.
     */
    std::string getString(const std::string& key, std::string def = "") {
        auto it = value_map_.find(key);

        if (it != value_map_.end())
            return (it->second);

        value_map_.insert(std::pair<std::string, std::string> {key, def});
        return def;
    }
    
    
    /*!
     * \fn  std::string getString(const std::string& key, std::string default = "") const
     * \brief   Get a config string.
     * \param   key         The key.
     * \param   default     The default.
     * \return  The string.
     */
    std::string getString(const std::string& key, std::string def = "") const {
        auto it = value_map_.find(key);

        if (it != value_map_.end())
            return (it->second);
        else
            return def;
    }


    /*!
     * \fn  tstring getPath() const
     * \brief   get a path of the file.
     */
    tstring getPath() const {
        return file_path_;
    }


    /*!
     * \fn  bool getBool(const std::string& key, bool default_val = false) const
     * \brief   Get a config string(as bool).
     * \param   key         Key name.
     * \param   default_val Default value.
     * \return  true if it succeeds, false if it fails.
     */
    bool getBool(const std::string& key, bool default_val = false) const {
        return getString(key, default_val ? "1" : "0") == "1";
    }


    /*!
     * \fn  int getInt(const std::string& key, int default_val = 0) const
     * \brief   Get a config string(as int).
     * \param   key         Key name.
     * \param   default_val Default value.
     * \return  The int.
     */
    int getInt(const std::string& key, int default_val = 0) const {
        return str::stringToInt(getString(key, std::to_string(default_val)));
    }


    /*!
     * \fn  long long getLongLong(const std::string& key, long long default_val = 0) const
     * \brief   Get a config string(as longlong).
     * \param   key         Key name.
     * \param   default_val Default value.
     * \return  The longlong.
     */
    long long getLongLong(const std::string& key, long long default_val = 0) const {
        return str::stringToLLong(getString(key, std::to_string(default_val)));
    }


    /*!
     * \fn  double getDouble(const std::string& key, double default_val = 0) const
     * \brief   Get a config string(as double).
     * \param   key         Key name.
     * \param   default_val Default value.
     * \return  The double.
     */
    double getDouble(const std::string& key, double default_val = 0) const {
        return str::stringToDouble(getString(key, std::to_string(default_val)));
    }


    std::map<std::string, std::string> getCopyValueMap() const {
        std::map<std::string, std::string> value_map_copy(value_map_);
        return value_map_copy;
    }

protected:
    std::map<std::string, std::string>  value_map_;
    tstring                             file_path_;
    std::string                         original_values_;
};


class FxConfig : public CConfig {

public:
    FxConfig()
    : CConfig() {
    }

    FxConfig(const QString& path)
        : CConfig(path) {
    }


    int save() override {
        if (file_path_.empty())
            return ERR_FILE_NOT_FOUND;

        std::string serialized = serialize(value_map_);

        sys::DataBuff buff;
        buff.set(serialized);
        lite_gamma::ec(buff.data(), buff.size(), DEFAULT_WP);

        return fs::fwriteBin(file_path_, buff.data(), buff.size());
    };

    /*!
     * \fn  int read()
     * \brief   Read.
     * \return  Error code.
     */
    int read() override {
        if (fs::fileExists(file_path_)) {
            sys::DataBuff buff;
            if (fs::freadBin(file_path_, buff) != 0)
                return ERR_FILE_ERROR;

            if (buff.size() > 0)
                lite_gamma::dc(buff.data(), buff.size(), DEFAULT_WP);

            original_values_ = buff.getString();

            str::trimRight(original_values_, '\0');
            deserialize(original_values_, value_map_);
        }
        else {
            return ERR_FILE_NOT_FOUND;
        }

        return ERR_SUCCESS;
    }

};

}

#endif // COMMON__CFG_EDITOR_H
