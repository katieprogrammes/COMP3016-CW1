#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "TypeMatchup.h"

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {}
Game::~Game() {}

void Game::battleLoopEasy() {
	Player player(100, 20);
	Enemy grunt(100, 20, AttackType::PLANT);

	while (!player.isDead() && !grunt.isDead()) {
		std::cout << "\n--- Player Turn ---\n";
		std::cout << "Choose your move:\n1. Fire\n2. Water\n3. Plant\n4. Lightning\n5. Physical\n6. Dark\n> ";
		int choice;
		std::cin >> choice;

		AttackType move = static_cast<AttackType>(choice - 1);
		player.attack(grunt, move);

		if (grunt.isDead()) {
			std::cout << "You defeated the enemy!\n";
			break;
		}

		std::cout << "\n--- Enemy Turn ---\n";
		player.takeDamage(20);
		std::cout << "Enemy attacks! Player HP: " << player.getHP() << "\n";

		if (player.isDead()) {
			std::cout << "You were defeated...\n";
			break;
		}
	}
}
void Game::battleLoopMedium() {
	Player player(100, 20);
	Enemy goblin(120, 20, AttackType::FIRE);

	while (!player.isDead() && !goblin.isDead()) {
		std::cout << "\n--- Player Turn ---\n";
		std::cout << "Choose your move:\n1. Fire\n2. Water\n3. Plant\n4. Lightning\n5. Physical\n6. Dark\n> ";
		int choice;
		std::cin >> choice;

		AttackType move = static_cast<AttackType>(choice - 1);
		player.attack(goblin, move);

		if (goblin.isDead()) {
			std::cout << "You defeated the enemy!\n";
			break;
		}

		std::cout << "\n--- Enemy Turn ---\n";
		player.takeDamage(20);
		std::cout << "Enemy attacks! Player HP: " << player.getHP() << "\n";

		if (player.isDead()) {
			std::cout << "You were defeated...\n";
			break;
		}
	}
}

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
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl; //debug
}
