#ifndef __BT_ENGINE_MESH_RENDERER_COMPONENT_H__
#define __BT_ENGINE_MESH_RENDERER_COMPONENT_H__

#include "engine/scene/component.h"
#include "engine/graphics/mesh.h"

namespace bt::engine
{
	// MeshRenderer --------------------------------------------------------------
	// ===========================================================================

	class MeshRendererComponent final : public Component
	{
	public:
		MeshRendererComponent(GameObject* pOwner, Mesh* pMesh);
		~MeshRendererComponent() = default;

		void SetMesh(Mesh* pMesh);
		Mesh* GetMesh() const;

	private:
		void Update() override;
		void FixedUpdate() override;
		void Render() const override;
		void Process(Event& e) override;

		Mesh* m_pMesh;
	};
}

#endif // !__BT_ENGINE_MESH_RENDERER_COMPONENT_H__
