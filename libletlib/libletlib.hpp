// Copyright (c) 2020-2021, Ville Rissanen
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// __        __  __        __                    __      __        __  __
// /  |      /  |/  |      /  |                  /  |    /  |      /  |/  |
// $$ |      $$/ $$ |____  $$ |        ______   _$$ |_   $$ |      $$/ $$ |____
// $$ |      /  |$$      \ $$ |       /      \ / $$   |  $$ |      /  |$$      \.
// $$ |      $$ |$$$$$$$  |$$ |      /$$$$$$  |$$$$$$/   $$ |      $$ |$$$$$$$  |
// $$ |      $$ |$$ |  $$ |$$ |      $$    $$ |  $$ | __ $$ |      $$ |$$ |  $$ |
// $$ |_____ $$ |$$ |__$$ |$$ |_____ $$$$$$$$/   $$ |/  |$$ |_____ $$ |$$ |__$$ |
// $$       |$$ |$$    $$/ $$       |$$       |  $$  $$/ $$       |$$ |$$    $$/
// $$$$$$$$/ $$/ $$$$$$$/  $$$$$$$$/  $$$$$$$/    $$$$/  $$$$$$$$/ $$/ $$$$$$$/

/// \file libletlib.hpp
/// \brief Implements ducktyping class var/var const for C++.
///  var is previous class that can hold any fundamental type,
///  string, wide string, pointer, array, MetaRoot derived object, function and subroutine (and nullptr_t C++11).
///
///  var is compliant with all standard versions of C++.

#ifndef LIBLETLIB_HPP
/// \def LIBLETLIB_HPP
/// Include guard.
#define LIBLETLIB_HPP

