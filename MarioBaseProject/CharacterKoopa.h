#pragma once
#ifndef _CHARACTERKOOPA_H
#define _CHARACTERKOOPA_H

#include "Character.h"
using namespace std;

class CharacterKoopa:public Character
{
	private:
		float m_single_sprite_w;
		float m_single_sprite_h;
		bool m_injured;;
		float m_injured_time;
		float m_movement_speed;
		FACING m_facing_direction;

		CharacterKoopa(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position, FACING start_facing, float movement_speed);
		~CharacterKoopa();
		void FlipRightwayUp();
	public:
		void GetInjured() { return m_injured; }
		void Render();
		void Update(float deltaTime, SDL_Event e)override;
		void TakeDamage();
		void Jump();
};

#endif //_CHARACTERKOOPA_H