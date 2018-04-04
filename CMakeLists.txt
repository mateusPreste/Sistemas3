cmake_minimum_required(VERSION 3.9)
project(Schedule)

set(CMAKE_CXX_STANDARD 11)

add_executable(Schedule Sistemas3/src/main.cpp Sistemas3/src/Clock.cpp Sistemas3/src/Clock.h Sistemas3/src/Process.cpp Sistemas3/src/Process.h Sistemas3/src/Queue.cpp Sistemas3/src/Queue.h Sistemas3/src/Schedule.cpp Sistemas3/src/Schedule.h Sistemas3/src/Memory.cpp Sistemas3/src/Memory.h Sistemas3/src/IO.cpp Sistemas3/src/IO.h Sistemas3/src/CPU.cpp Sistemas3/src/CPU.h Sistemas3/src/Cycle_Element.cpp Sistemas3/src/Cycle_Element.h Sistemas3/src/Computer.cpp Sistemas3/src/Computer.h)