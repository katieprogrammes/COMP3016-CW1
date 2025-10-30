#include "Game.h"
#include "TextureManager.h"
//#include "Map.h"
#include "Components.h"


//Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
AssetManager* Game::assets = new AssetManager(&manager);

auto& player(manager.addEntity());
auto& player2(manager.addEntity());
auto& player3(manager.addEntity());
auto& label(manager.addEntity());

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
	TTF_Init();

	assets->AddTexture("Missy", "Assets/Missy.png");
	assets->AddTexture("Larry", "Assets/Larry.png");
	assets->AddTexture("Witcharella", "Assets/Witcharella.png");

	assets->AddFont("arial", "Assets/arial.ttf", 16);

	//map = new Map();


	//New Player

	player.addComponent<TransformComponent>(0, 200); //Start Position
	player.addComponent<SpriteComponent>("Missy");
	player2.addComponent<TransformComponent>(150, 200); //Start Position
	player2.addComponent<SpriteComponent>("Larry");
	player3.addComponent<TransformComponent>(300, 200); //Start Position
	player3.addComponent<SpriteComponent>("Witcharella");

	SDL_Color white = { 255, 255, 255, 255 };
	label.addComponent<UILabel>(10, 500, "Test String", "arial", white);

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
	manager.refresh();
	manager.update();

	/*if (player.getComponent<TransformComponent>().x() > 100)
	{
		player.getComponent<SpriteComponent>().setTex("Assets/Asta.png");
	}*/
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//map->DrawMap();
	manager.draw();
	label.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl; //debug
}

