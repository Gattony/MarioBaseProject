#pragma once
#ifndef _CHARACTERMARIO_H
#define _CHARACTERMARIO_H
using namespace std;

#include "Character.h"

class CharacterMario: public Character
{   
    public:
	CharacterMario(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~CharacterMario();
};

#endif // _CHARACTERMARIO_H