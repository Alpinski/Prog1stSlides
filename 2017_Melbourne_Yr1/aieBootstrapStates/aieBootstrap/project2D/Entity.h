#pragma once
#include "Font.h"

using namespace aie;
class Entity
{
public:
	Entity();
	~Entity();

	void SetActive(bool bActive);
	bool GetActive();

private:
	bool m_bActive;
	Font* m_font;
};

