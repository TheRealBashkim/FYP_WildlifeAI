#ifndef CARNIVOREAGENT_H
#define CARNIVOREAGENT_H
#include "BaseAgent.h"
#include <SDL.h>
#include <algorithm>

class CarnivoreAgent : BaseAgent
{
public:
	CarnivoreAgent(std::string name,SDL_Renderer * Renderer);
	~CarnivoreAgent();
	void Update(float dt) override;
	void Render() override;
	void LoadTexture(std::string path);
	void DrawFeelers();
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


