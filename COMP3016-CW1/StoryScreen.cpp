#include "StoryScreen.h"
#include <string>
#include <iostream>

StoryScreen::StoryScreen(SDL_Renderer* renderer, TTF_Font* font)
    : renderer(renderer), font(font)
{
    //List of Story Screen paths
    std::vector<std::string> storyScreens
    {
        "Assets/StoryScreen1.png",
        "Assets/StoryScreen2.png",
        "Assets/StoryScreen3.png",
        "Assets/StoryScreen4.png",
        "Assets/StoryScreen5.png",
        "Assets/HowToPlayScreen.png"

    };
    for (const auto& path : storyScreens)
    {
        SDL_Surface* surface = IMG_Load(path.c_str());
        if (!surface) {
            std::cout << "Failed to load image: " << path << " - " << IMG_GetError() << std::endl;
            continue;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if (!texture) {
            std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
            continue;
        }

        storyTextures.push_back(texture);
    }
    //Position and size of story screens
    storyRect.x = 0;
    storyRect.y = 0;
    storyRect.w = 800;
    storyRect.h = 640;
}
StoryScreen::~StoryScreen() 
{
    for (auto texture : storyTextures) 
    {
        SDL_DestroyTexture(texture);
    }
}
void StoryScreen::handleEvents(SDL_Event& event) 
{
    if (event.type == SDL_KEYDOWN) 
    {
        currentIndex++;
        if (currentIndex >= storyTextures.size()) 
        {
            nextScreenReady = true;
        }
    }
}
void StoryScreen::update() 
{ }
void StoryScreen::render(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);

    if (currentIndex < storyTextures.size()) 
    {
        SDL_RenderCopy(renderer, storyTextures[currentIndex], nullptr, &storyRect);
        SDL_Color white = { 255, 255, 255 };
        renderText(renderer, "", 250, 200, white);
    }

    SDL_RenderPresent(renderer);
}

void StoryScreen::renderText(SDL_Renderer* renderer, const std::string& message, int x, int y, SDL_Color color) 
{
    if (!font) return;

    SDL_Surface* surface = TTF_RenderText_Solid(font, message.c_str(), color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect destRect = { x, y, surface->w, surface->h };
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    SDL_DestroyTexture(texture);
}

