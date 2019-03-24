#ifndef AGENTMANAGER_H
#define AGENTMANAGER_H
#include "BaseAgent.h"
#include <vector>
#include "Commons.h"
#include "ChromosomeManager.h"
#include <SDL.h>

class BaseAgent;
class ChromosomeManager;

class AgentManager
{
public:
	static AgentManager * Instance();
	void SetRenderer(SDL_Renderer * Renderer);
	void Update(float dt);
	void Draw();
	BaseAgent * CheckMousePolling(Vector2D mousepos);
	std::vector<BaseAgent*> * GetAgents() { return mAgents; }
	std::vector<BaseAgent*> GetVisibleAgents(BaseAgent * Looking);
	void AddAgent(BaseAgent * Agent) { mAgents->push_back(Agent); }
	void CheckForChildGenerationCollision(BaseAgent * mAgent);
	void SavePeriodically();
	


private:
	static AgentManager * mInstance;
	SDL_Renderer * mRenderer;
	std::vector<BaseAgent*>* mAgents = new std::vector<BaseAgent*>();
	void KillAgents(int index);
	AgentManager();
	~AgentManager();
	float mPeriodWait = 0;


};

#endif


