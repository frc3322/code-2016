#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            13
#define SHOOTER        12
#define NUMPIXELS      50

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10;
bool shooting = false;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  pinMode(SHOOTER, INPUT);
}

void loop() {
  shooting = (digitalRead(SHOOTER) == HIGH);
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
if(shooting){
   skipChase(pixels.Color(0, 0, 127), 25);
}
else {
    for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(0,120,255)); //(0, 120, 255) = Skyline Blue

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); 

  }
}
}

void skipChase(uint32_t c, uint8_t wait)
{
  for (int i = 0; i < 50; i++)
  {
    for (int j = 0; j < pixels.numPixels(); j++)
      pixels.setPixelColor(j, 0);
    for (int j = i & 3; j < pixels.numPixels(); j+=4)
      pixels.setPixelColor(j, c);
    pixels.show();
    delay(wait); 
  }
}
