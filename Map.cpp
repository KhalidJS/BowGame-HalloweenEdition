#include "Map.h"
#include <iostream>
#include <sstream>


Map::Map(sf::Vector2f position, float size, std::string loadMap)
{
  tilelocations.push_back("gameArrow/png/Tiles/Tile.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile1.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile2.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile3.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile4.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile5.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile6.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile7.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile8.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile9.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile10.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile11.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile12.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile13.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile14.png");
  tilelocations.push_back("gameArrow/png/Tiles/Tile15.png");


  std::string str;

  std::ifstream infile;
  infile.open(loadMap);
  int count = 0;
  while (!infile.eof())
  {
    int n = 0;

    std::getline(infile, str);
    //std::cout << str << std::endl;
    std::istringstream ss(str);
    std::string var;
    while (std::getline(ss, var, ','))
    {
      if (var == "x")
      {
        position.x += size;
        //count++;
        //std::cout << "posX: " << position.x << std::endl;
      }

      if (isdigit(var[0]))
      {
        n = std::stoi(var);
        texture_tile[n].loadFromFile(tilelocations[n]);
        //std::cout << "n: " << n << std::endl;
        sf::Sprite sp;
        sp.setTexture(texture_tile[n]);
        sp.setPosition(position);
        Tiles.push_back(sp);
        position.x += size;

        //std::cout << "posX: " << position.x << std::endl;
      }
      if (var == "pt")
      {
        Character *obj = new Character(1, "gameArrow/carector2/png/male/Idle1.png", sf::Vector2f(position.x, position.y), sf::Vector2f(0.5f, 0.5f), true);
        float height = obj->msprite.getLocalBounds().height * obj->msprite.getScale().y;
        obj->msprite.setPosition(sf::Vector2f(position.x + (obj->msprite.getLocalBounds().width) - 290, (position.y - (height / 2))));
        obj->WeaponSlot->msprite.setPosition(position.x - 65, position.y);
        obj->WeaponSlot->msprite.setOrigin(11, 46);
        obj->healthbar->rs.setPosition(position.x + 30, position.y + 130);
        obj->healthbar->rs.setSize(Vector2f(100, 25));
        obj->healthbar->rs.setFillColor(Color::Green);
        obj->collisionBox.setPosition(position.x - 30, position.y - 100);
        obj->collisionBox.setSize(Vector2f(125, 220));
        //obj->collisionBox.setFillColor(Color::Color(0, 255, 0, 128));
        obj->collisionBox.setFillColor(Color::Transparent);
        obj->ID = count;
        count++;

        //obj->msprite.setColor(Color::Transparent);
        obj->DEAD = false;
        Players.push_back(*obj);
        position.x += size;
      }
      if (var == "po")
      {
        Character *obj = new Character(1, "gameArrow/carector1/png/Idle1.png", sf::Vector2f(position.x, position.y), sf::Vector2f(0.3f, 0.3f), false);
        float h = obj->msprite.getLocalBounds().height * obj->msprite.getScale().y;
        obj->msprite.setPosition(sf::Vector2f(position.x + -110, ((position.y - (h / 2)) + 20)));
        obj->WeaponSlot->msprite.setPosition(position.x - 10 + 75, position.y + 30);
        obj->WeaponSlot->msprite.setOrigin(11, 46);
        obj->healthbar->rs.setPosition(position.x - 100, position.y + 130);
        obj->healthbar->rs.setSize(Vector2f(100, 25));
        obj->healthbar->rs.setFillColor(Color::Green);
        obj->arrow->spr_arrow.setPosition(obj->WeaponSlot->msprite.getPosition().x, position.y + 25);
        obj->collisionBox.setPosition(obj->msprite.getPosition().x, obj->msprite.getPosition().y + 35);
        obj->collisionBox.setSize(Vector2f(145, 205));
        //obj->collisionBox.setFillColor(Color::Color(0, 255, 0, 128));
        obj->collisionBox.setFillColor(Color::Transparent);
        obj->DEAD = false;
        obj->ID = count;
        count++;
        Players.push_back(*obj);
        position.x += size;
      }

      if (var == "n")
      {
        position.y += size;
        position.x = 0;
        //std::cout << "PosY: " << position.y << std::endl;
      }

    }

    //std::cout << "Count: " << count << std::endl;
    //std::cout << str << std::endl;
  }
  infile.close();
}