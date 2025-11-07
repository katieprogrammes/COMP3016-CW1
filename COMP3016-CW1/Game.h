#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <iostream>
#include <vector>

class Game {
public:
	Game(); //constructor
	~Game(); //deconstructor
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen); //method for initialising
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
};




