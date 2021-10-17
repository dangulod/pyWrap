cmake_minimum_required(VERSION 3.5)

project(PyWrap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PACKAGE_VERSION "0.0.1")

find_package(PythonInterp 3)
find_package(PythonLibs 3)
find_package(Python3 COMPONENTS Interpreter Development)
find_package(Boost 1.67 REQUIRED COMPONENTS python3)

if (${PYTHON3_FOUND})
    message(STATUS "Python3 found: ${Python3_FOUND}")
    message(STATUS "Python3 found at: " ${Python3_EXECUTABLE})
    message(STATUS "Python VERSION: ${Python3_VERSION}")
    message(STATUS "Python Development FOUND: ${Python3_Development_FOUND}")
    message(STATUS "Python LIBS DIR: ${Python3_LIBRARIES}")
    message(STATUS "Python INCLUDES DIR: ${Python3_INCLUDE_DIRS}")
    include_directories(${Python3_INCLUDE_DIRS})
endif()

set(SETUP_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in")
set(SETUP_PY    "${CMAKE_CURRENT_BINARY_DIR}/setup.py")

configure_file(${SETUP_PY_IN} ${SETUP_PY})

file(GLOB_RECURSE pyfiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.py" "README.md" "LICENSE")
foreach (filename ${pyfiles})
    message(STATUS "Copying ${filename} to ${CMAKE_CURRENT_BINARY_DIR}/${filename}")
    configure_file("${filename}" "${CMAKE_CURRENT_BINARY_DIR}/${filename}" COPYONLY)
endforeach (filename)

file(GLOB MODEL_SOURCES
    src/*.cpp
    src/*.hpp
    )

PYTHON_ADD_MODULE(person src/person.hpp src/pyPerson.cpp)
PYTHON_ADD_MODULE(animal src/animal.hpp src/pyAnimal.cpp)
set_target_properties(person PROPERTIES OUTPUT_NAME pyWrap/person/_person)
set_target_properties(animal PROPERTIES OUTPUT_NAME pyWrap/animal/_animal)

target_link_libraries(person Boost::python3)
target_link_libraries(animal Boost::python3)
