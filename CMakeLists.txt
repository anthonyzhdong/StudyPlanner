cmake_minimum_required(VERSION 3.10)

# Set the project name
project(cosc345project)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable(Add every file to this, space seperated)
add_executable(menu 
  menu.cpp 
  Calendar.h 
  Calendar.cpp 
  addPaper.h 
  addPaper.cpp 
  flashcard.h
  flashcard.cpp
  flashcardM.h
  flashcardM.cpp
  paper.h 
  paper.cpp 
  lab.h 
  lecture.h 
  tutorial.h 
  addNewEvent.h 
  addNewEvent.cpp 
  eventSkeleton.h 
  eventSkeleton.cpp 
  StudySession.h 
  StudySession.cpp 
  MenuItem.h 
  MenuItem.cpp
  validation.h
  validation.cpp
  CalendarFile.cpp
) 

# If you need to link against any libraries, you can use target_link_libraries
# target_link_libraries(menu some_library)

# If you have include directories, you can add them like this:
# target_include_directories(menu PUBLIC include_directory)

# Enable warnings
if(MSVC)
  target_compile_options(menu PRIVATE /W4)
else()
  target_compile_options(menu PRIVATE -Wall -Wextra -pedantic)
endif()

# Add the test executable
# Add the executable for the tests
add_executable(test_runner
    test.cpp 
    Calendar.h 
    Calendar.cpp 
    addPaper.h 
    addPaper.cpp 
    flashcard.h
    flashcard.cpp
    paper.h 
    paper.cpp 
    lab.h 
    lecture.h 
    tutorial.h 
    addNewEvent.h 
    addNewEvent.cpp 
    eventSkeleton.h 
    eventSkeleton.cpp 
    StudySession.h 
    StudySession.cpp 
    MenuItem.h 
    MenuItem.cpp
    validation.h
    validation.cpp
    CalendarFile.cpp
)
# Enable warnings for tests
if(MSVC)
  target_compile_options(test_runner PRIVATE /W4)
else()
  target_compile_options(test_runner PRIVATE -Wall -Wextra -pedantic)
endif()

# Copy input.txt to the build directory
configure_file(${CMAKE_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/input.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/input1.txt ${CMAKE_BINARY_DIR}/input1.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/input3.txt ${CMAKE_BINARY_DIR}/input3.txt COPYONLY)



# Add tests
enable_testing()
set(CTEST_OUTPUT_ON_FAILURE TRUE)

add_test(NAME ExampleTest COMMAND test_runner)
