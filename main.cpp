#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include "Dino.h"
#include "Background.h"
#include "Obstacle.h"
#include "TextureManager.h"
#include "Game.h"
int main()
{
	Game* game = new Game();
	game->Run();
	delete game;
	
	return 0;
}