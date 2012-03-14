#ifndef SECONDSTATE_H
#define SECONDSTATE_H

#include "core.h"
#include "core_state.h"


class SecondState : public perdix::core_state
{
public:
	void Init(perdix::core* game);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Draw();

	static SecondState* Instance() {
		return &m_IntroState;
	}

protected:
	SecondState() { }

private:
	static SecondState m_IntroState;

	ACTOR_IMAGE *temp;
	ACTOR_IMAGE *_image;
	ACTOR_RECT _rect;
	unsigned short _height;
	unsigned short _width;

	perdix::core* game;
};
	
#endif