#include <Wire.h>
#include <lookup.h>

  byte baitCounter[3]; //array holding bait counter
  byte baitUsed; //byte that holds the current bait being used
  byte numOfResets; //number of times counter has been reset
  boolean firstTime; //true if first time through loop
  byte useless; //byte that will hold what is returned when setting up the memory address for cheese counter; we don't need to use this otherwise

void setup() {
  firstTime = true; //will always be first time through loop at first
  numOfResets = 0; //there will always be a total of 0 resets at the start
  for(int i = 0; i < 3; i++) { //default values for counters should be 0
    baitCounter[i] = 0;
  }
  //will add below code when arduino-to-arduino connection is ready
  // Wire.begin();
  Serial.begin(9600);
}

void loop() {
  //will add below code when arduino-to-arduino connection is ready
  /* if(Wire.available()) {
    baitUsed = (byte)Wire.read();
    */

    //randomizes the bait used; will be removed once arduino-to-arduino connection is ready
    baitUsed = random(0, 4);
  
  //if it is the first time through the loop, set up the cheese counter memory address so that it starts at 0
  if(firstTime) {
    useless = encode(4);
    firstTime = false;
  }
  
  if(baitUsed == 3) { //if bait used indicates a reset
    useless = encode(baitUsed);
    for(int i = 0; i < 3; i++) { //default values for counters should be 0
      baitCounter[i] = 0;
    }
    numOfResets++; //increment reset counter
    Serial.println("Bait counter has been reset.");
	  Serial.print("Total Number of Times Reset: ");
	  Serial.println(numOfResets);
    Serial.println("-----------------------------");
  }
  
  else {
    baitCounter[baitUsed] = encode(baitUsed); //use assembly code to determine what bait should be incremented
    Serial.println("Bait counter stats:");
    Serial.print("Peanut Butter: ");
    Serial.println(baitCounter[0]);
    Serial.print("Beef Jerky: ");
    Serial.println(baitCounter[1]);
    Serial.print("Cheese: ");
    Serial.println(baitCounter[2]);
    Serial.println("-----------------------------");
  }
  
  delay(3000);
  
  }
  
//uncomment this when arduino-to-arduino connection is established }
