#include "stdafx.h"

#include "engine/utils/vault.h"

#include <fstream>

namespace bt::engine
{
	std::unordered_map<std::string, std::unique_ptr<Program>> Vault::m_Programs;
	std::unordered_map<std::string, std::unique_ptr<Mesh>> Vault::m_Meshes;

	/* static */ Program* Vault::LoadProgram(const std::string& vertexPath,
											 const std::string& fragmentPath,
											 const std::string& tag)
	{
		auto it = m_Programs.find(tag);

		if (it == m_Programs.end())
		{
			std::vector<char> vertexSource = ReadFile(vertexPath);
			std::vector<char> fragmentSource = ReadFile(fragmentPath);

			auto pProgram = new Program(Shader(vertexSource, Shader::Type::Vertex),
										Shader(fragmentSource, Shader::Type::Fragment));

			m_Programs[tag] = std::unique_ptr<Program>(pProgram);

			return pProgram;
		}

		return nullptr;
	}

	/* static */ Program* Vault::GetProgram(const std::string& tag)
	{
		auto it = m_Programs.find(tag);
		if (it == m_Programs.end())
		{
			return nullptr;
		}

		return it->second.get();
	}

	/* static */ Mesh* Vault::SaveMesh(const std::vector<Vertex>& vertices, const std::string& tag)
	{
		auto it = m_Meshes.find(tag);

		if (it == m_Meshes.end())
		{
			auto pMesh = new Mesh(vertices);
			m_Meshes[tag] = std::unique_ptr<Mesh>(pMesh);
			return pMesh;
		}

		return nullptr;
	}

	/* static */ Mesh* Vault::GetMesh(const std::string& tag)
	{
		auto it = m_Meshes.find(tag);
		if (it == m_Meshes.end())
		{
			return nullptr;
		}

		return it->second.get();
	}

	/* static */ std::vector<char> Vault::ReadFile(const std::string& filepath)
	{
		std::ifstream file(filepath, std::ios::ate);
		if (file.is_open())
		{
			std::vector<char> contents(file.tellg());
			file.seekg(std::ios::beg);
			file.read(contents.data(), contents.size());
			return contents;
		}

		throw std::runtime_error("Failed to read file!");
	}
}
