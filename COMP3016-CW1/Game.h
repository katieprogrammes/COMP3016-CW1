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

	static SDL_Renderer* renderer;
private:
	bool isRunning;
	SDL_Window* window;
	TTF_Font* font;
};




