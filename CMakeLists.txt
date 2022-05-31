cmake_minimum_required(VERSION 3.10)

project(gtps-framework VERSION 0.1 DESCRIPTION "A framework for Growtopia Private Server developers")

add_definitions("-DFRAMEWORK_COMMIT=${GIT_COMMIT_HASH}")
add_subdirectory(src)
add_subdirectory(vendor)