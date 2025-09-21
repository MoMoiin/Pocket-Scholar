#include <Arduino.h>
#include "Controls/Config.h"
#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include "Display/DisplayManager.h"

void setup() {

  Serial.begin(115200);

  displayManager.init();

  pinMode(BUTTON_O_PIN, INPUT_PULLUP);
  pinMode(BUTTON_X_PIN, INPUT_PULLUP);
  pinMode(BUTTON_LEFT_PIN, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT_PIN, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
}

/* // put function definitions here:
int myFunction(int x, int y) {
  return x + y;
} */
