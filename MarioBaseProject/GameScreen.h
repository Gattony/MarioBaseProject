#pragma once
#ifndef _GAMESCREEN_H
#define _GAMESCREEN_H

using namespace std;
#include <SDL.h>

class GameScreen
{
	SDL_Renderer* m_renderer;
	
	GameScreen(SDL_Renderer* renderer);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
};

#endif //0_GAMESCREENCLASS_H

class Gamescreen
{
};
