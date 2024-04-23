#include "GamescreenLevel1.h"
#include <iostream>
#include "Texture2D.h"
using namespace std;

GamescreenLevel1::GamescreenLevel1(SDL_Renderer* renderer):Gamescreen(renderer)
{

}

GamescreenLevel1::~GamescreenLevel1()
{

}

void GamescreenLevel1::Render()
{
	//draw the background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
}

void GamescreenLevel1::Update(float deltaTime, SDL_Event e)
{

}