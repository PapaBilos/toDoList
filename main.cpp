#include<iostream>
#include "stateMachine.h"

int main()
{
    StateMachine stateMachine = StateMachine(PossibleState::mainMenu);
    stateMachine.mainLoop();
}
