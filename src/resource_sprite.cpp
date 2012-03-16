/*
==================================================================

						Perdix - Resource: Sprite

==================================================================
*/

#include "core.h"

namespace perdix
{
	///////////////////////////////////////////////////////////////
	//
	// loadImage(char* imageName)
	//		Loads the image.
	//		In the future, this is going to be passed through to the 
	//		Resource Manager to handle.
	//
	///////////////////////////////////////////////////////////////
	bool sprite::loadImage(char* imageName){
		ACTOR_IMAGE *temp;
		temp = SDL_LoadBMP(imageName);

		if (temp != NULL){	
			this->image = SDL_DisplayFormat(temp);
			SDL_FreeSurface(temp);

			this->height = this->image->h;
			this->width = this->image->w;

			return true;
		}
		return false;
	};
	
	///////////////////////////////////////////////////////////////
	//
	// loadImageTransparent(char* imageName)
	//		Loads the image with transparency from the upper left hand pixel.
	//		In the future, this is going to be passed through to the 
	//		Resource Manager to handle.
	//
	///////////////////////////////////////////////////////////////
	bool sprite::loadImageTransparent(char* imageName){
		ACTOR_IMAGE *temp;
		temp = SDL_LoadBMP(imageName);

		if (temp != NULL){	
			this->image = SDL_DisplayFormat(temp);
			Uint32 *pixels = (Uint32 *)this->image->pixels;
			SDL_SetColorKey(this->image, SDL_SRCCOLORKEY | SDL_RLEACCEL, pixels[ ( 0 * this->image->w ) + 0 ]);  // should make the image transparent based on the first pixel.
			SDL_FreeSurface(temp);

			this->height = this->image->h;
			this->width = this->image->w;

			return true;
		}

		return false;
	};

	///////////////////////////////////////////////////////////////
	//
	// cleanUp(char* imageName)
	//		Frees up the imagee.
	//
	///////////////////////////////////////////////////////////////
	void sprite::cleanUp(){
		SDL_FreeSurface(this->image);
	};

}