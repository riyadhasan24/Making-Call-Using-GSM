#include <SoftwareSerial.h>
SoftwareSerial MY_GSM(8, 9);

char Phone_No[] = "+8801730288553";
#define Button  A1 // This Button for call command

void setup() 
{ 
  Serial.begin(9600);
  MY_GSM.begin(9600);
  pinMode(Button, INPUT_PULLUP);
}

void loop() 
{
  if (digitalRead (Button) == LOW)
    {
      Make_Call(Phone_No);
    }
  delay(5);
}


void Make_Call(char *number) 
{
  MY_GSM.print("ATD + "); 
  MY_GSM.print(number); 
  MY_GSM.println(";");
  delay(15000);       // wait for 20 seconds...
  MY_GSM.println("ATH"); //hang up
  delay(100);
}
