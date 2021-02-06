#!/bin/bash
ARDUINO_CLI_CMD=arduino-cli
if [ "$ARDUINO_CLI_HOME" != "" ]
then
  ARDUINO_CLI_CMD=$ARDUINO_CLI_HOME/$ARDUINO_CLI_CMD
fi
$ARDUINO_CLI_CMD version 2>/dev/null
if [ "$?" != 0 ] 
then
    echo "ERROR: arduino-cli not found"
    exit 1
fi

# See https://arduino.github.io/arduino-cli/latest/configuration/#environment-variables for details
export ARDUINO_LIBRARY_ENABLE_UNSAFE_INSTALL=true

# See https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_lib_install for details
$ARDUINO_CLI_CMD lib install ArduinoBearSSL
$ARDUINO_CLI_CMD lib install ArduinoHttpClient
$ARDUINO_CLI_CMD lib install ArduinoOTA
$ARDUINO_CLI_CMD lib install LibPrintf
$ARDUINO_CLI_CMD lib install WiFiNINA
echo Installing ArduinoFotaHubClient...
if [ ! -d "libraries/ArduinoFotaHubClient" ]
then
    $ARDUINO_CLI_CMD lib install --git-url https://github.com/fotahub/ArduinoFotaHubClient
    # Workaround for apparent Arduino-CLI bug
    # (see https://github.com/arduino/arduino-cli/blob/master/arduino/libraries/librariesmanager/install.go#L202 for details)
    if [ -d "libraries/ArduinoFotaHubClien" ]
    then
        mv libraries/ArduinoFotaHubClien libraries/ArduinoFotaHubClient
    fi
else
    echo Already installed ArduinoFotaHubClient
fi
echo Installing ArduinoFotaHubClientWrappers...
if [ ! -d "libraries/ArduinoFotaHubClientWrappers" ]
then
    $ARDUINO_CLI_CMD lib install --git-url https://github.com/fotahub/ArduinoFotaHubClientWrappers
else
    echo Already installed ArduinoFotaHubClient
fi
echo Installing ZeroTimer...
if [ ! -d "libraries/ZeroTimer" ]
then
    $ARDUINO_CLI_CMD lib install --git-url https://github.com/EHbtj/ZeroTimer
else
    echo Already installed ZeroTimer
fi

# Remove 'dot_a_linkage=true' in ArduinoOTA library.properties to avoid link errors due to inadequate 
# ordering of precompiled ArduinoOTA and ArduinoFotaHubClient library binaries in Arduino IDE-managed build
LIBRARY_PROPERTIES=libraries/ArduinoOTA/library.properties
OPTION_TO_REMOVE=dot_a_linkage=true
sed -e "s/$OPTION_TO_REMOVE//g" $LIBRARY_PROPERTIES > tmp.properties && mv tmp.properties $LIBRARY_PROPERTIES
