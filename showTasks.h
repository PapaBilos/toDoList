#pragma once
#include "state.h"

class ShowTasks : public State {
public:
	void execute() override;
	PossibleState leave() override;
};