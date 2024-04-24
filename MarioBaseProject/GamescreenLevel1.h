#pragma once
#ifndef _GAMESCREENLVL1_H
#define _GAMESCREENLVL1_H

using namespace std;
#include "Gamescreen.h"
#include "Commons.h"
#include <SDL.h>

class Texture2D;

class GamescreenLevel1 :Gamescreen
{
    public:
	GamescreenLevel1(SDL_Renderer* renderer);
	~GamescreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

    private:
	Texture2D* m_background_texture;
	bool SetUpLevel();

};
#endif // _GAMESCREENLVL1_H