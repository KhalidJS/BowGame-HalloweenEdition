#include "HealthBar.h"
#include <time.h>
#include <stdio.h>

HealthBar::HealthBar(Vector2f position,int health)
{
  this->Health = health;
  this->currentHealth = health - 1;
  this->size.y = 20;
  this->size.x = 100;
  this->position = position;
  this->rectColor = Color::Green;
 
}

void HealthBar::Update(__int64 deltatime)
{

}

void HealthBar::SetRectangleShape()
{
  rs.setSize(Vector2f(200,25));
  rs.setPosition(position.x, position.y);
  rs.setFillColor(rectColor);
}