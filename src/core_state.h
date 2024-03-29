/*
==================================================================

						Perdix - Core State Class Header

==================================================================
*/

#ifndef CORE_STATE_H
#define CORE_STATE_H

#include "core.h"

namespace perdix
{
	class core; // forward declaration for the core object :-)

	///////////////////////////////////////////////////////////////
	//
	// Class core_state
	//		Parent class for all of the states in the game. 
	//
	///////////////////////////////////////////////////////////////
	class core_state
	{
	public:
		virtual void Init(core* game) = 0;
		virtual void CleanUp() = 0;

		virtual void Pause() = 0;
		virtual void Resume() = 0;

		virtual void HandleEvents() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

		void ChangeState(core* game, core_state* state);

	protected:
		core_state() { }
	};

};
#endif