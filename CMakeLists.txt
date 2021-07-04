
cmake_minimum_required(VERSION 3.16)

project(Mahjong
	VERSION 1.0.0
	LANGUAGES CXX
)


set(MAHJONG_EXE_NAME mahjong)


find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)



set(SOURCES
	main.cpp
	Room.cpp
	Table.cpp
	Player.cpp
)

set(HEADERS
	json.hpp
	Room.hpp
	Table.hpp
	Player.hpp
)

qt5_add_resources(SOURCES qml.qrc)

add_executable(${MAHJONG_EXE_NAME} ${SOURCES})

target_link_libraries(${MAHJONG_EXE_NAME} PRIVATE
    Qt5::Core
    Qt5::Quick
    Qt5::Widgets
)

target_include_directories(${MAHJONG_EXE_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

