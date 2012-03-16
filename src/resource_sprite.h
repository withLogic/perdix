/*
==================================================================

						Perdix - Resource: Sprite Header

==================================================================
*/

#ifndef RESOURCE_SPRITE_H
#define RESOURCE_SPRITE_H

#include "core.h"

namespace perdix
{
	///////////////////////////////////////////////////////////////
	//
	// Class sprite
	//		Represents all of the images in the engine. 
	//
	///////////////////////////////////////////////////////////////
	
	// -- NOTE -- 
	// This should eventually look like below.
	// class sprite : public core_resource {
	
	class sprite {
		public:
			bool loadImage(char* imageName);
			bool loadImageTransparent(char* imageName);
			void cleanUp();
			
			ACTOR_IMAGE* getImage(){return this->image;};
			
			int getWidth(){return this->width;};
			int getHeight(){return this->height;};
			double getScale(){return this->scale;};
			double getRotation(){return this->rotation;};

		private:
			ACTOR_IMAGE* image;
			int width;
			int height;
			int animatedColumns;
			int animatedFrameStart;
			int animatedFrameEnd;
			int animatedStartX;
			int animatedStartY;
			int animatedCurrentFrame;
			bool transparent;
			
			double rotation;
			double scale;		
	};

};

#endif