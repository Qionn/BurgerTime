#ifndef __BT_ENGINE_TRANSFORM_COMPONENT_H__
#define __BT_ENGINE_TRANSFORM_COMPONENT_H__

#include "engine/scene/component.h"

#pragma warning(disable:4201)
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext.hpp>
#pragma warning(default:4201)

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
		 * Returns the local position of the GameObject.
		 *
		 * @returns The local position as a 2D vector
		 */
		const glm::vec2& GetPosition() const;

		/**
		 * Sets the local position of the GameObject.
		 */
		void SetPosition(const glm::vec2& position);

		/**
		 * Returns the local scale of the GameObject.
		 *
		 * @returns The local scale as a 2D vector
		 */
		const glm::vec2& GetScale() const;

		/**
		 * Sets the local scale of the GameObject.
		 */
		void SetScale(const glm::vec2& scale);

		/**
		 * Returns the model matrix of the gameObject
		 * 
		 * @returns The model matrix as a Matrix4x4
		 */
		glm::mat4 GetModelMatrix() const;

	private:
		void Update() override;
		void FixedUpdate() override;
		void Render() const override;
		void Process(Event& e) override;

		glm::vec2 m_Position;
		glm::vec2 m_Scale;
	};
}

#endif // !__BT_ENGINE_TRANSFORM_COMPONENT_H__
