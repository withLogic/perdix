/*
==================================================================

						Perdix - Core Class

==================================================================
*/

// -- NOTE --
// where should the timer class be? It's dependent on the OS
// and the libraries, but it can be abstracted from the core?

#include "core.h"

namespace perdix
{
	///////////////////////////////////////////////////////////////
	//
	// core()
	//		Constructor for the core class. Sets up the cores and
	//		main variables
	//
	///////////////////////////////////////////////////////////////
	core::core(){
		#ifdef _DEBUG
			this->console = new CConsole;
		#endif

		this->running = true;
		this->paused = false;
		this->graphics_core = new core_graphics;
		this->os_core = new core_os;

		frameCountCore = 0;
		frameRateCore = 0;
		frameCountReal = 0;
		frameRateReal = 0;
	}

	///////////////////////////////////////////////////////////////
	//
	// ~core()
	//		Destructor for the core class. Calls the core's CleanUp
	//		function, and calls the other core's cleanup functions.
	//
	///////////////////////////////////////////////////////////////
	core::~core(){
		this->cleanUp();

		#ifdef _DEBUG
			delete this->console;
		#endif

		delete this->graphics_core;
		delete this->os_core;
	}

	///////////////////////////////////////////////////////////////
	//
	// init(int width, int height, int depth, bool fullscreen)
	//		The initialization function for the core. 
	//
	///////////////////////////////////////////////////////////////
	bool core::init(int width, int height, int depth, bool fullscreen){
		#ifdef _DEBUG
			this->console->init();
			this->console->Print("-----------------------------------------",MSG_NORMAL);
			this->console->Print("Perdix version 0.0.1",MSG_NORMAL);
			this->console->Print("Written by: Matthew J Needham",MSG_NORMAL);
			this->console->Print("-----------------------------------------",MSG_NORMAL);
		#endif


		// this is where we turn all of the cores online. 
		#ifdef _DEBUG
			this->os_core->init(this->console);
			this->console->Print("core::init(): OS_CORE initialized",MSG_DIAG);

			if(this->screen = this->graphics_core->init(width, height, depth, fullscreen, this->console))
			{
				this->console->Print("core::init(): GRAPHICS_CORE initialized",MSG_DIAG);
			}
		#else
			this->os_core->init();
			this->screen = this->graphics_core->init(width, height, depth, fullscreen);
		#endif

		this->graphics_core->SetTitle(APP_NAME);

		if(this->screen != NULL){
			return true;
		} else {
			return false;
		}
	}

