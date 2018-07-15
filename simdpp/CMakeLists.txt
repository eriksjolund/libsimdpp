#   Copyright (C) 2013  Povilas Kanapickas <povilas@radix.lt>
#
#   Distributed under the Boost Software License, Version 1.0.
#       (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

set(HEADERS
    capabilities.h
    core/align.h
    core/aligned_allocator.h
    core/bit_and.h
    core/bit_andnot.h
    core/bit_not.h
    core/bit_or.h
    core/bit_xor.h
    core/blend.h
    core/cache.h
    core/cast.h
    core/cmp_eq.h
    core/cmp_ge.h
    core/cmp_gt.h
    core/cmp_le.h
    core/cmp_lt.h
    core/cmp_neq.h
    core/combine.h
    core/detail/get_expr_bitwise.h
    core/detail/get_expr_uint.h
    core/detail/scalar_arg_impl.h
    core/detail/subvec_extract.h
    core/detail/subvec_insert.h
    core/extract.h
    core/extract_bits.h
    core/f_abs.h
    core/f_add.h
    core/f_ceil.h
    core/f_div.h
    core/f_floor.h
    core/f_fmadd.h
    core/f_fmsub.h
    core/f_isnan.h
    core/f_isnan2.h
    core/f_max.h
    core/f_min.h
    core/f_mul.h
    core/f_neg.h
    core/f_rcp_e.h
    core/f_rcp_rh.h
    core/f_reduce_add.h
    core/f_reduce_max.h
    core/f_reduce_min.h
    core/f_reduce_mul.h
    core/f_rsqrt_e.h
    core/f_rsqrt_rh.h
    core/f_sign.h
    core/f_sqrt.h
    core/f_sub.h
    core/f_trunc.h
    core/for_each.h
    core/i_abs.h
    core/i_add.h
    core/i_add_sat.h
    core/i_avg.h
    core/i_avg_trunc.h
    core/i_div_p.h
    core/i_max.h
    core/i_min.h
    core/i_mul.h
    core/i_mull.h
    core/i_neg.h
    core/i_popcnt.h
    core/i_reduce_add.h
    core/i_reduce_and.h
    core/i_reduce_max.h
    core/i_reduce_min.h
    core/i_reduce_mul.h
    core/i_reduce_or.h
    core/i_reduce_popcnt.h
    core/i_shift_l.h
    core/i_shift_r.h
    core/i_sub.h
    core/i_sub_sat.h
    core/insert.h
    core/load.h
    core/load_packed2.h
    core/load_packed3.h
    core/load_packed4.h
    core/load_splat.h
    core/load_u.h
    core/make_float.h
    core/make_int.h
    core/make_shuffle_bytes_mask.h
    core/make_uint.h
    core/move_l.h
    core/move_r.h
    core/permute2.h
    core/permute4.h
    core/permute_bytes16.h
    core/permute_zbytes16.h
    core/set_splat.h
    core/shuffle1.h
    core/shuffle2.h
    core/shuffle2x2.h
    core/shuffle4x2.h
    core/shuffle_bytes16.h
    core/shuffle_zbytes16.h
    core/splat.h
    core/splat_n.h
    core/split.h
    core/store.h
    core/store_first.h
    core/store_last.h
    core/store_masked.h
    core/store_packed2.h
    core/store_packed3.h
    core/store_packed4.h
    core/store_u.h
    core/stream.h
    core/test_bits.h
    core/to_float32.h
    core/to_float64.h
    core/to_int16.h
    core/to_int32.h
    core/to_int64.h
    core/to_int8.h
    core/to_mask.h
    core/transpose.h
    core/unzip_hi.h
    core/unzip_lo.h
    core/zip_hi.h
    core/zip_lo.h
    deprecations.h
    detail/align.h
    detail/align_v128.h
    detail/altivec/load1.h
    detail/array.h
    detail/cast.h
    detail/cast.inl
    detail/cast_bitwise.h
    detail/construct_eval.h
    detail/eval_scalar.h
    detail/expr/bit_and.h
    detail/expr/bit_andnot.h
    detail/expr/bit_not.h
    detail/expr/bit_or.h
    detail/expr/blend.h
    detail/expr/f_abs.h
    detail/expr/f_add.h
    detail/expr/f_fmadd.h
    detail/expr/f_fmsub.h
    detail/expr/f_mul.h
    detail/expr/f_neg.h
    detail/expr/f_sub.h
    detail/expr/i_abs.h
    detail/expr/i_add.h
    detail/expr/i_add_sat.h
    detail/expr/i_mul.h
    detail/expr/i_mull.h
    detail/expr/i_neg.h
    detail/expr/i_sub.h
    detail/expr/i_sub_sat.h
    detail/expr/scalar.h
    detail/expr/splat_n.h
    detail/expr/test_bits.h
    detail/expr/vec.h
    detail/extract128.h
    detail/for_each.h
    detail/get_expr.h
    detail/insn/align.h
    detail/insn/bit_and.h
    detail/insn/bit_andnot.h
    detail/insn/bit_not.h
    detail/insn/bit_or.h
    detail/insn/bit_xor.h
    detail/insn/blend.h
    detail/insn/cmp_eq.h
    detail/insn/cmp_ge.h
    detail/insn/cmp_gt.h
    detail/insn/cmp_le.h
    detail/insn/cmp_lt.h
    detail/insn/cmp_neq.h
    detail/insn/combine.h
    detail/insn/conv_any_to_float32.h
    detail/insn/conv_any_to_float64.h
    detail/insn/conv_extend_to_int16.h
    detail/insn/conv_extend_to_int32.h
    detail/insn/conv_extend_to_int64.h
    detail/insn/conv_float_to_int16.h
    detail/insn/conv_float_to_int32.h
    detail/insn/conv_float_to_int64.h
    detail/insn/conv_float_to_int8.h
    detail/insn/conv_shrink_to_int16.h
    detail/insn/conv_shrink_to_int32.h
    detail/insn/conv_shrink_to_int8.h
    detail/insn/conv_to_mask.h
    detail/insn/conv_to_mask.inl
    detail/insn/extract.h
    detail/insn/extract_bits.h
    detail/insn/f_abs.h
    detail/insn/f_add.h
    detail/insn/f_ceil.h
    detail/insn/f_div.h
    detail/insn/f_floor.h
    detail/insn/f_fmadd.h
    detail/insn/f_fmsub.h
    detail/insn/f_isnan.h
    detail/insn/f_isnan2.h
    detail/insn/f_max.h
    detail/insn/f_min.h
    detail/insn/f_mul.h
    detail/insn/f_neg.h
    detail/insn/f_rcp_e.h
    detail/insn/f_rcp_rh.h
    detail/insn/f_reduce_add.h
    detail/insn/f_reduce_max.h
    detail/insn/f_reduce_min.h
    detail/insn/f_reduce_mul.h
    detail/insn/f_rsqrt_e.h
    detail/insn/f_rsqrt_rh.h
    detail/insn/f_sign.h
    detail/insn/f_sqrt.h
    detail/insn/f_sub.h
    detail/insn/f_trunc.h
    detail/insn/i_abs.h
    detail/insn/i_add.h
    detail/insn/i_add_sat.h
    detail/insn/i_avg.h
    detail/insn/i_avg_trunc.h
    detail/insn/i_max.h
    detail/insn/i_min.h
    detail/insn/i_mul_hi.h
    detail/insn/i_mul_lo.h
    detail/insn/i_mull.h
    detail/insn/i_neg.h
    detail/insn/i_popcnt.h
    detail/insn/i_reduce_add.h
    detail/insn/i_reduce_and.h
    detail/insn/i_reduce_max.h
    detail/insn/i_reduce_min.h
    detail/insn/i_reduce_mul.h
    detail/insn/i_reduce_or.h
    detail/insn/i_reduce_popcnt.h
    detail/insn/i_shift.h
    detail/insn/i_shift_l.h
    detail/insn/i_shift_l_v.h
    detail/insn/i_shift_r.h
    detail/insn/i_shift_r_v.h
    detail/insn/i_sub.h
    detail/insn/i_sub_sat.h
    detail/insn/insert.h
    detail/insn/load.h
    detail/insn/load_packed2.h
    detail/insn/load_packed3.h
    detail/insn/load_packed4.h
    detail/insn/load_splat.h
    detail/insn/load_u.h
    detail/insn/make_const.h
    detail/insn/mem_pack.h
    detail/insn/mem_unpack.h
    detail/insn/move_l.h
    detail/insn/move_r.h
    detail/insn/permute2.h
    detail/insn/permute4.h
    detail/insn/permute_bytes16.h
    detail/insn/permute_zbytes16.h
    detail/insn/set_splat.h
    detail/insn/shuffle128.h
    detail/insn/shuffle2x2.h
    detail/insn/shuffle4x2.h
    detail/insn/shuffle_bytes16.h
    detail/insn/shuffle_emul.h
    detail/insn/shuffle_zbytes16.h
    detail/insn/splat.h
    detail/insn/splat_n.h
    detail/insn/split.h
    detail/insn/store.h
    detail/insn/store_first.h
    detail/insn/store_last.h
    detail/insn/store_masked.h
    detail/insn/store_packed2.h
    detail/insn/store_packed3.h
    detail/insn/store_packed4.h
    detail/insn/store_u.h
    detail/insn/stream.h
    detail/insn/test_bits.h
    detail/insn/transpose.h
    detail/insn/unzip_hi.h
    detail/insn/unzip_lo.h
    detail/insn/zip128.h
    detail/insn/zip_hi.h
    detail/insn/zip_lo.h
    detail/insn_id.h
    detail/mem_block.h
    detail/neon/math_int.h
    detail/neon/memory_store.h
    detail/neon/shuffle.h
    detail/not_implemented.h
    detail/null/bitwise.h
    detail/null/compare.h
    detail/null/mask.h
    detail/null/math.h
    detail/null/memory.h
    detail/null/set.h
    detail/null/shuffle.h
    detail/null/transpose.h
    detail/preprocess_single_arch.h
    detail/preprocessor.h
    detail/preprocessor/arithmetic/dec.hpp
    detail/preprocessor/arithmetic/inc.hpp
    detail/preprocessor/cat.hpp
    detail/preprocessor/config/config.hpp
    detail/preprocessor/control/expr_if.hpp
    detail/preprocessor/control/expr_iif.hpp
    detail/preprocessor/control/if.hpp
    detail/preprocessor/control/iif.hpp
    detail/preprocessor/debug/error.hpp
    detail/preprocessor/detail/auto_rec.hpp
    detail/preprocessor/detail/split.hpp
    detail/preprocessor/facilities/detail/is_empty.hpp
    detail/preprocessor/facilities/empty.hpp
    detail/preprocessor/facilities/expand.hpp
    detail/preprocessor/facilities/identity.hpp
    detail/preprocessor/facilities/is_1.hpp
    detail/preprocessor/facilities/is_empty.hpp
    detail/preprocessor/facilities/is_empty_variadic.hpp
    detail/preprocessor/facilities/overload.hpp
    detail/preprocessor/logical/bool.hpp
    detail/preprocessor/logical/compl.hpp
    detail/preprocessor/punctuation/comma.hpp
    detail/preprocessor/punctuation/comma_if.hpp
    detail/preprocessor/punctuation/detail/is_begin_parens.hpp
    detail/preprocessor/punctuation/is_begin_parens.hpp
    detail/preprocessor/punctuation/remove_parens.hpp
    detail/preprocessor/repetition/detail/for.hpp
    detail/preprocessor/repetition/detail/msvc/for.hpp
    detail/preprocessor/repetition/for.hpp
    detail/preprocessor/seq/detail/is_empty.hpp
    detail/preprocessor/seq/elem.hpp
    detail/preprocessor/seq/for_each.hpp
    detail/preprocessor/seq/for_each_i.hpp
    detail/preprocessor/seq/seq.hpp
    detail/preprocessor/seq/size.hpp
    detail/preprocessor/stringize.hpp
    detail/preprocessor/tuple/detail/is_single_return.hpp
    detail/preprocessor/tuple/eat.hpp
    detail/preprocessor/tuple/elem.hpp
    detail/preprocessor/tuple/enum.hpp
    detail/preprocessor/tuple/rem.hpp
    detail/preprocessor/tuple/size.hpp
    detail/preprocessor/tuple/to_seq.hpp
    detail/preprocessor/variadic/elem.hpp
    detail/preprocessor/variadic/size.hpp
    detail/preprocessor/variadic/to_seq.hpp
    detail/shuffle/neon_int16x8.h
    detail/shuffle/neon_int32x4.h
    detail/shuffle/neon_int64x2.h
    detail/shuffle/shuffle_mask.h
    detail/shuffle/sse_float32_4x2.h
    detail/shuffle/sse_float64_4x2.h
    detail/shuffle/sse_int32_4x2.h
    detail/shuffle/sse_int64_4x2.h
    detail/traits.h
    detail/vector_array_conv_macros.h
    detail/vector_array_macros.h
    detail/width.h
    detail/workarounds.h
    dispatch/arch.h
    dispatch/collect_macros_generated.h
    dispatch/dispatcher.h
    dispatch/get_arch_gcc_builtin_cpu_supports.h
    dispatch/get_arch_linux_cpuinfo.h
    dispatch/get_arch_raw_cpuid.h
    dispatch/get_arch_string_list.h
    dispatch/macros_generated.h
    dispatch/make_dispatcher.h
    dispatch/preprocess_single_compile_arch.h
    expr.h
    expr.inl
    operators/bit_and.h
    operators/bit_not.h
    operators/bit_or.h
    operators/bit_xor.h
    operators/cmp_eq.h
    operators/cmp_ge.h
    operators/cmp_gt.h
    operators/cmp_le.h
    operators/cmp_lt.h
    operators/cmp_neq.h
    operators/f_add.h
    operators/f_div.h
    operators/f_mul.h
    operators/f_sub.h
    operators/i_add.h
    operators/i_mul.h
    operators/i_shift_l.h
    operators/i_shift_r.h
    operators/i_sub.h
    setup_arch.h
    simd.h
    this_compile_arch.h
    types.h
    types/any.h
    types/empty_expr.h
    types/float32.h
    types/float32x16.h
    types/float32x4.h
    types/float32x8.h
    types/float64.h
    types/float64x2.h
    types/float64x4.h
    types/float64x8.h
    types/fwd.h
    types/generic.h
    types/int16.h
    types/int16x16.h
    types/int16x32.h
    types/int16x8.h
    types/int32.h
    types/int32x16.h
    types/int32x4.h
    types/int32x8.h
    types/int64.h
    types/int64x2.h
    types/int64x4.h
    types/int64x8.h
    types/int8.h
    types/int8x16.h
    types/int8x32.h
    types/int8x64.h
    types/tag.h
    types/traits.h
)

