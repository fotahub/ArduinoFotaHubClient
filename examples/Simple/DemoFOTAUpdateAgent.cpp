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
