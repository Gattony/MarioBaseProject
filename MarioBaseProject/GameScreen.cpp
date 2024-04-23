#include "Gamescreen.h"
#include <iostream>
#include "SDL_image.h"
using namespace std;

Gamescreen::Gamescreen(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

Gamescreen::~Gamescreen()
{
	m_renderer = nullptr;
}