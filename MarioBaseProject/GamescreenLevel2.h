#pragma once
#ifndef _GAMESCREENLEVEL2_H
#define _GAMESCREENLEVEL2_H

using namespace std;
#include "LevelMap.h"
#include "Gamescreen.h"
#include "Commons.h"
#include <SDL.h>
#include "Character.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "CharacterKoopa.h"
#include <vector>

class Texture2D;
class Character;
class PowBlock;

class GamescreenLevel2 :Gamescreen
{
	GamescreenLevel2(SDL_Renderer* renderer) :Gamescreen(renderer);
	~(GamescreenLevel2);
};
#endif //GAMESCREENLEVEL2_H