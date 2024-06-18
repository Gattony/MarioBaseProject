#pragma once
#ifndef _METEOR_H
#define _METEOR_H

#include "LevelMap.h"
#include "Character.h"
using namespace std;

class Meteor :public Character
{
public:
	Meteor(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position);
	~Meteor(){}

private:
	bool m_dead;
	float m_single_sprite_w;
	float m_single_sprite_h;
	float m_movement_speed;
	LevelMap* m_current_level_map;

public:

	void Render();
	void Update(float deltaTime, SDL_Event e)override;
};

#endif //_METEOR_H