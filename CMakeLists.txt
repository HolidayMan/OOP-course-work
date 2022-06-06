cmake_minimum_required(VERSION 3.21)
project(OOP_course_work)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_course_work
        main.cpp models/Model.h models/ModelManager.h models/fields/Date.cpp models/Person.cpp models/PersonManager.cpp models/PersonInQueue.cpp models/PersonInQueueManager.cpp models/fields/Field.h utils.cpp models/Person.h models/PersonManager.h models/fields/Date.h models/PersonInQueue.h models/PersonInQueueManager.h)
