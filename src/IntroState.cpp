/*
==================================================================

						Game - State - IntroState

==================================================================
*/

#include "core.h"
#include "core_state.h"
#include "IntroState.h"

IntroState IntroState::m_IntroState;

///////////////////////////////////////////////////////////////
//
// Init(perdix::core* game)
//		Initialize the state. It passes a pointer of the game engine to use.
//
///////////////////////////////////////////////////////////////
void IntroState::Init(perdix::core* game)
{
	this->game = game;

	/* all of this is temp to show that the engine is working */
	#ifdef _DEBUG
		this->game->debugPrint("IntroState::Init(): Initializing the State.", MSG_DIAG);
	#endif

	this->grass = new perdix::sprite;
	this->grass->loadImage("grass.bmp");

	#ifdef _DEBUG
		this->game->debugPrint("IntroState::Init(): Image 'grass.bmp' has been loaded.", MSG_NORMAL);
	#endif
	/* all of this is temp to show that the engine is working */

};

///////////////////////////////////////////////////////////////
//
// Cleanup()
//		Cleanup function. Deletes all of the created resources.
//
///////////////////////////////////////////////////////////////
void IntroState::CleanUp()
{
	this->grass->cleanUp();
	delete this->grass;

	#ifdef _DEBUG
		this->game->debugPrint("IntroState::CleanUp(): Killing the State.", MSG_DIAG);
	#endif
};

///////////////////////////////////////////////////////////////
//
// Pause()
//		Pause the state. When the state is paused, nothing is processed
//		When the state is paused, the following will occur.
//
///////////////////////////////////////////////////////////////
void IntroState::Pause()
{

};

///////////////////////////////////////////////////////////////
//
// Resume()
//		Unpauses the state. When the state is unpaused, the follownig is processed
//
///////////////////////////////////////////////////////////////
void IntroState::Resume()
{

};

///////////////////////////////////////////////////////////////
//
// HandleEvents()
//
///////////////////////////////////////////////////////////////
void IntroState::HandleEvents()
{

};

///////////////////////////////////////////////////////////////
//
// Update()
//
///////////////////////////////////////////////////////////////
void IntroState::Update() 
{

};

///////////////////////////////////////////////////////////////
//
// Draw()
//
///////////////////////////////////////////////////////////////
void IntroState::Draw() 
{

/* all of this is temp to show that the engine is working */
	SDL_Rect _rect;

	for (int x = 0; x < game->getWindowWidth() / this->grass->getWidth(); x++) {
		for (int y = 0; y < game->getWindowHeight() / this->grass->getHeight(); y++) {
			_rect.x = x * this->grass->getWidth();
			_rect.y = y * this->grass->getHeight();
			SDL_BlitSurface(this->grass->getImage(), NULL, game->getScreen(), &_rect);
		}
	}

	SDL_Flip(game->getScreen());
/* all of this is temp to show that the engine is working */

};