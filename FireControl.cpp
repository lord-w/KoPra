
#include <Turm_servo.h>
#include <TOF_sensor.h>
#include <asm.h>

struct zielPos{
  uint_16 x;
  uint_8  phi;
}


void Zielerfassung(TOF_sensor sensor, Turm_servo servo /*, Pumpe*/) //Sensor ausrichten und Scannen
{
  
  //Servo auf Startposition ausrichten
  servo.pitch(0);
  
  //Scanning 
  for(int i = 0; i < 180; i++){
    servo.myServo.write(pos);
    sensor.readDistance(); // <- speichern und vergleichen noch benötigt
    asm.delay(1);
  }

  //Servo auf Neutraleposition ausrichten
  servo.pitch(90);
}

void Feuern(uint_8 firingAngle, Turm_servo servo /*, Pumpe*/) //Düse ausrichten und feuern
{

  //Servo auf Feuerposition
  servo.pitch(firingAngle);

  //JIGGLE!
  for(int i = 0; i < 10; i++){
    sprayNPray(firingAngle, servo);
  }
  
}

uint_16 calculateFiringAngle(uint_16 distance; )
{

  //<- Schießkurve ermitteln lol

}

void sprayNPray(uint_8* firingAngle, Turm_servo servo /*, Pumpe*/){

  for (int i = 2; i > -2; i--){
    servo.myServo.write(&firingAngle + i);
    asm.delay(10);
  }

  for (int i = -2; i < 2; i++){
    servo.myServo.write(&firingAngle + i);
    asm.delay(10);
  }

}