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
)
target_link_libraries(SlidingPuzzles
  Qt::Core
  Qt::Gui
  Qt::Widgets
)

