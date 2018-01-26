#include "aquarium.h"
#include "Drawer.h"
#include <iostream>
#include "Plankton.h"
#include "Herbivore.h"
#include "Predator.h"
void main()
{
	coordinates size(28,28,28);
	sf::RenderWindow window(sf::VideoMode(980, 980), "Aquarium", sf::Style::Close);
	window.setFramerateLimit(30);
	sf::Event e;
	const int UPDATING = 0, MODIFYING = 1;
	int state = MODIFYING;
	//Aquarium aquarium(coordinates(40, 30));
	///died
	sf::Font fontToDied;
	fontToDied.loadFromFile("CyrilicOld.ttf");
	sf::Text diedText("Aquarium died",fontToDied,150);
	diedText.setFillColor(sf::Color::Red);
	diedText.setPosition(size.first / 2,size.second/2);
	///
	int plan = 1;
	int count = 0;
	try
	{
		Aquarium aq(size);
		aq.randFill(100, 150, 150);
		std::string mapPath = "water.png";
		Drawer aquaDraw(window, size, mapPath);
		while (window.isOpen()) {
			
			while (window.pollEvent(e)) {
				if (e.type == sf::Event::Closed) {
					window.close();
				}

				if (e.type == sf::Event::KeyPressed) {

					switch (e.key.code) {
					case sf::Keyboard::Escape:
						window.close();
						break;
					case sf::Keyboard::Num1:
						plan = 1;
						break;
					case sf::Keyboard::Num2:
						plan = 2;
						break;
					case sf::Keyboard::Num3:
						plan = 3;
						break;
					case sf::Keyboard::Return:
						switch (state) {

						case UPDATING:
							state = MODIFYING;
							break;

						case MODIFYING:
							state = UPDATING;
							break;

						default:
							break;
						}
						break;

					case sf::Keyboard::Right: {
						state = UPDATING;
						break;
					}

					default:
						break;
					}
				}

				if (e.type == sf::Event::KeyReleased) {

					switch (e.key.code) {

					case sf::Keyboard::Right: {
						state = MODIFYING;
						break;
					}
					default:
						break;
					}
				}
			}
			window.clear();
			if (state == UPDATING) 
			{
				aq.update();	
				count++;
			}

			if (aq.isAlive())
			{
				aquaDraw.drawAquarium(plan);
				aquaDraw.drawOrganisms(aq.getListOfOrganisms(),plan);
			}
			else
			{
				window.draw(diedText);
				window.display();
				throw Exception(3);
			}

			aq.show();
			window.display();
			
			
			
		}
	}
	catch (Exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << count << std::endl;
	
	std::cin.get();
}
