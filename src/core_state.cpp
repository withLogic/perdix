#include "core.h"

namespace perdix
{
	void core_state::ChangeState(core* game, core_state* state) {
		game->changeState(state);
	}
}