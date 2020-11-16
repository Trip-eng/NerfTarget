#define ButtonCount 4
#define Button1 2
#define Button3 3
#define Button5 4
#define Button10 5
int buttons[ButtonCount] = {Button10, Button5, Button3, Button1};
int buttonsLast[ButtonCount] ;

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
