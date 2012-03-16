/*
==================================================================

						Game - State - SecondState
							
==================================================================
*/

#include "core.h"
#include "core_state.h"
#include "IntroState.h"
#include "SecondState.h"

SecondState SecondState::m_SecondState;

///////////////////////////////////////////////////////////////
//
// Init(perdix::core* game)
//		Initialize the state. It passes a pointer of the game engine to use.
//
///////////////////////////////////////////////////////////////
void SecondState::Init(perdix::core* game)
{
	this->game = game;

	/* all of this is temp to show that the engine is working */
	#ifdef _DEBUG
		this->game->debugPrint("SecondState::Init(): Initializing the State.", MSG_DIAG);
	#endif

	this->water = new perdix::sprite;
	this->water->loadImage("water.bmp");

	this->UpTick = 0;

	#ifdef _DEBUG
		this->game->debugPrint("SecondState::Init(): Image 'WaterTile.bmp' has been loaded.", MSG_NORMAL);
	#endif
	/* all of this is temp to show that the engine is working */

};

///////////////////////////////////////////////////////////////
//
// Cleanup()
//		Cleanup function. Deletes all of the created resources.
//
///////////////////////////////////////////////////////////////
void SecondState::CleanUp()
{
	this->water->cleanUp();
	delete this->water;

	#ifdef _DEBUG
		this->game->debugPrint("SecondState::CleanUp(): Killing the State.", MSG_DIAG);
	#endif
};

///////////////////////////////////////////////////////////////
//
// Pause()
//		Pause the state. When the state is paused, nothing is processed
//		When the state is paused, the following will occur.
//
///////////////////////////////////////////////////////////////
void SecondState::Pause()
{

};

///////////////////////////////////////////////////////////////
//
// Resume()
//			Unpauses the state. When the state is unpaused, the follownig is processed
//
///////////////////////////////////////////////////////////////
void SecondState::Resume()
{

};

///////////////////////////////////////////////////////////////
//
// HandleEvents()
//
///////////////////////////////////////////////////////////////
void SecondState::HandleEvents()
{

};

///////////////////////////////////////////////////////////////
//
// Update()
//
///////////////////////////////////////////////////////////////
void SecondState::Update() 
{
	if(this->UpTick >= 20){
		this->game->popState();
	};

	this->UpTick++;

	#ifdef _DEBUG
		this->game->debugPrint("SecondState::Update(): Updating the scene.", MSG_DIAG);
	#endif
};

///////////////////////////////////////////////////////////////
//
// Draw()
//
///////////////////////////////////////////////////////////////
void SecondState::Draw() 
{

/* all of this is temp to show that the engine is working */
	SDL_Rect _rect;

	for (int x = 0; x < game->getWindowWidth() / this->water->getWidth(); x++) {
		for (int y = 0; y < game->getWindowHeight() / this->water->getHeight(); y++) {
			_rect.x = x * this->water->getWidth();
			_rect.y = y * this->water->getHeight();
			SDL_BlitSurface(this->water->getImage(), NULL, game->getScreen(), &_rect);
		}
	}

	#ifdef _DEBUG
		this->game->debugPrint("SecondState::Draw(): Drawing the scene.", MSG_DIAG);
	#endif

	SDL_Flip(game->getScreen());
/* all of this is temp to show that the engine is working */

};