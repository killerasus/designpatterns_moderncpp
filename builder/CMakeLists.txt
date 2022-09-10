cmake_minimum_required(VERSION 3.14)

add_executable(builder_exe builder/src/main.cpp)

set_target_properties(
    builder_exe PROPERTIES
    OUTPUT_NAME builder
    EXPORT_NAME exe
)

target_compile_features(builder_exe PRIVATE cxx_std_17)