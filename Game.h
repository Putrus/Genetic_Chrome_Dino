#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Dino.h"
#include "Background.h"
#include "Obstacle.h"
#include "TextureManager.h"
class Game
{
private:
	Dino* dinosaur;
	Obstacle** obstacles;
	Background* background;

public:
	Game();
	~Game();
	void Run();




};