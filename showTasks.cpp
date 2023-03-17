#include <fstream>
#include <iostream>
#include <string>

#include "showTasks.h"


void ShowTasks::execute() {
	system("cls");
	std::cout << "Showing task(s)" << std::endl;

	std::string taskFileName = "tasks.txt";
	std::string taskFileLine;
	std::ifstream taskFile;
	taskFile.open(taskFileName);

	int taskNumber = 1;
	if (taskFile.is_open()) {
		while (taskFile.peek() != EOF) {
			std::getline(taskFile, taskFileLine);
			std::cout << taskNumber << "\t" << taskFileLine << std::endl;
			taskNumber++;
		}
		if (taskNumber == 1) {
			std::cout << "There is no tasks\n\n";
		}
	}
	else {
		std::cout << "ERROR::showTask::execute::FILE_NOT_OPEN\n";
	}
	taskFile.close();
	std::cout << std::endl;
}

PossibleState ShowTasks::leave() {
	return PossibleState::mainMenu;
}