#include <Arduino.h>
#include "Controls/Config.h"
#include "Display/Display.h"
// put function declarations here:
int myFunction(int, int);

void setup() {

  // Display setup
  displayManager.init();
  displayManager.setRotation(1);
  displayManager.setFont(&FreeMonoBold9pt7b);
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    // Draw a simple loading circle
    display.drawCircle(64, 64, 20, GxEPD_BLACK);
    display.setCursor(40, 100);
    display.setTextSize(2);
    display.print("Loading...");
  } while (display.nextPage());

  pinMode(BUTTON_O_PIN, INPUT_PULLUP);
  pinMode(BUTTON_X_PIN, INPUT_PULLUP);
  pinMode(BUTTON_LEFT_PIN, INPUT_PULLUP);
  pinMode(BUTTON_RIGHT_PIN, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}