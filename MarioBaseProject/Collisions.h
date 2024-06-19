#pragma once
#ifndef _COLLISONS_H
#define _COLLISIONS_H
#include "Commons.h"
#include "Character.h"
using namespace std;

class Character;
class SpaceCharacter;

class Collisions
{
      public:
          ~Collisions();
          static Collisions* Instance();

          bool Circle(Character* character1, Character* character2);
          bool Box(Rect2D rect1, Rect2D rect2);
     
     private:
         Collisions();

         static Collisions* m_instance;

};

#endif //_COLLISONS_H