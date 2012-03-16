/*
==================================================================

						Game - State - IntroState

==================================================================
*/

#include "core.h"
#include "core_state.h"
#include "IntroState.h"
#include "SecondState.h"

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
	if(this->grass->loadImage("grass.bmp")){
	#ifdef _DEBUG
		this->game->debugPrint("IntroState::Init(): Image 'grass.bmp' has been loaded.", MSG_NORMAL);
	#endif
	};

	this->hero = new perdix::sprite;
	if(this->hero->loadImageTransparent("hero.bmp")){
		#ifdef _DEBUG
			this->game->debugPrint("IntroState::Init(): Image 'hero.bmp' has been loaded.", MSG_NORMAL);
		#endif
	};

	this->tree = new perdix::sprite;
	if(this->tree->loadImageTransparent("tree.bmp")){
		#ifdef _DEBUG
			this->game->debugPrint("IntroState::Init(): Image 'tree.bmp' has been loaded.", MSG_NORMAL);
		#endif
	}

	this->UpTick = 0;

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
	this->hero->cleanUp();
	this->tree->cleanUp();

	delete this->grass;
	delete this->hero;
	delete this->tree;

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
	#ifdef _DEBUG
		this->game->debugPrint("IntroState::Pause(): Pausing the state.", MSG_ALERT);
	#endif
};

///////////////////////////////////////////////////////////////
//
// Resume()
//		Unpauses the state. When the state is unpaused, the following is processed
//
///////////////////////////////////////////////////////////////
void IntroState::Resume()
{
	#ifdef _DEBUG
		this->game->debugPrint("IntroState::Resume(): Resuming the state.", MSG_ALERT);
	#endif

	this->UpTick = 0;
};

///////////////////////////////////////////////////////////////
//
// HandleEvents()
//
///////////////////////////////////////////////////////////////
void IntroState::HandleEvents()
{
	SDL_Event keyevent;

	while(SDL_PollEvent(&keyevent))
	{
		switch (keyevent.type)
		{
			case SDL_QUIT:
				game->quit();
				break;
			case SDL_KEYDOWN:
				 switch(keyevent.key.keysym.sym){
					case SDLK_ESCAPE:
						this->game->quit();
						break;
				};
		};
	};

	#ifdef _DEBUG
		this->game->debugPrint("IntroState::HandleEvents(): Handling of the events.", MSG_DIAG);
	#endif

};

///////////////////////////////////////////////////////////////
//
// Update()
//
///////////////////////////////////////////////////////////////
void IntroState::Update() 
{

	//if(this->UpTick >= 200){
		//this->game->pushState( SecondState::Instance() );
	//}
	//this->UpTick++;
	

	#ifdef _DEBUG
		this->game->debugPrint("IntroState::Update(): Updating the scene.", MSG_DIAG);
	#endif
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
	SDL_Rect _rect2;
	SDL_Rect _tree1;
	SDL_Rect _tree2;
	SDL_Rect _tree3;
	SDL_Rect _tree4;

	for (int x = 0; x < game->getWindowWidth() / this->grass->getWidth(); x++) {
		for (int y = 0; y < game->getWindowHeight() / this->grass->getHeight(); y++) {
			_rect.x = x * this->grass->getWidth();
			_rect.y = y * this->grass->getHeight();
			SDL_BlitSurface(this->grass->getImage(), NULL, game->getScreen(), &_rect);
		}
	}

	_rect.x = 0;
	_rect.y = 0;
	SDL_BlitSurface(this->grass->getImage(), NULL, game->getScreen(), &_rect);

	_rect2.x = 32;
	_rect2.y = 32;
	SDL_BlitSurface(this->hero->getImage(), NULL, game->getScreen(), &_rect2);

	_tree1.x = 120;
	_tree1.y = 89;
	SDL_BlitSurface(this->tree->getImage(), NULL, game->getScreen(), &_tree1);

	_tree2.x = 33;
	_tree2.y = 350;
	SDL_BlitSurface(this->tree->getImage(), NULL, game->getScreen(), &_tree2);

	_tree3.x = 340;
	_tree3.y = 88;
	SDL_BlitSurface(this->tree->getImage(), NULL, game->getScreen(), &_tree3);

	_tree4.x = 500;
	_tree4.y = 300;
	SDL_BlitSurface(this->tree->getImage(), NULL, game->getScreen(), &_tree4);

	#ifdef _DEBUG
		this->game->debugPrint("IntroState::Draw(): Drawing the scene.", MSG_DIAG);
	#endif

	SDL_Flip(game->getScreen());
/* all of this is temp to show that the engine is working */

};