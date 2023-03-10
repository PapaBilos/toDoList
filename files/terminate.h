#pragma once
#include "state.h"

class Terminate : public State {
    void execute() override;
    PossibleState leave() override;
};