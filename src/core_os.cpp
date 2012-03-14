// linking it to the rest of the engine
#include "core.h"

namespace perdix
{
	core_os::core_os(){
		SDL_SysWMinfo SysInfo;

		if(SDL_GetWMInfo(&SysInfo) <= 0) {
			printf("%s : %d\n", SDL_GetError(), SysInfo.window);
		} else {
			this->currentWindow = SysInfo.window;
		}

	};
	
	core_os::~core_os(){
	
	};
	
	bool core_os::init(){
		if (SDL_Init(SDL_INIT_TIMER) < 0 ) return false;
		
		// this is where it would we create the windows for non-SDL versions of the game. Should try this out. :-)
		return true;
	};
	
	#ifdef _DEBUG
	bool core_os::init(CConsole *console){
		this->console = console;
		this->console->Print("core_os::init(): Start initialization.", MSG_DIAG);

		if (SDL_Init(SDL_INIT_TIMER) < 0 ) return false;
		
		// this is where it would we create the windows for non-SDL versions of the game. Should try this out. :-)
		this->console->Print("core_os::init(): End initialization.", MSG_DIAG);
		return true;
	};
	
	#endif

	void core_os::cleanUp(){
		// this should be within the core_os object.
		SDL_Quit();
	};
	
};