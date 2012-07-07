
#include "actor_hero.h"
#include "core.h"

actor_hero::actor_hero(perdix::core_state* state){
	this->parentState = state;
	this->image = new perdix::sprite;
	this->image->loadImageTransparent("hero.bmp");

	this->alive = true;
	this->visible = true;
	this->solid = true;
};

actor_hero::~actor_hero(){
	delete this->image;
};

int actor_hero::toggleVisible(){
	if(this->visible == true){
		this->visible = false;
	} else {
		this->visible = true;
	}

	return 0;
}

void actor_hero::draw(){
	
}