#pragma once
#include "Background.h"
#include "TextureManager.h"
Background::Background()
{
	this->sprite = new sf::Sprite();
	this->sprite_cloud = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::Load_texture("Background.png", "Images"));
	this->sprite_cloud->setTexture(*TextureManager::Load_texture("Cloud.png", "Images"));
	this->x = 0;
	this->x_cloud = 920;
	this->y_cloud = 60;
}
Background::~Background()
{
	delete this->sprite;
}
void Background::Move()
{
	this->x -= 0.5;
	if (this->x == -2700)
	{
		this->x = 0;
	}

	this->sprite->setPosition(x, 440);

}
void Background::Draw(sf::RenderWindow* window)
{
	window->draw(*this->sprite);	
	window->draw(*this->sprite_cloud);
}

void Background::Clouds()
{
	this->x_cloud -= 0.1;
	if (this->x_cloud < -200)
	{
		
		this->y_cloud = (float)(std::rand() % 300) + 100;
		this->x_cloud = 920;
		
	}
	this->sprite_cloud->setPosition(this->x_cloud, this->y_cloud);

}