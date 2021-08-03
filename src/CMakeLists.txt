
set(MAHJONG_EXE_NAME mahjong)

set(SOURCES
	main.cpp
	mahjong/Player.cpp
	mahjong/PlayerParser.cpp
	mahjong/Room.cpp
	mahjong/Table.cpp
)

set(HEADERS
	mahjong/json.hpp
	mahjong/Player.hpp
	mahjong/PlayerParser.hpp
	mahjong/Room.hpp
	mahjong/Table.hpp
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
