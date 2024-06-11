#include "GamescreenIntro.h"
#include "Texture2D.h"
#include <iostream>

GamescreenIntro::GamescreenIntro(SDL_Renderer* renderer) : Gamescreen(renderer)
{
	SetUpLevel();
}

GamescreenIntro::~GamescreenIntro()
{
	delete m_background_texture;
	m_background_texture = nullptr;
}

bool GamescreenIntro::SetUpLevel()
{
	titleText = new TextRenderer(50);

	//load texture
	m_background_texture = new Texture2D(m_renderer);

	if (!m_background_texture->LoadFromFile("Images/Titlescreen.png"))
	{
		cout << "Failed to load the background texture" << endl;
		return false;
	}

	return true;
}

void GamescreenIntro::Render()
{
	//draw the background
	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	titleText->Render(m_renderer, "MARIO GAME!", SCREEN_WIDTH / 4 - 50, SCREEN_HEIGHT / 4);
}

void GamescreenIntro::Update(float deltaTime, SDL_Event e)
{

}