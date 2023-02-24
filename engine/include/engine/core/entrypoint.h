#ifndef __BT_ENGINE_ENTRY_POINT_H__
#define __BT_ENGINE_ENTRY_POINT_H__

#include "engine/core/application.h"

#include <memory>

namespace bt::engine
{
	extern std::unique_ptr<bt::engine::Application> AppFactory();
}

#endif // !__BT_ENGINE_ENTRY_POINT_H__
