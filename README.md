# Arduino Mouse Trap
###### Official CIS126 Final Project by [Shane Staret](https://github.com/SStaret43), [Trush Patel](https://github.com/trushpatel1997), and [Chris Miller](https://github.com/chrism186). This projected was created through the use of Arduino and Assembly (using Microsoft Visual Studio and the AVR Assembler).
###### *We'd like to thank [Professor Robert Moyer](http://faculty.mc3.edu/rmoyer/) for helping us throughout this project.*
________________________________________________________________________________________________________________________________

#### Our mouse trap does exactly what you would expect it to. The way it works is that there is a ramp leading up to a small hallway with bait within it. Behind this bait is a distance sensor, which we use to detect how close the mouse is to our bait. Cleverly, we placed a trapdoor directly in front of the bait, so once the sensor notices the mouse is over the trapdoor, it quickly opens and then closes. This causes the mouse to fall below into a small and *safe* area where they can be held until released.

#### A servo connected to our first Arduino is used to open and close the trapdoor. This Arduino is also responsible for relaying what kind of bait was used to trap the mouse to the second Arduino. The second Arduino keeps track of how many times a particular bait (either peanut butter, beef jerky, or cheese) was effective in trapping a mouse. Once the area the caught mice are held in is full (about after five mice), the second Arduino lights up an LED indicating to the user of the mouse trap that the contraption is full and that the mice need to be released.

#### The vast majority of our code was created within the Arduino IDE, using C and C++ as programming languages.
