#include <SFML\Graphics.hpp>
#include "ResourceManager.h"

using namespace sf;

class Game
{

public:
  Game();
  void Update();
  void Run();
  void Render();
  void GetDeltaTime();
  void keyboard();
  bool playerTurn;
 // std::vector<Character> activplayer;
private:
  RenderWindow *_mWin;
  float _mfps;
  Clock _mClock;
  Clock _mgameClock;
  Time _mTime;
  Int64 _mdeltatime;
  Time _mPrevTime;
  ResourceManager *rm;
  sf::Image img;
  sf::Texture tex;
  sf::Sprite spr;
  //-for font-//
  Font gameFont;
  Text gameText;
  int count;
  int prev;
  Font gameTimeFont;
  Text gameTimeText;
  //
  Texture tex_fireArrows;
  Sprite  spr_fireArrows;
  float arrow_rotation;
  bool menustate;
  //
  Font menu_Font;
  Text menu_Text;
  //
  Font playervsplayer_font;
  Text playervsplayer_text;
  //
  Font playervscpu_font;
  Text playervscpu_text;
  //
  bool AI;
  bool ready;
};