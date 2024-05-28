#include "Gamescreen.h"
#include <iostream>
#include "SDL_image.h"
using namespace std;

Gamescreen::Gamescreen(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

Gamescreen::~Gamescreen()
{
	m_renderer = nullptr;
}

void Gamescreen::Render()
{

}

void Gamescreen::Update(float deltaTime, SDL_Event e)
{

}

void Gamescreen::SetGameState(GAMESTATE)
{

}

void Gamescreen::SetNextGameState(GAMESTATE)
{

}