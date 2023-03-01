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
// const std::string taskFileName = "tasks.txt"; //solve problem !
const std::string mainMenuOptions = "Welcome to toDoList v0.1\n"
"1. Add task\n"
"2. Read task(s)\n"
"3. Edit task\n"
"4. Remove task\n"
"5. Quit program\n"
"Select option: ";

bool actionDone(){
    std::cout << "Done? If so, type 'y' or 'Y':" << std::endl;
    char done;
    std::cin >> done;
    if(done != 'y' && done != 'Y'){
        return true;
    }
    else{
        return false;
    }
}

void addTask(){
    char repeat;
    do
    {
        std::string taskName;
        system("cls");
        std::cout << "Adding task\n\n";
        std::cout << " Enter new task: ";
        std::cin >> taskName;

        std::fstream tasksFile;
        tasksFile.open("tasks.txt",std::fstream::out | std::fstream::app);
        if(tasksFile.is_open()){
            tasksFile << taskName << "\n";
            tasksFile.close();
        }
        else{
            std::cout << "ERROR::addTask::taskFile::IS_NOT_OPEN" << std::endl;
        }

        taskID++;

        std::fstream idFile;
        idFile.open("id.txt",std::fstream::out | std::fstream::app);
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
    idFile.open("id.txt", std::fstream::in);
    tasksFile.open("tasks.txt", std::fstream::in);

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
    int taskToDel;
    int iter = 0;
    std::string newTask;

    system("cls");
    std::cout << "Editing task" << std::endl;
    std::cout << "There is list of tasks. Choose with one you want to edit: \n\n";
    showTasks();

    std::cout << "Type num. of task to edit.: ";
    std::cin >> taskToDel;

    if(taskToDel > 0 || taskToDel <= taskID){
        std::fstream taskFile, taskFileTemp;
        std::string line;
        taskFile.open("tasks.txt",std::fstream::in);
        taskFileTemp.open("tasksTemp.txt",std::fstream::out);
        if(taskFile.good() && taskFileTemp.good()){
            while (taskFile.peek() != EOF)
            {   
                iter++;
                std::getline(taskFile,line);

                if(iter != taskToDel){
                    taskFileTemp << line << "\n";
                }
                else{
                    std::cout << "Task you picked: \n" << taskToDel << "\t" << line << std::endl;
                    std::cout << "Enter new name of task: ";
                    std::getline(std::cin, newTask);
                    taskFileTemp << newTask << "\n";
                }
            }
        }
        std::cout<< "INFO::Task edited succesfully";

        taskFile.close();
        taskFileTemp.close();

        std::remove("tasks.txt");
        std::rename("tasksTemp.txt","tasks.txt");
        std::remove("tasksTemp.txt");
    }
    else{
        std::cout << "INFO::Task num. out of bound!\n";
    }
    system("cls");
}

void removeTask(){
    system("cls");
    std::cout << "Removing task" << std::endl;
    std::cout << "There is list of tasks. Choose with one you want to delete: \n\n";
    showTasks();
}

void idCheck(){
    std::fstream idFile;
    idFile.open("id.txt",std::fstream::in);

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
    // char check[100];
    // std::cin.getline(check,100);
    // std::cout << check;
    do{
        //Var to choose option
        int choice;

        std::cout << mainMenuOptions;
        std::cin >> choice;

        it = std::find(options.begin(), options.end(), choice);

        if(it != options.end()){
            switch (choice){
            case 1:
                //done
                addTask();
                system("cls");
                break;
            case 2:
                //done
                showTasks();
                while (actionDone());
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
            }
        }
        else{
            std::cout << "Number out of bound!" << std::endl;
        }
    }
    while(true);
    return 0;
}