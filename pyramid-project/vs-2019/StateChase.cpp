#include "StateChase.h"

using namespace df;


StateChase::StateChase() {

}

StateChase& StateChase::getInstance() {
	static StateChase stateChase;
	return stateChase;
}
