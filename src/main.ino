#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>
#include <avr/pgmspace.h>

#define CLK 8
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 32);

uint16_t green = matrix.Color333(0,2,0);
uint16_t blue = matrix.Color333(0,0,2);
uint16_t black = matrix.Color333(0,0,0);
uint16_t red = matrix.Color333(2,0,0);
uint16_t white = matrix.Color333(2,2,2);

static const unsigned char PROGMEM body[] = {
  B00000001, B11100000, B11110000,
  B00000001, B00110000, B10010000,
  B00000001, B00010111, B10010000,
  B00011111, B00011100, B00010000,
  B00010000, B00000000, B00010000,
  B00010000, B00000000, B00010000,
  B00011000, B00000000, B00010000,
  B00001000, B00000000, B00010000,
  B00001000, B00000000, B00010000,
  B00001000, B00000000, B00010000,
  B00001000, B00000000, B00010000,
  B00001000, B00000000, B00011000,
  B00011000, B00000000, B00001000,
  B00010000, B00000000, B00001000,
  B00010000, B00000000, B00001000,
  B00010000, B00000000, B00001000,
  B00010000, B00000000, B00001000,
  B00010000, B00000000, B00001000,
  B00010000, B00000000, B00001000,
  B00011111, B11111111, B11111000
};

static const unsigned char PROGMEM leftArmDown[] = {
  B01100000,
  B01100000,
  B11000000,
  B11000000,
  B11000000,
  B11000000
};

static const unsigned char PROGMEM rightArmUp[] = {
  B00100000,
  B00100000,
  B00100000,
  B11110000,
  B01100000,
  B01100000,
  B01100000,
  B11100000,
  B11100000
};

static const unsigned char PROGMEM rightArmUpErr[] = {
  B00010000,
  B00010000,
  B00010000,
  B01111000,
  B00110000,
  B00110000,
  B00110000,
  B11100000,
  B11000000
};

static const unsigned char PROGMEM leftFoot[] = {
  B00010100,
  B11110100,
  B10000100,
  B11111100
};

static const unsigned char PROGMEM rightFoot[] = {
  B10100000,
  B10111100,
  B10000100,
  B11111100
};


void setup() {
  // uint8_t *ptr = matrix.backBuffer(); // Get address of matrix data
  // memcpy_P(ptr, img, sizeof(img));
  
  matrix.begin();
  
}

void drawErr(uint8_t  xOffset = 0, uint8_t yOffset = 0) {
  // draw body  
  matrix.drawLine(3 + xOffset, 3 + yOffset, 13 + xOffset, 3 + yOffset, red);
  matrix.drawLine(13 + xOffset, 2 + yOffset, 13 + xOffset, 0 + yOffset, red);
  matrix.drawLine(14 + xOffset, 0 + yOffset, 17 + xOffset, 0 + yOffset, red);
  matrix.drawLine(17 + xOffset, 1 + yOffset, 17 + xOffset, 7 + yOffset, red);
  matrix.drawLine(18 + xOffset, 7 + yOffset, 20 + xOffset, 7 + yOffset, red);
  matrix.drawLine(20 + xOffset, 8 + yOffset, 20 + xOffset, 19 + yOffset, red);
  matrix.drawLine(3 + xOffset, 4 + yOffset, 3 + xOffset, 19 + yOffset, red);
  matrix.drawLine(4 + xOffset, 19 + yOffset, 19 + xOffset, 19 + yOffset, red);
  
  // left arm
  matrix.drawLine(xOffset, 13 + yOffset, xOffset, 16 + yOffset, blue);
  matrix.drawLine(1 + xOffset, 12 + yOffset, 1 + xOffset, 16 + yOffset, blue);
  matrix.drawLine(2 + xOffset, 12 + yOffset, 2 + xOffset, 13 + yOffset, blue);
  
  // right arm
  matrix.drawBitmap(21 + xOffset, 5 + yOffset, rightArmUpErr, 8, 9, blue);
  
  // left foot
  matrix.drawBitmap(5 + xOffset, 20 + yOffset, leftFoot, 8, 4, blue);

  // right foot
  matrix.drawBitmap(12 + xOffset, 20 + yOffset, rightFoot, 8, 4, blue);
  
  // eyes
  matrix.drawRect(6 + xOffset,10 + yOffset,2,3,blue);
  matrix.drawRect(15 + xOffset,10 + yOffset,2,3,blue);
  
  // brows
  matrix.drawLine(7 + xOffset, 7 + yOffset, 9 + xOffset, 10 + yOffset, blue);
  matrix.drawLine(8 + xOffset, 7 + yOffset, 10 + xOffset, 10 + yOffset, blue);
  matrix.drawLine(14 + xOffset, 7 + yOffset, 12 + xOffset, 10 + yOffset, blue);
  matrix.drawLine(15 + xOffset, 7 + yOffset, 13 + xOffset, 10 + yOffset, blue);
  
  // mouth
  matrix.drawRect(7 + xOffset, 15 + yOffset, 9, 3, blue);
  
}

void drawIgnignot(uint8_t xOffset = 0, uint8_t yOffset = 0) {
  matrix.drawBitmap(0 + xOffset, yOffset, body, 24, 20, green);
  matrix.drawBitmap(xOffset, 12 + yOffset, leftArmDown, 8, 6, blue);
  matrix.drawBitmap(21 + xOffset, 5 + yOffset, rightArmUp, 8, 9, blue);
  
  // eyes
  matrix.drawRect(7 + xOffset,8 + yOffset,3,2,blue);
  matrix.drawRect(13 + xOffset,8 + yOffset,3,2,blue);
  
  // mouth
  matrix.drawRect(7 + xOffset,13 + yOffset,9,3,blue);

  // left brow
  matrix.drawLine(5 + xOffset,7 + yOffset,7 + xOffset,5 + yOffset,blue);
  matrix.drawLine(6 + xOffset,7 + yOffset,8 + xOffset,5 + yOffset,blue);

  // right brow
  matrix.drawLine(17 + xOffset,7 + yOffset,15 + xOffset,5 + yOffset,blue);
  matrix.drawLine(16 + xOffset,7 + yOffset,14 + xOffset,5 + yOffset,blue);

  
  // left foot
  matrix.drawBitmap(5 + xOffset, 20 + yOffset, leftFoot, 8, 4, blue);

  // right foot
  matrix.drawBitmap(12 + xOffset, 20 + yOffset, rightFoot, 8, 4, blue);
}


void loop() {

  uint8_t x = 3;
  uint8_t y = 0;
  uint8_t xMove = 1;
  uint8_t yMove = 1;

  uint8_t counter = 0;
  int switchCharacter = 1;
  
  for(;;){
    counter++;
    if (counter == 4) {
      switchCharacter = switchCharacter * -1;
      counter = 0;
    }
    if (x > 5) {
      xMove = -1;
    }
    if (y > 7) {
      yMove = -1;
    }
    if (x < 1) {
      xMove = 1;
    }
    if (y < 1) {
      yMove = 1;
    }
    x = x + xMove;
    y = y + yMove;
    matrix.fillRect(0,0,32,32,black);
    // drawIgnignot(x, y);
    switchCharacter > 0 ? drawErr(x, y) : drawIgnignot(x, y);
    delay(2000);
  }
}


