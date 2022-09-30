cmake_minimum_required(VERSION 3.14)

add_executable(singleton_exe singleton/src/main.cpp)

set_target_properties(singleton_exe 
                      PROPERTIES OUTPUT_NAME singleton
                      EXPORT_NAME exe)

target_compile_features(singleton_exe PRIVATE cxx_std_17)
