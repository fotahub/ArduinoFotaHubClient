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
#include "DemoFOTAUpdateAgent.h"
#include "SinglePartitionDemoFirmwareUpdateInfoSerialReader.h"
#include "DemoFOTAUpdateWorkflow.h"
#include <Arduino.h>
#include <ArduinoFotaHubClient.h>

void DemoFOTAUpdateAgentClass::init(const char *productId, const char *productName, const FOTAUpdateClientConfig *pUpdateClientConfig)
{
  firmwareUpdateInfoReader_init();
  fotaUpdateWorkflow_init();
  FotaHubClient.init(productId, productName, pUpdateClientConfig);
}

void DemoFOTAUpdateAgentClass::run()
{
  if (Serial.available()) {
    firmwareUpdateInfoReader_onCharacterReceived(Serial.read());
  }

  firmwareUpdateInfoReader_run();
  FotaHubClient.run();
}

DemoFOTAUpdateAgentClass DemoFOTAUpdateAgent;
