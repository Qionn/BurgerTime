#ifndef __BT_ENGINE_SPRITE_COMPONENT_H__
#define __BT_ENGINE_SPRITE_COMPONENT_H__

#include "engine/graphics/mesh.h"
#include "engine/graphics/program.h"
#include "engine/scene/component.h"
#include "engine/scene/components/transform_component.h"

namespace bt::engine
{
	// SpriteComponent -----------------------------------------------------------
	// ===========================================================================

	class SpriteComponent final : public Component
	{
	public:
		/**
		 * Constructs a sprite component.
		 *
		 * @param pOwner A pointer to the GameObject that owns this SpriteComponent.
		 */
		SpriteComponent(GameObject* pOwner);
		~SpriteComponent() = default;

	private:
		void Update() override;
		void FixedUpdate() override;
		void Render() const override;
		void Process(Event& e) override;

		TransformComponent* m_pTransform;

		Mesh* m_pMesh;
		Program* m_pProgram;
	};
}

#endif // !__BT_ENGINE_SPRITE_COMPONENT_H__
