#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <GxEPD2_BW.h>
#include <U8g2_for_Adafruit_GFX.h>

// Pin definitions
#define CS_PIN    5
#define DC_PIN    17
#define RST_PIN   16
#define BUSY_PIN  4

class DisplayManager {
public:
    DisplayManager();
    void init();
    void showMainMenu();
    void showLoadingScreen(const char* message = nullptr);
    void updateLoadingProgress(uint8_t percent);
    void setPartialWindow(int16_t x, int16_t y, int16_t w, int16_t h);
    void fillScreen(uint16_t color);
    void setCursor(int16_t x, int16_t y);
    void setFont(const GFXfont* font);
    void setTextColor(uint16_t color);
    void print(const char* text);
    void println(const char* text);
    void setU8g2Font(const uint8_t* font);
    void printUTF8(const char* text);
    void printlnUTF8(const char* text);
    void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color);
    void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    void refresh(bool partial = false);
    void setRotation(uint8_t rotation);
    int16_t width();
    int16_t height();

private:
    void renderLoadingScreen();

    GxEPD2_BW<GxEPD2_213_B74, GxEPD2_213_B74::HEIGHT> epdDisplay;
    U8G2_FOR_ADAFRUIT_GFX u8g2;
    bool u8g2Ready = false;
    bool loadingActive = false;
    String loadingMessage;
    uint8_t loadingProgress = 0;
    int16_t loadingWindowX = 0;
    int16_t loadingWindowY = 0;
    int16_t loadingWindowW = 0;
    int16_t loadingWindowH = 0;
};

extern DisplayManager displayManager;

#endif
// End of Display.h
