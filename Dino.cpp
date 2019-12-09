#pragma once
#include "Dino.h"
#include "TextureManager.h"
#include <windows.h>
Dino::Dino()
{
	this->sprite = new sf::Sprite();
	for (int i = 1; i < 7; i++)
	{
		TextureManager::Load_texture(std::to_string(i) + ".png", "Images/Dino");
	}
	this->sprite->setTexture(*TextureManager::Get_texture("2.png"));
	this->sprite->setScale(0.8, 0.8);
	this->velocity = 0;
	this->gravitation = 0.005;
	this->timer = 0;
	this->is_jump = 0;
	this->x = 50;
	this->y = 335;
	this->sprite->setPosition(this->x,this->y);
	this->foot = true;
	this->delay_time = 0;
	this->collision_x1 = this->x + 40;
	this->collision_x2 = this->x + 135;
	this->collision_y1 = this->y + 40;
	this->collision_y2 = this->y + 140;
}
Dino::~Dino()
{
	delete this->sprite;
}
void Dino::Draw(sf::RenderWindow* window)
{
	window->draw(*this->sprite);
}

void Dino::Move()
{
	if (this->is_down == 1)
	{
		if (this->foot && this->is_jump == 0 && this->delay_time > 10)
		{
			this->sprite->setTexture(*TextureManager::Get_texture("5.png"));
			this->foot = false;
			this->start = clock();
			this->collision_x1 = this->x + 50;
			this->collision_x2 = this->x + 176;
			this->collision_y1 = this->y + 84;
			this->collision_y2 = this->y + 140;
		}

		else if (this->foot == false && this->is_jump == 0 && this->delay_time > 10)
		{
			this->sprite->setTexture(*TextureManager::Get_texture("6.png"));
			this->foot = true;
			this->start = clock();
			this->collision_x1 = this->x + 40;
			this->collision_x2 = this->x + 135;
			this->collision_y1 = this->y + 40;
			this->collision_y2 = this->y + 140;
		}
	}
	else
	{

		if (this->foot && this->is_jump == 0 && this->delay_time > 10)
		{
			this->sprite->setTexture(*TextureManager::Get_texture("1.png"));
			this->foot = false;
			this->start = clock();
			this->collision_x1 = this->x + 40;
			this->collision_x2 = this->x + 135;
			this->collision_y1 = this->y + 40;
			this->collision_y2 = this->y + 140;
		}

		else if (this->foot == false && this->is_jump == 0 && this->delay_time > 10)
		{
			this->sprite->setTexture(*TextureManager::Get_texture("2.png"));
			this->foot = true;
			this->start = clock();
			this->collision_x1 = this->x + 40;
			this->collision_x2 = this->x + 135;
			this->collision_y1 = this->y + 40;
			this->collision_y2 = this->y + 140;
		}
	}
	if (this->is_jump == 1)
	{
		this->sprite->setTexture(*TextureManager::Get_texture("3.png"));
		this->velocity = this->velocity_0 + (this->gravitation * timer);
		this->y += velocity;
		this->sprite->setPosition(this->x, this->y);
		this->timer++;
		this->collision_x1 = this->x + 40;
		this->collision_x2 = this->x + 135;
		this->collision_y1 = this->y + 40;
		this->collision_y2 = this->y + 140;
	}
	if (this->y > 333.6 && this->y < 336.4)
	{
		this->velocity_0 = 0;
		this->timer = 0;
		this->is_jump = 0;
	}
}

void Dino::Jump()
{
	this->velocity_0 = -2;
	this->is_jump = 1;
}
void Dino::Bend_down()
{
	this->is_down = 1;
}

void Dino::Human_control()
{
	this->stop = clock();
	this->delay_time = (float)((this->stop - this->start) / (CLOCKS_PER_SEC / 100));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->Bend_down();
	}
	else
	{
		this->is_down = 0;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && this->is_jump == 0)
	{
		this->Jump();
	}
	this->Move();
}

void Dino::is_Die(Obstacle * obstacle)
{
	if (obstacle->get_x1() < this->collision_x2 && obstacle->get_x2() > this->collision_x1&& obstacle->get_y1() < this->collision_y2&& obstacle->get_y2() > this->collision_y1)
	{
		this->sprite->setTexture(*TextureManager::Get_texture("4.png"));
	}
}

void Dino::Computer_control()
{

}