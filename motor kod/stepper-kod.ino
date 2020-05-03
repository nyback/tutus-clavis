#include <Stepper.h>

#define NUM_STEPS 200
#define STEP 25

Stepper motor(NUM_STEPS, 10, 11, 12, 13);


void setup() {
  // put your setup code here, to run once:

  motor.setSpeed(100);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  motor.step(25);
  delay(1000);

}
