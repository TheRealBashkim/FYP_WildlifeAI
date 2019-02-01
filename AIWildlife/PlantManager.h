#ifndef PLANTMANAGER_H
#define PLANTMANAGER_H
#include <vector>
#include "SDL.h"
#include "Plant.h"
#include "Agents.h"
class PlantManager
{
public:
	PlantManager(SDL_Renderer * _Renderer);
	~PlantManager();
	void Update(std::vector<Agents*>* Agents);
	void Draw();
	void SpawnNewItem();

private:
	SDL_Renderer * mRenderer;
	std::vector<Plant>* mPlantList = new std::vector<Plant>();


};
#endif

