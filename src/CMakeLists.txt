
set(CMAKE_AUTOMOC ON)

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


set(MAHJONG_QT_PACKAGES
    Core
    Gui
    Network
    Quick
    Qml
    QmlWorkerScript
    QuickControls2
    QuickTemplates2
    QmlModels
)

find_package(Qt5 COMPONENTS ${MAHJONG_QT_PACKAGES} REQUIRED)



qt5_add_resources(SOURCES qml.qrc)


list(TRANSFORM MAHJONG_QT_PACKAGES PREPEND "Qt5::")

add_executable(${MAHJONG_EXE_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${MAHJONG_EXE_NAME} PRIVATE
    ${MAHJONG_QT_PACKAGES}
)

target_include_directories(${MAHJONG_EXE_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

install(TARGETS ${MAHJONG_EXE_NAME}
    RUNTIME
    DESTINATION bin
)

set(QtDeps)

foreach(QtNeededLib ${MAHJONG_QT_PACKAGES})
    get_target_property(QtDepFile ${QtNeededLib} LOCATION)
    list(APPEND QtDeps "${QtDepFile}")
endforeach()

message("QtDeps ${QtDeps}")
install(FILES
    ${QtDeps}
    DESTINATION bin
)



### qml modules ###

set(QT_QML_DIR "${Qt5_DIR}/../../../qml/")

set(MAHJONG_QT_QML_DEPS
#    QtGraphicalEffects
#    QtMultimedia
#    QtQml
   QtQuick
    QtQuick.2
)

list(TRANSFORM MAHJONG_QT_QML_DEPS PREPEND ${QT_QML_DIR})

message("QT_QML_DIR : ${QT_QML_DIR}")
install(DIRECTORY ${MAHJONG_QT_QML_DEPS} DESTINATION bin/qml
        PATTERN "*.debug" EXCLUDE
)



install_qt_plugins("Qt5::QWindowsIntegrationPlugin" "bin/platforms")
# install_qt_plugins("Qt5::QWindowsDirect2DIntegrationPlugin" "bin/platforms")

