#ifndef SETTINGMAP_H
#define SETTINGMAP_H

enum STATUS
{

  STARTPROGRAM = 0,
  DATALOAD,
  PAUSE,
  STOP,
};

enum CLIENT_TYPE
{

  UDP_CLIENT_TYPE = 0,
  TXT_CLIENT_TYPE,
  TSP_CLIENT_TYPE
};


class Setting
{
public:
    Setting();
};


class SettingMap
{
public:
    SettingMap();
};

#endif // SETTINGMAP_H
