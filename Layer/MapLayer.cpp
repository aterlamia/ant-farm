//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "MapLayer.h"
#include "../Components/Tile.h"


void MapLayer::render() {
  for (int i = 0; i < m_tilesRow; i++) {
    for (int j = 0; j < m_tilesColumn; j++) {
      m_map[i][j]->render();
    }
  }
}

void MapLayer::update() {

}

MapLayer::MapLayer(
    Ember::EventBus *m_bus,
    int m_tilesRow,
    int m_tilesColumn
) : m_bus(m_bus)
    , m_tilesRow(m_tilesRow)
    , m_tilesColumn(m_tilesColumn) {}

void MapLayer::init() {
  for (int i = 0; i < m_tilesRow; i++) {
    std::vector<TileObject *> row;
    for (int j = 0; j < m_tilesColumn; j++) {

      int column = i % 16 + 1;
      int row1 = j % 8 + 1;
      TileObject *tile = new TileObject("Tile", Ember::Position2d(0 + i * 64, 0 + j * 64));
      Tile *tileComponent = new Tile(Ember::COMPONENT_VISUAL, "Tile",
                                     Ember::Dimension2d(64, 64),
                                     Ember::Frame(row1, column),
                                     m_bus);

      tileComponent->setTileType(Tile::TILE_SOIL);

      // BEgin area
      if (i == 5 && j == 8) {
        tile->setPassable(true);
        tileComponent->setFrame(Ember::Frame(16, 5));
        tileComponent->setTileType(Tile::TILE_NONE);
        tileComponent->setMineable(false);
      }

      // BEgin area
      if (i == 6 && j == 8) {
        tile->setPassable(true);
        tileComponent->setFrame(Ember::Frame(16, 6));
        tileComponent->setTileType(Tile::TILE_NONE);
        tileComponent->setMineable(false);
      }

      if (i == 7 && j == 8) {
        tile->setPassable(true);
        tileComponent->setFrame(Ember::Frame(16, 6));
        tileComponent->setTileType(Tile::TILE_NONE);
        tileComponent->setMineable(false);
      }

      if (i == 8 && j == 8) {
        tile->setPassable(true);
        tileComponent->setFrame(Ember::Frame(16, 7));
        tileComponent->setTileType(Tile::TILE_NONE);
        tileComponent->setMineable(false);
      }

//      if (i == 9 && j == 8) {
//        tile->setPassable(true);
//        tileComponent->setFrame(Ember::Frame(16, 7));
//        tileComponent->setTileType(Tile::TILE_NONE);
//        tileComponent->setMineable(false);
//      }

      tile->addComponent(
          tileComponent
      );
      row.push_back(tile);
    }
    m_map.push_back(row);
  }
}

TileObject *MapLayer::getTileObjectByPosition(Ember::Position2d position) {
  return m_map[position.X][position.Y];
}

