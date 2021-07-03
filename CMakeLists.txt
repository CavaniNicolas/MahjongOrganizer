
cmake_minimum_required(VERSION 3.16)

project(Mahjong
	VERSION 1.0.0
	LANGUAGES CXX
)


set(MAHJONG_EXE_NAME mahjong)

set(SOURCES
	main.cpp
)

set(HEADERS
)

add_executable(${MAHJONG_EXE_NAME} ${SOURCES})