#ifndef SOURCE_H
#define SOURCE_H
#include "SDL.h"
#include <iostream>
#include "Windows.h"
#include "InputHandler.h"
#include "Map.h"
#include "BaseAgent.h"
#include "TestAI.h"
#include "Messaging.h"

using namespace System;
using namespace System::Windows::Forms;
ref class Source
{
public:
	Source(int handler);
	~Source();
	void Update();
	void Render();
private:
	SDL_Window * mWindow;
	SDL_Renderer * mRenderer;
	Map * mMap;
	bool Initialize();
	bool InitWindow(int handler);
	TestAI * mAgent;
	Uint32 mOldTime;
	Messaging ^ mMessage;

};

#endif


