#pragma once
#ifndef _GAMESCREENLVL1_H
#define _GAMESCREENLVL1_H

using namespace std;
#include "Gamescreen.h"
#include "Commons.h"
#include <SDL.h>


class Texture2D
{
	GamescreenLevel1(SDL_Renderer* renderer);
	~GamescreenLevel1();
};

class GamescreenLevel1:Gamescreen
{
	private:
		Texture2D* m_background_texture;
};

#endif // _GAMESCREENLVL1_H