cmake_minimum_required(VERSION 3.5)
project(libOpenSimplexNoise VERSION 1.0.0 LANGUAGES CXX)

find_package(benchmark REQUIRED)

add_library(OpenSimplexNoise 
    OpenSimplexNoise/OpenSimplexNoise.cpp
    OpenSimplexNoise/OpenSimplexNoise.h
)

add_library(OpenSimplexNoise::OpenSimplexNoise ALIAS OpenSimplexNoise)

target_include_directories(OpenSimplexNoise
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/OpenSimplexNoise>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/OpenSimplexNoise
)

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/OpenSimplexNoise)

install(TARGETS OpenSimplexNoise
    EXPORT opensimplexnoise-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION include
)

install(EXPORT opensimplexnoise-targets
    FILE
        OpenSimplexNoiseTargets.cmake
    NAMESPACE
        OpenSimplexNoise::
    DESTINATION
        ${INSTALL_CONFIGDIR}
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/OpenSimplexNoiseConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/OpenSimplexNoiseConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/OpenSimplexNoiseConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/OpenSimplexNoiseConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/OpenSimplexNoiseConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

export(EXPORT opensimplexnoise-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/OpenSimplexNoiseTargets.cmake
    NAMESPACE OpenSimplexNoise::
)

# Register package in users package registry
export(PACKAGE OpenSimplexNoise)


add_executable(noise_benchmark benchmark.cpp)

target_link_libraries(noise_benchmark OpenSimplexNoise)
target_link_libraries(noise_benchmark benchmark)


