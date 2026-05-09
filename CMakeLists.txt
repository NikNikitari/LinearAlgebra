cmake_minimum_required(VERSION 3.16)

project(LinearAlgebra VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(LinearAlgebra SHARED
    src/LinearAlgebra2D.cpp
    src/LinearAlgebra3D.cpp
    src/LinearAlgebra4D.cpp
)

target_include_directories(LinearAlgebra
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(LinearAlgebra PUBLIC cxx_std_17)

install(TARGETS LinearAlgebra
    EXPORT LinearAlgebraTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT LinearAlgebraTargets
    FILE LinearAlgebraTargets.cmake
    NAMESPACE LinearAlgebra::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/LinearAlgebra
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/LinearAlgebraConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/LinearAlgebraConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/LinearAlgebra
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/LinearAlgebraConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/LinearAlgebraConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/LinearAlgebraConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/LinearAlgebra
)

include(CTest)
if(BUILD_TESTING)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    add_executable(LinearAlgebraTests test/main_test.cpp)
    target_link_libraries(LinearAlgebraTests PRIVATE LinearAlgebra gtest_main)
    include(GoogleTest)
    gtest_discover_tests(LinearAlgebraTests)
endif()