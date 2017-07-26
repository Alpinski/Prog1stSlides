#pragma once
#include "Renderer2D.h"
#include "Vector2.h"
using namespace aie;

class Agent
{
public:
	Agent() {};
	virtual ~Agent() {};

	virtual void Update(float fDeltaTime) = 0;
	virtual void Draw(Renderer2D* pRenderer) = 0;

	Vector2 GetPosition() { return m_v2Pos; }
	void SetPosition(Vector2 v2Pos) { m_v2Pos = v2Pos; }

protected:
	Vector2 m_v2Pos;

};