cmake_minimum_required(VERSION 3.0.0)
project(SENSOR_BASE)

add_compile_options(-g -Wall -std=c++17)

include_directories(include include/serial/include)


########################
#   Define files      #
########################

#Serial library sources
file(GLOB serial_SRC "include/serial/src/serial.cc"
                     "include/seral/src/impl/list_ports/list_ports_linux.cc"
                     "include/serial/src/impl/unix.cc"
)
#Tools library sources
file(GLOB tools_SRC "src/Tools/*.cpp")

#GPIO library sources
file(GLOB GPIO_SRC "src/GPIO/*.cpp")

########################
#   Libraries          #
########################
#Tools library
add_library(tools_lib
        ${tools_SRC}
)
add_library(serial_lib
        ${serial_SRC}
)
add_library(GPIO_lib
        ${GPIO_SRC}
)

########################
#   Executables        #
########################
add_executable(main src/main.cpp)


########################
#   Linking            #
########################
target_link_libraries(main serial_lib 
                           tools_lib
)

########################
#   Unit tests         #
########################

add_executable(log_test utests/test_Logger.cpp)
add_executable(time_test utests/test_Time.cpp)
add_executable(GPIO_test utests/test_GPIO.cpp)

target_link_libraries(log_test tools_lib)
target_link_libraries(time_test tools_lib)
target_link_libraries(GPIO_test GPIO_lib)
