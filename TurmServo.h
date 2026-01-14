#ifndef TURM_SERVO_H
#define TURM_SERVO_H

#include <Servo.h>
#include "fastop.h"

class TurmServo
{
  public:
    void    initServo(uint8_t servoPin);
    uint8_t readPos() const;
    uint8_t pitch(uint8_t target);

    Servo myServo;   // intentionally public (you use it directly)

  private:
    uint8_t currentPos = 90;
};

#endif