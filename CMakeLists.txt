cmake_minimum_required(VERSION 3.30)
project(SlidingPuzzles)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/home/szymon/Qt/6.8.2/gcc_64")

find_package(Qt6 COMPONENTS
  Core
  Gui
  Widgets
  REQUIRED)

add_executable(SlidingPuzzles main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        menu/MenuScreen.cpp
        menu/MenuScreen.h
        menu/MenuScreen.ui
        game/GameScreen.cpp
        game/GameScreen.h
        game/GameScreen.ui
        game/board/Board.cpp
        game/board/Board.h
        game/board/tiles/Tile.h
        game/board/tiles/NumberTile.cpp
        game/board/tiles/NumberTile.h
        game/board/tiles/EmptyTile.cpp
        game/board/tiles/EmptyTile.h
        game/board/tiles/ValueTile.h
        game/GameScreenViewModel.cpp
        game/GameScreenViewModel.h
        settings/GameSettingsScreen.cpp
        settings/GameSettingsScreen.h
        settings/GameSettingsScreen.ui
        settings/GameSettingsScreenViewModel.cpp
        settings/GameSettingsScreenViewModel.h
        game/board/BoardPreview.cpp
        game/board/BoardPreview.h
        game/board/BoardPreview.ui
        game/board/RandomBoardFactory.cpp
        game/board/RandomBoardFactory.h
)
target_link_libraries(SlidingPuzzles
  Qt::Core
  Qt::Gui
  Qt::Widgets
)

