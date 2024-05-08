#pragma once
#ifndef _CHARACTERMARIO_H
#define _CHARACTERMARIO_H
using namespace std;

#include "Character.h"
#include "LevelMap.h"

class CharacterMario: public Character
{   
    public:
	CharacterMario(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map);
	~CharacterMario();

};

#endif // _CHARACTERMARIO_H