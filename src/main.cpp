/*
 * Demo for NeoPixel-Hexagon (Settlers of Catan)
 */

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN 2
#define PIXEL_CNT 37
#define PIXEL_CLR 0x31b784

/*
        (11)    (12)    (01)
          [01][02][03][04]
   (10) [05][06][07][08][09] (02)
      [10][11][12][13][14][15]
(09)[16][17][18][19][20][21][22](03)
      [23][24][25][26][27][28]
  (08 ) [29][30][31][32][33] (04)
          [34][35][36][37]
        (07)    (06)    (05)
 */

Adafruit_NeoPixel Hex(PIXEL_CNT, PIXEL_PIN, NEO_GRB+NEO_KHZ800);

void print_A() {
/*
      [01][02][03][04]
    [05][ ][  ][  ][09]
  [10][  ][  ][  ][  ][15]
[16][17][18][19][20][21][22]
  [23][  ][  ][  ][  ][28]
    [29][  ][  ][  ][33]
      [34][  ][  ][37]
 */
    const int arrSize = 21;
    int arr[arrSize] = {1,2,3,4,5,9,10,15,16,17,18,19,20,21,22,23,28,29,33,34,37};
    for (int i = 0; i < arrSize ; ++i)
        Hex.setPixelColor(arr[i], 49, 183, 132);
}

void print_B() {
/*
      [01][02][03][04]
    [05][06][  ][  ][09]
  [10][11][  ][  ][  ][15]
[16][17][18][19][20][21][  ]
  [23][24][  ][  ][  ][28]
    [29][30][  ][  ][33]
      [34][35][36][37]
 */
    bool arr[PIXEL_CNT] = {1, 1, 1, 1,
                         1, 1, 0, 0, 1,
                         1, 1, 0, 0, 0, 1,
                         1, 1, 1, 1, 1, 1, 0,
                         1, 1, 0, 0, 0, 1,
                         1, 1, 0, 0, 1,
                         1, 1, 1, 1};
    for (int i = 0; i < PIXEL_CNT; ++i)
        if (arr[i] == 1)
            Hex.setPixelColor(i, PIXEL_CLR);
}

void setup() {
    Serial.begin(115200);
    Hex.begin();
    Hex.show();
}

void loop() {
    Serial.println("Hello world!");
    Hex.setPixelColor(19, 255, 0, 0);
    Hex.show();
    delay(1000);
}
