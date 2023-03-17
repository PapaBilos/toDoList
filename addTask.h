#pragma once

#include "state.h"

class AddTask : public State {
public:
	void execute() override;
	PossibleState leave() override;
};
