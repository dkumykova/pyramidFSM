#include <string>
#include <Object.h>
#ifndef STATE_H
#define STATE_H


namespace df {
	class State {
	private:
		std::string state_type;
	public:
		State();

		void setType(std::string new_type);

		std::string getType();

		//invoked when state first entered
		virtual void Enter(Object *obj);

		//invoked every game loop step
		virtual void Execute(Object *obj);
	
		//invoked when state exited
		virtual void Exit(Object *obj);
	};
}
#endif