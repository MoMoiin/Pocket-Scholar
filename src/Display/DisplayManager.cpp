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

void DisplayManager::showLoadingScreen(const char* message) {
    loadingActive = true;
    loadingMessage = message ? message : "Loading...";
    loadingProgress = 0;

    loadingWindowW = epdDisplay.width();
    loadingWindowH = epdDisplay.height() / 2;
    loadingWindowX = 0;
    loadingWindowY = (epdDisplay.height() - loadingWindowH) / 2;

    renderLoadingScreen();
}

void DisplayManager::updateLoadingProgress(uint8_t percent) {
    if (!loadingActive) {
        return;
    }

    percent = constrain(percent, static_cast<uint8_t>(0), static_cast<uint8_t>(100));
    if (percent == loadingProgress) {
        return;
    }

    loadingProgress = percent;
    renderLoadingScreen();
}

void DisplayManager::renderLoadingScreen() {
    if (loadingWindowW == 0 || loadingWindowH == 0) {
        loadingWindowX = 0;
        loadingWindowY = 0;
        loadingWindowW = epdDisplay.width();
        loadingWindowH = epdDisplay.height();
    }

    const char* message = loadingMessage.length() > 0 ? loadingMessage.c_str() : "Loading...";

    epdDisplay.setPartialWindow(loadingWindowX, loadingWindowY, loadingWindowW, loadingWindowH);
    epdDisplay.firstPage();
    do {
        epdDisplay.fillRect(loadingWindowX, loadingWindowY, loadingWindowW, loadingWindowH, GxEPD_WHITE);
        epdDisplay.setTextColor(GxEPD_BLACK);
        epdDisplay.setFont(&FreeMonoBold9pt7b);

        int16_t x1 = 0;
        int16_t y1 = 0;
        uint16_t w = 0;
        uint16_t h = 0;
        epdDisplay.getTextBounds(message, 0, 0, &x1, &y1, &w, &h);

        const int16_t centerX = (epdDisplay.width() - w) / 2 - x1;
        const int16_t centerY = (epdDisplay.height() + h) / 2 - y1 - 10;
        epdDisplay.setCursor(centerX, centerY);
        epdDisplay.println(message);

        const int16_t barWidth = epdDisplay.width() * 3 / 4;
        const int16_t barHeight = 12;
        const int16_t barX = (epdDisplay.width() - barWidth) / 2;
        const int16_t barY = centerY + 18;

        epdDisplay.drawRect(barX, barY, barWidth, barHeight, GxEPD_BLACK);

        const int16_t innerWidth = barWidth - 4;
        const int16_t filledWidth = (innerWidth * loadingProgress) / 100;
        if (filledWidth > 0) {
            epdDisplay.fillRect(barX + 2, barY + 2, filledWidth, barHeight - 4, GxEPD_BLACK);
        }
    } while (epdDisplay.nextPage());
}

void DisplayManager::setPartialWindow(int16_t x, int16_t y, int16_t w, int16_t h) {
    epdDisplay.setPartialWindow(x, y, w, h);
}

void DisplayManager::fillScreen(uint16_t color) {
    epdDisplay.fillScreen(color);
}

void DisplayManager::setCursor(int16_t x, int16_t y) {
    epdDisplay.setCursor(x, y);
}

void DisplayManager::setFont(const GFXfont* font) {
    epdDisplay.setFont(font);
}

void DisplayManager::setTextColor(uint16_t color) {
    epdDisplay.setTextColor(color);
}

void DisplayManager::print(const char* text) {
    epdDisplay.print(text);
}

void DisplayManager::println(const char* text) {
    epdDisplay.println(text);
}

void DisplayManager::setU8g2Font(const uint8_t* font) {
    if (!u8g2Ready) {
        u8g2.begin(epdDisplay);
        u8g2Ready = true;
    }
    u8g2.setFont(font);
}

void DisplayManager::printUTF8(const char* text) {
    if (!u8g2Ready) {
        u8g2.begin(epdDisplay);
        u8g2Ready = true;
    }
    u8g2.print(text);
}

void DisplayManager::printlnUTF8(const char* text) {
    if (!u8g2Ready) {
        u8g2.begin(epdDisplay);
        u8g2Ready = true;
    }
    u8g2.println(text);
}

void DisplayManager::drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color) {
    epdDisplay.drawBitmap(x, y, bitmap, w, h, color);
}

void DisplayManager::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    epdDisplay.fillRect(x, y, w, h, color);
}

void DisplayManager::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    epdDisplay.drawRect(x, y, w, h, color);
}

void DisplayManager::refresh(bool partial) {
    epdDisplay.display(partial);
}

void DisplayManager::setRotation(uint8_t rotation) {
    epdDisplay.setRotation(rotation);
}

int16_t DisplayManager::width() {
    return epdDisplay.width();
}

int16_t DisplayManager::height() {
    return epdDisplay.height();
}
