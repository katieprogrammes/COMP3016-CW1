#include "Game.h"
#include "TypeMatchup.h"
#include <iostream>
#include "IntroScreen.h"
#include "Screen.h"
#include "CombatScreen.h"
#include "StoryScreen.h"
#include "TransitionScreen.h"
#include "CombatScreenMed.h"
#include "DeathScreen.h"
#include "TransitionScreen2.h"
#include "CombatScreenHard.h"
#include "SuccessScreens.h"

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

	game->init("Help! My Best Friend Has Been Trapped in a Tower by an Evil Wizard! Lets go Save Her with the Power of Magic!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
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
	StoryScreen* story = new StoryScreen(game->getRenderer(), game->getFont());
	currentScreen = story;

	while (!story->nextScreenReady && game->running()) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) game->stopRunning();
			currentScreen->handleEvents(event);
		}

		currentScreen->update();
		currentScreen->render(game->getRenderer());
		SDL_Delay(frameDelay);
	}

	delete story;


	CombatScreen* combat = new CombatScreen(game->getRenderer(), game->getFont());
	currentScreen = combat;

	while (game->running() && !combat->isFinished()) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) game->stopRunning();
			currentScreen->handleEvents(event);
		}

		currentScreen->update();
		currentScreen->render(game->getRenderer());
		SDL_Delay(frameDelay);
	}
	if (!combat->isSuccessful()) 
	{
		DeathScreen* death = new DeathScreen(game->getRenderer(), game->getFont()); // Pass font from Game
		currentScreen = death;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				
			}
			currentScreen->handleEvents(event);
		}
		
		currentScreen->update();
		currentScreen->render(game->getRenderer()); // Use Game's renderer
		SDL_Delay(3000);
		game->stopRunning();
		std::cout << "Starting Cleanup" << std::endl; //debug
		game->clean();
		
		delete death;
	}
	else if (combat->isSuccessful()) {
		delete combat;
		TransitionScreen* transition = new TransitionScreen(game->getRenderer(), game->getFont()); // Pass font from Game
		currentScreen = transition;

		// Show transition screen until user presses a key
		while (!transition->isReadyToStart() && game->running()) {
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

		delete transition;
		CombatScreenMed* combatmed = new CombatScreenMed(game->getRenderer(), game->getFont());
		currentScreen = combatmed;

		while (game->running() && !combatmed->isFinished()) {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) game->stopRunning();
				currentScreen->handleEvents(event);
			}

			currentScreen->update();
			currentScreen->render(game->getRenderer());
			SDL_Delay(frameDelay);
		}
		if (!combatmed->isSuccessful())
		{
			DeathScreen* death = new DeathScreen(game->getRenderer(), game->getFont()); // Pass font from Game
			currentScreen = death;
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {

				}
				currentScreen->handleEvents(event);
			}

			currentScreen->update();
			currentScreen->render(game->getRenderer()); // Use Game's renderer
			SDL_Delay(3000);
			game->stopRunning();
			std::cout << "Starting Cleanup" << std::endl; //debug
			game->clean();

			delete death;
		}
		else if (combatmed->isSuccessful()) {
			delete combatmed;
			TransitionScreen2* transition = new TransitionScreen2(game->getRenderer(), game->getFont()); // Pass font from Game
			currentScreen = transition;

			// Show transition screen until user presses a key
			while (!transition->isReadyToStart() && game->running()) {
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

			delete transition;
			CombatScreenHard* combathard = new CombatScreenHard(game->getRenderer(), game->getFont());
			currentScreen = combathard;

			while (game->running() && !combathard->isFinished()) {
				SDL_Event event;
				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) game->stopRunning();
					currentScreen->handleEvents(event);
				}

				currentScreen->update();
				currentScreen->render(game->getRenderer());
				SDL_Delay(frameDelay);
			}
			if (!combathard->isSuccessful())
			{
				DeathScreen* death = new DeathScreen(game->getRenderer(), game->getFont()); // Pass font from Game
				currentScreen = death;
				SDL_Event event;
				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {

					}
					currentScreen->handleEvents(event);
				}

				currentScreen->update();
				currentScreen->render(game->getRenderer()); // Use Game's renderer
				SDL_Delay(3000);
				game->stopRunning();
				std::cout << "Starting Cleanup" << std::endl; //debug
				game->clean();

				delete death;
			}
			else if (combathard->isSuccessful()) {
				delete combathard;
				SuccessScreens* successend = new SuccessScreens(game->getRenderer());
				currentScreen = successend;

				while (!successend->nextScreenReady && game->running()) {
					SDL_Event event;
					while (SDL_PollEvent(&event)) {
						if (event.type == SDL_QUIT) game->stopRunning();
						currentScreen->handleEvents(event);
					}

					currentScreen->update();
					currentScreen->render(game->getRenderer());
					SDL_Delay(frameDelay);
				}

				delete successend;
				game->stopRunning();
				std::cout << "Starting Cleanup" << std::endl; //debug
				game->clean();
			}
		}
	}

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
	delete game;
	return 0;
}
