#define ButtonCount 2
#define Button0 2
#define Button1 3
int buttons[ButtonCount] = {Button0, Button1};
int buttonsLast[ButtonCount] = {HIGH,HIGH}; 

void ButtonSetup()
{
  for (int i = 0; i < ButtonCount;i++)
  {
    pinMode(buttons[i], INPUT);
    digitalWrite(buttons[i], HIGH); 
    buttonsLast[i] = HIGH;
    buttonsPress[i] = false; 
  }
}
void ButtonLoop()
{
  for (int i = 0; i < ButtonCount;i++)
  {
    int buti = digitalRead(buttons[i]);
    if(buti == LOW && buttonsLast[i] == HIGH) 
    {
      buttonsPress[i] = true;
    }
    buttonsLast[i] = buti;
  }
}
