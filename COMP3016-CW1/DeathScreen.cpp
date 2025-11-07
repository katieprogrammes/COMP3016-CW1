#include "DeathScreen.h"
#include "Game.h"
#include <iostream>



DeathScreen::DeathScreen(SDL_Renderer* renderer, TTF_Font* font)
    : renderer(renderer), font(font)
{
    SDL_Surface* deathSurface = IMG_Load("Assets/deathScreen.png");
    if (!deathSurface) {
        std::cout << "Failed to load intro image: " << IMG_GetError() << std::endl;
        return;
    }
    deathTexture = SDL_CreateTextureFromSurface(renderer, deathSurface);
    SDL_FreeSurface(deathSurface);
    if (!deathTexture) {
        std::cout << "Failed to create intro texture: " << SDL_GetError() << std::endl;
        return;
    }

    //Position and Size
    deathRect.x = 0;  // X position
    deathRect.y = 0; // Y position
    deathRect.w = 800;  // Width of image
    deathRect.h = 640;  // Height of image
}

DeathScreen::~DeathScreen() 
{
    SDL_DestroyTexture(deathTexture);
}

void DeathScreen::handleEvents(SDL_Event& event) {

}

void DeathScreen::update() {
}


void DeathScreen::render(SDL_Renderer* renderer) {
    SDL_Color white = { 255, 255, 255 };
    SDL_RenderClear(renderer);
    if (deathTexture) {
        SDL_RenderCopy(renderer, deathTexture, nullptr, &deathRect);
    }
    SDL_RenderPresent(renderer);
}

void DeathScreen::renderText(SDL_Renderer* renderer, const std::string& message, int x, int y, SDL_Color color) {
    if (!font) return;

    SDL_Surface* surface = TTF_RenderText_Solid(font, message.c_str(), color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect deathRect = { x, y, surface->w, surface->h };
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, nullptr, &deathRect);
    SDL_DestroyTexture(texture);
}

