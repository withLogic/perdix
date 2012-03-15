/*
==================================================================

						Perdix - Core Class Header

==================================================================
*/

#ifndef CORE_H
#define CORE_H

//
#include <vector>

// required files
#ifdef _DEBUG
	#include "core_win_console.h"
#endif
#include "core_state.h"

// all of the cores
#include "core_os.h"
#include "core_os_timer.h"
#include "core_graphics.h"

// defining the statics
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_DEPTH 32

#define APP_NAME "Perdix"
#define APP_AUTHOR "Matthew J Needham"
#define APP_AUTHOR_CONTACT "Matt@withlogic.com"
#define VERSION_MAJOR 0
#define VERSION_MINOR 0
#define VERSION_REV 1

namespace perdix
{
	///////////////////////////////////////////////////////////////
	//
	// Class core
	//		Primary game engine core. All of the other cores and the 
	//		rest of the game engine components call this file.
	//
	///////////////////////////////////////////////////////////////
	class core{
	private:
		// what is the engine doing?
		bool running;
		bool paused;
		
		// core variables
		core_os* os_core;
		core_graphics* graphics_core;
		CORE_GFX_SCREEN* screen;
		
		// Not even using this now, so ...
		//timer* timer;
		
		#ifdef _DEBUG
			CConsole *console;
		#endif

		std::vector<core_state*> states;

	protected:
	
	public:
		core();
		~core();
	
		bool init(int width, int height, int depth, bool fullscreen);
		bool init(bool fullscreen);

		void cleanUp();
	
		bool isRunning(){return this->running;}
		void setRunning(bool value){this->running = value;};
		bool isPaused(){return this->paused;}
		void setPaused(bool value){this->paused = value;};
		void quit(){this->running = false;};
		
		core_graphics* getGraphicsCore(){return this->graphics_core;}
		void setGraphicsCore(core_graphics* graphics_core){this->graphics_core = graphics_core;}
		core_os* getOSCore(){return this->os_core;}
		void setGraphicsCore(core_os* os_core){this->os_core = os_core;}

		CORE_GFX_SCREEN* getScreen(){return this->screen;};
		
		char* getTitle(){return this->graphics_core->getTitle();}
		bool getFullscreen(){return this->graphics_core->getFullscreen();}
		void toggleFullscreen(){this->graphics_core->toggleFullScreen();}
		int getWindowWidth(){return this->graphics_core->getWindowWidth();}
		int getWindowHeight(){return this->graphics_core->getWindowHeight();}

		#ifdef _DEBUG
			void debugPrint(std::string message, unsigned messageType){this->console->Print(message, messageType);};
		#endif

		void changeState(core_state* state);
		void pushState(core_state* state);
		void popState();

		void update();
	};
};

#endif