cmake_minimum_required(VERSION 3.21)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3 main.cpp ReadWAV.cpp ReadWAV.h WriteWAV.cpp WriteWAV.h Converters.cpp Converters.h ReadConfig.cpp ReadConfig.h SoundProcessor.cpp ConvertersFactory.cpp ConvertersFactory.h SoundProcessor.h sample.h SampleClass.cpp SampleClass.h)
