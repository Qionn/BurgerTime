#include "stdafx.h"

#include "engine/scene/components/transform_component.h"

namespace bt::engine
{
	TransformComponent::TransformComponent(GameObject* pOwner)
		: Component(pOwner)
		, m_Position{ 0.0f }
		, m_Scale{ 1.0f }
	{

	}

	const glm::vec2& TransformComponent::GetPosition() const
	{
		return m_Position;
	}

	void TransformComponent::SetPosition(const glm::vec2& position)
	{
		m_Position = position;
	}

	const glm::vec2& TransformComponent::GetScale() const
	{
		return m_Scale;
	}

	void TransformComponent::SetScale(const glm::vec2& scale)
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
