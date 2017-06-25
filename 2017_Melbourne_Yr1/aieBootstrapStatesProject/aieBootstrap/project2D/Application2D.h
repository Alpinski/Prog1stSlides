#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "StateMachine.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();
	//--------------------------------------------------
	//runs all the functions inside and creates the player, rock,etc
	//Parameters:
	//Returns:
	//--------------------------------------------------
	virtual bool startup();
	//--------------------------------------------------
	//Deletes everything that was created by the startup function
	//Parameters:
	//Returns:
	//--------------------------------------------------
	virtual void shutdown();
	//--------------------------------------------------
	//Updates player and rock in accordance with delta time
	//Parameters:
	//			takes in a float
	//Returns:
	//--------------------------------------------------
	virtual void update(float deltaTime);
	//--------------------------------------------------
	//main draw function draws everything, starts the renderer and ends it.
	//Parameters:
	//Returns:
	//--------------------------------------------------
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	StateMachine*		m_StateMachine;

	float m_cameraX, m_cameraY;
	float m_timer;
};