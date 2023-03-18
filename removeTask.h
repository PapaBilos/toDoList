#pragma once
#include"state.h"

class RemoveTask : public State {
public:
	void execute() override;
	PossibleState leave() override;
};