
cmake_minimum_required(VERSION 3.16)

project(Mahjong
	VERSION 1.0.0
	LANGUAGES CXX
)

include(cmake/MahjongHelper.cmake)

add_subdirectory(src)
