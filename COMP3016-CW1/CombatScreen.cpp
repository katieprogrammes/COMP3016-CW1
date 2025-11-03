#include "CombatScreen.h"
#include <iostream>

CombatScreen::CombatScreen(SDL_Renderer* renderer, TTF_Font* font)
    : renderer(renderer), font(font), player(100, 20), enemy(100, 20, AttackType::LIGHTNING) {

    SDL_Surface* surface = IMG_Load("Assets/Witcharella.png");
    playerTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    playerRect = { 50, 150, 180, 296 };

    surface = IMG_Load("Assets/DMGWitcharella.png");
    dmgPlayerTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    dmgPlayerRect = { 250, 150, 180, 296 };

    surface = IMG_Load("Assets/Larry.png");
    enemyTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    enemyRect = { 500, 150, 248, 303 };
}

CombatScreen::~CombatScreen() {
    SDL_DestroyTexture(playerTexture);
    SDL_DestroyTexture(dmgPlayerTexture);
    SDL_DestroyTexture(enemyTexture);
}

void CombatScreen::handleEvents(SDL_Event& event) {
    if (waitingForInput) {
        playerChoice = getPlayerMove(event);
        if (playerChoice != 0) {
            waitingForInput = false;
        }
    }
}

int CombatScreen::getPlayerMove(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_1: return 1;
        case SDLK_2: return 2;
        case SDLK_3: return 3;
        case SDLK_4: return 4;
        case SDLK_5: return 5;
        case SDLK_6: return 6;
        }
    }
    return 0;
}

void CombatScreen::update() {
    if (!waitingForInput && !player.isDead() && !enemy.isDead()) {
        AttackType move = static_cast<AttackType>(playerChoice - 1);
        auto [effectiveness, damage] = player.attack(enemy, move);

        std::string feedback = "You used " + TypeMatchup::typeToString(move) +
            ". Damage dealt: " + std::to_string(damage);
        SDL_Color pink = { 255, 230, 247 };
        SDL_Color effectColor = TypeMatchup::effectColor(effectiveness);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, playerTexture, nullptr, &playerRect);
        SDL_RenderCopy(renderer, enemyTexture, nullptr, &enemyRect);
        renderText(feedback, 200, 100, pink);
        renderText(TypeMatchup::effectToString(effectiveness), 250, 125, effectColor);
        SDL_RenderPresent(renderer);
        SDL_Delay(3000);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, dmgPlayerTexture, nullptr, &dmgPlayerRect);
        renderText("Enemy Turn: Enemy attacks!", 200, 500, { 255, 0, 0 });
        player.takeDamage(20);
        SDL_RenderPresent(renderer);
        SDL_Delay(1500);

        if (enemy.isDead()) {
            renderText("You defeated the enemy!", 200, 500, { 0, 255, 0 });
            SDL_RenderPresent(renderer);
            SDL_Delay(2000);
            finished = true;
        }
        else if (player.isDead()) {
            renderText("You were defeated...", 200, 500, { 255, 0, 0 });
            SDL_RenderPresent(renderer);
            SDL_Delay(2000);
            finished = true;
        }

        waitingForInput = true;
        playerChoice = 0;
    }
}

void CombatScreen::render(SDL_Renderer* renderer) {
    SDL_Color white = { 255, 255, 255 };
    SDL_RenderClear(renderer);
    renderText("Player HP: " + std::to_string(player.getHP()), 10, 10, white);
    SDL_RenderCopy(renderer, playerTexture, nullptr, &playerRect);
    SDL_RenderCopy(renderer, enemyTexture, nullptr, &enemyRect);
    renderText("Choose your move: 1.Fire 2.Water 3.Plant 4.Lightning 5.Physical 6.Dark", 10, 500, white);
    SDL_RenderPresent(renderer);
}

bool CombatScreen::isFinished() const {
    return finished;
}

void CombatScreen::renderText(const std::string& message, int x, int y, SDL_Color color) {
    if (!font || message.empty()) return;

    SDL_Surface* surface = TTF_RenderText_Solid(font, message.c_str(), color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect destRect = { x, y, surface->w, surface->h };
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    SDL_DestroyTexture(texture);
}
