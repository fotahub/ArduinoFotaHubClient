# ArduinoFotaHubClient library
The ArduinoFotaHubClient library enables developers to create firmware for Arduino&reg;-based IoT devices that can be updated through [FotaHub](http://fotahub.com). It provides an C99-based FotaHub client library along with a set of examples illustrating how the latter can be used and integrated in real applications.

# Supported targets

As of now, the ArduinoFotaHubClient library can be used on Wifi&reg; Nina or Wifi&reg; 101 module compatible boards of the Arduino&reg; MKR family. In future, it is planned to support also Wifi&reg; Nina compatible boards of the Arduino&reg; AVR family. 
# Installation
To use the ArduinoFotaHubClient library, the [Arduino&reg; IDE](https://www.arduino.cc/en/software) **1.8.13** or later must be available on your laptop or computer.

The installation of the ArduinoFotaHubClient library itself and the required dependencies is explained [here](docs/installation/install-library.md). 

In addition, you must add the `fotahub.com` root certificate to your Wifi&reg; Nina or Wifi&reg; 101 module compatible board or shield as explained in [this guide](https://support.arduino.cc/hc/en-us/articles/360016119219-How-to-add-certificates-to-Wifi-Nina-Wifi-101-Modules-).

# Getting started
The best way to get started with the FotaHub&reg; Device SDK for Arduino&reg; is to try out and study the included examples:
* [Simple](docs/getting-started/simple.md) - "Hello World" of firmware over-the-air updating with FotaHub&reg;

# API Reference
View the [C API reference](src/FotaHub.h) for detailed information about the FotaHub&reg; client library (:construction: *under construction*).

# License
Unless specifically indicated otherwise in a file included in this project, FotaHub&reg; Device SDK for Arduino&reg; files are provided under the *Apache-2.0* license. See the [LICENSE](LICENSE) file for the full text of this license.
