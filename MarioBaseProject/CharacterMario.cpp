#include "CharacterMario.h"
#include "Character.h"
#include "LevelMap.h"

using namespace std;

CharacterMario::CharacterMario(SDL_Renderer* renderer, string imagePath, Vector2D start_position, LevelMap* map):Character(renderer, imagePath, start_position, map)
{

}

CharacterMario::~CharacterMario()
{

}