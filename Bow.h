#include "GameObject.h"

class Bow : public GameObject
{
public:
  Bow(float gravity, std::string imagepath, sf::Vector2f position, sf::Vector2f scale, bool flip) : GameObject(gravity, imagepath, position, scale, flip){ startposition = position; };
  Bow();
  sf::Vector2f startposition;

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
    target.draw(msprite);
  }
};