std::vector<TileObject *> MapLayer::getPath(
    Ember::Position2d begin,
    Ember::Position2d end
) {
  // Maybe look at a linked list sometime now bruteforce it.
  // ALso obviosly create a pathfinder class.
  if (getTileObjectByPosition(begin)->isPassable() == false) {
    std::cout << "Begin item is not passable";
//    return false;
  }

  std::vector<TileObject *> path;
  std::vector<TileObject *> tilePath;
  path.push_back(getTileObjectByPosition(begin));

  std::cout << "STEP 1 a\n\n";
  Ember::Position2d nextPos = {begin.X + 1, begin.Y};
  if (getTileObjectByPosition(nextPos)->isPassable()) {
    std::cout << "Right is passable\n";
    tilePath = getTilePath(nextPos, end, begin, path);
    if (tilePath.size() > 1) {
      std::cout << "Path found 1";
    }
  }

  std::cout << "STEP 1 b\n\n";
  nextPos = {begin.X - 1, begin.Y};
  if (getTileObjectByPosition(nextPos)->isPassable()) {
    std::cout << "Left is passable\n";
    tilePath = getTilePath(nextPos, end, begin, path);
    if (tilePath.size() > 1) {
      std::cout << "Path found 1";
    }

  }

  std::cout << "STEP 1 c\n\n";
  nextPos = {begin.X, begin.Y + 1};
  if (getTileObjectByPosition(nextPos)->isPassable()) {
    std::cout << "y + 1 is passable\n";
    std::vector<TileObject *> curPath = getTilePath(nextPos, end, begin, path);
    tilePath = getTilePath(nextPos, end, begin, path);
    if (tilePath.size() > 1) {
      std::cout << "Path found 3";
    }
  }

  std::cout << "STEP 1 d\n\n";
  nextPos = {begin.X, begin.Y - 1};
  if (getTileObjectByPosition(nextPos)->isPassable()) {
    std::cout << "y - 1 is passable\n";
    tilePath = tilePath = getTilePath(nextPos, end, begin, path);
    if (tilePath.size() > 1) {
      std::cout << "Path found 4";
    }
  }

  std::cout << "NEXT STEP \n";
}

/**
 * Recusive function.
 *
 * @param begin
 * @param end
 * @param cameFrom
 * @param route
 * @return
 */
std::vector<TileObject *> MapLayer::getTilePath(
    Ember::Position2d begin,
    Ember::Position2d end,
    Ember::Position2d cameFrom,
    std::vector<TileObject *> route
) {
  Ember::Position2d nextPosLeft = {begin.X - 1, begin.Y};
  Ember::Position2d nextPosRight = {begin.X + 1, begin.Y};
  Ember::Position2d nextPosTop = {begin.X, begin.Y - 1};
  Ember::Position2d nextPosBottom = {begin.X, begin.Y + 1};

  std::cout << "STEP 2\n\n";
  // are we there yet?
  if (
      arrived(nextPosLeft, end)
      || arrived(nextPosRight, end)
      || arrived(nextPosTop, end)
      || arrived(nextPosBottom, end)
      ) {
    return route;
  }

  std::vector<TileObject *> tilePath;

  if (nextPosLeft.equals(cameFrom) == false && getTileObjectByPosition(nextPosLeft)->isPassable()) {
    std::cout << "Left is passable \n";
    route.push_back(getTileObjectByPosition(nextPosLeft));
    tilePath = getTilePath(nextPosLeft, end, begin, route);
    return route;
  } else if (nextPosRight.equals(cameFrom) == false && getTileObjectByPosition(nextPosRight)->isPassable()) {
    std::cout << "Right is passable \n";
    route.push_back(getTileObjectByPosition(nextPosRight));
    tilePath = getTilePath(nextPosRight, end, begin, route);
    return tilePath;
  } else if (nextPosBottom.equals(cameFrom) == false && getTileObjectByPosition(nextPosBottom)->isPassable()) {
    std::cout << "Bottom is passable \n";
    route.push_back(getTileObjectByPosition(nextPosBottom));
    tilePath = getTilePath(nextPosBottom, end, begin, route);
    return tilePath;
  } else if (nextPosTop.equals(cameFrom) == false && getTileObjectByPosition(nextPosTop)->isPassable()) {
    std::cout << "Top is passable \n";
    route.push_back(getTileObjectByPosition(nextPosTop));
    tilePath = getTilePath(nextPosTop, end, begin, route);
    return tilePath;
  } else {
    std::cout << "No path \n";
  }

  return std::vector<TileObject*>();
}

bool MapLayer::arrived(
    Ember::Position2d next,
    Ember::Position2d end
) {

  std::cout << "next: " << next.X << ", " << next.Y << "\n";
  std::cout << "end: " << end.X << ", " << end.Y << "\n";
  if (next.equals(end)) {
    std::cout << "We are there\n";
    return true;
  }

  return false;
};
