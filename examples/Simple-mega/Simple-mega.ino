/*
 *  Copyright (C) 2022 FotaHub Inc. All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of the FotaHub(R) Device SDK program (https://fotahub.com)
 */
#include <Arduino.h>
#include "BlinkDrv.h"
#include "WiFiDrv.h"
#include "DemoFOTAUpdateAgent.h"
#include "DemoProductInfo.h"
#include "Configuration.h"

#if defined(ARDUINO_SAMD_MKRWIFI1010)
#include "ConfigLib.h"
#endif

void setup() {   
  // Open and wait for serial port
  Serial.begin(115200);
  while (!Serial) { }

  printFirmwareInfo();

  BlinkDrv.init(BLINK_PERIOD);
  DemoFOTAUpdateAgent.init(DEMO_PRODUCT_ID, DEMO_PRODUCT_NAME, &FOTA_UPDATE_CLIENT_DEFAULT_CONFIG); 
  
  WiFiDrv.connect(WIFI_SSID, WIFI_PASSPHRASE);
}

void loop() {
  WiFiDrv.run();
  DemoFOTAUpdateAgent.run();
}

void printFirmwareInfo() {
  Serial.println("--------------------------------------------------------------------------");
  Serial.print("Running ");
  Serial.print(DEMO_PRODUCT_NAME);
  Serial.print(" ");
  Serial.print(DEMO_PRODUCT_FIRMWARE_VERSION);
  Serial.println(" firmware");
  Serial.println("--------------------------------------------------------------------------\n");
}

