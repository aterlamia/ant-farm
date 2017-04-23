//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_TEXTUREMANAGER_H
#define EMBERENGINE_TEXTUREMANAGER_H

#include <string>
#include <SDL2/SDL_image.h>
#include <map>
#include "../Events/EventListenerInterface.h"
#include "../Events/EventBus.h"
#include "../Events/LoadTextureEvent.h"
#include "../Events/RenderEvent.h"
#include "../Events/RenderFrameEvent.h"

namespace Ember {
/**
 * @todo we are not using an interface here and we use sdlm this means we have a hard dependecy
 *  towards sdl so this should be refactored. Create a interface for this class and use that.
 */
  class TextureManager : public EventListenerInterface {
  private:
    SDL_Renderer *mvpRenderer;
    std::map<std::string, SDL_Texture *> mTextureMap; /**< a Map containing all created textures */
    EventBus *m_bus;
  public:

    /**
     * Constuctor for texturemanager.
     *
     * @param pRenderer The class that will handeling outputing to the screen.
     * @return void
     */
    TextureManager(
        SDL_Renderer *mvpRenderer,
        EventBus *m_bus
    );

    bool load(
        std::string fileName,
        std::string id
    );

    /**
     * Will draw a texture to the screen.
     *
     * @param id Id of the texture as given when creating the texture.
     * @param x horizontal position where to start drawing te image.
     * @param y vertical position where to start drawing the image
     * @param width with of the texture
     * @param height height of the texture
     * @param flip does the picture need to be flipped vertical.
     */
    void draw(
        std::string id,
        int x,
        int y,
        int width,
        int height,
        bool flip = false
    );

    virtual ~TextureManager();

    /**
    * Will draw a texture frame  to the screen.
    * One texture can contain multiple frames (for example images of an animation)
    *
    * @param id Id of the texture as given when creating the texture.
    * @param x horizontal position where to start drawing te image.
    * @param y vertical position where to start drawing the image
    * @param width with of the texture
    * @param height height of the texture
    * @param currentRow The row as divided by the height first roww is 1 (second row 2 would be an offset of height)
    * @param currentColumn  The column as divided by width first column is 1 (second colunm 2 would be an offset of width)
    * @param flip does the picture need to be flipped vertical.
    */
    void drawFrame(
        std::string id,
        int x,
        int y,
        int width,
        int height,
        int currentRow,
        int currentColumn,
        bool flip = false
    );

    void handleEvent(EventInterface &event) override;

  };
};

#endif //EMBERENGINE_TEXTUREMANAGER_H
