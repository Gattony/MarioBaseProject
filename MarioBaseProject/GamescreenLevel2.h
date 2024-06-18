#pragma once
#ifndef _GAMESCREENLEVEL2_H
#define _GAMESCREENLEVEL2_H
using namespace std;
#include "LevelMap.h"
#include "Gamescreen.h"
#include "Commons.h"
#include <SDL.h>
#include "SpaceCharacter.h"
#include "CharacterSpaceMario.h"
#include "CharacterKoopa.h"
#include "Meteor.h"
#include <vector>

class Texture2D;
class Character;
class PowBlock;


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

	//Mapping
	void SetLevelMap();
	bool SetUpLevel();

	Texture2D* m_background_texture;

	//Characters
	CharacterSpaceMario* m_space_mario;
	Meteor* m_meteor;

	//Meteors
	void UpdateMeteors(float deltaTime, SDL_Event e);
	void CreateMeteor(Vector2D position);
	void MeteorSpawn(float deltaTime, SDL_Event e);
	float meteor_time;
	vector<Meteor*> m_meteors;
};

#endif //_GAMESCREENLEVEL2_H

