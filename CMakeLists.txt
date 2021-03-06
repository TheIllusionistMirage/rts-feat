# CMake build script for rts-feat, a simple isometric AoE like RTS
# Website: https://github.com/TheIllusionistMirage/rts-feat

cmake_minimum_required(VERSION 3.0)
project(rtsfeat)

# Set the default build type as Debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
      "Choose the type of build, options are: Debug Release."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# Set approriate compiler options depending upon the build type
if(CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Wnull-dereference -g")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

# Tell CMake about the FindSFML.cmake module
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/;${CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR}")

# Specify include directory
include_directories("${PROJECT_SOURCE_DIR}/include/")

# Specify the source directories
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp"
                  "${PROJECT_SOURCE_DIR}/src/AnimationManager/*.cpp"
                  "${PROJECT_SOURCE_DIR}/src/WorldEntities/EntityComponents/*.cpp"
                  "${PROJECT_SOURCE_DIR}/src/TileMap/*.cpp"
                  "${PROJECT_SOURCE_DIR}/src/ComponentManager/*.cpp"
                  "${PROJECT_SOURCE_DIR}/src/GameStates/*.cpp"
                  "${PROJECT_SOURCE_DIR}/src/ResourceManager/*.cpp"
                  "${PROJECT_SOURCE_DIR}/src/UI/*.cpp"
                  "${PROJECT_SOURCE_DIR}/src/UI/Components/*.cpp"
                  "${PROJECT_SOURCE_DIR}/src/UIManager/*.cpp"
                  "${PROJECT_SOURCE_DIR}/src/Utility/*.cpp")
                  
# Copy the `resources` directory to the build location
file(COPY assets DESTINATION .)

# SFML requires linking the main module if on Windows
if (SFML_OS_WINDOWS AND SFML_COMPILER_MSVC)
    find_package( SFML 2 COMPONENTS main audio network graphics window system REQUIRED )
else()
    find_package( SFML 2 COMPONENTS audio network graphics window system REQUIRED )
endif()

# If SFML was found, tell CMake about the include directories
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
else()
    set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
    message("\nSFML directory not found. Set SFML_ROOT to SFML's top-level path (containing \"include\" and \"lib\" directories).")
    message("Make sure the SFML libraries with the same configuration (Release/Debug, Static/Dynamic) exist.\n")
endif()

add_executable(rtsfeat ${SOURCES})

# Link SFML
target_link_libraries(rtsfeat ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# Require C++14 or above compliant compiler
set_property(TARGET rtsfeat PROPERTY CXX_STANDARD 14)
set_property(TARGET rtsfeat PROPERTY CXX_STANDARD_REQUIRED ON)
