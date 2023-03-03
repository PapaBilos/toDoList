/*
Quick toDoList program with four options:
1. Read tasks,
2. Add tasks,
3. Edit tasks,
4. Remove tasks.
*/

#include<iostream>
#include<vector>
#include<algorithm> //find()
#include<fstream>
#include<string> //getline()

std::vector<unsigned int> options {1,2,3,4,5};
std::vector<unsigned int>::iterator it;

unsigned int taskID;
std::string taskFileName = "tasks.txt", idFileName = "id.txt";

const std::string mainMenuOptions = "Welcome to toDoList v0.1\n"
"1. Add task\n"
"2. Read task(s)\n"
"3. Edit task\n"
"4. Remove task\n"
"5. Quit program\n"
"Select option: ";

bool actionDone(){
    std::cout << "Done? If so, type 'y' or 'Y':" << std::endl;
    char userInput;
    std::cin >> userInput;
    return (userInput != 'y' && userInput != 'Y');
}

void addTask(){
    char repeat;
    do
    {   
        std::string taskName;
        system("cls");
        std::fstream tasksFile, idFile;
        tasksFile.open(taskFileName,std::fstream::out | std::fstream::app);
        if(tasksFile.is_open()){
    
            std::cout << "Adding task\n" << std::endl;
            std::cout << "Enter new task: ";
            std::cin.ignore(); 
            std::getline(std::cin,taskName);
            std::cout << "You enter:" << taskName << std::endl;

            tasksFile << taskName << "\n";
            tasksFile.close();
        }
        else{
            std::cout << "ERROR::addTask::taskFile::IS_NOT_OPEN" << std::endl;
        }

        taskID++;

        idFile.open(idFileName,std::fstream::out | std::fstream::app);
        if(idFile.is_open()){
            idFile << taskID << "\n" ;
            idFile.close();
        }
        else{
            std::cout << "ERROR::addTask::idFile::IS_NOT_OPEN" << std::endl;
        }

        std::cout << "\nTask added succesfully!\n Add next task?\n If so, type 'y' or 'Y': \t";
        std::cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
}

void showTasks(){
    system("cls");
    std::cout << "Reading task(s)" << std::endl;

    std::string idFileLine, tasksFileLine;
    std::fstream idFile, tasksFile;
    idFile.open(idFileName, std::fstream::in);
    tasksFile.open(taskFileName, std::fstream::in);

    if(idFile.good() && tasksFile.good()){
        while (idFile.peek() != EOF && tasksFile.peek() != EOF)
        {
            std::getline(idFile,idFileLine);
            std::getline(tasksFile,tasksFileLine);
            std::cout << idFileLine << "\t" << tasksFileLine << std::endl;
        }
        idFile.close();
        tasksFile.close();
    }
    else{
        std::cout << "ERROR::readTask::FILE(s)_NOT_OPEN";
    }
}

void editTask(){

    system("cls");
    std::cout << "Editing task" << std::endl;

    std::fstream tasksFile, taskFileTemp;
    tasksFile.open(taskFileName,std::fstream::in);
    taskFileTemp.open("tasksTemp.txt",std::fstream::out);
    if(tasksFile.good() && taskFileTemp.good()){

        int taskToEdit, iter = 0;

        std::cout << "There is list of tasks. Choose with one you want to edit: \n\n";
        showTasks();
        std::cout << "Type num. of task to edit.: ";
        std::cin >> taskToEdit;

        if(taskToEdit > 0 || taskToEdit <= taskID){
            while (tasksFile.peek() != EOF)
            {   
                std::string line;
                std::getline(tasksFile,line);
                iter++;
                if(iter != taskToEdit)
                {
                    taskFileTemp << line << "\n";
                }
                else
                {
                    std::string editedTask;
                    std::cout << "Task you picked: \n" << taskToEdit << "\t" << line << std::endl;
                    std::cout << "Enter new name of task: ";
                    std::cin.ignore();
                    std::getline(std::cin, editedTask);
                    taskFileTemp << editedTask << "\n";
                }
            }
        }
        else{
            std::cout << "INFO::Task num. out of bound!\n";
        }
        std::cout<< "INFO::Task edited succesfully";
        system("cls");
    }   
    else
    {
        std::cout << "ERROT::editTask::FILE_IS_NOT_OPEN\n";
    }
    tasksFile.close();
    taskFileTemp.close();
    std::remove("tasks.txt");
    std::rename("tasksTemp.txt","tasks.txt");
    std::remove("tasksTemp.txt");
}

void removeTask(){
    system("cls");
    std::cout << "Removing task" << std::endl;
    std::cout << "There is list of tasks. Choose with one you want to delete: \n\n";
    showTasks();
}

void idCheck(){
    std::fstream idFile;
    idFile.open(idFileName,std::fstream::in);

    std::string line;
    unsigned int lineCount = 0;
    if(idFile.good()){
        while(idFile.peek() != EOF){
            std::getline(idFile, line);
            lineCount++;
        }
        idFile.close();
        taskID = lineCount;
    }
    else{
        taskID = 0;
    }
    std::cout << "Current task ID: " << taskID << std::endl;
}

int main(){
    system("cls");
    idCheck();

    do{
        int choice;

        std::cout << mainMenuOptions;
        std::cin >> choice;
        it = std::find(options.begin(), options.end(), choice);

        switch (choice){
        case 1:
            //done
            addTask();
            system("cls");
            break;
        case 2:
            //done
            showTasks();
            actionDone();
            system("cls");
            break;
        case 3:
            editTask();
            break;
        case 4:
            removeTask();
            break;
        case 5:
            //done
            std::cout << "Thanks for using this program!!!" << std::endl;
            return 0;
            break;
        default:
            std::cout << "Number out of bound!" << std::endl;
        }
    }
    while(true);
    return 0;
}