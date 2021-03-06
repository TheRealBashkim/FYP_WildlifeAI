#include "Source.h"
#include "SourceWindowForm.h"
#include "XMLHandler.h"
#include "HerbivoreAgent.h"
#include "CarnivoreAgent.h"
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
	mStatWindow = StatWindow::Initialize();
	mMessage = Messaging::Initialize();
	Initialize();
	if(!InitWindow(handler))
	{
		return;
	}
	//LoadMapTiles();
	mAgentManager = AgentManager::Instance();
	mAgentManager->SetRenderer(mRenderer);
	GenerateBaseChromosome();
	BackgroundTex = new Texture2D(mRenderer);
	BackgroundTex->LoadFromFile("Tiles/Grass.bmp");


	mPlantManger = new PlantManager(mRenderer);
	mOldTime = SDL_GetTicks();
	ThreadStart ^ operation = gcnew ThreadStart(GameLoop);
	Thread^ GameplayThread = gcnew Thread(operation);

	GameplayThread->Start();
	UILoop();
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
	mAgentManager->Update(dt);
	mPlantManger->Update(mAgentManager->GetAgents(),dt);
	mOldTime = newTime;
}

void Source::RenderGame()
{
	SDL_RenderClear(mRenderer);

	//mMap->DrawMap();
	BackgroundTex->Render(0,0);
	mPlantManger->Draw();
	mAgentManager->Draw();


	//renders background image.
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

void Source::SetupMessaging()
{
	Messaging::Initialize();
	
}

void Source::UILoop()
{
	
	while(true)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
			{
				int x, y;
				SDL_GetMouseState(&x, &y);
				Vector2D Mouse(x, y);
				mStatAgent = mAgentManager->CheckMousePolling(Mouse);
			}
		}
		if(mStatAgent != nullptr)
		{
			//mAgentManager->GetAgents()->at(selectedID)->SetSelected(true);
			mStatAgent->SetSelected(true);
			mStatWindow->SetAgent(mStatAgent);
		}
	}
}

void Source::LoadMapTiles()
{
	mMap = new Map(mRenderer);
	mMap->AddTile("Tiles/GrassTile.bmp", 0);
	mMap->SetMap(XMLHandler::LoadMapFromXML("Map1.xml"));

}

void Source::GenerateBaseChromosome()
{
	std::vector<Chromosome*> mChromo = XMLHandler::LoadChromosome("XML/Chromosome.xml");
	srand(time(NULL));
	if(mChromo.empty())
	{
		int carnivore = 0;
		int herbivore = 0;
		for(int i = 0; i < 24; i++)
		{
			HerbivoreAgent * temp = new HerbivoreAgent("Herbivore", mRenderer);
			temp->LoadTexture("Characters/Herbivore.bmp");
			float tempx, tempy;
			tempx = rand() % 875;
			tempy = rand() % 875;
			temp->GetChromosome()->SetGene(ChromosomeManager::GenerateGene());
			temp->GetChromosome()->GetGene()->mName = temp->GetName();
			temp->GetChromosome()->GetGene()->mID = rand() % MaxInt;
			temp->SetStats();
			temp->SetPosition(Vector2D(tempx, tempy));
			mChromo.push_back(temp->GetChromosome());
			BaseAgent * newTemp = (BaseAgent*)temp;
			mAgentManager->AddAgent(newTemp);
			herbivore++;
		}
		for (int i = 0; i < 12; i++)
		{
			CarnivoreAgent * temp = new CarnivoreAgent("Carnivore", mRenderer);
			temp->LoadTexture("Characters/Character.bmp");
			float tempx, tempy;
			tempx = rand() % 875;
			tempy = rand() % 875;
			temp->SetPosition(Vector2D(tempx, tempy));
			//temp->GetChromosome()->GenerateGene();
			temp->GetChromosome()->SetGene(ChromosomeManager::GenerateGene());
			temp->GetChromosome()->GetGene()->mName = temp->GetName();
			temp->GetChromosome()->GetGene()->mID = rand() % MaxInt;
			temp->SetStats();
			mChromo.push_back(temp->GetChromosome());
			BaseAgent * newTemp = (BaseAgent*)temp;
			mAgentManager->AddAgent(newTemp);
			carnivore++;
		}
		XMLHandler::SaveList(0, mAgentManager->GetAgents()->size(), carnivore, herbivore);
		//XMLHandler::StoreGenes(mChromo);
	}
	else
	{
		int herb = 0;
		int carn = 0;
		for(int i = 0; i < mChromo.size();i++)
		{
			if(mChromo[i]->GetGene()->mName == "Herbivore")
			{
				HerbivoreAgent * temp = new HerbivoreAgent("Herbivore", mRenderer);
				temp->LoadTexture("Characters/Herbivore.bmp");
				float tempx, tempy;
				tempx = rand() % 875;
				tempy = rand() % 875;
				temp->SetChromosome(mChromo.at(i));
				temp->SetPosition(Vector2D(tempx, tempy));
				temp->SetStats();
				//mChromo.push_back(temp->GetChromosome());
				BaseAgent * newTemp = (BaseAgent*)temp;
				mAgentManager->AddAgent(newTemp);
				herb++;
			}
			else if(mChromo[i]->GetGene()->mName == "Carnivore")
			{
				CarnivoreAgent * temp = new CarnivoreAgent("Carnivore", mRenderer);
				temp->LoadTexture("Characters/Character.bmp");
				float tempx, tempy;
				tempx = rand() % 875;
				tempy = rand() % 875;
				temp->SetPosition(Vector2D(tempx, tempy));
				temp->SetChromosome(mChromo.at(i));
				temp->SetStats();
				//mChromo.push_back(temp->GetChromosome());
				BaseAgent * newTemp = (BaseAgent*)temp;
				mAgentManager->AddAgent(newTemp);
				carn++;
			}
		}
			XMLHandler::SaveList(0, mAgentManager->GetAgents()->size(), carn, herb);
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
