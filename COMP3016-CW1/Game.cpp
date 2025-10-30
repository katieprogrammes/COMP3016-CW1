#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "TypeMatchup.h"

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

	font = TTF_OpenFont("Assets/arial.ttf", 20);
	if (!font) {
		std::cout << "Font Load Failed: " << TTF_GetError() << std::endl;
		isRunning = false;
		return;
	}

}

void Game::renderText(const std::string& message, int x, int y, SDL_Color color) {
	if (!font) {
		std::cout << "Font is null. Cannot render text.\n";
		return;
	}
	if (message.empty()) {
		std::cout << "Warning: Tried to render empty string.\n";
		return;
	}

	SDL_Surface* surface = TTF_RenderText_Solid(font, message.c_str(), color);
	if (!surface) {
		std::cout << "Text render failed: " << TTF_GetError() << std::endl;
		return;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect destRect = { x, y, surface->w, surface->h };
	SDL_FreeSurface(surface);
	SDL_RenderCopy(renderer, texture, nullptr, &destRect);
	SDL_DestroyTexture(texture);
}

int Game::getPlayerMove() {
	SDL_Event event;
	while (SDL_WaitEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_1: return 1;
			case SDLK_2: return 2;
			case SDLK_3: return 3;
			case SDLK_4: return 4;
			case SDLK_5: return 5;
			case SDLK_6: return 6;
			}
		}
	}
	return 5; // default to Physical
}
void Game::battleLoopEasy() {
	Player player(100, 20);
	Enemy grunt(100, 20, AttackType::PLANT);
	SDL_Color white = { 255, 255, 255 };
	SDL_Color blue = { 0, 0, 255 };
	SDL_Color red = { 255, 0, 0 };
	SDL_Color green = { 0, 255, 0 };

	while (!player.isDead() && !grunt.isDead()) {
		SDL_RenderClear(renderer);
		renderText("Choose your move: 1.Fire 2.Water 3.Plant 4.Lightning 5.Physical 6.Dark", 10, 500, white);
		SDL_RenderPresent(renderer);

		int choice = getPlayerMove();
		AttackType move = static_cast<AttackType>(choice - 1);
		auto [effectiveness, damage] = player.attack(grunt, move);
		std::string feedback = "You used " + TypeMatchup::typeToString(move) +
			". Effectiveness: " + std::to_string(effectiveness) +
			"x. Damage dealt: " + std::to_string(damage);

		renderText(feedback, 50, 550, blue);
		SDL_RenderPresent(renderer);
		SDL_Delay(1500); // pause to show feedback


		SDL_RenderClear(renderer);
		renderText("Enemy Turn: Enemy attacks!", 50, 500, red);
		player.takeDamage(20);
		SDL_RenderPresent(renderer);
		SDL_Delay(1000); // pause for effect

		if (grunt.isDead()) {
			SDL_RenderClear(renderer);
			renderText("You defeated the enemy!", 50, 500, green);
			SDL_RenderPresent(renderer);
			SDL_Delay(2000);
			break;
		}

		if (player.isDead()) {
			SDL_RenderClear(renderer);
			renderText("You were defeated...", 50, 500, red);
			SDL_RenderPresent(renderer);
			SDL_Delay(2000);
			break;
		}
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
