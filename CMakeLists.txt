cmake_minimum_required(VERSION 3.10)

# Set the project name
project(cosc345project)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(menu menu.cpp)

# If you have any additional source files, add them here
# add_executable(menu menu.cpp other_file.cpp another_file.cpp)

# If you need to link against any libraries, you can use target_link_libraries
# target_link_libraries(menu some_library)

# If you have include directories, you can add them like this:
# target_include_directories(menu PUBLIC include_directory)

# If you want to enable warnings, you can add:
if(MSVC)
  target_compile_options(menu PRIVATE /W4)
else()
  target_compile_options(menu PRIVATE -Wall -Wextra -Wpedantic)
endif()