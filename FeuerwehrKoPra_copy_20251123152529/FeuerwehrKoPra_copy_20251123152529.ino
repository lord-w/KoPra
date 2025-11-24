//libraries
//-------------------------------------------------------------------------
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Pixy2.h>
#include <Wire.h>
#include <Servo.h>

#include "Fahren.h"

Fahren fahren;
Pixy2 mypixy;
Servo myservo;

//Variablen
//-------------------------------------------------------------------------
  //Längenangaben in mm

static short radAbstand = 250;
static short radUmfang = 200;
unsigned long boardTime;
unsigned long moveTime;
bool kiesErkennung;
bool kiesErkannt;
bool autoL;
bool autoSuchen;


void setup() {

  kiesErkennung = false;
  kiesErkannt = false;
  autoL = false;
  autoSuchen = false;

  //Wire
  Wire.begin();
  Wire.setClock(100000);

  //Serial
  Serial1.begin(9600);
  Serial1.println("Serial Started");
  Serial.begin(9600);
  Serial.println("Serial Started");
  Serial.println(Serial1.available());

  //PinModes
    //LED
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    //Motoren
    pinMode(30, OUTPUT);
    pinMode(31, OUTPUT);
    pinMode(32, OUTPUT);
    pinMode(33, OUTPUT);
    //Sensoren
    mypixy.init();
  
  //Servomotor
  myservo.attach(6);

}

void loop() {
  //getimete funktionen werden nicht über delay() sondern über eine Abfrage der timer Variable ausgesetzt, um multitasking zu ermöglichen

  //SerialBluetooth
  if(Serial1.available() > 0) {
    char DATA = Serial1.read();
    switch(DATA) {
      case 'w':
        fahren.stop();
        fahren.moveGerade(true);
        break;
      case 'a':
        fahren.stop();
        fahren.turn(true);
        break;
      case 'd':
        fahren.stop();
        fahren.turn(false);
        break;
      case 's':
        fahren.stop();
        break;
    }
  }

  //Kieserkennung
  //-----------------------------------------------------------------------
    //Kies wird von Sensoren: Gyro, Pixycam erkannt
  if(kiesErkennung) {
    if(kiesErkannt) {
      fahren.stop();
    }
    else {
      fahren.moveGerade(true);
    }
  }

  //Slalom
  //-----------------------------------------------------------------------
    //Motorsteuerung manuell

  //AutoLöschen
  //-----------------------------------------------------------------------
  if(autoL) {
    //vier Phasen
    //Suchen || Zielen || Schießen || Fahren
    if(autoSuchen) {
    //Suchen
      //sweeping von links nach rechts
      //aufzeichnung der Daten des Ultraschallsensors
      //Auswerten der Daten
      //zurückschwenken bis zu maximalem ausschlag
    //Zielen
      //kleiner Schwenk mit tof sensor
      //Bis maximaler Wert gefunden
    //Schießen
      //auwertung der Distanz
      //ausrichten der Düse
      //Schießen
    //Fahren
      //ausrichten an evtl Bodenmarkierungen
      //Fahren bis zum nächsten markierungspunkt
      //Suchen starten
    }
  }
}


