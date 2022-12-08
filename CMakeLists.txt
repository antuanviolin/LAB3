cmake_minimum_required(VERSION 3.21)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3 main.cpp readWAV.cpp readWAV.h writeWAV.cpp writeWAV.h converters.cpp converters.h readConfig.cpp readConfig.h soundProcessor.cpp convertersFactory.cpp convertersFactory.h soundProcessor.h sample.h wavHeader.h)
