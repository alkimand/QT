#ifndef ITEMCONSTANT_H
#define ITEMCONSTANT_H
//for QML part only

#define FEATURE_S                             "feature"
#define FEATURE_NAME_S                        "feature_name"
#define NAME_S                                "name"
#define IS_ACTIVE_S                           "is_active"
#define DISPLAY_S                             "display_"
#define EDITE_S                               "edite"
#define TITLE_S                               "title"
#define ID_S                                  "ID"
#define ICON_S                                "icon_"

#define DEFAULT_ICON                          "qt-logo.png"
#define FREEYTVDOWNLOADER                     "FreeYTVDownloader"
#define FREEYTVDOWNLOADER_ICON                "freevideodownloader.ico"
#define FREETIKTOKDOWNLOADER                  "FreeTikTokDownloader"
#define FREETIKTOKDOWNLOADER_ICON             "freetiktokdownloader.ico"




const int DATE_MAP_SIZE                        = 3;
const int APP_MAIN_MODEL_COUNT                 = 1;

enum DATA_ID {
    FEATURE     = 0 ,
    FEATURE_NAME,
    IS_ACTIVE   ,
    NAME        ,
//  ICON        ,
//    EDITE
    };

enum MODEL_ROLES {
    DISPLAY     = 0 ,
    EDITE           ,
    TITLE           ,
    ID              ,
    ICON_PATH            ,

};















#endif // ITEMCONSTANT_H


