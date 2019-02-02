#include "Character.h"


Character::Character()
{
  
}

void Character::hit()
{
  healthbar->rs.setSize(Vector2f(healthbar->rs.getSize().x - 25,healthbar->rs.getSize().y));
  if (healthbar->rs.getSize().x == 0)
  {
    DEAD = true;
    std::cout << "True";
    
  }
  
}