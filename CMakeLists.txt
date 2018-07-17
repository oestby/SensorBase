cmake_minimum_required(VERSION 3.0.0)
project(SENSOR_BASE)

add_compile_options(-g -Wall -std=c++17)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include_directories(include)

########################
#   Define files      #
########################

#Tools library sources
file(GLOB TOOLS_SRC "src/tools/*.cpp")

file(GLOB SENSOR_SRC "src/sensor/*.cpp")

########################
#   Libraries          #
########################

add_library(tools_lib
    ${TOOLS_SRC}
)

add_library(sensor_lib
    ${SENSOR_SRC}
)

add_subdirectory(lib/googletest)
add_subdirectory(lib/serial)

########################
#   Executables        #
########################

add_executable(main src/main.cpp)


########################
#   Linking            #
########################

target_link_libraries(main tools_lib
)

########################
#   Unit tests         #
########################
set(${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/include)

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/utests/*.cpp)
enable_testing()


foreach(_test_file ${TEST_SRC_FILES})
    get_filename_component(_test_name ${_test_file} NAME_WE)
    add_executable(${_test_name} ${_test_file})
    target_link_libraries(${_test_name} gtest gtest_main serial_lib tools_lib ${CMAKE_THREAD_LIB_INIT})
    add_test(${_test_name} ${_test_name} WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
    set_tests_properties(${_test_name} PROPERTIES TIMEOUT 5)
endforeach()