#ifdef __cplusplus

	/// If the standard macro __STDC_HOSTED__ for freestanding mode is enabled,
	/// force freestanding mode in libletlib also.
	#if (__STDC_HOSTED__ == 0)
		#define LIBLETLIB_FREESTANDING
		#define LIBLETLIB_DISABLE_UCHAR
		#undef LIBLETLIB_HOSTED
		#undef LIBLETLIB_ERROR_LONGJMP
		#undef LIBLETLIB_ERROR_ERRNO
	#else
		#undef LIBLETLIB_FREESTANDING
	#endif

	#ifndef LIBLETLIB_ERROR_EXCEPTION
		#ifndef LIBLETLIB_ERROR_LONGJMP
			#ifndef LIBLETLIB_ERROR_ERRNO
				#ifndef LIBLETLIB_ERROR_NONE
					#define LIBLETLIB_ERROR_EXCEPTION
				#endif
			#endif
		#endif
	#endif

	#if (__cplusplus < 201103L)
		/// \def LIBLETLIB_EDOM
		/// Defines EDOM (Maths domain error), in case it was not defined.
		/// If defined, use EDOM value from <cerrno>
		#define LIBLETLIB_EDOM erroneous_domain
		/// \def LIBLETLIB_ERANGE
		/// Defines ERANGE (Out of range error), in case it was not defined.
		/// If defined, use ERANGE value from <cerrno>
		#define LIBLETLIB_ERANGE out_of_range
		/// \def LIBLETLIB_ENOTSUP
		/// Defines ENOTSUP (Not supported error), in case it was not defined.
		/// If defined, use ENOTSUP value from <cerrno>
		#define LIBLETLIB_ENOTSUP not_supported
	#else
		/// \def LIBLETLIB_EDOM
		/// Defines EDOM (Maths domain error), in case it was not defined.
		/// If defined, use EDOM value from <cerrno>
		#define LIBLETLIB_EDOM error_enumeration::erroneous_domain
		/// \def LIBLETLIB_ERANGE
		/// Defines ERANGE (Out of range error), in case it was not defined.
		/// If defined, use ERANGE value from <cerrno>
		#define LIBLETLIB_ERANGE error_enumeration::out_of_range
		/// \def LIBLETLIB_ENOTSUP
		/// Defines ENOTSUP (Not supported error), in case it was not defined.
		/// If defined, use ENOTSUP value from <cerrno>
		#define LIBLETLIB_ENOTSUP error_enumeration::not_supported
	#endif

	/// Error handling macros
	/// Libletlib supports four different types of error handling:
	/// 1. C++ exceptions (default and freestanding supported). LIBLETLIB_ERROR_EXCEPTION
	/// 2. std::longjmp with default or user defined callback function. LIBLETLIB_ERROR_LONGJMP
	/// 3. C style error code reporting via <cerrno>. LIBLETLIB_ERROR_ERRNO
	/// 4. No errors. LIBLETLIB_ERROR_NONE
	#ifdef LIBLETLIB_ERROR_EXCEPTION

		#include <exception>

		#ifndef LIBLETLIB_FREESTANDING
			#include <cerrno>
		#endif
		#ifndef NDEBUG
			#ifndef LIBLETLIB_FREESTANDING
				/// \def LIBLETLIB_ERROR(message, error_code)
				/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
				/// If NDEBUG is not defined, also print out the file and line where the error occurred and
				/// the message if unavailable using the selected error handling mechanism (non-exceptions).
				#define LIBLETLIB_ERROR(message, error_code)                                                           \
					std::cerr << __FILE__ << ":" << __LINE__ << ": error: " << (message) << std::endl;                 \
					switch (error_code)                                                                                \
					{                                                                                                  \
						case static_cast<int>(LIBLETLIB_EDOM):                                                         \
							throw std::domain_error(message);                                                          \
						case static_cast<int>(LIBLETLIB_ENOTSUP):                                                      \
							throw std::runtime_error(message);                                                         \
						case static_cast<int>(LIBLETLIB_ERANGE):                                                       \
							throw std::range_error(message);                                                           \
					}
			#else
				/// \def LIBLETLIB_ERROR(message, error_code)
				/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
				/// If NDEBUG is not defined, also print out the file and line where the error occurred and
				/// the message if unavailable using the selected error handling mechanism (non-exceptions).
				#define LIBLETLIB_ERROR(message, error_code) throw var(message);
			#endif
		#else
			/// \def LIBLETLIB_ERROR(message, error_code)
			/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
			/// If NDEBUG is not defined, also print out the file and line where the error occurred and
			/// the message if unavailable using the selected error handling mechanism (non-exceptions).
			#define LIBLETLIB_ERROR(message, error_code) throw var(message);
		#endif
		/// \def LIBLETLIB_NOEXCEPT
		/// Define throwing functions as not-noexcept when using LIBLETLIB_ERROR_EXCEPTION
		/// otherwise all functions are nonexcept.
		#define LIBLETLIB_NOEXCEPT
		#undef LIBLETLIB_ERROR_LONGJMP
		#undef LIBLETLIB_ERROR_ERRNO
		#undef LIBLETLIB_ERROR_NONE
	#elif defined LIBLETLIB_ERROR_LONGJMP
		#include <csetjmp>
		#include <cerrno>

		#if (__cplusplus >= 201103L)
			#ifndef NDEBUG
				/// \def LIBLETLIB_ERROR(message, error_code)
				/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
				/// If NDEBUG is not defined, also print out the file and line where the error occurred and
				/// the message if unavailable using the selected error handling mechanism (non-exceptions).
				#define LIBLETLIB_ERROR(message, error_code)                                                           \
					std::cerr << __FILE__ << ":" << __LINE__ << ": error: " << (message) << std::endl;                 \
					std::longjmp(libletlib::detail::LIBLETLIB_JMP_BUF, error_code);
			#else
				/// \def LIBLETLIB_ERROR(message, error_code)
				/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
				/// If NDEBUG is not defined, also print out the file and line where the error occurred and
				/// the message if unavailable using the selected error handling mechanism (non-exceptions).
				#define LIBLETLIB_ERROR(message, error_code)                                                           \
					std::longjmp(libletlib::detail::LIBLETLIB_JMP_BUF, error_code);
			#endif
		#else
			#ifndef NDEBUG
				/// \def LIBLETLIB_ERROR(message, error_code)
				/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
				/// If NDEBUG is not defined, also print out the file and line where the error occurred and
				/// the message if unavailable using the selected error handling mechanism (non-exceptions).
				#define LIBLETLIB_ERROR(message, error_code)                                                           \
					std::cerr << __FILE__ << ":" << __LINE__ << ": error: " << (message) << std::endl;                 \
					std::longjmp(libletlib::detail::LIBLETLIB_JMP_BUF, EDOM);
			#else
				/// \def LIBLETLIB_ERROR(message, error_code)
				/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
				/// If NDEBUG is not defined, also print out the file and line where the error occurred and
				/// the message if unavailable using the selected error handling mechanism (non-exceptions).
				#define LIBLETLIB_ERROR(message, error_code) std::longjmp(libletlib::detail::LIBLETLIB_JMP_BUF, EDOM);
			#endif
		#endif
		/// \def LIBLETLIB_NOEXCEPT
		/// Define throwing functions as not-noexcept when using LIBLETLIB_ERROR_EXCEPTION
		/// otherwise all functions are nonexcept.
		#define LIBLETLIB_NOEXCEPT noexcept
		#undef LIBLETLIB_ERROR_ERRNO
		#undef LIBLETLIB_ERROR_NONE
	#elif defined LIBLETLIB_ERROR_ERRNO
		#include <cerrno>

		#if (__cplusplus >= 201103L)
			#ifndef NDEBUG
				/// \def LIBLETLIB_ERROR(message, error_code)
				/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
				/// If NDEBUG is not defined, also print out the file and line where the error occurred and
				/// the message if unavailable using the selected error handling mechanism (non-exceptions).
				#define LIBLETLIB_ERROR(message, error_code)                                                           \
					std::cerr << __FILE__ << ":" << __LINE__ << ": error: " << (message) << std::endl;                 \
					errno = error_code;
			#else
				/// \def LIBLETLIB_ERROR(message, error_code)
				/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
				/// If NDEBUG is not defined, also print out the file and line where the error occurred and
				/// the message if unavailable using the selected error handling mechanism (non-exceptions).
				#define LIBLETLIB_ERROR(message, error_code) errno = error_code;
			#endif
			/// \def LIBLETLIB_NOEXCEPT
			/// Define throwing functions as not-noexcept when using LIBLETLIB_ERROR_EXCEPTION
			/// otherwise all functions are nonexcept.
			#define LIBLETLIB_NOEXCEPT noexcept
		#else
			#ifndef NDEBUG
				/// \def LIBLETLIB_ERROR(message, error_code)
				/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
				/// If NDEBUG is not defined, also print out the file and line where the error occurred and
				/// the message if unavailable using the selected error handling mechanism (non-exceptions).
				#define LIBLETLIB_ERROR(message, error_code)                                                           \
					std::cerr << __FILE__ << ":" << __LINE__ << ": error: " << (message) << std::endl;                 \
					errno = error_code;
			#else
				/// \def LIBLETLIB_ERROR(message, error_code)
				/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
				/// If NDEBUG is not defined, also print out the file and line where the error occurred and
				/// the message if unavailable using the selected error handling mechanism (non-exceptions).
				#define LIBLETLIB_ERROR(message, error_code) errno = EDOM;
			#endif
			/// \def LIBLETLIB_NOEXCEPT
			/// Define throwing functions as not-noexcept when using LIBLETLIB_ERROR_EXCEPTION
			/// otherwise all functions are nonexcept.
			#define LIBLETLIB_NOEXCEPT noexcept
		#endif
		#undef LIBLETLIB_ERROR_NONE
	#elif defined LIBLETLIB_ERROR_NONE
		/// \def LIBLETLIB_NOEXCEPT
		/// Define throwing functions as not-noexcept when using LIBLETLIB_ERROR_EXCEPTION
		/// otherwise all functions are nonexcept.
		#define LIBLETLIB_NOEXCEPT noexcept
		#ifndef NDEBUG
			/// \def LIBLETLIB_ERROR(message, error_code)
			/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
			/// If NDEBUG is not defined, also print out the file and line where the error occurred and
			/// the message if unavailable using the selected error handling mechanism (non-exceptions).
			#define LIBLETLIB_ERROR(message, error_code)                                                               \
				std::cerr << __FILE__ << ":" << __LINE__ << ": error: " << (message) << std::endl;
		#else
			/// \def LIBLETLIB_ERROR(message, error_code)
			/// Define LIBLETLIB_ERROR to behave accordingly to selected error handling mechanism.
			/// If NDEBUG is not defined, also print out the file and line where the error occurred and
			/// the message if unavailable using the selected error handling mechanism (non-exceptions).
			#define LIBLETLIB_ERROR(message, error_code)
		#endif
	#endif

	#ifdef LIBLETLIB_FREESTANDING
		#undef LIBLETLIB_HOSTED
		#define LIBLETLIB_DISABLE_UCHAR
	#else
		#define LIBLETLIB_HOSTED
		#undef LIBLETLIB_FREESTANDING

		#include <cstdio>
		#include <cmath>
		#include <csignal>
		#include <cstring>
		#include <string>
		#include <cwchar>
		#include <iostream>

		#if (__cplusplus >= 201103L)

			#include <type_traits>
			#include <memory>

			#ifndef LIBLETLIB_DISABLE_UCHAR

				#include <cuchar>

			#endif

		#else

			#define LIBLETLIB_DISABLE_UCHAR

		#endif
	#endif

	#include <new>
	#include <limits>
	#include <cstdlib>

	#if (__cplusplus >= 201703L)
	#elif (__cplusplus < 201703L) && (__cplusplus >= 201402L)
	#elif (__cplusplus < 201402L) && (__cplusplus >= 201103L)
	#elif (__cplusplus < 201103L)
		/// \def override
		/// Allows the override keyword to be used without effect in C++98.
		#define override
		/// \def final
		/// Allows the final keyword to be used without effect in C++98.
		#define final
		/// \def noexcept
		/// Allows the noexcept keyword to be used without effect in C++98.
		#define noexcept
		/// \def constexpr
		/// Allows the constexpr type to be used without effect in C++98.
		#define constexpr const
		/// \def constexprconst
		/// Allows tricks with the constexpr in C++98 and later.
		#define constexprconst const
		/// \def nothing
		/// Allows the nullptr type to be used without effect in C++98.
		#define nothing NULL
		/// \def print_to_string(_destination, _length, _format, _arguments)
		/// C++98 doesn't have the safer snprintf, shouldn't cause any problems.
		///    due to non-string type lengths being constant and well padded.
		#define print_to_string(_destination, _length, _format, _arguments)                                            \
			std::sprintf(_destination, _format, _arguments)
	#endif

	#if (__cplusplus >= 201703L)
		/// \def LIBLETLIB_FALLTHROUGH
		/// Allows the use of [[fallthrough]] attribute without effect in C++14 or lower.
		#define LIBLETLIB_FALLTHROUGH [[fallthrough]];
		/// \def LIBLETLIB_NODISCARD
		/// Allows the use of [[nodiscard]] attribute without effect in C++14 or lower.
		#define LIBLETLIB_NODISCARD [[nodiscard]]
		/// \def LIBLETLIB_MAYBE_UNUSED
		/// Allows the use of [[maybe_unused]] attribute without effect in C++14 or lower.
		#define LIBLETLIB_MAYBE_UNUSED [[maybe_unused]]

	#else
		/// \def LIBLETLIB_FALLTHROUGH
		/// Allows the use of [[fallthrough]] attribute without effect in C++14 or lower.
		#define LIBLETLIB_FALLTHROUGH
		/// \def LIBLETLIB_MAYBE_UNUSED
		/// Allows the use of [[maybe_unused]] attribute without effect in C++14 or lower.
		#define LIBLETLIB_MAYBE_UNUSED
		/// \def LIBLETLIB_NODISCARD
		/// Allows the use of [[nodiscard]] attribute without effect in C++14 or lower.
		#define LIBLETLIB_NODISCARD
	#endif

	#if (__cplusplus >= 201103L)
		/// \def constexprconst
		/// Allows constexpr const combination to be used without errors in C++98.
		#define constexprconst constexpr const
		/// \def nothing
		/// Allows the nullptr type to be used without error in C++98 (macro'd to NULL in C++98).
		#define nothing nullptr
	#endif

	#if (__cplusplus < 201103L) || defined LIBLETLIB_FREESTANDING
		/// \def address_of(_object)
		///  C++98 custom addressof.
		#define address_of(_object) address_of(_object)
	#else
		/// \def print_to_string(_destination, _length, _format, _arguments)
		///  C++11 and later have std::snprintf.
		#define print_to_string(_destination, _length, _format, _arguments)                                            \
			std::snprintf(_destination, _length, _format, _arguments)
		/// \def address_of(_object)
		///  C++11 and later have std::addressof.
		#define address_of(_object) std::addressof(_object)
	#endif

	#ifdef LIBLETLIB_FREESTANDING
		/// \def float_floor(_float)
		/// Round given float value down.
		/// Self-implemented function for freestanding, std::floor for hosted.
		#define float_floor(_float) floating_floor(_float)
		/// \def float_ceiling(_float)
		/// Round given float value up.
		/// Self-implemented function for freestanding, std::ceil for hosted.
		#define float_ceiling(_float) floating_ceiling(_float)
		/// \def float_remainder(_left, _right)
		/// Produces _left mod _right.
		/// Self-implemented function for freestanding, std::fmod for hosted.
		#define float_remainder(_left, _right) floating_modulo(_left, _right)
		/// \def float_fractional_part(_fractional, _integral)
		/// Produce the fractional part of a floating point number.
		/// Self-implemented function for freestanding, std::modf for hosted.
		#define float_fractional_part(_fractional, _integral) floating_fractional_part(_fractional, _integral)
		/// \def float_absolute_value(_value)
		/// Produce absolute value of a floating point number-
		/// Self-implemented function for freestanding, std::fabs for hosted.
		#define float_absolute_value(_value) floating_absolute_value(_value)
		/// \def float_power(_base, _exponent)
		/// Decides between standard library and self-implemented power function
		/// depending if using freestanding or hosted environment.
		#define float_power(_base, _exponent) floating_power(_base, _exponent)
	#else

		#ifndef LIBLETLIB_ARRAY_GROWTH
			#define LIBLETLIB_ARRAY_GROWTH 8
		#endif

		/// \def float_floor(_float)
		/// Round given float value down.
		/// Self-implemented function for freestanding, std::floor for hosted.
		#define float_floor(_float) std::floor(_float)
		/// \def float_ceiling(_float)
		/// Round given float value up.
		/// Self-implemented function for freestanding, std::ceil for hosted.
		#define float_ceiling(_float) std::ceil(_float)
		/// \def float_remainder(_left, _right)
		/// Produces _left mod _right.
		/// Self-implemented function for freestanding, std::fmod for hosted.
		#define float_remainder(_left, _right) std::fmod(_left, _right)
		/// \def float_fractional_part(_fractional, _integral)
		/// Produce the fractional part of a floating point number.
		/// Self-implemented function for freestanding, std::modf for hosted.
		#define float_fractional_part(_fractional, _integral) std::modf(_fractional, _integral)
		/// \def float_absolute_value(_value)
		/// Produce absolute value of a floating point number-
		/// Self-implemented function for freestanding, std::fabs for hosted.
		#define float_absolute_value(_value) std::fabs(_value)
		/// \def float_power(_base, _exponent)
		/// Decides between standard library and self-implemented power function
		/// depending if using freestanding or hosted environment.
		#define float_power(_base, _exponent) std::pow(_base, _exponent)
	#endif

	/// \def number_compare(_left, _right)
	/// If _left > _right return 1,
	/// else if _left > _right return -1,
	/// else return 0.
	#define number_compare(_left, _right) ((_left) > (_right) ? 1 : (_left) < (_right) ? -1 : 0)

	/// \def select_operation_var(_left, operation, _right)
	/// Selects higher ranked operator function to use.
	#define select_operation_var(_left, operation, _right)                                                             \
		((_left)->behaviour->rank >= (_right).behaviour->rank ? (_left)->behaviour->operation(*(_left), (_right))      \
		                                                      : (_right).behaviour->operation(*(_left), (_right)))

	/// \def select_operation_let(_left, operation, _right)
	/// Selects higher ranked operator function to use.
	#define select_operation_let(_left, operation, _right)                                                             \
		((_left).behaviour->rank >= (_right).behaviour->rank ? (_left).behaviour->operation((_left), (_right))         \
		                                                     : (_right).behaviour->operation((_left), (_right)))

	#ifndef LIBLETLIB_APPROXIMATELY_FLOAT_EQUAL
		/// \def LIBLETLIB_ESSENTIALLY_FLOAT_EQUAL
		/// Use stricter floating point equality by default.
		#define LIBLETLIB_ESSENTIALLY_FLOAT_EQUAL
	#endif
	#ifdef LIBLETLIB_ESSENTIALLY_FLOAT_EQUAL
		#undef LIBLETLIB_APPROXIMATELY_FLOAT_EQUAL
	#endif

	#if (__cplusplus < 201103L)
		#define enum_bool_type bool_type
		#define enum_char_type char_type
		#define enum_signed_char_type signed_char_type
		#define enum_unsigned_char_type unsigned_char_type
		#define enum_wchar_type wchar_type
		#define enum_short_type short_type
		#define enum_unsigned_short_type unsigned_short_type
		#define enum_int_type int_type
		#define enum_unsigned_int_type unsigned_int_type
		#define enum_long_type long_type
		#define enum_unsigned_long_type unsigned_long_type
		#define enum_float_type float_type
		#define enum_double_type double_type
		#define enum_long_double_type long_double_type
		#define enum_string_type string_type
		#define enum_wide_string_type wide_string_type
		#define enum_void_pointer_type void_pointer_type
		#ifndef LIBLETLIB_FREESTANDING
			#define enum_function_type function_type
			#define enum_subroutine_type subroutine_type
			#define enum_array_type array_type
		#endif
	#else
		#define enum_bool_type libletlib::detail::rank_enumeration::bool_type
		#define enum_char_type libletlib::detail::rank_enumeration::char_type
		#define enum_signed_char_type libletlib::detail::rank_enumeration::signed_char_type
		#define enum_unsigned_char_type libletlib::detail::rank_enumeration::unsigned_char_type
		#define enum_wchar_type libletlib::detail::rank_enumeration::wchar_type
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
				#define enum_char8_type libletlib::detail::rank_enumeration::char8_type
			#endif
			#define enum_char16_type libletlib::detail::rank_enumeration::char16_type
			#define enum_char32_type libletlib::detail::rank_enumeration::char32_type
		#endif
		#define enum_short_type libletlib::detail::rank_enumeration::short_type
		#define enum_unsigned_short_type libletlib::detail::rank_enumeration::unsigned_short_type
		#define enum_int_type libletlib::detail::rank_enumeration::int_type
		#define enum_unsigned_int_type libletlib::detail::rank_enumeration::unsigned_int_type
		#define enum_long_type libletlib::detail::rank_enumeration::long_type
		#define enum_unsigned_long_type libletlib::detail::rank_enumeration::unsigned_long_type
		#define enum_long_long_type libletlib::detail::rank_enumeration::long_long_type
		#define enum_unsigned_long_long_type libletlib::detail::rank_enumeration::unsigned_long_long_type
		#define enum_float_type libletlib::detail::rank_enumeration::float_type
		#define enum_double_type libletlib::detail::rank_enumeration::double_type
		#define enum_long_double_type libletlib::detail::rank_enumeration::long_double_type
		#define enum_string_type libletlib::detail::rank_enumeration::string_type
		#define enum_wide_string_type libletlib::detail::rank_enumeration::wide_string_type
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
				#define enum_bit8_string_type libletlib::detail::rank_enumeration::bit8_string_type
			#endif
			#define enum_bit16_string_type libletlib::detail::rank_enumeration::bit16_string_type
			#define enum_bit32_string_type libletlib::detail::rank_enumeration::bit32_string_type
		#endif
		#define enum_void_pointer_type libletlib::detail::rank_enumeration::void_pointer_type
		#define enum_subroutine_type libletlib::detail::rank_enumeration::subroutine_type
		#define enum_function_type libletlib::detail::rank_enumeration::function_type
		#define enum_array_type libletlib::detail::rank_enumeration::array_type
		#define enum_nullptr_type libletlib::detail::rank_enumeration::nullptr_type
	#endif

	#if (__cplusplus < 201103L)
		#define enum_bool_type bool_type_id
		#define enum_char_type char_type_id
		#define enum_signed_char_type signed_char_type_id
		#define enum_unsigned_char_type unsigned_char_type_id
		#define enum_wchar_type wchar_type_id
		#define enum_short_type short_type_id
		#define enum_unsigned_short_type unsigned_short_type_id
		#define enum_int_type int_type_id
		#define enum_unsigned_int_type unsigned_int_type_id
		#define enum_long_type long_type_id
		#define enum_unsigned_long_type unsigned_long_type_id
		#define enum_float_type float_type_id
		#define enum_double_type double_type_id
		#define enum_long_double_type long_double_type_id
		#define enum_string_type string_type_id
		#define enum_wide_string_type wide_string_type_id
		#define enum_void_pointer_type void_pointer_type_id
		#ifndef LIBLETLIB_FREESTANDING
			#define enum_function_type function_type_id
			#define enum_subroutine_type subroutine_type_id
			#define enum_array_type array_type_id
		#endif
		#define enum_any_type_id any_type_id
	#else
		#define enum_bool_type_id libletlib::detail::type_id_enumeration::bool_type_id
		#define enum_char_type_id libletlib::detail::type_id_enumeration::char_type_id
		#define enum_signed_char_type_id libletlib::detail::type_id_enumeration::signed_char_type_id
		#define enum_unsigned_char_type_id libletlib::detail::type_id_enumeration::unsigned_char_type_id
		#define enum_wchar_type_id libletlib::detail::type_id_enumeration::wchar_type_id
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
				#define enum_char8_type_id libletlib::detail::type_id_enumeration::char8_type_id
			#endif
			#define enum_char16_type_id libletlib::detail::type_id_enumeration::char16_type_id
			#define enum_char32_type_id libletlib::detail::type_id_enumeration::char32_type_id
		#endif
		#define enum_short_type_id libletlib::detail::type_id_enumeration::short_type_id
		#define enum_unsigned_short_type_id libletlib::detail::type_id_enumeration::unsigned_short_type_id
		#define enum_int_type_id libletlib::detail::type_id_enumeration::int_type_id
		#define enum_unsigned_int_type_id libletlib::detail::type_id_enumeration::unsigned_int_type_id
		#define enum_long_type_id libletlib::detail::type_id_enumeration::long_type_id
		#define enum_unsigned_long_type_id libletlib::detail::type_id_enumeration::unsigned_long_type_id
		#define enum_long_long_type_id libletlib::detail::type_id_enumeration::long_long_type_id
		#define enum_unsigned_long_long_type_id libletlib::detail::type_id_enumeration::unsigned_long_long_type_id
		#define enum_float_type_id libletlib::detail::type_id_enumeration::float_type_id
		#define enum_double_type_id libletlib::detail::type_id_enumeration::double_type_id
		#define enum_long_double_type_id libletlib::detail::type_id_enumeration::long_double_type_id
		#define enum_string_type_id libletlib::detail::type_id_enumeration::string_type_id
		#define enum_wide_string_type_id libletlib::detail::type_id_enumeration::wide_string_type_id
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
				#define enum_bit8_string_type_id libletlib::detail::type_id_enumeration::bit8_string_type_id
			#endif
			#define enum_bit16_string_type_id libletlib::detail::type_id_enumeration::bit16_string_type_id
			#define enum_bit32_string_type_id libletlib::detail::type_id_enumeration::bit32_string_type_id
		#endif
		#define enum_void_pointer_type_id libletlib::detail::type_id_enumeration::void_pointer_type_id
		#define enum_subroutine_type_id libletlib::detail::type_id_enumeration::subroutine_type_id
		#define enum_function_type_id libletlib::detail::type_id_enumeration::function_type_id
		#define enum_array_type_id libletlib::detail::type_id_enumeration::array_type_id
		#define enum_nullptr_type_id libletlib::detail::type_id_enumeration::nullptr_type_id
		#define enum_any_type_id libletlib::detail::type_id_enumeration::any_type_id
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
				#define enum_bit8_string_type libletlib::detail::rank_enumeration::bit8_string_type
			#endif
			#define enum_bit16_string_type libletlib::detail::rank_enumeration::bit16_string_type
			#define enum_bit32_string_type libletlib::detail::rank_enumeration::bit32_string_type
		#endif
		#define enum_void_pointer_type libletlib::detail::rank_enumeration::void_pointer_type
		#define enum_subroutine_type libletlib::detail::rank_enumeration::subroutine_type
		#define enum_function_type libletlib::detail::rank_enumeration::function_type
		#define enum_array_type libletlib::detail::rank_enumeration::array_type
		#define enum_nullptr_type libletlib::detail::rank_enumeration::nullptr_type
	#endif

	#if (__cplusplus < 201103L)
		#define enum_bool_type bool_type_id
		#define enum_char_type char_type_id
		#define enum_signed_char_type signed_char_type_id
		#define enum_unsigned_char_type unsigned_char_type_id
		#define enum_wchar_type wchar_type_id
		#define enum_short_type short_type_id
		#define enum_unsigned_short_type unsigned_short_type_id
		#define enum_int_type int_type_id
		#define enum_unsigned_int_type unsigned_int_type_id
		#define enum_long_type long_type_id
		#define enum_unsigned_long_type unsigned_long_type_id
		#define enum_float_type float_type_id
		#define enum_double_type double_type_id
		#define enum_long_double_type long_double_type_id
		#define enum_string_type string_type_id
		#define enum_wide_string_type wide_string_type_id
		#define enum_void_pointer_type void_pointer_type_id
		#ifndef LIBLETLIB_FREESTANDING
			#define enum_function_type function_type_id
			#define enum_subroutine_type subroutine_type_id
			#define enum_array_type array_type_id
		#endif
		#define enum_any_type_id any_type_id
	#else
		#define enum_bool_type_id libletlib::detail::type_id_enumeration::bool_type_id
		#define enum_char_type_id libletlib::detail::type_id_enumeration::char_type_id
		#define enum_signed_char_type_id libletlib::detail::type_id_enumeration::signed_char_type_id
		#define enum_unsigned_char_type_id libletlib::detail::type_id_enumeration::unsigned_char_type_id
		#define enum_wchar_type_id libletlib::detail::type_id_enumeration::wchar_type_id
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
				#define enum_char8_type_id libletlib::detail::type_id_enumeration::char8_type_id
			#endif
			#define enum_char16_type_id libletlib::detail::type_id_enumeration::char16_type_id
			#define enum_char32_type_id libletlib::detail::type_id_enumeration::char32_type_id
		#endif
		#define enum_short_type_id libletlib::detail::type_id_enumeration::short_type_id
		#define enum_unsigned_short_type_id libletlib::detail::type_id_enumeration::unsigned_short_type_id
		#define enum_int_type_id libletlib::detail::type_id_enumeration::int_type_id
		#define enum_unsigned_int_type_id libletlib::detail::type_id_enumeration::unsigned_int_type_id
		#define enum_long_type_id libletlib::detail::type_id_enumeration::long_type_id
		#define enum_unsigned_long_type_id libletlib::detail::type_id_enumeration::unsigned_long_type_id
		#define enum_long_long_type_id libletlib::detail::type_id_enumeration::long_long_type_id
		#define enum_unsigned_long_long_type_id libletlib::detail::type_id_enumeration::unsigned_long_long_type_id
		#define enum_float_type_id libletlib::detail::type_id_enumeration::float_type_id
		#define enum_double_type_id libletlib::detail::type_id_enumeration::double_type_id
		#define enum_long_double_type_id libletlib::detail::type_id_enumeration::long_double_type_id
		#define enum_string_type_id libletlib::detail::type_id_enumeration::string_type_id
		#define enum_wide_string_type_id libletlib::detail::type_id_enumeration::wide_string_type_id
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
				#define enum_bit8_string_type_id libletlib::detail::type_id_enumeration::bit8_string_type_id
			#endif
			#define enum_bit16_string_type_id libletlib::detail::type_id_enumeration::bit16_string_type_id
			#define enum_bit32_string_type_id libletlib::detail::type_id_enumeration::bit32_string_type_id
		#endif
		#define enum_void_pointer_type_id libletlib::detail::type_id_enumeration::void_pointer_type_id
		#define enum_subroutine_type_id libletlib::detail::type_id_enumeration::subroutine_type_id
		#define enum_function_type_id libletlib::detail::type_id_enumeration::function_type_id
		#define enum_array_type_id libletlib::detail::type_id_enumeration::array_type_id
		#define enum_nullptr_type_id libletlib::detail::type_id_enumeration::nullptr_type_id
		#define enum_any_type_id libletlib::detail::type_id_enumeration::any_type_id
	#endif

	#include "core/libletlib_forward_declarations.hpp"
	#include "core/libletlib_index_sequence.hpp"
	#include "core/libletlib_math.hpp"
	#include "core/libletlib_roots.hpp"
	#include "core/libletlib_memory.hpp"
	#include "core/libletlib_rank_enum.hpp"
	#include "core/libletlib_type_id_enum.hpp"
	#include "core/libletlib_behaviour.hpp"
	#include "core/libletlib_value_union.hpp"
	#include "core/libletlib_lambda_capture.hpp"
	#include "core/libletlib_var.hpp"
	#include "core/libletlib_lambda_curry.hpp"
	#include "core/libletlib_lambda_compose.hpp"
	#include "core/libletlib_error.hpp"
	#include "core/libletlib_lambda_helper.hpp"
	#include "core/libletlib_value_union_implementation.hpp"
	#include "core/libletlib_var_implementation.hpp"
	#include "utility/libletlib_ranges.hpp"
	#include "utility/libletlib_lists.hpp"
	#include "utility/libletlib_miscellaneous.hpp"
	#include "utility/libletlib_field.hpp"
	#include "utility/libletlib_pattern_matching.hpp"

	#include "conversions/libletlib_as_boolean.hpp"
	#include "conversions/libletlib_as_character.hpp"
	#include "conversions/libletlib_as_signed_character.hpp"
	#include "conversions/libletlib_as_unsigned_character.hpp"
	#include "conversions/libletlib_as_wide_character.hpp"
	#include "conversions/libletlib_as_bit8_character.hpp"
	#include "conversions/libletlib_as_bit16_character.hpp"
	#include "conversions/libletlib_as_bit32_character.hpp"
	#include "conversions/libletlib_as_short.hpp"
	#include "conversions/libletlib_as_unsigned_short.hpp"
	#include "conversions/libletlib_as_integer.hpp"
	#include "conversions/libletlib_as_unsigned_integer.hpp"
	#include "conversions/libletlib_as_long.hpp"
	#include "conversions/libletlib_as_unsigned_long.hpp"
	#include "conversions/libletlib_as_long_long.hpp"
	#include "conversions/libletlib_as_unsigned_long_long.hpp"
	#include "conversions/libletlib_as_float.hpp"
	#include "conversions/libletlib_as_double.hpp"
	#include "conversions/libletlib_as_long_double.hpp"
	#include "conversions/libletlib_as_string.hpp"
	#include "conversions/libletlib_as_wide_string.hpp"
	#include "conversions/libletlib_as_bit8_string.hpp"
	#include "conversions/libletlib_as_bit16_string.hpp"
	#include "conversions/libletlib_as_bit32_string.hpp"
	#include "conversions/libletlib_as_subroutine.hpp"
	#include "conversions/libletlib_as_function.hpp"
	#include "conversions/libletlib_as_array.hpp"
	#include "conversions/libletlib_as_void_pointer.hpp"
	#include "conversions/libletlib_as_null.hpp"

	#include "operations/libletlib_sum.hpp"
	#include "operations/libletlib_subtraction.hpp"
	#include "operations/libletlib_division.hpp"
	#include "operations/libletlib_multiplication.hpp"
	#include "operations/libletlib_modulo.hpp"
	#include "operations/libletlib_exponentiation.hpp"
	#include "operations/libletlib_binary_and.hpp"
	#include "operations/libletlib_binary_xor.hpp"
	#include "operations/libletlib_binary_or.hpp"
	#include "operations/libletlib_complement.hpp"
	#include "operations/libletlib_indirection.hpp"
	#include "operations/libletlib_negation.hpp"
	#include "operations/libletlib_positive.hpp"
	#include "operations/libletlib_negative.hpp"
	#include "operations/libletlib_decrement.hpp"
	#include "operations/libletlib_increment.hpp"
	#include "operations/libletlib_comparison.hpp"
	#include "operations/libletlib_index.hpp"

