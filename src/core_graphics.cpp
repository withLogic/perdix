#include "core.h"

// this core_graphics module is made for SDL. There should be a naming convention later down the road that specifies this
// and maybe have something like a 'helper' file that loads all of the required includes for the particular platform
// example: if platform == wii -> load all of the wii includes.

namespace perdix
{
	core_graphics::core_graphics(){
		// init the libraries and stuff.
		this->flags = SDL_HWSURFACE | SDL_DOUBLEBUF;
	}

	core_graphics::~core_graphics(){
		// delete whatever we created above.
	}

	CORE_GFX_SCREEN* core_graphics::init(int width, int height, int depth, bool fullscreen){
		if (SDL_Init(SDL_INIT_VIDEO) < 0 ) return NULL;
		
		if(fullscreen){
			this->flags ^= SDL_FULLSCREEN;
			this->w_fullscreen = true;
		}
		
		if (!(this->screen = SDL_SetVideoMode(width, height, depth, this->flags )))
		{
			SDL_Quit();	
		}

		this->w_height = height;
		this->w_width = width;
		this->w_depth = depth;
		
		return this->screen;	
	}

	#ifdef _DEBUG
	CORE_GFX_SCREEN* core_graphics::init(int width, int height, int depth, bool fullscreen, CConsole *console){
		this->console = console;

		this->console->Print("core_graphics::init(): Start initialization.", MSG_DIAG);
		
		if (SDL_Init(SDL_INIT_VIDEO) < 0 ) return NULL;
		
		if(fullscreen){
			this->flags ^= SDL_FULLSCREEN;
			this->w_fullscreen = true;
		}
		
		if (!(this->screen = SDL_SetVideoMode(width, height, depth, this->flags )))
		{
			SDL_Quit();	
		}

		this->w_height = height;
		this->w_width = width;
		this->w_depth = depth;
		
		this->console->Print("core_graphics::init(): Ending initialization.", MSG_DIAG);

		return this->screen;	
	}
	#endif
	
	CORE_GFX_SCREEN* core_graphics::toggleFullScreen(){
		// i dont think this works, haha. Maybe I should fix that!
		if (this->w_fullscreen){
			this->flags |= SDL_FULLSCREEN; 
			this->w_fullscreen = false;
		} else {
			this->flags ^= SDL_FULLSCREEN;
			this->w_fullscreen = true;
		}
		
		this->screen = SDL_SetVideoMode(this->w_width, this->w_height, this->w_depth, this->flags);
		
		return this->screen;		
	}
	
	void core_graphics::SetTitle(char* title){
		this->w_title = title;
		SDL_WM_SetCaption(this->w_title, this->w_title);

		#ifdef _DEBUG
			this->console->Print("core_graphics::SetTitle(): The title of the window has been set.", MSG_DIAG);
		#endif

	}

	void core_graphics::cleanUp(){
		delete this->screen;
	}
}