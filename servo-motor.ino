#include <Servo.h>


Servo myservo;  // create servo object to control a servo

// twelve servo objects can be created on most boards

int pos=0;


void setup() {

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);
  delay(1500);
  myservo.write(180);
delay(3000);
myservo.write(0);
delay(1000);
}


void loop() {


myservo.write(random(100));
pos++;
delay(500);
}