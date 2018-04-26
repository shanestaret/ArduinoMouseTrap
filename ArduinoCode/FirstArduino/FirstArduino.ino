#include <div.h>
#include <Servo.h>
#include <Wire.h>
// this constant won't change.  It's the pin number
// of the sensor's output:
const int pingPin = 7;
int counter = 0;
Servo myservo;  // create servo object to control a servo
div_t divCM;
int CM,test;
long duration;
int previousMotionState;
void setup() 
{
           // initialize serial communication:
           Serial.begin(9600);
           myservo.attach(9);  // attaches the servo on pin 9 to the servo object
           myservo.write(180);
           Wire.begin();
}
void loop() 
{
  
           delay(100);
             // establish variables for duration of the ping,
           // and the distance result in inches and centimeters:
           long cm;
          
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
          
           // convert the time into a distance
           divCM = div(int(duration), 29);
           CM = divCM.quot;
           divCM = div(CM, 2);
           CM = divCM.quot;
           test = duration/29/2;
           Serial.print(test);
           Serial.print(" ");
           Serial.print(CM);
           Serial.print("cm");
           Serial.println();
          
           delay(100);
          
           if(CM < 6 && CM >= 0) {
                  myservo.write(90); //servo goes to 90 degree
                  delay(10000);
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
                  test = duration/29/2;
                  Serial.print(test);
                  Serial.print(" ");
                  Serial.print(CM);
                  Serial.print("cm");
                  Serial.println();
                   
                    if(CM >=6){
                    counter = counter + 1; //add 1 to the counter
                      Serial.println("Mouse has been trapped");
                      Serial.print("Number of mouse trapped so far ");
                      Serial.println(counter);
                        if(counter >= 5){
                          Serial.println("Too many mice in box");          
                        }
                    } 
           
           }else{
                    delay(3000);
                    delay(100);
                    myservo.write(180);
                    delay(100); 
           }
           Wire.write(bait);
           
}
