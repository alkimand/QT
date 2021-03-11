set QTDIR=%1
set ProjectDir=%2
set OutDir=%3
set TargetDir=%4
set TargetName=%5
set TargetExt=%6
set ThirdPartyPath=%7

%QTDIR%\bin\windeployqt.exe "%OutDir%%TargetName%%TargetExt%" --no-translations 
xcopy /Y "%ThirdPartyPath%microsoft\x86\Microsoft.VC120.CRT\msvcp120.dll"   "%TargetDir%"
xcopy /Y "%ThirdPartyPath%microsoft\x86\Microsoft.VC120.CRT\msvcr120.dll"   "%TargetDir%"