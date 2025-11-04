#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Screen.h"
#include <string>
#include <vector>
class SuccessScreens : public Screen
{
public:
	SuccessScreens(SDL_Renderer* renderer);
	~SuccessScreens();

	void handleEvents(SDL_Event& event) override;
	void update() override;
	void render(SDL_Renderer* renderer) override;
	bool nextScreenReady = false;

private:
	std::vector<SDL_Texture*> successTextures;
	SDL_Renderer* renderer;
	SDL_Rect successRect;
	int currentIndex = 0;
};

