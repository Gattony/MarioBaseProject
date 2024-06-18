#include "Meteor.h"
#include "LevelMap.h"
#include "constants.h"
#include "Character.h"

using namespace std;

Meteor::Meteor(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position) : Character(renderer, imagePath, start_position, map)
{
	m_position = start_position;
}

void Meteor::Render()
{
	//Rendering the meteor
	m_texture->Render(m_position, SDL_FLIP_NONE);
	
}

void Meteor::Update(float deltaTime, SDL_Event e)
{
    Character::Update(deltaTime, e);

    if (m_current_level_map == nullptr)
    {
        cout << "Error: LevelMap is null!" << endl;
        return;
    }

    int centralX_position = (int)(m_position.x + m_texture->GetWidth() * 0.5) / TILE_WIDTH;
    int foot_position = (int)(m_position.y + m_texture->GetHeight()) / TILE_HEIGHT;

    if (m_current_level_map->GetTileAt(foot_position, centralX_position) == 1)
    {
        m_alive = false; // Mark as dead
    }
    else
    {
        AddGravity(deltaTime);
    }
}
