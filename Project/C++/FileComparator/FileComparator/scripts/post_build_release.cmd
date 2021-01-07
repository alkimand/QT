set QTDIR=%1
set ProjectDir=%2
set OutDir=%3
set TargetDir=%4
set TargetName=%5
set TargetExt=%6

%QTDIR%\bin\windeployqt.exe "%OutDir%%TargetName%%TargetExt%" --no-translations 
%QTDIR%\bin\windeployqt.exe "%OutDir%qtglrender.dll" --no-translations 


windeployqt.exe F:\QT_2\Project\builds\FileComparator\FileComparator.exe --no-translations 
