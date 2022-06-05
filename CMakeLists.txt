cmake_minimum_required(VERSION 3.21)
project(OOP_course_work)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_course_work
        main.cpp Models/Model.h Models/ModelManager.h Models/Date.cpp Models/DateManager.cpp Models/Person.cpp Models/PersonManager.cpp)
