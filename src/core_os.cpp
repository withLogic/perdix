/*
==================================================================

						Perdix - Core OS

==================================================================
*/

#include "core.h"

namespace perdix
{
	///////////////////////////////////////////////////////////////
	//
	// core_os()
	//		Constructor for the core OS class. Sets up whats 
	//		needed to by the Operating System for the game engine.
	//
	///////////////////////////////////////////////////////////////
	core_os::core_os(){
		SDL_SysWMinfo SysInfo;

		if(SDL_GetWMInfo(&SysInfo) <= 0) {
			printf("%s : %d\n", SDL_GetError(), SysInfo.window);
		} else {
			this->currentWindow = SysInfo.window;
		}

	};
	
	///////////////////////////////////////////////////////////////
	//
	// ~core_os()
	//		Destructor for the core OS class. 
	//
	///////////////////////////////////////////////////////////////
	core_os::~core_os(){
	
	};
	
	///////////////////////////////////////////////////////////////
	//
	// init()
	//		Initializes the OS core for the game engine.
	//
	///////////////////////////////////////////////////////////////
	bool core_os::init(){
		if (SDL_Init(SDL_INIT_TIMER) < 0 ) return false;
		
		// this is where it would we create the windows for non-SDL versions of the game. Should try this out. :-)
		return true;
	};
	
	#ifdef _DEBUG
	///////////////////////////////////////////////////////////////
	//
	// init(CConsole *console)
	//		Initializes the OS core for the game engine.
	//		This one has a debug console attached.
	//
	///////////////////////////////////////////////////////////////
	bool core_os::init(CConsole *console){
		this->console = console;
		this->console->Print("core_os::init(): Start initialization.", MSG_DIAG);

		if (SDL_Init(SDL_INIT_TIMER) < 0 ) return false;
		
		// this is where it would we create the windows for non-SDL versions of the game. Should try this out. :-)
		this->console->Print("core_os::init(): End initialization.", MSG_DIAG);
		return true;
	};
	#endif

	///////////////////////////////////////////////////////////////
	//
	// cleanUp()
	//		Deletes all of the created and initialized objects.
	//		Does whatever is needed to tell the OS that the game engine is closing
	//
	///////////////////////////////////////////////////////////////
	void core_os::cleanUp(){
		// this should be within the core_os object.
		SDL_Quit();
	};
	
};