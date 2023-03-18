#include"config.h"

void Config::fileReplace() {
	Config config;
	std::remove(config.tasksFileName.c_str());
	std::rename(config.tasksTempFileName.c_str(), config.tasksFileName.c_str());
	std::remove(config.tasksTempFileName.c_str());
}