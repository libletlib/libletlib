cmake_minimum_required(VERSION 3.10)

project(LibLetLib VERSION 0.99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (DEFINED LIBLETLIB_ERROR_EXCEPTION)
    add_definitions(-DLIBLETLIB_ERROR_EXCEPTION)
endif ()

if (DEFINED LIBLETLIB_ERROR_LONGJMP)
    add_definitions(-DLIBLETLIB_ERROR_LONGJMP)
endif ()

if (DEFINED LIBLETLIB_ERROR_ERRNO)
    add_definitions(-DLIBLETLIB_ERROR_ERRNO)
endif ()

if (DEFINED LIBLETLIB_ERROR_NONE)
    add_definitions(-DLIBLETLIB_ERROR_NONE)
endif ()

if (DEFINED LIBLETLIB_DISABLE_UCHAR)
    add_definitions(-DLIBLETLIB_DISABLE_UCHAR)
endif ()

if (DEFINED LIBLETLIB_ENABLE_UCHAR)
    remove_definitions(-DLIBLETLIB_DISABLE_UCHAR)
endif ()

if (DEFINED LIBLETLIB_FREESTANDING)
    add_definitions(-DLIBLETLIB_FREESTANDING)
endif ()

if (DEFINED LIBLETLIB_HOSTED)
    add_definitions(-DLIBLETLIB_HOSTED)
endif ()

if (DEFINED LIBLETLIB_DISABLE_MACRO)
    add_definitions(-DLIBLETLIB_DISABLE_MACRO)
endif ()

if (DEFINED LIBLETLIB_DISABLE_MACRO)
    add_definitions(-DLIBLETLIB_DISABLE_MACRO)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    if (APPLE)
        set(CMAKE_CXX_FLAGS "-DLIBLETLIB_DISABLE_UCHAR -Weverything -pedantic-errors -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-switch-enum -Wno-exit-time-destructors -Wno-global-constructors -Wno-format-nonliteral -Wno-missing-prototypes")
    else ()
        set(CMAKE_CXX_FLAGS "-Weverything -pedantic-errors -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-switch-enum -Wno-exit-time-destructors -Wno-global-constructors -Wno-format-nonliteral -Wno-missing-prototypes")
    endif ()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic-errors -Wno-switch-enum")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "/Wall /Zc:__cplusplus /EHsc /wd4061 /wd4068 /wd4668 /wd5045 /wd4514")
endif ()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}/bin>)
add_executable(test test.cpp libletlib/core/libletlib_behaviour.hpp libletlib/core/libletlib_var.hpp libletlib/core/libletlib_index_sequence.hpp libletlib/core/libletlib_rank_enum.hpp libletlib/core/libletlib_value_union.hpp libletlib/core/libletlib_size_struct.hpp libletlib/core/libletlib_forward_declarations.hpp libletlib/utility/libletlib_strings.hpp libletlib/utility/libletlib_format_constants.hpp libletlib/core/libletlib_memory.hpp libletlib/core/libletlib_math.hpp libletlib/core/libletlib_roots.hpp libletlib/core/libletlib_iterators.hpp libletlib/core/libletlib_error.hpp libletlib/conversions/libletlib_as_boolean.hpp libletlib/conversions/libletlib_as_character.hpp libletlib/conversions/libletlib_as_signed_character.hpp libletlib/conversions/libletlib_as_unsigned_character.hpp libletlib/conversions/libletlib_as_wide_character.hpp libletlib/conversions/libletlib_as_bit16_character.hpp libletlib/conversions/libletlib_as_bit32_character.hpp libletlib/conversions/libletlib_as_short.hpp libletlib/conversions/libletlib_as_unsigned_short.hpp libletlib/conversions/libletlib_as_integer.hpp libletlib/conversions/libletlib_as_unsigned_integer.hpp libletlib/conversions/libletlib_as_long.hpp libletlib/conversions/libletlib_as_unsigned_long.hpp libletlib/conversions/libletlib_as_long_long.hpp libletlib/conversions/libletlib_as_unsigned_long_long.hpp libletlib/conversions/libletlib_as_float.hpp libletlib/conversions/libletlib_as_double.hpp libletlib/conversions/libletlib_as_long_double.hpp libletlib/conversions/libletlib_as_string.hpp libletlib/conversions/libletlib_as_wide_string.hpp libletlib/conversions/libletlib_as_bit16_string.hpp libletlib/conversions/libletlib_as_bit32_string.hpp libletlib/conversions/libletlib_as_subroutine.hpp libletlib/conversions/libletlib_as_function.hpp libletlib/conversions/libletlib_as_array.hpp libletlib/conversions/libletlib_as_void_pointer.hpp libletlib/conversions/libletlib_as_null.hpp libletlib/operations/libletlib_sum.hpp libletlib/operations/libletlib_subtraction.hpp libletlib/operations/libletlib_multiplication.hpp libletlib/operations/libletlib_division.hpp libletlib/operations/libletlib_modulo.hpp libletlib/operations/libletlib_exponentiation.hpp libletlib/operations/libletlib_binary_and.hpp libletlib/operations/libletlib_binary_or.hpp libletlib/operations/libletlib_comparison.hpp libletlib/operations/libletlib_negative.hpp libletlib/operations/libletlib_positive.hpp libletlib/operations/libletlib_binary_xor.hpp libletlib/operations/libletlib_increment.hpp libletlib/operations/libletlib_decrement.hpp libletlib/operations/libletlib_negation.hpp libletlib/operations/libletlib_index.hpp libletlib/operations/libletlib_indirection.hpp libletlib/operations/libletlib_complement.hpp libletlib/utility/libletlib_pattern_matching.hpp libletlib/utility/libletlib_ranges.hpp libletlib/utility/libletlib_lists.hpp libletlib/utility/libletlib_miscellaneous.hpp libletlib/core/libletlib_value_union_implementation.hpp libletlib/utility/libletlib_field.hpp libletlib/core/libletlib_var_implementation.hpp libletlib/core/libletlib_lambda_capture.hpp libletlib/core/libletlib_math_implementation.hpp libletlib/conversions/libletlib_as_bit8_character.hpp libletlib/conversions/libletlib_as_bit8_string.hpp libletlib/core/libletlib_lambda_helper.hpp test.cpp libletlib/core/libletlib_lambda_curry.hpp libletlib/core/libletlib_type_id_enum.hpp)
