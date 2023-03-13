#include "stdafx.h"

#include "engine/scene/components/mesh_renderer_component.h"

namespace bt::engine
{
	MeshRendererComponent::MeshRendererComponent(GameObject* pOwner, Mesh* pMesh)
		: Component(pOwner)
		, m_pMesh{ pMesh }
	{

	}

	void MeshRendererComponent::SetMesh(Mesh* pMesh)
	{
		m_pMesh = pMesh;
	}

	Mesh* MeshRendererComponent::GetMesh() const
	{
		return m_pMesh;
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
		m_pMesh->Draw();
	}

	void MeshRendererComponent::Process(Event&)
	{
		// Empty
	}
}
