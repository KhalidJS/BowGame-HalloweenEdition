#include <SFML\Graphics.hpp>

using namespace sf;

class HealthBar
{
public:
  HealthBar(Vector2f position, int health);
  HealthBar();
  void Update(__int64 deltatime);
  void SetRectangleShape();
  RectangleShape rs;
  int currentHealth;
  int Health;
private:
  Vector2f position;
  Vector2f size;
  Color rectColor;
};