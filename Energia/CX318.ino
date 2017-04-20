// Sweep
// by BARRAGAN <http://barraganstudio.com>
// This example code is in the public domain.


#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// a maximum of eight servo objects can be created

int pos = 0;    // variable to store the servo position

int fleft = 0;
int left = 0;
int right = 0;
int fright = 0;

int angle = 0;

int speed = 0;

/*
*
* Project: Line Following Car - Group 45
* Module:  Servo & Motor control
* Last Updated on 20-04-2017
* Description of Last Update
* assigning steering angle and speed to each sensor.
*
*/
void setup()
{
    //set pins
    myservo.attach(P2_4);
    pinMode(P2_1, OUTPUT);
    pinMode(P1_6,INPUT);
    pinMode(P2_5,INPUT);
    pinMode(P2_2,INPUT);
    pinMode(P1_2,INPUT);

}


void loop()
{
    /**
    * Takes readings from all 4 sensor pins and sets old angle
    */
    fleft = !digitalRead(P1_6);
    left = !digitalRead(P2_5);
    right = !digitalRead(P2_2);
    fright = !digitalRead(P1_2);
    int oldA = angle;

    /**
     * old code, used for testing servo and/or drive. Left in in case needed.
     */
    //  for (int i = 75; i <= 105; i++) {
    //      angle = i;
    //      myservo.write(angle);
    //      delay(50);
    //  } for (int i = 105; i >= 75; i--) {
    //      angle = i;
    //      myservo.write(angle);
    //      delay(50);
    //  }
    //  analogWrite(P2_1,255);

    /**
    * uses pin readings to decide where to angle the steering, reduces speed as turn increases
    */
    if(left&&right){
        speed = 255;
        angle = 90;
    } else if(fleft){
        speed = 100;
        angle = 105;
    } else if(fright){
        speed = 100;
        angle = 75;
    } else if(left){
        speed = 190;
        angle = 80;
    } else if(right){
        speed = 190;
        angle = 100;
    } else if(fleft){
        speed = 100;
        angle = 105;
    } else if(fright){
        speed = 100;
        angle = 75;
    }


    /**
     * if angle has changed, set it
     */
    if(oldA != angle){
        analogWrite(P2_1,speed);
        myservo.write(angle);
    }
    delay(10);

}
