/*

  Fahren.h - Library for fahren das Fahrzeug.

  Created by Jakob Hawlat, November 24 2025.

  Not released into the public domain.

*/

#ifndef FAHREN_H
#define FAHREN_H

#include <Arduino.h>

class Fahren
{
  public:
    //Constructor
    Fahren();
    //Methoden
    void moveGerade(bool dir);
    void turn(bool dir);
    void rotate(bool dir);
    void stop();
  private:
};

#endif