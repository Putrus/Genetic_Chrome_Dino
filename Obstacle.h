#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Obstacle
{
private:
	sf::Sprite* sprite;
	float x;
	float y;
	float collision_right;
	float collision_down;
public:
	Obstacle(std::string name);
	void Move();
	void Draw(sf::RenderWindow* window);
	//to collision with dino
	float get_x1();
	float get_x2();
	float get_y1();
	float get_y2();
	bool is_behind();

};