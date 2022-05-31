cmake_minimum_required(VERSION 3.10)
find_package(Threads REQUIRED)

add_library(
    ${PROJECT_NAME} SHARED 
    logger/logger.cc
    logger/logger.h

    player/player.cc
    player/player.h

    server/server.h

    macros.h
    )

target_compile_definitions(${PROJECT_NAME} PUBLIC FRAMEWORK_DLL FRAMEWORK_LIB)
target_link_libraries(${PROJECT_NAME} PUBLIC enet fmt ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(${PROJECT_NAME} PRIVATE .)