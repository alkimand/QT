#http://itnotesblog.ru/note.php?id=3

PROJECT_ROOT_PATH = $${PWD}/
win32: OS_SUFFIX = win32
linux-g++: OS_SUFFIX = linux

QT += qml quick core quickcontrols2 widgets concurrent opengl multimedia gui
CONFIG += c++11

#CONFIG(debug, debug|release) {
CONFIG(debug) {
    BUILD_FLAG = debug
    LIB_SUFFIX = d
} else {
    BUILD_FLAG = release
}

LIBS_PATH = $${PROJECT_ROOT_PATH}/lib/$${OS_SUFFIX}/
INC_PATH = $${PROJECT_ROOT_PATH}/include/
IMPORT_PATH = $${PROJECT_ROOT_PATH}/import/
BIN_PATH = $${PROJECT_ROOT_PATH}/bin/$${BUILD_FLAG}/
IMAGES_PATH = $${PROJECT_ROOT_PATH}/src/images/ToolBarIcon/
BUILD_PATH = $${PROJECT_ROOT_PATH}/build/$${BUILD_FLAG}/$${TARGET}/

#RCC_DIR = $${BUILD_PATH}/rcc/

#UI_DIR = $${BUILD_PATH}/ui/
#MOC_DIR = $${BUILD_PATH}/moc/
#OBJECTS_DIR = $${BUILD_PATH}/obj/
LIBS += -L$${LIBS_PATH}/

DEFINES += QT_DEPRECATED_WARNINGS

#INCLUDEPATH += $${INC_PATH}/
#INCLUDEPATH += $${IMPORT_PATH}/

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QML_CUSTOM_CLASSES = $${PROJECT_ROOT_PATH}/src/C++/QMLCustomClasses/
#models paths
C_SOURSE_MODEL_PATH =       $${PROJECT_ROOT_PATH}/src/C++/Models
C_SOURSE_CONTROLLERS_PATH = $${PROJECT_ROOT_PATH}/src/C++/Controllers
#C_SOURSE_UTILS_PATH =       $${PROJECT_ROOT_PATH}/src/C++/utilities
SOURCES += \
        main.cpp \
        $${C_SOURSE_CONTROLLERS_PATH}/appdatacontroller.cpp \
        $${C_SOURSE_CONTROLLERS_PATH}/pixmap_controller.cpp \
        $${C_SOURSE_MODEL_PATH}/appdata.cpp \
        $${C_SOURSE_MODEL_PATH}/item.cpp \
        $${C_SOURSE_MODEL_PATH}/Item/AbstractTableModel\ItemModelBase.cpp \
        $${C_SOURSE_MODEL_PATH}/Item/puzzlepath.cpp \
        $${C_SOURSE_MODEL_PATH}/Item/pathpoints.cpp \
        $${C_SOURSE_MODEL_PATH}/Item/random_points.cpp \
        $${C_SOURSE_MODEL_PATH}/Tile/puzzleitem.cpp \
        $${C_SOURSE_MODEL_PATH}/Tile/tile.cpp
HEADERS += \
        $${C_SOURSE_CONTROLLERS_PATH}/appdatacontroller.h \
        $${C_SOURSE_CONTROLLERS_PATH}/pixmap_controller.h \
        $${C_SOURSE_MODEL_PATH}/appdata.h \
        $${C_SOURSE_MODEL_PATH}/item.h \
        $${C_SOURSE_MODEL_PATH}/Item/AbstractTableModel\ItemModelBase.h \
        $${C_SOURSE_MODEL_PATH}/Item/itemproperties.h \
        $${C_SOURSE_MODEL_PATH}/Item/itemconstants.h \
        $${C_SOURSE_MODEL_PATH}/Item/itemenums.h \
        $${C_SOURSE_MODEL_PATH}/Item/puzzlepath.h \
        $${C_SOURSE_MODEL_PATH}/Item/pathpoints.h \
        $${C_SOURSE_MODEL_PATH}/Item/random_points.h \
        $${C_SOURSE_MODEL_PATH}/Tile/puzzleitem.h \
        $${C_SOURSE_MODEL_PATH}/Tile/tile.h


QRC_DIR_PATH = $${PROJECT_ROOT_PATH}/src/resources \

RESOURCES += $${QRC_DIR_PATH}/qml.qrc \
             $${QRC_DIR_PATH}/Icons.qrc

TRANSLATIONS += \
             $${QRC_DIR_PATH}/translations/translations_ru_RU.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

INCLUDEPATH += $${PROJECT_ROOT_PATH}/src \
               $${C_SOURSE_CONTROLLERS_PATH}/ \
               $${C_SOURSE_MODEL_PATH}/ \
             #  $${QML_CUSTOM_CLASSES}/BorderRadiusWidget/ \
              # $${C_SOURSE_VARAIATIVE_DATA_PATH}/AbstractPropertyConteiner/ \
              # $${C_SOURSE_ABSTRACT_ITEM_DATA_PATH}/AbstractTableModel/ \
              # $${C_SOURSE_ABSTRACT_ITEM_DATA_PATH} \
               #$${C_SOURSE_ABSTRACT_ITEM_DATA_PATH}/ItemPropertyWrapper/ \
              # $${C_SOURSE_MODEL_PATH}/UserSession/ \
            #  $${C_SOURSE_MODEL_PATH}/Tile/ \
              # $${C_SOURSE_UTILS_PATH}/DataBuff/ \
              # $${C_SOURSE_UTILS_PATH}/ \
               $${IMPORT_PATH}/ \
               $${INC_PATH}/ \
             #  $${PROJECT_ROOT_PATH}/src/C++/sound_controller/
               # $${QML_CUSTOM_CLASSES}/BorderRadiusWidget

