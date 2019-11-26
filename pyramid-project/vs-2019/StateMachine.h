#include <string>
#include <Object.h>
#include "State.h"
#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H


namespace df {
	class StateMachine {
	private:
		Object* owner; //owner of state machine
		State* state; //current state
		State* previous_state; 
		State* global_state; //reachable from any state
	public:
		StateMachine();

		void setOwner(Object *owner);

		Object* getOwner() const;

		void setState(State *new_state);

		State* getState() const;

		void setPreviousState(State *new_state);

		State* getPreviousState() const;

		void setGlobalState(State *new_state);

		State* getGlobalState() const;

		//update state machine, call execute on current state
		void update();

		void changeState(State *new_state);
		//revert to previous state
		void revertToPrevious();
	};
}
#endif