#pragma once
#ifndef _GAMESCREEN_H
#define _GAMESCREEN_H

using namespace std;
#include <SDL.h>
#include <string>
#include "Commons.h"

class Gamescreen
{
   public:
	   Gamescreen(SDL_Renderer* renderer);
	   ~Gamescreen();

	   virtual void Render();
	   virtual void Update(float deltaTime, SDL_Event e);
	   SDL_Renderer* m_renderer;
	   SDL_Texture* m_texture;

   private:
	   int m_width;
	   int m_height;
};


#endif //_GAMESCREEN_H