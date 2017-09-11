
#include <SoftwareSerial.h>
SoftwareSerial RFID(2, 3); // RX and TX
 
int i;
int c =12;
int b; 
void setup()
{
  RFID.begin(9600);    // start serial to RFID reader
  Serial.begin(9600);  // start serial to PC 
}
 
void loop()
{
 start:
  if (RFID.available() > 0) 
  {

     i = RFID.read();
    //      delay(100000);
     Serial.print(i, DEC);
     Serial.print(" ");
     int i=0;
     c = c - 1;            //manipulation of c
     Serial.println(c);    // printed c for debugging
  //for (b=c; b<0; b--)    //set b = to c in order to manipulate outside of the for loop  NOT NEEDED ANYMORE THANKS KENNETH :D
   if (c < 0)              // if statement performs same actions as for, just makes more sense
    {
       c=13;         // set c=9 to reset c counter diff from var declaration, "weed"
     delay(500);
     goto bailout;         
    
    }
    
  }
// if(RFID.available() == 0)
// {
  if (RFID.available() < -9000) // its to seperate it from the whole statment so it is not used when the rfid breaks
  {
  bailout:
  Serial.print("kenneth :D");   //For our purpose, this would be replaced with high signal to the relay
  delay(500);
  goto start;
  //relay instructions
  
 //}
}
}
