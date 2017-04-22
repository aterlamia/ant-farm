cmake_minimum_required(VERSION 3.7)
project(AntFarm)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

set(SOURCE_FILES
        main.cpp
        Game.cpp
        Game.h
        Assets/StaticAssetLoader.cpp
        Assets/StaticAssetLoader.h
        GameObject/Map.cpp GameObject/Map.h Components/Tile.cpp Components/Tile.h Layer/LayerInterface.h Layer/MapLayer.cpp Layer/MapLayer.h Layer/CharacterLayer.cpp Layer/CharacterLayer.h Components/Ant.cpp Components/Ant.h Jobs/JobManager.cpp Jobs/JobManager.h Jobs/JobInterface.cpp Jobs/JobInterface.h Events/BuildEvent.cpp Events/BuildEvent.h Events/MineEvent.cpp Events/MineEvent.h Events/EventMessage.h)

add_executable(AntFarm ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} /home/melvin/CLionProjects/EmberEngine/release/lib/libEmberEngine.so)
INCLUDE_DIRECTORIES(/home/melvin/CLionProjects/EmberEngine/release/include)

# Use the FindPkgCOnfig to find sdl and sdl image.
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
# Link SDL to EMBER
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES})

PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

# Link SDL_IMAGE to EMBER
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

ADD_CUSTOM_COMMAND(
        TARGET ${PROJECT_NAME}
        PRE_BUILD
        COMMAND rsync
        ARGS -r
        "${PROJECT_SOURCE_DIR}/assets/"
        "${PROJECT_SOURCE_DIR}/bin/assets"
        COMMENT "Copying Bundle Assets")


ADD_CUSTOM_COMMAND(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND rsync
        ARGS -r
        "${PROJECT_SOURCE_DIR}/assets/"
        "${PROJECT_SOURCE_DIR}/bin/assets"
        COMMENT "Copying Bundle Assets")