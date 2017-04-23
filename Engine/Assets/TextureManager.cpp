//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "TextureManager.h"
#include "../Events/LogEVent.h"

namespace Ember {
  bool TextureManager::load(
      std::string fileName,
      std::string id
  ) {
    SDL_Surface *pTempSurface = IMG_Load(fileName.c_str());

    if (pTempSurface == 0) {
      m_bus->fire(new LogEVent("Error could not find file" + fileName, LOG_CANAL::TEXTURES,
                               LOG_TYPE::ERROR_TYPE));
      return false;
    }

    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(mvpRenderer, pTempSurface);

    SDL_FreeSurface(pTempSurface);
    // everything went ok, add the texture to our list
    if (pTexture != 0) {
      mTextureMap[id] = pTexture;
      m_bus->fire(new LogEVent("Added texture " + id + " from file " + fileName, LOG_CANAL::TEXTURES,
                               LOG_TYPE::INFO_TYPE));
      return true;
    }
    m_bus->fire(new LogEVent("Could not Load texture " + id + " from file " + fileName, LOG_CANAL::TEXTURES,
                             LOG_TYPE::ERROR_TYPE));

    return false;
  }

  void Ember::TextureManager::draw(
      std::string id,
      int x,
      int y,
      int width,
      int height,
      bool flip
  ) {
    SDL_RendererFlip sdl_flip = SDL_FLIP_NONE;

    if (flip) {
      sdl_flip = SDL_FLIP_HORIZONTAL;
    }

    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(
        mvpRenderer,
        mTextureMap[id],
        &srcRect,
        &destRect,
        0,
        0,
        sdl_flip);
  }

  void Ember::TextureManager::drawFrame(
      std::string id,
      int x,
      int y,
      int width,
      int height,
      int currentRow,
      int currentColumn,
      bool flip
  ) {
    SDL_RendererFlip sdl_flip = SDL_FLIP_NONE;

    if (flip == true) {
      sdl_flip = SDL_FLIP_HORIZONTAL;
    }

    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * (currentColumn - 1);
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(
        mvpRenderer,
        mTextureMap[id],
        &srcRect,
        &destRect,
        0,
        0,
        sdl_flip);
  }

  Ember::TextureManager::~TextureManager() {
    m_bus->fire(new LogEVent("Texture manager", LOG_CANAL::DESTRUCTOR,
                             LOG_TYPE::INFO_TYPE));
  }

  void TextureManager::handleEvent(EventInterface &event) {
    if (event.getType() == "texture_load") {
      EventMessage message = event.getMessage();
      load(message.file, message.name);
    }

    if (event.getType() == "render_event") {
      EventMessage message = event.getMessage();
      draw(
          message.name,
          message.position.X,
          message.position.Y,
          message.dimension.height,
          message.dimension.width
      );

    }

    if (event.getType() == "render_frame") {
      EventMessage message = event.getMessage();
      drawFrame(
          message.name,
          message.position.X,
          message.position.Y,
          message.dimension.height,
          message.dimension.width,
          message.frame.row,
          message.frame.column
      );

    }

  }

  TextureManager::TextureManager(
      SDL_Renderer *mvpRenderer,
      EventBus *m_bus
  )
      : mvpRenderer(mvpRenderer)
        , m_bus(m_bus) {}
}