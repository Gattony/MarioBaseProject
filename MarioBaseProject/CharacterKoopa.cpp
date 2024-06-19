#include "constants.h"
#include "CharacterKoopa.h"
#include "Character.h"

using namespace std;

CharacterKoopa::CharacterKoopa(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed) : Character(renderer, imagePath, start_position, map)
{
	m_facing_direction = start_facing;
	m_movement_speed = movement_speed;
	m_position = start_position;
	m_injured = false;

	m_single_sprite_w = m_texture->GetWidth() / 2;
	m_single_sprite_h = m_texture->GetHeight();
}

void CharacterKoopa::TakeDamage()
{
	m_injured = true;
	m_injured_time = INJURED_TIME;
}

void CharacterKoopa::Jump()
{
	if (!m_jumping)
	{
		m_jump_force = INITIAL_JUMP_FORCE_SMALL;
		m_jumping = true;
		m_can_jump = false;
	}
}

void CharacterKoopa::FlipRightwayUp()
{
	m_facing_direction = (m_facing_direction == FACING_LEFT) ? FACING_RIGHT : FACING_LEFT;
	m_injured = false;
}

void CharacterKoopa::Render()
{
	//Variable to hold left position of sprite
	int left = 0.0f;

	//If injured move the left postion to be the left position of the second image of the sprite sheet
	if (m_injured)
		left = m_single_sprite_w;

	//Get the portion of the sprite sheet
	// 
	//{xPos, yPos, width of sprite, height of sprite)
	SDL_Rect portion_of_sprite = { left,0, m_single_sprite_w, m_single_sprite_h };

	//Determine the position of the sprite drawing
	SDL_Rect destRect = { (int)(m_position.x), (int)(m_position.y), m_single_sprite_w, m_single_sprite_h };

	//Draw it facing the correct direction
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(portion_of_sprite, destRect, SDL_FLIP_HORIZONTAL);
	}
}

void CharacterKoopa::Update(float deltaTime, SDL_Event e)
{
	if (!m_injured)
	{
		//Enemy is not injured so move
		if (m_facing_direction == FACING_LEFT)
		{
			m_moving_left = true;
			m_moving_right = false;
		}
		else if (m_facing_direction == FACING_RIGHT)
		{
			m_moving_right = true;
			m_moving_left = false;
		}
	}
	else {
		m_moving_right = false;
		m_moving_left = false;

		m_injured_time -= deltaTime;
		if (m_injured_time <= 0) {
			m_injured = false;
		}
	}

	Character::Update(deltaTime, e);
}

void CharacterKoopa::CheckBoundaries() 
{
	if (m_position.x <= 0 && m_facing_direction == FACING_LEFT) 
	{
		m_facing_direction = FACING_RIGHT;
	}
	else if (m_position.x + m_single_sprite_w >= SCREEN_WIDTH && m_facing_direction == FACING_RIGHT) 
	{
		m_facing_direction = FACING_LEFT;
	}
}
