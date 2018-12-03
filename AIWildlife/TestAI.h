#ifndef TESTAI_H
#define TESTAI_H
#include "BaseAgent.h"
#include <algorithm>
class TestAI : BaseAgent
{
public:
	TestAI(SDL_Renderer * Renderer);
	~TestAI();
	void Update(float dt, SDL_Event e);
	void Render();
	void LoadTexture(std::string path);
	void DrawFeelers();
	void SetPosition(Vector2D position) { BaseAgent::SetPosition(position); }
	Vector2D GetPosition();
	Vector2D Seek(Vector2D TargetPosition);
	Vector2D Flee(Vector2D TargetPosition);
	Vector2D Arrive(Vector2D TargetPosition);
private:
	Vector2D temp = GetPosition();


};

#endif


