#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <map>
#include "TextureManager.h"

//niepotrzebny konstruktor
TextureManager::TextureManager()
{
}

//mapa z teksturami
std::map<std::string, sf::Texture*> TextureManager::textures;
//vector kolejnosc tekstur
std::vector<std::string> TextureManager::texture_order;


//zwraca dlugosc mapy textur
int TextureManager::Get_length()
{
	return textures.size();
}
//zwraca texture po indeksie
sf::Texture* TextureManager::Get_texture(int index)
{
	return Get_texture(texture_order.at(index));
}
//zwraca texture po nazwie
sf::Texture* TextureManager::Get_texture(std::string name)
{
	if (textures.find(name) != textures.end())
	{
		//std::cout << name << "\n";
		return textures[name];
	}
	else
	{
		return NULL
			;
	}
}

//wczytuje texture i wyrzuca na podstawie nazwy i sciezki(folder w ktorym jest obraz)
sf::Texture* TextureManager::Load_texture(std::string name, std::string pathname)
{
	sf::Texture* texture = new sf::Texture();
	if (texture->loadFromFile(pathname + "/" + name))
	{
		textures[name] = texture;
		texture_order.push_back(name);
		return textures[name];
	}
	else
	{
		delete texture;
		return NULL;
	}
	

}

//destruktor
TextureManager::~TextureManager()
{
	sf::Texture* texture;
	std::map<std::string, sf::Texture*>::iterator iterinho = textures.begin();
	while (iterinho != textures.end())
	{
		texture = iterinho->second;
		delete texture;
		iterinho++;
	}
}
