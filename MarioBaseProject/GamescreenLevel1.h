#pragma once
#ifndef _GAMESCREENLVL1_H
#define _GAMESCREENLVL1_H

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

class GamescreenLevel1 :Gamescreen
{
public:
	GamescreenLevel1(SDL_Renderer* renderer);
	~GamescreenLevel1();

	void UpdatePOWBlock();
	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

private:

	bool m_screenshake;
	float m_shake_time;
	float m_wobble;
	float m_background_yPos;
	PowBlock* m_pow_block;
	LevelMap* m_level_map;

	//Mapping
	void DoScreenShake();
	void SetLevelMap();
	bool SetUpLevel();

	//Character* my_character;
	Texture2D* m_background_texture;

	//Characters:
	CharacterKoopa* m_koopa;
	CharacterMario* m_mario;
	CharacterLuigi* m_luigi;

	//Enemies:
	void UpdateEnemies(float deltaTime, SDL_Event e);
	void CreateKoopa(Vector2D position, FACING direction, float speed);
	vector<CharacterKoopa*> m_enemies;

};
#endif // _GAMESCREENLVL1_H