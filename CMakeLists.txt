cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
SET(projectname SanaeGame)
find_package(glfw 3.2.1 REQUIRED)
include_directories(${glfw_INCLUDE_DIRS})
include_directories("./src")
link_directories
