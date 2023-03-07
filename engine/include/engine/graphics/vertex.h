#ifndef __BT_ENGINE_VERTEX_H__
#define __BT_ENGINE_VERTEX_H__

#include "engine/core/common.h"

#pragma warning(disable:4201)
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#pragma warning(default:4201)

namespace bt::engine
{
	// Vertex --------------------------------------------------------------------
	// ===========================================================================

	struct Vertex final
	{
		glm::vec3 position;
		glm::vec2 texCoord;
	};
}

#endif // !__BT_ENGINE_VERTEX_H__
