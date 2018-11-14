#include "TextureManager.h"

SDL_Texture * TextureManager::LoadImage(const char path[], SDL_Renderer * render)
{
	SDL_Surface * tempSurface = SDL_LoadBMP(path);
	if (tempSurface == nullptr)
	{
		return nullptr;
	}
	SDL_Texture * tempTexture = SDL_CreateTextureFromSurface(render, tempSurface);
	if (tempTexture != nullptr)
	{
		SDL_FreeSurface(tempSurface);
		return tempTexture;
	}
	return nullptr;
}

void TextureManager::Draw(SDL_Texture * texture, SDL_Renderer * renderer, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(renderer, texture, &src, &dest);
}
