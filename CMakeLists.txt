cmake_minimum_required(VERSION 3.15)
project(worker_mangement)

set(CMAKE_CXX_STANDARD 14)

add_executable(worker_mangement workerManager.cpp workerManager.h system.cpp work.cpp work.h Employee.cpp Employee.h Manager.cpp Manager.h Boss.cpp Boss.h)