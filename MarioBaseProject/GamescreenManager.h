#pragma once
#ifndef _GAMESCREENMANAGER_H
#define _GAMESCREENMANAGER_H

using namespace std;
#include "Commons.h"
#include <SDL.h>

class Gamescreen;

class GamescreenManager
{
      public:
          GamescreenManager(SDL_Renderer* renderer, SCREENS startScreen);
          ~GamescreenManager();

          void Render();
          void Update(float deltaTime, SDL_Event e);

          void ChangeScreen(SCREENS new_screen);
      private:
      SDL_Renderer* m_renderer;
      Gamescreen* m_current_screen;
};

#endif //_GAMESCREENMANAGER_H