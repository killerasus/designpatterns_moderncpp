cmake_minimum_required(VERSION 3.14)

add_executable(prototype_exe 
                prototype/src/main.cpp
)

set_target_properties(
    prototype_exe PROPERTIES
    OUTPUT_NAME prototype
    EXPORT_NAME exe
)

target_compile_features(prototype_exe PRIVATE cxx_std_17)