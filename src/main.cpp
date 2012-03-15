/*
==================================================================

						Game - Main

==================================================================
*/

#include "core.h"

// -- NOTE --  
// Move the states into a statemanager.h file.

#include "IntroState.h"
#include "SecondState.h"

///////////////////////////////////////////////////////////////
//
// main(  int argc, char* args[] )
//		The main function, this is where the magic starts.
//
///////////////////////////////////////////////////////////////
int main( int argc, char* args[] ) 
{
	perdix::core PerdixGame;
	if(PerdixGame.init(false) == false){return 0;};

	PerdixGame.changeState( IntroState::Instance() );
		#ifdef _DEBUG
			PerdixGame.debugPrint("main(): ERROR - The game engine STILL doesn't do anything", MSG_ERROR);
		#endif

	bool state = true;

	while(PerdixGame.isRunning()){
		if(state){
			PerdixGame.changeState( SecondState::Instance() );
			state = false;
		} else {
			PerdixGame.changeState( IntroState::Instance() );
			state = true;
		}

		Sleep(450);
		PerdixGame.update();
	}/*while*/

	return 0;
}/*main*/
