#include "Drawer.h"
const int SIZE = 35;
Drawer::~Drawer()
{
}
Drawer::Drawer(sf::RenderWindow& renderWindow, coordinates size, std::string aquaImagePath)
{
	map.loadFromFile(aquaImagePath);
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	this->renderWindow = &renderWindow;
	this->size = size;
	this->fontToPlan.loadFromFile("CyrilicOld.ttf");
	this->planText1 = sf::Text("Y/X", fontToPlan, 40);
	planText1.setFillColor(sf::Color::Green);
	planText1.setPosition(0, 0);
	this->planText2 = sf::Text("Z/X", fontToPlan, 40);
	planText2.setFillColor(sf::Color::Green);
	planText2.setPosition(0, 0);
	this->planText3 = sf::Text("Z/Y", fontToPlan, 40);
	planText3.setFillColor(sf::Color::Green);
	planText3.setPosition(0, 0);

}
bool Drawer::animationUpdate(std::list<Organism*>&listOfOrganisms, float time)
{
	bool flag = false;///���� true �� ����� ������������
	for (auto i : listOfOrganisms)
	{
		if ((i->getPrevLocation().first != i->getLocation().first)&
			(i->getPrevLocation().second != i->getLocation().second)&
			(i->getPrevLocation().third != i->getLocation().third))
		{
			float x = i->getPrevLocation().first;
			float y = i->getPrevLocation().second;
			float y2 = i->getLocation().second;
			float x2 = i->getLocation().first;
			float z = i->getPrevLocation().third;
			float z2 = i->getLocation().third;
			float distance = sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y));

			if (distance > 2)
			{
				x += speed*time*(x2 - x) / distance;//���� �� ���� � ������� ������� �������
				y += speed*time*(y2 - y) / distance;//���� �� ������ ��� ��
				z += speed*time*(z2 - z) / distance;
				coordinates coor(x, y, z);
				i->setPrevLocation(coor);
				flag = true;
			}
		}
	}
	return flag;
}
void Drawer::diedAnimation()
{
	sf::Font fontToDied;
	fontToDied.loadFromFile("CyrilicOld.ttf");
	sf::Text diedText("Aquarium died", fontToDied, 150);
	diedText.setFillColor(sf::Color::Red);
	diedText.setPosition(size.first / 2, size.second / 2);
	renderWindow->draw(diedText);
}
void Drawer::drawOrganisms(std::list<Organism*>& listOfOrganisms,int plan)
{
	//std::cout << "\n\n"<<listOfOrganisms.size()<<"   ";
	if (plan == 1)
	{
		for (auto i : listOfOrganisms)
		{
			sf::Sprite sp = i->getSprite();
			sp.setPosition(i->getPrevLocation().first*SIZE, i->getPrevLocation().second*SIZE);
			renderWindow->draw(sp);
		}
	}
	else if (plan == 2) 
	{
		for (auto i :listOfOrganisms)
		{
			sf::Sprite sp = i->getSprite();
			sp.setPosition(i->getPrevLocation().first*SIZE, i->getPrevLocation().third*SIZE);
			renderWindow->draw(sp);
			//std::cout << i->getLocation().first << "-" << i->getLocation().third << "  ";
		}
	}
	else
	{
		for (auto i : listOfOrganisms)
		{
			sf::Sprite sp = i->getSprite();
			sp.setPosition(i->getPrevLocation().second*SIZE, i->getPrevLocation().third*SIZE);
			renderWindow->draw(sp);
			//std::cout << i->getLocation().second << "-" << i->getLocation().third << "  ";
		}
	}
}
void Drawer::drawAquarium(int plan)
{	
	if (plan == 1)
	{
		for (int i = 0; i < size.second; i++)
		{
			for (int j = 0; j < size.first; j++)
			{
				s_map.setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
				s_map.setPosition(j * SIZE, i * SIZE);
				renderWindow->draw(s_map);
				renderWindow->draw(planText1);
			}
		}
	}
	else if (plan == 2)
	{
		for (int i = 0; i < size.third; i++)
		{
			for (int j = 0; j < size.first; j++)
			{
				s_map.setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
				s_map.setPosition(j * SIZE, i * SIZE);
				renderWindow->draw(s_map);
				renderWindow->draw(planText2);
			}
		}
	}
	else
	{
		for (int i = 0; i < size.third; i++)
		{
			for (int j = 0; j < size.second; j++)
			{
				s_map.setTextureRect(sf::IntRect(0, 0, SIZE, SIZE));
				s_map.setPosition(j * SIZE, i * SIZE);
				renderWindow->draw(s_map);
				renderWindow->draw(planText3);
			}
		}
	}
	
}
