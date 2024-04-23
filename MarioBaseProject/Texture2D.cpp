#include "Texture2D.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;

Texture2D::Texture2D(SDL_Renderer* renderer) 
{
	m_renderer = renderer;
}

Texture2D::~Texture2D()
{
	//Free up memory
	Free();

	m_renderer = nullptr;
}

bool Texture2D::LoadFromFile(string path) 
{

}

void Texture2D::Free() 
{
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
		m_width = 0;
		m_height = 0;
	}
}

void Texture2D::Render(Vector2D new_position, SDL_RendererFlip flip, double angle) 
{
	//set where to render the text ure
	SDL_Rect renderLocation = { 0,0,m_width, m_height };
	
	//Render to screen
	SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &renderLocation, 0, nullptr, SDL_FLIP_NONE);
}