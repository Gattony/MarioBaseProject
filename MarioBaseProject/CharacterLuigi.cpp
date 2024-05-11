#include "CharacterLuigi.h"
#include "constants.h"
#include "LevelMap.h"
#include <iostream>

CharacterLuigi::CharacterLuigi(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map) 
	:Character(renderer, imagePath, start_position, map)
{

}

CharacterLuigi::~CharacterLuigi()
{

}

void CharacterLuigi::Update(float deltaTime, SDL_Event e)
{
	Character::Update(deltaTime, e);

	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = true;
			break;
		case SDLK_RIGHT:
			m_moving_right = true;
			break;
		case SDLK_UP:
			Jump();
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_moving_left = false;
			break;
		case SDLK_RIGHT:
			m_moving_right = false;
			break;
		default:
			break;
		}
		break;
	}
}