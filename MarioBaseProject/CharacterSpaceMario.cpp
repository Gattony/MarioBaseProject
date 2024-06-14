#include "CharacterSpaceMario.h"
#include "SpaceCharacter.h";
#include "LevelMap.h";

CharacterSpaceMario::CharacterSpaceMario(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map):SpaceCharacter(renderer, imagePath, start_position, map)
{

}

CharacterSpaceMario::~CharacterSpaceMario()
{

}

void CharacterSpaceMario::Update(float deltaTime, SDL_Event e)
{
	SpaceCharacter::Update(deltaTime, e);

	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			m_moving_left = true;
			break;
		case SDLK_d:
			m_moving_right = true;
			break;
		case SDLK_w:
			Jump();
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			m_moving_left = false;
			break;
		case SDLK_d:
			m_moving_right = false;
			break;
		default:
			break;
		}
		break;
	}
}
