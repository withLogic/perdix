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

	#ifdef _DEBUG
		this->game->debugPrint("IntroState::Init(): Initializing the State.", MSG_DIAG);
	#endif

	/* all of this is temp to show that the engine is working */
	this->temp = SDL_LoadBMP("grass.bmp");
	if (this->temp != NULL){	
		this->_image = SDL_DisplayFormat(this->temp);
		SDL_FreeSurface(this->temp);
		this->_height = this->_image->h;
		this->_width = this->_image->w;
	}

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
SDL_FreeSurface(this->_image);
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
//			Unpauses the state. When the state is unpaused, the follownig is processed
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
for (int x = 0; x < SCREEN_WIDTH / _width; x++) {
	for (int y = 0; y < SCREEN_HEIGHT / _height; y++) {
	_rect.x = x * _width;
	_rect.y = y * _height;
	SDL_BlitSurface(_image, NULL, game->getScreen(), &_rect);
	}
}

SDL_Flip(game->getScreen());
/* all of this is temp to show that the engine is working */

};