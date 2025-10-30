#include <map>
#include "Attack.h"
#include <SDL.h>

std::map<SDL_Keycode, AttackType> keyToAttack = {
    {SDLK_1, FIRE},
    {SDLK_2, WATER},
    {SDLK_3, PLANT},
    {SDLK_4, LIGHTNING},
    {SDLK_5, PHYSICAL},
    {SDLK_6, DARK},
};
	