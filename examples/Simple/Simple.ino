#include <Arduino.h>
#include "BlinkDrv.h"
#include "WiFiDrv.h"
#include "DemoFOTAUpdateAgent.h"
#include "DemoProductInfo.h"
#include "Configuration.h"

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
  Serial.println("\n--------------------------------------------------------------------------");
  Serial.print("Running ");
  Serial.print(DEMO_PRODUCT_NAME);
  Serial.print(" ");
  Serial.print(DEMO_PRODUCT_FIRMWARE_VERSION);
  Serial.println(" firmware");
  Serial.println("--------------------------------------------------------------------------\n");
}
