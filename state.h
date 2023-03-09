#pragma once

#include <map>
#include <functional>

enum class PossibleState {
    mainMenu,
    askMenuOtion,
    repeat,
    addTask,
    editTask,
    removeTask,
    shutdown
};

class State {
public:
    // State();
    virtual ~State() = default;

    virtual void execute() = 0;
    virtual PossibleState leave() = 0;
};

class MainMenu : public State {
public:
    //MainMenu();
    int i;
    void execute() override;
    PossibleState leave() override;
    
};

class AddTask : public State {
public:
    //AddTask();

    void execute() override;
    PossibleState leave() override;
};

class AskMenuOption : public State {
    public:

    void execute() override;
    PossibleState leave() override;
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
        {PossibleState::mainMenu,createMainMenuState},
        {PossibleState::addTask,[]{return new AddTask();}},
    };
};
