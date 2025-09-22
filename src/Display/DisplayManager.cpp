#include "Display/DisplayManager.h"
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>

// Global display manager instance used throughout the application
DisplayManager displayManager;

DisplayManager::DisplayManager(): epdDisplay(GxEPD2_213_B74(CS_PIN, DC_PIN, RST_PIN, BUSY_PIN)) {}

void DisplayManager::init() {
    epdDisplay.init();
    epdDisplay.setRotation(1);
    epdDisplay.setFullWindow();

    u8g2.begin(epdDisplay);
    u8g2Ready = true;
}



/* void DisplayManager::showMainMenu() {
    static const char* const kMenuItems[] = {
        "Flashcards",
        "Study Decks",
        "Settings",
    };
    constexpr size_t kMenuItemCount = sizeof(kMenuItems) / sizeof(kMenuItems[0]);
    constexpr size_t kSelectedIndex = 0;

    const int16_t screenWidth = epdDisplay.width();
    const int16_t titleLeft = 16;
    const int16_t titleBaseline = 32;

    epdDisplay.setFullWindow();
    epdDisplay.firstPage();
    do {
        epdDisplay.fillScreen(GxEPD_WHITE);

        epdDisplay.setFont(&FreeMonoBold9pt7b);
        epdDisplay.setTextColor(GxEPD_BLACK);
        epdDisplay.setCursor(titleLeft, titleBaseline);
        epdDisplay.print(F("Pocket Scholar"));

        epdDisplay.drawLine(titleLeft, titleBaseline + 4, screenWidth - titleLeft, titleBaseline + 4, GxEPD_BLACK);

        const int16_t menuLeft = 20;
        const int16_t menuWidth = screenWidth - (menuLeft * 2);
        const int16_t firstBaseline = titleBaseline + 30;
        const int16_t lineGap = 26;
        const int16_t boxHeight = 24;

        for (size_t index = 0; index < kMenuItemCount; ++index) {
            const bool isSelected = index == kSelectedIndex;
            const int16_t baseline = firstBaseline + static_cast<int16_t>(index) * lineGap;
            const int16_t boxTop = baseline - 18;

            if (isSelected) {
                epdDisplay.fillRect(menuLeft, boxTop, menuWidth, boxHeight, GxEPD_BLACK);
                epdDisplay.setTextColor(GxEPD_WHITE);
            } else {
                epdDisplay.drawRect(menuLeft, boxTop, menuWidth, boxHeight, GxEPD_BLACK);
                epdDisplay.setTextColor(GxEPD_BLACK);
            }

            epdDisplay.setCursor(menuLeft + 10, baseline);
            epdDisplay.print(kMenuItems[index]);
        }

        epdDisplay.setTextColor(GxEPD_BLACK);
    } while (epdDisplay.nextPage());
} */


