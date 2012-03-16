/*
==================================================================

						Game - State - SecondState Header

==================================================================
*/

#ifndef SECONDSTATE_H
#define SECONDSTATE_H

#include "core.h"
#include "core_state.h"

class SecondState : public perdix::core_state
{
public:
	void Init(perdix::core* game);
	void CleanUp();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Draw();

	static SecondState* Instance() {
		return &m_SecondState;
	}

protected:
	SecondState() { }

private:
	static SecondState m_SecondState;

	perdix::core* game;
	perdix::sprite* water;

	int UpTick;
};
	
#endif