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

	short int TileHeight;
	short int TileWidth;

protected:
	IntroState() { }

private:
	static IntroState m_IntroState;

	ACTOR_IMAGE *temp;
	ACTOR_IMAGE *_image;
	ACTOR_RECT _rect;
	unsigned short _height;
	unsigned short _width;

	perdix::core* game;
};
	
#endif