#pragma once
#ifndef _CHARACTERSPACEMARIO_H
#define _CHARACTERSPACEMARIO_H
using namespace std;
#include "SpaceCharacter.h";
#include "LevelMap.h";

class CharacterSpaceMario :public SpaceCharacter
{
	public:
		CharacterSpaceMario(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map);
		~CharacterSpaceMario();

		void Update(float deltaTime, SDL_Event e)override;
};

#endif // !_CHARACTERSPACEMARIO_H