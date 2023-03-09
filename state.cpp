#include <iostream>
#include "state.h"


void MainMenu::execute()
{
    //std::cout << "Now in Main Menu n\n Uga buga list of options\n";

}

PossibleState MainMenu::leave()
{
    return PossibleState::mainMenu;
}

void AddTask::execute()
{
    std::cout << "Now in Add Task\n\n Uga buga cos sie dziele!!!\n";
}

PossibleState AddTask::leave()
{
    return PossibleState::mainMenu;
}

// void AskMenuOption::execute() {
    
// }

// PossibleState AskMenuOption::leave() {
//     return
// }

//