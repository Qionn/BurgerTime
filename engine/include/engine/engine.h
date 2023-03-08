#ifndef __BT_ENGINE_ENGINE_H__
#define __BT_ENGINE_ENGINE_H__

#include "core/application.h"
#include "core/common.h"
#include "core/event.h"
#include "core/time.h"
#include "core/window.h"

#include "core/events/game_object_events.h"
#include "core/events/window_events.h"
#include "core/events/keyboard_events.h"
#include "core/events/mouse_events.h"

#include "scene/component.h"
#include "scene/scene.h"
#include "scene/game_object.h"

#include "scene/components/transform_component.h"

#include "utils/family.h"
#include "utils/messenger.h"
#include "utils/timer.h"

namespace bt
{
	using namespace engine;
}

#endif // !__BT_ENGINE_ENGINE_H__
