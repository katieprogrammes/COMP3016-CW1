#pragma once
#include "ECS.h"
#include "TextureManager.h"
#include "Game.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class UILabel : public Component
{
public:
	UILabel(int xpos, int ypos, std::string text, SDL_Color& colour): 
		labelText(text), textColor(colour)
	{
		position.x = xpos;
		position.y = ypos;
	}
	~UILabel() {}

	void SetLabelText()
	{ 
		//SDL_Surface* surf = TTF_RenderText_Blended()
	}

	void draw() override
	{ }


private:
	SDL_Rect position;
	std::string labelText;
	SDL_Color textColor;
	SDL_Texture* labelTexture;
};
