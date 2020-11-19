// --- variables ---

int buttonValue[4] = {1,3,5,10};


long colldown = 0;
long colldowntime = 200;

void setup() {
  MatrixSetup();
  ButtonSetup();
  NeoSetup();
  NeoSetTarget();
  //MatrixSetLong(123);
}

int rounds = 10;
long count = 0;

void loop() {
  MatrixLoop();
  ButtonLoop();
  
  if (colldown == 0)
  {
    for(int i = 3; i >=0 ; i--)
    {
      if(BottonWasPresst(i))
      {
        count += buttonValue[i];
        MatrixSetLong(count);
        colldown = millis();
        NeoSetSingel(i);
        break;
      }
    }
  }
  else if(millis() - colldown >= colldowntime)
  {
    BottonClearAll();
    NeoSetTarget();
    colldown = 0;
  }
}
