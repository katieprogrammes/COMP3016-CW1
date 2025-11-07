#pragma once
#include "Screen.h"
#include <SDL_ttf.h>
#include <string>
#include <SDL_image.h>
#include <SDL.h>

class IntroScreen : public Screen {
public:
    IntroScreen(SDL_Renderer* renderer, TTF_Font* font);
    ~IntroScreen();

    void handleEvents(SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

    bool isReadyToStart() const;

private:
    bool readyToStart = false;
    SDL_Texture* introTexture;
    SDL_Renderer* renderer;
    SDL_Rect introRect;
    TTF_Font* font;
    Mix_Music* bgMusic;
    void renderText(SDL_Renderer* renderer, const std::string& message, int x, int y, SDL_Color color);
};


