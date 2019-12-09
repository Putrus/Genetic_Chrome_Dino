#include <iostream>
#include <SFML/Graphics.hpp>
#include "Dino.h"
#include "Background.h"
#include "Obstacle.h"
#include "TextureManager.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "Genetic Dino");
	
	Dino dinosaur;
	Background * background = new Background();
	Obstacle obstacle("Double_kaktus");
	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		//{
			dinosaur.Human_control();
			obstacle.Move();
			background->Move();
			background->Clouds();
		//}
			dinosaur.is_Die(&obstacle);
			
		window.clear(sf::Color::White);
		background->Draw(&window);
		dinosaur.Draw(&window);
		obstacle.Draw(&window);
		window.display();


	}
	delete background;
	return 0;
}