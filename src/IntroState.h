/*
==================================================================

						Game - State - IntroState Header

==================================================================
*/

#ifndef INTROSTATE_H
#define INTROSTATE_H

#include "core.h"
#include "core_state.h"


class IntroState : public perdix::core_state
{
private:
	static IntroState m_IntroState;
	perdix::core* game;
	perdix::core_event* eventManager;

	perdix::sprite* grass;
	perdix::sprite* hero;
	perdix::sprite* tree;

	int UpTick;

public:
	void Init(perdix::core* game);
	void CleanUp();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Draw();

	static IntroState* Instance() {
		return &m_IntroState;
	}

protected:
	IntroState() { }
};
	
#endif