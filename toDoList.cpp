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

std::vector<int> options {1,2,3,4,5};
std::vector<int>::iterator it;

int taskID;

const std::string mainMenuOptions = "Welcome to toDoList v0.1\n"
"1. Add task\n"
"2. Read task(s)\n"
"3. Edit task\n"
"4. Remove task\n"
"5. Quit program\n"
"Select option: ";

void addTask(){
    char repeat;
    do
    {
        std::string taskName;
        system("cls");
        std::cout << "Adding task" << std::endl << std::endl;
        std::cout << " Enter new task: ";
        std::cin >> taskName;

        std::fstream tasksFile;
        tasksFile.open("tasks.txt",std::fstream::out | std::fstream::app);
        if(tasksFile.is_open()){
            tasksFile << taskName << "\n" ;
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

void readTask(){
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

    std::cout << "Done? If so, tyle 'y' or 'Y':" << std::endl;
    char done;
    do{
        std::cin >> done;
    }while(done != 'y' && done != 'Y');
    system("cls");
}

void editTask(){
    system("cls");
    std::cout << "Editing task" << std::endl;
}

void removeTask(){
    system("cls");
    std::cout << "Removing task" << std::endl;
    
}

void idCheck(){
    //HOW TO GET LAST LINE FROM id.txt ???
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

    do{
        //Var to choose option
        int choice;

        std::cout << mainMenuOptions;
        std::cin >> choice;

        it = std::find(options.begin(), options.end(), choice);

        if(it != options.end()){
            switch (choice)
            {
            case 1:
                addTask();
                break;
            case 2:
                readTask();
                break;
            case 3:
                editTask();
                break;
            case 4:
                removeTask();
                break;
            case 5:
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

