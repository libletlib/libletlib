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

#ifndef LIBLETLIB_LIBLETLIB_VAR_HPP
#define LIBLETLIB_LIBLETLIB_VAR_HPP

#include "libletlib_behaviour.hpp"
#include "libletlib_lambda_capture.hpp"
#include "libletlib_rank_enum.hpp"
#include "libletlib_roots.hpp"
#include "libletlib_size_struct.hpp"
#include "libletlib_value_union.hpp"

namespace libletlib
{
	namespace detail
	{

		/// \brief Main class that manages the fundamental type given to it
		///	and its behaviour->
		///
		///	TODO: write longer
		class var final
		{
			template<std::size_t>
			friend class matcher;
			friend class MetaRoot;
			friend class Var;

		public:
			friend bool boolean_as_boolean(var const&) noexcept;
			friend bool character_as_boolean(var const&) noexcept;
			friend bool signed_character_as_boolean(var const&) noexcept;
			friend bool unsigned_character_as_boolean(var const&) noexcept;
			friend bool wide_character_as_boolean(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend bool bit8_character_as_boolean(var const&) noexcept;
	#endif
			friend bool bit16_character_as_boolean(var const&) noexcept;
			friend bool bit32_character_as_boolean(var const&) noexcept;
#endif

			friend bool short_as_boolean(var const&) noexcept;
			friend bool unsigned_short_as_boolean(var const&) noexcept;
			friend bool integer_as_boolean(var const&) noexcept;
			friend bool unsigned_integer_as_boolean(var const&) noexcept;
			friend bool long_as_boolean(var const&) noexcept;
			friend bool unsigned_long_as_boolean(var const&) noexcept;

#if (__cplusplus >= 201103L)
			friend bool long_long_as_boolean(var const&) noexcept;
			friend bool unsigned_long_long_as_boolean(var const&) noexcept;
#endif

			friend bool float_as_boolean(var const&) noexcept;
			friend bool double_as_boolean(var const&) noexcept;
			friend bool long_double_as_boolean(var const&) noexcept;
			friend bool string_as_boolean(var const&) noexcept;
			friend bool wide_string_as_boolean(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend bool bit8_string_as_boolean(var const&) noexcept;
	#endif
			friend bool bit16_string_as_boolean(var const&) noexcept;
			friend bool bit32_string_as_boolean(var const&) noexcept;

#endif

			friend bool pointer_as_boolean(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend bool array_as_boolean(var const&) noexcept;
			friend bool subroutine_as_boolean(var const&) LIBLETLIB_NOEXCEPT;
			friend bool function_as_boolean(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend bool null_as_boolean(var const&) noexcept;

#endif

			friend char boolean_as_character(var const&) noexcept;
			friend char character_as_character(var const&) noexcept;
			friend char signed_character_as_character(var const&) noexcept;
			friend char unsigned_character_as_character(var const&) noexcept;
			friend char wide_character_as_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend char bit8_character_as_character(var const&) noexcept;
	#endif
			friend char bit16_character_as_character(var const&) noexcept;
			friend char bit32_character_as_character(var const&) noexcept;

#endif

			friend char short_as_character(var const&) noexcept;
			friend char unsigned_short_as_character(var const&) noexcept;
			friend char integer_as_character(var const&) noexcept;
			friend char unsigned_integer_as_character(var const&) noexcept;
			friend char long_as_character(var const&) noexcept;
			friend char unsigned_long_as_character(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend char long_long_as_character(var const&) noexcept;
			friend char unsigned_long_long_as_character(var const&) noexcept;

#endif

			friend char float_as_character(var const&) noexcept;
			friend char double_as_character(var const&) noexcept;
			friend char long_double_as_character(var const&) noexcept;
			friend char string_as_character(var const&) noexcept;
			friend char wide_string_as_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend char bit8_string_as_character(var const&) noexcept;
	#endif
			friend char bit16_string_as_character(var const&) noexcept;
			friend char bit32_string_as_character(var const&) noexcept;

#endif

			friend char pointer_as_character(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend char array_as_character(var const&) noexcept;
			friend char subroutine_as_character(var const&) LIBLETLIB_NOEXCEPT;
			friend char function_as_character(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend char null_as_character(var const&) noexcept;

#endif

			friend signed char boolean_as_signed_character(var const&) noexcept;
			friend signed char character_as_signed_character(var const&) noexcept;
			friend signed char signed_character_as_signed_character(var const&) noexcept;
			friend signed char unsigned_character_as_signed_character(var const&) noexcept;
			friend signed char wide_character_as_signed_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend signed char bit8_character_as_signed_character(var const&) noexcept;
	#endif
			friend signed char bit16_character_as_signed_character(var const&) noexcept;
			friend signed char bit32_character_as_signed_character(var const&) noexcept;

#endif

			friend signed char short_as_signed_character(var const&) noexcept;
			friend signed char unsigned_short_as_signed_character(var const&) noexcept;
			friend signed char integer_as_signed_character(var const&) noexcept;
			friend signed char unsigned_integer_as_signed_character(var const&) noexcept;
			friend signed char long_as_signed_character(var const&) noexcept;
			friend signed char unsigned_long_as_signed_character(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend signed char long_long_as_signed_character(var const&) noexcept;
			friend signed char unsigned_long_long_as_signed_character(var const&) noexcept;

#endif

			friend signed char float_as_signed_character(var const&) noexcept;
			friend signed char double_as_signed_character(var const&) noexcept;
			friend signed char long_double_as_signed_character(var const&) noexcept;
			friend signed char string_as_signed_character(var const&) noexcept;
			friend signed char wide_string_as_signed_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend signed char bit8_string_as_signed_character(var const&) noexcept;
	#endif
			friend signed char bit16_string_as_signed_character(var const&) noexcept;
			friend signed char bit32_string_as_signed_character(var const&) noexcept;

#endif

			friend signed char pointer_as_signed_character(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend signed char array_as_signed_character(var const&) noexcept;
			friend signed char subroutine_as_signed_character(var const&) LIBLETLIB_NOEXCEPT;
			friend signed char function_as_signed_character(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend signed char null_as_signed_character(var const&) noexcept;

#endif

			friend unsigned char boolean_as_unsigned_character(var const&) noexcept;
			friend unsigned char character_as_unsigned_character(var const&) noexcept;
			friend unsigned char signed_character_as_unsigned_character(var const&) noexcept;
			friend unsigned char unsigned_character_as_unsigned_character(var const&) noexcept;
			friend unsigned char wide_character_as_unsigned_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend unsigned char bit8_character_as_unsigned_character(var const&) noexcept;
	#endif
			friend unsigned char bit16_character_as_unsigned_character(var const&) noexcept;
			friend unsigned char bit32_character_as_unsigned_character(var const&) noexcept;

#endif

			friend unsigned char short_as_unsigned_character(var const&) noexcept;
			friend unsigned char unsigned_short_as_unsigned_character(var const&) noexcept;
			friend unsigned char integer_as_unsigned_character(var const&) noexcept;
			friend unsigned char unsigned_integer_as_unsigned_character(var const&) noexcept;
			friend unsigned char long_as_unsigned_character(var const&) noexcept;
			friend unsigned char unsigned_long_as_unsigned_character(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend unsigned char long_long_as_unsigned_character(var const&) noexcept;
			friend unsigned char unsigned_long_long_as_unsigned_character(var const&) noexcept;

#endif

			friend unsigned char float_as_unsigned_character(var const&) noexcept;
			friend unsigned char double_as_unsigned_character(var const&) noexcept;
			friend unsigned char long_double_as_unsigned_character(var const&) noexcept;
			friend unsigned char string_as_unsigned_character(var const&) noexcept;
			friend unsigned char wide_string_as_unsigned_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend unsigned char bit8_string_as_unsigned_character(var const&) noexcept;
	#endif
			friend unsigned char bit16_string_as_unsigned_character(var const&) noexcept;
			friend unsigned char bit32_string_as_unsigned_character(var const&) noexcept;

#endif

			friend unsigned char pointer_as_unsigned_character(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend unsigned char array_as_unsigned_character(var const&) noexcept;
			friend unsigned char subroutine_as_unsigned_character(var const&) LIBLETLIB_NOEXCEPT;
			friend unsigned char function_as_unsigned_character(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend unsigned char null_as_unsigned_character(var const&) noexcept;

#endif

			friend wchar_t boolean_as_wide_character(var const&) noexcept;
			friend wchar_t character_as_wide_character(var const&) noexcept;
			friend wchar_t signed_character_as_wide_character(var const&) noexcept;
			friend wchar_t unsigned_character_as_wide_character(var const&) noexcept;
			friend wchar_t wide_character_as_wide_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend wchar_t bit8_character_as_wide_character(var const&) noexcept;
	#endif
			friend wchar_t bit16_character_as_wide_character(var const&) noexcept;
			friend wchar_t bit32_character_as_wide_character(var const&) noexcept;

#endif

			friend wchar_t short_as_wide_character(var const&) noexcept;
			friend wchar_t unsigned_short_as_wide_character(var const&) noexcept;
			friend wchar_t integer_as_wide_character(var const&) noexcept;
			friend wchar_t unsigned_integer_as_wide_character(var const&) noexcept;
			friend wchar_t long_as_wide_character(var const&) noexcept;
			friend wchar_t unsigned_long_as_wide_character(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend wchar_t long_long_as_wide_character(var const&) noexcept;
			friend wchar_t unsigned_long_long_as_wide_character(var const&) noexcept;

#endif

			friend wchar_t float_as_wide_character(var const&) noexcept;
			friend wchar_t double_as_wide_character(var const&) noexcept;
			friend wchar_t long_double_as_wide_character(var const&) noexcept;
			friend wchar_t string_as_wide_character(var const&) noexcept;
			friend wchar_t wide_string_as_wide_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend wchar_t bit8_string_as_wide_character(var const&) noexcept;
	#endif
			friend wchar_t bit16_string_as_wide_character(var const&) noexcept;
			friend wchar_t bit32_string_as_wide_character(var const&) noexcept;

#endif

			friend wchar_t pointer_as_wide_character(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend wchar_t array_as_wide_character(var const&) noexcept;
			friend wchar_t subroutine_as_wide_character(var const&) LIBLETLIB_NOEXCEPT;
			friend wchar_t function_as_wide_character(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend wchar_t null_as_wide_character(var const&) noexcept;

#endif

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend char8_t boolean_as_bit8_character(var const&) noexcept;
			friend char8_t character_as_bit8_character(var const&) noexcept;
			friend char8_t signed_character_as_bit8_character(var const&) noexcept;
			friend char8_t unsigned_character_as_bit8_character(var const&) noexcept;
			friend char8_t wide_character_as_bit8_character(var const&) noexcept;
			friend char8_t bit8_character_as_bit8_character(var const&) noexcept;
			friend char8_t bit16_character_as_bit8_character(var const&) noexcept;
			friend char8_t bit32_character_as_bit8_character(var const&) noexcept;
			friend char8_t short_as_bit8_character(var const&) noexcept;
			friend char8_t unsigned_short_as_bit8_character(var const&) noexcept;
			friend char8_t integer_as_bit8_character(var const&) noexcept;
			friend char8_t unsigned_integer_as_bit8_character(var const&) noexcept;
			friend char8_t long_as_bit8_character(var const&) noexcept;
			friend char8_t unsigned_long_as_bit8_character(var const&) noexcept;
			friend char8_t long_long_as_bit8_character(var const&) noexcept;
			friend char8_t unsigned_long_long_as_bit8_character(var const&) noexcept;
			friend char8_t float_as_bit8_character(var const&) noexcept;
			friend char8_t double_as_bit8_character(var const&) noexcept;
			friend char8_t long_double_as_bit8_character(var const&) noexcept;
			friend char8_t string_as_bit8_character(var const&) noexcept;
			friend char8_t wide_string_as_bit8_character(var const&) noexcept;
			friend char8_t bit8_string_as_bit8_character(var const&) noexcept;
			friend char8_t bit16_string_as_bit8_character(var const&) noexcept;
			friend char8_t bit32_string_as_bit8_character(var const&) noexcept;
			friend char8_t pointer_as_bit8_character(var const&) noexcept;
			friend char8_t array_as_bit8_character(var const&) noexcept;
			friend char8_t subroutine_as_bit8_character(var const&) LIBLETLIB_NOEXCEPT;
			friend char8_t function_as_bit8_character(var const&) noexcept;
			friend char8_t null_as_bit8_character(var const&) noexcept;
	#endif
			friend char16_t boolean_as_bit16_character(var const&) noexcept;
			friend char16_t character_as_bit16_character(var const&) noexcept;
			friend char16_t signed_character_as_bit16_character(var const&) noexcept;
			friend char16_t unsigned_character_as_bit16_character(var const&) noexcept;
			friend char16_t wide_character_as_bit16_character(var const&) noexcept;
	#if (__cplusplus >= 202002L)
			friend char16_t bit8_character_as_bit16_character(var const&) noexcept;
	#endif
			friend char16_t bit16_character_as_bit16_character(var const&) noexcept;
			friend char16_t bit32_character_as_bit16_character(var const&) noexcept;
			friend char16_t short_as_bit16_character(var const&) noexcept;
			friend char16_t unsigned_short_as_bit16_character(var const&) noexcept;
			friend char16_t integer_as_bit16_character(var const&) noexcept;
			friend char16_t unsigned_integer_as_bit16_character(var const&) noexcept;
			friend char16_t long_as_bit16_character(var const&) noexcept;
			friend char16_t unsigned_long_as_bit16_character(var const&) noexcept;
			friend char16_t long_long_as_bit16_character(var const&) noexcept;
			friend char16_t unsigned_long_long_as_bit16_character(var const&) noexcept;
			friend char16_t float_as_bit16_character(var const&) noexcept;
			friend char16_t double_as_bit16_character(var const&) noexcept;
			friend char16_t long_double_as_bit16_character(var const&) noexcept;
			friend char16_t string_as_bit16_character(var const&) noexcept;
			friend char16_t wide_string_as_bit16_character(var const&) noexcept;
	#if (__cplusplus >= 202002L)
			friend char16_t bit8_string_as_bit16_character(var const&) noexcept;
	#endif
			friend char16_t bit16_string_as_bit16_character(var const&) noexcept;
			friend char16_t bit32_string_as_bit16_character(var const&) noexcept;
			friend char16_t pointer_as_bit16_character(var const&) noexcept;
			friend char16_t array_as_bit16_character(var const&) noexcept;
			friend char16_t subroutine_as_bit16_character(var const&) LIBLETLIB_NOEXCEPT;
			friend char16_t function_as_bit16_character(var const&) noexcept;
			friend char16_t null_as_bit16_character(var const&) noexcept;

			friend char32_t boolean_as_bit32_character(var const&) noexcept;
			friend char32_t character_as_bit32_character(var const&) noexcept;
			friend char32_t signed_character_as_bit32_character(var const&) noexcept;
			friend char32_t unsigned_character_as_bit32_character(var const&) noexcept;
			friend char32_t wide_character_as_bit32_character(var const&) noexcept;
	#if (__cplusplus >= 202002L)
			friend char32_t bit8_character_as_bit32_character(var const&) noexcept;
	#endif
			friend char32_t bit16_character_as_bit32_character(var const&) noexcept;
			friend char32_t bit32_character_as_bit32_character(var const&) noexcept;
			friend char32_t short_as_bit32_character(var const&) noexcept;
			friend char32_t unsigned_short_as_bit32_character(var const&) noexcept;
			friend char32_t integer_as_bit32_character(var const&) noexcept;
			friend char32_t unsigned_integer_as_bit32_character(var const&) noexcept;
			friend char32_t long_as_bit32_character(var const&) noexcept;
			friend char32_t unsigned_long_as_bit32_character(var const&) noexcept;
			friend char32_t long_long_as_bit32_character(var const&) noexcept;
			friend char32_t unsigned_long_long_as_bit32_character(var const&) noexcept;
			friend char32_t float_as_bit32_character(var const&) noexcept;
			friend char32_t double_as_bit32_character(var const&) noexcept;
			friend char32_t long_double_as_bit32_character(var const&) noexcept;
			friend char32_t string_as_bit32_character(var const&) noexcept;
			friend char32_t wide_string_as_bit32_character(var const&) noexcept;
	#if (__cplusplus >= 202002L)
			friend char32_t bit8_string_as_bit32_character(var const&) noexcept;
	#endif
			friend char32_t bit16_string_as_bit32_character(var const&) noexcept;
			friend char32_t bit32_string_as_bit32_character(var const&) noexcept;
			friend char32_t pointer_as_bit32_character(var const&) noexcept;
			friend char32_t array_as_bit32_character(var const&) noexcept;
			friend char32_t subroutine_as_bit32_character(var const&) LIBLETLIB_NOEXCEPT;
			friend char32_t function_as_bit32_character(var const&) noexcept;
			friend char32_t null_as_bit32_character(var const&) noexcept;

#endif

			friend short boolean_as_short(var const&) noexcept;
			friend short character_as_short(var const&) noexcept;
			friend short signed_character_as_short(var const&) noexcept;
			friend short unsigned_character_as_short(var const&) noexcept;
			friend short wide_character_as_short(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend short bit8_character_as_short(var const&) noexcept;
	#endif
			friend short bit16_character_as_short(var const&) noexcept;
			friend short bit32_character_as_short(var const&) noexcept;

#endif

			friend short short_as_short(var const&) noexcept;
			friend short unsigned_short_as_short(var const&) noexcept;
			friend short integer_as_short(var const&) noexcept;
			friend short unsigned_integer_as_short(var const&) noexcept;
			friend short long_as_short(var const&) noexcept;
			friend short unsigned_long_as_short(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend short long_long_as_short(var const&) noexcept;
			friend short unsigned_long_long_as_short(var const&) noexcept;

#endif

			friend short float_as_short(var const&) noexcept;
			friend short double_as_short(var const&) noexcept;
			friend short long_double_as_short(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend short string_as_short(var const&) noexcept;
			friend short wide_string_as_short(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend short bit8_string_as_short(var const&) noexcept;
		#endif
			friend short bit16_string_as_short(var const&) noexcept;
			friend short bit32_string_as_short(var const&) noexcept;

	#endif
#endif

			friend short pointer_as_short(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend short array_as_short(var const&) noexcept;
			friend short subroutine_as_short(var const&) LIBLETLIB_NOEXCEPT;
			friend short function_as_short(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend short null_as_short(var const&) noexcept;

#endif

			friend unsigned short boolean_as_unsigned_short(var const&) noexcept;
			friend unsigned short character_as_unsigned_short(var const&) noexcept;
			friend unsigned short signed_character_as_unsigned_short(var const&) noexcept;
			friend unsigned short unsigned_character_as_unsigned_short(var const&) noexcept;
			friend unsigned short wide_character_as_unsigned_short(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend unsigned short bit8_character_as_unsigned_short(var const&) noexcept;
	#endif
			friend unsigned short bit16_character_as_unsigned_short(var const&) noexcept;
			friend unsigned short bit32_character_as_unsigned_short(var const&) noexcept;

#endif

			friend unsigned short short_as_unsigned_short(var const&) noexcept;
			friend unsigned short unsigned_short_as_unsigned_short(var const&) noexcept;
			friend unsigned short integer_as_unsigned_short(var const&) noexcept;
			friend unsigned short unsigned_integer_as_unsigned_short(var const&) noexcept;
			friend unsigned short long_as_unsigned_short(var const&) noexcept;
			friend unsigned short unsigned_long_as_unsigned_short(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend unsigned short long_long_as_unsigned_short(var const&) noexcept;
			friend unsigned short unsigned_long_long_as_unsigned_short(var const&) noexcept;

#endif

			friend unsigned short float_as_unsigned_short(var const&) noexcept;
			friend unsigned short double_as_unsigned_short(var const&) noexcept;
			friend unsigned short long_double_as_unsigned_short(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend unsigned short string_as_unsigned_short(var const&) noexcept;
			friend unsigned short wide_string_as_unsigned_short(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend unsigned short bit8_string_as_unsigned_short(var const&) noexcept;
		#endif
			friend unsigned short bit16_string_as_unsigned_short(var const&) noexcept;
			friend unsigned short bit32_string_as_unsigned_short(var const&) noexcept;

	#endif
#endif

			friend unsigned short pointer_as_unsigned_short(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend unsigned short array_as_unsigned_short(var const&) noexcept;
			friend unsigned short subroutine_as_unsigned_short(var const&) LIBLETLIB_NOEXCEPT;
			friend unsigned short function_as_unsigned_short(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend unsigned short null_as_unsigned_short(var const&) noexcept;

#endif

			friend int boolean_as_integer(var const&) noexcept;
			friend int character_as_integer(var const&) noexcept;
			friend int signed_character_as_integer(var const&) noexcept;
			friend int unsigned_character_as_integer(var const&) noexcept;
			friend int wide_character_as_integer(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend int bit8_character_as_integer(var const&) noexcept;
	#endif
			friend int bit16_character_as_integer(var const&) noexcept;
			friend int bit32_character_as_integer(var const&) noexcept;

#endif

			friend int short_as_integer(var const&) noexcept;
			friend int unsigned_short_as_integer(var const&) noexcept;
			friend int integer_as_integer(var const&) noexcept;
			friend int unsigned_integer_as_integer(var const&) noexcept;
			friend int long_as_integer(var const&) noexcept;
			friend int unsigned_long_as_integer(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend int long_long_as_integer(var const&) noexcept;
			friend int unsigned_long_long_as_integer(var const&) noexcept;

#endif

			friend int float_as_integer(var const&) noexcept;
			friend int double_as_integer(var const&) noexcept;
			friend int long_double_as_integer(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend int string_as_integer(var const&) noexcept;
			friend int wide_string_as_integer(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend int bit8_string_as_integer(var const&) noexcept;
		#endif
			friend int bit16_string_as_integer(var const&) noexcept;
			friend int bit32_string_as_integer(var const&) noexcept;

	#endif
#endif

			friend int pointer_as_integer(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend int array_as_integer(var const&) noexcept;
			friend int subroutine_as_integer(var const&) LIBLETLIB_NOEXCEPT;
			friend int function_as_integer(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend int null_as_integer(var const&) noexcept;

#endif

			friend unsigned boolean_as_unsigned_integer(var const&) noexcept;
			friend unsigned character_as_unsigned_integer(var const&) noexcept;
			friend unsigned signed_character_as_unsigned_integer(var const&) noexcept;
			friend unsigned unsigned_character_as_unsigned_integer(var const&) noexcept;
			friend unsigned wide_character_as_unsigned_integer(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend unsigned bit8_character_as_unsigned_integer(var const&) noexcept;
	#endif
			friend unsigned bit16_character_as_unsigned_integer(var const&) noexcept;
			friend unsigned bit32_character_as_unsigned_integer(var const&) noexcept;

#endif

			friend unsigned short_as_unsigned_integer(var const&) noexcept;
			friend unsigned unsigned_short_as_unsigned_integer(var const&) noexcept;
			friend unsigned integer_as_unsigned_integer(var const&) noexcept;
			friend unsigned unsigned_integer_as_unsigned_integer(var const&) noexcept;
			friend unsigned long_as_unsigned_integer(var const&) noexcept;
			friend unsigned unsigned_long_as_unsigned_integer(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend unsigned long_long_as_unsigned_integer(var const&) noexcept;
			friend unsigned unsigned_long_long_as_unsigned_integer(var const&) noexcept;

#endif

			friend unsigned float_as_unsigned_integer(var const&) noexcept;
			friend unsigned double_as_unsigned_integer(var const&) noexcept;
			friend unsigned long_double_as_unsigned_integer(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend unsigned string_as_unsigned_integer(var const&) noexcept;
			friend unsigned wide_string_as_unsigned_integer(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend unsigned bit8_string_as_unsigned_integer(var const&) noexcept;
		#endif
			friend unsigned bit16_string_as_unsigned_integer(var const&) noexcept;
			friend unsigned bit32_string_as_unsigned_integer(var const&) noexcept;

	#endif
#endif

			friend unsigned pointer_as_unsigned_integer(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend unsigned int array_as_unsigned_integer(var const&) noexcept;
			friend unsigned subroutine_as_unsigned_integer(var const&) LIBLETLIB_NOEXCEPT;
			friend unsigned function_as_unsigned_integer(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend unsigned null_as_unsigned_integer(var const&) noexcept;

#endif

			friend long boolean_as_long(var const&) noexcept;
			friend long character_as_long(var const&) noexcept;
			friend long signed_character_as_long(var const&) noexcept;
			friend long unsigned_character_as_long(var const&) noexcept;
			friend long wide_character_as_long(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend long bit8_character_as_long(var const&) noexcept;
	#endif
			friend long bit16_character_as_long(var const&) noexcept;
			friend long bit32_character_as_long(var const&) noexcept;

#endif

			friend long short_as_long(var const&) noexcept;
			friend long unsigned_short_as_long(var const&) noexcept;
			friend long integer_as_long(var const&) noexcept;
			friend long unsigned_integer_as_long(var const&) noexcept;
			friend long long_as_long(var const&) noexcept;
			friend long unsigned_long_as_long(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend long long_long_as_long(var const&) noexcept;
			friend long unsigned_long_long_as_long(var const&) noexcept;

#endif

			friend long float_as_long(var const&) noexcept;
			friend long double_as_long(var const&) noexcept;
			friend long long_double_as_long(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend long string_as_long(var const&) noexcept;
			friend long wide_string_as_long(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend long bit8_string_as_long(var const&) noexcept;
		#endif
			friend long bit16_string_as_long(var const&) noexcept;
			friend long bit32_string_as_long(var const&) noexcept;

	#endif
#endif

			friend long pointer_as_long(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend long array_as_long(var const&) noexcept;
			friend long subroutine_as_long(var const&) LIBLETLIB_NOEXCEPT;
			friend long function_as_long(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend long null_as_long(var const&) noexcept;

#endif

			friend unsigned long boolean_as_unsigned_long(var const&) noexcept;
			friend unsigned long character_as_unsigned_long(var const&) noexcept;
			friend unsigned long signed_character_as_unsigned_long(var const&) noexcept;
			friend unsigned long unsigned_character_as_unsigned_long(var const&) noexcept;
			friend unsigned long wide_character_as_unsigned_long(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend unsigned long bit8_character_as_unsigned_long(var const&) noexcept;
	#endif
			friend unsigned long bit16_character_as_unsigned_long(var const&) noexcept;
			friend unsigned long bit32_character_as_unsigned_long(var const&) noexcept;

#endif

			friend unsigned long short_as_unsigned_long(var const&) noexcept;
			friend unsigned long unsigned_short_as_unsigned_long(var const&) noexcept;
			friend unsigned long integer_as_unsigned_long(var const&) noexcept;
			friend unsigned long unsigned_integer_as_unsigned_long(var const&) noexcept;
			friend unsigned long long_as_unsigned_long(var const&) noexcept;
			friend unsigned long unsigned_long_as_unsigned_long(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend unsigned long long_long_as_unsigned_long(var const&) noexcept;
			friend unsigned long unsigned_long_long_as_unsigned_long(var const&) noexcept;

#endif

			friend unsigned long float_as_unsigned_long(var const&) noexcept;
			friend unsigned long double_as_unsigned_long(var const&) noexcept;
			friend unsigned long long_double_as_unsigned_long(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend unsigned long string_as_unsigned_long(var const&) noexcept;
			friend unsigned long wide_string_as_unsigned_long(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend unsigned long bit8_string_as_unsigned_long(var const&) noexcept;
		#endif
			friend unsigned long bit16_string_as_unsigned_long(var const&) noexcept;
			friend unsigned long bit32_string_as_unsigned_long(var const&) noexcept;

	#endif
#endif

			friend unsigned long pointer_as_unsigned_long(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend unsigned long array_as_unsigned_long(var const&) noexcept;
			friend unsigned long subroutine_as_unsigned_long(var const&) LIBLETLIB_NOEXCEPT;
			friend unsigned long function_as_unsigned_long(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend unsigned long null_as_unsigned_long(var const&) noexcept;

#endif

#if (__cplusplus >= 201103L)

			friend long long boolean_as_long_long(var const&) noexcept;
			friend long long character_as_long_long(var const&) noexcept;
			friend long long signed_character_as_long_long(var const&) noexcept;
			friend long long unsigned_character_as_long_long(var const&) noexcept;
			friend long long wide_character_as_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend long long bit8_character_as_long_long(var const&) noexcept;
		#endif
			friend long long bit16_character_as_long_long(var const&) noexcept;
			friend long long bit32_character_as_long_long(var const&) noexcept;

	#endif

			friend long long short_as_long_long(var const&) noexcept;
			friend long long unsigned_short_as_long_long(var const&) noexcept;
			friend long long integer_as_long_long(var const&) noexcept;
			friend long long unsigned_integer_as_long_long(var const&) noexcept;
			friend long long long_as_long_long(var const&) noexcept;
			friend long long unsigned_long_as_long_long(var const&) noexcept;
			friend long long long_long_as_long_long(var const&) noexcept;
			friend long long unsigned_long_long_as_long_long(var const&) noexcept;
			friend long long float_as_long_long(var const&) noexcept;
			friend long long double_as_long_long(var const&) noexcept;
			friend long long long_double_as_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_FREESTANDING

			friend long long string_as_long_long(var const&) noexcept;
			friend long long wide_string_as_long_long(var const&) noexcept;

		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
			friend long long bit8_string_as_long_long(var const&) noexcept;
			#endif
			friend long long bit16_string_as_long_long(var const&) noexcept;
			friend long long bit32_string_as_long_long(var const&) noexcept;

		#endif
	#endif

			friend long long pointer_as_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_FREESTANDING

			friend long long array_as_long_long(var const&) noexcept;
			friend long long subroutine_as_long_long(var const&) LIBLETLIB_NOEXCEPT;
			friend long long function_as_long_long(var const&) noexcept;

	#endif

			friend long long null_as_long_long(var const&) noexcept;
			friend unsigned long long boolean_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long character_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long signed_character_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long unsigned_character_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long wide_character_as_unsigned_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend unsigned long long bit8_character_as_unsigned_long_long(var const&) noexcept;
		#endif
			friend unsigned long long bit16_character_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long bit32_character_as_unsigned_long_long(var const&) noexcept;

	#endif

			friend unsigned long long short_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long unsigned_short_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long integer_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long unsigned_integer_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long long_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long unsigned_long_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long long_long_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long unsigned_long_long_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long float_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long double_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long long_double_as_unsigned_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_FREESTANDING

			friend unsigned long long string_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long wide_string_as_unsigned_long_long(var const&) noexcept;

		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
			friend unsigned long long bit8_string_as_unsigned_long_long(var const&) noexcept;
			#endif
			friend unsigned long long bit16_string_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long bit32_string_as_unsigned_long_long(var const&) noexcept;

		#endif
	#endif

			friend unsigned long long pointer_as_unsigned_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_FREESTANDING

			friend unsigned long long array_as_unsigned_long_long(var const&) noexcept;
			friend unsigned long long subroutine_as_unsigned_long_long(var const&) LIBLETLIB_NOEXCEPT;
			friend unsigned long long function_as_unsigned_long_long(var const&) noexcept;

	#endif

			friend unsigned long long null_as_unsigned_long_long(var const&) noexcept;

#endif

			friend float boolean_as_float(var const&) noexcept;
			friend float character_as_float(var const&) noexcept;
			friend float signed_character_as_float(var const&) noexcept;
			friend float unsigned_character_as_float(var const&) noexcept;
			friend float wide_character_as_float(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend float bit8_character_as_float(var const&) noexcept;
	#endif
			friend float bit16_character_as_float(var const&) noexcept;
			friend float bit32_character_as_float(var const&) noexcept;

#endif

			friend float short_as_float(var const&) noexcept;
			friend float unsigned_short_as_float(var const&) noexcept;
			friend float integer_as_float(var const&) noexcept;
			friend float unsigned_integer_as_float(var const&) noexcept;
			friend float long_as_float(var const&) noexcept;
			friend float unsigned_long_as_float(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend float long_long_as_float(var const&) noexcept;
			friend float unsigned_long_long_as_float(var const&) noexcept;

#endif

			friend float float_as_float(var const&) noexcept;
			friend float double_as_float(var const&) noexcept;
			friend float long_double_as_float(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend float string_as_float(var const&) noexcept;
			friend float wide_string_as_float(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend float bit8_string_as_float(var const&) noexcept;
		#endif
			friend float bit16_string_as_float(var const&) noexcept;
			friend float bit32_string_as_float(var const&) noexcept;

	#endif
#endif

			friend float pointer_as_float(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend float array_as_float(var const&) noexcept;
			friend float subroutine_as_float(var const&) LIBLETLIB_NOEXCEPT;
			friend float function_as_float(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend float null_as_float(var const&) noexcept;

#endif

			friend double boolean_as_double(var const&) noexcept;
			friend double character_as_double(var const&) noexcept;
			friend double signed_character_as_double(var const&) noexcept;
			friend double unsigned_character_as_double(var const&) noexcept;
			friend double wide_character_as_double(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend double bit8_character_as_double(var const&) noexcept;
	#endif
			friend double bit16_character_as_double(var const&) noexcept;
			friend double bit32_character_as_double(var const&) noexcept;

#endif

			friend double short_as_double(var const&) noexcept;
			friend double unsigned_short_as_double(var const&) noexcept;
			friend double integer_as_double(var const&) noexcept;
			friend double unsigned_integer_as_double(var const&) noexcept;
			friend double long_as_double(var const&) noexcept;
			friend double unsigned_long_as_double(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend double long_long_as_double(var const&) noexcept;
			friend double unsigned_long_long_as_double(var const&) noexcept;

#endif

			friend double float_as_double(var const&) noexcept;
			friend double double_as_double(var const&) noexcept;
			friend double long_double_as_double(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend double string_as_double(var const&) noexcept;
			friend double wide_string_as_double(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend double bit8_string_as_double(var const&) noexcept;
		#endif
			friend double bit16_string_as_double(var const&) noexcept;
			friend double bit32_string_as_double(var const&) noexcept;

	#endif
#endif

			friend double pointer_as_double(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend double array_as_double(var const&) noexcept;
			friend double subroutine_as_double(var const&) LIBLETLIB_NOEXCEPT;
			friend double function_as_double(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend double null_as_double(var const&) noexcept;

#endif

			friend long double boolean_as_long_double(var const&) noexcept;
			friend long double character_as_long_double(var const&) noexcept;
			friend long double signed_character_as_long_double(var const&) noexcept;
			friend long double unsigned_character_as_long_double(var const&) noexcept;
			friend long double wide_character_as_long_double(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend long double bit8_character_as_long_double(var const&) noexcept;
	#endif
			friend long double bit16_character_as_long_double(var const&) noexcept;
			friend long double bit32_character_as_long_double(var const&) noexcept;

#endif

			friend long double short_as_long_double(var const&) noexcept;
			friend long double unsigned_short_as_long_double(var const&) noexcept;
			friend long double integer_as_long_double(var const&) noexcept;
			friend long double unsigned_integer_as_long_double(var const&) noexcept;
			friend long double long_as_long_double(var const&) noexcept;
			friend long double unsigned_long_as_long_double(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend long double long_long_as_long_double(var const&) noexcept;
			friend long double unsigned_long_long_as_long_double(var const&) noexcept;

#endif

			friend long double float_as_long_double(var const&) noexcept;
			friend long double double_as_long_double(var const&) noexcept;
			friend long double long_double_as_long_double(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend long double string_as_long_double(var const&) noexcept;
			friend long double wide_string_as_long_double(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend long double bit8_string_as_long_double(var const&) noexcept;
		#endif
			friend long double bit16_string_as_long_double(var const&) noexcept;
			friend long double bit32_string_as_long_double(var const&) noexcept;

	#endif
#endif

			friend long double pointer_as_long_double(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend long double array_as_long_double(var const&) noexcept;
			friend long double subroutine_as_long_double(var const&) LIBLETLIB_NOEXCEPT;
			friend long double function_as_long_double(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend long double null_as_long_double(var const&) noexcept;

#endif

#ifndef LIBLETLIB_FREESTANDING

			friend char* boolean_as_string(var const&) noexcept;
			friend char* character_as_string(var const&) noexcept;
			friend char* signed_character_as_string(var const&) noexcept;
			friend char* unsigned_character_as_string(var const&) noexcept;
			friend char* wide_character_as_string(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend char* bit8_character_as_string(var const&) noexcept;
		#endif
			friend char* bit16_character_as_string(var const&) noexcept;
			friend char* bit32_character_as_string(var const&) noexcept;

	#endif

			friend char* short_as_string(var const&) noexcept;
			friend char* unsigned_short_as_string(var const&) noexcept;
			friend char* integer_as_string(var const&) noexcept;
			friend char* unsigned_integer_as_string(var const&) noexcept;
			friend char* long_as_string(var const&) noexcept;
			friend char* unsigned_long_as_string(var const&) noexcept;

	#if (__cplusplus >= 201103L)

			friend char* long_long_as_string(var const&) noexcept;
			friend char* unsigned_long_long_as_string(var const&) noexcept;

	#endif

			friend char* float_as_string(var const&) noexcept;
			friend char* double_as_string(var const&) noexcept;
			friend char* long_double_as_string(var const&) noexcept;
			friend char* string_as_string(var const&) noexcept;
			friend char* wide_string_as_string(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend char* bit8_string_as_string(var const&) noexcept;
		#endif
			friend char* bit16_string_as_string(var const&) noexcept;
			friend char* bit32_string_as_string(var const&) noexcept;

	#endif

			friend char* pointer_as_string(var const&) noexcept;
			friend char* array_as_string(var const&) noexcept;
			friend char* subroutine_as_string(var const&) LIBLETLIB_NOEXCEPT;
			friend char* function_as_string(var const&) noexcept;

	#if (__cplusplus >= 201103L)

			friend char* null_as_string(var const&) noexcept;

	#endif

			friend wchar_t* boolean_as_wide_string(var const&) noexcept;
			friend wchar_t* character_as_wide_string(var const&) noexcept;
			friend wchar_t* signed_character_as_wide_string(var const&) noexcept;
			friend wchar_t* unsigned_character_as_wide_string(var const&) noexcept;
			friend wchar_t* wide_character_as_wide_string(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend wchar_t* bit8_character_as_wide_string(var const&) noexcept;
		#endif
			friend wchar_t* bit16_character_as_wide_string(var const&) noexcept;
			friend wchar_t* bit32_character_as_wide_string(var const&) noexcept;

	#endif

			friend wchar_t* short_as_wide_string(var const&) noexcept;
			friend wchar_t* unsigned_short_as_wide_string(var const&) noexcept;
			friend wchar_t* integer_as_wide_string(var const&) noexcept;
			friend wchar_t* unsigned_integer_as_wide_string(var const&) noexcept;
			friend wchar_t* long_as_wide_string(var const&) noexcept;
			friend wchar_t* unsigned_long_as_wide_string(var const&) noexcept;

	#if (__cplusplus >= 201103L)

			friend wchar_t* long_long_as_wide_string(var const&) noexcept;
			friend wchar_t* unsigned_long_long_as_wide_string(var const&) noexcept;

	#endif

			friend wchar_t* float_as_wide_string(var const&) noexcept;
			friend wchar_t* double_as_wide_string(var const&) noexcept;
			friend wchar_t* long_double_as_wide_string(var const&) noexcept;
			friend wchar_t* string_as_wide_string(var const&) noexcept;
			friend wchar_t* wide_string_as_wide_string(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend wchar_t* bit8_string_as_wide_string(var const&) noexcept;
		#endif
			friend wchar_t* bit16_string_as_wide_string(var const&) noexcept;
			friend wchar_t* bit32_string_as_wide_string(var const&) noexcept;

	#endif

			friend wchar_t* pointer_as_wide_string(var const&) noexcept;
			friend wchar_t* array_as_wide_string(var const&) noexcept;
			friend wchar_t* subroutine_as_wide_string(var const&) LIBLETLIB_NOEXCEPT;
			friend wchar_t* function_as_wide_string(var const&) noexcept;

	#if (__cplusplus >= 201103L)

			friend wchar_t* null_as_wide_string(var const&) noexcept;

	#endif

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend char8_t* boolean_as_bit8_string(var const&) noexcept;
			friend char8_t* character_as_bit8_string(var const&) noexcept;
			friend char8_t* signed_character_as_bit8_string(var const&) noexcept;
			friend char8_t* unsigned_character_as_bit8_string(var const&) noexcept;
			friend char8_t* wide_character_as_bit8_string(var const&) noexcept;
			friend char8_t* bit8_character_as_bit8_string(var const&) noexcept;
			friend char8_t* bit16_character_as_bit8_string(var const&) noexcept;
			friend char8_t* bit32_character_as_bit8_string(var const&) noexcept;
			friend char8_t* short_as_bit8_string(var const&) noexcept;
			friend char8_t* unsigned_short_as_bit8_string(var const&) noexcept;
			friend char8_t* integer_as_bit8_string(var const&) noexcept;
			friend char8_t* unsigned_integer_as_bit8_string(var const&) noexcept;
			friend char8_t* long_as_bit8_string(var const&) noexcept;
			friend char8_t* unsigned_long_as_bit8_string(var const&) noexcept;
			friend char8_t* long_long_as_bit8_string(var const&) noexcept;
			friend char8_t* unsigned_long_long_as_bit8_string(var const&) noexcept;
			friend char8_t* float_as_bit8_string(var const&) noexcept;
			friend char8_t* double_as_bit8_string(var const&) noexcept;
			friend char8_t* long_double_as_bit8_string(var const&) noexcept;
			friend char8_t* string_as_bit8_string(var const&) noexcept;
			friend char8_t* wide_string_as_bit8_string(var const&) noexcept;
			friend char8_t* bit8_string_as_bit8_string(var const&) noexcept;
			friend char8_t* bit16_string_as_bit8_string(var const&) noexcept;
			friend char8_t* bit32_string_as_bit8_string(var const&) noexcept;
			friend char8_t* pointer_as_bit8_string(var const&) noexcept;
			friend char8_t* array_as_bit8_string(var const&) noexcept;
			friend char8_t* subroutine_as_bit8_string(var const&) LIBLETLIB_NOEXCEPT;
			friend char8_t* function_as_bit8_string(var const&) noexcept;
			friend char8_t* null_as_bit8_string(var const&) noexcept;
		#endif
			friend char16_t* boolean_as_bit16_string(var const&) noexcept;
			friend char16_t* character_as_bit16_string(var const&) noexcept;
			friend char16_t* signed_character_as_bit16_string(var const&) noexcept;
			friend char16_t* unsigned_character_as_bit16_string(var const&) noexcept;
			friend char16_t* wide_character_as_bit16_string(var const&) noexcept;
		#if (__cplusplus >= 202002L)
			friend char16_t* bit8_character_as_bit16_string(var const&) noexcept;
		#endif
			friend char16_t* bit16_character_as_bit16_string(var const&) noexcept;
			friend char16_t* bit32_character_as_bit16_string(var const&) noexcept;
			friend char16_t* short_as_bit16_string(var const&) noexcept;
			friend char16_t* unsigned_short_as_bit16_string(var const&) noexcept;
			friend char16_t* integer_as_bit16_string(var const&) noexcept;
			friend char16_t* unsigned_integer_as_bit16_string(var const&) noexcept;
			friend char16_t* long_as_bit16_string(var const&) noexcept;
			friend char16_t* unsigned_long_as_bit16_string(var const&) noexcept;
			friend char16_t* long_long_as_bit16_string(var const&) noexcept;
			friend char16_t* unsigned_long_long_as_bit16_string(var const&) noexcept;
			friend char16_t* float_as_bit16_string(var const&) noexcept;
			friend char16_t* double_as_bit16_string(var const&) noexcept;
			friend char16_t* long_double_as_bit16_string(var const&) noexcept;
			friend char16_t* string_as_bit16_string(var const&) noexcept;
			friend char16_t* wide_string_as_bit16_string(var const&) noexcept;
		#if (__cplusplus >= 202002L)
			friend char16_t* bit8_string_as_bit16_string(var const&) noexcept;
		#endif
			friend char16_t* bit16_string_as_bit16_string(var const&) noexcept;
			friend char16_t* bit32_string_as_bit16_string(var const&) noexcept;
			friend char16_t* pointer_as_bit16_string(var const&) noexcept;
			friend char16_t* array_as_bit16_string(var const&) noexcept;
			friend char16_t* subroutine_as_bit16_string(var const&) LIBLETLIB_NOEXCEPT;
			friend char16_t* function_as_bit16_string(var const&) noexcept;
			friend char16_t* null_as_bit16_string(var const&) noexcept;

			friend char32_t* boolean_as_bit32_string(var const&) noexcept;
			friend char32_t* character_as_bit32_string(var const&) noexcept;
			friend char32_t* signed_character_as_bit32_string(var const&) noexcept;
			friend char32_t* unsigned_character_as_bit32_string(var const&) noexcept;
			friend char32_t* wide_character_as_bit32_string(var const&) noexcept;
		#if (__cplusplus >= 202002L)
			friend char32_t* bit8_character_as_bit32_string(var const&) noexcept;
		#endif
			friend char32_t* bit16_character_as_bit32_string(var const&) noexcept;
			friend char32_t* bit32_character_as_bit32_string(var const&) noexcept;
			friend char32_t* short_as_bit32_string(var const&) noexcept;
			friend char32_t* unsigned_short_as_bit32_string(var const&) noexcept;
			friend char32_t* integer_as_bit32_string(var const&) noexcept;
			friend char32_t* unsigned_integer_as_bit32_string(var const&) noexcept;
			friend char32_t* long_as_bit32_string(var const&) noexcept;
			friend char32_t* unsigned_long_as_bit32_string(var const&) noexcept;
			friend char32_t* long_long_as_bit32_string(var const&) noexcept;
			friend char32_t* unsigned_long_long_as_bit32_string(var const&) noexcept;
			friend char32_t* float_as_bit32_string(var const&) noexcept;
			friend char32_t* double_as_bit32_string(var const&) noexcept;
			friend char32_t* long_double_as_bit32_string(var const&) noexcept;
			friend char32_t* string_as_bit32_string(var const&) noexcept;
			friend char32_t* wide_string_as_bit32_string(var const&) noexcept;
		#if (__cplusplus >= 202002L)
			friend char32_t* bit8_string_as_bit32_string(var const&) noexcept;
		#endif
			friend char32_t* bit16_string_as_bit32_string(var const&) noexcept;
			friend char32_t* bit32_string_as_bit32_string(var const&) noexcept;
			friend char32_t* pointer_as_bit32_string(var const&) noexcept;
			friend char32_t* array_as_bit32_string(var const&) noexcept;
			friend char32_t* subroutine_as_bit32_string(var const&) LIBLETLIB_NOEXCEPT;
			friend char32_t* function_as_bit32_string(var const&) noexcept;
			friend char32_t* null_as_bit32_string(var const&) noexcept;

	#endif
#endif

			friend void* boolean_as_pointer(var const&) noexcept;
			friend void* character_as_pointer(var const&) noexcept;
			friend void* signed_character_as_pointer(var const&) noexcept;
			friend void* unsigned_character_as_pointer(var const&) noexcept;
			friend void* wide_character_as_pointer(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend void* bit8_character_as_pointer(var const&) noexcept;
	#endif
			friend void* bit16_character_as_pointer(var const&) noexcept;
			friend void* bit32_character_as_pointer(var const&) noexcept;

#endif

			friend void* short_as_pointer(var const&) noexcept;
			friend void* unsigned_short_as_pointer(var const&) noexcept;
			friend void* integer_as_pointer(var const&) noexcept;
			friend void* unsigned_integer_as_pointer(var const&) noexcept;
			friend void* long_as_pointer(var const&) noexcept;
			friend void* unsigned_long_as_pointer(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend void* long_long_as_pointer(var const&) noexcept;
			friend void* unsigned_long_long_as_pointer(var const&) noexcept;

#endif

			friend void* float_as_pointer(var const&) noexcept;
			friend void* double_as_pointer(var const&) noexcept;
			friend void* long_double_as_pointer(var const&) noexcept;
			friend void* string_as_pointer(var const&) noexcept;
			friend void* wide_string_as_pointer(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend void* bit8_string_as_pointer(var const&) noexcept;
	#endif
			friend void* bit16_string_as_pointer(var const&) noexcept;
			friend void* bit32_string_as_pointer(var const&) noexcept;

#endif

			friend void* pointer_as_pointer(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend void* array_as_pointer(var const&) noexcept;
			friend void* subroutine_as_pointer(var const&) LIBLETLIB_NOEXCEPT;
			friend void* function_as_pointer(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend void* null_as_pointer(var const&) noexcept;

#endif

			friend subroutine_t boolean_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t signed_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t unsigned_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t wide_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend subroutine_t bit8_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend subroutine_t bit16_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t bit32_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend subroutine_t short_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t unsigned_short_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t integer_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t unsigned_integer_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t long_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t unsigned_long_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
#if (__cplusplus >= 201103L)
			friend subroutine_t long_long_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t unsigned_long_long_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
#endif
			friend subroutine_t float_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t double_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t long_double_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t string_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t wide_string_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend subroutine_t bit8_string_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend subroutine_t bit16_string_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t bit32_string_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend subroutine_t pointer_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t subroutine_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t function_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t array_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend subroutine_t null_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t boolean_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t character_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t signed_character_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t unsigned_character_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t wide_character_as_function(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend function_t bit8_character_as_function(var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend function_t bit16_character_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t bit32_character_as_function(var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend function_t short_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t unsigned_short_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t integer_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t unsigned_integer_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t long_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t unsigned_long_as_function(var const&) LIBLETLIB_NOEXCEPT;
#if (__cplusplus >= 201103L)
			friend function_t long_long_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t unsigned_long_long_as_function(var const&) LIBLETLIB_NOEXCEPT;
#endif
			friend function_t float_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t double_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t long_double_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t string_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t wide_string_as_function(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend function_t bit8_string_as_function(var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend function_t bit16_string_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t bit32_string_as_function(var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend function_t pointer_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t subroutine_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t function_as_function(var const&) noexcept;
			friend function_t array_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend function_t null_as_function(var const&) LIBLETLIB_NOEXCEPT;
			friend var boolean_as_array(var const&) noexcept;
			friend var character_as_array(var const&) noexcept;
			friend var signed_character_as_array(var const&) noexcept;
			friend var unsigned_character_as_array(var const&) noexcept;
			friend var wide_character_as_array(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_as_array(var const&) noexcept;
	#endif
			friend var bit16_character_as_array(var const&) noexcept;
			friend var bit32_character_as_array(var const&) noexcept;

#endif

			friend var short_as_array(var const&) noexcept;
			friend var unsigned_short_as_array(var const&) noexcept;
			friend var integer_as_array(var const&) noexcept;
			friend var unsigned_integer_as_array(var const&) noexcept;
			friend var long_as_array(var const&) noexcept;
			friend var unsigned_long_as_array(var const&) noexcept;
#if (__cplusplus >= 201103L)
			friend var long_long_as_array(var const&) noexcept;
			friend var unsigned_long_long_as_array(var const&) noexcept;
#endif
			friend var float_as_array(var const&) noexcept;
			friend var double_as_array(var const&) noexcept;
			friend var long_double_as_array(var const&) noexcept;
			friend var string_as_array(var const&) noexcept;
			friend var wide_string_as_array(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_as_array(var const&) noexcept;
	#endif
			friend var bit16_string_as_array(var const&) noexcept;
			friend var bit32_string_as_array(var const&) noexcept;

#endif

			friend var pointer_as_array(var const&) noexcept;
			friend var subroutine_as_array(var const&) noexcept;
			friend var function_as_array(var const&) noexcept;
			friend var array_as_array(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var null_as_array(var const&) noexcept;

#endif

#if (__cplusplus >= 201103L)
			friend std::nullptr_t function_as_null(var const&) noexcept;
#endif

			friend var boolean_negative(var const&) noexcept;
			friend var character_negative(var const&) noexcept;
			friend var signed_character_negative(var const&) noexcept;
			friend var unsigned_character_negative(var const&) noexcept;
			friend var wide_character_negative(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_negative(var const&) noexcept;
	#endif
			friend var bit16_character_negative(var const&) noexcept;
			friend var bit32_character_negative(var const&) noexcept;

#endif

			friend var short_negative(var const&) noexcept;
			friend var unsigned_short_negative(var const&) noexcept;
			friend var integer_negative(var const&) noexcept;
			friend var unsigned_integer_negative(var const&) noexcept;
			friend var long_negative(var const&) noexcept;
			friend var unsigned_long_negative(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_negative(var const&) noexcept;
			friend var unsigned_long_long_negative(var const&) noexcept;

#endif

			friend var float_negative(var const&) noexcept;
			friend var double_negative(var const&) noexcept;
			friend var long_double_negative(var const&) noexcept;
			friend var string_negative(var const&) noexcept;
			friend var wide_string_negative(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_negative(var const&) noexcept;
	#endif
			friend var bit16_string_negative(var const&) noexcept;
			friend var bit32_string_negative(var const&) noexcept;

#endif

			friend var pointer_negative(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var array_negative(var const&) LIBLETLIB_NOEXCEPT;
			friend var subroutine_negative(var const&) LIBLETLIB_NOEXCEPT;
			friend var function_negative(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend var null_negative(var const&) noexcept;

#endif

			friend var boolean_positive(var const&) noexcept;
			friend var character_positive(var const&) noexcept;
			friend var signed_character_positive(var const&) noexcept;
			friend var unsigned_character_positive(var const&) noexcept;
			friend var wide_character_positive(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_positive(var const&) noexcept;
	#endif
			friend var bit16_character_positive(var const&) noexcept;
			friend var bit32_character_positive(var const&) noexcept;

#endif

			friend var short_positive(var const&) noexcept;
			friend var unsigned_short_positive(var const&) noexcept;
			friend var integer_positive(var const&) noexcept;
			friend var unsigned_integer_positive(var const&) noexcept;
			friend var long_positive(var const&) noexcept;
			friend var unsigned_long_positive(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_positive(var const&) noexcept;
			friend var unsigned_long_long_positive(var const&) noexcept;

#endif

			friend var float_positive(var const&) noexcept;
			friend var double_positive(var const&) noexcept;
			friend var long_double_positive(var const&) noexcept;
			friend var string_positive(var const&) noexcept;
			friend var wide_string_positive(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_positive(var const&) noexcept;
	#endif
			friend var bit16_string_positive(var const&) noexcept;
			friend var bit32_string_positive(var const&) noexcept;

#endif

			friend var pointer_positive(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var array_positive(var const&) LIBLETLIB_NOEXCEPT;
			friend var subroutine_positive(var const&) LIBLETLIB_NOEXCEPT;
			friend var function_positive(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend var null_positive(var const&) noexcept;

#endif

			friend var boolean_increment(var const&) noexcept;
			friend var character_increment(var const&) noexcept;
			friend var signed_character_increment(var const&) noexcept;
			friend var unsigned_character_increment(var const&) noexcept;
			friend var wide_character_increment(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_increment(var const&) noexcept;
	#endif
			friend var bit16_character_increment(var const&) noexcept;
			friend var bit32_character_increment(var const&) noexcept;

#endif

			friend var short_increment(var const&) noexcept;
			friend var unsigned_short_increment(var const&) noexcept;
			friend var integer_increment(var const&) noexcept;
			friend var unsigned_integer_increment(var const&) noexcept;
			friend var long_increment(var const&) noexcept;
			friend var unsigned_long_increment(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_increment(var const&) noexcept;
			friend var unsigned_long_long_increment(var const&) noexcept;

#endif

			friend var float_increment(var const&) noexcept;
			friend var double_increment(var const&) noexcept;
			friend var long_double_increment(var const&) noexcept;
			friend var string_increment(var const&) noexcept;
			friend var wide_string_increment(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_increment(var const&) noexcept;
	#endif
			friend var bit16_string_increment(var const&) noexcept;
			friend var bit32_string_increment(var const&) noexcept;

#endif

			friend var pointer_increment(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var array_increment(var const&) LIBLETLIB_NOEXCEPT;
			friend var subroutine_increment(var const&) LIBLETLIB_NOEXCEPT;
			friend var function_increment(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend var null_increment(var const&) noexcept;

#endif

			friend var boolean_decrement(var const&) noexcept;
			friend var character_decrement(var const&) noexcept;
			friend var signed_character_decrement(var const&) noexcept;
			friend var unsigned_character_decrement(var const&) noexcept;
			friend var wide_character_decrement(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_decrement(var const&) noexcept;
	#endif
			friend var bit16_character_decrement(var const&) noexcept;
			friend var bit32_character_decrement(var const&) noexcept;

#endif

			friend var short_decrement(var const&) noexcept;
			friend var unsigned_short_decrement(var const&) noexcept;
			friend var integer_decrement(var const&) noexcept;
			friend var unsigned_integer_decrement(var const&) noexcept;
			friend var long_decrement(var const&) noexcept;
			friend var unsigned_long_decrement(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_decrement(var const&) noexcept;
			friend var unsigned_long_long_decrement(var const&) noexcept;

#endif

			friend var float_decrement(var const&) noexcept;
			friend var double_decrement(var const&) noexcept;
			friend var long_double_decrement(var const&) noexcept;
			friend var string_decrement(var const&) noexcept;
			friend var wide_string_decrement(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_decrement(var const&) noexcept;
	#endif
			friend var bit16_string_decrement(var const&) noexcept;
			friend var bit32_string_decrement(var const&) noexcept;

#endif

			friend var pointer_decrement(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var array_decrement(var const&) LIBLETLIB_NOEXCEPT;
			friend var subroutine_decrement(var const&) LIBLETLIB_NOEXCEPT;
			friend var function_decrement(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend var null_decrement(var const&) noexcept;

#endif

			friend var boolean_negation(var const&) noexcept;
			friend var character_negation(var const&) noexcept;
			friend var signed_character_negation(var const&) noexcept;
			friend var unsigned_character_negation(var const&) noexcept;
			friend var wide_character_negation(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_negation(var const&) noexcept;
	#endif
			friend var bit16_character_negation(var const&) noexcept;
			friend var bit32_character_negation(var const&) noexcept;

#endif

			friend var short_negation(var const&) noexcept;
			friend var unsigned_short_negation(var const&) noexcept;
			friend var integer_negation(var const&) noexcept;
			friend var unsigned_integer_negation(var const&) noexcept;
			friend var long_negation(var const&) noexcept;
			friend var unsigned_long_negation(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_negation(var const&) noexcept;
			friend var unsigned_long_long_negation(var const&) noexcept;

#endif

			friend var float_negation(var const&) noexcept;
			friend var double_negation(var const&) noexcept;
			friend var long_double_negation(var const&) noexcept;
			friend var string_negation(var const&) noexcept;
			friend var wide_string_negation(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_negation(var const&) noexcept;
	#endif
			friend var bit16_string_negation(var const&) noexcept;
			friend var bit32_string_negation(var const&) noexcept;

#endif

			friend var pointer_negation(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var array_negation(var const&) LIBLETLIB_NOEXCEPT;
			friend var subroutine_negation(var const&) LIBLETLIB_NOEXCEPT;
			friend var function_negation(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend var null_negation(var const&) noexcept;

#endif

			friend var boolean_complement(var const&) noexcept;
			friend var character_complement(var const&) noexcept;
			friend var signed_character_complement(var const&) noexcept;
			friend var unsigned_character_complement(var const&) noexcept;
			friend var wide_character_complement(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_complement(var const&) noexcept;
	#endif
			friend var bit16_character_complement(var const&) noexcept;
			friend var bit32_character_complement(var const&) noexcept;

#endif

			friend var short_complement(var const&) noexcept;
			friend var unsigned_short_complement(var const&) noexcept;
			friend var integer_complement(var const&) noexcept;
			friend var unsigned_integer_complement(var const&) noexcept;
			friend var long_complement(var const&) noexcept;
			friend var unsigned_long_complement(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_complement(var const&) noexcept;
			friend var unsigned_long_long_complement(var const&) noexcept;

#endif

			friend var float_complement(var const&) noexcept;
			friend var double_complement(var const&) noexcept;
			friend var long_double_complement(var const&) noexcept;
			friend var string_complement(var const&) noexcept;
			friend var wide_string_complement(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_complement(var const&) noexcept;
	#endif
			friend var bit16_string_complement(var const&) noexcept;
			friend var bit32_string_complement(var const&) noexcept;

#endif

			friend var pointer_complement(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var array_complement(var const&) LIBLETLIB_NOEXCEPT;
			friend var subroutine_complement(var const&) LIBLETLIB_NOEXCEPT;
			friend var function_complement(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend var null_complement(var const&) noexcept;

#endif

			friend var boolean_indirection(var const&) noexcept;
			friend var character_indirection(var const&) noexcept;
			friend var signed_character_indirection(var const&) noexcept;
			friend var unsigned_character_indirection(var const&) noexcept;
			friend var wide_character_indirection(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_indirection(var const&) noexcept;
	#endif
			friend var bit16_character_indirection(var const&) noexcept;
			friend var bit32_character_indirection(var const&) noexcept;

#endif

			friend var short_indirection(var const&) noexcept;
			friend var unsigned_short_indirection(var const&) noexcept;
			friend var integer_indirection(var const&) noexcept;
			friend var unsigned_integer_indirection(var const&) noexcept;
			friend var long_indirection(var const&) noexcept;
			friend var unsigned_long_indirection(var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_indirection(var const&) noexcept;
			friend var unsigned_long_long_indirection(var const&) noexcept;

#endif

			friend var float_indirection(var const&) noexcept;
			friend var double_indirection(var const&) noexcept;
			friend var long_double_indirection(var const&) noexcept;
			friend var string_indirection(var const&) noexcept;
			friend var wide_string_indirection(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_indirection(var const&) noexcept;
	#endif
			friend var bit16_string_indirection(var const&) noexcept;
			friend var bit32_string_indirection(var const&) noexcept;

#endif

			friend var pointer_indirection(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var array_indirection(var const&) noexcept;
			friend var subroutine_indirection(var const&) LIBLETLIB_NOEXCEPT;
			friend var function_indirection(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend var null_indirection(var const&) noexcept;

#endif

			friend var boolean_index(var const&, var const&) noexcept;
			friend var character_index(var const&, var const&) noexcept;
			friend var signed_character_index(var const&, var const&) noexcept;
			friend var unsigned_character_index(var const&, var const&) noexcept;
			friend var wide_character_index(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_index(var const&, var const&) noexcept;
	#endif
			friend var bit16_character_index(var const&, var const&) noexcept;
			friend var bit32_character_index(var const&, var const&) noexcept;

#endif

			friend var short_index(var const&, var const&) noexcept;
			friend var unsigned_short_index(var const&, var const&) noexcept;
			friend var integer_index(var const&, var const&) noexcept;
			friend var unsigned_integer_index(var const&, var const&) noexcept;
			friend var long_index(var const&, var const&) noexcept;
			friend var unsigned_long_index(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_index(var const&, var const&) noexcept;
			friend var unsigned_long_long_index(var const&, var const&) noexcept;

#endif

			friend var float_index(var const&, var const&) noexcept;
			friend var double_index(var const&, var const&) noexcept;
			friend var long_double_index(var const&, var const&) noexcept;
			friend var string_index(var const&, var const&) noexcept;
			friend var wide_string_index(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_index(var const&, var const&) noexcept;
	#endif
			friend var bit16_string_index(var const&, var const&) noexcept;
			friend var bit32_string_index(var const&, var const&) noexcept;

#endif

			friend var pointer_index(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var array_index(var const&, var const&) noexcept;
			friend var subroutine_index(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var function_index(var const&, var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

			friend var null_index(var const&, var const&) noexcept;

#endif

			friend var boolean_subtraction(var const&, var const&) noexcept;
			friend var character_subtraction(var const&, var const&) noexcept;
			friend var signed_character_subtraction(var const&, var const&) noexcept;
			friend var unsigned_character_subtraction(var const&, var const&) noexcept;
			friend var wide_character_subtraction(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_subtraction(var const&, var const&) noexcept;
	#endif
			friend var bit16_character_subtraction(var const&, var const&) noexcept;
			friend var bit32_character_subtraction(var const&, var const&) noexcept;

#endif

			friend var short_subtraction(var const&, var const&) noexcept;
			friend var unsigned_short_subtraction(var const&, var const&) noexcept;
			friend var integer_subtraction(var const&, var const&) noexcept;
			friend var unsigned_integer_subtraction(var const&, var const&) noexcept;
			friend var long_subtraction(var const&, var const&) noexcept;
			friend var unsigned_long_subtraction(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_subtraction(var const&, var const&) noexcept;
			friend var unsigned_long_long_subtraction(var const&, var const&) noexcept;

#endif

			friend var float_subtraction(var const&, var const&) noexcept;
			friend var double_subtraction(var const&, var const&) noexcept;
			friend var long_double_subtraction(var const&, var const&) noexcept;
			friend var string_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var wide_string_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend var bit16_string_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var bit32_string_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend var pointer_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

#if (__cplusplus >= 201103L)

			friend var subroutine_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var function_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#ifndef LIBLETLIB_FREESTANDING

			friend var array_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

#if (__cplusplus >= 201103L)

			friend var null_subtraction(var const&, var const&) noexcept;

#endif

			friend var boolean_sum(var const&, var const&) noexcept;
			friend var character_sum(var const&, var const&) noexcept;
			friend var signed_character_sum(var const&, var const&) noexcept;
			friend var unsigned_character_sum(var const&, var const&) noexcept;
			friend var wide_character_sum(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_sum(var const&, var const&) noexcept;
	#endif
			friend var bit16_character_sum(var const&, var const&) noexcept;
			friend var bit32_character_sum(var const&, var const&) noexcept;

#endif

			friend var short_sum(var const&, var const&) noexcept;
			friend var unsigned_short_sum(var const&, var const&) noexcept;
			friend var integer_sum(var const&, var const&) noexcept;
			friend var unsigned_integer_sum(var const&, var const&) noexcept;
			friend var long_sum(var const&, var const&) noexcept;
			friend var unsigned_long_sum(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_sum(var const&, var const&) noexcept;
			friend var unsigned_long_long_sum(var const&, var const&) noexcept;

#endif

			friend var float_sum(var const&, var const&) noexcept;
			friend var double_sum(var const&, var const&) noexcept;
			friend var long_double_sum(var const&, var const&) noexcept;
			friend var string_sum(var const&, var const&) noexcept;
			friend var wide_string_sum(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_sum(var const&, var const&) noexcept;
	#endif
			friend var bit16_string_sum(var const&, var const&) noexcept;
			friend var bit32_string_sum(var const&, var const&) noexcept;

#endif

			friend var pointer_sum(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var subroutine_sum(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var function_sum(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var array_sum(var const&, var const&) noexcept;

#endif

#if (__cplusplus >= 201103L)

			friend var null_sum(var const&, var const&) noexcept;

#endif

			friend var boolean_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var signed_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var unsigned_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var wide_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend var bit16_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var bit32_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend var short_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var unsigned_short_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var integer_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var unsigned_integer_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var long_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var unsigned_long_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#if (__cplusplus >= 201103L)

			friend var long_long_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var unsigned_long_long_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend var float_division(var const&, var const&) noexcept;
			friend var double_division(var const&, var const&) noexcept;
			friend var long_double_division(var const&, var const&) noexcept;
			friend var string_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var wide_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend var bit16_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var bit32_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend var pointer_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var subroutine_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var function_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var array_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

#if (__cplusplus >= 201103L)

			friend var null_division(var const&, var const&) noexcept;

#endif

			friend var boolean_multiplication(var const&, var const&) noexcept;
			friend var character_multiplication(var const&, var const&) noexcept;
			friend var signed_character_multiplication(var const&, var const&) noexcept;
			friend var unsigned_character_multiplication(var const&, var const&) noexcept;
			friend var wide_character_multiplication(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_multiplication(var const&, var const&) noexcept;
	#endif
			friend var bit16_character_multiplication(var const&, var const&) noexcept;
			friend var bit32_character_multiplication(var const&, var const&) noexcept;

#endif

			friend var short_multiplication(var const&, var const&) noexcept;
			friend var unsigned_short_multiplication(var const&, var const&) noexcept;
			friend var integer_multiplication(var const&, var const&) noexcept;
			friend var unsigned_integer_multiplication(var const&, var const&) noexcept;
			friend var long_multiplication(var const&, var const&) noexcept;
			friend var unsigned_long_multiplication(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_multiplication(var const&, var const&) noexcept;
			friend var unsigned_long_long_multiplication(var const&, var const&) noexcept;

#endif

			friend var float_multiplication(var const&, var const&) noexcept;
			friend var double_multiplication(var const&, var const&) noexcept;
			friend var long_double_multiplication(var const&, var const&) noexcept;
			friend var string_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var wide_string_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend var bit16_string_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var bit32_string_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend var pointer_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

#if (__cplusplus >= 201103L)

			friend var subroutine_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var function_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#ifndef LIBLETLIB_FREESTANDING

			friend var array_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

#if (__cplusplus >= 201103L)

			friend var null_multiplication(var const&, var const&) noexcept;

#endif

			friend var boolean_modulo(var const&, var const&) noexcept;
			friend var character_modulo(var const&, var const&) noexcept;
			friend var signed_character_modulo(var const&, var const&) noexcept;
			friend var unsigned_character_modulo(var const&, var const&) noexcept;
			friend var wide_character_modulo(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_modulo(var const&, var const&) noexcept;
	#endif
			friend var bit16_character_modulo(var const&, var const&) noexcept;
			friend var bit32_character_modulo(var const&, var const&) noexcept;

#endif

			friend var short_modulo(var const&, var const&) noexcept;
			friend var unsigned_short_modulo(var const&, var const&) noexcept;
			friend var integer_modulo(var const&, var const&) noexcept;
			friend var unsigned_integer_modulo(var const&, var const&) noexcept;
			friend var long_modulo(var const&, var const&) noexcept;
			friend var unsigned_long_modulo(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_modulo(var const&, var const&) noexcept;
			friend var unsigned_long_long_modulo(var const&, var const&) noexcept;

#endif

			friend var float_modulo(var const&, var const&) noexcept;
			friend var double_modulo(var const&, var const&) noexcept;
			friend var long_double_modulo(var const&, var const&) noexcept;
			friend var string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var wide_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend var bit16_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var bit32_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend var pointer_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

#if (__cplusplus >= 201103L)

			friend var subroutine_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var function_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#ifndef LIBLETLIB_FREESTANDING

			friend var array_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

#if (__cplusplus >= 201103L)

			friend var null_modulo(var const&, var const&) noexcept;

#endif

			friend var boolean_exponentiation(var const&, var const&) noexcept;
			friend var character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var signed_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var unsigned_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var wide_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend var bit16_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var bit32_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend var short_exponentiation(var const&, var const&) noexcept;
			friend var unsigned_short_exponentiation(var const&, var const&) noexcept;
			friend var integer_exponentiation(var const&, var const&) noexcept;
			friend var unsigned_integer_exponentiation(var const&, var const&) noexcept;
			friend var long_exponentiation(var const&, var const&) noexcept;
			friend var unsigned_long_exponentiation(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_exponentiation(var const&, var const&) noexcept;
			friend var unsigned_long_long_exponentiation(var const&, var const&) noexcept;

#endif

			friend var float_exponentiation(var const&, var const&) noexcept;
			friend var double_exponentiation(var const&, var const&) noexcept;
			friend var long_double_exponentiation(var const&, var const&) noexcept;
			friend var string_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var wide_string_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend var bit16_string_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var bit32_string_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend var pointer_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var subroutine_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var function_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var array_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

#if (__cplusplus >= 201103L)

			friend var null_exponentiation(var const&, var const&) noexcept;

#endif

			friend var boolean_binary_and(var const&, var const&) noexcept;
			friend var character_binary_and(var const&, var const&) noexcept;
			friend var signed_character_binary_and(var const&, var const&) noexcept;
			friend var unsigned_character_binary_and(var const&, var const&) noexcept;
			friend var wide_character_binary_and(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_binary_and(var const&, var const&) noexcept;
	#endif
			friend var bit16_character_binary_and(var const&, var const&) noexcept;
			friend var bit32_character_binary_and(var const&, var const&) noexcept;

#endif

			friend var short_binary_and(var const&, var const&) noexcept;
			friend var unsigned_short_binary_and(var const&, var const&) noexcept;
			friend var integer_binary_and(var const&, var const&) noexcept;
			friend var unsigned_integer_binary_and(var const&, var const&) noexcept;
			friend var long_binary_and(var const&, var const&) noexcept;
			friend var unsigned_long_binary_and(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_binary_and(var const&, var const&) noexcept;
			friend var unsigned_long_long_binary_and(var const&, var const&) noexcept;

#endif

			friend var float_binary_and(var const&, var const&) noexcept;
			friend var double_binary_and(var const&, var const&) noexcept;
			friend var long_double_binary_and(var const&, var const&) noexcept;
			friend var string_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var wide_string_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend var bit16_string_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var bit32_string_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend var pointer_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

#if (__cplusplus >= 201103L)

			friend var subroutine_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var function_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#ifndef LIBLETLIB_FREESTANDING

			friend var array_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

#if (__cplusplus >= 201103L)

			friend var null_binary_and(var const&, var const&) noexcept;

#endif

			friend var boolean_binary_or(var const&, var const&) noexcept;
			friend var character_binary_or(var const&, var const&) noexcept;
			friend var signed_character_binary_or(var const&, var const&) noexcept;
			friend var unsigned_character_binary_or(var const&, var const&) noexcept;
			friend var wide_character_binary_or(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_binary_or(var const&, var const&) noexcept;
	#endif
			friend var bit16_character_binary_or(var const&, var const&) noexcept;
			friend var bit32_character_binary_or(var const&, var const&) noexcept;

#endif

			friend var short_binary_or(var const&, var const&) noexcept;
			friend var unsigned_short_binary_or(var const&, var const&) noexcept;
			friend var integer_binary_or(var const&, var const&) noexcept;
			friend var unsigned_integer_binary_or(var const&, var const&) noexcept;
			friend var long_binary_or(var const&, var const&) noexcept;
			friend var unsigned_long_binary_or(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_binary_or(var const&, var const&) noexcept;
			friend var unsigned_long_long_binary_or(var const&, var const&) noexcept;

#endif

			friend var float_binary_or(var const&, var const&) noexcept;
			friend var double_binary_or(var const&, var const&) noexcept;
			friend var long_double_binary_or(var const&, var const&) noexcept;
			friend var string_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var wide_string_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend var bit16_string_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var bit32_string_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend var pointer_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var subroutine_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var function_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var array_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

#if (__cplusplus >= 201103L)

			friend var null_binary_or(var const&, var const&) noexcept;

#endif

			friend var boolean_binary_xor(var const&, var const&) noexcept;
			friend var character_binary_xor(var const&, var const&) noexcept;
			friend var signed_character_binary_xor(var const&, var const&) noexcept;
			friend var unsigned_character_binary_xor(var const&, var const&) noexcept;
			friend var wide_character_binary_xor(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_character_binary_xor(var const&, var const&) noexcept;
	#endif
			friend var bit16_character_binary_xor(var const&, var const&) noexcept;
			friend var bit32_character_binary_xor(var const&, var const&) noexcept;

#endif

			friend var short_binary_xor(var const&, var const&) noexcept;
			friend var unsigned_short_binary_xor(var const&, var const&) noexcept;
			friend var integer_binary_xor(var const&, var const&) noexcept;
			friend var unsigned_integer_binary_xor(var const&, var const&) noexcept;
			friend var long_binary_xor(var const&, var const&) noexcept;
			friend var unsigned_long_binary_xor(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend var long_long_binary_xor(var const&, var const&) noexcept;
			friend var unsigned_long_long_binary_xor(var const&, var const&) noexcept;

#endif

			friend var float_binary_xor(var const&, var const&) noexcept;
			friend var double_binary_xor(var const&, var const&) noexcept;
			friend var long_double_binary_xor(var const&, var const&) noexcept;
			friend var string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var wide_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend var bit8_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
			friend var bit16_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var bit32_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

			friend var pointer_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

			friend var subroutine_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var function_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var array_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

#if (__cplusplus >= 201103L)

			friend var null_binary_xor(var const&, var const&) noexcept;

#endif

			friend int boolean_comparison(var const&, var const&) noexcept;
			friend int character_comparison(var const&, var const&) noexcept;
			friend int signed_character_comparison(var const&, var const&) noexcept;
			friend int unsigned_character_comparison(var const&, var const&) noexcept;
			friend int wide_character_comparison(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend int bit8_character_comparison(var const&, var const&) noexcept;
	#endif
			friend int bit16_character_comparison(var const&, var const&) noexcept;
			friend int bit32_character_comparison(var const&, var const&) noexcept;

#endif

			friend int short_comparison(var const&, var const&) noexcept;
			friend int unsigned_short_comparison(var const&, var const&) noexcept;
			friend int integer_comparison(var const&, var const&) noexcept;
			friend int unsigned_integer_comparison(var const&, var const&) noexcept;
			friend int long_comparison(var const&, var const&) noexcept;
			friend int unsigned_long_comparison(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

			friend int long_long_comparison(var const&, var const&) noexcept;
			friend int unsigned_long_long_comparison(var const&, var const&) noexcept;

#endif

			friend int float_comparison(var const&, var const&) noexcept;
			friend int double_comparison(var const&, var const&) noexcept;
			friend int long_double_comparison(var const&, var const&) noexcept;
			friend int string_comparison(var const&, var const&) noexcept;
			friend int wide_string_comparison(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			friend int bit8_string_comparison(var const&, var const&) noexcept;
	#endif
			friend int bit16_string_comparison(var const&, var const&) noexcept;
			friend int bit32_string_comparison(var const&, var const&) noexcept;

#endif

			friend int pointer_comparison(var const&, var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

			friend int subroutine_comparison(var const&, var const&) noexcept;
			friend int function_comparison(var const&, var const&) noexcept;
			friend int array_comparison(var const&, var const&) noexcept;

#endif

#if (__cplusplus >= 201103L)

			friend int null_comparison(var const&, var const&) noexcept;
			friend var_iterator begin(var const&) noexcept;
			friend var_iterator end(var const&) noexcept;
			friend let_iterator cbegin(var const&) noexcept;
			friend let_iterator cend(var const&) noexcept;
			friend var_reverse_iterator rbegin(var const&) noexcept;
			friend var_reverse_iterator rend(var const&) noexcept;
			friend let_reverse_iterator crbegin(var const&) noexcept;
			friend let_reverse_iterator crend(var const&) noexcept;
#endif

#ifndef LIBLETLIB_FREESTANDING

			friend void string_deallocate(var const&) noexcept;
			friend void wide_string_deallocate(var const&) noexcept;
			friend void array_deallocate(var const&) noexcept;
			friend void object_deallocate(var const&) noexcept;
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			friend void bit8_string_deallocate(var const&) noexcept;
		#endif
			friend void bit16_string_deallocate(var const&) noexcept;
			friend void bit32_string_deallocate(var const&) noexcept;
	#endif
#endif

			friend char backing::type_id(var const&) noexcept;
			friend char const* backing::type_string(var const&) noexcept;
			friend std::size_t backing::length(var const&) noexcept;
			friend var& property_reference(var const&, char const*) noexcept;
			template<typename UniqueDummy, typename... Arguments>
			friend var curry_(UniqueDummy&&, var const&, Arguments const&...) noexcept;
			friend int backing::rank_compare(var const&, var const&) noexcept;
			friend bool backing::is_string(var const& value) noexcept;
			friend bool backing::is_character(var const&) noexcept;
			friend bool backing::is_integral(var const&) noexcept;
			friend bool backing::is_floating_point(var const&) noexcept;
			friend bool backing::is_boolean(var const&) noexcept;
			friend bool backing::is_unsigned(var const&) noexcept;
			friend bool backing::is_signed(var const&) noexcept;
			friend bool backing::is_invokable(var const&) noexcept;
			friend bool backing::is_list(var const&) noexcept;
			friend bool backing::is_object(var const&) noexcept;
			friend bool backing::is_null(var const&) noexcept;
			friend bool backing::is_empty(var const&) noexcept;
			friend bool backing::is_curried(var const&) noexcept;

#ifdef LIBLETLIB_HOSTED
			friend var pattern_(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var foldl_(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var foldr_(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var map_(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var filter_(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var peek_(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var head_(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var tail_(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend var zip_(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend std::ostream& operator<<(std::ostream& _out, var const& _item) noexcept;
			friend std::wostream& operator<<(std::wostream& _out, var const& _item) noexcept;
#endif


			/// \brief Empty constructor initializes to previous null pointer.
			///
			///	Either NULL void pointer or nullptr depending on C++ standard.
			var() noexcept
			{
				this->value = value_union();
				this->size  = size_struct();
#if (__cplusplus >= 201103L)
				this->behaviour = &null_behaviour;
#else
				this->behaviour = &pointer_behaviour;
#endif
			}

			/// \brief Constructor for bool value.
			///
			///	\param _value to wrap.
			var(bool const _value) noexcept
			{
				this->value.bool_type = _value;
				this->size            = size_struct();
				this->behaviour       = &boolean_behaviour;
			}

			/// \brief Constructor for char value.
			///
			///	\param _value to wrap.
			var(char const _value) noexcept
			{
				this->value.char_type = _value;
				this->size            = size_struct();
				this->behaviour       = &character_behaviour;
			}

			/// \brief Constructor for signed char value.
			///
			///	\param _value to wrap.
			var(signed char const _value) noexcept
			{
				this->value.signed_char_type = _value;
				this->size                   = size_struct();
				this->behaviour              = &signed_character_behaviour;
			}

			/// \brief Constructor for unsigned char value.
			///
			///	\param _value to wrap.
			var(unsigned char const _value) noexcept
			{
				this->value.unsigned_char_type = _value;
				this->size                     = size_struct();
				this->behaviour                = &unsigned_character_behaviour;
			}

#ifndef LIBLETLIB_FREESTANDING

			/// \brief Constructor for wchar_t value.
			///
			///	\param _value to wrap.
			var(wchar_t const _value) noexcept
			{
				this->value.wchar_type = _value;
				this->size             = size_struct();
				this->behaviour        = &wide_character_behaviour;
			}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			/// \brief Constructor for char8_t value.
			///
			///	\param _value to wrap.
			var(char8_t const _value) noexcept
			{
				this->value.char8_type = _value;
				this->size             = size_struct(sizeof(char8_t));
				this->behaviour        = &bit8_character_behaviour;
			}
		#endif
			/// \brief Constructor for char16_t value.
			///
			///	\param _value to wrap.
			var(char16_t const _value) noexcept
			{
				this->value.char16_type = _value;
				this->size              = size_struct(sizeof(char16_t));
				this->behaviour         = &bit16_character_behaviour;
			}

			/// \brief Constructor for char32_t value.
			///
			///	\param _value to wrap.
			var(char32_t const _value) noexcept
			{
				this->value.char32_type = _value;
				this->size              = size_struct(sizeof(char32_t));
				this->behaviour         = &bit32_character_behaviour;
			}

	#endif
#endif

			/// \brief Constructor for short value.
			///
			///	\param _value to wrap.
			var(short const _value) noexcept
			{
				this->value.short_type = _value;
				this->size             = size_struct();
				this->behaviour        = &short_behaviour;
			}

			/// \brief Constructor for unsigned short value.
			///
			///	\param _value to wrap.
			var(unsigned short const _value) noexcept
			{
				this->value.unsigned_short_type = _value;
				this->size                      = size_struct();
				this->behaviour                 = &unsigned_short_behaviour;
			}

			/// \brief Constructor for int value.
			///
			///	\param _value to wrap.
			var(int const _value) noexcept
			{
				this->value.int_type = _value;
				this->size           = size_struct();
				this->behaviour      = &integer_behaviour;
			}

			/// \brief Constructor for unsigned int value.
			///
			///	\param _value to wrap.
			var(unsigned const _value) noexcept
			{
				this->value.unsigned_int_type = _value;
				this->size                    = size_struct();
				this->behaviour               = &unsigned_integer_behaviour;
			}

			/// \brief Constructor for long value.
			///
			///	\param _value to wrap.
			var(long const _value) noexcept
			{
				this->value.long_type = _value;
				this->size            = size_struct();
				this->behaviour       = &long_behaviour;
			}

			/// \brief Constructor for unsigned long value.
			///
			///	\param _value to wrap.
			var(unsigned long const _value) noexcept
			{
				this->value.unsigned_long_type = _value;
				this->size                     = size_struct();
				this->behaviour                = &unsigned_long_behaviour;
			}

#if (__cplusplus >= 201103L)

			/// \brief Constructor for long long value.
			///
			///	\param _value to wrap.
			var(long long const _value) noexcept
			{
				this->value.long_long_type = _value;
				this->size                 = size_struct();
				this->behaviour            = &long_long_behaviour;
			}

			/// \brief Constructor for unsigned long long value.
			///
			///	\param _value to wrap.
			var(unsigned long long const _value) noexcept
			{
				this->value.unsigned_long_long_type = _value;
				this->size                          = size_struct();
				this->behaviour                     = &unsigned_long_long_behaviour;
			}

#endif

			/// \brief Constructor for float value.
			///
			///	\param _value to wrap.
			var(float const _value) noexcept
			{
				this->value.float_type = _value;
				this->size             = size_struct();
				this->behaviour        = &float_behaviour;
			}

			/// \brief Constructor for double value.
			///
			///	\param _value to wrap.
			var(double const _value) noexcept
			{
				this->value.double_type = _value;
				this->size              = size_struct();
				this->behaviour         = &double_behaviour;
			}

			/// \brief Constructor for long double value.
			///
			///	\param _value to wrap.
			var(long double const _value) noexcept
			{
				this->value.long_double_type = _value;
				this->size                   = size_struct();
				this->behaviour              = &long_double_behaviour;
			}

#ifndef LIBLETLIB_FREESTANDING

			/// \brief Constructor for raw string value.
			///
			///	\param _value to wrap.
			var(char const* const _value) noexcept
			{
				this->value              = value_union(_value);
				std::size_t const length = string_length(_value);
				this->size               = size_struct(length, length + 1);
				this->behaviour          = &string_behaviour;
			}

			/// \brief Constructor for wide string value.
			///
			///	\param _value to wrap.
			var(wchar_t const* const _value) noexcept
			{
				this->value              = value_union(_value);
				std::size_t const length = string_length(_value) * sizeof(wchar_t);
				this->size               = size_struct(length, length + sizeof(wchar_t));
				this->behaviour          = &wide_string_behaviour;
			}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			/// \brief Constructor for 8 bit string value.
			///
			///	\param _value to wrap.
			var(char8_t const* const _value) noexcept
			{
				this->value              = value_union(_value);
				std::size_t const length = string_length(_value) * sizeof(char8_t);
				this->size               = size_struct(length, length + sizeof(char8_t));
				this->behaviour          = &bit8_string_behaviour;
			}
		#endif
			/// \brief Constructor for 16 bit string value.
			///
			///	\param _value to wrap.
			var(char16_t const* const _value) noexcept
			{
				this->value              = value_union(_value);
				std::size_t const length = string_length(_value) * sizeof(char16_t);
				this->size               = size_struct(length, length + sizeof(char16_t));
				this->behaviour          = &bit16_string_behaviour;
			}

			/// \brief Constructor for 32 bit string value.
			///
			///	\param _value to wrap.
			var(char32_t const* const _value) noexcept
			{
				this->value              = value_union(_value);
				std::size_t const length = string_length(_value) * sizeof(char32_t);
				this->size               = size_struct(length, length + sizeof(char32_t));
				this->behaviour          = &bit32_string_behaviour;
			}

	#endif

			/// \brief Constructor used when concatenation of raw strings happens.
			///
			///	\param _left hand side string
			///	\param _right right hand side string
			///	\param _left_length of the left hand side string
			///	\param _right_length of the right hand side string
			var(char const* const _left, char const* const _right, std::size_t const _left_length,
			    std::size_t const _right_length) noexcept
			{
				this->value = value_union(_left, _left_length, _right_length + 1ul);
				static_cast<void>(string_concatenate(this->value.string_type, _right, _right_length));
				this->size      = size_struct(_left_length + _right_length + 1ul);
				this->behaviour = &string_behaviour;
			}

			/// \brief Constructor used when concatenation of wide strings happens.
			///
			///	\param _left hand side string
			///	\param _right hand side string
			///	\param _left_length of the left hand side string
			///	\param _right_length of the right hand side string
			var(wchar_t const* const _left, wchar_t const* const _right, std::size_t const _left_length,
			    std::size_t const _right_length) noexcept
			{
				this->value = value_union(_left, _left_length, (_right_length + 1ul) * sizeof(wchar_t));
				static_cast<void>(string_concatenate(this->value.wide_string_type, _right, _right_length));
				this->size      = size_struct((_left_length + _right_length + 1ul) * sizeof(wchar_t));
				this->behaviour = &wide_string_behaviour;
			}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			/// \brief Constructor used when concatenation of 8 bit strings happens.
			///
			///	\param _left hand side string
			///	\param _right hand side string
			///	\param _left_length of the left hand side string
			///	\param _right_length of the right hand side string
			var(char8_t const* const _left, char8_t const* const _right, std::size_t const _left_length,
			    std::size_t const _right_length) noexcept
			{
				this->value = value_union(_left, _left_length, (_right_length + 1ul) * sizeof(char8_t));
				static_cast<void>(string_concatenate(this->value.bit8_string_type, _right, _right_length));
				this->size      = size_struct((_left_length + _right_length + 1ul) * sizeof(char8_t));
				this->behaviour = &bit8_string_behaviour;
			}
		#endif

			/// \brief Constructor used when concatenation of 16 bit strings happens.
			///
			///	\param _left hand side string
			///	\param _right hand side string
			///	\param _left_length of the left hand side string
			///	\param _right_length of the right hand side string
			var(char16_t const* const _left, char16_t const* const _right, std::size_t const _left_length,
			    std::size_t const _right_length) noexcept
			{
				this->value = value_union(_left, _left_length, (_right_length + 1ul) * sizeof(char16_t));
				static_cast<void>(string_concatenate(this->value.bit16_string_type, _right, _right_length));
				this->size      = size_struct((_left_length + _right_length + 1ul) * sizeof(char16_t));
				this->behaviour = &bit16_string_behaviour;
			}

			/// \brief Constructor used when concatenation of 32 bit strings happens.
			///
			///	\param _left left hand side string
			///	\param _right right hand side string
			///	\param _left_length of the left hand side string
			///	\param _right_length of the right hand side string
			var(char32_t const* const _left, char32_t const* const _right, std::size_t const _left_length,
			    std::size_t const _right_length) noexcept
			{
				this->value = value_union(_left, _left_length, (_right_length + 1ul) * sizeof(char32_t));
				static_cast<void>(string_concatenate(this->value.bit32_string_type, _right, _right_length));
				this->size      = size_struct((_left_length + _right_length + 1ul) * sizeof(char32_t));
				this->behaviour = &bit32_string_behaviour;
			}

	#endif

			/// \brief Constructor for raw string value.
			///
			///	\param _array to wrap.
			///	\param _size of elements in array.
			var(var* _array, struct size_struct const _size) noexcept
			{
				this->size = _size;
				if (this->size.allocated == 0)
				{
					this->size.allocated   = LIBLETLIB_ARRAY_GROWTH;
					this->value.array_type = allocate<var>(LIBLETLIB_ARRAY_GROWTH);
				}
				else
				{
					this->value.array_type = _array;
				}
				this->behaviour = &array_behaviour;
			}

			/// \brief Constructor for raw string value.
			///
			///	\param _array to wrap.
			///	\param _in_use of elements in array.
			///	\param _allocated memory in array.
			var(var* const _array, std::size_t _in_use, std::size_t _allocated) noexcept
			{
				this->size             = size_struct(_in_use, _allocated);
				this->value.array_type = _array;
				this->behaviour        = &array_behaviour;
			}

	#if (__cplusplus >= 201103L)

			/// \brief List initialise a list of var.
			/// \param _list to initialise from.
			var(std::initializer_list<var> _list) noexcept
			{
				size_struct new_size = size_struct(_list.size());
				if (new_size.allocated == 0)
				{
					new_size.allocated     = LIBLETLIB_ARRAY_GROWTH;
					this->value.array_type = allocate<var>(LIBLETLIB_ARRAY_GROWTH);
				}
				else
				{
					this->value = value_union(_list);
				}
				this->size      = new_size;
				this->behaviour = &array_behaviour;
			}

	#endif

#endif

			/// \brief Constructor for void pointer value.
			///
			///	\param _value to wrap.
			var(void* _value) noexcept
			{
				this->size                    = size_struct();
				this->value.void_pointer_type = _value;
				this->behaviour               = &pointer_behaviour;
			}

#ifndef LIBLETLIB_FREESTANDING

			/// \brief Constructor for subroutine type.
			///
			/// \param _value to wrap.
			var(subroutine_t _value) noexcept
			{
				this->size                  = size_struct();
				this->value.subroutine_type = _value;
				this->behaviour             = &subroutine_behaviour;
			}

			/// \brief Constructor for function type.
			///
			/// \param _value to wrap.
			var(function_t _value) noexcept
			{
				this->size                = size_struct();
				this->value.function_type = _value;
				this->behaviour           = &function_behaviour;
			}

			/// \brief Constructor for subroutine type.
			///
			/// \param _value to wrap.
			var(subroutine_t _value, std::size_t _curry) noexcept
			{
				this->size                  = size_struct(_curry);
				this->value.subroutine_type = _value;
				this->behaviour             = &subroutine_behaviour;
			}

			/// \brief Constructor for function type.
			///
			/// \param _value to wrap.
			var(function_t _value, std::size_t _curry) noexcept
			{
				this->size                = size_struct(_curry);
				this->value.function_type = _value;
				this->behaviour           = &function_behaviour;
			}

#endif

#if (__cplusplus >= 201103L)

			/// \brief Constructor for nullptr_t value.
			///
			///	\param _value to wrap.
			var(std::nullptr_t const _value) noexcept
			{
				this->size               = size_struct();
				this->value.nullptr_type = _value;
				this->behaviour          = &null_behaviour;
			}

#endif

			/// \brief Copy constructor.
			///
			///	\param _other object to copy from.
			var(var const& _other) noexcept;

#if (__cplusplus >= 201103L)

			/// \brief Move constructor.
			///
			///	\param _other object to move from.
			var(var&& _other) noexcept
			{
				this->behaviour->deallocate(*this);
				value           = _other.value;
				_other.value    = value_union();
				this->size      = _other.size;
				this->behaviour = _other.behaviour;
			}

#endif

			/// \brief Destructor
			///
			///
			~var() noexcept
			{
				this->behaviour->deallocate(*this);
			}

			/// \brief Conversion function to bool.
			///
			///
			operator bool() const noexcept
			{
				return this->behaviour->as_boolean(*this);
			}

			/// \brief Conversion function to char.
			///
			///
			operator char() const noexcept
			{
				return this->behaviour->as_character(*this);
			}

			/// \brief Conversion function to signed char.
			///
			///
			operator signed char() const noexcept
			{
				return this->behaviour->as_signed_character(*this);
			}

			/// \brief Conversion function to unsigned char.
			///
			///
			operator unsigned char() const noexcept
			{
				return this->behaviour->as_unsigned_character(*this);
			}

#ifndef LIBLETLIB_FREESTANDING

			/// \brief Conversion function to wchar_t.
			///
			///
			operator wchar_t() const noexcept
			{
				return this->behaviour->as_wide_character(*this);
			}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			/// \brief Conversion function to char8_t.
			///
			///
			operator char8_t() const noexcept
			{
				return this->behaviour->as_bit8_character(*this);
			}
		#endif

			/// \brief Conversion function to char16_t.
			///
			///
			operator char16_t() const noexcept
			{
				return this->behaviour->as_bit16_character(*this);
			}

			/// \brief Conversion function to char32_t.
			///
			///
			operator char32_t() const noexcept
			{
				return this->behaviour->as_bit32_character(*this);
			}

	#endif
#endif

			/// \brief Conversion function to short.
			///
			///
			operator short() const noexcept
			{
				return this->behaviour->as_short(*this);
			}

			/// \brief Conversion function to unsigned short.
			///
			///
			operator unsigned short() const noexcept
			{
				return this->behaviour->as_unsigned_short(*this);
			}

			/// \brief Conversion function to int.
			///
			///
			operator int() const noexcept
			{
				return this->behaviour->as_integer(*this);
			}

			/// \brief Conversion function to unsigned int.
			///
			///
			operator unsigned() const noexcept
			{
				return this->behaviour->as_unsigned_integer(*this);
			}

			/// \brief Conversion function to long.
			///
			///
			operator long() const noexcept
			{
				return this->behaviour->as_long(*this);
			}

			/// \brief Conversion function to unsigned long.
			///
			///
			operator unsigned long() const noexcept
			{
				return this->behaviour->as_unsigned_long(*this);
			}

#if (__cplusplus >= 201103L)

			/// \brief Conversion function to long long.
			///
			///
			operator long long() const noexcept
			{
				return this->behaviour->as_long_long(*this);
			}

			/// \brief Conversion function to unsigned long long.
			///
			///
			operator unsigned long long() const noexcept
			{
				return this->behaviour->as_unsigned_long_long(*this);
			}

#endif

			/// \brief Conversion function to float.
			///
			///
			operator float() const noexcept
			{
				return this->behaviour->as_float(*this);
			}

			/// \brief Conversion function to double.
			///
			///
			operator double() const noexcept
			{
				return this->behaviour->as_double(*this);
			}

			/// \brief Conversion function to long double.
			///
			///
			operator long double() const noexcept
			{
				return this->behaviour->as_long_double(*this);
			}

#ifndef LIBLETLIB_FREESTANDING

			/// \brief Conversion function to raw string.
			///
			///
			operator std::string() const noexcept
			{
				char* const string    = this->behaviour->as_string(*this);
				std::string container = std::string(string);
				deallocate(string);
				return container;
			}

			/// \brief Conversion function to wide string.
			///
			///
			operator std::wstring() const noexcept
			{
				wchar_t* const string  = this->behaviour->as_wide_string(*this);
				std::wstring container = std::wstring(string);
				deallocate(string);
				return container;
			}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			/// \brief Conversion function to char8_t string.
			///
			///
			operator std::u8string() const noexcept
			{
				char8_t* const string   = this->behaviour->as_bit8_string(*this);
				std::u8string container = std::u8string(string);
				deallocate(string);
				return container;
			}
		#endif

			/// \brief Conversion function to char16_t string.
			///
			///
			operator std::u16string() const noexcept
			{
				char16_t* const string   = this->behaviour->as_bit16_string(*this);
				std::u16string container = std::u16string(string);
				deallocate(string);
				return container;
			}

			/// \brief Conversion function to char32_t string.
			///
			///
			operator std::u32string() const noexcept
			{
				char32_t* const string   = this->behaviour->as_bit32_string(*this);
				std::u32string container = std::u32string(string);
				deallocate(string);
				return container;
			}

	#endif
#endif

			/// \brief Conversion function to void pointer.
			///
			///
			operator void*() const noexcept
			{
				return this->behaviour->as_pointer(*this);
			}

#if (__cplusplus >= 201103L)

			/// \brief Conversion function to nullptr_t.
			///
			///
			operator std::nullptr_t() const noexcept
			{
				return this->behaviour->as_null(*this);
			}

#endif

			/// \brief Copy assignment operator for everything else than let/var.
			///
			/// \param _type value to be wrapped.
			/// \return self.
			template<typename Type>
			var& operator=(Type _type) noexcept
			{
				return *this = var(_type);
			}

			/// \brief Copy assignment operator let/var.
			///
			/// \param _other object to assign.
			/// \return self.
			var& operator=(var const& _other) noexcept;

#if (__cplusplus >= 201103L)

			/// \brief Move assignment operator.
			///
			/// \param _other object to assign.
			/// \return self.
			var& operator=(var&& _other) noexcept
			{
				if (this != address_of(_other))
				{
					this->behaviour->deallocate(*this);
					this->value     = _other.value;
					_other.value    = value_union();
					this->size      = _other.size;
					this->behaviour = _other.behaviour;
				}
				return *this;
			}

#endif
#ifndef LIBLETLIB_FREESTANDING
			/// \brief Append to list.
			/// \param _right item to append to list.
			/// \return this with _right appended.
			template<typename Type>
			var operator<<(Type const& _right) const noexcept
			{
				return *this << var(_right);
			}

			/// \brief Append to list.
			/// \param _right item to append to list.
			/// \return this with _right appended.
			var operator<<(var const& _right) const noexcept
			{
				if (this->behaviour->rank == enum_array_type)
				{
					if (_right.behaviour->rank == enum_array_type)
					{
						std::size_t other_real_size = _right.size.allocated == 0 ? 1 : _right.size.in_use;
						size_struct const _size     = size_struct(this->size.in_use + other_real_size);
						var* array                  = allocate<var>(_size.allocated);
						std::size_t index           = 0;
						for (std::size_t jindex = 0; jindex < this->size.in_use; ++index, ++jindex)
						{
							array[index] = this->value.array_type[jindex];
						}
						for (std::size_t jindex = 0; jindex < _right.size.in_use; ++index, ++jindex)
						{
							array[index] = _right[jindex];
						}
						return var(array, _size);
					}
					return *this + _right;
				}
				else
				{
					return *this + _right;
				}
			}
#endif

			/// \brief Sum assignment operator.
			///
			/// \param _right object to sum with this.
			/// \return previous new object holding the sum.
			var& operator+=(var const& _right) LIBLETLIB_NOEXCEPT
			{
				return *this = select_operation_var(this, sum, _right);
			}

			/// \brief Sum assignment operator.
			///
			/// \param _right type to sum with this.
			/// \return previous new object holding the sum.
			template<typename Type>
			var& operator+=(Type _right) LIBLETLIB_NOEXCEPT
			{
				return *this += var(_right);
			}

			/// \brief Sum operator.
			///
			/// \param _left hand side of sum.
			/// \param _right hand side of sum.
			/// \return previous new object holding the sum.
			template<typename Type>
			friend var operator+(var const& _left, Type _right) LIBLETLIB_NOEXCEPT
			{
				return _left + var(_right);
			}

			/// \brief Sum operator.
			///
			/// \param _left hand side of sum.
			/// \param _right hand side of sum.
			/// \return previous new object holding the sum.
			template<typename Type>
			friend var operator+(Type _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return var(_left) + _right;
			}

			/// \brief Sum operator.
			///
			/// \param _left hand side of sum.
			/// \param _right hand side of sum.
			/// \return previous new object holding the sum.
			friend var operator+(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return select_operation_let(_left, sum, _right);
			}

			/// \brief Subtraction assignment operator.
			///
			/// \param _right object to subtract from this.
			/// \return previous new object holding the difference.
			var& operator-=(var const& _right) LIBLETLIB_NOEXCEPT
			{
				return *this = select_operation_var(this, subtraction, _right);
			}

			/// \brief Subtraction assignment operator.
			///
			/// \param _right type to subtract from this.
			/// \return previous new object holding the difference.
			template<typename Type>
			var& operator-=(Type _right) LIBLETLIB_NOEXCEPT
			{
				return *this -= var(_right);
			}

			/// \brief Subtraction operator.
			///
			/// \param _left hand side of subtraction.
			/// \param _right hand side of subtraction.
			/// \return previous new object holding the difference.
			template<typename Type>
			friend var operator-(var const& _left, Type _right) LIBLETLIB_NOEXCEPT
			{
				return _left - var(_right);
			}

			/// \brief Subtraction operator.
			///
			/// \param _left hand side of subtraction.
			/// \param _right hand side of subtraction.
			/// \return previous new object holding the difference.
			template<typename Type>
			friend var operator-(Type _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return var(_left) - _right;
			}

			/// \brief Subtraction operator.
			///
			/// \param _left hand side of subtraction.
			/// \param _right hand side of subtraction.
			/// \return previous new object holding the difference.
			friend var operator-(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return select_operation_let(_left, subtraction, _right);
			}

			/// \brief Multiplication assignment operator.
			///
			/// \param _right object to multiply with this.
			/// \return previous new object holding the result.
			var& operator*=(var const& _right) LIBLETLIB_NOEXCEPT
			{
				return *this = select_operation_var(this, multiplication, _right);
			}

			/// \brief Multiplication assignment operator.
			///
			/// \param _right type to multiply with this.
			/// \return previous new object holding the result.
			template<typename Type>
			var& operator*=(Type const& _right) LIBLETLIB_NOEXCEPT
			{
				return *this *= var(_right);
			}

			/// \brief Multiplication operator.
			///
			/// \param _left hand side of multiplication.
			/// \param _right hand side of multiplication.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator*(var const& _left, Type _right) LIBLETLIB_NOEXCEPT
			{
				return _left * var(_right);
			}

			/// \brief Multiplication operator.
			///
			/// \param _left hand side of multiplication.
			/// \param _right hand side of multiplication.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator*(Type _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return var(_left) * _right;
			}

			/// \brief Multiplication operator.
			///
			/// \param _left hand side of multiplication.
			/// \param _right hand side of multiplication.
			/// \return previous new object holding the result.
			friend var operator*(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return select_operation_let(_left, multiplication, _right);
			}

			/// \brief Division assignment operator.
			///
			/// \param _right object to divide this with.
			/// \return previous new object holding the result.
			var& operator/=(var const& _right) LIBLETLIB_NOEXCEPT
			{
				return *this = select_operation_var(this, division, _right);
			}

			/// \brief Division assignment operator.
			///
			/// \param _right object to divide this with.
			/// \return previous new object holding the result.
			template<typename Type>
			var& operator/=(Type _right) LIBLETLIB_NOEXCEPT
			{
				return *this /= var(_right);
			}

			/// \brief Division operator.
			///
			/// \param _left hand side of division.
			/// \param _right hand side of division.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator/(var const& _left, Type _right) LIBLETLIB_NOEXCEPT
			{
				return _left / var(_right);
			}

			/// \brief Division operator.
			///
			/// \param _left hand side of division.
			/// \param _right hand side of division.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator/(Type _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return var(_left) / _right;
			}

			/// \brief Division operator.
			///
			/// \param _left hand side of division.
			/// \param _right hand side of division.
			/// \return previous new object holding the result.
			friend var operator/(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return select_operation_let(_left, division, _right);
			}

			/// \brief Exponentation assignment operator.
			///
			/// \param _right object to act as exponent of this.
			/// \return previous new object holding the result.
			var& operator^=(var const& _right) LIBLETLIB_NOEXCEPT
			{
				return *this = select_operation_var(this, exponentiation, _right);
			}

			/// \brief Exponentation assignment operator.
			///
			/// \param _right object to act as exponent of this.
			/// \return previous new object holding the result.
			template<typename Type>
			var& operator^=(Type _right) LIBLETLIB_NOEXCEPT
			{
				return *this ^= var(_right);
			}

			/// \brief Exponentation operator.
			///
			/// \param _left base of the exponentation.
			/// \param _right exponent of the exponentation.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator^(var const& _left, Type _right) LIBLETLIB_NOEXCEPT
			{
				return _left ^ var(_right);
			}

			/// \brief Exponentation operator.
			///
			/// \param _left base of the exponentation.
			/// \param _right exponent of the exponentation.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator^(Type _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return var(_left) ^ _right;
			}

			/// \brief Exponentation operator.
			///
			/// \param _left base of the exponentation.
			/// \param _right exponent of the exponentation.
			/// \return previous new object holding the result.
			friend var operator^(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return select_operation_let(_left, exponentiation, _right);
			}

			/// \brief Modulo assignment operator.
			///
			/// \param _right object to act as modulus.
			/// \return previous new object holding the result.
			var& operator%=(var const& _right) LIBLETLIB_NOEXCEPT
			{
				return *this = select_operation_var(this, modulo, _right);
			}

			/// \brief Modulo assignment operator.
			///
			/// \param _right object to act as modulus.
			/// \return previous new object holding the result.
			template<typename Type>
			var& operator%=(Type _right) LIBLETLIB_NOEXCEPT
			{
				return *this %= var(_right);
			}

			/// \brief Modulo operator.
			///
			/// \param _left dividend of the modulo.
			/// \param _right modulus of the modulo.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator%(var const& _left, Type _right) LIBLETLIB_NOEXCEPT
			{
				return _left % var(_right);
			}

			/// \brief Modulo operator.
			///
			/// \param _left dividend of the modulo.
			/// \param _right modulus of the modulo.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator%(Type _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return var(_left) % _right;
			}

			/// \brief Modulo operator.
			///
			/// \param _left dividend of the modulo.
			/// \param _right modulus of the modulo.
			/// \return previous new object holding the result.
			friend var operator%(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return select_operation_let(_left, modulo, _right);
			}

			/// \brief Binary and assignment operator.
			///
			/// \param _right object to take binary and of.
			/// \return previous new object holding the result.
			var& operator&=(var const& _right) LIBLETLIB_NOEXCEPT
			{
				return *this = select_operation_var(this, binary_and, _right);
			}

			/// \brief Binary and assignment operator.
			///
			/// \param _right object to take binary and of.
			/// \return previous new object holding the result.
			template<typename Type>
			var& operator&=(Type _right) LIBLETLIB_NOEXCEPT
			{
				return *this &= var(_right);
			}

			/// \brief Binary and operator.
			///
			/// \param _left hand side of the binary and.
			/// \param _right hand side of the binary and.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator&(var const& _left, Type _right) LIBLETLIB_NOEXCEPT
			{
				return _left & var(_right);
			}

			/// \brief Binary and operator.
			///
			/// \param _left hand side of the binary and.
			/// \param _right hand side of the binary and.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator&(Type _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return var(_left) & _right;
			}

			/// \brief Binary and operator.
			///
			/// \param _left hand side of the binary and.
			/// \param _right hand side of the binary and.
			/// \return previous new object holding the result.
			friend var operator&(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return select_operation_let(_left, binary_and, _right);
			}

			/// \brief Binary or assignment operator.
			///
			/// \param _right object to take binary or of.
			/// \return previous new object holding the result.
			var& operator|=(var const& _right) LIBLETLIB_NOEXCEPT
			{
				return *this = select_operation_var(this, binary_or, _right);
			}

			/// \brief Binary or assignment operator.
			///
			/// \param _right object to take binary or of.
			/// \return previous new object holding the result.
			template<typename Type>
			var& operator|=(Type _right) LIBLETLIB_NOEXCEPT
			{
				return *this |= var(_right);
			}

			/// \brief Binary or operator.
			///
			/// \param _left hand side of the binary or.
			/// \param _right hand side of the binary or.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator|(var const& _left, Type _right) LIBLETLIB_NOEXCEPT
			{
				return _left | var(_right);
			}

			/// \brief Binary or operator.
			///
			/// \param _left hand side of the binary or.
			/// \param _right hand side of the binary or.
			/// \return previous new object holding the result.
			template<typename Type>
			friend var operator|(Type _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return var(_left) | _right;
			}

			/// \brief Binary or operator.
			///
			/// \param _left hand side of the binary or.
			/// \param _right hand side of the binary or.
			/// \return previous new object holding the result.
			friend var operator|(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
			{
				return select_operation_let(_left, binary_or, _right);
			}

			/// \brief Binary xor assignment operator.
			///
			/// \param _right object to take binary xor of.
			/// \return previous new object holding the result.
			var bit_xor(var const& _right) const LIBLETLIB_NOEXCEPT
			{
				return select_operation_var(this, binary_xor, _right);
			}

			/// \brief Equals operator.
			///
			/// \param _left hand side of the equality.
			/// \param _right hand side of the equality.
			/// \return equality result as bool.
			friend bool operator==(var const& _left, var const& _right) noexcept
			{
				return backing::rank_compare(_left, _right) == 0;
			}

			/// \brief Not equals operator.
			///
			/// \param _left hand side of the non-equality.
			/// \param _right hand side of the non-equality.
			/// \return non-equality result as bool.
			friend bool operator!=(var const& _left, var const& _right) noexcept
			{
				return backing::rank_compare(_left, _right) != 0;
			}

			/// \brief Less than operator.
			///
			/// \param _left hand side of the less than operation.
			/// \param _right hand side of the less than operation.
			/// \return less than operation result as bool.
			friend bool operator<(var const& _left, var const& _right) noexcept
			{
				return backing::rank_compare(_left, _right) < 0;
			}

			/// \brief Greater than operator.
			///
			/// \param _left hand side of the greater than operation.
			/// \param _right hand side of the greater than operation.
			/// \return greater than operation result as bool.
			friend bool operator>(var const& _left, var const& _right) noexcept
			{
				return backing::rank_compare(_left, _right) > 0;
			}

			/// \brief Less than or equals operator.
			///
			/// \param _left hand side of the less than or equals operation.
			/// \param _right hand side of the less or equals operation.
			/// \return less than or equals operation result as bool.
			friend bool operator<=(var const& _left, var const& _right) noexcept
			{
				return backing::rank_compare(_left, _right) <= 0;
			}

			/// \brief Greater than or equals operator.
			///
			/// \param _left hand side of the greater than or equals operation.
			/// \param _right hand side of the greater or equals operation.
			/// \return greater than or equals operation result as bool.
			friend bool operator>=(var const& _left, var const& _right) noexcept
			{
				return backing::rank_compare(_left, _right) >= 0;
			}

			/// \brief Equals operator.
			///
			/// \param _left hand side of the equality.
			/// \param _right hand side of the equality.
			/// \return equality result as bool.
			template<typename Type>
			friend bool operator==(Type const _left, var const& _right) noexcept
			{
				return backing::rank_compare(var(_left), _right) == 0;
			}

			/// \brief Not equals operator.
			///
			/// \param _left hand side of the non-equality.
			/// \param _right hand side of the non-equality.
			/// \return non-equality result as bool.
			template<typename Type>
			friend bool operator!=(Type const _left, var const& _right) noexcept
			{
				return backing::rank_compare(var(_left), _right) != 0;
			}

			/// \brief Less than operator.
			///
			/// \param _left hand side of the less than operation.
			/// \param _right hand side of the less than operation.
			/// \return less than operation result as bool.
			template<typename Type>
			friend bool operator<(Type const _left, var const& _right) noexcept
			{
				return backing::rank_compare(var(_left), _right) < 0;
			}

			/// \brief Greater than operator.
			///
			/// \param _left hand side of the greater than operation.
			/// \param _right hand side of the greater than operation.
			/// \return greater than operation result as bool.
			template<typename Type>
			friend bool operator>(Type const _left, var const& _right) noexcept
			{
				return backing::rank_compare(var(_left), _right) > 0;
			}

			/// \brief Less than or equals operator.
			///
			/// \param _left hand side of the less than or equals operation.
			/// \param _right hand side of the less or equals operation.
			/// \return less than or equals operation result as bool.
			template<typename Type>
			friend bool operator<=(Type const _left, var const& _right) noexcept
			{
				return backing::rank_compare(var(_left), _right) <= 0;
			}

			/// \brief Greater than or equals operator.
			///
			/// \param _left hand side of the greater than or equals operation.
			/// \param _right hand side of the greater or equals operation.
			/// \return greater than or equals operation result as bool.
			template<typename Type>
			friend bool operator>=(Type const _left, var const& _right) noexcept
			{
				return backing::rank_compare(var(_left), _right) >= 0;
			}

			/// \brief Equals operator.
			///
			/// \param _left hand side of the equality.
			/// \param _right hand side of the equality.
			/// \return equality result as bool.
			template<typename Type>
			friend bool operator==(var const& _left, Type const& _right) noexcept
			{
				return backing::rank_compare(_left, var(_right)) == 0;
			}

			/// \brief Not equals operator.
			///
			/// \param _left hand side of the non-equality.
			/// \param _right hand side of the non-equality.
			/// \return non-equality result as bool.
			template<typename Type>
			friend bool operator!=(var const& _left, Type const& _right) noexcept
			{
				return backing::rank_compare(_left, var(_right)) != 0;
			}

			/// \brief Less than operator.
			///
			/// \param _left hand side of the less than operation.
			/// \param _right hand side of the less than operation.
			/// \return less than operation result as bool.
			template<typename Type>
			friend bool operator<(var const& _left, Type const& _right) noexcept
			{
				return backing::rank_compare(_left, var(_right)) < 0;
			}

			/// \brief Greater than operator.
			///
			/// \param _left hand side of the greater than operation.
			/// \param _right hand side of the greater than operation.
			/// \return greater than operation result as bool.
			template<typename Type>
			friend bool operator>(var const& _left, Type const& _right) noexcept
			{
				return backing::rank_compare(_left, var(_right)) > 0;
			}

			/// \brief Less than or equals operator.
			///
			/// \param _left hand side of the less than or equals operation.
			/// \param _right hand side of the less or equals operation.
			/// \return less than or equals operation result as bool.
			template<typename Type>
			friend bool operator<=(var const& _left, Type const& _right) noexcept
			{
				return backing::rank_compare(_left, var(_right)) <= 0;
			}

			/// \brief Greater than or equals operator.
			///
			/// \param _left hand side of the greater than or equals operation.
			/// \param _right hand side of the greater or equals operation.
			/// \return greater than or equals operation result as bool.
			template<typename Type>
			friend bool operator>=(var const& _left, Type const& _right) noexcept
			{
				return backing::rank_compare(_left, var(_right)) >= 0;
			}

			/// \brief Negation operator.
			///
			/// \return New object holding the negated value of this.
			var operator-() const LIBLETLIB_NOEXCEPT
			{
				return this->behaviour->negative(*this);
			}

			/// \brief Positive operator.
			///
			/// \return New object holding the positive value of this.
			var operator+() const LIBLETLIB_NOEXCEPT
			{
				return this->behaviour->positive(*this);
			}

			/// \brief Complement operator.
			///
			/// \return New object holding the complement value of this.
			var operator~() const LIBLETLIB_NOEXCEPT
			{
				return this->behaviour->complement(*this);
			}

			/// \brief Negation operator.
			///
			/// \return New object holding the not value of this.
			var operator!() const noexcept
			{
				return this->behaviour->negation(*this);
			}

			/// \brief Prefix increment operator.
			///
			/// \return This with incremented value
			var& operator++() LIBLETLIB_NOEXCEPT
			{
				return *this = this->behaviour->increment(*this);
			}

			/// \brief Postfix increment operator.
			///
			/// \return Copy of this without incremented value
			var const operator++(int) LIBLETLIB_NOEXCEPT
			{
				var copy(*this);
				operator++();
				return copy;
			}

			/// \brief Prefix decrement operator.
			///
			/// \return This with decremented value
			var& operator--() LIBLETLIB_NOEXCEPT
			{
				return *this = this->behaviour->decrement(*this);
			}

			/// \brief Postfix decrement operator.
			///
			/// \return Copy of this without decremented value
			var const operator--(int) LIBLETLIB_NOEXCEPT
			{
				var copy(*this);
				operator--();
				return copy;
			}

			/// \brief Indirection operator.
			///
			/// \return Indirected value of this.
			var operator*() const LIBLETLIB_NOEXCEPT
			{
				return this->behaviour->indirection(*this);
			}


#ifndef LIBLETLIB_FREESTANDING

			/// \brief Index-of operator overload.
			/// \tparam Type of index.
			/// \param _index index.
			/// \return var containing the result based on the wrapped type of this and the _index.
			template<typename Type>
			var operator[](Type _index) const LIBLETLIB_NOEXCEPT
			{
				return this->behaviour->index(*this, _index);
			}

	#if (__cplusplus < 201103L)
			/// \brief Function call operator overload.
			/// \return var containing the result based on the wrapped type of this and the argument(s).
			var operator()() const LIBLETLIB_NOEXCEPT
			{
				var result = var();
				var in     = backing::list();
				switch (this->behaviour->rank)
				{
					case enum_function_type:
						result = this->value.function_type(*this, in);
						break;
					case enum_subroutine_type:
						this->value.subroutine_type(*this, in);
						break;
					default:
						result = *this;
						break;
				}
				return result;
			}

			/// \brief Function call operator overload. (No variadic templates in C++98)
			/// \tparam Argument1 first argument.
			/// \param argument1 first argument.
			/// \return var containing the result based on the wrapped type of this and the argument(s).
			template<typename Argument1>
			var operator()(Argument1 const& argument1) const noexcept
			{
				var result = var();
				var in     = backing::list(argument1);
				switch (this->behaviour->rank)
				{
					case enum_function_type:
						result = this->value.function_type(*this, in);
						break;
					case enum_subroutine_type:
						this->value.subroutine_type(*this, in);
						break;
					default:
						result = *this;
						break;
				}
				return result;
			}

			/// \brief Function call operator overload. (No variadic templates in C++98)
			/// \tparam Argument1 first argument.
			/// \tparam Argument2 second argument.
			/// \param argument1 first argument.
			/// \param argument2 second argument.
			/// \return var containing the result based on the wrapped type of this and the argument(s).
			template<typename Argument1, typename Argument2>
			var operator()(Argument1 const& argument1, Argument2 const& argument2) const noexcept
			{
				var result = var();
				var in     = backing::list(argument1, argument2);
				switch (this->behaviour->rank)
				{
					case enum_function_type:
						result = this->value.function_type(*this, in);
						break;
					case enum_subroutine_type:
						this->value.subroutine_type(*this, in);
						break;
					default:
						result = *this;
						break;
				}
				return result;
			}

			/// \brief Function call operator overload. (No variadic templates in C++98)
			/// \tparam Argument1 first argument.
			/// \tparam Argument2 second argument.
			/// \tparam Argument3 third argument.
			/// \param argument1 first argument.
			/// \param argument2 second argument.
			/// \param argument3 third argument.
			/// \return var containing the result based on the wrapped type of this and the argument(s).
			template<typename Argument1, typename Argument2, typename Argument3>
			var operator()(Argument1 const& argument1, Argument2 const& argument2,
			               Argument3 const& argument3) const noexcept
			{
				var result = var();
				var in     = backing::list(argument1, argument2, argument3);
				switch (this->behaviour->rank)
				{
					case enum_function_type:
						result = this->value.function_type(*this, in);
						break;
					case enum_subroutine_type:
						this->value.subroutine_type(*this, in);
						break;
					default:
						result = *this;
						break;
				}
				return result;
			}

			/// \brief Function call operator overload. (No variadic templates in C++98)
			/// \tparam Argument1 first argument.
			/// \tparam Argument2 second argument.
			/// \tparam Argument3 third argument.
			/// \tparam Argument4 fourth argument.
			/// \param argument1 first argument.
			/// \param argument2 second argument.
			/// \param argument3 third argument.
			/// \param argument4 fourth argument.
			/// \return var containing the result based on the wrapped type of this and the argument(s).
			template<typename Argument1, typename Argument2, typename Argument3, typename Argument4>
			var operator()(Argument1 const& argument1, Argument2 const& argument2, Argument3 const& argument3,
			               Argument4 const& argument4) const noexcept
			{
				var result = var();
				var in     = backing::list(argument1, argument2, argument3, argument4);
				switch (this->behaviour->rank)
				{
					case enum_function_type:
						result = this->value.function_type(*this, in);
						break;
					case enum_subroutine_type:
						this->value.subroutine_type(*this, in);
						break;
					default:
						result = *this;
						break;
				}
				return result;
			}

			/// \brief Function call operator overload. (No variadic templates in C++98)
			/// \tparam Argument1 first argument.
			/// \tparam Argument2 second argument.
			/// \tparam Argument3 third argument.
			/// \tparam Argument4 fourth argument.
			/// \tparam Argument5 fifth argument.
			/// \param argument1 first argument.
			/// \param argument2 second argument.
			/// \param argument3 third argument.
			/// \param argument4 fourth argument.
			/// \param argument5 fifth argument.
			/// \return var containing the result based on the wrapped type of this and the argument(s).
			template<typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5>
			var operator()(Argument1 const& argument1, Argument2 const& argument2, Argument3 const& argument3,
			               Argument4 const& argument4, Argument5 const& argument5) const noexcept
			{
				var result = var();
				var in     = backing::list(argument1, argument2, argument3, argument4, argument5);
				switch (this->behaviour->rank)
				{
					case enum_function_type:
						result = this->value.function_type(*this, in);
						break;
					case enum_subroutine_type:
						this->value.subroutine_type(*this, in);
						break;
					default:
						result = *this;
						break;
				}
				return result;
			}

			/// \brief Function call operator overload. (No variadic templates in C++98)
			/// \tparam Argument1 first argument.
			/// \tparam Argument2 second argument.
			/// \tparam Argument3 third argument.
			/// \tparam Argument4 fourth argument.
			/// \tparam Argument5 fifth argument.
			/// \tparam Argument6 sixth argument.
			/// \param argument1 first argument.
			/// \param argument2 second argument.
			/// \param argument3 third argument.
			/// \param argument4 fourth argument.
			/// \param argument5 fifth argument.
			/// \param argument6 sixth argument.
			/// \return var containing the result based on the wrapped type of this and the argument(s).
			template<typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5,
			         typename Argument6>
			var operator()(Argument1 const& argument1, Argument2 const& argument2, Argument3 const& argument3,
			               Argument4 const& argument4, Argument5 const& argument5,
			               Argument6 const& argument6) const noexcept
			{
				var result = var();
				var in     = backing::list(argument1, argument2, argument3, argument4, argument5, argument6);
				switch (this->behaviour->rank)
				{
					case enum_function_type:
						result = this->value.function_type(*this, in);
						break;
					case enum_subroutine_type:
						this->value.subroutine_type(*this, in);
						break;
					default:
						result = *this;
						break;
				}
				return result;
			}

			/// \brief Function call operator overload. (No variadic templates in C++98)
			/// \tparam Argument1 first argument.
			/// \tparam Argument2 second argument.
			/// \tparam Argument3 third argument.
			/// \tparam Argument4 fourth argument.
			/// \tparam Argument5 fifth argument.
			/// \tparam Argument6 sixth argument.
			/// \tparam Argument7 seventh argument.
			/// \param argument1 first argument.
			/// \param argument2 second argument.
			/// \param argument3 third argument.
			/// \param argument4 fourth argument.
			/// \param argument5 fifth argument.
			/// \param argument6 sixth argument.
			/// \param argument7 seventh argument.
			/// \return var containing the result based on the wrapped type of this and the argument(s).
			template<typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5,
			         typename Argument6, typename Argument7>
			var operator()(Argument1 const& argument1, Argument2 const& argument2, Argument3 const& argument3,
			               Argument4 const& argument4, Argument5 const& argument5, Argument6 const& argument6,
			               Argument7 const& argument7) const noexcept
			{
				var result = var();
				var in     = backing::list(argument1, argument2, argument3, argument4, argument5, argument6, argument7);
				switch (this->behaviour->rank)
				{
					case enum_function_type:
						result = this->value.function_type(*this, in);
						break;
					case enum_subroutine_type:
						this->value.subroutine_type(*this, in);
						break;
					default:
						result = *this;
						break;
				}
				return result;
			}

			/// \brief Function call operator overload. (No variadic templates in C++98)
			/// \tparam Argument1 first argument.
			/// \tparam Argument2 second argument.
			/// \tparam Argument3 third argument.
			/// \tparam Argument4 fourth argument.
			/// \tparam Argument5 fifth argument.
			/// \tparam Argument6 sixth argument.
			/// \tparam Argument7 seventh argument.
			/// \tparam Argument8 eight argument.
			/// \param argument1 first argument.
			/// \param argument2 second argument.
			/// \param argument3 third argument.
			/// \param argument4 fourth argument.
			/// \param argument5 fifth argument.
			/// \param argument6 sixth argument.
			/// \param argument7 seventh argument.
			/// \param argument8 eigth argument.
			/// \return var containing the result based on the wrapped type of this and the argument(s).
			template<typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5,
			         typename Argument6, typename Argument7, typename Argument8>
			var operator()(Argument1 const& argument1, Argument2 const& argument2, Argument3 const& argument3,
			               Argument4 const& argument4, Argument5 const& argument5, Argument6 const& argument6,
			               Argument7 const& argument7, Argument8 const& argument8) const noexcept
			{
				var result = var();
				var in     = backing::list(argument1, argument2, argument3, argument4, argument5, argument6, argument7,
                                       argument8);
				switch (this->behaviour->rank)
				{
					case enum_function_type:
						result = this->value.function_type(*this, in);
						break;
					case enum_subroutine_type:
						this->value.subroutine_type(*this, in);
						break;
					default:
						result = *this;
						break;
				}
				return result;
			}

			/// \brief Function call operator overload. (No variadic templates in C++98)
			/// \tparam Argument1 first argument.
			/// \tparam Argument2 second argument.
			/// \tparam Argument3 third argument.
			/// \tparam Argument4 fourth argument.
			/// \tparam Argument5 fifth argument.
			/// \tparam Argument6 sixth argument.
			/// \tparam Argument7 seventh argument.
			/// \tparam Argument8 eight argument.
			/// \tparam Argument9 ninth argument.
			/// \param argument1 first argument.
			/// \param argument2 second argument.
			/// \param argument3 third argument.
			/// \param argument4 fourth argument.
			/// \param argument5 fifth argument.
			/// \param argument6 sixth argument.
			/// \param argument7 seventh argument.
			/// \param argument8 eigth argument.
			/// \param argument9 ninth argument.
			/// \return var containing the result based on the wrapped type of this and the argument(s).
			template<typename Argument1, typename Argument2, typename Argument3, typename Argument4, typename Argument5,
			         typename Argument6, typename Argument7, typename Argument8, typename Argument9>
			var operator()(Argument1 const& argument1, Argument2 const& argument2, Argument3 const& argument3,
			               Argument4 const& argument4, Argument5 const& argument5, Argument6 const& argument6,
			               Argument7 const& argument7, Argument8 const& argument8,
			               Argument9 const& argument9) const noexcept
			{
				var result = var();
				var in     = backing::list(argument1, argument2, argument3, argument4, argument5, argument6, argument7,
                                       argument8, argument9);
				switch (this->behaviour->rank)
				{
					case enum_function_type:
						result = this->value.function_type(*this, in);
						break;
					case enum_subroutine_type:
						this->value.subroutine_type(*this, in);
						break;
					default:
						result = *this;
						break;
				}
				return result;
			}

	#else

			/// \brief Function call operator.
			/// \tparam Arguments to call function/subroutine with.
			/// \param arguments to call function/subroutine with.
			/// \return result of the call (nullptr for subroutines).
			template<typename... Arguments>
			var operator()(Arguments const&... arguments) const noexcept
			{
				var result = var();
				var in     = backing::list(arguments...);
				switch (this->behaviour->rank)
				{
					case enum_function_type:
						result = this->value.function_type(*this, in);
						break;
					case enum_subroutine_type:
						this->value.subroutine_type(*this, in);
						break;
					case enum_void_pointer_type: {
						var& overload = this->message("()");
						if (overload != EMPTY_VALUE)
						{
							result = overload(in);
						}
					}
					break;
					default:
						result = *this;
						break;
				}
				return result;
			}

		private:
			template<std::size_t... Indices>
			static var flatten_and_invoke(var const& _function, var const& _list,
			                              libletlib::detail::index_sequence<Indices...>) noexcept
			{
				return _function(_list[Indices]...);
			}

		public:
			/// \brief List-flattening function/subroutine call function.
			/// \tparam Amount of arguments to apply.
			/// \param argument or singular value to apply to function.
			/// \return result of the call (nullptr for subroutines).
			template<std::size_t Amount>
			inline var apply(var const& argument) const noexcept
			{
				if (argument.behaviour->rank == enum_array_type)
				{
					return flatten_and_invoke(*this, argument, make_index_sequence<Amount> {});
				}
				return operator()(argument);
			}

			/// \brief Return this var as a list, the contents may be atomised to smaller data units if the original value
			/// is composed of smaller units of data. e.g. strings.
			/// \return this var as a list.
			LIBLETLIB_NODISCARD inline var to_list() const noexcept
			{
				return this->behaviour->as_array(*this);
			}
	#endif

			/// \brief Reserve memory to a list ahead of time.
			/// \param amount to reserve.
			inline void reserve(std::size_t const amount) noexcept
			{
				if (this->behaviour->rank != enum_array_type)
					return;
				var* new_allocation = allocate<var>(amount);
				for (std::size_t index = 0; index < this->size.in_use; ++index)
					new_allocation[index] = this->value.array_type[index];
				delete[] this->value.array_type;
				this->value.array_type = new_allocation;
			}

			/// \brief Objectify current value (should be void pointer)
			/// \return Current value casted to MetaRoot*.
			LIBLETLIB_NODISCARD inline MetaRoot* objectify() const noexcept;

			/// \brief Objectify current value (should be void pointer)
			/// \return Current value casted to MetaRoot*.
			LIBLETLIB_NODISCARD inline MetaRoot* objectify() noexcept;

			template<typename String>
			var& message(String) noexcept;

			template<typename String>
			var& message(String) const noexcept;

			template<typename Low, typename High>
			LIBLETLIB_NODISCARD inline var slice(Low low, High const high) const LIBLETLIB_NOEXCEPT {
				if(low >= high)
					return nothing;
				var part;

				if(this->behaviour->rank == enum_array_type)
				{
					part = backing::list();
					for(; low < high; low++)
						part += this->operator[](low);
				}
				else if(this->behaviour->rank == enum_string_type) {
					part = "";
					for(; low < high; low++)
						part += this->operator[](low);
				} else if(this->behaviour->rank == enum_wide_string_type) {
					part = L"";
					for(; low < high; low++)
						part += this->operator[](low);
				}
			#if (__cplusplus >= 201103L)
				#ifndef LIBLETLIB_DISABLE_UCHAR
					#if (__cplusplus >= 202002L)
				else if(this->behaviour->rank == enum_bit8_string_type) {
					part = u8"";
					for(; low < high; low++)
						part += this->operator[](low);
				}
					#endif
				else if(this->behaviour->rank == enum_bit16_string_type) {
					part = u"";
					for(; low < high; low++)
						part += this->operator[](low);
				}
				else if(this->behaviour->rank == enum_bit32_string_type) {
					part = U"";
					for(; low < high; low++)
						part += this->operator[](low);
				}
				#endif
			#endif
				return part;
			}

			/// \brief Get possibly mutable reference to an element at an index.
			/// \tparam Index type.
			/// \param index of the element.
			/// \return reference to the element.
			template<typename Index>
			LIBLETLIB_NODISCARD inline var& at(Index const index) noexcept
			{
				if (this->behaviour->rank == enum_array_type)
					return this->value.array_type[index];
				return *this;
			}

			/// \brief Get immutable reference to an element at an index.
			/// \tparam Index type.
			/// \param index of the element.
			/// \return immutable reference to the element.
			template<typename Index>
			LIBLETLIB_NODISCARD inline var const& at(Index index) const noexcept
			{
				if (this->behaviour->rank == enum_array_type)
					return this->value.array_type[index];
				return *this;
			}

#endif

		private:
#if (__cplusplus >= 201103L)
			union value_union mutable value = value_union();///< Holds the fundamental type wrapped.
			struct size_struct mutable size = size_struct();///< Holds the size, multiple uses for different data types.
			type_behaviour const* behaviour = &null_behaviour;///< Holds the behaviour of the fundamental type wrapped.
#else
			union value_union mutable value;///< Holds the fundamental type wrapped.
			struct size_struct mutable size;///< Holds the size, multiple uses for different data types.
			type_behaviour const* behaviour;///< Holds the behaviour of the fundamental type wrapped.
#endif
		};

		namespace backing
		{
			/// \brief Compare ranks of vars and select the highest ranking comparison function to execute.
			/// \param _left var to compare.
			/// \param _right var to compare.
			/// \return Result of the highest ranking comparison function with _left and _right.
			LIBLETLIB_NODISCARD inline int rank_compare(var const& _left, var const& _right) noexcept
			{
				return (_left).behaviour->rank >= (_right).behaviour->rank
				           ? (_left).behaviour->comparison((_left), (_right))
				           : (_right).behaviour->comparison((_left), (_right));
			}
		}// namespace backing

	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_VAR_HPP
