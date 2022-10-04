# ArduinoFotaHubClient library
The ArduinoFotaHubClient library enables developers to create firmware for Arduino&reg;-based IoT devices that can be updated through [FotaHub](http://fotahub.com). It provides a FotaHub client C library along with a set of examples illustrating how the latter can be used and integrated in real applications.

# Supported targets
The ArduinoFotaHubClient library can be used on Wifi&reg; Nina or Wifi&reg; 101 module compatible boards of the Arduino&reg; MKR family as well as Wifi&reg; Nina compatible boards or shields of the Arduino&reg; AVR family. 

# Installation
To use the FotaHub&reg; Device SDK for Linux&reg; and Raspberry Pi, the following tools must be available on your laptop or computer:
* The [Arduino&reg; CLI 0.27](https://arduino.github.io/arduino-cli/0.27) or later
* A GNU make toolchain - we recommend [MSYS2](https://www.msys2.org) when working under Windows&reg;, most likely already available when working under Linux&reg; or Mac&reg; OS X
* A text editor or IDE of your choice, e.g., [Visual Studio Code](https://code.visualstudio.com)

> &#x26A0; Be sure that the location into which you install the Arduino&reg; CLI does not contain any spaces in its path.

To enable `arduino-cli`, `make`, etc. to be invoked conveniently from Visual Studio Code's integrated terminal, add the following locations to your user or system level `Path` (Windows&reg;) or `PATH` (Linux&reg;, Mac&reg; OS X) environment variable:
* The Arduino CLI install location
* `C:\msys64\usr\bin` when working under Windows&reg; and using MSYS2 as GNU make toolchain

    > &#x1F6C8; As an alternative to adding the Arduino CLI install location to your `Path` of `PATH` environment variable, you can also set an environment variable named `ARDUINO_CLI_HOME` at user or system level.

Aside from that, you must add the `fotahub.com` root certificate to your Wifi&reg; Nina or Wifi&reg; 101 module compatible board or shield as explained in [this guide](https://support.arduino.cc/hc/en-us/articles/360016119219-How-to-add-certificates-to-Wifi-Nina-Wifi-101-Modules-).

# Getting started
The best way to get started with the FotaHub&reg; Device SDK for Arduino&reg; is to try out and study the included examples:
* [Simple](extras/docs/getting-started/simple.md) - "Hello World" of firmware over-the-air updating with FotaHub&reg;

# API Reference
View the [C API reference](src/FotaHub.h) for detailed information about the FotaHub&reg; client library (:construction: *under construction*).

# License
Unless specifically indicated otherwise in a file included in this project, FotaHub&reg; Device SDK for Arduino&reg; files are provided under the *Apache-2.0* license. See the [LICENSE](LICENSE) file for the full text of this license.
