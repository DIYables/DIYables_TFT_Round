/*
   Created by DIYables

   This example code is in the public domain

   Product page:
   - https://diyables.io/products/1.28-inch-round-circular-tft-lcd-display-module
   - https://www.amazon.com/dp/B0F9NY6JZ6
*/

#include <DIYables_TFT_Round.h>

#define BLACK     DIYables_TFT::colorRGB(0, 0, 0)
#define BLUE      DIYables_TFT::colorRGB(0, 0, 255)
#define RED       DIYables_TFT::colorRGB(255, 0, 0)
#define GREEN     DIYables_TFT::colorRGB(0, 255, 0)
#define ORANGE    DIYables_TFT::colorRGB(255, 165, 0)
#define PINK      DIYables_TFT::colorRGB(255, 192, 203)
#define VIOLET    DIYables_TFT::colorRGB(148, 0, 211)
#define TURQUOISE DIYables_TFT::colorRGB(64, 224, 208)
#define WHITE     DIYables_TFT::colorRGB(255, 255, 255)

#define PIN_RST 8
#define PIN_DC 9
#define PIN_CS 10

DIYables_TFT_GC9A01_Round TFT_display(PIN_RST, PIN_DC, PIN_CS);

// Helper to draw a filled diamond
void fillDiamond(int cx, int cy, int h, int v, uint16_t color) {
  int x0 = cx, y0 = cy - v;
  int x1 = cx + h, y1 = cy;
  int x2 = cx, y2 = cy + v;
  int x3 = cx - h, y3 = cy;
  TFT_display.fillTriangle(x0, y0, x1, y1, x2, y2, color);
  TFT_display.fillTriangle(x0, y0, x2, y2, x3, y3, color);
}

void setup() {
  TFT_display.begin();
  TFT_display.setRotation(1); 
}

void loop() {
  TFT_display.fillScreen(BLACK);

  // Outlined circle (top left)
  TFT_display.drawCircle(35, 70, 20, RED);

  // Filled circle (top center)
  TFT_display.fillCircle(90, 70, 20, RED);

  // Outlined triangle (top right)
  TFT_display.drawTriangle(125, 50, 165, 50, 145, 90, BLUE);

  // Filled triangle (top far right)
  TFT_display.fillTriangle(175, 50, 215, 50, 195, 90, GREEN);

  // Outlined rectangle (middle left)
  TFT_display.drawRect(15, 110, 40, 25, ORANGE);

  // Filled rectangle (middle center)
  TFT_display.fillRect(70, 110, 40, 25, TURQUOISE);

  // Outlined round rectangle (middle right)
  TFT_display.drawRoundRect(125, 110, 40, 25, 8, VIOLET);

  // Filled round rectangle (middle far right)
  TFT_display.fillRoundRect(180, 110, 40, 25, 8, PINK);

  // Outlined diamond shape (bottom left)
  int cx1 = 80, cy1 = 180, h1 = 20, v1 = 25;
  TFT_display.drawLine(cx1, cy1 - v1, cx1 + h1, cy1, GREEN);
  TFT_display.drawLine(cx1 + h1, cy1, cx1, cy1 + v1, GREEN);
  TFT_display.drawLine(cx1, cy1 + v1, cx1 - h1, cy1, GREEN);
  TFT_display.drawLine(cx1 - h1, cy1, cx1, cy1 - v1, GREEN);

  // Filled diamond shape (bottom right)
  int cx2 = 160, cy2 = 180, h2 = 20, v2 = 25;
  fillDiamond(cx2, cy2, h2, v2, BLUE);

  delay(10000);
}