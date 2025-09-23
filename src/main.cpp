#include <Arduino.h>

#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include "Display/DisplayManager.h"
#include "Controls/inputControls.h"
#include "Menu/MenuSystem.h"

MenuSystem menuSystem(displayManager);

void setup() {
    Serial.begin(115200);

    displayManager.init();
    inputcontrols.init();

    menuSystem.begin();
}

void loop() {
    ButtonEvent evt;
    if (inputcontrols.poll(evt)) {
        menuSystem.handleInput(evt);
    }
}
