#include "stdafx.h"

#include "engine/graphics/program.h"

#include <sstream>

#pragma warning(disable:4201)
#include <glm/gtc/type_ptr.hpp>
#pragma warning(default:4201)

namespace bt::engine
{
	Program::Program(const Shader& vertex, const Shader& fragment)
	{
		m_Id = glCreateProgram();
		glAttachShader(m_Id, vertex.GetId());
		glAttachShader(m_Id, fragment.GetId());
		glLinkProgram(m_Id);

	#ifdef _DEBUG
		GLint success = GL_FALSE;
		glGetProgramiv(m_Id, GL_LINK_STATUS, &success);
		if (success != GL_TRUE)
		{
			char infoLog[1024];
			glGetProgramInfoLog(m_Id, ARRAYSIZE(infoLog), nullptr, infoLog);

			std::stringstream ss;
			ss << "Failed to link program:\n" << infoLog;

			OutputDebugStringA(ss.str().c_str());
		}
	#endif
	}

	Program::~Program()
	{
		glDeleteProgram(m_Id);
	}

	void Program::Bind() const
	{
		glUseProgram(m_Id);
	}

	void Program::Unbind() const
	{
		glUseProgram(0);
	}

	uint32_t Program::GetId() const
	{
		return m_Id;
	}

	void Program::SetUniform(const std::string& name, float value)
	{
		glUniform1f(CacheUniformLocation(name), value);
	}

	void Program::SetUniform(const std::string& name, int value)
	{
		glUniform1i(CacheUniformLocation(name), value);
	}

	void Program::SetUniform(const std::string& name, const glm::vec2& value)
	{
		glUniform2fv(CacheUniformLocation(name), 1, glm::value_ptr(value));
	}

	void Program::SetUniform(const std::string& name, const glm::vec3& value)
	{
		glUniform3fv(CacheUniformLocation(name), 1, glm::value_ptr(value));
	}

	void Program::SetUniform(const std::string& name, const glm::vec4& value)
	{
		glUniform4fv(CacheUniformLocation(name), 1, glm::value_ptr(value));
	}

	void Program::SetUniform(const std::string& name, const glm::mat4& value)
	{
		glUniformMatrix4fv(CacheUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
	}

	int32_t Program::CacheUniformLocation(const std::string& name)
	{
		auto it = m_UniformCache.find(name);
		if (it == m_UniformCache.end())
		{
			return m_UniformCache[name] = glGetUniformLocation(m_Id, name.c_str());
		}

		return it->second;
	}
}
