/*
==================================================================

						Perdix - Core State Class

==================================================================
*/

#include "core.h"

namespace perdix
{
	///////////////////////////////////////////////////////////////
	//
	// ChangeState(core* game, core_state* state)
	//		Tell the game to change the state to the new state. 
	//		This function is really not needed, to be honest.
	//
	///////////////////////////////////////////////////////////////
	void core_state::ChangeState(core* game, core_state* state) {
		game->changeState(state);
	}
}