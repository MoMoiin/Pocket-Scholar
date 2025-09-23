#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include <Arduino.h>
#include "Controls/inputControls.h"

class DisplayManager;

enum class MenuPage {
    MAIN_MENU,
    FLASHCARD_VIEWER,
    DECK_SELECTION,
    SETTINGS,
};

class MenuSystem {
public:
    static constexpr size_t MainMenuItemCount = 3;

    MenuSystem(DisplayManager &display);

    void begin();
    void handleInput(const ButtonEvent &event);
    void navigateTo(MenuPage page);
    void selectItem(int index);
    void editSettings();
    void refreshDisplay();

private:
    void renderMainMenu();
    void moveSelection(int delta);

    DisplayManager &displayManager;
    MenuPage currentPage;
    int selectedBox;
    int selectedItem;
    bool settingsEditing;
    int settingsTopIndex;
    unsigned long lastFullRefresh;
};

#endif
