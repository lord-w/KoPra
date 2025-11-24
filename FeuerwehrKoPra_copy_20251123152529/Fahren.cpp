#include "Fahren.h"

Fahren::Fahren() {

}

//true -> vorwärts || false -> rückwärts (sollte man aber nicht verwenden)
void Fahren::moveGerade(bool dir) {
  if(dir) {
    digitalWrite(30, LOW);
    digitalWrite(31, HIGH);
    digitalWrite(31, LOW);
    digitalWrite(31, HIGH);
  }
  else {
    digitalWrite(30, HIGH);
    digitalWrite(31, LOW);
    digitalWrite(31, HIGH);
    digitalWrite(31, LOW);
  }
}

//true -> links || false -> rechts
//schaltet eines der Räder am um zu steuern
void Fahren::turn(bool dir) {
  if(dir) {
    digitalWrite(30, HIGH);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
  }
  else {
    digitalWrite(30, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, HIGH);
    digitalWrite(33, LOW);
  }
}

//true -> links || false -> rechts
//dreht die Räder in entgegengesetzte Richtungen um auf der Stelle zu drehen
void Fahren::rotate(bool dir) {
  if(dir) {
    digitalWrite(30, LOW);
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(33, LOW);
  }
  else {
    digitalWrite(30, HIGH);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, HIGH);
  }
}

void Fahren::stop() {
  digitalWrite(30, LOW);
  digitalWrite(31, LOW);
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);
}