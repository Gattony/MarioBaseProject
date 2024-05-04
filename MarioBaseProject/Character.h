#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H

using namespace std;
#include "Commons.h"
#include <SDL.h>
#include <iostream>

class Texture2D;

class Character
{
      public:
          Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
          ~Character();

          virtual void Render();
          virtual void Update(float deltaTime, SDL_Event e);
          void SetPosition(Vector2D new_position);
          Vector2D GetPosition();

      protected:
          SDL_Renderer* m_renderer;
          Vector2D m_position;
          Texture2D* m_texture;
};

#endif //_CHARACTER_H