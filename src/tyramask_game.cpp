#include "tyramask_game.hpp"

namespace TyraMask {

using namespace Tyra;

TyraMaskGame::TyraMaskGame(Engine* t_engine) { 
    engine = t_engine; 
    pad = &engine->pad;
}
TyraMaskGame::~TyraMaskGame() {
}

void TyraMaskGame::init() { 
    
}

void TyraMaskGame::loop() { 
    
}

void TyraMaskGame::loadSprite(Sprite* sprite, Vec2 newPosition) {

}

void TyraMaskGame::loadTexture(Sprite* sprite, const char* image) {
  /**
   * Renderer has high layer functions,
   * which allows to render:
   * - Sprite (2D)
   * - Mesh (3D)
   *
   * It uses ONLY low layer functions which are in renderer.core
   */
  auto& renderer = engine->renderer;

  /**
   * TextureRepository is a repository of textures.
   * It is a singleton class, with all game textures.
   * We are linking these textures with sprite's (2D) and mesh (3D) materials.
   */
  auto& textureRepository = renderer.getTextureRepository();

  /**
   * Texture is stored in "res" directory.
   * Content of "res" directory is automatically copied into
   * "bin" directory, which contains our final game.
   *
   * File utils automatically add's device prefix to the path,
   * based on current working directory.
   *
   * In PS2 world:
   * - USB has a "mass:" prefix
   * - Our PC in PS2Link has a "host:" prefix
   * - Our PC in PCSX2 has a "host:" prefix
   */
  auto filepath = FileUtils::fromCwd(image);

  /**
   * Tyra supports folloWINg PNG formats:
   * 32bpp (RGBA)
   * 24bpp (RGB)
   * 8bpp, palletized (RGBA)
   * 4bpp, palletized (RGBA)
   *
   * 8bpp and 4bpp are the fastest.
   * All of these formats can be easily exported via GIMP.
   */
  auto* texture = textureRepository.add(filepath);

  /** Let's assign this texture to sprite. */
  texture->addLink(sprite->id);

  TYRA_LOG("Texture loaded!");
}

}  // namespace Racer
