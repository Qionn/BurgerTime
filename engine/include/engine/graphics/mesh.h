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
		/**
		 * Creates a mesh with the specified vertices.
		 *
		 * @param vertices A vector of vertices to use for the mesh.
		 */
		Mesh(const std::vector<Vertex>& vertices);
		~Mesh();

		/**
		 * Draws the mesh to the current context.
		 */
		void Draw() const;

	private:
		uint32_t m_VAO, m_VBO;
		size_t m_VertexCount;
	};
}

#endif // !__BT_ENGINE_MESH_H__
