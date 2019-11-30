#include "StateWander.h"
#include <LogManager.h>
#include "../Mummy.h"
#include "StateMachine.h"
using namespace df;


StateWander::StateWander() {
	setType("wander");
}

//invoked when state first entered
void StateWander::Enter(Object* obj) {
	obj->setSprite("mummy-white");

	LM.writeLog("StateWander::Enter():set mummy-white");
}

//invoked every game loop step
void StateWander::Execute(Object* obj) {
	//this state deals with mummy, so cast object*
	Mummy* mummy = dynamic_cast<Mummy*> (obj);

	//move, implement wandering

	//if hero has ankh, enter cower state
	if (mummy->getHero()->hasAnkh()) {
		StateMachine* machine = &(mummy->getStateMachine());
		machine->changeState(mummy->getStateCower());
		return;
	}

	//if can sense Hero, enter seek state
	if (mummy->senseHero()) {
		StateMachine* machine = &(mummy->getStateMachine());
		machine->changeState(mummy->getStateSearch());
		return;
	}

}

StateWander& StateWander::getInstance() {
	static StateWander stateWander;
	return stateWander;
}