#include "IntroScreen.h"
#include <iostream>



IntroScreen::IntroScreen(SDL_Renderer* renderer, TTF_Font* font)
    : renderer(renderer), font(font)
{
    SDL_Surface* introSurface = IMG_Load("Assets/Intro.png");
    if (!introSurface) {
        std::cout << "Failed to load intro image: " << IMG_GetError() << std::endl;
        return;
    }
    introTexture = SDL_CreateTextureFromSurface(renderer, introSurface);
    SDL_FreeSurface(introSurface);
    if (!introTexture) {
        std::cout << "Failed to create intro texture: " << SDL_GetError() << std::endl;
        return;
    }

    //Position and Size
    introRect.x = 0;  // X position
    introRect.y = 0; // Y position
    introRect.w = 800;  // Width of image
    introRect.h = 680;  // Height of image
}

IntroScreen::~IntroScreen() {}

void IntroScreen::handleEvents(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        readyToStart = true;
    }
}

void IntroScreen::update() {
    // No logic yet
}


void IntroScreen::render(SDL_Renderer* renderer) {
    SDL_Color white = { 255, 255, 255 };
    SDL_RenderClear(renderer);
    if (introTexture) {
        SDL_RenderCopy(renderer, introTexture, nullptr, &introRect);
    }
    renderText(renderer, "Press any key to start...", 250, 500, white);
    SDL_RenderPresent(renderer);
}

bool IntroScreen::isReadyToStart() const {
    return readyToStart;
}

void IntroScreen::renderText(SDL_Renderer* renderer, const std::string& message, int x, int y, SDL_Color color) {
    if (!font) return;

    SDL_Surface* surface = TTF_RenderText_Solid(font, message.c_str(), color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect destRect = { x, y, surface->w, surface->h };
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    SDL_DestroyTexture(texture);
}

