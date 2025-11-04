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
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl; //debug
}
