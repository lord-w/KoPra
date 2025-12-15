#include <VL53L0X.h>

class TOF_sensor
{
  public:

    void      TurnOn ();
    void      TurnOff ();
    uint_16   readDistance ();  //returns range in mm
    void      initSensor ();    //before using this fcn Wire.begin needs to be conducted

  private:

    VL53L0X   sensor;
    bool      powerON;
    
}