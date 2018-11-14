#include "Source.h"
#include "SourceWindowForm.h"
#include "XMLHandler.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AIWildlife::SourceWindowForm form;
	Application::Run(%form);
	return 0;
}


Source::Source(int handler)
{
	Initialize();
	if(!InitWindow(handler))
	{
		return;
	}
	mMap = new Map(mRenderer);
	mMap->AddTile("Tiles/GrassTile.bmp", 0);
	mMap->SetMap(XMLHandler::LoadMapFromXML("Map1.xml"));
	Update();
}

Source::~Source()
{
}

void Source::Update()
{
	int quit = false;
	bool gridlines = false;
	SDL_Event e;
	while (!quit)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if (InputHandler::IsKeyDown(_Keys::G))
			{
				if (!gridlines)
				{
					gridlines = true;
				}
				else
				{
					gridlines = false;
				}
			}
		}
		mMap->DrawMap();
		SDL_RenderPresent(mRenderer);
	}
}

bool Source::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Error Loading SDL " << SDL_GetError() << std::endl;
		return false;
	}
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		std::cout << "Warning: Linear Texture filtering not enabled!" << std::endl;
	}
	return true;
}

bool Source::InitWindow(int handler)
{
	HWND handle = (HWND)handler;
	mWindow = SDL_CreateWindowFrom(handle);
	if (mWindow != NULL)
	{
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (mRenderer == NULL)
		{
			std::cout << "Error Creating Screen" << SDL_GetError() << std::endl;
			SDL_DestroyWindow(mWindow);
			mWindow = NULL;
			return false;
		}
		SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}
	return true;
}
