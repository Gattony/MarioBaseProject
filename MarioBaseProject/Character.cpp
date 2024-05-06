#include "Character.h"
#include "Texture2D.h"
using namespace std;

char input;

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position)
{
	m_moving_left = false;
	m_moving_right = false;
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer)	;

	m_facing_direction = FACING_RIGHT;

	if (!m_texture->LoadFromFile(imagePath))
	{
		cout << "Failed to load the file from image path" << endl;
	}
}

Character::~Character()
{
	delete m_texture;
	m_texture = nullptr;
}

void Character::Render()
{
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

void Character::MoveLeft(float deltaTime)
{

}

void Character::MoveRight(float deltaTime)
{

}

void Character::Update(float deltaTime, SDL_Event e)
{
	if (m_moving_left)
	{
		MoveLeft(deltaTime);

	}

	else if (m_moving_right)
	{
		MoveRight(deltaTime);
	}

	switch (e.type) 
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		    case SDLK_a:
				m_position.x -= 3;
				m_moving_left = true;
				break;
			case SDLK_d:
				m_position.x += 3;
				m_moving_right = true;
				break;
			default:
				break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		     case SDLK_a:
				 m_position.x -= 3;
				 m_moving_right = false;
				 break;
			 case SDLK_d:
				 m_position.x += 3;
				 m_moving_left = false;
				 break;
			 default:
				 break;
		}
	}
}

void Character::SetPosition(Vector2D new_position)
{
	m_position = new_position;
}

Vector2D Character::GetPosition()
{
	return m_position;
}