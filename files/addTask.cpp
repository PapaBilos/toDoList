#include<iostream>
#include<fstream>
#include<string>

#include "addTask.h"
#include "state.h"

void AddTask::execute() {
    system("cls");
    std::string taskName, taskFileName = "tasks.txt";
    std::fstream tasksFile;
    tasksFile.open(taskFileName);
    if(tasksFile.is_open()) {
            std::cout << "Adding task\n" << std::endl;
            std::cout << "Enter new task: ";
            std::cin.ignore(); 
            std::getline(std::cin,taskName);

            tasksFile << taskName << "\n";
            tasksFile.close();
        }
    else {
        std::cout << "ERROR::addTask::taskFile::IS_NOT_OPEN" << std::endl;
    }
    std::cout << "Task Added succesfully!\n";
}

PossibleState AddTask::leave() {
    return PossibleState::mainMenu;
}