
#include <SoftwareSerial.h>
SoftwareSerial RFID(2, 3); // RX and TX
 
int i;
int c = 12;
int b = 0; 


void setup()
{
  RFID.begin(9600);    // start serial to RFID reader
  Serial.begin(9600);  // start serial to PC 
  pinMode (13, OUTPUT);
}
 
void loop()
{  
 start:
  if (RFID.available() > 0) 
  {
                          //*******************************************************************
     i = RFID.read();     // for multi person scanning, we would need to know the value of i
                          // we would then set i as a string, and use that as a comparator
                          // then if i is scanned, do this
                          // and if d is scanned, do this
                          // then at the end if i = 0 d = 0, then turn off light
    //      delay(100000);*********************************************************************
     Serial.print(i, DEC);
     Serial.print(" ");
     
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
   if (b==0){
     b = b + 1;
     digitalWrite(13, HIGH);
     delay(500);
   }
   if (b==1){
     b = b - 1;
     digitalWrite(13, LOW);
     delay(500);
   }
     
  //relay instructions
  
 //}
}
}


