#pragma once
#ifndef _GAMESCREENINTRO_H
#define _GAMESCREENINTRO_H
#include "LevelMap.h"
#include "Gamescreen.h"
#include "Commons.h"
#include <SDL.h>
#include "Character.h"

class Texture2D;

class GamescreenIntro :public Gamescreen
{
	public:
	GamescreenIntro(SDL_Renderer* renderer);
	~GamescreenIntro();
	void SetUpLevel();
	void Render();
	void Update(float deltaTime, SDL_Event e);

	private:

	Texture2D* m_background_texture;

};

#endif //_GAMESCREENINTRO_H