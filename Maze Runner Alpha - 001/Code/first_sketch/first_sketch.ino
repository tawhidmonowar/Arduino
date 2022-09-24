#include <AFMotor.h>

AF_DCMotor motorLeft(3), motorRight(4);
int speed = 1000;

void setup() {

}

void loop() {
  
//  delay(3000);

  motorLeft.setSpeed(speed);
  motorLeft.run(FORWARD);
  motorRight.setSpeed(speed);
  motorRight.run(FORWARD);
  delay(5000);
  
  motorLeft.run(RELEASE);
  delay(200);
  motorLeft.run(BACKWARD);
  motorRight.run(FORWARD);
  delay(2000);
  motorRight.run(RELEASE);
  delay(200);
  motorLeft.run(FORWARD);
  motorRight.run(BACKWARD);
  delay(3000);

  motorLeft.setSpeed(speed);
  motorLeft.run(FORWARD);
  motorRight.setSpeed(speed);
  motorRight.run(FORWARD);

  delay(5000);

  motorLeft.run(RELEASE);
  delay(100);
  motorLeft.run(BACKWARD);
  motorRight.run(FORWARD);
  delay(350);



}
