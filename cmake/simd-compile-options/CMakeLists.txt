cmake_minimum_required(VERSION 3.11.4)
project(simd-compile-options
    VERSION
        0.9.0
    LANGUAGES
        CXX
)

cmake_policy(SET CMP0048 NEW)

set(simd_architectures 
    ARCH_X86_SSE2
    ARCH_X86_SSE3
    ARCH_X86_SSSE3
    ARCH_X86_SSE4_1
    ARCH_X86_POPCNT_INSN
    ARCH_X86_AVX
    ARCH_X86_AVX2
    ARCH_X86_AVX512F
    ARCH_X86_AVX512BW
    ARCH_X86_AVX512DQ
    ARCH_X86_AVX512VL
    ARCH_ARM_NEON
    ARCH_ARM64_NEON
)

foreach(simd_arch IN LISTS simd_architectures)
    add_library(${simd_arch} INTERFACE)
    add_library(simd-compile-options::${simd_arch} ALIAS ${simd_arch})
    add_executable(${simd_arch}_test ${simd_arch}.cc)
    set_target_properties(${simd_arch}_test PROPERTIES EXCLUDE_FROM_ALL TRUE)
    target_link_libraries(${simd_arch}_test PRIVATE ${simd_arch})
    install(
        TARGETS
            ${simd_arch}
        EXPORT
            simd-compile-options_Targets
    )
endforeach()

target_compile_options(ARCH_X86_SSE2
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-msse2>
    $<$<CXX_COMPILER_ID:Clang>:-msse2>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<PLATFORM_ID:Windows>>:/arch:SSE2>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<NOT:$<PLATFORM_ID:Windows>>>:-msse2>
    $<$<CXX_COMPILER_ID:MSVC>:/arch:SSE2>
)

target_compile_options(ARCH_X86_SSE3
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-msse3>
    $<$<CXX_COMPILER_ID:Clang>:-msse3>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<PLATFORM_ID:Windows>>:/arch:SSE3>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<NOT:$<PLATFORM_ID:Windows>>>:-msse3>
    $<$<CXX_COMPILER_ID:MSVC>:/arch:SSE2>
)

target_compile_options(ARCH_X86_SSSE3
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-mssse3>
    $<$<CXX_COMPILER_ID:Clang>:-mssse3>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<PLATFORM_ID:Windows>>:/arch:SSSE3>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<NOT:$<PLATFORM_ID:Windows>>>:-mssse3>
    $<$<CXX_COMPILER_ID:MSVC>:/arch:SSE2>
)

target_compile_options(ARCH_X86_SSE4_1
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-msse4.1>
    $<$<CXX_COMPILER_ID:Clang>:-msse4.1>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<PLATFORM_ID:Windows>>:/arch:SSE4.1>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<NOT:$<PLATFORM_ID:Windows>>>:-msse4.1>
    $<$<CXX_COMPILER_ID:MSVC>:/arch:SSE2>
)

target_compile_options(ARCH_X86_POPCNT_INSN
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-mssse3 -mpopcnt>
    $<$<CXX_COMPILER_ID:Clang>:-mssse3 -mpopcnt>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<PLATFORM_ID:Windows>>:/arch:SSE4.2>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<NOT:$<PLATFORM_ID:Windows>>>:-mssse3 -mpopcnt>
    $<$<CXX_COMPILER_ID:MSVC>:/arch:SSE4.2>
)

target_compile_options(ARCH_X86_AVX
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-mavx>
    $<$<CXX_COMPILER_ID:Clang>:-mavx>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<PLATFORM_ID:Windows>>:/arch:AVX>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<NOT:$<PLATFORM_ID:Windows>>>:-mavx>
    $<$<CXX_COMPILER_ID:MSVC>:/arch:AVX>
)

target_compile_options(ARCH_X86_AVX2
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-mavx2>
    $<$<CXX_COMPILER_ID:Clang>:-mavx2>
    $<$<CXX_COMPILER_ID:MSVC>:/arch:AVX>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<PLATFORM_ID:Windows>>:/arch:CORE-AVX2>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<NOT:$<PLATFORM_ID:Windows>>>:-xCORE-AVX2>
)

