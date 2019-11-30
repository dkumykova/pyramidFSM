#include "StateSearch.h"

using namespace df;


StateSearch::StateSearch() {

}
StateSearch& StateSearch::getInstance() {
	static StateSearch stateSearch;
	return stateSearch;
}
