#include<iostream>
#include<fstream>
#include<string>
#include"config.h"
#include"removeTask.h"
#include"showTasks.h"

void RemoveTask::execute() {
	std::fstream tasksFile, tasksFileTemp;
	Config config;

	std::cout << "Removing task" << std::endl;
	tasksFile.open(config.tasksFileName, std::fstream::in);
	tasksFileTemp.open(config.tasksFileName, std::fstream::out);

	if (tasksFile.is_open() && tasksFileTemp.is_open()) {
		ShowTasks showTask;
		int taskToRemove, iter = 0;
		std::string line;

		std::cout << "There is list of tasks. Choose with one you want to edit: \n\n";
		showTask.execute();
		std::cout << "Type num. of task to remove: ";
		std::cin >> taskToRemove;

		while (std::getline(tasksFile, line)) {
			iter++;
			if (iter != taskToRemove) {
				tasksFileTemp << line << "\n";
			}
		}
		system("cls");
		std::cout << "INFO::Task removed succesfully\n";
	}
	else {
		std::cout << "ERROT::editTask::FILE_IS_NOT_OPEN\n";
	}
	tasksFile.close();
	tasksFileTemp.close();
	config.fileReplace();

}

PossibleState RemoveTask::leave() {
	return PossibleState::mainMenu;
}