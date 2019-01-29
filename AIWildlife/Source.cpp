#include "Source.h"
#include "SourceWindowForm.h"
#include "XMLHandler.h"
using namespace System;
using namespace System::Windows::Forms;

#pragma region appmain

[STAThreadAttribute]
int Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AIWildlife::SourceWindowForm form;
	Application::Run(%form);
	return 0;
}

#pragma endregion 


/**
 * Map Size is 875 * 875
 */

Source::Source(int handler)
{	
	mMessage = Messaging::Initialize();
	mStatWindow = StatWindow::Initialize();
	Initialize();
	if(!InitWindow(handler))
	{
		return;
	}
	LoadMapTiles();
	for (int i = 0; i < 15; i++)
	{
		Agents * temp = new Agents("Herbivore",mRenderer);
		temp->LoadTexture("Characters/Herbivore.bmp");
		
		float tempx, tempy;
	tempx = rand() % 875;
	tempy = rand() % 875;
	temp->SetPosition(Vector2D(tempx,tempy));
	mAgent->push_back(temp);
	}
	for (int i = 0; i < 15; i++)
	{
		Agents * temp = new Agents("Carnivore",mRenderer);
		temp->LoadTexture("Characters/Character.bmp");
		float tempx, tempy;
		tempx = rand() % 875;
		tempy = rand() % 875;
		temp->SetPosition(Vector2D(tempx, tempy));
		mAgent->push_back(temp);
	}
	for(int i = 0; i < 10;i++)
	{
		Plant * mPlant = new Plant(mRenderer);
		mPlant->LoadTexture("Tiles/FoodTile.bmp");
		mPlant->GeneratePosition();
		mPlant->SetStatIncrease(10.0f);
		mPlants->push_back(mPlant);
	}
	
	
	mOldTime = SDL_GetTicks();
	ThreadStart ^ operation = gcnew ThreadStart(GameLoop);
	Thread^ GameplayThread = gcnew Thread(operation);

	GameplayThread->Start();
	UILoop();



	//GameplayThread = gcnew Thread(gcnew ThreadStart());
}

Source::~Source()
{
}
void Source::UpdateGame()
{
	Uint32 newTime = SDL_GetTicks();
	float dt;
	dt = ((float)(newTime - mOldTime) / 1000.0f);
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
	}
	Flock(dt);
	for (int i = 0; i < mAgent->size(); i++)
	{
		if(mAgent->at(i)->GetName() == "Carnivore")
		{
			mAgent->at(i)->Update(dt, e);
		}
	}
	mOldTime = newTime;
}

void Source::RenderGame()
{
	SDL_RenderClear(mRenderer);
	mMap->DrawMap();
	for(int i = 0; i < mPlants->size(); i++)
	{
		mPlants->at(i)->Draw();
	}
	for (int i = 0; i < mAgent->size(); i++)
	{
		mAgent->at(i)->Render();
	}
	SDL_RenderPresent(mRenderer);
}

void Source::GameLoop()
{
	while (true)
	{
		UpdateGame();
		RenderGame();
	}

}

void Source::UILoop()
{
	int id = 500;
	while(true)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				id = CheckMousePolling();
			}
		}
		if(id > mAgent->size())
		{
		
		}
		else
		{
			mAgent->at(id)->SetSelected(true);
			mStatWindow->SetAgent(mAgent->at(id));
		}
	}
}

void Source::Flock(float dt)
{
	Vector2D Average;
	for(int i = 0; i < mAgent->size(); i++)
	{
		if(mAgent->at(i)->GetName() == "Herbivore")
		{
			Average += mAgent->at(i)->Wander(dt);
		}
	}
	Average = Average / mAgent->size();
	for (int j = 0; j < mAgent->size(); j++)
	{
		if(mAgent->at(j)->GetName() == "Herbivore")
		{
			mAgent->at(j)->GetForce() += mAgent->at(j)->Seek(Average);
			mAgent->at(j)->Update(dt);
		}
	}
}

void Source::LoadMapTiles()
{
	mMap = new Map(mRenderer);
	mMap->AddTile("Tiles/GrassTile.bmp", 0);
//	mMap->AddTile("Tiles/FoodTile.bmp", 1);
	mMap->SetMap(XMLHandler::LoadMapFromXML("Map1.xml"));

}

int Source::CheckMousePolling()
{
	int id = 500;
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		Vector2D mouse(x, y);
		for(int i = 0; i < mAgent->size();i++)
		{
			if(PointInBoxCollision(mouse,mAgent->at(i)->GetPosition(),mAgent->at(i)->GetWidth(),mAgent->at(i)->GetHeight()))
			{
				id = i;
			}
		}
	}
	return id;
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
	mMessage->SendMessage("Init Complete");
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
		SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
	}
	return true;
}
