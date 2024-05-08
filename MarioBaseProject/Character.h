#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H

using namespace std;
#include "Commons.h"
#include "constants.h"
#include <SDL.h>
#include <iostream>
#include "Texture2D.h"
#include "LevelMap.h"

class Texture2D;
class MoveLeft;
class MoveRight;

class Character
{
      public:
          Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map);
          ~Character();

          float GetCollisionRadius();
          virtual void Jump();
          virtual void AddGravity(float deltaTime);
          virtual void Render();
          virtual void Update(float deltaTime, SDL_Event e);
          void SetPosition(Vector2D new_position);
          Vector2D GetPosition();

          inline Rect2D GetCollisionBox()
          {
              return Rect2D(m_position.x, m_position.y, m_texture->GetWidth(), m_texture->GetHeight());
          }


      private:
          FACING m_facing_direction;
          LevelMap* m_current_level_map;

      protected:
          virtual void MoveLeft(float deltaTime);
          virtual void MoveRight(float deltaTime);
          bool m_moving_left;
          bool m_moving_right;
          bool m_jumping;
          bool m_can_jump;
          float m_jump_force;
          float m_collision_radius;

          SDL_Renderer* m_renderer;
          Vector2D m_position;
          Texture2D* m_texture;
};

#endif //_CHARACTER_H