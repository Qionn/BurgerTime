#ifndef __BT_ENGINE_MATERIAL_H__
#define __BT_ENGINE_MATERIAL_H__

#include "engine/core/common.h"

#include <string>
#include <unordered_map>

namespace bt::engine
{
	class Material final
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(Material)

	public:
		Material(const char* pVertexPath, const char* pFragmentPath);
		~Material();

		void Bind() const;
		void Unbind() const;

	private:
		void ValidateProgram() const;
		void CacheUniforms();
		static uint32_t CompileShader(const char* pShaderPath, uint32_t type);

		uint32_t m_Id;
		std::unordered_map<std::string, uint32_t> m_UniformCache;
	};
}

#endif // !__BT_ENGINE_MATERIAL_H__
