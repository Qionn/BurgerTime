#include "stdafx.h"

#include "engine/scene/components/mesh_renderer_component.h"

namespace bt::engine
{
	MeshRendererComponent::MeshRendererComponent(GameObject* pOwner, Mesh* pMesh, Material* pMaterial)
		: Component(pOwner)
		, m_pMesh{ pMesh }
		, m_pMaterial{ pMaterial }
	{

	}

	void MeshRendererComponent::SetMesh(Mesh* pMesh)
	{
		m_pMesh = pMesh;
	}

	void MeshRendererComponent::SetMaterial(Material* pMaterial)
	{
		m_pMaterial = pMaterial;
	}

	Mesh* MeshRendererComponent::GetMesh() const
	{
		return m_pMesh;
	}

	Material* MeshRendererComponent::GetMaterial() const
	{
		return m_pMaterial;
	}

	void MeshRendererComponent::Update()
	{
		// Empty
	}

	void MeshRendererComponent::FixedUpdate()
	{
		// Empty
	}

	void MeshRendererComponent::Render() const
	{
		m_pMaterial->Bind();
		m_pMesh->Draw();
		m_pMaterial->Unbind();
	}

	void MeshRendererComponent::Process(Event&)
	{
		// Empty
	}
}
