/*
==================================================================

						Perdix - Core Actor Header

==================================================================
*/

#ifndef CORE_ACTOR_H
#define CORE_ACTOR_H

#include "core.h"

namespace perdix{

	class sprite; // forward declaration for the win!
	class core_state; // same thing, the actor needs the calling state so it can interact with it.

	class core_actor
	{
	public:
		core_actor() : x(0),y(0) {};
		virtual ~core_actor() {};
			
	private:
		int objectType;
		sprite* image;
		core_state* parentState;

		bool visible;
		bool alive;
		bool solid;
		// there is a cool vector3 class that I've seen that might replace the below.
		int x;
		int y;
		// ^^^ 
		int state;
		int direction;
	};

};
#endif