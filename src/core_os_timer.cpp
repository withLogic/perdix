/*
==================================================================

						Perdix - Core OS Timer

==================================================================
*/

// -- NOTE --
// this timer code taken from Advanced2D game engine.
// designed for using Windows for it's time.

#ifdef TIMER_H

#include "core.h"

namespace perdix {

	timer::timer(void)
	{
		timer_start = timeGetTime();
		reset();
	}

	timer::~timer(void)
	{
	}

	DWORD timer::getTimer()
	{
		return (DWORD) (timeGetTime());
	}

	DWORD timer::getStartTimeMillis()
	{
		return (DWORD) (timeGetTime() - timer_start);
	}


	void timer::sleep(int ms)
	{
		DWORD start = getTimer();
		while (start + ms > getTimer());
	}

	void timer::reset()
	{
		stopwatch_start = getTimer();
	}

	bool timer::stopwatch(int ms)
	{
		if ( timeGetTime() > stopwatch_start + ms ) {
			stopwatch_start = getTimer();
			return true;
		}
		else return false;
	}

}

#endif
