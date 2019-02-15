#ifndef AGENTMANAGER_H
#define AGENTMANAGER_H
#include "BaseAgent.h"
#include "HerbivoreAgent.h"
#include "CarnivoreAgent.h"
#include <vector>
#include "Commons.h"
#include <SDL.h>

class AgentManager
{
public:
	static AgentManager * Instance();
	void SetRenderer(SDL_Renderer * Renderer);
	void GenerateBaseAgents();
	void Update(float dt);
	void Draw();
	int CheckMousePolling(Vector2D mousepos);
	std::vector<BaseAgent*> * GetAgents() { return mAgents; }

private:
	static AgentManager * mInstance;
	SDL_Renderer * mRenderer;
	std::vector<BaseAgent*>* mAgents = new std::vector<BaseAgent*>();
	void KillAgents(int index);
	AgentManager();
	~AgentManager();


};

#endif


