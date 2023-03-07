#include "stdafx.h"

#include "engine/graphics/mesh.h"

namespace bt::engine
{
	Mesh::Mesh(const std::vector<Vertex>& vertices)
		: m_VertexCount{ vertices.size() }
	{
		if (vertices.size() % 3 != 0)
		{
			throw std::runtime_error("Invalid mesh: Mesh does not contain triangles!");
		}

		glCreateVertexArrays(1, &m_VAO);
		glCreateBuffers(1, &m_VBO);

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

		glBindVertexArray(m_VAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float) * 3));

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(1, &m_VBO);
		glDeleteVertexArrays(1, &m_VAO);
	}

	void Mesh::Draw() const
	{
		glBindVertexArray(m_VAO);
		glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(m_VertexCount));
		glBindVertexArray(0);
	}
}
