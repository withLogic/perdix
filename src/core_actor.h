#ifndef CORE_ACTOR_H
#define CORE_ACTOR_H

#include "core.h"

namespace perdix{

	class sprite;

	class core_actor
	{
	public:
		core_actor() : _x(0),_y(0) {};
		virtual ~core_actor() {};
			
	private:
		int _x;
		int _y;
		sprite* _image;
		unsigned short _height;
		unsigned short _width;
	};

};
#endif