/*
   Created by DIYables

   This example code is in the public domain

   Product page:
   - https://diyables.io/products/1.28-inch-round-circular-tft-lcd-display-module
   - https://www.amazon.com/dp/B0F9NY6JZ6
*/

#include <DIYables_TFT_Round.h>

#define RED DIYables_TFT::colorRGB(255, 0, 0)
#define BLUE DIYables_TFT::colorRGB(0, 0, 255)
#define WHITE DIYables_TFT::colorRGB(255, 255, 255)

#define PIN_RST 8  // The Arduino pin connected to the RST pin of the circular TFT display
#define PIN_DC 9   // The Arduino pin connected to the DC pin of the circular TFT display
#define PIN_CS 10  // The Arduino pin connected to the CS pin of the circular TFT display

DIYables_TFT_GC9A01_Round TFT_display(PIN_RST, PIN_DC, PIN_CS);

void setup() {
  Serial.println(F("Arduino TFT LCD Display - show text and number"));

  TFT_display.begin();

  // Set the rotation (0 to 3)
  TFT_display.setRotation(1);  // Rotate screen 90 degrees
  TFT_display.fillScreen(WHITE);

  TFT_display.setTextSize(2);  // Adjust text size as needed

  // Sample temperature value
  float temperature = 26.4;
  float humidity = 64.7;

  // Display temperature with degree symbol
  TFT_display.setTextColor(RED);
  TFT_display.setCursor(5, 100);  // Set cursor position (x, y)
  TFT_display.print("Temperature: ");
  TFT_display.print(temperature, 1);  // Print temperature with 1 decimal place
  TFT_display.print(char(247));
  TFT_display.println("C");

  // Display humidity
  TFT_display.setTextColor(BLUE);
  TFT_display.setCursor(30, 140);  // Set cursor position (x, y)
  TFT_display.print("Humidity: ");
  TFT_display.print(humidity, 1);  // Print humidity with 1 decimal place
  TFT_display.print("%");
}

void loop(void) {
}
