cmake_minimum_required(VERSION 3.14)

project(
    designpatterns_moderncpp
    VERSION 0.1.0
    DESCRIPTION "Coding exercises for Design Patterns in Moderns C++"
    HOMEPAGE_URL "https://github.com/killerasus/designpatterns_moderncpp"
    LANGUAGES CXX
)

include(builder/CMakeLists.txt)
include(factory/CMakeLists.txt)
include(prototype/CMakeLists.txt)
