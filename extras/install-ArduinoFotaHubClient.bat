@echo off
setlocal
set ARDUINO_CLI_CMD=arduino-cli
if not "%ARDUINO_CLI_HOME%" == "" (
    set ARDUINO_CLI_CMD=%ARDUINO_CLI_HOME%\%ARDUINO_CLI_CMD%
)
%ARDUINO_CLI_CMD% version >nul 2>&1
if ERRORLEVEL 1 (
    echo ERROR: arduino-cli not found
    exit /B 1
)

rem See https://arduino.github.io/arduino-cli/latest/configuration/#environment-variables for details
set ARDUINO_LIBRARY_ENABLE_UNSAFE_INSTALL=true

rem See https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_lib_install for details
%ARDUINO_CLI_CMD% lib install ArduinoBearSSL
%ARDUINO_CLI_CMD% lib install ArduinoHttpClient
%ARDUINO_CLI_CMD% lib install ArduinoOTA
%ARDUINO_CLI_CMD% lib install LibPrintf
%ARDUINO_CLI_CMD% lib install WiFiNINA
echo Installing ArduinoFotaHubClient...
if not exist libraries\ArduinoFotaHubClient (
    %ARDUINO_CLI_CMD% lib install --git-url https://github.com/fotahub/ArduinoFotaHubClient
    rem Workaround for apparent Arduino-CLI bug
    rem (see https://github.com/arduino/arduino-cli/blob/master/arduino/libraries/librariesmanager/install.go#L202 for details)
    if exist libraries\ArduinoFotaHubClien (
        ren libraries\ArduinoFotaHubClien ArduinoFotaHubClient
    )
) else (
    echo Already installed ArduinoFotaHubClient
)
echo Installing ArduinoFotaHubClientWrappers...
if not exist libraries\ArduinoFotaHubClientWrappers (
    %ARDUINO_CLI_CMD% lib install --git-url https://github.com/fotahub/ArduinoFotaHubClientWrappers
) else (
    echo Already installed ArduinoFotaHubClientWrappers
)
echo Installing ZeroTimer...
if not exist libraries\ZeroTimer (
    %ARDUINO_CLI_CMD% lib install --git-url https://github.com/EHbtj/ZeroTimer
) else (
    echo Already installed ZeroTimer
)

rem Remove 'dot_a_linkage=true' in ArduinoOTA library.properties to avoid link errors due to inadequate 
rem ordering of precompiled ArduinoOTA and ArduinoFotaHubClient library binaries in Arduino IDE-managed build
set LIBRARY_PROPERTIES=libraries\ArduinoOTA\library.properties
set OPTION_TO_REMOVE=dot_a_linkage=true
powershell -Command "(Get-Content %LIBRARY_PROPERTIES%) -replace '%OPTION_TO_REMOVE%', '' | Out-File -encoding ASCII %LIBRARY_PROPERTIES%"

endlocal
