//Be grateful for humble beginnings, because the next level will always require so much more of you
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"
#include <iostream>
#include "Texture2D.h"
#include "Commons.h"
#include "GamescreenManager.h"
using namespace std;

//Globals
GamescreenManager* game_screen_manager;
Uint32 g_old_time;
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
Texture2D* g_texture = nullptr;
Uint32 new_time = SDL_GetTicks();

//Function prototypes
bool InitSDL()
{
	// Setup SDL

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL did not initialise. Error:" << SDL_GetError();
		return false;
	}

	else
	{
		//setup passed so create window
		g_window = SDL_CreateWindow("Games Engine Creation",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
		//did the window get created?
		if (g_window == nullptr)
		{
			//window failed
			cout << "Window was not created. Error:" << SDL_GetError();
			return false;
		}
	}

	g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

	if (g_renderer != nullptr)
	{
		//init PNG loading
		int imageFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imageFlags) & imageFlags))
		{
			cout << "SDL_Image could not initialise.Error:" << IMG_GetError();
			return false;
		}
	}
	else
	{
		cout << "Renderer could not initialise.Error:" << SDL_GetError();
		return false;
	}

	//Load the background texture
	g_texture = new Texture2D(g_renderer);

	if (!g_texture -> LoadFromFile("Images/test.bmp"))
	{
		return false;
	}
}

void Render()
{
	//Clear the screen
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);

	g_texture->Render(Vector2D(), SDL_FLIP_NONE);
	game_screen_manager->Render();

	//update the screen
	SDL_RenderPresent(g_renderer);
}

void CloseSDL()
{
	//release the texture
	delete g_texture;
	g_texture = nullptr;
	 
	//release the window
	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	//quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	//destroy the game screen manager
	delete game_screen_manager;
	game_screen_manager = nullptr;
}

bool Update()
{

	//Event handler
	SDL_Event e;

	//get events
	SDL_PollEvent(&e);

	//handle the events
	switch (e.type)
	{
		//click the 'X' to quit
	    case SDL_QUIT:
			return true;
			break;
	}

	new_time = SDL_GetTicks();

	game_screen_manager->Update((float)(new_time - g_old_time) / 1000.0f, e);
	g_old_time = new_time;

	return false;

}

int main(int argc, char* args[])
{
	if (InitSDL())
	{
		game_screen_manager = new GamescreenManager(g_renderer, SCREEN_LEVEL1);

		//set the ticks
		g_old_time = SDL_GetTicks();

		//flag to check if we wish to quit
		bool quit = false;

		//Game loop
		while (!quit)
		{
			Render();
			quit = Update();
		}
	}

	CloseSDL();

	return 0;

}
