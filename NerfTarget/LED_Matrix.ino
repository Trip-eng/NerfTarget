/* Di  = D11
 * CS  = D10
 * CLK = D13
 */

 
#include <SPI.h>
#include <Adafruit_GFX.h>  //https://github.com/adafruit/Adafruit-GFX-Library
#include <Max72xxPanel.h>  //https://github.com/markruys/arduino-Max72xxPanel

int MatrixPinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int MatrixNumberOfHorizontalDisplays = 4;
int MatrixNumberOfVerticalDisplays = 1;

Max72xxPanel matrix = Max72xxPanel(MatrixPinCS, MatrixNumberOfHorizontalDisplays, MatrixNumberOfVerticalDisplays);


int MatrixWait = 20; // In milliseconds

int MatrixCharacterSpacer = 1;
int MatrixCharacterWidth = 5 + MatrixCharacterSpacer; // The font width is 5 pixels

void MatrixSetup() {

  matrix.setIntensity(0); // Use a value between 0 and 15 for brightness
  for(int i = 0; i < MatrixNumberOfHorizontalDisplays; i++)
  {
    matrix.setRotation(i, 1);
  }
}

String MatrixText = "Nerf Target";

unsigned long MarixLastUpdate = 0;
int MatrixAnimationStep = 0;
int MartixMode = 2;


void MatrixLoop() {
  switch (MartixMode)
  {
    case 0:// off
      if(MatrixAnimationStep <= 0)
      {
        matrix.fillScreen(LOW); 
        matrix.write();
        MatrixAnimationStep = 1;
      }
      break;
    case 1: // Static Text
      if(MatrixAnimationStep <= 0)
      {
        matrix.fillScreen(LOW); 
        int x0 = (matrix.width() - MatrixTextLengthPx(MatrixText)) / 2; 
        for (int i = 0; i < MatrixText.length(); i++ )
        {
          matrix.drawChar(x0 + (i * MatrixCharacterWidth), 0, MatrixText[i], HIGH, LOW, 1);
        }
        matrix.write();
        MatrixAnimationStep = 1;
      }
      break;
    case 2: // Rolling Text
      if(millis() - MarixLastUpdate >= MatrixWait)
      {
         matrix.fillScreen(LOW);
         int letter = MatrixAnimationStep / MatrixCharacterWidth;
         int x = (matrix.width() - 1) - MatrixAnimationStep % MatrixCharacterWidth;
         int y = 0;//(matrix.height() - 8) / 2; // center the text vertically  
    
         while ( x + MatrixCharacterWidth - MatrixCharacterSpacer >= 0 && letter >= 0 ) {
           if ( letter < MatrixText.length() ) {
             matrix.drawChar(x, y, MatrixText[letter], HIGH, LOW, 1);
           }
    
           letter--;
           x -= MatrixCharacterWidth;
         }
    
         matrix.write(); // Send bitmap to display
         MarixLastUpdate = millis();
         MatrixAnimationStep ++;
         if(MatrixAnimationStep > MatrixCharacterWidth * MatrixText.length() + matrix.width() - 1 - MatrixCharacterSpacer) 
            MatrixAnimationStep = 0;
      }
      break;
  }
}


void MartixSetText(String text)
{
  MatrixText = text;
  if(matrix.width() < MatrixTextLengthPx(text))
  {
    MartixMode = 2; 
  }
  else
  {
    MartixMode = 1;
  }
  MatrixAnimationStep = 0;
  MarixLastUpdate = 0;
}

void MatrixSetLong(long number)
{
  MartixSetText(String(number));
}

//  --- Helper ---

int MatrixTextLengthPx(String text)
{
  return (text.length() * MatrixCharacterWidth) - MatrixCharacterSpacer;
}