	///////////////////////////////////////////////////////////////
	//
	// init(int width, int height, int depth, bool fullscreen)
	//		The initialization function for the core. 
	//
	///////////////////////////////////////////////////////////////
	bool core::init(bool fullscreen){
		#ifdef _DEBUG
			char buffForAppInfo[100];
			sprintf(buffForAppInfo, "%s - %d.%d.%d", APP_NAME, VERSION_MAJOR, VERSION_MINOR, VERSION_REV);
			std::string buffAsStdStr1 = buffForAppInfo;

			char buffForAuthorInfo[100];
			sprintf(buffForAuthorInfo, "%s - %s", APP_AUTHOR, APP_AUTHOR_CONTACT);
			std::string buffAsStdStr2 = buffForAuthorInfo;

			this->console->init();
			this->console->Print("-----------------------------------------",MSG_NORMAL);
			this->console->Print(buffAsStdStr1,MSG_NORMAL);
			this->console->Print(buffAsStdStr2,MSG_NORMAL);
			this->console->Print("-----------------------------------------",MSG_NORMAL);
		#endif

		#ifdef _DEBUG
			this->os_core->init(this->console);
			this->console->Print("core::init(): OS_CORE initialized",MSG_DIAG);

			if(this->screen = this->graphics_core->init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, fullscreen, this->console))
			{
				this->console->Print("core::init(): GRAPHICS_CORE initialized",MSG_DIAG);
			}
		#else
			this->os_core->init();
			this->screen = this->graphics_core->init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, fullscreen);
		#endif
		
		this->graphics_core->SetTitle(APP_NAME);

		if(this->screen != NULL){
			return true;
		} else {
			return false;
		}
	}

	///////////////////////////////////////////////////////////////
	//
	// handleArgs(int argc, char* args[])
	//		Handle any arguements given to it from the commandline or shortcut.
	//		Currently, thats nothing.
	//
	///////////////////////////////////////////////////////////////
	void core::handleArgs(int argc, char* args[]){
		std::vector<std::string> argv(args, args + argc);
		std::vector<std::string>::iterator it = argv.begin();
		
		++it;

		while (it != argv.end()){
			if(*it == "--fullscreen" || *it == "-f")
			{
				//This will make the game start in fullscreen mode!
			}
			else if(*it == "--window" || *it == "-w")
			{
				//This will make the game start in windowed mode!
			}
			it++;
		};

	};

	///////////////////////////////////////////////////////////////
	//
	// cleanUp()
	//		Calls the cleanUp function for all of the cores. 
	//
	///////////////////////////////////////////////////////////////
	bool core::cleanUp(){
		#ifdef _DEBUG
			this->console->cleanUp();
		#endif

		// destroy the active state
		// -- NOTE --
		// should also look for a paused state and destroy it too...
		if ( !states.empty() ) {
			states.back()->CleanUp();
			states.pop_back();
		};

		// destroy the cores
		this->graphics_core->cleanUp();
		this->os_core->cleanUp();

		return true;
	}

	///////////////////////////////////////////////////////////////
	//
	// changeState(core_state* state)
	//		Detroys the active state and replaces it with the new state 
	//
	///////////////////////////////////////////////////////////////
	void core::changeState(core_state* state) 
	{
		// cleanup the current state
		if ( !states.empty() ) {
			states.back()->CleanUp();
			states.pop_back();
		}

		// store and init the new state
		states.push_back(state);
		states.back()->Init(this);
	};
	
	///////////////////////////////////////////////////////////////
	//
	// pushState(core_state* state)
	//		Pauses the active state and activates the new state.
	//
	///////////////////////////////////////////////////////////////
	void core::pushState(core_state* state)
	{
		// pause current state
		if ( !states.empty() ) {
			states.back()->Pause();
		}

		// store and init the new state
		states.push_back(state);
		states.back()->Init(this);
	};

	///////////////////////////////////////////////////////////////
	//
	// popState(core_state* state)
	//		Resumes the paused state and destroys the active state.
	//
	///////////////////////////////////////////////////////////////
	void core::popState()
	{
		// cleanup the current state
		if ( !states.empty() ) {
			states.back()->CleanUp();
			states.pop_back();
		}

		// resume previous state
		if ( !states.empty() ) {
			states.back()->Resume();
		}
	};

	///////////////////////////////////////////////////////////////
	//
	// handleEvents()
	//		Tells the active state to handle events.
	//
	///////////////////////////////////////////////////////////////
	void core::handleEvents(){
		// -- NOTE --
		// What do we need to do to let the engine handle its events.
		states.back()->HandleEvents();
	}

	///////////////////////////////////////////////////////////////
	//
	// update()
	//		Tells the active state to call it's update function
	//
	///////////////////////////////////////////////////////////////
	void core::update(){
		static timer timedUpdate;

		frameCountCore++;
		if(this->coreTimer.stopwatch(999)){
			frameRateCore = frameCountCore;
			frameCountCore = 0;
		}

		states.back()->Update();

		if(!timedUpdate.stopwatch(14)){
			SDL_Delay(1);
		} else {
			frameCountReal++;
			if(this->realTimer.stopwatch(999)){
				frameRateReal = frameCountReal;
				frameCountReal = 0;
			};
		};

		char buff[100];
		sprintf(buff, "%s - Real: %d Core: %d", "Perdix - ", frameRateReal, frameRateCore);

		this->setTitle(buff);

	}

	///////////////////////////////////////////////////////////////
	//
	// draw()
	//		Tells the active state to draw to the screen.
	//
	///////////////////////////////////////////////////////////////
	void core::draw(){
		// do nothing
		states.back()->Draw();
	}

}