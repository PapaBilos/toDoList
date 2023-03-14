#include"terminate.h"

void Terminate::execute() {
	shutdown();
}
PossibleState Terminate::leave() {
	return PossibleState::mainMenu;
}

void Terminate::shutdown() {
	exit(0);
}