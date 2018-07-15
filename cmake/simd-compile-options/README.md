# simd-compile-options

This directory is not dependent of the rest of libsimdpp and
could be moved out into its own GitHub repository.

# Example

This code

    find_package(simd-compile-options REQUIRED)
    add_executable(myprog main.cc)
    target_link_libraries(myprog PRIVATE simd-compile-options::ARCH_X86_AVX2)

will compile main.cc with AVX2 support enabled. Transparently the CMAKE INTERFACE library 
simd-compile-options::ARCH_X86_AVX2 will enable appropriate command line options for 
different compilers (GCC, Clang, Intel and MSVC). Note that the CMAKE INTERFACE library
simd-compile-options::ARCH_X86_AVX2 does not contain any C/C++ code. It just contains
usage requirements (i.e. the compiler command line options).



