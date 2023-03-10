
#include<iostream>
#include "state.h"
//#include "askMenuOption.h"
//#include "addTask.h"

int main()
{
    StateMachine stateMachine = StateMachine(PossibleState::mainMenu);
    stateMachine.mainLoop();
}
