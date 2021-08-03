
cmake_minimum_required(VERSION 3.16)

project(Mahjong
	VERSION 1.0.0
	LANGUAGES CXX
)

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)

add_subdirectory(src)