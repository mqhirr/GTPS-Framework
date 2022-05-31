cmake_minimum_required(VERSION 3.10)
find_package(Threads REQUIRED)

add_executable(
    ${PROJECT_NAME} SHARED 
    logger/logger.cc
    logger/logger.h

    player/player.cc
    player/player.h

    server/server.h

    macros.h
    )

target_compile_definitions(${PROJECT_NAME} FRAMEWORK_DLL FRAMEWORK_LIB)
target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_THREAD_LIBS_INIT} enet fmt)
target_include_directories(${PROJECT_NAME} PRIVATE .)