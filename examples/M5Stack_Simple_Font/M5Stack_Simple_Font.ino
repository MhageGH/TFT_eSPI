#define USE_SD  // uncomment and SPIFFS is enabled

#include "FS.h"
#include "SD.h"
#include "SPIFFS.h"
#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
#ifdef USE_SD
  if (!SD.begin(4, SPI, 40000000)) while (1) yield();
  tft.setFS(SD);
#else
  SPIFFS.begin(true);
#endif
  tft.loadFont("Meiryo40");
  tft.setCursor(10, 100);
  tft.println("明日って今さッ!");
}

void loop() {
}
