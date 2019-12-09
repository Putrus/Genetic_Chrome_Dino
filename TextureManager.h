#pragma once
class TextureManager {

private:
	//zaladowane tekstury
	static std::map<std::string, sf::Texture*> textures;

	//kolejnosc do sledzenia tekstur(ich indeksow)
	static std::vector<std::string> texture_order;
	//konstruktor niepotrzebny
	TextureManager();

public:
	//destruktor
	~TextureManager();
	
	//zwraca ilosc tekstur w textures
	static int Get_length();
	//zwraca texture po indeksie
	static sf::Texture * Get_texture(int index);
	//zwraca texture po nazwie
	static sf::Texture * Get_texture(std::string name);
	
	
	//zwraca wskaznik do zaladowanej tekstury
	//jesli nie znajdzie pliku zwraca NULL
	static sf::Texture * Load_texture(std::string name, std::string pathname);


};