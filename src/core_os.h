/*
==================================================================

						Perdix - Core OS Header

==================================================================
*/

#ifndef CORE_OS_H
#define CORE_OS_H

// these are the libaries for this core_os.
#include <SDL.h>
#include <Windows.h>
#include "SDL_syswm.h"

// linking it to the rest of the engine
#include "core.h"

// defining variables needed for this core
#ifdef _WIN32
#define CORE_OS_WHDLR HWND
#else
#define CORE_OS_WHDLR Window
#endif

namespace perdix
{
	///////////////////////////////////////////////////////////////
	//
	// Class core_os
	//		The OS core. This handles all of the OS subsystems
	//		for the engine. This includes stuff like SDL, DirectX, ect.
	//		Also, window management and the like. (for example, pausing
	//		the current state whenever the game loses focus)
	//
	///////////////////////////////////////////////////////////////
	class core_os {
		private:
			#ifdef _DEBUG
				CConsole *console;
			#endif

			// window handler
			CORE_OS_WHDLR currentWindow;
		
		protected:
		
		public:
			core_os();
			~core_os();
			
			bool init();
			
			#ifdef _DEBUG
				bool init(CConsole *console);
			#endif

			void cleanUp();

			CORE_OS_WHDLR getWindowHandler(){return this->currentWindow;};
	};
};


#endif