#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
class Screen {
public:
    virtual ~Screen() {}
    virtual void handleEvents(SDL_Event& event) = 0;
    virtual void update() = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
};

