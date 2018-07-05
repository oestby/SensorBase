cmake_minimum_required(VERSION 3.0.0)
project(SENSOR_BASE)

add_compile_options(-g -Wall -std=c++17)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include_directories(include)

########################
#   Define files      #
########################

#Tools library sources
file(GLOB tools_SRC "src/Tools/*.cpp")

#GPIO library sources
file(GLOB GPIO_SRC "src/GPIO/*.cpp")

#MOSI library sources
file(GLOB MOSI_SRC "src/MOSI/*.cpp")

########################
#   Libraries          #
########################

add_library(tools_lib
        ${tools_SRC}
)

add_library(GPIO_lib
        ${GPIO_SRC}
)

add_library(MOSI_lib
        ${MOSI_SRC}
)

#add_subdirectory(lib/serial)

add_subdirectory(lib/googletest)

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
    target_link_libraries(${_test_name} gtest gtest_main GPIO_lib tools_lib${CMAKE_THREAD_LIB_INIT})
    add_test(${_test_name} ${_test_name} WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
    set_tests_properties(${_test_name} PROPERTIES TIMEOUT 5)
endforeach()

