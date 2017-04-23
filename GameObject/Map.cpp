//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <ValueObjects/Position2d.h>
#include <ValueObjects/Dimension2d.h>
#include <Components/TextureComponent.h>
#include "Map.h"


/**
 * Constructor.
 * @param m_bus
 * @param m_tilesRow
 * @param m_tilesColumn
 */
Map::Map(
    Ember::EventBus *m_bus,
    int m_tilesRow,
    int m_tilesColumn
)
    : m_bus(m_bus)
      , m_tilesRow(m_tilesRow)
      , m_tilesColumn(m_tilesColumn) {}


/**
 * Init the map.
 * @return
 */
void Map::init() {
  for (int i = 0; i < m_tilesRow; i++) {
    std::vector<Ember::GameObject *> row;
    for (int j = 0; j < m_tilesColumn; j++) {

      int column = i % 16 + 1;
      int row1 = j % 8 + 1;
      Ember::GameObject *tile = new Ember::GameObject("Tile", Ember::Position2d(0 + i * 64, 0 + j * 64));
      Tile *tileComponent = new Tile(Ember::COMPONENT_VISUAL, "Tile",
                                     Ember::Dimension2d(64, 64),
                                     Ember::Frame(row1, column),
                                     m_bus);

      tileComponent->setTileType(Tile::TILE_SOIL);


      if (i == 6 && j == 8) {
        tileComponent->setFrame(Ember::Frame(16, 5));
        tileComponent->setTileType(Tile::TILE_NONE);
        tileComponent->setMineable(false);
      }

      if (i == 7 && j == 8) {
        tileComponent->setFrame(Ember::Frame(16, 6));
        tileComponent->setTileType(Tile::TILE_NONE);
        tileComponent->setMineable(false);
      }

      if (i == 8 && j == 8) {
        tileComponent->setFrame(Ember::Frame(16, 7));
        tileComponent->setTileType(Tile::TILE_NONE);
        tileComponent->setMineable(false);
      }

      tile->addComponent(
          tileComponent
      );
      row.push_back(tile);
    }
    m_map.push_back(row);
  }
}

void Map::render() {

  for (int i = 0; i < m_tilesRow; i++) {
    for (int j = 0; j < m_tilesColumn; j++) {
      m_map[i][j]->render();
    }

  }
}
