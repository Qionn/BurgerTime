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
		/**
		 * Constructs a transform component.
		 *
		 * @param pOwner A pointer to the GameObject that owns this TransformComponent.
		 */
		TransformComponent(GameObject* pOwner);
		~TransformComponent() = default;

		/**
		 * Returns the local position.
		 *
		 * @returns The local position as a 3D vector
		 */
		const glm::vec3& GetPosition() const;

		/**
		 * Sets the local position.
		 */
		void SetPosition(const glm::vec3& position);

		/**
		 * Returns the local rotation.
		 *
		 * @returns The local rotation as a 3D vector
		 */
		const glm::vec3& GetRotation() const;

		/**
		 * Sets the local rotation.
		 */
		void SetRotation(const glm::vec3& rotation);

		/**
		 * Returns the local scale.
		 *
		 * @returns The local scale as a 3D vector
		 */
		const glm::vec3& GetScale() const;

		/**
		 * Sets the local scale.
		 */
		void SetScale(const glm::vec3& scale);

		/**
		 * Returns the model matrix of this object.
		 *
		 * @returns The model matrix of this object as a 4x4 matrix.
		 */
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
