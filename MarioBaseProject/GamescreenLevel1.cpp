#include "GamescreenLevel1.h"
#include <iostream>
#include "Texture2D.h"
#include "Character.h"
#include "Collisions.h"

using namespace std;

GamescreenLevel1::GamescreenLevel1(SDL_Renderer* renderer):Gamescreen(renderer)
{
	SetUpLevel();
	LevelMap* m_level_map = nullptr;
}

GamescreenLevel1::~GamescreenLevel1()
{
	delete m_background_texture;
	m_background_texture = nullptr;
	delete m_mario;
	m_mario = nullptr;
	delete m_luigi;
	m_luigi = nullptr;
}

void GamescreenLevel1::Render()
{
	//draw the background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	m_mario->Render();
	m_luigi->Render();
}

bool GamescreenLevel1::SetUpLevel() 
{
	{
		//load texture
		m_background_texture = new Texture2D(m_renderer);

		//set up player character
		
		m_luigi = new CharacterLuigi(m_renderer, "Images/Luigi.png", Vector2D(64, 330), m_level_map);
		m_mario = new CharacterMario(m_renderer, "Images/Mario.png", Vector2D(100, 330),m_level_map);

		return true;

		if (!m_background_texture->LoadFromFile("Images/test.bmp"))
		{
			cout << "Failed to load the background texture" << endl;
			return false;
		}
	}
}

void GamescreenLevel1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] ={ { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0 },
									  { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },
									  { 1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
									  { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
	//clear any old maps
	if (m_level_map != nullptr)
	{
		delete m_level_map;
	}
	
	//set the new one
	m_level_map = new LevelMap(map);
}

void GamescreenLevel1::Update(float deltaTime, SDL_Event e)
{
	//update character
	m_mario->Update(deltaTime, e);
	m_luigi->Update(deltaTime, e);

	////if (Collisions::Instance()->Circle(m_mario, m_luigi))
	//{
	//	cout << "Cirlce hit!" << endl;
	//}

	if (Collisions::Instance()->Box(m_mario->GetCollisionBox(), m_luigi->GetCollisionBox()))
	{
		cout <<"Box hit!" << endl;
	}
}