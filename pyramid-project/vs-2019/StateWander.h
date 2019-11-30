#include <string>
#include "State.h"
#ifndef STATE_WANDER_H
#define STATE_WANDER_H

#define SW df::StateWander::getInstance()

namespace df {
	class StateWander : public State {
	private:
		StateWander(); //singleton! therefore private
		StateWander(StateWander const&); //don't allow copies
		void operator = (StateWander const&); //don't allow assignment

	public:
		static StateWander& getInstance();

		//invoked when state first entered
		void Enter(Object* obj);

		//invoked every game loop step
		void Execute(Object* obj);
	};
}
#endif