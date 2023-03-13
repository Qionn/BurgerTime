#ifndef __BT_ENGINE_MESH_H__
#define __BT_ENGINE_MESH_H__

#include "engine/core/common.h"
#include "engine/graphics/vertex.h"

#include <vector>

namespace bt::engine
{
	// Mesh ----------------------------------------------------------------------
	// ===========================================================================

	class Mesh final
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(Mesh)

	public:
		Mesh(const std::vector<Vertex>& vertices, const std::vector<uint16_t>& indices);
		~Mesh();

		void Draw() const;

	private:
		uint32_t m_VAO, m_VBO, m_EBO;
		uint32_t m_ElementCount;
	};
}

#endif // !__BT_ENGINE_MESH_H__
