cmake_minimum_required(VERSION 3.7)
project(AntFarm)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/Engine")

set(SOURCE_FILES
    main.cpp
    MyGame.cpp
    MyGame.h
    Assets/StaticAssetLoader.cpp
    Assets/StaticAssetLoader.h
    GameObject/Map.cpp
    GameObject/Map.h
    Components/Tile.cpp
    Components/Tile.h
    Layer/LayerInterface.h
    Layer/MapLayer.cpp
    Layer/MapLayer.h
    Layer/CharacterLayer.cpp
    Layer/CharacterLayer.h
    Components/Ant.cpp
    Components/Ant.h
    Jobs/JobManager.cpp
    Jobs/JobManager.h
    Jobs/JobInterface.cpp
    Jobs/JobInterface.h
    Events/BuildEvent.cpp
    Events/BuildEvent.h
    Events/MineEvent.cpp
    Events/MineEvent.h
    Events/EventMessage.h
    Jobs/MineJob.cpp
    Jobs/MineJob.h
    Layer/OverlayLayer.cpp
    Layer/OverlayLayer.h
    System/ServiceContainer.cpp
    System/ServiceContainer.h
    )


set(SOURCE_FILES_ENGINE
    Engine/Game.cpp
    Engine/Game.h
    Engine/Events/EventInterface.h
    Engine/Assets/TextureManager.cpp
    Engine/Assets/TextureManager.h
    Engine/Events/EventBus.cpp
    Engine/Events/EventBus.h
    Engine/Events/EventListenerInterface.h
    Engine/System/Logger.cpp
    Engine/System/Logger.h
    Engine/Events/LogEVent.cpp
    Engine/Events/LogEVent.h
    Engine/Events/EventMessage.h
    Engine/Assets/AssetLoaderInterface.h
    Engine/ValueObjects/Dimension2d.h
    Engine/Events/LoadTextureEvent.cpp
    Engine/Events/LoadTextureEvent.h
    Engine/System/InputHandler.cpp
    Engine/System/InputHandler.h
    Engine/Events/InputEvent.cpp
    Engine/Events/InputEvent.h
    Engine/State/GameState.cpp
    Engine/State/GameState.h
    Engine/Events/RenderEvent.cpp
    Engine/Events/RenderEvent.h
    Engine/Objects/GameObject.cpp
    Engine/Objects/GameObject.h
    Engine/Components/ComponentInterface.h
    Engine/Components/TextureComponent.cpp
    Engine/Components/TextureComponent.h
    Engine/Math/Vector2d.h
    Engine/ValueObjects/Position2d.h
    Engine/ValueObjects/Frame.h
    Engine/Components/AnimationComponent.cpp
    Engine/Components/AnimationComponent.h
    Engine/Events/RenderFrameEvent.cpp
    Engine/Events/RenderFrameEvent.h
    Engine/Components/TiledTextureComponent.cpp
    Engine/Components/TiledTextureComponent.h
    Engine/Events/MouseEvent.cpp
    Engine/Events/MouseEvent.h
    Engine/Events/EventType.h
    Engine/System/LogEnums.h
    Layer/LayerManager.h)


add_executable(AntFarm ${SOURCE_FILES_ENGINE} ${SOURCE_FILES})

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