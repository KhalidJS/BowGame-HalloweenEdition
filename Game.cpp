#include "Game.h"
#include <iostream>
#include "Map.h"
#include <algorithm>

using namespace std;

GameObject *obj;
Map *objmap;
bool fired;
bool canFire;
Sprite *pArrow;

Game::Game()
{
  _mWin = new RenderWindow(VideoMode(1280, 720), "BowGame!!", Style::Close);
  _mWin->setVerticalSyncEnabled(true);
  _mgameClock.restart();
  _mfps = 0;
  obj = new GameObject(1, "gameArrow/png/BG.png", Vector2f(0, 0), Vector2f(1, 1), false);
  objmap = new Map(sf::Vector2f(0, 0), 128, "lvl.txt");

  //---------------
  gameFont.loadFromFile("C:/Windows/Fonts/arial.ttf");
  gameText.setFont(gameFont);
  gameText.setCharacterSize(20);
  gameText.setStyle(Text::Bold);
  //---------------
  tex_fireArrows.loadFromFile("gameArrow/arrow.png");
  spr_fireArrows.setTexture(tex_fireArrows);
  spr_fireArrows.setPosition(0, 0);
  //----------------
  gameTimeFont.loadFromFile("C:/Windows/Fonts/arial.ttf");
  gameTimeText.setFont(gameTimeFont);
  gameTimeText.setCharacterSize(35);
  gameTimeText.setString("Time: ");
  gameTimeText.setPosition((float)((_mWin->getSize().x / 2) - 100), 0);
  //----------------
  fired = false;
  canFire = true;
  // --- Menu stuff ----
  menustate = true;
  menu_Font.loadFromFile("C:/Windows/Fonts/arial.ttf");
  menu_Text.setFont(menu_Font);
  menu_Text.setCharacterSize(35);
  menu_Text.setString("Choose a GameMode");
  menu_Text.setPosition((float)(_mWin->getSize().x / 2) - 200, 75);

  playervsplayer_font.loadFromFile("C:/Windows/Fonts/arial.ttf");
  playervsplayer_text.setFont(playervsplayer_font);
  playervsplayer_text.setCharacterSize(25);
  playervsplayer_text.setString("Player vs Player ( F1 )");
  playervsplayer_text.setPosition((float)(_mWin->getSize().x / 2) - 200, 120);

  playervscpu_font.loadFromFile("C:/Windows/Fonts/arial.ttf");
  playervscpu_text.setFont(playervscpu_font);
  playervscpu_text.setCharacterSize(25);
  playervscpu_text.setString("Player vs CPU ( F2 )");
  playervscpu_text.setPosition((float)(_mWin->getSize().x / 2) - 200, 150);
  // --- Menu stuff ----
  AI = false;
  ready = false;
}

void Game::Run()
{
  while (_mWin->isOpen())
  {
    Event e;
    while (_mWin->pollEvent(e))
    {
      if (e.type == Event::Closed || e.type == Event::KeyPressed && e.key.code == Keyboard::Escape) _mWin->close();
      //if (e.type == Event::KeyPressed && e.key.code == Keyboard::Return);

      if (e.type == Event::KeyPressed && e.key.code == Keyboard::Space && canFire == true && menustate == false && AI == false || e.type == Event::KeyPressed && e.key.code == Keyboard::Space && canFire == true && menustate == false && count == 0 ||
        e.type == Event::KeyPressed && e.key.code == Keyboard::Space  && menustate == false && AI == false && spr_fireArrows.getPosition().x > _mWin->getSize().x ||
        e.type == Event::KeyPressed && e.key.code == Keyboard::Space &&   menustate == false && AI == false && spr_fireArrows.getPosition().x < 0 ||
        e.type == Event::KeyPressed && e.key.code == Keyboard::Space &&  menustate == false && AI == false && spr_fireArrows.getPosition().y > _mWin->getSize().y ||
        e.type == Event::KeyPressed && e.key.code == Keyboard::Space &&  menustate == false && AI == false && spr_fireArrows.getPosition().y < 0)
      {





        if (objmap->Players[count].WeaponSlot->msprite.getScale().x == -1){
          arrow_rotation = objmap->Players[count].WeaponSlot->msprite.getRotation() + 180;
          //cout << "minus";
        }
        else
        {
          arrow_rotation = objmap->Players[count].WeaponSlot->msprite.getRotation();
        }
        objmap->Players[count].arrow->visible = false;
        spr_fireArrows.setPosition(objmap->Players[count].arrow->spr_arrow.getPosition());
        spr_fireArrows.setRotation(arrow_rotation);
        objmap->Players[count].arrow->hit = false;
        count++;

        prev = count - 1;
        fired = true;
        canFire = false;
      }
      if (e.type == Event::Closed || e.type == Event::KeyPressed && e.key.code == Keyboard::F1 && menustate == true){ menustate = false; _mgameClock.restart(); AI == false; }
      if (e.type == Event::Closed || e.type == Event::KeyPressed && e.key.code == Keyboard::F2 && menustate == true){ menustate = false; _mgameClock.restart(); AI = true; }
    }
    Update();
    Render();
  }
}

