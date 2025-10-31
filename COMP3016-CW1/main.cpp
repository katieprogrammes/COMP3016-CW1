#include "Game.h"
#include "TypeMatchup.h"
#include <iostream>
#include "IntroScreen.h"
#include "Screen.h"


Game* game = nullptr;

int main(int argc, char* argv[])
{

	TypeMatchup matchup;
	AttackType playerMove = AttackType::FIRE;
	AttackType enemyType = AttackType::PLANT;
	float effectiveness = matchup.getEffectiveness(playerMove, enemyType);

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	game = new Game();

	game->init("Help! My Best Friend Has Been Trapped in a Tower by an Evil Wizard and Our Friends are Coming Together to Save Them", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	IntroScreen* intro = new IntroScreen(game->getRenderer(), game->getFont()); // Pass font from Game
	Screen* currentScreen = intro;

	// Show intro screen until user presses a key
	while (!intro->isReadyToStart() && game->running()) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				game->stopRunning();
			}
			currentScreen->handleEvents(event);
		}

		currentScreen->update();
		currentScreen->render(game->getRenderer()); // Use Game's renderer

		SDL_Delay(frameDelay);
	}

	delete intro;

	game->battleLoopEasy();
	//game->battleLoopMedium();
	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	};

	game->clean();
	return 0;
}
