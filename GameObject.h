#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

#pragma once

class GameObject : public sf::Drawable
{
public:
  GameObject(float gravity, std::string imagepath, sf::Vector2f position, sf::Vector2f scale, bool flip);
  GameObject();
  void Update(__int64 deltatime);
  sf::Vector2f mposition;
  sf::Sprite msprite;
  

private:
  sf::Texture mtexture;
  sf::Image mimage;
  sf::Vector2f scale;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
    target.draw(msprite);
  }
};