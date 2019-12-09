#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
class Background
{
private:
	sf::Sprite* sprite;
	sf::Sprite* sprite_cloud;
	float x;
	float x_cloud;
	float y_cloud;
public:
	Background();
	~Background();
	void Move();
	void Draw(sf::RenderWindow * window);
	void Clouds();
};