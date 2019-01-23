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

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
ref class Source
{
public:
	Source(int handler);
	~Source();
	void Update();
	void Render();
private:
	void CheckMousePolling();
	SDL_Window * mWindow;
	SDL_Renderer * mRenderer;
	Map * mMap;
	bool Initialize();
	bool InitWindow(int handler);
	std::vector<Agents*> * mAgent = new std::vector<Agents*>();
	Uint32 mOldTime;
	Messaging ^ mMessage;
	StatWindow ^ mStatWindow;
	Thread^ StatThread;

};

#endif


