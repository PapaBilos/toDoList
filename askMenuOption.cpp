#pragma once
#include <iostream>
#include <map>

#include "askMenuOption.h"

void AskMenuOption::nextStateSelection() {
	std::cout << "Choose option: ";
	int inputOption;
	std::cin >> inputOption;
	std::map<int, PossibleState> nextStateMap{
		{1, PossibleState::addTask},
		{2, PossibleState::showTasks},
		{3, PossibleState::editTask},
		{4, PossibleState::removeTask},
		{5, PossibleState::terminate}
	};
	AskMenuOption::nextState = nextStateMap.at(inputOption);
}

void AskMenuOption::execute() {
	AskMenuOption::nextStateSelection();
}

PossibleState AskMenuOption::leave() {
	return nextState;
}