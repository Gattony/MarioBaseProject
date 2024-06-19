#include "GamescreenLevel2.h"
#include "SpaceCharacter.h"
#include "Collisions.h"

using namespace std;

GamescreenLevel2::GamescreenLevel2(SDL_Renderer* renderer) :Gamescreen(renderer)
{
	SetUpLevel();
}

GamescreenLevel2::~GamescreenLevel2()
{
	delete m_background_texture;
	m_background_texture = nullptr;
	delete m_level_map;
	m_level_map = nullptr;
	delete m_space_mario;
	m_space_mario = nullptr;

}

bool GamescreenLevel2::SetUpLevel()
{
	SetLevelMap();

	//load texture
	m_background_texture = new Texture2D(m_renderer);

	//Rendering entities
	m_space_mario = new CharacterSpaceMario(m_renderer, "Images/SpaceMario.png", Vector2D(50, 330), m_level_map);
	m_background_yPos = 0.0f;
	CreateMeteor(Vector2D(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.05));
	CreateMeteor(Vector2D(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.05));
#
	if (!m_background_texture->LoadFromFile("Images/Space.png"))
	{
		cout << "Failed to load the background texture" << endl;
		return false;
	}

	return true;
}

void GamescreenLevel2::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] ={ { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
								      { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
								      { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
								      { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
								      { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
								      { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
								      { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
								      { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
								      { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
								      { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
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

void GamescreenLevel2::Render()
{
	m_background_texture->Render(Vector2D(0, m_background_yPos), SDL_FLIP_NONE);

	m_space_mario->Render();

	for (int i = 0; i < m_meteors.size(); i++)
	{
		m_meteors[i]->Render();
	}

}

void GamescreenLevel2::UpdateMeteors(float deltaTime, SDL_Event e)
{

}

void GamescreenLevel2::CreateMeteor(Vector2D position)
{
	m_meteor = new Meteor(m_renderer, "Images/Meteor.png", m_level_map, position);

	m_meteors.push_back(m_meteor);
}

void GamescreenLevel2::Update(float deltaTime, SDL_Event e)
{
	//Updating characters
	m_space_mario->Update(deltaTime, e);

	MeteorSpawn(deltaTime, e);

	for (int i = 0; i < m_meteors.size(); i++)
	{
		m_meteors[i]->Update(deltaTime, e);

		if (m_meteors[i]->IsToBeDeleted()) {
			delete m_meteors[i]; // Free memory
			m_meteors.erase(m_meteors.begin() + i); // Remove from vector and advance iterator
		}

		if (Collisions::Instance()->Circle(m_meteors[i], m_space_mario))
		{
			if (m_meteors[i]->GetInjured())
			{
				m_meteors[i]->SetAlive(false);
			}
			else
			{
				//kill mario
				m_space_mario->SetAlive(false);
			}
		}
	}
}

void GamescreenLevel2::MeteorSpawn(float deltaTime, SDL_Event e)
{
	meteor_time -= deltaTime;
	if (meteor_time <= 0)
	{
		// Generate random coordinates within a range
		int randomX = rand() % SCREEN_WIDTH;
		int randomY = rand() % (SCREEN_HEIGHT / 3);

		CreateMeteor(Vector2D(randomX, randomY));
		CreateMeteor(Vector2D(randomX, randomY));

		meteor_time = 0.5f;
	}
}

