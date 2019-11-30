#include <string>
#include "State.h"
#ifndef STATE_COWER_H
#define STATE_COWER_H

#define SC df::StateCower::getInstance()

namespace df {

	class StateCower : public State {
	private:
		StateCower(); //singleton! therefore private
		StateCower(StateCower const&); //don't allow copies
		void operator = (StateCower const&); //don't allow assignment

	public:

		static StateCower& getInstance();
		//invoked when state first entered
		void Enter(Object* obj);

		//invoked every game loop step
		void Execute(Object* obj);
	};
}
#endif