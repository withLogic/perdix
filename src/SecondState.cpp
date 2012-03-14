#include "core.h"
#include "core_state.h"
#include "SecondState.h"

SecondState SecondState::m_IntroState;

void SecondState::Init(perdix::core* game)
{
	this->game = game;

	#ifdef _DEBUG
		this->game->debugPrint("SecondState::Init(): Initializing the State.", MSG_DIAG);
	#endif

	/* all of this is temp to show that the engine is working */
	this->temp = SDL_LoadBMP("water.bmp");
	if (this->temp != NULL){
		this->_image = SDL_DisplayFormat(this->temp);	
		SDL_FreeSurface(this->temp);
		this->_height = this->_image->h;
		this->_width = this->_image->w;
	}

	#ifdef _DEBUG
		this->game->debugPrint("SecondState::Init(): Image 'WaterTile.bmp' has been loaded.", MSG_NORMAL);
	#endif
	/* all of this is temp to show that the engine is working */

};

void SecondState::Cleanup()
{
SDL_FreeSurface(this->_image);
	#ifdef _DEBUG
		this->game->debugPrint("SecondState::Init(): Killing the State.", MSG_DIAG);
	#endif
};

void SecondState::Pause()
{

};

void SecondState::Resume()
{

};

void SecondState::HandleEvents()
{

};

void SecondState::Update() 
{

};

void SecondState::Draw() 
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