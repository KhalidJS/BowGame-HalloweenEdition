#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
  sf::Image img1;
  img1.loadFromFile("gameArrorw/png/BG.png");
  sf::Texture tex1;
  tex1.loadFromImage(img1);
  sf::Sprite spr1;
  spr1.setTexture(tex1);
  _mGraphics["Back"] = spr1;
}