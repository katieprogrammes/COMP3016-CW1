#pragma once
#include "Screen.h"
#include <SDL_ttf.h>
#include <string>
#include <SDL_image.h>
#include <SDL.h>

class DeathScreen : public Screen {
public:
    DeathScreen(SDL_Renderer* renderer, TTF_Font* font);
    ~DeathScreen();

    void handleEvents(SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

private:
    bool readyToStart = false;
    SDL_Texture* deathTexture;
    SDL_Renderer* renderer;
    SDL_Rect deathRect;
    TTF_Font* font;

    void renderText(SDL_Renderer* renderer, const std::string& message, int x, int y, SDL_Color color);
};


