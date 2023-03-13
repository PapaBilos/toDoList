#include <iostream>
#include <map>

#include "askMenuOption.h"
#include "state.h"

void AskMenuOption::execute() {
    
}

PossibleState AskMenuOption::leave() {
    int userInput;
    static const std::map<int,PossibleState> nextStateMap {
        {1,PossibleState::mainMenu}
    };
    std::cout << "Select an option: ";
    std::cin >> userInput;

    PossibleState nextState = nextStateMap.at(userInput);
    return nextState;
}