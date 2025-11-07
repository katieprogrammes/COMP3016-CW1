#pragma once
#include "Screen.h"
#include <SDL_ttf.h>
#include <string>
#include <SDL_image.h>
#include <SDL.h>

class TransitionScreen2 : public Screen {
public:
    TransitionScreen2(SDL_Renderer* renderer, TTF_Font* font);
    ~TransitionScreen2();

    void handleEvents(SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

    bool isReadyToStart() const;

private:
    bool readyToStart = false;
    SDL_Texture* transTexture;
    SDL_Renderer* renderer;
    SDL_Rect transRect;
    TTF_Font* font;
    Mix_Music* bgMusic;

    void renderText(SDL_Renderer* renderer, const std::string& message, int x, int y, SDL_Color color);
};


