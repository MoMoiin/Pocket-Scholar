#ifndef CONFIG_H
#define CONFIG_H

// Display configuration
#define DISPLAY_WIDTH   250
#define DISPLAY_HEIGHT  122

// Storage configuration
// Chip Select pin for SD card (adjust for your board wiring)
#ifndef SD_CS_PIN
#define SD_CS_PIN 13
#endif

// Overwrite default internal deck on boot (for testing)
#ifndef OVERWRITE_DEFAULT_DECK
#define OVERWRITE_DEFAULT_DECK 1
#endif

// Button pins (ESP32)
// Active-low with internal pull-ups enabled in setup()
#ifndef BUTTON_O_PIN
#define BUTTON_O_PIN 25
#endif

#ifndef BUTTON_X_PIN
#define BUTTON_X_PIN 0
#endif

#ifndef BUTTON_LEFT_PIN
#define BUTTON_LEFT_PIN 32
#endif

#ifndef BUTTON_RIGHT_PIN
#define BUTTON_RIGHT_PIN 33
#endif

#endif
