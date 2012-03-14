#ifndef CORE_GRAPHICS_H
#define CORE_GRAPHICS_H

// these are the libaries for this core_graphics.
#include <SDL_image.h>

// linking it to the rest of the engine
#include "core.h"

// defining variables needed for this core
#define CORE_GFX_SCREEN SDL_Surface
#define ACTOR_IMAGE SDL_Surface
#define ACTOR_RECT SDL_Rect

namespace perdix
{
	class core_graphics {
		private:
			#ifdef _DEBUG
				CConsole *console;
			#endif

			CORE_GFX_SCREEN* screen;
			Uint32 flags;
			
			// what does our window looklike?
			bool w_fullscreen;
			char* w_title;
			int w_width;
			int w_height;
			int w_depth;
	
		public:
			core_graphics();
			~core_graphics();
			
			CORE_GFX_SCREEN* init(int width, int height, int depth, bool fullscreen);
			#ifdef _DEBUG
				CORE_GFX_SCREEN* init(int width, int height, int depth, bool fullscreen, CConsole *console);
			#endif

			CORE_GFX_SCREEN* toggleFullScreen();
			void cleanUp();
			
			char* getTitle(){return this->w_title;}
			bool getFullscreen(){return this->w_fullscreen;}
			int getWindowWidth(){return this->w_width;}
			int getWindowHeight(){return this->w_height;}
			
			void SetTitle(char* title);
	};
	
}

#endif