#include "stdafx.h"

#include "engine/scene/game_object.h"
#include "engine/scene/components/sprite_component.h"
#include "engine/utils/vault.h"

#include "engine/core/time.h"

#pragma warning(disable:4201)
#include <glm/ext.hpp>
#pragma warning(default:4201)

namespace bt::engine
{
	SpriteComponent::SpriteComponent(GameObject* pOwner)
		: Component(pOwner)
	{
		m_pTransform = GetOwner()->GetComponent<TransformComponent>();

		m_pMesh = Vault::GetMesh("sprite_component_mesh");
		if (m_pMesh == nullptr)
		{
			m_pMesh = Vault::SaveMesh(
				{/*        position         texcoord   */
					{ {-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f} },
					{ {0.5f, -0.5f, 0.0f}, {1.0f, 0.0f} },
					{ {0.5f, 0.5f, 0.0f}, {1.0f, 1.0f} },

					{ { -0.5f, -0.5f, 0.0f }, {0.0f, 0.0f} },
					{ {0.5f, 0.5f, 0.0f}, {1.0f, 1.0f} },
					{ {-0.5f, 0.5f, 0.0f}, {0.0f, 1.0f} }

				},
				"default_mesh_sprite"
			);
		}

		m_pProgram = Vault::GetProgram("sprite_component_program");
		if (m_pProgram == nullptr)
		{
			m_pProgram = Vault::LoadProgram("data/shaders/sprite.vs.glsl",
											"data/shaders/sprite.fs.glsl",
											"sprite_component_program");
		}

		// ====== Temporary =======
		m_pProgram->Bind();
		auto projection = glm::ortho(0.0f, 640.0f, 360.0f, 0.0f, -1.0f, 1.0f);
		m_pProgram->SetUniform("uProjection", projection);
		m_pProgram->SetUniform("uColor", glm::vec3(1.0f, 1.0f, 0.0f));
		m_pProgram->Unbind();
		// ========================
	}

	void SpriteComponent::Update()
	{
		// Empty
	}

	void SpriteComponent::FixedUpdate()
	{
		// Empty
	}

	void SpriteComponent::Render() const
	{
		m_pProgram->Bind();
		m_pProgram->SetUniform("uModel", m_pTransform->GetModelMatrix());
		m_pMesh->Draw();
		m_pProgram->Unbind();
	}

	void SpriteComponent::Process(Event&)
	{
		// Empty
	}
}
