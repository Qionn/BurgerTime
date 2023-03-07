#include "stdafx.h"

#include "engine/graphics/shader.h"

#include <fstream>
#include <sstream>

namespace bt::engine
{
	Shader::Shader(const std::vector<char>& source, Type type)
		: Shader(source.data(), source.size(), type)
	{

	}

	Shader::Shader(const char* pSource, size_t size, Type type)
		: m_Type{ type }
	{
		m_Id = glCreateShader(static_cast<GLenum>(type));

		auto length = static_cast<GLint>(size);
		glShaderSource(m_Id, 1, &pSource, &length);
		glCompileShader(m_Id);

	#ifdef _DEBUG
		GLint success = 0;
		glGetShaderiv(m_Id, GL_COMPILE_STATUS, &success);
		if (success != GL_TRUE)
		{
			char infoLog[1024];
			glGetShaderInfoLog(m_Id, ARRAYSIZE(infoLog), nullptr, infoLog);

			std::stringstream ss;
			ss << "Shader compilation failed:\n" << infoLog;

			OutputDebugStringA(ss.str().c_str());
		}
	#endif
	}

	Shader::~Shader()
	{
		glDeleteShader(m_Id);
	}

	uint32_t Shader::GetId() const
	{
		return m_Id;
	}

	Shader::Type Shader::GetType() const
	{
		return m_Type;
	}
}
