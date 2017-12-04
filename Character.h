#include "Bow.h"
#include "HealthBar.h"
#include "Arrow.h"

class Character : public GameObject
{
public:
  Character(float gravity, std::string imagepath, sf::Vector2f position, sf::Vector2f scale, bool flip) : GameObject(gravity, imagepath, position, scale, flip)
  {
    WeaponSlot = new Bow(1, "gameArrow/bow.png", sf::Vector2f(position.x, position.y), sf::Vector2f(1, 1), flip);
    healthbar = new HealthBar(position, 10);
    arrow = new Arrow(0, "gameArrow/arrow.png", position,sf::Vector2f(1,1), flip);
  }
  Character();
  //~Character();
  void Update(__int64 deltatime);
  void FireArrow(int minPower, int maxPower);
  void ArrowAngle(int minDegrees, int maxDegrees);
  void hit();
  Bow *WeaponSlot;
  sf::Vector2f weaponOffSet;
  HealthBar *healthbar;
  Arrow *arrow;
  RectangleShape collisionBox;
  bool DEAD;
  int ID;
};