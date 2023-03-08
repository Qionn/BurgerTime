#include "stdafx.h"

#include "engine/scene/components/transform_component.h"

namespace bt::engine
{
	TransformComponent::TransformComponent(GameObject* pOwner)
		: Component(pOwner)
		, m_Position{ 0.0f }
		, m_Rotation{ 0.0f }
		, m_Scale{ 1.0f }
	{

	}

	const glm::vec3& TransformComponent::GetPosition() const
	{
		return m_Position;
	}

	void TransformComponent::SetPosition(const glm::vec3& position)
	{
		m_Position = position;
	}

	const glm::vec3& TransformComponent::GetRotation() const
	{
		return m_Rotation;
	}

	void TransformComponent::SetRotation(const glm::vec3& rotation)
	{
		m_Rotation = rotation;
	}

	const glm::vec3& TransformComponent::GetScale() const
	{
		return m_Scale;
	}

	void TransformComponent::SetScale(const glm::vec3& scale)
	{
		m_Scale = scale;
	}

	void TransformComponent::Update()
	{
		// Empty
	}

	void TransformComponent::FixedUpdate()
	{
		// Empty
	}

	void TransformComponent::Render() const
	{
		// Empty
	}

	void TransformComponent::Process(Event&)
	{
		// Empty
	}
}
