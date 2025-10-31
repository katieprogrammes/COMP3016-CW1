#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
#include <vector>

class Game {
public:
	Game(); //constructor
	~Game(); //deconstructor
	void battleLoopEasy();
	void battleLoopMedium();
	//void battleLoopHard();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen); //method for initialising
	void renderText(const std::string& message, int x, int y, SDL_Color color);
	int getPlayerMove();
	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();
	SDL_Renderer* getRenderer() const { return renderer; }
	TTF_Font* getFont() const { return font; }
	void stopRunning() { isRunning = false; }


	static SDL_Renderer* renderer;
private:
	bool isRunning;
	SDL_Window* window;
	TTF_Font* font;
	SDL_Texture* playerTexture;
	SDL_Rect playerRect;
	SDL_Texture* DMGplayerTexture;
	SDL_Rect DMGplayerRect;
	SDL_Texture* enemyTexture;
	SDL_Rect enemyRect;
	SDL_Texture* enemyTexture2;
	SDL_Rect enemyRect2;
};




