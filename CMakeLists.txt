cmake_minimum_required(VERSION 3.10)

project(LinearAlgebra)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(LinearAlgebra SHARED src/LinearAlgebra2D.cpp src/LinearAlgebra3D.cpp src/LinearAlgebra4D.cpp)
target_include_directories(LinearAlgebra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(LinearAlgebraTests test/main_test.cpp)

target_link_libraries(LinearAlgebraTests
	PRIVATE LinearAlgebra gtest_main
)

set_target_properties(LinearAlgebraTests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)

add_custom_command(TARGET LinearAlgebraTests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:LinearAlgebra>
        $<TARGET_FILE_DIR:LinearAlgebraTests>
)

include(GoogleTest)
gtest_discover_tests(LinearAlgebraTests)