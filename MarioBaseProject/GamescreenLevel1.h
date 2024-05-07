#pragma once
#ifndef _GAMESCREENLVL1_H
#define _GAMESCREENLVL1_H

using namespace std;
#include "Gamescreen.h"
#include "Commons.h"
#include <SDL.h>
#include "Character.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"

class Texture2D;
class Character;

class GamescreenLevel1 :Gamescreen
{
public:
	GamescreenLevel1(SDL_Renderer* renderer);
	~GamescreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;

private:

	//Character* my_character;
	Texture2D* m_background_texture;
	bool SetUpLevel();
	//Characters:
	CharacterMario* m_mario;
	CharacterLuigi* m_luigi;

};
#endif // _GAMESCREENLVL1_H