#include "GamescreenLevel1.h"
#include <iostream>
#include "Texture2D.h"

using namespace std;

GamescreenLevel1::GamescreenLevel1(SDL_Renderer* renderer):Gamescreen(renderer)
{
	SetUpLevel();
}

GamescreenLevel1::~GamescreenLevel1()
{
	m_background_texture = nullptr;
}

void GamescreenLevel1::Render()
{
	//draw the background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
}

bool GamescreenLevel1::SetUpLevel()
{
	{
		//load texture
		m_background_texture = new Texture2D(m_renderer);
		if (!m_background_texture->LoadFromFile("Images/test.bmp"))
		{
			cout << "Failed to load the background texture" << endl;
			return false;
		}
	}
}

void GamescreenLevel1::Update(float deltaTime, SDL_Event e)
{

}