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
#include "WiFiDrv.h"
#include <ArduinoFotaHubClient.h>

#define WIFI_ACTIVITY_INTERVAL 500
uint64_t previousMillis = 0;
uint64_t currentMillis = 0;

void WiFiDrvClass::connect(const char* ssid, const char *passphrase)
{
  uint8_t status = WL_IDLE_STATUS;

  while (status != WL_CONNECTED) {
    Serial.print("Connecting to Wi-Fi network ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, passphrase);

    // Wait until Wi-Fi connnection has been established
    delay(2000);
  }
  FotaHubClient.notifyNetworkStatusChange(NETWORK_ADAPTER_STATUS_CONNECTED);
  connected = true;
}

void WiFiDrvClass::run(void)
{
  currentMillis = millis(); 
  if(currentMillis - previousMillis >= WIFI_ACTIVITY_INTERVAL) { 
    previousMillis = currentMillis; 
  if(connected && WiFi.status() != WL_CONNECTED) {
    connected = false;
    FotaHubClient.notifyNetworkStatusChange(NETWORK_ADAPTER_STATUS_DISCONNECTED);
  } else if (!connected && WiFi.status() == WL_CONNECTED) {
    connected = true;
    FotaHubClient.notifyNetworkStatusChange(NETWORK_ADAPTER_STATUS_CONNECTED);
  }
  }
}

WiFiDrvClass WiFiDrv;
