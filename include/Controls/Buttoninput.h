/* #include <Arduino.h>

enum class ButtonId : uint8_t { Confirm, Cancel, Left, Right };
enum class ButtonAction : uint8_t { Press, Release, LongPress, Repeat };

struct ButtonEvent { ButtonId id; ButtonAction action; uint32_t atMillis; };

class ButtonInput {
public:
    void begin();
    bool poll(ButtonEvent& outEvent);   // returns true while there are events to process
private:
    struct ButtonState {
        uint8_t pin;
        ButtonId id;
        bool activeLow;
        bool lastLevel;
        uint32_t lastTransition;
        bool longPressSent;
    };
    std::array<ButtonState, 4> buttons_;
    bool computeEvent(ButtonState&, ButtonEvent&);
}; */
