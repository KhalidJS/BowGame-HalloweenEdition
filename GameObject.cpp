#include "GameObject.h"

GameObject::GameObject(float gravity, std::string imagepath, sf::Vector2f position, sf::Vector2f scale, bool flip)
{
  mtexture.loadFromFile(imagepath);
  msprite.setTexture(mtexture);
  msprite.setPosition(position);
  this->scale = scale;
  msprite.setScale(this->scale);
  this->mposition = position;
  //msprite.setOrigin(sf::Vector2f(msprite.getLocalBounds().width / 2,msprite.getLocalBounds().height / 2));
  if (flip) msprite.scale(-1, 1);
}

GameObject::GameObject()
{

}

void GameObject::Update(__int64 deltatime)
{

}

