#include<iostream>
#include<string>
#include<fstream>

#include "editTask.h"
#include "showTasks.h"

void EditTask::execute() {
	system("cls");
	std::cout << "Editing task" << std::endl;

	std::string tasksFileName = "tasks.txt", tasksTempFileName = "taskTemp.txt";
	std::fstream tasksFile, tasksFileTemp;
	tasksFile.open(tasksFileName, std::fstream::in);
	tasksFileTemp.open(tasksTempFileName, std::fstream::out);


	if (tasksFile.is_open() && tasksFileTemp.is_open()) {
		ShowTasks showTask;
		int taskToEdit, iter =0;

		std::cout << "There is list of tasks. Choose with one you want to edit: \n\n";
		showTask.execute();
		std::cout << "Type num. of task to edit.: ";
		std::cin >> taskToEdit;

		while (tasksFile.peek() != EOF) {
			std::string line;
			std::getline(tasksFile, line);
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
	std::remove(tasksFileName.c_str());
	std::rename(tasksTempFileName.c_str(), tasksFileName.c_str());
	std::remove(tasksTempFileName.c_str());
}

PossibleState EditTask::leave() {
	return PossibleState::mainMenu;
}