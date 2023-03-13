#pragma once

#include "state.h"

class RemoveTask : public State {
    void execute() override;
    PossibleState leave() override;
};