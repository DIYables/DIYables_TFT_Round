/*
   Created by DIYables

   This example code is in the public domain

   Product page:
   - https://diyables.io/products/1.28-inch-round-circular-tft-lcd-display-module
   - https://www.amazon.com/dp/B0F9NY6JZ6
*/

#include <DIYables_TFT_Round.h>

#define MAGENTA   DIYables_TFT::colorRGB(255, 0, 255)
#define WHITE     DIYables_TFT::colorRGB(255, 255, 255)

#define PIN_RST 8
#define PIN_DC  9
#define PIN_CS  10

DIYables_TFT_GC9A01_Round TFT_display(PIN_RST, PIN_DC, PIN_CS);

void setup() {
  Serial.println(F("Arduino TFT LCD Display - show text and float number"));

  TFT_display.begin();

  // Set the rotation (0 to 3)
  TFT_display.setRotation(1);  // Rotate screen 90 degrees
  TFT_display.fillScreen(WHITE);

  // Set text color and size
  TFT_display.setTextColor(MAGENTA);
  TFT_display.setTextSize(3);  // Adjust text size as needed

  // Sample temperature value
  float temperature = 23.5;
  float humidity = 78.6;

  // Display temperature with degree symbol
  TFT_display.setCursor(20, 20);    // Set cursor position (x, y)
  TFT_display.print("Temperature: ");
  TFT_display.print(temperature, 1);  // Print temperature with 1 decimal place
  TFT_display.print(char(247));
  TFT_display.println("C");

  // Display humidity
  TFT_display.setCursor(20, 60);    // Set cursor position (x, y)
  TFT_display.print("Humidity: ");
  TFT_display.print(humidity, 1);   // Print humidity with 1 decimal place
  TFT_display.print("%");
}

void loop(void) {
}
