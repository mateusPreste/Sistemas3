project(Schedule)

set(CMAKE_CXX_STANDARD 11)

add_executable(Schedule src/main.cpp src/Clock.cpp src/Clock.h src/Process.cpp src/Process.h src/Queue.cpp src/Queue.h src/Schedule.cpp src/Schedule.h src/Memory.cpp src/Memory.h src/IO.cpp src/IO.h src/CPU.cpp src/CPU.h src/Cycle_Element.cpp src/Cycle_Element.h src/Computer.cpp src/Computer.h)
