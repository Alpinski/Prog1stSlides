#include "Entity.h"
#include "Font.h"
Entity::Entity()
{
	m_bActive = false;
}

Entity::~Entity()
{
}

void Entity::UpdateTransforms(float fDeltatime)
{
}

void Entity::Draw(Renderer2D * m_2dRenderer)
{
}

void Entity::SetActive(bool bActive)
{
	m_bActive = bActive;
}

bool Entity::GetActive()
{
	return m_bActive;
}