/// \brief Library public namespace
namespace libletlib
{
	using libletlib::detail::var;
	typedef libletlib::detail::var const let;
	#ifndef LIBLETLIB_FREESTANDING
	using libletlib::detail::MetaRoot;
	using libletlib::detail::Root;
	namespace detail {
		let any_type_pattern = static_cast<char>(enum_any_type_id);
	}
	#endif
}// namespace libletlib

	#ifndef LIBLETLIB_DISABLE_MACRO
		#ifndef LIBLETLIB_FREESTANDING
			#if (__cplusplus >= 201103L)
				/// \def match
				/// Create pattern matching object.
				#define match(...) libletlib::detail::matcher<libletlib::detail::count_arguments(__VA_ARGS__)>(__VA_ARGS__
				/// \def against
				/// Finalise pattern matching object.
				#define against )
				/// \def otherwise
				/// Match any pattern.
				#define otherwise libletlib::detail::any_type_pattern
			#endif

			/// \def st
			/// First argument of a function/subroutine.
			#define st (length(args) > 0 ? args[0] : var())
/// \def type
			/// Second argument of a function/subroutine.
			#define nd (length(args) > 1 ? args[1] : var())
/// \def type
			/// Third argument of a function/subroutine.
			#define rd (length(args) > 2 ? args[2] : var())
