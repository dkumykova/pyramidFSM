#include "StateCower.h"

using namespace df;


StateCower::StateCower() {

}
StateCower& StateCower::getInstance() {
	static StateCower stateCower;
	return stateCower;
}
