#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// ILI9341 display pins
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

// display dimensions
#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 320

// initialize display object
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// set starting point for flood fill
int x = 120;
int y = 160;

// define colors
uint16_t startColor = ILI9341_BLACK;
uint16_t fillColor = ILI9341_BLUE;

void setup() {
  // initialize serial port and display
  Serial.begin(9600);
  tft.begin();
  tft.setRotation(3);
}

void loop() {
  // fill the screen with white color

  // set starting color
  tft.fillRect(x, y, 1, 1, startColor);

  // perform flood fill algorithm
  bfsFill(x, y, startColor, fillColor);

  // pause for a moment
}

// breadth-first-search flood fill algorithm
void bfsFill(int x, int y, uint16_t startColor, uint16_t fillColor) {
  // create queue
  int queueX[1000];
  int queueY[1000];
  int queueHead = 0;
  int queueTail = 0;

  // check if starting point is already filled or outside display bounds

  // add starting point to queue
  queueX[queueTail] = x;
  queueY[queueTail] = y;
  queueTail++;

  // loop until queue is empty
  while (queueHead != queueTail) {
    // get next point from queue
    int currX = queueX[queueHead];
    int currY = queueY[queueHead];
    queueHead++;

    // fill current pixel with fill color
    tft.drawPixel(currX, currY, fillColor);

    // add neighboring points to queue
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