# Additional import path used to resolve QML modules just for Qt Quick Designer

#defines other files
QML_SOURSE_PATH = $${PROJECT_ROOT_PATH}/src/qml/
    QML_SOURSE_TOOL_BAR_PATH    =  $${QML_SOURSE_PATH}/ToolBar
    QML_SOURSE_MENU_BAR_PATH    =  $${QML_SOURSE_PATH}/Menu
    QML_SOURSE_TAB_VIEW_PATH    =  $${QML_SOURSE_PATH}/TabView
    QML_SOURSE_TABLE_VIEW_PATH  =  $${QML_SOURSE_PATH}/TableView
    QML_SOURSE_SCENE_PATH       =  $${QML_SOURSE_PATH}/Scene
    QML_SOURSE_FILE_DIALOG_PATH =  $${QML_SOURSE_PATH}/FileDialog
OTHER_FILES += \
    main.qml \
#Actions
    $${PROJECT_ROOT_PATH}/src/qml/Action/Actions.qml \
#ToolBar
    $${QML_SOURSE_TOOL_BAR_PATH}/ToolBarWidget.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomComboBox/CustomComboBox.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomToolButton/CustomToolButtonIconText.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomToolButton/CustomToolButtonIcon.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomToolButton/CustomToolButtonText.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomToolButton/ToolButtonLoader.qml \
    $${QML_SOURSE_TOOL_BAR_PATH}/CustomToolButton/CustomToolButton.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/ToolBarContextMenu/ToolBarContextMenu.qml \
#MenuBar
    $${QML_SOURSE_MENU_BAR_PATH}/HeaderMenuBar/MenuBarWidget.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/HeaderMenuBar/MenuBarBasic.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/ContextMenuBase.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/ContextMenuSeparator.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/CheckIndicator.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/MenuBarContextMenu/FileContexMenu/FileContexMenu.qml \
#TabView
    $${QML_SOURSE_TAB_VIEW_PATH}/TabViewWidget.qml \
    $${QML_SOURSE_TAB_VIEW_PATH}/Style/TabViewStyle.qml \
    $${QML_SOURSE_TAB_VIEW_PATH}/Style/OneTabBaseStyle.qml \
#TabView_menu
    $${QML_SOURSE_TAB_VIEW_PATH}/Tab/MouseEvent.qml \
    $${QML_SOURSE_MENU_BAR_PATH}/TabContextMenu/TabContextMenu.qml \
#Scene
    $${QML_SOURSE_TAB_VIEW_PATH}/BackGroundWidget.qml \
   # $${QML_SOURSE_TABLE_VIEW_PATH}/BaseTableView.qml \
#
    #TableView Item Delegats
 #  $${QML_SOURSE_TABLE_VIEW_PATH}/ItemDelegate/ItemDelegate/EditableLable.qml \
  #  $${QML_SOURSE_TABLE_VIEW_PATH}/ItemDelegate/ItemDelegate/CheckBox.qml \
#
    #TableView Loaders
   # $${QML_SOURSE_MENU_BAR_PATH}/ItemDelegate/Loaders/ColumnProvider.qml \
#
    #TableView ContextMenu
    #$${QML_SOURSE_MENU_BAR_PATH}/TableViewContexMenu/ItemContexMenu/ItemContexMenu.qml \
#FileDialog
    $${QML_SOURSE_FILE_DIALOG_PATH}/FileDialogWidget.qml \
    $${QML_SOURSE_FILE_DIALOG_PATH}/OpenDialogWidget.qml \
    $${QML_SOURSE_FILE_DIALOG_PATH}/SaveDialogWidget.qml \
#GridView
   $${QML_SOURSE_SCENE_PATH}/DropWidget.qml \
   $${QML_SOURSE_SCENE_PATH}/DraggedWidget.qml

RC_FILE = $${PROJECT_ROOT_PATH}/src/images/AppIcon/AppIcon.rc

DISTFILES += \
    $${IMAGES_PATH}/filenew.png \
    $${IMAGES_PATH}/fileopen.png \
    $${IMAGES_PATH}/filesave.png \
    $${IMAGES_PATH}/qt-logo.png \
    $${IMAGES_PATH}/close.png \
    $${IMAGES_PATH}/plus.png \
    $${IMAGES_PATH}/refresh.png \
    $${IMAGES_PATH}/remove_row.png \
    $${IMAGES_PATH}/add_row.png \
    $${IMAGES_PATH}/dvdvideosoft_big.png \
    $${IMAGES_PATH}/delete_file.png \
    $${IMAGES_PATH}/freevideodownloader.ico \
    $${IMAGES_PATH}/freeyoutubetomp3converter.ico \
    $${IMAGES_PATH}/freeinstagramdownload.ico \
    $${IMAGES_PATH}/freetiktokdownloader.ico \
    $${IMAGES_PATH}/vimeodownload.ico \

QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    src/ui/TestForms/mainwindow.ui
