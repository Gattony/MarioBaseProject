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

void GamescreenIntro::SetUpLevel()
{
	//load texture
	m_background_texture = new Texture2D(m_renderer);
}

void GamescreenIntro::Render()
{
	//draw the background
	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void GamescreenIntro::Update(float deltaTime, SDL_Event e)
{

}