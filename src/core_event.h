/*
==================================================================

						Perdix - Core Event Header

==================================================================
*/

#ifndef CORE_EVENT_H
#define CORE_EVENT_H

#include "core.h"

namespace perdix
{

	typedef std::vector<core_actor*> ObjectsThemselves;
	typedef std::vector<ObjectsThemselves> EventLists;

	class core_event {
		public:
			core_event();
			~core_event();
			
			void init();
			void cleanUp();
			
			int addEventType(char* eventName);
			void removeEventType(char* eventName);
			
			int lookupEventIdByName(char* eventName);
			char* lookupEventNameById(int eventId);
			
			void handleEvents(int eventId);
			void registerActorToEvent(int eventId, core_actor* ActorPointer);
			void unregisterActorToEvent(int eventId, core_actor* ActorPointer);
			void unregisterAllFromEvent(int eventId);
			
		private:		
			EventLists EventsForThisState;
			// some sort of lookup table between IDs and Names.
	};
};

#endif