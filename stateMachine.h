#pragma once

#include"state.h"
#include"mainMenu.h"
#include"addTask.h"
#include"askMenuOption.h"
#include"showTasks.h"
#include"editTask.h"
#include"removeTask.h"
#include"terminate.h"

class StateMachine {
public:
    StateMachine(PossibleState initialState) {
        currentState = stateMap.at(initialState)();
    }

    void mainLoop() {
        while (true) {
            currentState->execute();
            PossibleState nextState = currentState->leave();
            delete currentState;
            currentState = stateMap.at(nextState)();
        }
    }
private:
    State* currentState;
    static State* createMainMenuState() { return new MainMenu(); }

    const inline static std::map<PossibleState, std::function<State* ()>> stateMap{
        {PossibleState::mainMenu,createMainMenuState},
        {PossibleState::addTask,[]{return new AddTask();}},
        {PossibleState::askMenuOption,[] {return new AskMenuOption(); }},
        {PossibleState::showTasks,[]{return new ShowTasks(); }},
        {PossibleState::editTask,[]{return new EditTask();}},
        {PossibleState::removeTask,[]{return new RemoveTask();}},
        {PossibleState::terminate,[]{return new Terminate();}}
    };
};