void Game::Update()
{
  //cout << _mdeltatime << endl;
  Time t1 = sf::microseconds(_mdeltatime);
  gameText.setString("FPS: " + std::to_string((int)(1.0f / t1.asSeconds())));
  if (menustate == false){
    gameTimeText.setString("Time: " + std::to_string((int)_mgameClock.getElapsedTime().asSeconds()));
  }
  if (objmap->Players.size() == count)
  {
    count = 0;
    prev = -1;
    for (auto v : objmap->Players) v.arrow->visible = true;
  }

  objmap->Players[count].arrow->spr_arrow.setRotation(objmap->Players[count].WeaponSlot->msprite.getRotation());
  objmap->Players[count].arrow->spr_arrow.setPosition(objmap->Players[count].WeaponSlot->msprite.getPosition());

  //if (objmap->Players[count].arrow->visible == false) objmap->Players[count].arrow->spr_arrow.setColor(sf::Color(255,255,255,128));
  //cout << objmap->Players[count].WeaponSlot->msprite.getRotation() << endl;

}

void Game::Render()
{
  _mWin->clear();



  _mWin->draw(obj->msprite);
  _mWin->draw(gameText);
  _mWin->draw(gameTimeText);
  if (menustate){
    _mWin->draw(menu_Text);
    _mWin->draw(playervsplayer_text);
    _mWin->draw(playervscpu_text);
  }
  for (auto sp : objmap->Tiles)
  {
    _mWin->draw(sp);
  }

  if (fired == true){
    _mWin->draw(spr_fireArrows);
  }

  for (auto pl : objmap->Players)
  {
    _mWin->draw(pl);
    _mWin->draw(pl.WeaponSlot->msprite);
    _mWin->draw(pl.healthbar->rs);
    _mWin->draw(pl.collisionBox);

    for (unsigned i = 0; i < objmap->Players.size(); i++)
    {
      if (objmap->Players.at(i).DEAD == true)
      {
        cout << "A player with ID" << objmap->Players.at(i).ID << " has died" << endl;;
        objmap->Players.erase(objmap->Players.begin() + i);
        if (i == 0)
        {
          cout << " Player 2 wins" << endl;
          cout <<_mgameClock.getElapsedTime().asSeconds();
        }
        if (i == 1)
        {
          cout << " Player 1 wins" << endl;
          cout << _mgameClock.getElapsedTime().asSeconds();
        }
      }
    }

    if (objmap->Players[count].arrow->visible){
      Vector2f dir((float)std::cos((3.14 * (double)arrow_rotation) / 180.0), (float)std::sin((3.14 * (double)arrow_rotation) / 180.0));
      objmap->Players[count - prev].arrow->direction = dir;
      _mWin->draw(objmap->Players[count].arrow->spr_arrow);
      spr_fireArrows.move(dir * objmap->Players[count - prev].arrow->speed);

      //cout << dir.y << endl;

      if (spr_fireArrows.getGlobalBounds().intersects(pl.collisionBox.getGlobalBounds()) && objmap->Players[count].arrow->hit == false)
      {
        objmap->Players[count].hit();
        fired = false;
        //cout << "Collision";
        objmap->Players[count].arrow->hit = true;
        canFire = true;
        //objmap->Players[count].msprite.setColor(Color::Transparent);
        //objmap->Players[count].DEAD = true;
        if (objmap->Players[count].healthbar->rs.getSize().x <= 50)
        {
          objmap->Players[count].healthbar->rs.setFillColor(Color::Yellow);
        }
        if (objmap->Players[count].healthbar->rs.getSize().x <= 25)
        {
          objmap->Players[count].healthbar->rs.setFillColor(Color::Red);
        }
      }
    }
  }
  _mWin->display();
  GetDeltaTime();
  keyboard();
}

