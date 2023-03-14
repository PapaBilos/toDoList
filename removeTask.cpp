#include<iostream>
#include<fstream>
#include<string>
#include"removeTask.h"
#include"showTasks.h"

void RemoveTask::execute() {
	std::cout << "Removing task" << std::endl;

	std::string tasksFileName = "tasks.txt", tasksTempFileName = "taskTemp.txt";
	std::fstream tasksFile, tasksFileTemp;
	tasksFile.open(tasksFileName, std::fstream::in);
	tasksFileTemp.open(tasksTempFileName, std::fstream::out);

	if (tasksFile.is_open() && tasksFileTemp.is_open()) {
		ShowTasks showTask;
		int taskToRemove, iter = 0;

		std::cout << "There is list of tasks. Choose with one you want to edit: \n\n";
		showTask.execute();
		std::cout << "Type num. of task to remove: ";
		std::cin >> taskToRemove;

		while (tasksFile.peek() != EOF) {
			std::string line;
			std::getline(tasksFile, line);
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
	std::remove(tasksFileName.c_str());
	std::rename(tasksTempFileName.c_str(), tasksFileName.c_str());
	std::remove(tasksTempFileName.c_str());

}

PossibleState RemoveTask::leave() {
	return PossibleState::mainMenu;
}