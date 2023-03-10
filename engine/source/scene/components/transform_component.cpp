#include "stdafx.h"

#include "engine/scene/components/transform_component.h"

namespace bt::engine
{
	TransformComponent::TransformComponent(GameObject* pOwner)
		: Component(pOwner)
		, m_Position{ 0.0f }
		, m_Rotation{ 0.0f }
		, m_Scale{ 1.0f }
		, m_WorldMatrixCache{ glm::mat4(1.0f) }
	{

	}

	const glm::vec3& TransformComponent::GetPosition() const
	{
		return m_Position;
	}

	const glm::vec3& TransformComponent::GetRotation() const
	{
		return m_Rotation;
	}

	const glm::vec3& TransformComponent::GetScale() const
	{
		return m_Scale;
	}

	void TransformComponent::SetPosition(const glm::vec3& position)
	{
		m_Position = position;
		m_WorldMatrixCache.SetDirty();
	}

	void TransformComponent::SetRotation(const glm::vec3& rotation)
	{
		m_Rotation = rotation;
		m_WorldMatrixCache.SetDirty();
	}

	void TransformComponent::SetScale(const glm::vec3& scale)
	{
		m_Scale = scale;
		m_WorldMatrixCache.SetDirty();
	}

	const glm::mat4& TransformComponent::GetWorldMatrix() const
	{
		m_WorldMatrixCache.WhenDirty([this](glm::mat4& value) {
			value = glm::mat4(1.0f);
			value = glm::translate(value, m_Position);
			value = glm::rotate(value, m_Rotation.x, { 1.0f, 0.0f, 0.0f });
			value = glm::rotate(value, m_Rotation.y, { 0.0f, 1.0f, 0.0f });
			value = glm::rotate(value, m_Rotation.z, { 0.0f, 0.0f, 1.0f });
			value = glm::scale(value, m_Scale);
		});

		return *m_WorldMatrixCache;
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
