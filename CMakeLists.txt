cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME Stack)
project(${PROJECT_NAME})


set(LIBRARY "${PROJECT_NAME}")
set(TESTS  "test_${PROJECT_NAME}")


set(stacklib StackLib)
set(formulalib FormulaLib)
set(stack Stack)
set(formula Formula)
set(stringlib StringLib)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StringLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/FormulaLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StringLib)

add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StringLib)
add_subdirectory(Formula)
add_subdirectory(FormulaLib)
add_subdirectory(gtest)
add_subdirectory(test)
add_subdirectory(StringLib)

