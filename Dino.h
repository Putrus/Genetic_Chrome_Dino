#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Obstacle.h"
class Dino
{
private:
	sf::Sprite* sprite;
	float x;
	float y;
	float gravitation;
	float velocity;
	float velocity_0;
	float timer;
	bool is_jump;
	bool is_down;
	bool foot;
	clock_t start;
	clock_t stop;
	float delay_time;

	float collision_x1;
	float collision_x2;
	float collision_y1;
	float collision_y2;
	bool isin_array(int obst[], Obstacle* obstacle);

public:
	Dino(int r, int g, int b);
	~Dino();
	void Draw(sf::RenderWindow* window);
	void Move();
	void Jump();
	void Bend_down();
	void Human_control();
	void is_Die(Obstacle * obstacle);
	void Computer_control(int dist_jump, int obst_jump[], int dist_bend, int obst_bend[], Obstacle * obstacle);
};