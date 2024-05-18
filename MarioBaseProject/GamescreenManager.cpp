#include "GamescreenManager.h"
#include "Gamescreen.h"
#include "GamescreenLevel1.h"
#include <iostream>

using namespace std;

GamescreenManager::GamescreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{
	m_renderer = renderer;
	m_current_screen = nullptr;
	ChangeScreen(startScreen);
}

GamescreenManager::~GamescreenManager()
{
	m_renderer = nullptr;
	m_current_screen = nullptr;
}

void GamescreenManager::Render()
{
	m_current_screen->Render();
}

void GamescreenManager::ChangeScreen(SCREENS new_screen)
{
	//clear up the old screen
	if (m_current_screen != nullptr)
	{
		delete m_current_screen;
	}
	GamescreenLevel1* tempScreen;

	switch (new_screen)
	{
	case SCREEN_LEVEL1:
		tempScreen = new GamescreenLevel1(m_renderer);
		m_current_screen = (Gamescreen*)tempScreen;
		tempScreen;
	default:;
	}
}

void GamescreenManager::Update(float deltaTime, SDL_Event e)
{
	m_current_screen->Update(deltaTime, e);
}