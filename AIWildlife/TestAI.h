#ifndef TESTAI_H
#define TESTAI_H
#include "BaseAgent.h"
class TestAI : BaseAgent
{
public:
	TestAI(SDL_Renderer * Renderer);
	~TestAI();
	void Update(float dt, SDL_Event e) override;
	void Render();
	void DrawFeelers();
	Vector2D Seek(Vector2D TargetPosition);


};

#endif


