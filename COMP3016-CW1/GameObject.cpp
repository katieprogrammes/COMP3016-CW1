#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;
}
