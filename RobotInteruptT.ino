//Initiate and start libraries
#include <SoftwareSerial.h>
SoftwareSerial Soft_Serial(2,3);

//Declere variables
int pinLED = 9;
int pinButton = 7;
int LED = false;

//Declare time variable
uint32_t tMain;

void setup()
{  
  //Begin SoftwareSerial
  Soft_Serial.begin(19200);
  
  //Begin GPIO pins
  pinMode(pinLED, OUTPUT);
  pinMode(pinButton, INPUT);

  //Set internal pullup resistor high
  digitalWrite(pinButton, HIGH);
}

void loop()
{  
  //If the button is NOT pressed
  if (digitalRead(pinButton) == HIGH)
  {  
    //Set LED off
    digitalWrite(pinLED, LOW);

    //If 50 miliseconds has passed
    if (millis() > tMain + 50)
    {
      //Reset timer
      tMain = millis();

      //Send out life-sign
      Soft_Serial.print("?");

      //Pusle LED
      LED = !LED;
      digitalWrite(pinLED, LED);
    }
  }
  //If the button is pressed
  else
  {
    //Set LED on
    digitalWrite(pinLED, HIGH);
  }
}
