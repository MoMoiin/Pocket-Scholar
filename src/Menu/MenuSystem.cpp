#include "Menu/MenuSystem.h"


MenuSystem::MenuSystem() : currentPage(MAIN_MENU), selectedBox(0), selectedItem(0), settingsEditing(false), settingsTopIndex(0), lastFullRefresh(0) {
}

void MenuSystem::HandleInput(char input) {
    if (input == "x") {
        // Handle 'x' button press
    } else if (input == "o") {
        // Handle 'o' button press
    } else if (input == "left") {
        // Handle 'left' button press
    } else if (input == "right") {
        // Handle 'right' button press
    }
}
