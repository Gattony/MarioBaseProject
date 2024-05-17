#include "GamescreenLevel1.h"
#include <iostream>
#include "Texture2D.h"
#include "Character.h"
#include "Collisions.h"
#include "Powblock.h"

using namespace std;

GamescreenLevel1::GamescreenLevel1(SDL_Renderer* renderer):Gamescreen(renderer)
{
	SetUpLevel();
}

GamescreenLevel1::~GamescreenLevel1()
{
	delete m_background_texture;
	m_background_texture = nullptr;
	delete m_mario;
	m_mario = nullptr;
	delete m_luigi;
	m_luigi = nullptr;
	delete m_level_map;
	m_level_map = nullptr;
	delete m_pow_block;
	m_pow_block = nullptr;

	for (int i = 0; i < m_enemies.size(); i++)
	{
		delete m_enemies[i];
	}

	m_enemies.clear();
}

void GamescreenLevel1::Render()
{
	//draw the enemies
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->Render();
	}

	//draw the background
	m_background_texture->Render(Vector2D(0, m_background_yPos), SDL_FLIP_NONE);
	m_mario->Render();
	m_luigi->Render();
	m_pow_block->Render();
	//__debugbreak();
}

bool GamescreenLevel1::SetUpLevel()
{
	SetLevelMap();

	//load texture
	m_background_texture = new Texture2D(m_renderer);

	//set up characters

	m_luigi = new CharacterLuigi(m_renderer, "Images/Luigi.png", Vector2D(64, 100), m_level_map);
	m_mario = new CharacterMario(m_renderer, "Images/Mario.png", Vector2D(100, 100), m_level_map);
	CreateKoopa(Vector2D(150, 32), FACING_RIGHT, KOOPA_SPEED);
	CreateKoopa(Vector2D(325, 32), FACING_LEFT, KOOPA_SPEED);
	//set up powblocks

	m_pow_block = new PowBlock(m_renderer, m_level_map);
	m_screenshake = false;
	m_background_yPos = 0.0f;

	if (!m_background_texture->LoadFromFile("Images/BackgroundMB.png"))
	{
		cout << "Failed to load the background texture" << endl;
		return false;
	}

	return true;
}

void GamescreenLevel1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
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

	KoopaSpawn(deltaTime, e);
	UpdateEnemies(deltaTime, e);
	UpdatePOWBlock();

	//end shake after duration
	if (m_shake_time <= 0.0f)
	{
		m_screenshake = false;
		m_shake_time = false;
		m_background_yPos = 0.0f;
	}

	if (m_screenshake)
	{
		m_shake_time -= deltaTime;
		m_wobble++;
		m_background_yPos = sin(m_wobble);
		m_background_yPos *= 3.0f;
	}
}

void GamescreenLevel1::UpdatePOWBlock()
{
	if (Collisions::Instance()->Box(m_mario->GetCollisionBox(), m_pow_block->GetCollisionBox()))
	{
		if (m_pow_block->IsAvailable())
		{
			if (m_mario->IsJumping())
			{
				DoScreenShake();
				m_pow_block->TakeHit();
				m_mario->CancelJump();
			}
		}
	}

	if (Collisions::Instance()->Box(m_luigi->GetCollisionBox(), m_pow_block->GetCollisionBox()))
	{
		if (m_pow_block->IsAvailable())
		{
			if (m_luigi->IsJumping())
			{
				DoScreenShake();
				m_pow_block->TakeHit();
				m_luigi->CancelJump();
			}
		}
	}
}

void GamescreenLevel1::UpdateEnemies(float deltaTime, SDL_Event e)
{
	if (!m_enemies.empty())
	{
		int enemyIndexToDelete = -1;
		for (unsigned int i = 0; i < m_enemies.size(); i++)
		{
			//check if the enemy is on the bottom row of tiles
			if (m_enemies[i]->GetPosition().y > 300.0f)
			{
				//is the enemy off screen to the left / right?
				if (m_enemies[i]->GetPosition().x < (float)(-m_enemies[i]->GetCollisionBox().width * 0.5f) || 
					m_enemies[i]->GetPosition().x > SCREEN_WIDTH - (float)(m_enemies[i]->GetCollisionBox().width * 0.55f))
					m_enemies[i]->SetAlive(false);
			}
			else 
			{
				m_enemies[i]->CheckBoundaries();
			}

			//now do the update
			m_enemies[i]->Update(deltaTime, e);

			//check to see if enemy collides with player
			if ((m_enemies[i]->GetPosition().y > 300.0f || m_enemies[i]->GetPosition().y <= 64.0f) && 
				(m_enemies[i]->GetPosition().x < 64.0f || m_enemies[i]->GetPosition().x > SCREEN_WIDTH - 96.0f))
			{
				//ignore collisions if behind pipe
			}
			else
			{
				if (Collisions::Instance()->Circle(m_enemies[i], m_mario))
				{
					if (m_enemies[i]->GetInjured())
					{
						m_enemies[i]->SetAlive(false);
					}
					else
					{
						//kill mario
						m_mario->SetAlive(false);
					}
				}

				if (Collisions::Instance()->Circle(m_enemies[i], m_luigi))
				{
					if (m_enemies[i]->GetInjured())
					{
						m_enemies[i]->SetAlive(false);
					}
					else
					{
						//kill luigi
						m_luigi->SetAlive(false);
					}
				}
			}

			//if the enemy is no longer alive then schedule it for deletion
			if (!m_enemies[i]->GetAlive())
			{
				enemyIndexToDelete = i;
			}
		}

		//remove dead enemies -1 each update
		if (enemyIndexToDelete != -1)
		{
			m_enemies.erase(m_enemies.begin() + enemyIndexToDelete);
		}
	}

}

void GamescreenLevel1::DoScreenShake()
{
	m_screenshake = true;
	m_shake_time = SHAKE_DURATION;
	m_wobble = 0.0f;
	for (auto& enenmy : m_enemies)
	{
		enenmy->TakeDamage();
	}
}

void GamescreenLevel1::CreateKoopa(Vector2D position, FACING direction, float speed)
{
	m_koopa = new CharacterKoopa(m_renderer, "Images/Koopa.png", m_level_map, position, direction, speed);

		// Add the koopa to the enemies vector
		m_enemies.push_back(m_koopa);
}

void GamescreenLevel1::KoopaSpawn(float deltaTime, SDL_Event e)
{
	koopa_timer -= deltaTime;
	if (koopa_timer <= 0)
	{
		CreateKoopa(Vector2D(150, 30), FACING_RIGHT, KOOPA_SPEED);
		koopa_timer = 5.0f;
		cout << "spawn" << endl;
	}
}