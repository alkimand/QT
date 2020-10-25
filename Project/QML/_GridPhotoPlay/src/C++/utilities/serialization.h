// serialization.h

#ifndef CORE_LIB__SERIALIZATION_H
#define CORE_LIB__SERIALIZATION_H

#include <map>
#include <vector>

//class vector
namespace fs {
    std::string serialize(const std::map<std::string, std::string> &keyvalue_map);

    int deserialize(const std::string& serialized_array, std::map<std::string, std::string>& keyvalue_map);
    template <typename T>
    inline void tokenize(const std::basic_string<T> &input, const std::basic_string<T> &separator, std::vector<std::basic_string<T>> &out_tokens);
};
#endif //CORE_LIB__SERIALIZATION_H
