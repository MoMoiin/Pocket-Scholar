#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include <Arduino.h>

enum class MenuPage {
    MAIN_MENU,
    FLASHCARD_VIEWER,
    DECK_SELECTION,
    SETTINGS,
    // Add other pages as needed
};

class MenuSystem {
public:
    MenuSystem();
    // Add methods to navigate and interact with the menu system
    void navigateTo(MenuPage page);
    void selectItem(int index);
    void editSettings();
    void refreshDisplay();
private:
    MenuPage currentPage;
    int selectedBox;
    int selectedItem;
    bool settingsEditing;
    int settingsTopIndex;
    unsigned long lastFullRefresh;
};

#endif
