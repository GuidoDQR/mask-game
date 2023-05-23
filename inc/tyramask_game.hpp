#pragma once

#include <tyra>
#include <cstdlib>
#include <time.h>

namespace TyraMask{

class TyraMaskGame: public Tyra::Game {
 public:
  TyraMaskGame(Tyra::Engine* engine);
  ~TyraMaskGame();

  void init();
  void loop();
  
 private:
  void loadSprite(Sprite* sprite, Vec2 newPosition);
  void loadTexture(Tyra::Sprite* sprite, const char* image);

  Tyra::Engine* engine;
  Tyra::Pad* pad;
};

}