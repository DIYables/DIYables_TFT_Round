/*
   Created by DIYables

   This example code is in the public domain

   Product page:
   - https://diyables.io/products/1.28-inch-round-circular-tft-lcd-display-module
   - https://www.amazon.com/dp/B0F9NY6JZ6
*/

#include <DIYables_TFT_Round.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeMono9pt7b.h>

#define PIN_RST 8
#define PIN_DC 9
#define PIN_CS 10

DIYables_TFT_GC9A01_Round TFT_display(PIN_RST, PIN_DC, PIN_CS);

void setup() {
  Serial.println(F("Arduino TFT LCD Display - Use external font"));

  TFT_display.begin();
  TFT_display.fillScreen(DIYables_TFT::colorRGB(0, 0, 0));          // black
  TFT_display.setTextColor(DIYables_TFT::colorRGB(255, 255, 255));  // White text

  TFT_display.setTextSize(2);
  TFT_display.setCursor(40, 50);
  TFT_display.print("Hello DIYables!");  // default font

  TFT_display.setTextSize(1);

  TFT_display.setFont(&FreeSans9pt7b);
  TFT_display.setTextColor(DIYables_TFT::colorRGB(255, 0, 0));  // Red text
  TFT_display.setCursor(60, 100);
  TFT_display.print("Hello DIYables!");  // FreeSans9pt7b font

  TFT_display.setFont(&FreeSerif9pt7b);
  TFT_display.setTextColor(DIYables_TFT::colorRGB(0, 0, 255));  // Blue text
  TFT_display.setCursor(60, 140);
  TFT_display.print("Hello DIYables!");  // FreeSerif9pt7b font

  TFT_display.setFont(&FreeMono9pt7b);
  TFT_display.setTextColor(DIYables_TFT::colorRGB(0, 255, 0));  // Green text
  TFT_display.setCursor(40, 180);
  TFT_display.print("Hello DIYables!");  // FreeMono9pt7b font
}

void loop(void) {
}
