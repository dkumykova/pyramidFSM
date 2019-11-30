#include <string>
#include "State.h"
#ifndef STATE_SEARCH_H
#define STATE_SEACH_H

#define SS df::StateSearch::getInstance()

namespace df {
	class StateSearch: public State {
	private:
		StateSearch(); //singleton! therefore private
		StateSearch(StateSearch const&); //don't allow copies
		void operator = (StateSearch const&); //don't allow assignment

	public:
		static StateSearch& getInstance();

		//invoked when state first entered
		void Enter(Object* obj);

		//invoked every game loop step
		void Execute(Object* obj);
	};
}
#endif