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

class GamescreenLevel2:public Gamescreen
{
public:
	GamescreenLevel2(SDL_Renderer* renderer);
	~GamescreenLevel2();

	void Render(); 
	void Update(float deltaTime, SDL_Event e);

private:

	float m_background_yPos;
	LevelMap* m_level_map;

	void SetLevelMap();
	bool SetUpLevel();

	Character* my_character;
	Texture2D* m_background_texture;

	//Characters
	CharacterMario* m_mario;
	CharacterLuigi* m_luigi;
};

#endif //_GAMESCREENLEVEL2_H