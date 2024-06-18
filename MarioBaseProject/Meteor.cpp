#include "Meteor.h"
#include "constants.h"
#include "Character.h"

using namespace std;

Meteor::Meteor(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position) : Character(renderer, imagePath, start_position, map)
{
	m_position = start_position;
}

void Meteor::Render()
{
}

void Meteor::Update(float deltaTime, SDL_Event e)
{
}
