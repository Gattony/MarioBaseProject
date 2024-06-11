#include "GamescreenLevel2.h"


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
}

bool GamescreenLevel2::SetUpLevel()
{
	SetLevelMap();

	//load texture
	m_background_texture = new Texture2D(m_renderer);

	m_background_yPos = 0.0f;

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

	//__debugbreak();
}

void GamescreenLevel2::Update(float deltaTime, SDL_Event e)
{

}

>>>>>>> parent of 6aefcb9 (bingus)
