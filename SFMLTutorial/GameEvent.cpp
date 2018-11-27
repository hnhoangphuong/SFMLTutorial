#include "GameEvent.h"


EventTypes GameEvent::GetTypes()
{
	return (EventTypes)m_event.type;
}

GameEvent::GameEvent()
{
}


GameEvent::~GameEvent()
{
}
