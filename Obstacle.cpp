#include "Obstacle.h"
#include "TextureManager.h"
Obstacle::Obstacle(std::string name)
{
	this->sprite = new sf::Sprite();
	TextureManager::Load_texture(name + ".png", "Images");
	this->sprite->setTexture(*TextureManager::Get_texture(name + ".png"));
	this->sprite->setPosition(x, y);
	this->sprite->setScale(0.8, 0.8);
	this->x = 1000;
	this->y = 500 - this->sprite->getTextureRect().height;
}
void Obstacle::Move()
{
	this->x -= 0.5;
	this->sprite->setPosition(x, y);
	this->collision_right = (this->sprite->getPosition().x + this->sprite->getTextureRect().width) - 10;
	this->collision_down = (this->sprite->getPosition().y + this->sprite->getTextureRect().height) + 10;
	if (this->x == -300)
	{
		this->x = 1000;
	}
}

void Obstacle::Draw(sf::RenderWindow* window)
{
	window->draw(*this->sprite);
}


float Obstacle::get_x1()
{
	return this->sprite->getPosition().x;
}
float Obstacle::get_x2()
{
	return this->collision_right;
}
float Obstacle::get_y1()
{
	return this->sprite->getPosition().y;
}
float Obstacle::get_y2()
{
	return this->collision_down;
}