#include <iostream>
#include <fstream>
#include <string>
#include <SFML\Graphics.hpp>
#include <sstream>
#include <stdio.h>
#include <vector>
#include "Character.h"

class Map
{
public:
  Map(sf::Vector2f position, float tilesize, std::string loadmap);
  std::vector<sf::Sprite> Tiles;
  std::vector<Character> Players;
private:
  std::vector<std::string> tilelocations;
  sf::Texture texture_tile[20];
  sf::Sprite sprite_tile;
};