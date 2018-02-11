#   Copyright (C) 2011-2013  Povilas Kanapickas <povilas@radix.lt>
#
#   Distributed under the Boost Software License, Version 1.0.
#       (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

# CMake 3.8 introduced target compile feature: cxx_std_11
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(libsimdpp VERSION 2.1 LANGUAGES CXX)
set(SIMDPP_API_VERSION "2.1")

set(PKG_NAME "${CMAKE_PROJECT_NAME}")
set(PKG_FULL_NAME "${CMAKE_PROJECT_NAME}-${PROJECT_VERSION}")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
# ------------------------------------------------------------------------------
# Custom make dist target. Assumes source directory is a git repository.

set(ARCHIVE_NAME "${PKG_FULL_NAME}")
set(ARCHIVE_DIR "${PKG_FULL_NAME}")

add_custom_target(dist
    COMMAND cd "${CMAKE_SOURCE_DIR}" && ./make_dist.sh "${ARCHIVE_DIR}" "${CMAKE_BINARY_DIR}/${ARCHIVE_NAME}.tar.gz"
    # we may append to the archive now if needed
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# ------------------------------------------------------------------------------
# Check what instruction sets the current host supports. Use them for testing
include(SimdppMultiarch)
message(STATUS "Checking instruction set support in the compiler...")
simdpp_get_compilable_archs(COMPILABLE_ARCHS)
message(STATUS "Checking instruction sets to run tests for on this host...")
simdpp_get_runnable_archs(NATIVE_ARCHS)
# ------------------------------------------------------------------------------

set(SIMDPP_INCLUDEDIR_ENDING "include/${PKG_NAME}-${SIMDPP_API_VERSION}")
set(SIMDPP_INCLUDEDIR "${CMAKE_INSTALL_PREFIX}/${SIMDPP_INCLUDEDIR_ENDING}")
set(SIMDPP_DOCDIR "${CMAKE_INSTALL_PREFIX}/share/doc/${PKG_NAME}")
set(SIMDPP_PKGCONFIGDIR "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig")

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/libsimdpp.pc.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PKG_NAME}-${SIMDPP_API_VERSION}.pc" @ONLY
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PKG_NAME}-${SIMDPP_API_VERSION}.pc"
    DESTINATION "${SIMDPP_PKGCONFIGDIR}"
)


enable_testing()

add_subdirectory(simdpp)
add_subdirectory(test)

set(cmake_configuration_install_dir lib/cmake/libsimdpp)

install(
    EXPORT
        libsimdpp_Targets
    DESTINATION
        ${cmake_configuration_install_dir}
    FILE
        libsimdpp_Targets.cmake
    NAMESPACE
        libsimdpp::
)

export(
    EXPORT
        libsimdpp_Targets
    FILE
        libsimdpp_Targets.cmake
    NAMESPACE
        libsimdpp::
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("libsimdppConfigVersion.cmake"
    VERSION
        ${SIMDPP_API_VERSION}
    COMPATIBILITY
        SameMajorVersion
)

configure_file(cmake/libsimdppConfig.cmake.in ${CMAKE_BINARY_DIR}/libsimdppConfig.cmake COPYONLY)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/Export/${cmake_configuration_install_dir}/libsimdpp_Targets.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/libsimdppConfigVersion.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/libsimdppConfig.cmake
    DESTINATION
        ${cmake_configuration_install_dir}
)
