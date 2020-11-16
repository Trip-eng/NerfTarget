// --- variables ---
bool buttonsPress[2];
int buttonValue[2] = {1,10};

long colldown = 0;
long colldowntime = 200;

void setup() {
  MatrixSetup();
  ButtonSetup();
  //MatrixSetLong(123);
}

long count = 0;

void loop() {
  MatrixLoop();
  ButtonLoop();
  
  if (colldown == 0)
  {
    for(int i = 0; i < 2; i++)
    {
      if(buttonsPress[i])
      {
        count += buttonValue[i];
        buttonsPress[i] = false;
        MatrixSetLong(count);
        colldown = millis();
        break;
      }
    }
  }
  else if(millis() - colldown >= colldowntime)
  {
    for(int i = 0; i < 2; i++)
    {
      buttonsPress[i] = 0;
    }
    colldown = 0;
  }
}
