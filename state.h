#pragma once

#include <map>
#include <functional>
#include "mainMenu.h"

//#include "askMenuOption.h"
//#include "addTask.h"
// #include "editTask.h"
// #include "removeTask.h"
// #include "terminate.h"

enum class PossibleState {

    mainMenu,
    askMenuOption,
    //repeat, //think and add later
    addTask,
    editTask,
    removeTask,
    terminate
};

class State {
public:
    // State();
    virtual ~State() = default;

    virtual void execute() = 0;
    virtual PossibleState leave() = 0;
};

class StateMachine {
public:
    StateMachine(PossibleState initialState){
        currentState = stateMap.at(initialState)();
    }

    void mainLoop(){
        while(true){
            currentState->execute();
            PossibleState nextState = currentState->leave();
            delete currentState;
            currentState = stateMap.at(nextState)();
        }
    }
private:
    State* currentState;
    static State* createMainMenuState(){return new MainMenu();}
    const inline static std::map<PossibleState,std::function<State*()>> stateMap {
        {PossibleState::mainMenu,createMainMenuState}
        //{PossibleState::askMenuOption,[]{return new AskMenuOption();}},
        //{PossibleState::addTask,[]{return new AddTask();}}
        //,
        // {PossibleState::editTask,[]{return new EditTask();}},
        // {PossibleState::removeTask,[]{return new RemoveTask();}},
        // {PossibleState::terminate,[]{return new Terminate();}}
    };
};
