#include "Controls/inputControls.h"
#include "Controls/Config.h"

InputControls inputcontrols;

namespace {
constexpr uint8_t ButtonPins[InputControls::ButtonCount] = {
    BUTTON_O_PIN,
    BUTTON_X_PIN,
    BUTTON_LEFT_PIN,
    BUTTON_RIGHT_PIN
};
}

InputControls::InputControls() = default;

void InputControls::init() {
    for (uint8_t i = 0; i < ButtonCount; ++i) {
        pinMode(ButtonPins[i], INPUT_PULLUP);
        int reading = digitalRead(ButtonPins[i]);
        states[i].lastReading = reading;
        states[i].stableState = reading;
        states[i].lastChangeTime = millis();
    }
}

bool InputControls::poll(ButtonEvent &event) {
    uint32_t now = millis();

    for (uint8_t i = 0; i < ButtonCount; ++i) {
        int reading = digitalRead(ButtonPins[i]);
        DebounceState &state = states[i];

        if (reading != state.lastReading) {
            state.lastReading = reading;
            state.lastChangeTime = now;
        }

        if ((now - state.lastChangeTime) > Debounce_MS && reading != state.stableState) {
            state.stableState = reading;

            event.id = static_cast<ButtonId>(i);
            event.action = (reading == LOW) ? ButtonAction::Press : ButtonAction::Release;
            event.atMillis = now;
            return true;
        }
    }

    return false;
}
