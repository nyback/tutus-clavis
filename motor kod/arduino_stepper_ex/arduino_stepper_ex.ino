
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

//#include <Stepper.h>
//
//const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
//// for your motor
//
//// initialize the stepper library on pins 8 through 11:
//Stepper myStepper(stepsPerRevolution, 10, 11, 12, 13);
//
//void setup() {
//  // set the speed at 60 rpm:
//  myStepper.setSpeed(60);
//  // initialize the serial port:
//  Serial.begin(9600);
//}
//
//void loop() {
//  // step one revolution  in one direction:
//  Serial.println("clockwise");
//  myStepper.step(stepsPerRevolution);
//  delay(500);
//
//  // step one revolution in the other direction:
//  Serial.println("counterclockwise");
//  myStepper.step(-stepsPerRevolution);
//  delay(500);
//}

#include <AFMotor.h>

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(200, 1);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  motor.setSpeed(10);  // 10 rpm   
}

void loop() {
  Serial.println("Single coil steps");
  motor.step(100, FORWARD, SINGLE); 
  motor.step(100, BACKWARD, SINGLE); 

  Serial.println("Double coil steps");
  motor.step(100, FORWARD, DOUBLE); 
  motor.step(100, BACKWARD, DOUBLE);

  Serial.println("Interleave coil steps");
  motor.step(100, FORWARD, INTERLEAVE); 
  motor.step(100, BACKWARD, INTERLEAVE); 

  Serial.println("Micrsostep steps");
  motor.step(100, FORWARD, MICROSTEP); 
  motor.step(100, BACKWARD, MICROSTEP); 
}
