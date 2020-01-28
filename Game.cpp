#include "Game.h"

Game::Game()
{
	this->dinosaur = new Dino(255,255,255);
	this->background = new Background();
	this->obstacles = new  Obstacle*[7];
	for (int i = 0; i < 7; i++)
	{
		this->obstacles[i] = new Obstacle("Obstacle" + std::to_string(i));
	}
}


Game::~Game()
{

}

void Game::Run()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "Genetic Dino");
	int i = 0;
	srand(time(NULL));
	int k[4] = { 1,2,3,4 };
	int k2[4] = { 2,3,4 };
	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		if (obstacles[i]->is_behind())
		{
			i = (std::rand() % 7) + 0;
		}



		//this->dinosaur->Computer_control(200, k, 50, k2, obstacles[i]);
		this->dinosaur->Human_control();
		this->obstacles[i]->Move();
		this->background->Move();
		this->background->Clouds();
		this->dinosaur->is_Die(obstacles[i]);

		window.clear(sf::Color::White);
		this->background->Draw(&window);
		this->dinosaur->Draw(&window);
		this->obstacles[i]->Draw(&window);
		window.display();


	}
	
	return;




}