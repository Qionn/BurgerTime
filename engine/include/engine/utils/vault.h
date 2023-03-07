#ifndef __BT_ENGINE_VAULT_H__
#define __BT_ENGINE_VAULT_H__

#include "engine/core/common.h"
#include "engine/graphics/mesh.h"
#include "engine/graphics/program.h"

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

namespace bt::engine
{
	// Vault ---------------------------------------------------------------------
	// ===========================================================================

	class Vault final
	{
		BT_ENGINE_DISALLOW_IMPLICIT_CONSTRUCTOR(Vault)

	public:
		/**
		 * Loads a shader program from the given vertex and fragment shader files.
		 *
		 * @param vertexPath The file path to the vertex shader source code.
		 * @param fragmentPath The file path to the fragment shader source code.
		 * @param tag The tag to use for this program.
		 * @returns A pointer to the loaded Program object.
		 */
		static Program* LoadProgram(const std::string& vertexPath, const std::string& fragmentPath, const std::string& tag);

		/**
		 * Gets the program with the specified tag.
		 *
		 * @param tag The tag of the program to retrieve.
		 * @returns A pointer to the Program object with the specified tag, or nullptr if not found.
		 */
		static Program* GetProgram(const std::string& tag);

		/**
		 * Saves a mesh with the specified vertices and tag.
		 *
		 * @param vertices A vector of vertices to use for the mesh.
		 * @param tag The tag to use for the cached mesh.
		 * @returns A pointer to the cached mesh.
		 */
		static Mesh* SaveMesh(const std::vector<Vertex>& vertices, const std::string& tag);

		/**
		 * Gets a saved mesh with the specified tag.
		 *
		 * @param tag The tag of the cached mesh to get.
		 * @returns A pointer to the cached mesh, or nullptr if no mesh with the specified tag was found.
		 */
		static Mesh* GetMesh(const std::string& tag);

	private:
		static std::vector<char> ReadFile(const std::string& filepath);

		static std::unordered_map<std::string, std::unique_ptr<Program>> m_Programs;
		static std::unordered_map<std::string, std::unique_ptr<Mesh>> m_Meshes;
	};
}

#endif // !__BT_ENGINE_VAULT_H__
