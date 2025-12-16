#include <Servo.h>
#include <asm.h>

Servo   myServo;
uint_8  currentPos;

void initServo (uint_8 ServoPin){

  myServo.attach(ServoPin);

}

uint_8 pitch (uint_8 pitch){

  if(currentPos - pitch >= 0){
    while (currentPos != pitch){
      myServo.write(currentPos);
      currentPos++;
      asm.delay(10);
    }
    return currentPos;
  }

  while (currentPos != pitch){
    myServo.write(currentPos);
    currentPos--;
    asm.delay(10);
  }
  return currentPos;

}