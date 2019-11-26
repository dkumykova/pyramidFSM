#include "State.h"
using namespace df;


State::State() {
	state_type = "";
}

void State::setType(std::string new_type) {
	state_type = new_type;
}

std::string State::getType() {
	return state_type;
}

//invoked when state first entered
void State::Enter(Object* obj) {

}

//invoked every game loop step
void State::Execute(Object* obj) {

}

//invoked when state exited
void State::Exit(Object* obj) {
	
}