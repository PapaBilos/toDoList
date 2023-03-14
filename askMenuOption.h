#pragma once
#include "state.h"

class AskMenuOption : public State {

public:
	void execute() override;
	PossibleState leave() override;

	void nextStateSelection();
private:
	PossibleState nextState{};
};