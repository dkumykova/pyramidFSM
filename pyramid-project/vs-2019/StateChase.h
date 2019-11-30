#include <string>
#include "State.h"
#ifndef STATE_CHASE_H
#define STATE_CHASE_H

#define SCS df::StateChase::getInstance()

namespace df {
	class StateChase : public State {
	private:
		StateChase(); //singleton! therefore private
		StateChase(StateChase const&); //don't allow copies
		void operator = (StateChase const&); //don't allow assignment

	public:

		static StateChase& getInstance();
		//invoked when state first entered
		void Enter(Object* obj);

		//invoked every game loop step
		void Execute(Object* obj);
	};
}
#endif