void Game::GetDeltaTime()
{
  _mTime = _mClock.getElapsedTime();
  _mdeltatime = (_mTime.asMicroseconds() - _mPrevTime.asMicroseconds());
  _mPrevTime = _mTime;
}

void Game::keyboard()
{
  if (Keyboard::isKeyPressed(Keyboard::Down) && menustate == false && AI == false || Keyboard::isKeyPressed(Keyboard::Down) && menustate == false && count == 0){
    // when bow is flipped
    if (objmap->Players[count].WeaponSlot->msprite.getScale().x == -1 && objmap->Players[count].WeaponSlot->msprite.getPosition().y - 150 < objmap->Players[count].WeaponSlot->startposition.y){
      objmap->Players[count].WeaponSlot->msprite.rotate(-2);
      objmap->Players[count].WeaponSlot->msprite.move(0, +5);
    }
    // when bow not flipped
    if (objmap->Players[count].WeaponSlot->msprite.getScale().x == 1 && objmap->Players[count].WeaponSlot->msprite.getPosition().y - 150 < objmap->Players[count].WeaponSlot->startposition.y
      ){
      objmap->Players[count].WeaponSlot->msprite.rotate(+2);
      objmap->Players[count].WeaponSlot->msprite.move(0, +5);
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::Up) && menustate == false && AI == false || Keyboard::isKeyPressed(Keyboard::Up) && menustate == false && count == 0){
    // when bow is flipped
    if (objmap->Players[count].WeaponSlot->msprite.getScale().x == -1 && objmap->Players[count].WeaponSlot->msprite.getPosition().y + 125 > objmap->Players[count].WeaponSlot->startposition.y){
      objmap->Players[count].WeaponSlot->msprite.rotate(+2);
      objmap->Players[count].WeaponSlot->msprite.move(0, -5);
    }
    // when bow not flipped
    if (objmap->Players[count].WeaponSlot->msprite.getScale().x == 1 && objmap->Players[count].WeaponSlot->msprite.getPosition().y + 125 > objmap->Players[count].WeaponSlot->startposition.y){
      objmap->Players[count].WeaponSlot->msprite.rotate(-2);
      objmap->Players[count].WeaponSlot->msprite.move(0, -5);
    }
  }

  // AI Logic
  if (AI == true && count == 1 && objmap->Players[count].arrow->hit == true && ready == true || AI == true && count == 1 &&
    spr_fireArrows.getPosition().x > _mWin->getSize().x || AI == true && count == 1 &&
    spr_fireArrows.getPosition().x < 0 || AI == true && count == 1 &&
    spr_fireArrows.getPosition().y > _mWin->getSize().y || AI == true && count == 1 &&
    spr_fireArrows.getPosition().y < 0)
  {
    if (objmap->Players[count].WeaponSlot->msprite.getScale().x == -1){
      arrow_rotation = objmap->Players[count].WeaponSlot->msprite.getRotation() + 180;
      //cout << "minus";
    }
    else
    {
      arrow_rotation = objmap->Players[count].WeaponSlot->msprite.getRotation();
    }
    objmap->Players[count].arrow->visible = false;
    spr_fireArrows.setPosition(objmap->Players[count].arrow->spr_arrow.getPosition());
    spr_fireArrows.setRotation(arrow_rotation);
    objmap->Players[count].arrow->hit = false;
    count++;

    prev = count - 1;
    fired = true;
    canFire = false;
  }
}