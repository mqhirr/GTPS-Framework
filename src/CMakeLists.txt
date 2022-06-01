cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

add_library(
    ${PROJECT_NAME} SHARED 
    logger/logger.cc
    logger/logger.h

    player/player.cc
    player/player.h

    server/server.cc
    server/server.h

    config/macros.h
    config/config.h

    runner/run.cc
    runner/run.h

    math/math.h
    
    sdk/variant.cc
    sdk/variant.h
    sdk/packet.h
    sdk/update.h

    events/manager.cc
    events/manager.h
    events/context.h
)

target_compile_definitions(${PROJECT_NAME} PUBLIC FRAMEWORK_DLL FRAMEWORK_LIB)
target_link_libraries(${PROJECT_NAME} PUBLIC enet fmt ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(${PROJECT_NAME} PRIVATE .)