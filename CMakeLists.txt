cmake_minimum_required(VERSION 3.5)

project(PyWrap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PACKAGE_VERSION "0.0.1")

find_package(PythonInterp 3)
find_package(PythonLibs 3)
find_package(Python3 COMPONENTS Interpreter Development)
find_package(Boost 1.67 REQUIRED COMPONENTS python38)

if (${PYTHON3_FOUND})
    message("Python3FOUND: ${Python3_FOUND}")
    message("Python3 found at: " ${Python3_EXECUTABLE})
    message("Python VERSION: ${Python3_VERSION}")
    message("Python Development FOUND: ${Python3_Development_FOUND}")
    message("Python LIBS DIR: ${Python3_LIBRARIES}")
    message("Python INCLUDES DIR: ${Python3_INCLUDE_DIRS}")
    include_directories(${Python3_INCLUDE_DIRS})
endif()

set(SETUP_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in")
set(SETUP_PY    "${CMAKE_CURRENT_BINARY_DIR}/setup.py")
#set(DEPS        "${CMAKE_CURRENT_SOURCE_DIR}/module/__init__.py")
#set(OUTPUT      "${CMAKE_CURRENT_BINARY_DIR}/build/timestamp")

configure_file(${SETUP_PY_IN} ${SETUP_PY})

# add_custom_command(OUTPUT ${OUTPUT}
#    COMMAND ${PYTHON} ${SETUP_PY} build
#    COMMAND ${CMAKE_COMMAND} -E touch ${OUTPUT}
#    DEPENDS ${DEPS})

#add_custom_target(target ALL DEPENDS ${OUTPUT})

#install(CODE "execute_process(COMMAND ${PYTHON} ${SETUP_PY} install)")

file(GLOB MODEL_SOURCES
    src/*.cpp
    src/*.hpp
    )

file(COPY pyWrap DESTINATION .)
#file(COPY setup.py DESTINATION .)
file(COPY README.md DESTINATION .)
file(COPY LICENSE DESTINATION .)
PYTHON_ADD_MODULE(person src/person.hpp src/pyPerson.cpp)
PYTHON_ADD_MODULE(animal src/animal.hpp src/pyAnimal.cpp)
set_target_properties(person PROPERTIES OUTPUT_NAME pyWrap/person/_person)
set_target_properties(animal PROPERTIES OUTPUT_NAME pyWrap/animal/_animal)

target_link_libraries(person Boost::python38)
target_link_libraries(animal Boost::python38)
