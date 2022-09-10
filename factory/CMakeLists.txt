cmake_minimum_required(VERSION 3.14)

add_executable(factory_exe 
                factory/src/main.cpp
                factory/src/Person.cpp
)

set_target_properties(
    factory_exe PROPERTIES
    OUTPUT_NAME factory
    EXPORT_NAME exe
)

target_compile_features(factory_exe PRIVATE cxx_std_17)