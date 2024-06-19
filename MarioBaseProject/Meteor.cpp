#include "Meteor.h"
#include "constants.h"
#include "Character.h"

using namespace std;

Meteor::Meteor(SDL_Renderer* renderer, string imagePath, LevelMap* map, Vector2D start_position) : Character(renderer, imagePath, start_position, map)
{
	m_injured = false;
	m_position = start_position;
}

void Meteor::Render()
{
	//Rendering the meteor
	m_texture->Render(m_position, SDL_FLIP_NONE);
	
}

void Meteor::TakeDamage()
{
	m_injured = true;
}

void Meteor::Update(float deltaTime, SDL_Event e)
{
	Character::Update(deltaTime, e);

}