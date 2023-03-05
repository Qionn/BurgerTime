#ifndef __BT_ENGINE_COMPONENT_H__
#define __BT_ENGINE_COMPONENT_H__

#include "engine/core/common.h"
#include "engine/core/event.h"

namespace bt::engine
{
	class GameObject;

	// Component -----------------------------------------------------------------
	// ===========================================================================

	class Component
	{
		BT_ENGINE_DISALLOW_COPY_AND_MOVE(Component)

	public:
		/**
		 * Constructs a new base component.
		 *
		 * @param pOwner A pointer to the GameObject that owns this Component.
		 */
		Component(GameObject* pOwner);
		virtual ~Component() = default;

		/**
		 * Gets the GameObject that owns this component.
		 *
		 * @return The owner GameObject, or nullptr if this component has no owner.
		 */
		GameObject* GetOwner() const;

		/**
		 * Checks whether this component has an owner.
		 *
		 * @return True if this component has an owner, false otherwise.
		 */
		bool HasOwner() const;

		/**
		 * Updates the component.
		 *
		 * @note This method should be called once per frame.
		 */
		virtual void Update() = 0;

		/**
		 * Fixed update method for physics simulation.
		 */
		virtual void FixedUpdate() = 0;

		/**
		 * Renders the component.
		 */
		virtual void Render() const = 0;

		/**
		 * Processes an event received by the game object.
		 *
		 * @param e The event to process
		 */
		virtual void Process(Event& e) = 0;

	private:
		GameObject* m_pOwner = nullptr;
	};
}

#endif // !__BT_ENGINE_COMPONENT_H__