foreach(FILE ${HEADERS})
    get_filename_component(DIR_PATH "${FILE}" DIRECTORY)
    install(FILES "${FILE}" DESTINATION "${SIMDPP_INCLUDEDIR_ENDING}/simdpp/${DIR_PATH}")
endforeach()

# Don't enable header tests by default because configuring it takes excessive
# amount of time
set(ENABLE_HEADER_TESTS "0")

if(${ENABLE_HEADER_TESTS} STREQUAL "1")

    simdpp_get_compilable_archs(COMPILABLE_ARCHS)

    set(HEADER_TESTS "")
    add_custom_target(check_headers)

    foreach(ARCH ${COMPILABLE_ARCHS})
        simdpp_get_arch_info(CXX_FLAGS DEFINES_LIST SUFFIX ${ARCH})
        foreach(FILE ${HEADERS})

            if("${FILE}" STREQUAL ".inl")
                continue()
            endif()

            string(REPLACE "/" "_" TEST "${FILE}")
            string(REPLACE "." "_" TEST "${TEST}")
            set(TEST "${TEST}${SUFFIX}")
            set(TEST_OUT "check_headers/test_header_compiles_${TEST}")
            string(REPLACE "-" "_" TEST_TARGET "check_headers_${TEST}")


            file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/check_headers")
            separate_arguments(CXX_FLAGS)
            add_custom_command(
                OUTPUT ${TEST_OUT}
                COMMAND ${CMAKE_CXX_COMPILER}
                        -DLIBSIMDPP_SIMD_H
                        -I "${CMAKE_SOURCE_DIR}"
                        ${CXX_FLAGS} -x c++ -std=c++11 -g2 -Wall
                        ${CMAKE_SOURCE_DIR}/simdpp/${FILE}
                        -c -o ${CMAKE_BINARY_DIR}/${TEST_OUT}
                DEPENDS ${FILE} )
            add_custom_target(${TEST_TARGET} DEPENDS ${TEST_OUT})
            add_dependencies(check_headers "${TEST_TARGET}")
        endforeach()
    endforeach()
endif()

add_library(libsimdpp INTERFACE)
add_library(simdpp::libsimdpp ALIAS libsimdpp)

target_include_directories(libsimdpp
    INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${SIMDPP_INCLUDEDIR_ENDING}>
)

target_compile_features(libsimdpp INTERFACE cxx_std_11)

install(TARGETS libsimdpp EXPORT libsimdpp_Targets
  INCLUDES DESTINATION include
)

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

find_package(simd-compile-options REQUIRED)

foreach(simd_arch IN LISTS simd_architectures)
    add_library(${simd_arch} INTERFACE)
    add_library(libsimdpp::${simd_arch} ALIAS ${simd_arch})
    target_compile_definitions(${simd_arch} INTERFACE ${simd_arch})
    target_link_libraries(${simd_arch} INTERFACE simd-compile-options::${simd_arch} simdpp::libsimdpp)
    install(
        TARGETS
            ${simd_arch}
        EXPORT

            libsimdpp_Targets
        INCLUDES
        DESTINATION
            include
    )
endforeach()
