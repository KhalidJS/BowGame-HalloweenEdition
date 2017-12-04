#include <SFML\Graphics.hpp>
#include "GameObject.h"

using namespace sf;

class Arrow : public GameObject
{
public:
  Arrow(float gravity, std::string imagepath, sf::Vector2f position, sf::Vector2f scale, bool flip) : GameObject(gravity,imagepath,position,scale,flip){
  
    tex_arrow.loadFromFile(imagepath);
    spr_arrow.setTexture(tex_arrow);
    spr_arrow.setPosition(position);
    this->gravity = gravity;
    this->position = position;
    this->flipped = flip;
    if (flipped)
    {
      spr_arrow.setScale(-1, 1);
      speed = 2;
    }
    hit = false;
    this->gravity = 0.02;
  };
  Arrow();
  Vector2f position;
  Vector2f size;
  Texture tex_arrow;
  Sprite spr_arrow;
  double gravity;
  bool flipped;
  bool visible;
  float speed = -2;
  bool hit;
  Vector2f direction;
};