#include <iostream>
#include "mainMenu.h"
#include "state.h"

void MainMenu::execute() {
    const std::string version = "v. UGA_BUGA";
    const std::string mainMenuOptions = "Welcome to toDoList (" + version + ")\n"
        "1. Add task\n"
        "2. Show task(s)\n"
        "3. Edit task\n"
        "4. Remove task\n"
        "5. Quit program\n";
    std::cout << mainMenuOptions;
}

PossibleState MainMenu::leave() {
	return PossibleState::askMenuOption;
}