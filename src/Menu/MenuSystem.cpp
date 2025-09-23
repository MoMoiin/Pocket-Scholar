#include "Menu/MenuSystem.h"
#include "Display/DisplayManager.h"

namespace {
const char* const kMainMenuItems[MenuSystem::MainMenuItemCount] = {
    "Flashcards",
    "Decks",
    "Settings"
};
}

MenuSystem::MenuSystem(DisplayManager &display)
    : displayManager(display),
      currentPage(MenuPage::MAIN_MENU),
      selectedBox(0),
      selectedItem(0),
      settingsEditing(false),
      settingsTopIndex(0),
      lastFullRefresh(0) {}

void MenuSystem::begin() {
    currentPage = MenuPage::MAIN_MENU;
    selectedItem = 0;
    renderMainMenu();
}

void MenuSystem::handleInput(const ButtonEvent &event) {
    if (event.action != ButtonAction::Press) {
        return;
    }

    if (currentPage == MenuPage::MAIN_MENU) {
        switch (event.id) {
        case ButtonId::Left:
            moveSelection(-1);
            break;
        case ButtonId::Right:
            moveSelection(1);
            break;
        case ButtonId::Confirm:
            Serial.print(F("Selected menu item: "));
            Serial.println(kMainMenuItems[selectedItem]);
            break;
        case ButtonId::Cancel:
            Serial.println(F("Cancel pressed on main menu"));
            break;
        }
    }
}

void MenuSystem::navigateTo(MenuPage page) {
    currentPage = page;
    selectedItem = 0;
    refreshDisplay();
}

void MenuSystem::selectItem(int index) {
    if (index < 0) {
        index = 0;
    } else if (index >= static_cast<int>(MainMenuItemCount)) {
        index = static_cast<int>(MainMenuItemCount) - 1;
    }

    if (selectedItem != index) {
        selectedItem = index;
        refreshDisplay();
    }
}

void MenuSystem::editSettings() {
    settingsEditing = true;
}

void MenuSystem::refreshDisplay() {
    switch (currentPage) {
    case MenuPage::MAIN_MENU:
        renderMainMenu();
        break;
    default:
        break;
    }
}

void MenuSystem::renderMainMenu() {
    displayManager.showMainMenu(kMainMenuItems, MainMenuItemCount, selectedItem);
    lastFullRefresh = millis();
}

void MenuSystem::moveSelection(int delta) {
    int next = selectedItem + delta;
    if (next < 0) {
        next = 0;
    } else if (next >= static_cast<int>(MainMenuItemCount)) {
        next = static_cast<int>(MainMenuItemCount) - 1;
    }

    if (next != selectedItem) {
        selectedItem = next;
        renderMainMenu();
    }
}

