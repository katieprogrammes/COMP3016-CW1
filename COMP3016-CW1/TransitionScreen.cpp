#include "TransitionScreen.h"
#include <iostream>



TransitionScreen::TransitionScreen(SDL_Renderer* renderer, TTF_Font* font)
    : renderer(renderer), font(font)
{
    SDL_Surface* transSurface = IMG_Load("Assets/combatTransition.png");
    if (!transSurface) {
        std::cout << "Failed to load intro image: " << IMG_GetError() << std::endl;
        return;
    }
    transTexture = SDL_CreateTextureFromSurface(renderer, transSurface);
    SDL_FreeSurface(transSurface);
    if (!transTexture) {
        std::cout << "Failed to create intro texture: " << SDL_GetError() << std::endl;
        return;
    }

    //Position and Size
    transRect.x = 0;  // X position
    transRect.y = 0; // Y position
    transRect.w = 800;  // Width of image
    transRect.h = 640;  // Height of image

    bgMusic = Mix_LoadMUS("Assets/transition.wav");
    Mix_PlayMusic(bgMusic, -1);
}

TransitionScreen::~TransitionScreen() 
{
    Mix_FreeMusic(bgMusic);
}

void TransitionScreen::handleEvents(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        readyToStart = true;
    }
}

void TransitionScreen::update() {

}


void TransitionScreen::render(SDL_Renderer* renderer) {
    SDL_Color white = { 255, 255, 255 };
    SDL_RenderClear(renderer);
    if (transTexture) {
        SDL_RenderCopy(renderer, transTexture, nullptr, &transRect);
    }
    SDL_RenderPresent(renderer);
}

bool TransitionScreen::isReadyToStart() const {
    return readyToStart;
}

void TransitionScreen::renderText(SDL_Renderer* renderer, const std::string& message, int x, int y, SDL_Color color) {
    if (!font) return;

    SDL_Surface* surface = TTF_RenderText_Solid(font, message.c_str(), color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect transRect = { x, y, surface->w, surface->h };
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, nullptr, &transRect);
    SDL_DestroyTexture(texture);
}

