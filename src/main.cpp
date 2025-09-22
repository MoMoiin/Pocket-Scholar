#include <Arduino.h>

#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include "Display/DisplayManager.h"
#include "Controls/inputControls.h"

void setup() {

  Serial.begin(115200);

  displayManager.init();
  inputcontrols.init();

}

void loop() {




/*     ButtonEvent evt;
    if (inputcontrols.poll(evt)) {
        Serial.print("Button ");
        Serial.print(static_cast<int>(evt.id));
        Serial.print(" action ");
        Serial.print(static_cast<int>(evt.action));
        Serial.print(" at ");
        Serial.println(evt.atMillis);
    } */
}
