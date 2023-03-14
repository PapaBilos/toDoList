#pragma once
#include"state.h"

class Terminate : public State {
public:
	void execute() override;
	PossibleState leave() override;
	void shutdown();
};