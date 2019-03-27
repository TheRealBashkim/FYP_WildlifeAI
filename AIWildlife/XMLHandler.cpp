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

void XMLHandler::StoreGenes(std::vector<Chromosome*> genes)
{
	TiXmlDocument  mDoc;
	TiXmlNode * Root(mDoc.InsertEndChild(TiXmlElement("Genes")));

	for(int i = 0; i < genes.size(); i++)
	{
		TiXmlElement _Gene("Gene");
		_Gene.SetAttribute("ID", genes[i]->GetGene()->mID);
		_Gene.SetAttribute("Name", genes[i]->GetGene()->mName);
		_Gene.SetAttribute("Health", genes[i]->GetGene()->health);
		_Gene.SetAttribute("MaxAge", genes[i]->GetGene()->maxAge);
		_Gene.SetAttribute("CurrentAge", genes[i]->GetGene()->mCurrentAge);
		_Gene.SetAttribute("Speed", genes[i]->GetGene()->maxSpeed);
		_Gene.SetAttribute("MaxStamina", genes[i]->GetGene()->maxStamina);
		_Gene.SetAttribute("CurrentStamina", genes[i]->GetGene()->mCurrentStamina);
		_Gene.SetAttribute("Gender", genes[i]->GetGene()->mGender);
		Root->InsertEndChild(_Gene);
	}
	mDoc.SaveFile("TempChromosome.xml");
	std::string FileName = "Chromosome.xml";
	if (remove(FileName.c_str()) != 0)
	{
		
	}
	rename("TempChromosome.xml", FileName.c_str());  

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

		_TempGene->mName = _Gene->Attribute("Name");

		std::istringstream ssID(_Gene->Attribute("ID"));
		float ss1ID;
		while (ssID >> ss1ID)
		{
			_TempGene->mID = ss1ID;
		}


		std::istringstream ss(_Gene->Attribute("Health"));
		float ss1;
		while(ss >> ss1)
		{
			_TempGene->health = ss1;
		}
		std::istringstream ssAge(_Gene->Attribute("MaxAge"));
		float ss1Age;
		while(ssAge >> ss1Age)
		{
			_TempGene->maxAge = ss1Age;
		}
		std::istringstream ssAgeCurrent(_Gene->Attribute("CurrentAge"));
		float ss1AgeCurrent;
		while (ssAgeCurrent >> ss1AgeCurrent)
		{
			_TempGene->mCurrentAge = ss1AgeCurrent;
		}
		std::istringstream ssSpeed(_Gene->Attribute("Speed"));
		float ss1Speed;
		while (ssSpeed >> ss1Speed)
		{
			_TempGene->maxSpeed = ss1Speed;
		}
		std::istringstream ssStamina(_Gene->Attribute("MaxStamina"));
		float ss1Stamina;
		while (ssStamina >> ss1Stamina)
		{
			_TempGene->maxStamina = ss1Stamina;
		}
		std::istringstream ssStaminaCurrent(_Gene->Attribute("CurrentStamina"));
		float ss1StaminaCurrent;
		while (ssStaminaCurrent >> ss1StaminaCurrent)
		{
			_TempGene->mCurrentStamina = ss1StaminaCurrent;
		}

		_TempGene->mGender = _Gene->Attribute("Gender");

		Chromosome * Temp = new Chromosome();
		Temp->SetGene(_TempGene);
		Chromosomes.push_back(Temp);
	}
	return Chromosomes;
}

void XMLHandler::AddGene(std::string path, Gene* gene)
{
	TiXmlDocument  mDoc;
	//mDoc.LoadFile(path);
	if(!mDoc.LoadFile("Fitness.xml"))
	{
		TiXmlNode * Root(mDoc.InsertEndChild(TiXmlElement("Genes")));
		TiXmlElement _Gene("Gene");
		_Gene.SetAttribute("ID", gene->mID);
		_Gene.SetAttribute("Name", gene->mName);
		_Gene.SetAttribute("Health", gene->health);
		_Gene.SetAttribute("MaxAge", gene->maxAge);
		_Gene.SetAttribute("CurrentAge", gene->mCurrentAge);
		_Gene.SetAttribute("Speed", gene->maxSpeed);
		_Gene.SetAttribute("MaxStamina", gene->maxStamina);
		_Gene.SetAttribute("CurrentStamina", gene->mCurrentStamina);
		_Gene.SetAttribute("Gender", gene->mGender);
		Root->InsertEndChild(_Gene);
		mDoc.SaveFile(path);
		return;
	}
	TiXmlNode * Root  = mDoc.FirstChildElement("Genes");
	TiXmlElement _Gene("Gene");
	_Gene.SetAttribute("ID", gene->mID);
	_Gene.SetAttribute("Name", gene->mName);
	_Gene.SetAttribute("Health", gene->health);
	_Gene.SetAttribute("MaxAge", gene->maxAge);
	_Gene.SetAttribute("CurrentAge", gene->mCurrentAge);
	_Gene.SetAttribute("Speed", gene->maxSpeed);
	_Gene.SetAttribute("MaxStamina", gene->maxStamina);
	_Gene.SetAttribute("CurrentStamina", gene->mCurrentStamina);
	_Gene.SetAttribute("Gender", gene->mGender);
	Root->InsertEndChild(_Gene);
	mDoc.SaveFile(path);

}

void XMLHandler::SaveFitness(Gene * gene)
{
	TiXmlDocument mDoc;
		mDoc.LoadFile("Fitness.xml");
		TiXmlNode * Root(mDoc.InsertEndChild(TiXmlElement("Fitness")));
		TiXmlElement _Gene("Gene");
		_Gene.SetAttribute("ID", gene->mID);
		_Gene.SetAttribute("Name", gene->mName);
		_Gene.SetAttribute("Health", gene->health);
		_Gene.SetAttribute("Age Of Death", gene->mCurrentAge);
		_Gene.SetAttribute("Max Speed", gene->maxSpeed);
		_Gene.SetAttribute("Max Stamina", gene->mCurrentStamina);
		_Gene.SetAttribute("Gender", gene->mGender);
		std::string temp = std::to_string(ChromosomeManager::GenerateFitnessOfChromosome(gene)) + " / 100";
		_Gene.SetAttribute("Fitness of Gene", temp);
		Root->InsertEndChild(_Gene);
		mDoc.SaveFile("Fitness.xml");
}
