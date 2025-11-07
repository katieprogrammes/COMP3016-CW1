#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "TypeMatchup.h"
#include "IntroScreen.h"
#include "Screen.h"

Screen* currentScreen = nullptr;
IntroScreen* intro = nullptr;
bool inIntro = true;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {}
Game::~Game() {}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) //initialising SDL
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialised!" << std::endl; //debug
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags); //window position on the screen
		if (window)
		{
			std::cout << "Window Created!" << std::endl; //debug
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			std::cout << "Renderer Created!" << std::endl; //debug
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	if (TTF_Init() == -1) {
		std::cout << "TTF Init Failed: " << TTF_GetError() << std::endl;
		isRunning = false;
		return;
	}

	font = TTF_OpenFont("Assets/MSGothic.ttf", 20);
	if (!font) {
		std::cout << "Font Load Failed: " << TTF_GetError() << std::endl;
		isRunning = false;
		return;
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) 
	{
		std::cout << "SDL_mixer Init Failed: " << Mix_GetError() << std::endl;
		isRunning = false;
		return;
	}

}



void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	std::cout << "Starting Cleanup" << std::endl; //debug
	SDL_DestroyWindow(window);
	std::cout << "Window Cleaned" << std::endl; //debug
	SDL_DestroyRenderer(renderer);
	std::cout << "Renderer Cleaned" << std::endl; //debug
	Mix_CloseAudio();
	std::cout << "Audio Cleaned" << std::endl; //debug
	TTF_Quit();
	std::cout << "TTF Cleaned" << std::endl; //debug
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl; //debug
}
