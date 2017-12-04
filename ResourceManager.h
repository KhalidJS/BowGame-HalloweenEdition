#include <map>
#include <string>
#include <SFML\Graphics.hpp>
#include <vector>

class ResourceManager
{
public:
  ResourceManager();
  sf::Sprite GetSprite(std::string ID);
  sf::Sprite GetTile(std::string ID);
  std::vector<sf::Sprite> GetAnimation(std::string ID);
  std::map<std::string, sf::Sprite> _mGraphics;
};