#pragma once
#include "Entity.h"

using namespace aie;

class MeObject : public Entity
{
public:
	MeObject();
	~MeObject();

	void UpdateTransforms(float fDeltatime);

	void Draw(Renderer2D* m_2dRenderer);

	void SetActive(bool bActive);
	bool GetActive();

private:
	bool		m_bActive;
	float		m_timer;
	Font*		m_font;
};

