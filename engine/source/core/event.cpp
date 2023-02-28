#include "stdafx.h"

#include "engine/core/event.h"

namespace bt::engine
{
	Event::Event(uint32_t id)
		: m_Id{ id }
		, m_IsHandled{ false }
	{

	}
}
