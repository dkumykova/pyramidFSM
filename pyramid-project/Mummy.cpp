//
// Mummy.cpp
//

// Engine includes.
#include "EventStep.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "utility.h"

// Game includes.
#include "Mummy.h"
#include "vs-2019/StateWander.h"
using namespace df;

Mummy::Mummy(Hero *p_hero) {

  // Basic Mummy attributes.
  m_move_countdown = 0;
  m_think_countdown = 0;
  setType("Mummy");
  setAltitude(3);
  setSpeed(0);
  stateMachine.setOwner(this);
  stateMachine.setState((*SW));
  stateMachine.changeState(*(StateWander::getInstance()));

  // Default sprite, standing.
  setSprite("mummy-white");
  stopAnimation(true);
  
  // Mummy keeps track of Hero.
  m_p_hero = p_hero;

  // Get step events.
#ifdef DF_REGISTER_INTEREST
  registerInterest(df::STEP_EVENT);
#endif
}

// Start or stop animation.
void Mummy::stopAnimation(bool stop) {
  df::Animation animation = getAnimation();
  if (stop) {
    if (animation.getSlowdownCount() != -1) {
      animation.setSlowdownCount(-1);
      animation.setIndex(0);
    }
  } else {
    if (animation.getSlowdownCount() == -1) {
      animation.setSlowdownCount(0);
      animation.setIndex(0);
    }
  }
  setAnimation(animation);
}  

// Handle event.
// Return 0 if ignored, else 1
int Mummy::eventHandler(const df::Event *e) {
	if (e->getType() == df::STEP_EVENT) {
		stateMachine.update(); //update state machine
		return 1;
	}
  // If we get here, we have ignored this event.
  return 0;
}

// Return true if Hero is within sensing distance.
bool Mummy::senseHero() {
	//compute distance of hero from mummy
	//if within range, return true; else false
  return false; // Can't sense.
}

// If can see Hero and can sense Hero, return direction
// else return (0,0).
df::Vector Mummy::seeHero() {
	//check if in range for sensing, i.e. sense hero is true
	//check if line from hero to mummy has wall
	//no wall return normalized vecotr, selse 0
  return df::Vector(0,0);  // Can't see.
}

void Mummy::setMoveCountdown(int new_move_countdown) {
  m_move_countdown = new_move_countdown;
}

int Mummy::getMoveCountdown() {
  return m_move_countdown;
}

void Mummy::setThinkCountdown(int new_think_countdown) {
  m_think_countdown = new_think_countdown;
}

int Mummy::getThinkCountdown() {
  return m_think_countdown;
}

Hero *Mummy::getHero() {
  return m_p_hero;
}

StateMachine Mummy::getStateMachine() {
	return stateMachine;
}
void Mummy::setStateMachine(StateMachine new_machine) {
	stateMachine = new_machine;
}

State Mummy::getState() {
	return state;
}
void Mummy::setState(State new_state) {
	state = new_state;
}

StateSearch Mummy::getStateSearch() {
	/*return SS;*/
}
StateCower Mummy::getStateCower() {

}
StateWander Mummy::getStateWander() {

}
StateChase Mummy::getStateChase() {

}