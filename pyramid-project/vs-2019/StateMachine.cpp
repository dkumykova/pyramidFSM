#include "StateMachine.h"
using namespace df;



StateMachine::StateMachine() {
	owner = NULL;
	state = NULL;
	previous_state = NULL;
	global_state = NULL;
}

void StateMachine::setOwner(Object* new_owner) {
	owner = new_owner;
}

Object* StateMachine::getOwner() const {
	return owner;
}

void StateMachine::setState(State* new_state) {
	state = new_state;
}

State* StateMachine::getState() const {
	return state;
}

void StateMachine::setPreviousState(State* new_state) {
	previous_state = new_state;
}

State* StateMachine::getPreviousState() const {
	return previous_state;
}

void StateMachine::setGlobalState(State* new_state) {
	global_state = new_state;
}

State* StateMachine::getGlobalState() const {
	return global_state;
}

//update state machine, call execute on current state
void StateMachine::update() {
	//execute global state
	if (global_state) {
		global_state->Execute(owner);
	}

	if (state) {
		state->Execute(owner);
	}
}

void StateMachine::changeState(State* new_state) {
	//call exit on old state
	if (state) {
		state->Exit(owner);
	}

	//keep track of previous state
	previous_state = state;

	//change to new state
	state = new_state;

	if (state) {
		state->Enter(owner);
	}
}
//revert to previous state
void StateMachine::revertToPrevious() {

}