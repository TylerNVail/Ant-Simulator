cmake_minimum_required(VERSION 3.23)


project(Ants LANGUAGES CXX VERSION 0.1.0)

#configure_file(AntsConfig.h.in AntsConfig.h)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#Create the AntSimulation Library
add_library(AntSimulator STATIC)
target_sources(AntSimulator
    PRIVATE
      world.cpp
      food.cpp
      pheromones.cpp
      vector3d.cpp
      ant.cpp
      randomnumbergenerator.cpp
      antdecisions.cpp
      utilities.cpp
      foodmap.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS ${PROJECT_SOURCE_DIR}
    FILES
        world.h
        food.h
        pheromones.h
        vector3d.h
        ant.h
        randomnumbergenerator.h
        antdecisions.h
        utilities.h
        foodmap.h)

target_link_libraries(AntSimulator
    PUBLIC)

install(TARGETS AntSimulator
    EXPORT AntSimulatorTargets
    FILE_SET HEADERS
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)

install(EXPORT AntSimulatorTargets
    FILE AntSimulatorTargets.cmake
    NAMESPACE AntSimulator::
    DESTINATION lib/cmake/AntSimulator)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "AntSimulationConfigVersion.cmake"
    VERSION ${AntSimulator_VERSION}
    COMPATIBILITY AnyNewerVersion)

install(
    FILES
        "AntSimulatiorConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/AntSimulatiorConfigVersion.cmake"
    DESTINATION lib/cmake/${PROJECT_NAME}
)
#Create AntSimulatior UnitTests Library
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(AntSimulatiorUnittests)
target_sources(AntSimulatiorUnittests
    PRIVATE
    utilites_unittests.cpp
    world_unittests.cpp
    food_unittests.cpp)

target_link_libraries(AntSimulatiorUnittests PRIVATE
          ${GTEST_LIBRARIES}
     ${GTEST_MAIN_LIBRARIES}
    AntSimulator
    )

#create the Qt GUI Executable
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets Concurrent REQUIRED)

add_executable(Ants)
target_sources(Ants PRIVATE
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
  drawingwidget.h
  drawingwidget.cpp
 )

target_link_libraries(Ants PRIVATE
  Qt6::Widgets
  Qt6::Concurrent
  AntSimulator
  )

