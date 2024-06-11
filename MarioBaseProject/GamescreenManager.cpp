#include "GamescreenManager.h"
#include "Gamescreen.h"
#include "GamescreenIntro.h"
#include "GamescreenLevel1.h"
#include "GamescreenLevel2.h"
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
	GamescreenIntro* tempScreen;
	GamescreenLevel1* tempScreen1;
	GamescreenLevel2* tempScreen2;

	switch (new_screen)
	{
	case SCREEN_INTRO:
		tempScreen = new GamescreenIntro(m_renderer);
		m_current_screen = (Gamescreen*)tempScreen;
		tempScreen = nullptr;
		break;
	case SCREEN_LEVEL1:
		tempScreen1 = new GamescreenLevel1(m_renderer);
		m_current_screen = (Gamescreen*)tempScreen1;
		tempScreen1 = nullptr;
		break;
	case SCREEN_LEVEL2:
		tempScreen2 = new GamescreenLevel2(m_renderer);
		m_current_screen = (Gamescreen*)tempScreen2;
		tempScreen2 = nullptr;
		break;
	default:;
		cout << "Invalid screen type";
		break;
	}
}

void GamescreenManager::Update(float deltaTime, SDL_Event e)
{
	m_current_screen->Update(deltaTime, e);
}