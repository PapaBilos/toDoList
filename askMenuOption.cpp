#pragma once
#include <iostream>
#include <map>

#include "askMenuOption.h"

void AskMenuOption::execute() {
	std::cout << "Choose option: ";
}

PossibleState AskMenuOption::leave() {
	int inputOption;
	std::cin >> inputOption;

	PossibleState nextState;
	std::map<int, PossibleState> nextStateMap{
		{1, PossibleState::addTask},
		{2, PossibleState::showTasks},
		{3, PossibleState::editTask}
	};

	return nextState = nextStateMap.at(inputOption);
}