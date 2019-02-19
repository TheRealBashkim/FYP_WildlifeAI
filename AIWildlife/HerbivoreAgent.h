#ifndef HERBIVOREAGENT_H
#define HERBIVOREAGENT_H
#include "BaseAgent.h"
#include <SDL.h>
#include <algorithm>
class HerbivoreAgent : BaseAgent
{
public:
	HerbivoreAgent(std::string name,SDL_Renderer * Renderer);
	~HerbivoreAgent();
	void Update(float dt) override;
	void Render() override;
	void LoadTexture(std::string path);
	void SetPosition(Vector2D position) { BaseAgent::SetPosition(position); }
	Vector2D GetPosition();
	Vector2D Seek(Vector2D TargetPosition);
	Vector2D Flee(Vector2D TargetPosition);
	Vector2D Arrive(Vector2D TargetPosition);
	Vector2D Wander(float dt);
	Vector2D WallAvoidance();

private:
};
#endif


