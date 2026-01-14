
#include "TurmServo.h"
#include "TOFsensor.h"
#include "fastop.h"

#define G_EARTH 9.81
#define Y_0     0

struct zielPos{
  int    x;
  short  phi;
};

int pos;


void Zielerfassung(TOFsensor& sensor, TurmServo& servo)
{
    servo.pitch(0);

    for (int i = 0; i < 180; i++)
    {
        servo.myServo.write(i);
        sensor.readDistance();
        fastop::delay(1);
    }

    servo.pitch(90);
}

void sprayNPray(short* firingAngle, TurmServo servo /*, Pumpe*/){

  for (int i = 2; i > -2; i--){
    servo.myServo.write(&firingAngle + i);
    fastop::delay(10);
  }

  for (int i = -2; i < 2; i++){
    servo.myServo.write(&firingAngle + i);
    fastop::delay(10);
  }

}

void Feuern(short firingAngle, TurmServo servo /*, Pumpe*/) //Düse ausrichten und feuern
{

  //Servo auf Feuerposition
  servo.pitch(firingAngle);

  //JIGGLE!
  for(int i = 0; i < 10; i++){
    sprayNPray(firingAngle, servo);
  }
  
}

uint16_t calculateFiringAngle(uint16_t distance, uint8_t phi, uint16_t muzzle_vel)
{
  uint16_t alpha;
  
  uint16_t x_z = distance * cos(phi);
  uint16_t y_z = distance * sin(phi);
  uint16_t gxz = G_EARTH*pow(x_z, 2)/(2*pow(muzzle_vel, 2));

  alpha = (uint16_t)atan((x_z - sqrt((pow(x_z, 2), - 4*gxz*(Y_0 - y_z - gxz)))*1/gxz)); //Winkelberechnung

  return alpha;
}

