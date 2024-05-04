#include "Character.h"
#include "Texture2D.h"
using namespace std;

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position)
{
	
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagePath))
	{
		cout << "Failed to load the file from image path" << endl;
	}
}

Character::~Character()
{
	delete m_texture;
	m_texture = nullptr;
}

void Character::Render()
{
	m_texture->Render(m_position, SDL_FLIP_NONE);
}

void Character::Update(float deltaTime, SDL_Event e)
{
	switch
    
}

void Character::SetPosition(Vector2D new_position)
{

}
