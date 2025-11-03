#pragma once
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
#include "TypeMatchup.h"
#include <SDL.h>
#include "SDL_image.h"
#include <SDL_ttf.h>
#include <string>

class CombatScreen : public Screen
{
public:
	CombatScreen(SDL_Renderer* renderer, TTF_Font* font);
	~CombatScreen();

	void handleEvents(SDL_Event& event) override;
	void update() override;
	void render(SDL_Renderer* renderer) override;

	bool isFinished() const;

private:
    SDL_Renderer* renderer;
    TTF_Font* font;

    Player player;
    Enemy enemy;

    SDL_Texture* playerTexture;
    SDL_Texture* dmgPlayerTexture;
    SDL_Texture* deadPlayerTexture;
    SDL_Texture* enemyTexture;

    SDL_Rect playerRect;
    SDL_Rect dmgPlayerRect;
    SDL_Rect deadPlayerRect;
    SDL_Rect enemyRect;

    bool finished = false;
    bool waitingForInput = true;
    int playerChoice = 0;

    void renderText(const std::string& message, int x, int y, SDL_Color color);
    int getPlayerMove(SDL_Event& event);

};

