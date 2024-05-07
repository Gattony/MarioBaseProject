#pragma once
#ifndef _COLLISONS_H
#define _COLLISIONS_H
#include "Commons.h"
using namespace std;

class Character;

class Collisions
{
      public:
          ~Collisions();
          static Collisions* Instance();

          float GetCollisionRadius();
          bool Circle(Character* character1, Character* character2);
          bool Box(Rect2D rect1, Rect2D rect2);
     
     protected:
         float m_collision_radius;

     private:
         Collisions();

         static Collisions* m_instance;

};

#endif //_COLLISONS_H