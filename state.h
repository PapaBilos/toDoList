#pragma once
#include <map>
#include <functional>

enum class PossibleState {
    mainMenu,
    showTasks,
    askMenuOption,
    repeat,
    addTask,
    editTask,
    removeTask,
    terminate
};

class State {
public:
    virtual ~State() = default;

    virtual void execute() = 0;
    virtual PossibleState leave() = 0;
};