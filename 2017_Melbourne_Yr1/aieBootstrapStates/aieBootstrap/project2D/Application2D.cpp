#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "LoadState.h"
#include "GameState.h"
#include "MenuState.h"
#include "SplashState.h"
#include "PauseState.h"
#include <crtdbg.h>
using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();
	_ASSERT(m_2dRenderer);

	ResourceManager<Font>::Create();

	m_shipTexture = new Texture("./textures/ship.png");
	_ASSERT(m_shipTexture);

	m_font = new Font("./font/consolas.ttf", 32);
	_ASSERT(m_font);

	m_audio = new Audio("./audio/powerup.wav");
	_ASSERT(m_audio);

	m_StateMachine = new StateMachine();
	_ASSERT(m_StateMachine);

	m_StateMachine->AddState(0, new MenuState());
	_ASSERT(m_StateMachine);
	m_StateMachine->AddState(1, new SplashState());
	_ASSERT(m_StateMachine);
	m_StateMachine->AddState(2, new GameState());
	_ASSERT(m_StateMachine);
	m_StateMachine->AddState(3, new LoadState());
	_ASSERT(m_StateMachine);
	m_StateMachine->AddState(4, new PauseState());
	_ASSERT(m_StateMachine);

	m_StateMachine->PushState(1);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete m_StateMachine;
	delete m_audio;
	delete m_font;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	m_StateMachine->Update(deltaTime);

	// input example
	Input* input = Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	// example of audio
	if (input->wasKeyPressed(INPUT_KEY_SPACE))
		m_audio->play();

	// exit the application
	//if (input->isKeyDown(INPUT_KEY_ESCAPE))
	//	quit();
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_StateMachine->Draw(m_2dRenderer);

	//// demonstrate spinning sprite
	//m_2dRenderer->setUVRect(0,0,1,1);
	//m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	//// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 500, 400, 2, 1);

	//// draw a moving purple circle
	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	//// draw a rotating red box
	//m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	//// draw a slightly rotated sprite with no texture, coloured yellow
	//m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
	
	// output some text, uses the last used colour
	//char fps[32];
	//sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}