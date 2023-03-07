#ifndef __BT_ENGINE_SHADER_H__
#define __BT_ENGINE_SHADER_H__

#include "engine/core/common.h"

#include <vector>

namespace bt::engine
{
	// Shader --------------------------------------------------------------------
	// ===========================================================================

	class Shader final
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(Shader)

	public:
		/**
		 * The Type enum specifies the type of shader.
		 */
		enum class Type
		{
			Vertex		= 0x8B31,	// GL_VERTEX_SHADER
			Fragment	= 0x8B30	// GL_FRAGMENT_SHADER
		};

		/**
		 * Constructs a new Shader object.
		 *
		 * @param source A vector to the shader source code.
		 * @param type The type of shader.
		 */
		Shader(const std::vector<char>& source, Type type);

		/**
		 * Constructs a new Shader object.
		 *
		 * @param pSource A pointer to the shader source code.
		 * @param size The size of the shader source code.
		 * @param type The type of shader.
		 */
		Shader(const char* pSource, size_t size, Type type);
		~Shader();

		/**
		 * Gets the ID of this shader.
		 *
		 * @returns The ID of this shader.
		 */
		uint32_t GetId() const;

		/**
		 * Gets the type of this shader.
		 *
		 * @returns The type of this shader.
		 */
		Type GetType() const;

	private:
		uint32_t m_Id = 0;
		Type m_Type;
	};
}

#endif // !__BT_ENGINE_SHADER_H__
