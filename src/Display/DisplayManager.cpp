#include "Display/DisplayManager.h"
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>

// Global display manager instance used throughout the application
DisplayManager displayManager;

DisplayManager::DisplayManager() : epdDisplay(GxEPD2_213_B74(CS_PIN, DC_PIN, RST_PIN, BUSY_PIN)) {}

void DisplayManager::init() {
    epdDisplay.init();
    epdDisplay.setRotation(1);
    epdDisplay.setFullWindow();

    u8g2.begin(epdDisplay);
    u8g2Ready = true;
}

void DisplayManager::showMainMenu(const char* const* items, size_t count, int selectedIndex) {
    if (!u8g2Ready || items == nullptr || count == 0) {
        return;
    }

    epdDisplay.setFullWindow();
    epdDisplay.firstPage();
    do {
        epdDisplay.fillScreen(GxEPD_WHITE);

        const int16_t displayWidth = epdDisplay.width();
        const int16_t headerHeight = 32;
        const int16_t itemHeight = 48;
        const int16_t verticalPadding = 6;
        const int16_t itemWidth = displayWidth / static_cast<int16_t>(count);

        epdDisplay.setTextColor(GxEPD_BLACK);
        epdDisplay.setFont(&FreeSansBold9pt7b);
        epdDisplay.setCursor(12, 24);
        epdDisplay.print(F("Pocket Scholar"));

        epdDisplay.setFont(&FreeMonoBold9pt7b);

        for (size_t i = 0; i < count; ++i) {
            const int16_t x = static_cast<int16_t>(i) * itemWidth;
            const int16_t y = headerHeight + verticalPadding;
            const bool selected = (static_cast<int>(i) == selectedIndex);
            const int16_t rectWidth = itemWidth - (verticalPadding * 2);

            if (selected) {
                epdDisplay.fillRect(x + verticalPadding, y, rectWidth, itemHeight, GxEPD_BLACK);
                epdDisplay.setTextColor(GxEPD_WHITE);
            } else {
                epdDisplay.drawRect(x + verticalPadding, y, rectWidth, itemHeight, GxEPD_BLACK);
                epdDisplay.setTextColor(GxEPD_BLACK);
            }

            epdDisplay.setCursor(x + (verticalPadding * 2), y + (itemHeight / 2) + 6);
            epdDisplay.print(items[i]);
        }

    } while (epdDisplay.nextPage());
}
