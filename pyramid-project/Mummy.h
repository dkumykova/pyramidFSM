//
// Mummy.h
//

#ifndef MUMMY_H
#define MUMMY_H

// Engine includes
#include "Event.h"
#include "Object.h"
#include "Vector.h"

// Game includes
#include "game.h"
#include "Hero.h"
#include "vs-2019/StateMachine.h"
#include "vs-2019/StateSearch.h"
#include "vs-2019/StateCower.h"
#include "vs-2019/StateChase.h"

namespace df {
	class Mummy : public df::Object {

	private:
		Hero* m_p_hero;
		int m_move_countdown;
		int m_think_countdown;
		StateMachine stateMachine;
		State state;

	public:
		Mummy(Hero* p_hero);
		int eventHandler(const df::Event* e);
		Hero* getHero();
		void stopAnimation(bool stop);
		df::Vector seeHero();
		bool senseHero();
		int getMoveCountdown();
		void setMoveCountdown(int new_move_countdown);
		int getThinkCountdown();
		void setThinkCountdown(int new_think_countdown);
		StateMachine getStateMachine();
		void setStateMachine(StateMachine new_machine);
		State getState();
		void setState(State new_state);

		StateSearch getStateSearch();
		StateCower getStateCower();
		StateWander getStateWander();
		StateChase getStateChase();
	};
}

#endif
