#include "Display/DisplayManager.h"

// Global display manager instance used throughout the application
DisplayManager displayManager;

DisplayManager::DisplayManager()
    : epdDisplay(GxEPD2_213_B74(CS_PIN, DC_PIN, RST_PIN, BUSY_PIN)) {}

void DisplayManager::init() {
    epdDisplay.init();
    epdDisplay.setRotation(1);
    epdDisplay.setFullWindow();

    epdDisplay.firstPage();
    do {
        epdDisplay.fillScreen(GxEPD_WHITE);
    } while (epdDisplay.nextPage());

    u8g2.begin(epdDisplay);
    u8g2Ready = true;
}

