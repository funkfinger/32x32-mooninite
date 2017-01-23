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
  B00110000,
  B00110000,
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


void setup() {
  // uint8_t *ptr = matrix.backBuffer(); // Get address of matrix data
  // memcpy_P(ptr, img, sizeof(img));
  matrix.begin();
  
  // matrix.drawBitmap(0,0,bitmap,5,5,matrix.Color333(1,2,3));
  matrix.drawBitmap(3, 3, body, 24, 20, matrix.Color333(0,7,0));
  matrix.drawBitmap(2, 15, leftArmDown, 8, 6, matrix.Color333(0,0,7));
  matrix.drawBitmap(24, 8, rightArmUp, 8, 9, matrix.Color333(0,0,7));

  // left brow
  matrix.drawLine(11,9,9,11,matrix.Color333(0,0,7));
  matrix.drawLine(12,9,10,11,matrix.Color333(0,0,7));
  
  // right brow
  matrix.drawLine(17,9,19,11,matrix.Color333(0,0,7));
  matrix.drawLine(18,9,20,11,matrix.Color333(0,0,7));
  
  // eyes
  matrix.drawRect(11,12,3,2,matrix.Color333(0,0,7));
  matrix.drawRect(16,12,3,2,matrix.Color333(0,0,7));
  
  // mouth
  matrix.drawRect(11,17,8,3,matrix.Color333(0,0,7));
  
  // left foot
  matrix.drawRect(9,24,6,3,matrix.Color333(0,0,7));
  matrix.drawPixel(12,23,matrix.Color333(0,0,7));
  matrix.drawPixel(14,23,matrix.Color333(0,0,7));
  matrix.drawPixel(13,24,matrix.Color333(0,0,0));

  // right foot
  matrix.drawRect(16,24,6,3,matrix.Color333(0,0,7));
  matrix.drawPixel(16,23,matrix.Color333(0,0,7));
  matrix.drawPixel(18,23,matrix.Color333(0,0,7));
  matrix.drawPixel(17,24,matrix.Color333(0,0,0));
  
}

void loop() {
  
}