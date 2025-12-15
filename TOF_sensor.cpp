#include <VL53L0X.h>

#define XSHUT_PIN = 7; //any digital pin connected to the xshut of the sensor

VL53L0X sensor;
bool powerON;

void TurnOn () {
  
  if(!powerON){pinmode(XSHUT, HIGH); initSensor(); powerON = true;}
  
}

void TurnOff () {

  if(powerON){pinmode(XSHUT, LOW);}

}

uint_16 readDistance (){

  if(!powerON){return -1;}
  uint_16 distance = sensor.readRangeContinuousMillimeters();
  if(sensor.timeoutOccured();){return -1}
  return distance;

}

void initSensor(){

  if(!sensor.init();)
  {
    Serial.println("Failed to detect and initialize VL53L0X");
    while(1) {} //death loop
  }

  sensor.setTimeout(500);

  // long range settings
  sensor.setSignalRateLimit(0.1);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);

  // reduce timing budget to 20 ms (default is about 33 ms)
  //sensor.setMeasurementTimingBudget(20000);

  // increase timing budget to 200 ms
  sensor.setMeasurementTimingBudget(200000);

}
