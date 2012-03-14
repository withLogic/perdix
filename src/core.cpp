#include "core.h"

// where should the timer class be? It's dependent on the OS
// and the libraries, but it can be abstracted from the core?

namespace perdix
{
	core::core(){
		#ifdef _DEBUG
			this->console = new CConsole;
		#endif

		this->running = true;
		this->paused = false;
		this->graphics_core = new core_graphics;
		this->os_core = new core_os;
	}

	core::~core(){
		this->cleanUp();

		#ifdef _DEBUG
			delete this->console;
		#endif

		delete this->graphics_core;
		delete this->os_core;
	}

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

			if(this->screen = this->graphics_core->init(width, height, depth, fullscreen, this->console));
			this->console->Print("core::init(): GRAPHICS_CORE initialized",MSG_DIAG);
		#else
			this->os_core->init();

			if(this->screen = this->graphics_core->init(width, height, depth, fullscreen));
		#endif

		this->graphics_core->SetTitle(APP_NAME);

		if(this->screen != NULL){
			return true;
		} else {
			return false;
		}
	}

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

			if(this->screen = this->graphics_core->init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, fullscreen, this->console));
			this->console->Print("core::init(): GRAPHICS_CORE initialized",MSG_DIAG);
		#else
			this->os_core->init();

			if(this->screen = this->graphics_core->init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, fullscreen));
		#endif
		
		this->graphics_core->SetTitle(APP_NAME);

		if(this->screen != NULL){
			return true;
		} else {
			return false;
		}
	}

	void core::cleanUp(){
		#ifdef _DEBUG
			this->console->cleanUp();
		#endif

		this->os_core->cleanUp();
		this->graphics_core->cleanUp();
	}

	void core::changeState(core_state* state) 
	{
		// cleanup the current state
		if ( !states.empty() ) {
			states.back()->Cleanup();
			states.pop_back();
		}

		// store and init the new state
		states.push_back(state);
		states.back()->Init(this);
	};

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

	void core::popState()
	{
		// cleanup the current state
		if ( !states.empty() ) {
			states.back()->Cleanup();
			states.pop_back();
		}

		// resume previous state
		if ( !states.empty() ) {
			states.back()->Resume();
		}
	};


	void core::update(){
		// do nothing
		states.back()->Draw();
	}
}