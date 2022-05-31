cmake_minimum_required(VERSION 3.10)
find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(${PROJECT_NAME} PRIVATE .)