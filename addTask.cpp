#include<iostream>
#include<fstream>
#include<string>

#include "addTask.h"
#include "state.h"

void AddTask::execute() {
	system("cls");
	std::cout << "Adding task\n";

	std::string taskFileName = "tasks.txt";
	std::string taskName;
	std::ofstream taskFile;
	taskFile.open(taskFileName, std::ofstream::app);
	if(taskFile.is_open()){
		std::cout << "Enter noew task: ";
		std::cin.ignore();
		std::getline(std::cin, taskName);
		taskFile << taskName << "\n";
		
	}
	else {
		std::cout << "ERROR::addTask::execute::FILE_IS_NOT_OPEN" << std::endl;
	}
	taskFile.close();
	system("cls");
	std::cout << "\nTask added succesfully!\n\n";
}

PossibleState AddTask::leave() {
	return PossibleState::mainMenu;
}
