#pragma once
#include "state.h"
class EditTask : public State {
public:
	void execute() override;
	PossibleState leave() override;
};