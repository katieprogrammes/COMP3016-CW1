#include "SuccessScreens.h"
#include <string>
#include <iostream>

SuccessScreens::SuccessScreens(SDL_Renderer* renderer)
    : renderer(renderer)
{
    //List of Story Screen paths
    std::vector<std::string> SuccessScreenss
    {
        "Assets/SuccessScreen1.png",
        "Assets/SuccessScreen2.png",
        "Assets/SuccessScreen3.png",
        "Assets/SuccessScreen4.png"
    };
    for (const auto& path : SuccessScreenss)
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

        successTextures.push_back(texture);
    }
    //Position and size of success screens
    successRect.x = 0;
    successRect.y = 0;
    successRect.w = 800;
    successRect.h = 640;

    bgMusic = Mix_LoadMUS("Assets/Ending.mp3");
    Mix_PlayMusic(bgMusic, -1);
}
SuccessScreens::~SuccessScreens()
{
    for (auto texture : successTextures)
    {
        SDL_DestroyTexture(texture);
    }
    Mix_FreeMusic(bgMusic);
}
void SuccessScreens::handleEvents(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN)
    {
        currentIndex++;
        if (currentIndex >= successTextures.size())
        {
            nextScreenReady = true;
        }
    }
}
void SuccessScreens::update()
{
}
void SuccessScreens::render(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);

    if (currentIndex < successTextures.size())
    {
        SDL_RenderCopy(renderer, successTextures[currentIndex], nullptr, &successRect);
        SDL_Color white = { 255, 255, 255 };

    }
    SDL_RenderPresent(renderer);
}


