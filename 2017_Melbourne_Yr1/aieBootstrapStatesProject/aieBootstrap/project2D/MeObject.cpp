#include "MeObject.h"
#include "ResourceManager.h"
#include "Renderer2D.h"
#include "Font.h"
#include <crtdbg.h>

using namespace aie;

MeObject::MeObject()
{
	m_bActive = false;
	m_timer = 0;
	ResourceManager<Font>* pTextureMan = ResourceManager<Font>::GetInstance();
	m_font = pTextureMan->LoadResource("./font/consolas.ttf", 32);
	_ASSERT(m_font);
}

MeObject::~MeObject()
{
	delete m_font;
}

void MeObject::UpdateTransforms(float fDeltatime)
{
	m_timer += fDeltatime;
	if (m_timer > 7)
	{
		SetActive(false);
		m_timer = 0;
	}
}

void MeObject::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(sin(m_timer) * 500 + 600, 150, 50);
}

void MeObject::SetActive(bool bActive)
{
	m_bActive = bActive;
}

bool MeObject::GetActive()
{
	return m_bActive;
}
