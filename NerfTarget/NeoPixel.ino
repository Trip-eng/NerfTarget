#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define NeoLedPin    6
#define NeoLedCount 300


Adafruit_NeoPixel NeoStrip(NeoLedCount, NeoLedPin, NEO_GRB + NEO_KHZ800);

int NeoPartLength[4] = {5,4,3,2};
uint32_t NeoPartColor[4];

void NeoSetup()
{
  NeoStrip.begin();           
  NeoStrip.show();            
  NeoStrip.setBrightness(50); 

  NeoPartColor[0] = NeoStrip.Color(255,   0,   0);
  NeoPartColor[1] = NeoStrip.Color(128,   128,   0);
  NeoPartColor[2] = NeoStrip.Color(0,   250,   0);
  NeoPartColor[3] = NeoStrip.Color(128,   128,   128);

  //uint32_t = .Color(255,   0,   0)
  //.setPixelColor(i, color);  
  //.clear();  
  //.numPixels()
}

void NeoSetTarget()
{
   NeoStrip.setBrightness(50); 
  NeoSetColors(NeoPartColor);
}

void NeoSetSingel(int i)
{
  NeoStrip.setBrightness(100); 
  uint32_t c[] = {0,0,0,0};
  c[i] = NeoPartColor[i];
  NeoSetColors(c);
   
}

void NeoSetColors(uint32_t color[])
{
  int index = 0;
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < NeoPartLength[i]; j++)
    {
       NeoStrip.setPixelColor(index, color[i]); 
      index++;
    }
  }
  NeoStrip.show();  
}
