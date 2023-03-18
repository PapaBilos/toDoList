#pragma once

#include <map>
#include <functional>

//#include "askMenuOption.h"
//#include "addTask.h"
//#include "editTask.h"
//#include "removeTask.h"
//#include "terminate.h"

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
    // State();
    virtual ~State() = default;

    virtual void execute() = 0;
    virtual PossibleState leave() = 0;
};