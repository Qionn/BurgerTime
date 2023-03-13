#include "stdafx.h"

#include "engine/graphics/material.h"

#include <fstream>
#include <filesystem>
#include <iostream>

namespace bt::engine
{
	Material::Material(const char* pVertexPath, const char* pFragmentPath)
	{
		uint32_t vertexId	= CompileShader(pVertexPath, GL_VERTEX_SHADER);
		uint32_t fragmentId	= CompileShader(pFragmentPath, GL_FRAGMENT_SHADER);

		m_Id = glCreateProgram();
		glAttachShader(m_Id, vertexId);
		glAttachShader(m_Id, fragmentId);
		glLinkProgram(m_Id);

		glDeleteShader(vertexId);
		glDeleteShader(fragmentId);
		
		ValidateProgram();
		CacheUniforms();
	}

	Material::~Material()
	{
		glDeleteProgram(m_Id);
	}

	void Material::Bind() const
	{
		glUseProgram(m_Id);
	}

	void Material::Unbind() const
	{
		glUseProgram(0);
	}

	void Material::ValidateProgram() const
	{
	#ifdef _DEBUG
		GLint success = 0;
		glGetProgramiv(m_Id, GL_LINK_STATUS, &success);
		if (success != GL_TRUE)
		{
			char infoLog[1024];
			glGetProgramInfoLog(m_Id, 1024, nullptr, infoLog);
			std::cerr << infoLog;
		}
	#endif

		GLint size = 0;
		GLenum type = 0;
		GLchar name[256];

		glGetActiveAttrib(m_Id, 0, 256, nullptr, &size, &type, name);
		if (type != GL_FLOAT_VEC3)
		{
			throw std::runtime_error("First attribute must be a vec3 (position)!");
		}
	}

	void Material::CacheUniforms()
	{
		GLint uniformCount = 0;
		glGetProgramInterfaceiv(m_Id, GL_UNIFORM, GL_ACTIVE_RESOURCES, &uniformCount);

		GLchar name[256];
		for (GLuint i = 0; i < static_cast<GLuint>(uniformCount); ++i)
		{
			glGetProgramResourceName(m_Id, GL_UNIFORM, i, 256, nullptr, name);
			m_UniformCache[name] = i;
		}
	}

	/* static */ uint32_t Material::CompileShader(const char* pShaderPath, uint32_t type)
	{
		uint32_t id = glCreateShader(type);
		
		if (std::ifstream file(pShaderPath); file.is_open())
		{
			size_t fileSize = std::filesystem::file_size(pShaderPath);
			std::vector<char> contents(fileSize);
			file.read(contents.data(), fileSize);

			auto len	= static_cast<GLint>(fileSize);
			auto pData	= static_cast<const GLchar*>(contents.data());
			
			glShaderSource(id, 1, &pData, &len);
			glCompileShader(id);
		}

		return id;
	}
}
