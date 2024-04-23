#pragma once
#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H

using namespace std;
#include <SDL.h>
#include <string>
#include "Commons.h"

SDL_Renderer* m_renderer;
SDL_Texture* m_texture;

int m_width;
int m_height;

class Texture2D
{
   public:
	   Texture2D(SDL_Renderer* renderer);
	   ~Texture2D();

	   bool LoadFromFile(string path);
	   void Free();
	   void Render(Vector2D new_position, SDL_RendererFlip flip, double angle = 0.0);
	   
	   int GetWidth() { return m_width; }
	   int GetHeight() { return m_height; }
   private:

};

#endif //0_TEXTURE2D_H