#ifndef __BT_ENGINE_TRANSFORM_COMPONENT_H__
#define __BT_ENGINE_TRANSFORM_COMPONENT_H__

#include "engine/scene/component.h"
#include "engine/utils/dirty_cache.h"

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace bt::engine
{
	// TransformComponent --------------------------------------------------------
	// ===========================================================================

	class TransformComponent final : public Component
	{
	public:
		TransformComponent(GameObject* pOwner);
		~TransformComponent() = default;

		const glm::vec3& GetPosition() const;
		const glm::vec3& GetRotation() const;
		const glm::vec3& GetScale() const;

		void SetPosition(const glm::vec3& position);
		void SetRotation(const glm::vec3& rotation);
		void SetScale(const glm::vec3& scale);

		const glm::mat4& GetWorldMatrix() const;

	private:
		void Update() override;
		void FixedUpdate() override;
		void Render() const override;
		void Process(Event& e) override;

		glm::vec3 m_Position;
		glm::vec3 m_Rotation;
		glm::vec3 m_Scale;

		mutable DirtyCache<glm::mat4> m_WorldMatrixCache;
	};
}

#endif // !__BT_ENGINE_TRANSFORM_COMPONENT_H__
