#ifndef COMMON__CONFIG_EDITOR_DEFS_H
#define COMMON__CONFIG_EDITOR_DEFS_H

// Visible options
#define Language                            Language
#define Sounds                              Sounds
#define OutputFolder                        OutputFolder

#define AutoUpdate                          AutoUpdate

#define ShutdownComputerWhenDone            ShutdownComputerWhenDone
#define CreateITunesPlaylist                CreateITunesPlaylist

#define NamePrefix                          NamePrefix
#define NamePostfix                         NamePostfix
#define SeparatorForOutFN                   SeparatorForOutFN
#define DateFormatForOutFN                  DateFormatForOutFN
#define NumberingInOutFN                    NumberingInOutFN
#define OriginalTitleInOutFN                OriginalTitleInOutFN
#define IncludeDateInOutFN                  IncludeDateInOutFN

#define Location                            Location
#define Price                               Price
#define CheckLicenseForceNextStart          CheckLicenseForceNextStart

#define LastInstalledApp                    LastInstalledApp

enum EProxyType
{
    kNoProxy            = 0,
    kUseSystemProxy     = 1,
    kManualProxyConfig  = 2
};

#endif // COMMON__CONFIG_EDITOR_DEFS_H


