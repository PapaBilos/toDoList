#include<iostream>
#include<map>

#include"askMenuOption.h"

void AskMenuOption::nextStateSelection() {
	int inputOption;
	int* input_ptr;
	input_ptr = &inputOption;
	std::cout << "Choose option: ";
	std::cin >> inputOption;
	std::map<int, PossibleState> nextStateMap{
		{1, PossibleState::addTask},
		{2, PossibleState::showTasks},
		{3, PossibleState::editTask},
		{4, PossibleState::removeTask},
		{5, PossibleState::terminate}
	};
	if(!nextStateMap.count(inputOption)){
		std::cout << "Number out of bound!" << std::endl;
		AskMenuOption::nextState = PossibleState::askMenuOption;
	}
	else {
		AskMenuOption::nextState = nextStateMap.at(*input_ptr);
	}
}

void AskMenuOption::execute() {
	AskMenuOption::nextStateSelection();
}

PossibleState AskMenuOption::leave() {
	return nextState;
}