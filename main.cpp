
#include<iostream>
#include "state.h"


int main()
{
    StateMachine stateMachine = StateMachine(PossibleState::mainMenu);
    stateMachine.mainLoop();
}
