#pragma once
#include<iostream>
class Config {
public:
	std::string tasksFileName = "tasks.txt";
	std::string tasksTempFileName = "tasksTemp.txt";
	void fileReplace();
};