#include <tyra>
#include "tyramask_game.hpp"

int main() {
  Tyra::Engine engine;
  TyraMask::TyraMaskGame game(&engine); 
  engine.run(&game);
  SleepThread();
  return 0;
}
