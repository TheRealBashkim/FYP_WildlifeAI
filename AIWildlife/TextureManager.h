#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "SDL.h"
class TextureManager
{
public:
	static SDL_Texture * LoadImage(const char path[], SDL_Renderer * render);
	static void Draw(SDL_Texture * texture, SDL_Renderer * render, SDL_Rect src, SDL_Rect dest);

};
#endif


