#include "XMLHandler.h"

int** XMLHandler::LoadMapFromXML(std::string path)
{
	int ** tempMap;
	TiXmlDocument Doc;
	if (!Doc.LoadFile(path))
	{
		return nullptr;
	}
	TiXmlElement * root = Doc.FirstChildElement();
	if (!root)
	{
		Doc.Clear();
		return nullptr;
	}
	for (TiXmlElement * GroupElement = root->FirstChildElement("objectgroup"); GroupElement != NULL; GroupElement = GroupElement->NextSiblingElement())
	{
		std::string name = GroupElement->Attribute("name");
		if (name == "MapSeed")
		{
			int x = 0;
			int y = 0;
			int row = 0;
			int column = 0;

			for (TiXmlElement* objectElement = GroupElement->FirstChildElement("object"); objectElement != NULL; objectElement = objectElement->NextSiblingElement())
			{

				std::string name = objectElement->Attribute("name");
				if (name == "rowValue")
				{
					x = 0;
					std::istringstream ss(objectElement->Attribute("value"));

					int token;
					while (ss >> token)
					{
						//init map values x = token = token;
						row = token;
						if (ss.peek() == ',')
							ss.ignore();

						//Increment the x position.
						x++;
					}

				}
				if (name == "columnValue")
				{
					x = 0;
					std::istringstream ss(objectElement->Attribute("value"));

					int token;
					while (ss >> token)
					{
						//init map values x = token = token;
						column = token;
						if (ss.peek() == ',')
							ss.ignore();

						//Increment the x position.
						x++;
						tempMap = new int*[row - 1];
						for (int i = 0; i < row; i++)
						{
							tempMap[i] = new int[column];
						}
					}

				}

				if (name == "TileTypes")
				{
					//Reset x position of map to 0 at start of each element.
					x = 0;

					//Split up the comma delimited connections.

					std::istringstream ss(objectElement->Attribute("value"));

					int i;
					while (ss >> i)
					{
						tempMap[x][y] = i;

						if (ss.peek() == ',')
							ss.ignore();

						//Increment the x position.
						x++;
					}

					//Move down to the next y position in the map.
					y++;
				}
			}
		}
	}
	if (tempMap == NULL)
	{
		return nullptr;
	}
	return tempMap;



}

void XMLHandler::StoreGenes(std::string path, std::vector<Chromosome*> genes)
{
	TiXmlDocument * mDoc;
	TiXmlNode * root(mDoc->InsertEndChild(TiXmlElement("Genes")));
	
	for(int i = 0; i < genes.size(); i++)
	{
		TiXmlElement Gene("Gene");
		TiXmlElement Health("Health");
		Health.SetAttribute("Health", genes[i]->GetGene()->health);
		TiXmlElement MaxStamina("Stamina");
		MaxStamina.SetAttribute("Stamina", genes[i]->GetGene()->maxStamina);
		TiXmlElement MaxAge("Age");
		MaxAge.SetAttribute("Age", genes[i]->GetGene()->maxAge);
		TiXmlElement MaxSpeed("Speed");
		MaxSpeed.SetAttribute("Speed", genes[i]->GetGene()->maxSpeed);
		Gene.InsertEndChild(Health);
		Gene.InsertEndChild(MaxStamina);
		Gene.InsertEndChild(MaxAge);
		Gene.InsertEndChild(MaxSpeed);
		root->InsertEndChild(Gene);
	}
	mDoc->SaveFile(path);
}

std::vector<Chromosome*> XMLHandler::LoadChromosome(std::string path)
{
	std::vector<Chromosome*> Chromosomes;
	TiXmlDocument mDoc;
	if(!mDoc.LoadFile(path))
	{
		return Chromosomes;
	}
	TiXmlElement * root = mDoc.FirstChildElement();
	if(!root)
	{
		mDoc.Clear();
		return Chromosomes;
	}

	for(TiXmlElement * _Gene = root->FirstChildElement("Gene"); _Gene != NULL; _Gene = _Gene->NextSiblingElement())
	{
		Gene * _TempGene = new Gene();
		std::istringstream ss(_Gene->Attribute("Health"));
		float ss1;
		while(ss >> ss1)
		{
			_TempGene->health = ss1;
		}
		std::istringstream ssAge(_Gene->Attribute("Age"));
		float ss1Age;
		while(ssAge >> ss1Age)
		{
			_TempGene->maxAge = ss1Age;
		}
		std::istringstream ssSpeed(_Gene->Attribute("Speed"));
		float ss1Speed;
		while (ssSpeed >> ss1Speed)
		{
			_TempGene->maxSpeed = ss1Speed;
		}
		std::istringstream ssStamina(_Gene->Attribute("Stamina"));
		float ss1Stamina;
		while (ssStamina >> ss1Stamina)
		{
			_TempGene->maxStamina = ss1Stamina;
		}
		Chromosome * Temp = new Chromosome();
		Temp->SetGene(_TempGene);
		Chromosomes.push_back(Temp);
	}
	return Chromosomes;
}
