#include <div.h>
#include <Servo.h>
#include <Wire.h>

const int pingPin = 7; // this constant won't change.  It's the pin number of the sensor's output
byte bait; //the bait that is being used to lure the rodents
int counter = 0; // keeps track of how many mice are in the trap
Servo myservo;  // create servo object to control a servo
div_t divCM; //holds the final quotient and remainder after duration is passed to "div" library
int CM; //holds the quotient from divCM
long duration; //holds how long it took for the wave emitted by the ultrasonic sensor to come back to the sensor

void setup() 
{
           // initialize serial communication:
           Serial.begin(9600);
           myservo.attach(9);  // attaches the servo on pin 9 to the servo object
           myservo.write(180); //immediately writes the servo to position 180
           Wire.begin();
}

void loop() 
{
  
           delay(100);
           
           //for our simulation, we will just randomly choose what bait is used each time
           bait = random(0,4);
          
           // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
           // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
           pinMode(pingPin, OUTPUT);
           digitalWrite(pingPin, LOW);
           delayMicroseconds(2);
           digitalWrite(pingPin, HIGH);
           delayMicroseconds(10);
           digitalWrite(pingPin, LOW);
           
           // The same pin is used to read the signal from the PING))): a HIGH
           // pulse whose duration is the time (in microseconds) from the sending
           // of the ping to the reception of its echo off of an object.
           pinMode(pingPin, INPUT);
           duration = pulseIn(pingPin, HIGH);
          
           // convert the time into a distance and print the distance of the closest object
           divCM = div(int(duration), 29);
           CM = divCM.quot;
           divCM = div(CM, 2);
           CM = divCM.quot;
           
           //print the distance of the closest object
           Serial.print("Closest object: ");
           Serial.print(CM);
           Serial.print("cm");
           Serial.println();
          
           delay(100);
          
           //if the distance sensor is sensing that there is something within 7 centimeters
           if(CM < 7 && CM >= 0)
           {
                  myservo.write(90); //servo goes to 90 degree, dropping the trap door
                  delay(2000); //wait 2 seconds to ensure that the mouse actually falls in
                      
                  //send out a pulse with the distance sensor again to check if something is still above the trap door
                  pinMode(pingPin, OUTPUT);
                  digitalWrite(pingPin, LOW);
                  delayMicroseconds(2);
                  digitalWrite(pingPin, HIGH);
                  delayMicroseconds(10);
                  digitalWrite(pingPin, LOW);
                  pinMode(pingPin, INPUT);
                  duration = pulseIn(pingPin, HIGH);
                      
                  divCM = div(int(duration), 29);
                  CM = divCM.quot;
                  divCM = div(CM, 2);
                  CM = divCM.quot;
                      
                  Serial.print(CM);
                  Serial.print("cm");
                  Serial.println();
                   
                    //if there is not something above the trap door, then the mouse was caught
                    if(CM >=7)
                    {
                      counter = counter + 1; //add 1 to the counter
                      Serial.println("Mouse has been trapped");
                      Serial.print("Number of mouse trapped so far ");
                      Serial.println(counter);
                               
                      //send the kind of bait that was used to trap the mouse to the Second Arduino
                      Wire.beginTransmission(8);
                      Wire.write(bait);
                      Wire.endTransmission();
                               
                        //if there are five rodents or more now captured
                        if(counter >= 5)
                        {
                          Serial.println("Too many mice in box");
                          delay(1000);
                          Serial.println("Emptying box...");
                          delay(1000);
                          Serial.println("Box Emptied");
                          counter = 0;
                        }
                    } 
           }
           
           //if there is not something above the trap door, don't drop it
           else
           {
                    delay(100);
                    myservo.write(180);
                    delay(100); 
           }
           
}
