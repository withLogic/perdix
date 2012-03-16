/*
==================================================================

						Perdix - Core OS Timer Header

==================================================================
*/

// -- NOTE --
// this timer code taken from Advanced2D game engine.
// designed for using Windows for it's time.

#ifdef _DEBUG
#ifdef WIN32

#ifndef TIMER_H
#define TIMER_H 

#include "core.h"
#include <time.h>

namespace perdix {

	class timer
	{
	private:
		#ifdef _DEBUG
			CConsole *console;
		#endif

		DWORD timer_start;
		DWORD stopwatch_start;

	public:
		timer(void);
		~timer(void);
		DWORD getTimer();
		DWORD getStartTimeMillis();
		
		void sleep(int ms);
		void reset();
		bool stopwatch(int ms);
	};

};

#endif

#endif
#endif