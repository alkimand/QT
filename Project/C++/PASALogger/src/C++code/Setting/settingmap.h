#ifndef SETTINGMAP_H
#define SETTINGMAP_H

enum STATUS
{

  STARTPROGRAM = 0,
  PLAY = 1,
  PAUSE = 2,
  STOP = 3,
  CLEAR = 4,
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
