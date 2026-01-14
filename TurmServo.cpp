#include "TurmServo.h"

void TurmServo::initServo(uint8_t servoPin)
{
    myServo.attach(servoPin);
    currentPos = 90;
    myServo.write(currentPos);
}

uint8_t TurmServo::readPos() const
{
    return currentPos;
}

uint8_t TurmServo::pitch(uint8_t target)
{
    if (target > 180)
        target = 180;

    while (currentPos != target)
    {
        myServo.write(currentPos);

        if (currentPos < target)
            currentPos++;
        else
            currentPos--;

        fastop::delay(10);
    }

    return currentPos;
}