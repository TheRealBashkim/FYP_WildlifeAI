#ifndef SOURCE_H
#define SOURCE_H
#include "SDL.h"
#include <iostream>
#include "Windows.h"
#include "InputHandler.h"
#include "Map.h"

class Source
{
public:
	Source(int handler);
	~Source();
	void Update();
private:
	SDL_Window * mWindow;
	SDL_Renderer * mRenderer;
	Map * mMap;
	bool Initialize();
	bool InitWindow(int handler);

};

#endif


