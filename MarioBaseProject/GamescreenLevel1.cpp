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
	delete m_background_texture;
	m_background_texture = nullptr;
	delete my_character;
	my_character = nullptr;
}

void GamescreenLevel1::Render()
{
	//draw the background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	my_character->Render();
}

bool GamescreenLevel1::SetUpLevel() 
{
	{
		//load texture
		m_background_texture = new Texture2D(m_renderer);

		//set up player character
		my_character = new Character(m_renderer, "Images/Mario.png", Vector2D(64, 330));

		if (!m_background_texture->LoadFromFile("Images/test.bmp"))
		{
			cout << "Failed to load the background texture" << endl;
			return false;
		}
	}
}

void GamescreenLevel1::Update(float deltaTime, SDL_Event e)
{
	//update character
	my_character->Update(deltaTime, e);
}