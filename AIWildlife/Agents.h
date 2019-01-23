#ifndef AGENTS_H
#define AGENTS_H
#include "BaseAgent.h"
#include <algorithm>
class Agents : BaseAgent
{
public:
	Agents(SDL_Renderer * Renderer);
	~Agents();
	void Update(float dt, SDL_Event e);
	void Render();
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
	Vector2D temp = GetPosition();
	float counter = 0;


};

#endif


