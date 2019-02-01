#ifndef SOURCE_H
#define SOURCE_H
#include "SDL.h"
#include <iostream>
#include "Windows.h"
#include "InputHandler.h"
#include "Map.h"
#include "BaseAgent.h"
#include "Agents.h"
#include "Messaging.h"
#include <vector>
#include "StatWindow.h"
#include "Plant.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
ref class Source
{
public:
	Source(int handler);
	~Source();
	static void UpdateGame();
	static void RenderGame();
	static void GameLoop();
	static void UILoop();
	static void Flock(float dt);
	static void LoadMapTiles();
private:
	static int CheckMousePolling();
	SDL_Window * mWindow;
	static SDL_Renderer * mRenderer;
	static Map * mMap;
	bool Initialize();
	bool InitWindow(int handler);
	static std::vector<Agents*> * mAgent = new std::vector<Agents*>();
	static std::vector<Plant*>* mPlants = new std::vector<Plant*>();
	static Uint32 mOldTime;
	Messaging ^ mMessage;
	static StatWindow ^ mStatWindow;
	Thread^ StatThread;

};

#endif


