#include "SpaceCharacter.h"
#include "Texture2D.h"
#include "LevelMap.h"
#include "constants.h"

using namespace std;


SpaceCharacter::SpaceCharacter(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map) :Character(renderer, imagePath, start_position, map)
{
	m_alive = true;
	m_moving_left = false;
	m_moving_right = false;
	m_renderer = renderer;
	m_position = start_position;
	m_current_level_map = map;
	m_texture = new Texture2D(m_renderer);

	m_facing_direction = FACING_RIGHT;

	m_collision_radius = 15.0f;

	if (!m_texture->LoadFromFile(imagePath))
	{
		cout << "Failed to load the file from image path" << endl;
	}
}

SpaceCharacter::~SpaceCharacter()
{
	delete m_texture;
	m_texture = nullptr;
}

void SpaceCharacter::Render()
{
	//Deleting the sprite if death
	if (!m_alive) return;

	m_texture->Render(m_position, SDL_FLIP_NONE);

	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}

	else
	{
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}

}

void SpaceCharacter::AddGravity(float deltaTime)
{
	if (m_position.y + 64 <= SCREEN_HEIGHT)
	{
		m_position.y += GRAVITY/1.7 * deltaTime;
	}
	else
	{
		m_can_jump = true;
	}
}

void SpaceCharacter::Jump()
{
	if (m_can_jump && !m_jumping)
	{
		//JUMP
		m_jump_force = INITIAL_JUMP_FORCE*1.5;
		m_jumping = true;
		m_can_jump = false;
	}
}

void SpaceCharacter::MoveLeft(float deltaTime)
{
	m_facing_direction = FACING_LEFT;
	m_position.x -= deltaTime * MOVEMENTSPEED;
}

void SpaceCharacter::MoveRight(float deltaTime)
{
	m_facing_direction = FACING_RIGHT;
	m_position.x += deltaTime * MOVEMENTSPEED;
}


void SpaceCharacter::Update(float deltaTime, SDL_Event e)
{
	//Deleting the updates if death
	if (!m_alive) return;

	//deal with jumping first
	if (m_jumping)
	{
		//adjust position
		m_position.y -= m_jump_force * deltaTime;

		//reduce jump force
		m_jump_force -= JUMP_FORCE_DECREMENT*1.5 * deltaTime;


		//is jump force 0?
		if (m_jump_force <= 0.0f)
			m_jumping = false;
	}
	else
	{
		//colisions position variables
		int centralX_position = (int)(m_position.x + (m_texture->GetWidth() * 0.5)) / TILE_WIDTH;
		int foot_position = (int)(m_position.y + m_texture->GetHeight()) / TILE_HEIGHT;

		//deal with gravity
		if (m_current_level_map->GetTileAt(foot_position, centralX_position) == 0)
		{
			AddGravity(deltaTime);
		}
		else
		{
			//collided with ground so we can jump again
			m_can_jump = true;
		}
	}

	if (m_moving_left)
	{
		MoveLeft(deltaTime);
	}
	else if (m_moving_right)
	{
		MoveRight(deltaTime);
	}
}


float SpaceCharacter::GetCollisionRadius()
{
	return m_collision_radius;
}

void SpaceCharacter::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

Vector2D SpaceCharacter::GetPosition()
{
	return m_position;
}

