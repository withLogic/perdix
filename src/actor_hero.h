#ifndef ACTOR_HERO
#define ACTOR_HERO

#include "core.h"

class actor_hero : public perdix::core_actor{
	public:
		actor_hero(perdix::core_state* state);
		~actor_hero();

		int toggleVisible();
		
		void draw();

	private:
		int objectType;
		perdix::sprite* image;
		perdix::core_state* parentState;

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

#endif
