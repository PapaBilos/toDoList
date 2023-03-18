#include<iostream>
#include<string>
#include<fstream>
#include"config.h"
#include"editTask.h"
#include"showTasks.h"

void EditTask::execute() {
	std::fstream tasksFile, tasksFileTemp;
	Config config;
	system("cls");
	std::cout << "Editing task" << std::endl;

	tasksFile.open(config.tasksFileName, std::fstream::in);
	tasksFileTemp.open(config.tasksTempFileName, std::fstream::out);

	if (tasksFile.is_open() && tasksFileTemp.is_open()) {
		int taskToEdit, iter =0;
		std::string line;
		ShowTasks showTask;

		std::cout << "There is list of tasks. Choose with one you want to edit: \n\n";
		showTask.execute();
		std::cout << "Type num. of task to edit.: ";
		std::cin >> taskToEdit;
		
		while (std::getline(tasksFile, line)) {
			iter++;
			if (iter != taskToEdit) {
				tasksFileTemp << line << "\n";
			}
			else {
				std::string editedTask;
				std::cout << "Task you picked task no.: " << taskToEdit << std::endl;
				std::cout << "Enter new task name: ";
				std::cin.ignore();
				std::getline(std::cin, editedTask);
				tasksFileTemp << editedTask << "\n";
			}
		}
		system("cls");
		std::cout << "INFO::Task edited succesfully\n";
	}
	else {
		std::cout << "ERROT::editTask::FILE_IS_NOT_OPEN\n";
	}
	tasksFile.close();
	tasksFileTemp.close();
	config.fileReplace();
}

PossibleState EditTask::leave() {
	return PossibleState::mainMenu;
}
