/*
==================================================================

						Perdix - Core Event

==================================================================
*/

#include "core.h"

namespace perdix
{
	///////////////////////////////////////////////////////////////
	//
	// core_event()
	//		Constructor for the events manager.
	//
	///////////////////////////////////////////////////////////////
	core_event::core_event(){
		// start the event.
		// create the base set of events
		// -- DRAW
		// -- STEP
		// -- KeyUp
		// -- KeyDown
		this->addEventType("Draw");
		this->addEventType("Step");
		this->addEventType("KeyUp");
		this->addEventType("KeyDown");
	};

	///////////////////////////////////////////////////////////////
	//
	// ~event()
	//		Destructor for the events manager.
	//
	///////////////////////////////////////////////////////////////
	core_event::~core_event(){
		// destroy the event.
	};
	
	///////////////////////////////////////////////////////////////
	//
	// init()
	//		Initialization for the events manager.
	//
	///////////////////////////////////////////////////////////////
	void core_event::init(){
		// init the event manager.
	};
	
	///////////////////////////////////////////////////////////////
	//
	// cleanUp()
	//		Clean up function for the events manager.
	//
	///////////////////////////////////////////////////////////////
	void core_event::cleanUp(){
		// clean up the event manager.
	};
	
	///////////////////////////////////////////////////////////////
	//
	// addEventType(char* eventName)
	//		Creates a new event type and adds it to the event manager.
	//
	///////////////////////////////////////////////////////////////
	int core_event::addEventType(char* eventName){
		// this should also log the index number (vectorLength++) 
		// and the eventName into a lookup table.
		int vectorLength = this->EventsForThisState.size();
		this->EventsForThisState.push_back(ObjectsThemselves());
		
		return vectorLength++;
	};
	
	///////////////////////////////////////////////////////////////
	//
	// removeEventType(char* eventName)
	//		Removes an event type from the event manager.
	//
	///////////////////////////////////////////////////////////////
	void core_event::removeEventType(char* eventName){
		// remove the event from the event manager.
	};
	
	///////////////////////////////////////////////////////////////
	//
	// lookupEventIdByName(char* eventName)
	//		Returns the ID of the event based on it's name.
	//
	///////////////////////////////////////////////////////////////
	int core_event::lookupEventIdByName(char* eventName){
		// return the ID of the event based on the name,
		return 1;
	};
	
	///////////////////////////////////////////////////////////////
	//
	// lookupEventNameById(int eventId)
	//		Returns the name of the Event of the event based on it's ID.
	//
	///////////////////////////////////////////////////////////////
	char* core_event::lookupEventNameById(int eventId){
		// return the name of the event based on the ID.
		return "nothing";
	};
	
	///////////////////////////////////////////////////////////////
	//
	// handleEvents(int eventId)
	//		Tells the objects of the Event ID to do their things
	//
	///////////////////////////////////////////////////////////////
	void core_event::handleEvents(int eventId){
		// tell the registered objects to handle their shit.
	};
	
	///////////////////////////////////////////////////////////////
	//
	// registerActorToEvent(int eventId, core_actor* ActorPointer)
	//		Registers the ActorPointer to the EventID
	//
	///////////////////////////////////////////////////////////////
	void core_event::registerActorToEvent(int eventId, core_actor* ActorPointer){
		// register an actor to an event.
		this->EventsForThisState[eventId].push_back(ActorPointer);
	};
	
	///////////////////////////////////////////////////////////////
	//
	// unregisterActorToEvent(int eventId, core_actor* ActorPointer)
	//		UnRegisters the ActorPointer to the EventID
	//
	///////////////////////////////////////////////////////////////
	void core_event::unregisterActorToEvent(int eventId, core_actor* ActorPointer){
		// unregister an actor to an event.
	};
	
	///////////////////////////////////////////////////////////////
	//
	// unregisterAllFromEvent(int eventId, core_actor* ActorPointer)
	//		UnRegisters all of the actors from the EventID
	//
	///////////////////////////////////////////////////////////////
	void core_event::unregisterAllFromEvent(int eventId){
		// unregister all of the actors from the event.
	};
	
};