#ifndef __BT_ENGINE_PROGRAM_H__
#define __BT_ENGINE_PROGRAM_H__

#include "engine/core/common.h"
#include "engine/graphics/shader.h"

#include <string>
#include <unordered_map>

#pragma warning(disable:4201)
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#pragma warning(default:4201)

namespace bt::engine
{
	// Program -------------------------------------------------------------------
	// ===========================================================================

	class Program final
	{
	public:
		/**
		 * Constructs a new Program object.
		 *
		 * @param vertex The vertex shader object to use.
		 * @param fragment The fragment shader object to use.
		 */
		Program(const Shader& vertex, const Shader& fragment);
		~Program();

		/**
		 * Activates this shader program for usage.
		 */
		void Bind() const;

		/**
		 * Deactivates this shader program for usage.
		 */
		void Unbind() const;

		/**
		 * Gets the ID of this program.
		 *
		 * @returns The ID of this program.
		 */
		uint32_t GetId() const;

		/**
		 * Sets a uniform with the given name to the specified float value.
		 *
		 * @param name The name of the uniform to set.
		 * @param value The float value to set the uniform to.
		 */
		void SetUniform(const std::string& name, float value);

		/**
		 * Sets a uniform with the given name to the specified integer value.
		 *
		 * @param name The name of the uniform to set.
		 * @param value The integer value to set the uniform to.
		 */
		void SetUniform(const std::string& name, int value);

		/**
		 * Sets a uniform with the given name to the specified 2D vector value.
		 *
		 * @param name The name of the uniform to set.
		 * @param value The 2D vector value to set the uniform to.
		 */
		void SetUniform(const std::string& name, const glm::vec2& value);

		/**
		 * Sets a uniform with the given name to the specified 3D vector value.
		 *
		 * @param name The name of the uniform to set.
		 * @param value The 3D vector value to set the uniform to.
		 */
		void SetUniform(const std::string& name, const glm::vec3& value);

		/**
		 * Sets a uniform with the given name to the specified 4D vector value.
		 *
		 * @param name The name of the uniform to set.
		 * @param value The 4D vector value to set the uniform to.
		 */
		void SetUniform(const std::string& name, const glm::vec4& value);

		/**
		 * Sets a uniform with the given name to the specified 4x4 matrix value.
		 *
		 * @param name The name of the uniform to set.
		 * @param value The 4x4 matrix value to set the uniform to.
		 */
		void SetUniform(const std::string& name, const glm::mat4& value);

	private:
		int32_t CacheUniformLocation(const std::string& name);

		uint32_t m_Id;
		std::unordered_map<std::string, int32_t> m_UniformCache;
	};
}

#endif // !__BT_ENGINE_PROGRAM_H__
