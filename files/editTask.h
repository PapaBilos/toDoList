#pragma once
#include "state.h"

class EditTask : public State {
    void execute() override;
    PossibleState leave() override;
};