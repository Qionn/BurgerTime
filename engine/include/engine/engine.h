#ifndef __BT_ENGINE_ENGINE_H__
#define __BT_ENGINE_ENGINE_H__

#include "core/application.h"
#include "core/common.h"
#include "core/event.h"
#include "core/time.h"
#include "core/window.h"

#include "core/events/component_events.h"
#include "core/events/window_events.h"
#include "core/events/keyboard_events.h"
#include "core/events/mouse_events.h"

#include "engine/graphics/mesh.h"
#include "engine/graphics/program.h"
#include "engine/graphics/shader.h"
#include "engine/graphics/vertex.h"

#include "scene/component.h"
#include "scene/scene.h"
#include "scene/game_object.h"

#include "scene/components/sprite_component.h"
#include "scene/components/transform_component.h"

#include "utils/family.h"
#include "utils/messenger.h"
#include "utils/timer.h"
#include "utils/vault.h"

#include <windows.h>

namespace bt
{
	using namespace engine;
}

#endif // !__BT_ENGINE_ENGINE_H__