target_compile_options(ARCH_X86_AVX512F
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-mavx512f -O1>
    $<$<CXX_COMPILER_ID:Clang>:-mavx512f -O1>
    $<$<CXX_COMPILER_ID:MSVC>:The ARCH_X86_AVX512F is not supported for MSVC. Hopefully these words should generate an error.>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<PLATFORM_ID:Windows>>:/arch:COMMON-AVX512>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<NOT:$<PLATFORM_ID:Windows>>>:-xCOMMON-AVX512>
)

target_compile_options(ARCH_X86_AVX512BW
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-mavx512bw>
    $<$<CXX_COMPILER_ID:Clang>:-mavx512bw>
    $<$<CXX_COMPILER_ID:MSVC>:The ARCH_X86_AVX512BW is not supported for MSVC. Hopefully these words should generate an error.>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<PLATFORM_ID:Windows>>:/arch:CORE-AVX512>
    $<$<AND:$<CXX_COMPILER_ID:Intel>,$<NOT:$<PLATFORM_ID:Windows>>>:-xCORE-AVX512>
)

target_compile_options(ARCH_X86_AVX512DQ
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-mavx512dq>
    $<$<CXX_COMPILER_ID:Clang>:-mavx512dq>
    $<$<CXX_COMPILER_ID:Intel>:-mavx512dq>
    $<$<CXX_COMPILER_ID:MSVC>:The ARCH_X86_AVX512DQ is not supported for MSVC. Hopefully these words should generate an error.>
)

target_compile_options(ARCH_X86_AVX512VL
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-mavx512vl>
    $<$<CXX_COMPILER_ID:Clang>:-mavx512vl>
    $<$<CXX_COMPILER_ID:Intel>:-mavx512vl>
    $<$<CXX_COMPILER_ID:MSVC>:The ARCH_X86_AVX512DQ is not supported for MSVC. Hopefully these words should generate an error.>
)

target_compile_options(ARCH_ARM_NEON
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-mfpu=neon>
    $<$<AND:$<CXX_COMPILER_ID:Clang>,$<VERSION_LESS_EQUAL:$<CXX_COMPILER_VERSION>,3.3.0>>:The clang compiler version <= 3.3 does not support ARM_NEON>
#    $<$<AND:$<CXX_COMPILER_ID:Clang>,$<NOT:$<VERSION_LESS_EQUAL:$<CXX_COMPILER_VERSION>,3.3.0>>>-mfpu=neon>    
    $<$<CXX_COMPILER_ID:Intel>:I guess ARM_NEON is not supported by the Intel compiler>
    $<$<CXX_COMPILER_ID:MSVC>:I guess ARM_NEON is not supported by the MSVC compiler>
)

target_compile_options(ARCH_ARM64_NEON
    INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-mcpu=generic+simd>
    $<$<CXX_COMPILER_ID:Clang>:-arch arm64>
    $<$<CXX_COMPILER_ID:Intel>:I guess ARM64_NEON is not supported by the Intel compiler>
    $<$<CXX_COMPILER_ID:MSVC>:I guess ARM64_NEON is not supported by the MSVC compiler>
)

set(cmake_configuration_install_dir lib/cmake/simd-compile-options)

install(
    EXPORT
        simd-compile-options_Targets
    DESTINATION
        ${cmake_configuration_install_dir}
    FILE
        simd-compile-options_Targets.cmake
    NAMESPACE
        simd-compile-options::
)

export(
    EXPORT
        simd-compile-options_Targets
    FILE
        simd-compile-options_Targets.cmake
    NAMESPACE
        simd-compile-options::
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("simd-compile-optionsConfigVersion.cmake"
    VERSION
        ${CMAKE_PROJECT_VERSION}
    COMPATIBILITY
        SameMajorVersion
)

configure_file(simd-compile-optionsConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/simd-compile-optionsConfig.cmake COPYONLY)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/Export/${cmake_configuration_install_dir}/simd-compile-options_Targets.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/simd-compile-optionsConfigVersion.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/simd-compile-optionsConfig.cmake
    DESTINATION
        ${cmake_configuration_install_dir}
)
