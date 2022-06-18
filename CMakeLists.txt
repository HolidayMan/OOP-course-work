cmake_minimum_required(VERSION 3.21)
project(OOP_course_work)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_course_work
        main.cpp models/Model.h models/ModelManager.h models/fields/Date.cpp models/Person.cpp models/PersonManager.cpp models/PersonInQueue.cpp models/PersonInQueueManager.cpp models/fields/Field.h utils.cpp models/Person.h models/PersonManager.h models/fields/Date.h models/PersonInQueue.h models/PersonInQueueManager.h models/Dwelling.cpp models/Dwelling.h models/DwellingManager.cpp models/DwellingManager.h DBWorker.cpp DBWorker.h Constants.h Exceptions.cpp Exceptions.h Tests.cpp Tests.h views/View.h views/MainView.cpp views/MainView.h utils.h controllers/Controller.h views/DwellingView.cpp views/DwellingView.h controllers/MainScreenController.cpp controllers/MainScreenController.h controllers/ManagePeopleController.cpp controllers/ManagePeopleController.h controllers/Controller.cpp controllers/ManageDwellingsController.cpp controllers/ManageDwellingsController.h controllers/ManageQueueController.cpp controllers/ManageQueueController.h views/ManageDwellingsView.cpp views/ManageDwellingsView.h models/Filter.cpp models/Filter.h controllers/DisplayDwellingsController.cpp controllers/DisplayDwellingsController.h controllers/SearchDwellingController.cpp controllers/SearchDwellingController.h controllers/AddDwellingController.cpp controllers/AddDwellingController.h views/DisplayDwellingsView.cpp views/DisplayDwellingsView.h views/SearchDwellingsView.cpp views/SearchDwellingsView.h views/PromptView.cpp views/PromptView.h controllers/DisplayPeopleController.cpp controllers/DisplayPeopleController.h controllers/AddPersonController.cpp controllers/AddPersonController.h views/MenuListView.cpp views/MenuListView.h models/QueueDwelling.cpp models/QueueDwelling.h views/DisplayPeopleView.cpp views/DisplayPeopleView.h views/DisplayQueueView.cpp views/DisplayQueueView.h views/ChooseDwellingView.cpp views/ChooseDwellingView.h)
include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(OOP_course_work sqlite3)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0 COMPONENTS)
target_link_libraries(OOP_course_work Boost::boost)

