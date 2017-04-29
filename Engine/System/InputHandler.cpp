//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "InputHandler.h"
#include "../Events/LogEVent.h"
#include "../Events/InputEvent.h"
#include "../Events/MouseEvent.h"


namespace Ember {
  void InputHandler::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          m_bus->fire(new InputEvent(Ember::QUIT_EVENT));
          break;
        case SDL_KEYDOWN:
          m_bus->fire(new InputEvent(Ember::KEYBOARD_EVENT_DOWN, event.key.keysym.scancode));
          break;
        case SDL_KEYUP:
          m_bus->fire(new InputEvent(Ember::KEYBOARD_EVENT_UP, event.key.keysym.scancode));
          break;
        case SDL_MOUSEBUTTONDOWN:
          int x, y;
          SDL_GetMouseState(&x, &y);
          if (event.button.button == SDL_BUTTON_LEFT) {
            m_bus->fire(new MouseEvent(Ember::MOUSE_DOWN, LEFT, Vector2D(x, y)));
          }
          if (event.button.button == SDL_BUTTON_MIDDLE) {
            m_bus->fire(new MouseEvent(Ember::MOUSE_DOWN, MIDDLE, Vector2D(x, y)));
          }
          if (event.button.button == SDL_BUTTON_RIGHT) {
            m_bus->fire(new MouseEvent(Ember::MOUSE_DOWN, RIGHT, Vector2D(x, y)));
          }

          break;

        default:
          break;
      }
    }
  }

  InputHandler::~InputHandler() {
    m_bus->fire(new LogEVent("InputHandler", LOG_CANAL::DESTRUCTOR,
                             LOG_TYPE::INFO_TYPE));
  }

  InputHandler::InputHandler(EventBus *m_bus)
      : m_bus(m_bus) {}

}