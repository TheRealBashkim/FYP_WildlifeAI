#ifndef AGENTMANAGER_H
#define AGENTMANAGER_H
#include "BaseAgent.h"
#include <vector>
#include "Commons.h"
#include <SDL.h>

class BaseAgent;

class AgentManager
{
public:
	static AgentManager * Instance();
	void SetRenderer(SDL_Renderer * Renderer);
	void Update(float dt);
	void Draw();
	int CheckMousePolling(Vector2D mousepos);
	std::vector<BaseAgent*> * GetAgents() { return mAgents; }
	std::vector<BaseAgent*> GetVisibleAgents(BaseAgent * Looking);
	void AddAgent(BaseAgent * Agent) { mAgents->push_back(Agent); }

private:
	static AgentManager * mInstance;
	SDL_Renderer * mRenderer;
	std::vector<BaseAgent*>* mAgents = new std::vector<BaseAgent*>();
	void KillAgents(int index);
	AgentManager();
	~AgentManager();


};

#endif


