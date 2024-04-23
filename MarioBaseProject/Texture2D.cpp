#include "Texture2D.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;

Texture2D::Texture2D(SDL_Renderer* renderer) 
{
	m_renderer = renderer;
}

bool Texture2D::LoadFromFile(string path) 
{

}

void Texture2D::Free() 
{

}

void Texture2D::Render(Vector2D new_position, SDL_RendererFlip flip, double angle) 
{

}