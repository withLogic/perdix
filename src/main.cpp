/*
==================================================================

						Game - Main

==================================================================
*/

#include "core.h"

// -- NOTE --  
// Move the states into a statemanager.h file.

#include "IntroState.h"

///////////////////////////////////////////////////////////////
//
// main(  int argc, char* args[] )
//		The main function, this is where the magic starts.
//
///////////////////////////////////////////////////////////////
int main( int argc, char* args[] ) 
{
	perdix::core PerdixGame;
	PerdixGame.handleArgs(argc, args);

	if(PerdixGame.init(PerdixGame.argFullScreen) == false){return 0;};

	PerdixGame.changeState( IntroState::Instance() );
		#ifdef _DEBUG
			PerdixGame.debugPrint("main(): ERROR - The game engine STILL doesn't do anything", MSG_ERROR);
		#endif

	while(PerdixGame.isRunning()){
		
		PerdixGame.handleEvents();
		PerdixGame.update();
		PerdixGame.draw();

	}/*while*/

	if(!PerdixGame.cleanUp()){
		// do something to log whatever errors

	}

	return 0;
}/*main*/
