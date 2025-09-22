#pragma once

#include <Arduino.h>

enum class ButtonId : uint8_t { Confirm, Cancel, Left, Right };
enum class ButtonAction : uint8_t { Press, Release, LongPress, Repeat };

struct ButtonEvent { ButtonId id; ButtonAction action; uint32_t atMillis; };

#define Debounce_MS 15

class InputControls {
public:
    static constexpr uint8_t ButtonCount = 4;

    InputControls();
    void init();
    bool poll(ButtonEvent &event);

private:
    struct DebounceState {
        uint32_t lastChangeTime = 0;
        int lastReading = HIGH;
        int stableState = HIGH;
    };

    DebounceState states[ButtonCount];
};

extern InputControls inputcontrols;
