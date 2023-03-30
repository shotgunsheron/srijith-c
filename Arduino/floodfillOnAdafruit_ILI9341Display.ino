#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// ILI9341 display pins
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 320

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

int x = 120;
int y = 160;

uint16_t startColor = ILI9341_BLACK;
uint16_t fillColor = ILI9341_BLUE;

void setup() {
  Serial.begin(9600);
  tft.begin();
  tft.setRotation(3);
}

void loop() {

  tft.fillRect(x, y, 1, 1, startColor);

  bfsFill(x, y, startColor, fillColor);

}

void bfsFill(int x, int y, uint16_t startColor, uint16_t fillColor) {
  int queueX[1000];
  int queueY[1000];
  int queueHead = 0;
  int queueTail = 0;

  queueX[queueTail] = x;
  queueY[queueTail] = y;
  queueTail++;

  while (queueHead != queueTail) {
    int currX = queueX[queueHead];
    int currY = queueY[queueHead];
    queueHead++;
    tft.drawPixel(currX, currY, fillColor);

    if (true) {
      queueX[queueTail] = currX + 1;
      queueY[queueTail] = currY;
      queueTail++;
    }
    if (true) {
      queueX[queueTail] = currX - 1;
      queueY[queueTail] = currY;
      queueTail++;
    }
    if (true) {
      queueX[queueTail] = currX;
      queueY[queueTail] = currY + 1;
      queueTail++;
    }
    if (true) {
      queueX[queueTail] = currX;
      queueY[queueTail] = currY - 1;
    }

  }

}
