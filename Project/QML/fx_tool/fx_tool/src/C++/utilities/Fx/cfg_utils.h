//cfg_utils.h

#ifndef COMMON__CFG_UTILS_H_
#define COMMON__CFG_UTILS_H_

#include "cfg_editor.h"
//#include "../appfx/appfx_utils.h"

#define CFG_SINGLETON_HELPER_CLASS_BODY(class_name, cfg_file_name, config_class_name) { \
public:\
    static class_name& instance() {\
        static class_name instance;\
        return instance;\
    }\
    class_name(class_name const&) = delete;\
    void operator=(class_name const&) = delete;\
    config_class_name& cfg() {\
        return cfg_;\
    }\
private:\
    class_name() {\
        cfg_.init(\
            fs::concatPaths(\
            digi::getAppSpecificFolder(fs::EAppSpecificFolder::eConfig),\
            cfg_file_name));\
        cfg_.read();\
    }\
    config_class_name cfg_;\
};




#endif // COMMON__CFG_UTILS_H_
