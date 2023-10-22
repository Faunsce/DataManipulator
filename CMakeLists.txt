# CMakeList.txt : CMake project for DataManipulator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("DataManipulator")

# Add source to this project's executable.
add_executable (DataManipulator "DataManipulator.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DataManipulator PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
