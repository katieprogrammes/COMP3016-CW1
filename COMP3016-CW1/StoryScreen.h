#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Screen.h"
#include <string>
#include <vector>
class StoryScreen : public Screen
{
public:
	StoryScreen(SDL_Renderer* renderer, TTF_Font* font);
	~StoryScreen();

	void handleEvents(SDL_Event& event) override;
	void update() override;
	void render(SDL_Renderer* renderer) override;
	bool nextScreenReady = false;

private:
	std::vector<SDL_Texture*> storyTextures;
	SDL_Renderer* renderer;
	SDL_Rect storyRect;
	TTF_Font* font;
	int currentIndex = 0;

	void renderText(SDL_Renderer* renderer, const std::string& message, int x, int y, SDL_Color color);
};

