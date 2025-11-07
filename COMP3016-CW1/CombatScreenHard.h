#pragma once
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
#include "TypeMatchup.h"
#include <SDL.h>
#include "SDL_image.h"
#include <SDL_ttf.h>
#include <string>

class CombatScreenHard : public Screen
{
public:
    CombatScreenHard(SDL_Renderer* renderer, TTF_Font* font);
    ~CombatScreenHard();

    void handleEvents(SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

    bool isFinished() const;
    bool isSuccessful() const;

private:
    SDL_Renderer* renderer;
    TTF_Font* font;

    Player player;
    Enemy enemy;

    SDL_Texture* playerTexture;
    SDL_Texture* dmgPlayerTexture;
    SDL_Texture* deadPlayerTexture;
    SDL_Texture* enemyTexture;
    SDL_Texture* dmgEnemyTexture;
    SDL_Texture* sasaTexture;
    SDL_Texture* typeMatchupTex;
    SDL_Texture* moveSetTex;
    SDL_Texture* deadTxtTex;

    SDL_Rect playerRect;
    SDL_Rect dmgPlayerRect;
    SDL_Rect deadPlayerRect;
    SDL_Rect enemyRect;
    SDL_Rect dmgEnemyRect;
    SDL_Rect sasaRect;
    SDL_Rect typeMatchupRect;
    SDL_Rect moveSetRect;
    SDL_Rect deadTxtRect;

    bool finished = false;
    bool successful = false;
    bool waitingForInput = true;
    int playerChoice = 0;
    bool showTypeMatchup = false;

    Mix_Chunk* dmgSound;
    Mix_Chunk* hitSound;
    Mix_Chunk* superEffectiveSound;
    Mix_Chunk* notEffectiveSound;
    Mix_Chunk* victorySound;
    Mix_Music* bgMusic;
    Mix_Chunk* deathSound;

    void renderText(const std::string& message, int x, int y, SDL_Color color);
    int getPlayerMove(SDL_Event& event);
    void controlChart(SDL_Event& event);
};

