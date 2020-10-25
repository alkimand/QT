#include "serialization.h"

//#include <str_conv.h>
//#include <str_parse.h>
#include <vector>
namespace fs {


std::string serialize(const std::map<std::string, std::string> &keyvalue_map) {
    std::string result;

    for (auto it = keyvalue_map.begin(); it != keyvalue_map.end(); ++it) {
        if (!it->second.empty()) {
            result.append(it->first);
            result.append("=");
            result.append(it->second);
            result.append("\n");
        }
    }
    return result;
}


int deserialize(const std::string& serialized_array, std::map<std::string, std::string>& keyvalue_map) {
    std::vector<std::string> lines;
    tokenize<char>(serialized_array, "\n", lines);

    std::vector<std::string> key_and_value;
    for (size_t i = 0; i < lines.size(); i++) {
        tokenize<char>(lines[i], "=", key_and_value);

        if (key_and_value.size() < 2)
            continue;

        keyvalue_map[key_and_value[0]] = key_and_value[1];
        //keyvalue_map.insert(std::pair<std::string, std::string>(key_and_value[0], key_and_value[1]));
    }

    return 0;
}

template <typename T>
inline void tokenize(
        const std::basic_string<T> &input,
        const std::basic_string<T> &separator,
        std::vector<std::basic_string<T>> &out_tokens) {
    if (separator.empty())
        return;

    size_t cchStart = 0;
    size_t cchEnd = input.find(separator, cchStart);

    out_tokens.clear();

    if (input.empty())
        return;

    if (cchEnd == -1) {
        out_tokens.push_back(input);
    }
    else {
        size_t cchSrcLen = input.size();
        size_t cchSeparatorLen = separator.size();

        do {
            out_tokens.push_back(input.substr(cchStart, cchEnd - cchStart));

            cchStart = cchEnd + cchSeparatorLen;
            cchEnd = input.find(separator, cchStart);

            if (cchEnd == -1)
                out_tokens.push_back(input.substr(cchStart, cchSrcLen - cchStart));
        } while (cchEnd != -1);
    }
}
};
