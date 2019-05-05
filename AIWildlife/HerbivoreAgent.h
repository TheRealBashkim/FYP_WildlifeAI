#ifndef HERBIVOREAGENT_H
#define HERBIVOREAGENT_H
#include "BaseAgent.h"
#include <SDL.h>
#include <algorithm>
#include "PlantManager.h"
class HerbivoreAgent : public BaseAgent
{
public:
	HerbivoreAgent(std::string name,SDL_Renderer * Renderer);
	~HerbivoreAgent();
	void Update(float dt) override;
	void Render() override;
	void LoadTexture(std::string path);
	void SetPosition(Vector2D position) { BaseAgent::SetPosition(position); }
	void GetVisiblePlants(std::vector<Plant*> mPlant);
	void NeuralInput();
	Vector2D GetPosition();
	Vector2D Seek(Vector2D TargetPosition);
	Vector2D Flee(Vector2D TargetPosition);
	Vector2D Arrive(Vector2D TargetPosition);
	Vector2D Wander(float dt);
	Vector2D WallAvoidance();


private:
	std::vector<Plant*> mPlantsIcanSee;
};
#endif


