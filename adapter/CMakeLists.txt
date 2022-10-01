cmake_minimum_required(VERSION 3.14)

add_executable(adapter_exe adapter/src/main.cpp)

set_target_properties(
    adapter_exe PROPERTIES
    OUTPUT_NAME adapter
    EXPORT_NAME exe
)

target_compile_features(adapter_exe PRIVATE cxx_std_17)