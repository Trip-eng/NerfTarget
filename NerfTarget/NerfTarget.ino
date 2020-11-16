// --- variables ---
bool buttonsPress[4];
int buttonValue[4] = {10,5,3,1};

long colldown = 0;
long colldowntime = 200;

void setup() {
  MatrixSetup();
  ButtonSetup();
  //MatrixSetLong(123);
}

int rounds = 10;
long count = 0;

void loop() {
  MatrixLoop();
  ButtonLoop();
  
  if (colldown == 0)
  {
    for(int i = 0; i < 4; i++)
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