/// \def Function
			/// C++98 function macro.
			#define Function(name) var name(var const& self, var const& args) LIBLETLIB_NOEXCEPT
/// \def Subroutine
			/// C++98 subroutine macro.
			#define Subroutine(name) void name(var const& self, var const& args) LIBLETLIB_NOEXCEPT

			#if (__cplusplus >= 201103L)
				/// \def subroutine
				/// Nonreturning function.
				#define subroutine(code)                                                                               \
					(LIBLETLIB_MAYBE_UNUSED let & self, LIBLETLIB_MAYBE_UNUSED let & args) LIBLETLIB_NOEXCEPT -> void  \
					{                                                                                                  \
						code                                                                                           \
					}                                                                                                  \
					++
				/// \def type
				/// Returning function.
				#define function(code)                                                                                 \
					(LIBLETLIB_MAYBE_UNUSED let & self, LIBLETLIB_MAYBE_UNUSED let & args) LIBLETLIB_NOEXCEPT -> var   \
					{                                                                                                  \
						code                                                                                           \
					}                                                                                                  \
					++
				/// \def lambda
				/// Syntactic sugar for oneliner returning functions.
				#define lambda(expression) []function(return expression;)

				/// \def curry
				/// Syntactic sugar for currying functions.
				#define curry(...)                                                                                     \
					libletlib::detail::curry_(                                                                         \
					    []() noexcept {                                                                                \
					    },                                                                                             \
					    __VA_ARGS__)

				/// \def compose
				/// Syntactic sugar for composing functions.
				#define compose(...)                                                                                   \
					libletlib::detail::compose_(                                                                       \
					    []() noexcept {                                                                                \
					    },                                                                                             \
					    __VA_ARGS__)
			#endif


			#if (__cplusplus >= 201103L)
				/// \def type
				/// Declare a libletlib type and inner types within it under this.
				#define type(Name)                                                                                     \
					class Name final : public Root<Name>                                                               \
					{                                                                                                  \
					public:                                                                                            \
						Name()                                                                                         \
						{                                                                                              \
							inner = { libletlib::detail::field(#Name)

				/// \def contains
				/// Include fields in this object.
				#define contains(...)                                                                                  \
					__VA_ARGS__                                                                                        \
					}                                                                                                  \
					;                                                                                                  \
					}                                                                                                  \
					}                                                                                                  \
					;

				/// \def constructor
				/// Define the constructor of this object.
				#define constructor(code) = [&]subroutine(code)

				/// \def construct
				/// Call the constructor of an object (the field that has the name of the object, it must be invokable.
				#define construct(Name) [](LIBLETLIB_MAYBE_UNUSED let& self, LIBLETLIB_MAYBE_UNUSED let& args) -> var {\
                    var base = new Name;\
					base.message(#Name)

				/// \def with
				/// For giving the construct macro its arguments.
				#define with(...) (__VA_ARGS__); \
									return base;}++()

				/// \def member
				/// Creates a field in a libletlib object.
				#define member(key) , libletlib::detail::field(#key)
			#endif
		#endif
	#endif

	#ifdef nodiscard
		#undef nodiscard
	#endif
	#ifdef print_to_string
		#undef print_to_string
	#endif
	#ifdef constexprconst
		#undef constexprconst
	#endif
	#if (__cplusplus < 201103L)
		#ifdef final
			#undef final
		#endif
		#ifdef constexpr
			#undef constexpr
		#endif
		#ifdef nothing
			#undef nothing
		#endif
		#ifdef noexcept
			#undef noexcept
		#endif
	#endif
	#ifdef address_of
		#undef address_of
	#endif
	#ifdef float_floor
		#undef float_floor
	#endif
	#ifdef float_ceiling
		#undef float_ceiling
	#endif
	#ifdef float_remainder
		#undef float_remainder
	#endif
	#ifdef float_fractional_part
		#undef float_fractional_part
	#endif
	#ifdef float_absolute_value
		#undef float_absolute_value
	#endif
	#ifdef float_power
		#undef float_power
	#endif
	#ifdef number_compare
		#undef number_compare
	#endif
	#ifdef select_operation_var
		#undef select_operation_var
	#endif
	#ifdef select_operation_let
		#undef select_operation_let
	#endif

	#ifdef enum_bool_type
		#undef enum_bool_type
	#endif
	#ifdef enum_char_type
		#undef enum_char_type
	#endif
	#ifdef enum_signed_char_type
		#undef enum_signed_char_type
	#endif
	#ifdef enum_unsigned_char_type
		#undef enum_unsigned_char_type
	#endif
	#ifdef enum_wchar_type
		#undef enum_wchar_type
	#endif
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			#ifdef enum_char8_type
				#undef enum_char8_type
			#endif
		#endif
		#ifdef enum_char16_type
			#undef enum_char16_type
		#endif
		#ifdef enum_char32_type
			#undef enum_char32_type
		#endif
	#endif
	#ifdef enum_short_type
		#undef enum_short_type
	#endif
	#ifdef enum_unsigned_short_type
		#undef enum_unsigned_short_type
	#endif
	#ifdef enum_int_type
		#undef enum_int_type
	#endif
	#ifdef enum_unsigned_int_type
		#undef enum_unsigned_int_type
	#endif
	#ifdef enum_long_type
		#undef enum_long_type
	#endif
	#ifdef enum_unsigned_long_type
		#undef enum_unsigned_long_type
	#endif
	#if (__cplusplus >= 201103L)
		#ifdef enum_long_long_type
			#undef enum_long_long_type
		#endif
		#ifdef enum_unsigned_long_long_type
			#undef enum_unsigned_long_long_type
		#endif
	#endif
	#ifdef enum_float_type
		#undef enum_float_type
	#endif
	#ifdef enum_double_type
		#undef enum_double_type
	#endif
	#ifdef enum_long_double_type
		#undef enum_long_double_type
	#endif
	#ifdef enum_string_type
		#undef enum_string_type
	#endif
	#ifdef enum_wide_string_type
		#undef enum_wide_string_type
	#endif
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			#ifdef enum_bit8_string_type
				#undef enum_bit8_string_type
			#endif
		#endif
		#ifdef enum_bit16_string_type
			#undef enum_bit16_string_type
		#endif
		#ifdef enum_bit32_string_type
			#undef enum_bit32_string_type
		#endif
	#endif
	#ifdef enum_void_pointer_type
		#undef enum_void_pointer_type
	#endif
	#ifdef enum_array_type
		#undef enum_array_type
	#endif
	#if (__cplusplus >= 201103L)
		#ifdef enum_subroutine_type
			#undef enum_subroutine_type
		#endif
		#ifdef enum_function_type
			#undef enum_function_type
		#endif
		#ifdef enum_nullptr_type
			#undef enum_nullptr_type
		#endif
	#endif

	#ifdef enum_bool_type_id
		#undef enum_bool_type_id
	#endif
	#ifdef enum_char_type_id
		#undef enum_char_type_id
	#endif
	#ifdef enum_signed_char_type_id
		#undef enum_signed_char_type_id
	#endif
	#ifdef enum_unsigned_char_type_id
		#undef enum_unsigned_char_type_id
	#endif
	#ifdef enum_wchar_type_id
		#undef enum_wchar_type_id
	#endif
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			#ifdef enum_char8_type_id
				#undef enum_char8_type_id
			#endif
		#endif
		#ifdef enum_char16_type_id
			#undef enum_char16_type_id
		#endif
		#ifdef enum_char32_type_id
			#undef enum_char32_type_id
		#endif
	#endif
	#ifdef enum_short_type_id
		#undef enum_short_type_id
	#endif
	#ifdef enum_unsigned_short_type_id
		#undef enum_unsigned_short_type_id
	#endif
	#ifdef enum_int_type_id
		#undef enum_int_type_id
	#endif
	#ifdef enum_unsigned_int_type_id
		#undef enum_unsigned_int_type_id
	#endif
	#ifdef enum_long_type_id
		#undef enum_long_type_id
	#endif
	#ifdef enum_unsigned_long_type_id
		#undef enum_unsigned_long_type_id
	#endif
	#if (__cplusplus >= 201103L)
		#ifdef enum_long_long_type_id
			#undef enum_long_long_type_id
		#endif
		#ifdef enum_unsigned_long_long_type_id
			#undef enum_unsigned_long_long_type_id
		#endif
	#endif
	#ifdef enum_float_type_id
		#undef enum_float_type_id
	#endif
	#ifdef enum_double_type_id
		#undef enum_double_type_id
	#endif
	#ifdef enum_long_double_type_id
		#undef enum_long_double_type_id
	#endif
	#ifdef enum_string_type_id
		#undef enum_string_type_id
	#endif
	#ifdef enum_wide_string_type_id
		#undef enum_wide_string_type_id
	#endif
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			#ifdef enum_bit8_string_type_id
				#undef enum_bit8_string_type_id
			#endif
		#endif
		#ifdef enum_bit16_string_type_id
			#undef enum_bit16_string_type_id
		#endif
		#ifdef enum_bit32_string_type_id
			#undef enum_bit32_string_type_id
		#endif
	#endif
	#ifdef enum_void_pointer_type_id
		#undef enum_void_pointer_type_id
	#endif
	#ifdef enum_array_type_id
		#undef enum_array_type_id
	#endif
	#if (__cplusplus >= 201103L)
		#ifdef enum_subroutine_type_id
			#undef enum_subroutine_type_id
		#endif
		#ifdef enum_function_type_id
			#undef enum_function_type_id
		#endif
		#ifdef enum_nullptr_type_id
			#undef enum_nullptr_type_id
		#endif
	#endif

#endif
#endif /* LIBLETLIB_HPP */
