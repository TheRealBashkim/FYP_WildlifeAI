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
