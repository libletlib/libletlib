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

#ifndef LIBLETLIB_LIBLETLIB_BEHAVIOUR_HPP
#define LIBLETLIB_LIBLETLIB_BEHAVIOUR_HPP

#include "libletlib_forward_declarations.hpp"
#include "libletlib_rank_enum.hpp"

namespace libletlib
{
	namespace detail
	{

		bool boolean_as_boolean(var const&) noexcept;
		bool character_as_boolean(var const&) noexcept;
		bool signed_character_as_boolean(var const&) noexcept;
		bool unsigned_character_as_boolean(var const&) noexcept;
		bool wide_character_as_boolean(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		bool bit8_character_as_boolean(var const&) noexcept;
	#endif
		bool bit16_character_as_boolean(var const&) noexcept;
		bool bit32_character_as_boolean(var const&) noexcept;
#endif

		bool short_as_boolean(var const&) noexcept;
		bool unsigned_short_as_boolean(var const&) noexcept;
		bool integer_as_boolean(var const&) noexcept;
		bool unsigned_integer_as_boolean(var const&) noexcept;
		bool long_as_boolean(var const&) noexcept;
		bool unsigned_long_as_boolean(var const&) noexcept;

#if (__cplusplus >= 201103L)
		bool long_long_as_boolean(var const&) noexcept;
		bool unsigned_long_long_as_boolean(var const&) noexcept;
#endif

		bool float_as_boolean(var const&) noexcept;
		bool double_as_boolean(var const&) noexcept;
		bool long_double_as_boolean(var const&) noexcept;
		bool string_as_boolean(var const&) noexcept;
		bool wide_string_as_boolean(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		bool bit8_string_as_boolean(var const&) noexcept;
	#endif
		bool bit16_string_as_boolean(var const&) noexcept;
		bool bit32_string_as_boolean(var const&) noexcept;

#endif

		bool pointer_as_boolean(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		bool array_as_boolean(var const&) noexcept;
		bool subroutine_as_boolean(var const&) LIBLETLIB_NOEXCEPT;
		bool function_as_boolean(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		bool null_as_boolean(var const&) noexcept;

#endif

		char boolean_as_character(var const&) noexcept;
		char character_as_character(var const&) noexcept;
		char signed_character_as_character(var const&) noexcept;
		char unsigned_character_as_character(var const&) noexcept;
		char wide_character_as_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		char bit8_character_as_character(var const&) noexcept;
	#endif
		char bit16_character_as_character(var const&) noexcept;
		char bit32_character_as_character(var const&) noexcept;

#endif

		char short_as_character(var const&) noexcept;
		char unsigned_short_as_character(var const&) noexcept;
		char integer_as_character(var const&) noexcept;
		char unsigned_integer_as_character(var const&) noexcept;
		char long_as_character(var const&) noexcept;
		char unsigned_long_as_character(var const&) noexcept;

#if (__cplusplus >= 201103L)

		char long_long_as_character(var const&) noexcept;
		char unsigned_long_long_as_character(var const&) noexcept;

#endif

		char float_as_character(var const&) noexcept;
		char double_as_character(var const&) noexcept;
		char long_double_as_character(var const&) noexcept;
		char string_as_character(var const&) noexcept;
		char wide_string_as_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		char bit8_string_as_character(var const&) noexcept;
	#endif
		char bit16_string_as_character(var const&) noexcept;
		char bit32_string_as_character(var const&) noexcept;

#endif

		char pointer_as_character(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		char array_as_character(var const&) noexcept;
		char subroutine_as_character(var const&) LIBLETLIB_NOEXCEPT;
		char function_as_character(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		char null_as_character(var const&) noexcept;

#endif

		signed char boolean_as_signed_character(var const&) noexcept;
		signed char character_as_signed_character(var const&) noexcept;
		signed char signed_character_as_signed_character(var const&) noexcept;
		signed char unsigned_character_as_signed_character(var const&) noexcept;
		signed char wide_character_as_signed_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		signed char bit8_character_as_signed_character(var const&) noexcept;
	#endif
		signed char bit16_character_as_signed_character(var const&) noexcept;
		signed char bit32_character_as_signed_character(var const&) noexcept;

#endif

		signed char short_as_signed_character(var const&) noexcept;
		signed char unsigned_short_as_signed_character(var const&) noexcept;
		signed char integer_as_signed_character(var const&) noexcept;
		signed char unsigned_integer_as_signed_character(var const&) noexcept;
		signed char long_as_signed_character(var const&) noexcept;
		signed char unsigned_long_as_signed_character(var const&) noexcept;

#if (__cplusplus >= 201103L)

		signed char long_long_as_signed_character(var const&) noexcept;
		signed char unsigned_long_long_as_signed_character(var const&) noexcept;

#endif

		signed char float_as_signed_character(var const&) noexcept;
		signed char double_as_signed_character(var const&) noexcept;
		signed char long_double_as_signed_character(var const&) noexcept;
		signed char string_as_signed_character(var const&) noexcept;
		signed char wide_string_as_signed_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		signed char bit8_string_as_signed_character(var const&) noexcept;
	#endif
		signed char bit16_string_as_signed_character(var const&) noexcept;
		signed char bit32_string_as_signed_character(var const&) noexcept;

#endif

		signed char pointer_as_signed_character(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		signed char array_as_signed_character(var const&) noexcept;
		signed char subroutine_as_signed_character(var const&) LIBLETLIB_NOEXCEPT;
		signed char function_as_signed_character(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		signed char null_as_signed_character(var const&) noexcept;

#endif

		unsigned char boolean_as_unsigned_character(var const&) noexcept;
		unsigned char character_as_unsigned_character(var const&) noexcept;
		unsigned char signed_character_as_unsigned_character(var const&) noexcept;
		unsigned char unsigned_character_as_unsigned_character(var const&) noexcept;
		unsigned char wide_character_as_unsigned_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		unsigned char bit8_character_as_unsigned_character(var const&) noexcept;
	#endif
		unsigned char bit16_character_as_unsigned_character(var const&) noexcept;
		unsigned char bit32_character_as_unsigned_character(var const&) noexcept;

#endif

		unsigned char short_as_unsigned_character(var const&) noexcept;
		unsigned char unsigned_short_as_unsigned_character(var const&) noexcept;
		unsigned char integer_as_unsigned_character(var const&) noexcept;
		unsigned char unsigned_integer_as_unsigned_character(var const&) noexcept;
		unsigned char long_as_unsigned_character(var const&) noexcept;
		unsigned char unsigned_long_as_unsigned_character(var const&) noexcept;

#if (__cplusplus >= 201103L)

		unsigned char long_long_as_unsigned_character(var const&) noexcept;
		unsigned char unsigned_long_long_as_unsigned_character(var const&) noexcept;

#endif

		unsigned char float_as_unsigned_character(var const&) noexcept;
		unsigned char double_as_unsigned_character(var const&) noexcept;
		unsigned char long_double_as_unsigned_character(var const&) noexcept;
		unsigned char string_as_unsigned_character(var const&) noexcept;
		unsigned char wide_string_as_unsigned_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		unsigned char bit8_string_as_unsigned_character(var const&) noexcept;
	#endif
		unsigned char bit16_string_as_unsigned_character(var const&) noexcept;
		unsigned char bit32_string_as_unsigned_character(var const&) noexcept;

#endif

		unsigned char pointer_as_unsigned_character(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		unsigned char array_as_unsigned_character(var const&) noexcept;
		unsigned char subroutine_as_unsigned_character(var const&) LIBLETLIB_NOEXCEPT;
		unsigned char function_as_unsigned_character(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		unsigned char null_as_unsigned_character(var const&) noexcept;

#endif

		wchar_t boolean_as_wide_character(var const&) noexcept;
		wchar_t character_as_wide_character(var const&) noexcept;
		wchar_t signed_character_as_wide_character(var const&) noexcept;
		wchar_t unsigned_character_as_wide_character(var const&) noexcept;
		wchar_t wide_character_as_wide_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		wchar_t bit8_character_as_wide_character(var const&) noexcept;
	#endif
		wchar_t bit16_character_as_wide_character(var const&) noexcept;
		wchar_t bit32_character_as_wide_character(var const&) noexcept;

#endif

		wchar_t short_as_wide_character(var const&) noexcept;
		wchar_t unsigned_short_as_wide_character(var const&) noexcept;
		wchar_t integer_as_wide_character(var const&) noexcept;
		wchar_t unsigned_integer_as_wide_character(var const&) noexcept;
		wchar_t long_as_wide_character(var const&) noexcept;
		wchar_t unsigned_long_as_wide_character(var const&) noexcept;

#if (__cplusplus >= 201103L)

		wchar_t long_long_as_wide_character(var const&) noexcept;
		wchar_t unsigned_long_long_as_wide_character(var const&) noexcept;

#endif

		wchar_t float_as_wide_character(var const&) noexcept;
		wchar_t double_as_wide_character(var const&) noexcept;
		wchar_t long_double_as_wide_character(var const&) noexcept;
		wchar_t string_as_wide_character(var const&) noexcept;
		wchar_t wide_string_as_wide_character(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		wchar_t bit8_string_as_wide_character(var const&) noexcept;
	#endif
		wchar_t bit16_string_as_wide_character(var const&) noexcept;
		wchar_t bit32_string_as_wide_character(var const&) noexcept;

#endif

		wchar_t pointer_as_wide_character(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		wchar_t array_as_wide_character(var const&) noexcept;
		wchar_t subroutine_as_wide_character(var const&) LIBLETLIB_NOEXCEPT;
		wchar_t function_as_wide_character(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		wchar_t null_as_wide_character(var const&) noexcept;

#endif

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		char8_t boolean_as_bit8_character(var const&) noexcept;
		char8_t character_as_bit8_character(var const&) noexcept;
		char8_t signed_character_as_bit8_character(var const&) noexcept;
		char8_t unsigned_character_as_bit8_character(var const&) noexcept;
		char8_t wide_character_as_bit8_character(var const&) noexcept;
		char8_t bit8_character_as_bit8_character(var const&) noexcept;
		char8_t bit16_character_as_bit8_character(var const&) noexcept;
		char8_t bit32_character_as_bit8_character(var const&) noexcept;
		char8_t short_as_bit8_character(var const&) noexcept;
		char8_t unsigned_short_as_bit8_character(var const&) noexcept;
		char8_t integer_as_bit8_character(var const&) noexcept;
		char8_t unsigned_integer_as_bit8_character(var const&) noexcept;
		char8_t long_as_bit8_character(var const&) noexcept;
		char8_t unsigned_long_as_bit8_character(var const&) noexcept;
		char8_t long_long_as_bit8_character(var const&) noexcept;
		char8_t unsigned_long_long_as_bit8_character(var const&) noexcept;
		char8_t float_as_bit8_character(var const&) noexcept;
		char8_t double_as_bit8_character(var const&) noexcept;
		char8_t long_double_as_bit8_character(var const&) noexcept;
		char8_t string_as_bit8_character(var const&) noexcept;
		char8_t wide_string_as_bit8_character(var const&) noexcept;
		char8_t bit8_string_as_bit8_character(var const&) noexcept;
		char8_t bit16_string_as_bit8_character(var const&) noexcept;
		char8_t bit32_string_as_bit8_character(var const&) noexcept;
		char8_t pointer_as_bit8_character(var const&) noexcept;
		char8_t array_as_bit8_character(var const&) noexcept;
		char8_t subroutine_as_bit8_character(var const&) LIBLETLIB_NOEXCEPT;
		char8_t function_as_bit8_character(var const&) noexcept;
		char8_t null_as_bit8_character(var const&) noexcept;
	#endif

		char16_t boolean_as_bit16_character(var const&) noexcept;
		char16_t character_as_bit16_character(var const&) noexcept;
		char16_t signed_character_as_bit16_character(var const&) noexcept;
		char16_t unsigned_character_as_bit16_character(var const&) noexcept;
		char16_t wide_character_as_bit16_character(var const&) noexcept;
	#if (__cplusplus >= 202002L)
		char16_t bit8_character_as_bit16_character(var const&) noexcept;
	#endif
		char16_t bit16_character_as_bit16_character(var const&) noexcept;
		char16_t bit32_character_as_bit16_character(var const&) noexcept;
		char16_t short_as_bit16_character(var const&) noexcept;
		char16_t unsigned_short_as_bit16_character(var const&) noexcept;
		char16_t integer_as_bit16_character(var const&) noexcept;
		char16_t unsigned_integer_as_bit16_character(var const&) noexcept;
		char16_t long_as_bit16_character(var const&) noexcept;
		char16_t unsigned_long_as_bit16_character(var const&) noexcept;
		char16_t long_long_as_bit16_character(var const&) noexcept;
		char16_t unsigned_long_long_as_bit16_character(var const&) noexcept;
		char16_t float_as_bit16_character(var const&) noexcept;
		char16_t double_as_bit16_character(var const&) noexcept;
		char16_t long_double_as_bit16_character(var const&) noexcept;
		char16_t string_as_bit16_character(var const&) noexcept;
		char16_t wide_string_as_bit16_character(var const&) noexcept;
	#if (__cplusplus >= 202002L)
		char16_t bit8_string_as_bit16_character(var const&) noexcept;
	#endif
		char16_t bit16_string_as_bit16_character(var const&) noexcept;
		char16_t bit32_string_as_bit16_character(var const&) noexcept;
		char16_t pointer_as_bit16_character(var const&) noexcept;
		char16_t array_as_bit16_character(var const&) noexcept;
		char16_t subroutine_as_bit16_character(var const&) LIBLETLIB_NOEXCEPT;
		char16_t function_as_bit16_character(var const&) noexcept;
		char16_t null_as_bit16_character(var const&) noexcept;

		char32_t boolean_as_bit32_character(var const&) noexcept;
		char32_t character_as_bit32_character(var const&) noexcept;
		char32_t signed_character_as_bit32_character(var const&) noexcept;
		char32_t unsigned_character_as_bit32_character(var const&) noexcept;
		char32_t wide_character_as_bit32_character(var const&) noexcept;
	#if (__cplusplus >= 202002L)
		char32_t bit8_character_as_bit32_character(var const&) noexcept;
	#endif
		char32_t bit16_character_as_bit32_character(var const&) noexcept;
		char32_t bit32_character_as_bit32_character(var const&) noexcept;
		char32_t short_as_bit32_character(var const&) noexcept;
		char32_t unsigned_short_as_bit32_character(var const&) noexcept;
		char32_t integer_as_bit32_character(var const&) noexcept;
		char32_t unsigned_integer_as_bit32_character(var const&) noexcept;
		char32_t long_as_bit32_character(var const&) noexcept;
		char32_t unsigned_long_as_bit32_character(var const&) noexcept;
		char32_t long_long_as_bit32_character(var const&) noexcept;
		char32_t unsigned_long_long_as_bit32_character(var const&) noexcept;
		char32_t float_as_bit32_character(var const&) noexcept;
		char32_t double_as_bit32_character(var const&) noexcept;
		char32_t long_double_as_bit32_character(var const&) noexcept;
		char32_t string_as_bit32_character(var const&) noexcept;
		char32_t wide_string_as_bit32_character(var const&) noexcept;
	#if (__cplusplus >= 202002L)
		char32_t bit8_string_as_bit32_character(var const&) noexcept;
	#endif
		char32_t bit16_string_as_bit32_character(var const&) noexcept;
		char32_t bit32_string_as_bit32_character(var const&) noexcept;
		char32_t pointer_as_bit32_character(var const&) noexcept;
		char32_t array_as_bit32_character(var const&) noexcept;
		char32_t subroutine_as_bit32_character(var const&) LIBLETLIB_NOEXCEPT;
		char32_t function_as_bit32_character(var const&) noexcept;
		char32_t null_as_bit32_character(var const&) noexcept;

#endif

		short boolean_as_short(var const&) noexcept;
		short character_as_short(var const&) noexcept;
		short signed_character_as_short(var const&) noexcept;
		short unsigned_character_as_short(var const&) noexcept;
		short wide_character_as_short(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		short bit8_character_as_short(var const&) noexcept;
	#endif
		short bit16_character_as_short(var const&) noexcept;
		short bit32_character_as_short(var const&) noexcept;

#endif

		short short_as_short(var const&) noexcept;
		short unsigned_short_as_short(var const&) noexcept;
		short integer_as_short(var const&) noexcept;
		short unsigned_integer_as_short(var const&) noexcept;
		short long_as_short(var const&) noexcept;
		short unsigned_long_as_short(var const&) noexcept;

#if (__cplusplus >= 201103L)

		short long_long_as_short(var const&) noexcept;
		short unsigned_long_long_as_short(var const&) noexcept;

#endif

		short float_as_short(var const&) noexcept;
		short double_as_short(var const&) noexcept;
		short long_double_as_short(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		short string_as_short(var const&) noexcept;
		short wide_string_as_short(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		short bit8_string_as_short(var const&) noexcept;
		#endif
		short bit16_string_as_short(var const&) noexcept;
		short bit32_string_as_short(var const&) noexcept;

	#endif
#endif

		short pointer_as_short(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		short array_as_short(var const&) noexcept;
		short subroutine_as_short(var const&) LIBLETLIB_NOEXCEPT;
		short function_as_short(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		short null_as_short(var const&) noexcept;

#endif

		unsigned short boolean_as_unsigned_short(var const&) noexcept;
		unsigned short character_as_unsigned_short(var const&) noexcept;
		unsigned short signed_character_as_unsigned_short(var const&) noexcept;
		unsigned short unsigned_character_as_unsigned_short(var const&) noexcept;
		unsigned short wide_character_as_unsigned_short(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		unsigned short bit8_character_as_unsigned_short(var const&) noexcept;
	#endif
		unsigned short bit16_character_as_unsigned_short(var const&) noexcept;
		unsigned short bit32_character_as_unsigned_short(var const&) noexcept;

#endif

		unsigned short short_as_unsigned_short(var const&) noexcept;
		unsigned short unsigned_short_as_unsigned_short(var const&) noexcept;
		unsigned short integer_as_unsigned_short(var const&) noexcept;
		unsigned short unsigned_integer_as_unsigned_short(var const&) noexcept;
		unsigned short long_as_unsigned_short(var const&) noexcept;
		unsigned short unsigned_long_as_unsigned_short(var const&) noexcept;

#if (__cplusplus >= 201103L)

		unsigned short long_long_as_unsigned_short(var const&) noexcept;
		unsigned short unsigned_long_long_as_unsigned_short(var const&) noexcept;

#endif

		unsigned short float_as_unsigned_short(var const&) noexcept;
		unsigned short double_as_unsigned_short(var const&) noexcept;
		unsigned short long_double_as_unsigned_short(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		unsigned short string_as_unsigned_short(var const&) noexcept;
		unsigned short wide_string_as_unsigned_short(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		unsigned short bit8_string_as_unsigned_short(var const&) noexcept;
		#endif
		unsigned short bit16_string_as_unsigned_short(var const&) noexcept;
		unsigned short bit32_string_as_unsigned_short(var const&) noexcept;

	#endif
#endif

		unsigned short pointer_as_unsigned_short(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		unsigned short array_as_unsigned_short(var const&) noexcept;
		unsigned short subroutine_as_unsigned_short(var const&) LIBLETLIB_NOEXCEPT;
		unsigned short function_as_unsigned_short(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		unsigned short null_as_unsigned_short(var const&) noexcept;

#endif

		int boolean_as_integer(var const&) noexcept;
		int character_as_integer(var const&) noexcept;
		int signed_character_as_integer(var const&) noexcept;
		int unsigned_character_as_integer(var const&) noexcept;
		int wide_character_as_integer(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		int bit8_character_as_integer(var const&) noexcept;
	#endif
		int bit16_character_as_integer(var const&) noexcept;
		int bit32_character_as_integer(var const&) noexcept;

#endif

		int short_as_integer(var const&) noexcept;
		int unsigned_short_as_integer(var const&) noexcept;
		int integer_as_integer(var const&) noexcept;
		int unsigned_integer_as_integer(var const&) noexcept;
		int long_as_integer(var const&) noexcept;
		int unsigned_long_as_integer(var const&) noexcept;

#if (__cplusplus >= 201103L)

		int long_long_as_integer(var const&) noexcept;
		int unsigned_long_long_as_integer(var const&) noexcept;

#endif

		int float_as_integer(var const&) noexcept;
		int double_as_integer(var const&) noexcept;
		int long_double_as_integer(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		int string_as_integer(var const&) noexcept;
		int wide_string_as_integer(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		int bit8_string_as_integer(var const&) noexcept;
		#endif
		int bit16_string_as_integer(var const&) noexcept;
		int bit32_string_as_integer(var const&) noexcept;

	#endif
#endif

		int pointer_as_integer(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		int array_as_integer(var const&) noexcept;
		int subroutine_as_integer(var const&) LIBLETLIB_NOEXCEPT;
		int function_as_integer(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		int null_as_integer(var const&) noexcept;

#endif

		unsigned boolean_as_unsigned_integer(var const&) noexcept;
		unsigned character_as_unsigned_integer(var const&) noexcept;
		unsigned signed_character_as_unsigned_integer(var const&) noexcept;
		unsigned unsigned_character_as_unsigned_integer(var const&) noexcept;
		unsigned wide_character_as_unsigned_integer(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		unsigned bit8_character_as_unsigned_integer(var const&) noexcept;
	#endif
		unsigned bit16_character_as_unsigned_integer(var const&) noexcept;
		unsigned bit32_character_as_unsigned_integer(var const&) noexcept;

#endif

		unsigned short_as_unsigned_integer(var const&) noexcept;
		unsigned unsigned_short_as_unsigned_integer(var const&) noexcept;
		unsigned integer_as_unsigned_integer(var const&) noexcept;
		unsigned unsigned_integer_as_unsigned_integer(var const&) noexcept;
		unsigned long_as_unsigned_integer(var const&) noexcept;
		unsigned unsigned_long_as_unsigned_integer(var const&) noexcept;

#if (__cplusplus >= 201103L)

		unsigned long_long_as_unsigned_integer(var const&) noexcept;
		unsigned unsigned_long_long_as_unsigned_integer(var const&) noexcept;

#endif

		unsigned float_as_unsigned_integer(var const&) noexcept;
		unsigned double_as_unsigned_integer(var const&) noexcept;
		unsigned long_double_as_unsigned_integer(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		unsigned string_as_unsigned_integer(var const&) noexcept;
		unsigned wide_string_as_unsigned_integer(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		unsigned bit8_string_as_unsigned_integer(var const&) noexcept;
		#endif
		unsigned bit16_string_as_unsigned_integer(var const&) noexcept;
		unsigned bit32_string_as_unsigned_integer(var const&) noexcept;

	#endif
#endif

		unsigned pointer_as_unsigned_integer(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		unsigned int array_as_unsigned_integer(var const&) noexcept;
		unsigned subroutine_as_unsigned_integer(var const&) LIBLETLIB_NOEXCEPT;
		unsigned function_as_unsigned_integer(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		unsigned null_as_unsigned_integer(var const&) noexcept;

#endif

		long boolean_as_long(var const&) noexcept;
		long character_as_long(var const&) noexcept;
		long signed_character_as_long(var const&) noexcept;
		long unsigned_character_as_long(var const&) noexcept;
		long wide_character_as_long(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		long bit8_character_as_long(var const&) noexcept;
	#endif
		long bit16_character_as_long(var const&) noexcept;
		long bit32_character_as_long(var const&) noexcept;

#endif

		long short_as_long(var const&) noexcept;
		long unsigned_short_as_long(var const&) noexcept;
		long integer_as_long(var const&) noexcept;
		long unsigned_integer_as_long(var const&) noexcept;
		long long_as_long(var const&) noexcept;
		long unsigned_long_as_long(var const&) noexcept;

#if (__cplusplus >= 201103L)

		long long_long_as_long(var const&) noexcept;
		long unsigned_long_long_as_long(var const&) noexcept;

#endif

		long float_as_long(var const&) noexcept;
		long double_as_long(var const&) noexcept;
		long long_double_as_long(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		long string_as_long(var const&) noexcept;
		long wide_string_as_long(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		long bit8_string_as_long(var const&) noexcept;
		#endif
		long bit16_string_as_long(var const&) noexcept;
		long bit32_string_as_long(var const&) noexcept;

	#endif
#endif

		long pointer_as_long(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		long array_as_long(var const&) noexcept;
		long subroutine_as_long(var const&) LIBLETLIB_NOEXCEPT;
		long function_as_long(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		long null_as_long(var const&) noexcept;

#endif

		unsigned long boolean_as_unsigned_long(var const&) noexcept;
		unsigned long character_as_unsigned_long(var const&) noexcept;
		unsigned long signed_character_as_unsigned_long(var const&) noexcept;
		unsigned long unsigned_character_as_unsigned_long(var const&) noexcept;
		unsigned long wide_character_as_unsigned_long(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		unsigned long bit8_character_as_unsigned_long(var const&) noexcept;
	#endif
		unsigned long bit16_character_as_unsigned_long(var const&) noexcept;
		unsigned long bit32_character_as_unsigned_long(var const&) noexcept;

#endif

		unsigned long short_as_unsigned_long(var const&) noexcept;
		unsigned long unsigned_short_as_unsigned_long(var const&) noexcept;
		unsigned long integer_as_unsigned_long(var const&) noexcept;
		unsigned long unsigned_integer_as_unsigned_long(var const&) noexcept;
		unsigned long long_as_unsigned_long(var const&) noexcept;
		unsigned long unsigned_long_as_unsigned_long(var const&) noexcept;

#if (__cplusplus >= 201103L)

		unsigned long long_long_as_unsigned_long(var const&) noexcept;
		unsigned long unsigned_long_long_as_unsigned_long(var const&) noexcept;

#endif

		unsigned long float_as_unsigned_long(var const&) noexcept;
		unsigned long double_as_unsigned_long(var const&) noexcept;
		unsigned long long_double_as_unsigned_long(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		unsigned long string_as_unsigned_long(var const&) noexcept;
		unsigned long wide_string_as_unsigned_long(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		unsigned long bit8_string_as_unsigned_long(var const&) noexcept;
		#endif
		unsigned long bit16_string_as_unsigned_long(var const&) noexcept;
		unsigned long bit32_string_as_unsigned_long(var const&) noexcept;

	#endif
#endif

		unsigned long pointer_as_unsigned_long(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		unsigned long array_as_unsigned_long(var const&) noexcept;
		unsigned long subroutine_as_unsigned_long(var const&) LIBLETLIB_NOEXCEPT;
		unsigned long function_as_unsigned_long(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		unsigned long null_as_unsigned_long(var const&) noexcept;

#endif

#if (__cplusplus >= 201103L)

		long long boolean_as_long_long(var const&) noexcept;
		long long character_as_long_long(var const&) noexcept;
		long long signed_character_as_long_long(var const&) noexcept;
		long long unsigned_character_as_long_long(var const&) noexcept;
		long long wide_character_as_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		long long bit8_character_as_long_long(var const&) noexcept;
		#endif
		long long bit16_character_as_long_long(var const&) noexcept;
		long long bit32_character_as_long_long(var const&) noexcept;

	#endif

		long long short_as_long_long(var const&) noexcept;
		long long unsigned_short_as_long_long(var const&) noexcept;
		long long integer_as_long_long(var const&) noexcept;
		long long unsigned_integer_as_long_long(var const&) noexcept;
		long long long_as_long_long(var const&) noexcept;
		long long unsigned_long_as_long_long(var const&) noexcept;
		long long long_long_as_long_long(var const&) noexcept;
		long long unsigned_long_long_as_long_long(var const&) noexcept;
		long long float_as_long_long(var const&) noexcept;
		long long double_as_long_long(var const&) noexcept;
		long long long_double_as_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_FREESTANDING

		long long string_as_long_long(var const&) noexcept;
		long long wide_string_as_long_long(var const&) noexcept;

		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		long long bit8_string_as_long_long(var const&) noexcept;
			#endif
		long long bit16_string_as_long_long(var const&) noexcept;
		long long bit32_string_as_long_long(var const&) noexcept;

		#endif
	#endif

		long long pointer_as_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_FREESTANDING

		long long array_as_long_long(var const&) noexcept;
		long long subroutine_as_long_long(var const&) LIBLETLIB_NOEXCEPT;
		long long function_as_long_long(var const&) noexcept;

	#endif

		long long null_as_long_long(var const&) noexcept;
		unsigned long long boolean_as_unsigned_long_long(var const&) noexcept;
		unsigned long long character_as_unsigned_long_long(var const&) noexcept;
		unsigned long long signed_character_as_unsigned_long_long(var const&) noexcept;
		unsigned long long unsigned_character_as_unsigned_long_long(var const&) noexcept;
		unsigned long long wide_character_as_unsigned_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		unsigned long long bit8_character_as_unsigned_long_long(var const&) noexcept;
		#endif
		unsigned long long bit16_character_as_unsigned_long_long(var const&) noexcept;
		unsigned long long bit32_character_as_unsigned_long_long(var const&) noexcept;

	#endif

		unsigned long long short_as_unsigned_long_long(var const&) noexcept;
		unsigned long long unsigned_short_as_unsigned_long_long(var const&) noexcept;
		unsigned long long integer_as_unsigned_long_long(var const&) noexcept;
		unsigned long long unsigned_integer_as_unsigned_long_long(var const&) noexcept;
		unsigned long long long_as_unsigned_long_long(var const&) noexcept;
		unsigned long long unsigned_long_as_unsigned_long_long(var const&) noexcept;
		unsigned long long long_long_as_unsigned_long_long(var const&) noexcept;
		unsigned long long unsigned_long_long_as_unsigned_long_long(var const&) noexcept;
		unsigned long long float_as_unsigned_long_long(var const&) noexcept;
		unsigned long long double_as_unsigned_long_long(var const&) noexcept;
		unsigned long long long_double_as_unsigned_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_FREESTANDING

		unsigned long long string_as_unsigned_long_long(var const&) noexcept;
		unsigned long long wide_string_as_unsigned_long_long(var const&) noexcept;

		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		unsigned long long bit8_string_as_unsigned_long_long(var const&) noexcept;
			#endif
		unsigned long long bit16_string_as_unsigned_long_long(var const&) noexcept;
		unsigned long long bit32_string_as_unsigned_long_long(var const&) noexcept;

		#endif
	#endif

		unsigned long long pointer_as_unsigned_long_long(var const&) noexcept;

	#ifndef LIBLETLIB_FREESTANDING

		unsigned long long array_as_unsigned_long_long(var const&) noexcept;
		unsigned long long subroutine_as_unsigned_long_long(var const&) LIBLETLIB_NOEXCEPT;
		unsigned long long function_as_unsigned_long_long(var const&) noexcept;

	#endif

		unsigned long long null_as_unsigned_long_long(var const&) noexcept;

#endif

		float boolean_as_float(var const&) noexcept;
		float character_as_float(var const&) noexcept;
		float signed_character_as_float(var const&) noexcept;
		float unsigned_character_as_float(var const&) noexcept;
		float wide_character_as_float(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		float bit8_character_as_float(var const&) noexcept;
	#endif
		float bit16_character_as_float(var const&) noexcept;
		float bit32_character_as_float(var const&) noexcept;

#endif

		float short_as_float(var const&) noexcept;
		float unsigned_short_as_float(var const&) noexcept;
		float integer_as_float(var const&) noexcept;
		float unsigned_integer_as_float(var const&) noexcept;
		float long_as_float(var const&) noexcept;
		float unsigned_long_as_float(var const&) noexcept;

#if (__cplusplus >= 201103L)

		float long_long_as_float(var const&) noexcept;
		float unsigned_long_long_as_float(var const&) noexcept;

#endif

		float float_as_float(var const&) noexcept;
		float double_as_float(var const&) noexcept;
		float long_double_as_float(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		float string_as_float(var const&) noexcept;
		float wide_string_as_float(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		float bit8_string_as_float(var const&) noexcept;
		#endif
		float bit16_string_as_float(var const&) noexcept;
		float bit32_string_as_float(var const&) noexcept;

	#endif
#endif

		float pointer_as_float(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		float array_as_float(var const&) noexcept;
		float subroutine_as_float(var const&) LIBLETLIB_NOEXCEPT;
		float function_as_float(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		float null_as_float(var const&) noexcept;

#endif

		double boolean_as_double(var const&) noexcept;
		double character_as_double(var const&) noexcept;
		double signed_character_as_double(var const&) noexcept;
		double unsigned_character_as_double(var const&) noexcept;
		double wide_character_as_double(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		double bit8_character_as_double(var const&) noexcept;
	#endif
		double bit16_character_as_double(var const&) noexcept;
		double bit32_character_as_double(var const&) noexcept;

#endif

		double short_as_double(var const&) noexcept;
		double unsigned_short_as_double(var const&) noexcept;
		double integer_as_double(var const&) noexcept;
		double unsigned_integer_as_double(var const&) noexcept;
		double long_as_double(var const&) noexcept;
		double unsigned_long_as_double(var const&) noexcept;

#if (__cplusplus >= 201103L)

		double long_long_as_double(var const&) noexcept;
		double unsigned_long_long_as_double(var const&) noexcept;

#endif

		double float_as_double(var const&) noexcept;
		double double_as_double(var const&) noexcept;
		double long_double_as_double(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		double string_as_double(var const&) noexcept;
		double wide_string_as_double(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		double bit8_string_as_double(var const&) noexcept;
		#endif
		double bit16_string_as_double(var const&) noexcept;
		double bit32_string_as_double(var const&) noexcept;

	#endif
#endif

		double pointer_as_double(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		double array_as_double(var const&) noexcept;
		double subroutine_as_double(var const&) LIBLETLIB_NOEXCEPT;
		double function_as_double(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		double null_as_double(var const&) noexcept;

#endif

		long double boolean_as_long_double(var const&) noexcept;
		long double character_as_long_double(var const&) noexcept;
		long double signed_character_as_long_double(var const&) noexcept;
		long double unsigned_character_as_long_double(var const&) noexcept;
		long double wide_character_as_long_double(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		long double bit8_character_as_long_double(var const&) noexcept;
	#endif
		long double bit16_character_as_long_double(var const&) noexcept;
		long double bit32_character_as_long_double(var const&) noexcept;

#endif

		long double short_as_long_double(var const&) noexcept;
		long double unsigned_short_as_long_double(var const&) noexcept;
		long double integer_as_long_double(var const&) noexcept;
		long double unsigned_integer_as_long_double(var const&) noexcept;
		long double long_as_long_double(var const&) noexcept;
		long double unsigned_long_as_long_double(var const&) noexcept;

#if (__cplusplus >= 201103L)

		long double long_long_as_long_double(var const&) noexcept;
		long double unsigned_long_long_as_long_double(var const&) noexcept;

#endif

		long double float_as_long_double(var const&) noexcept;
		long double double_as_long_double(var const&) noexcept;
		long double long_double_as_long_double(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		long double string_as_long_double(var const&) noexcept;
		long double wide_string_as_long_double(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		long double bit8_string_as_long_double(var const&) noexcept;
		#endif
		long double bit16_string_as_long_double(var const&) noexcept;
		long double bit32_string_as_long_double(var const&) noexcept;

	#endif
#endif

		long double pointer_as_long_double(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		long double array_as_long_double(var const&) noexcept;
		long double subroutine_as_long_double(var const&) LIBLETLIB_NOEXCEPT;
		long double function_as_long_double(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		long double null_as_long_double(var const&) noexcept;

#endif

#ifndef LIBLETLIB_FREESTANDING

		char* boolean_as_string(var const&) noexcept;
		char* character_as_string(var const&) noexcept;
		char* signed_character_as_string(var const&) noexcept;
		char* unsigned_character_as_string(var const&) noexcept;
		char* wide_character_as_string(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		char* bit8_character_as_string(var const&) noexcept;
		#endif
		char* bit16_character_as_string(var const&) noexcept;
		char* bit32_character_as_string(var const&) noexcept;

	#endif

		char* short_as_string(var const&) noexcept;
		char* unsigned_short_as_string(var const&) noexcept;
		char* integer_as_string(var const&) noexcept;
		char* unsigned_integer_as_string(var const&) noexcept;
		char* long_as_string(var const&) noexcept;
		char* unsigned_long_as_string(var const&) noexcept;

	#if (__cplusplus >= 201103L)

		char* long_long_as_string(var const&) noexcept;
		char* unsigned_long_long_as_string(var const&) noexcept;

	#endif

		char* float_as_string(var const&) noexcept;
		char* double_as_string(var const&) noexcept;
		char* long_double_as_string(var const&) noexcept;
		char* string_as_string(var const&) noexcept;
		char* wide_string_as_string(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		char* bit8_string_as_string(var const&) noexcept;
		#endif
		char* bit16_string_as_string(var const&) noexcept;
		char* bit32_string_as_string(var const&) noexcept;

	#endif

		char* pointer_as_string(var const&) noexcept;
		char* array_as_string(var const&) noexcept;
		char* subroutine_as_string(var const&) LIBLETLIB_NOEXCEPT;
		char* function_as_string(var const&) noexcept;

	#if (__cplusplus >= 201103L)

		char* null_as_string(var const&) noexcept;

	#endif

		wchar_t* boolean_as_wide_string(var const&) noexcept;
		wchar_t* character_as_wide_string(var const&) noexcept;
		wchar_t* signed_character_as_wide_string(var const&) noexcept;
		wchar_t* unsigned_character_as_wide_string(var const&) noexcept;
		wchar_t* wide_character_as_wide_string(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		wchar_t* bit8_character_as_wide_string(var const&) noexcept;
		#endif
		wchar_t* bit16_character_as_wide_string(var const&) noexcept;
		wchar_t* bit32_character_as_wide_string(var const&) noexcept;

	#endif

		wchar_t* short_as_wide_string(var const&) noexcept;
		wchar_t* unsigned_short_as_wide_string(var const&) noexcept;
		wchar_t* integer_as_wide_string(var const&) noexcept;
		wchar_t* unsigned_integer_as_wide_string(var const&) noexcept;
		wchar_t* long_as_wide_string(var const&) noexcept;
		wchar_t* unsigned_long_as_wide_string(var const&) noexcept;

	#if (__cplusplus >= 201103L)

		wchar_t* long_long_as_wide_string(var const&) noexcept;
		wchar_t* unsigned_long_long_as_wide_string(var const&) noexcept;

	#endif

		wchar_t* float_as_wide_string(var const&) noexcept;
		wchar_t* double_as_wide_string(var const&) noexcept;
		wchar_t* long_double_as_wide_string(var const&) noexcept;
		wchar_t* string_as_wide_string(var const&) noexcept;
		wchar_t* wide_string_as_wide_string(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		wchar_t* bit8_string_as_wide_string(var const&) noexcept;
		#endif
		wchar_t* bit16_string_as_wide_string(var const&) noexcept;
		wchar_t* bit32_string_as_wide_string(var const&) noexcept;

	#endif

		wchar_t* pointer_as_wide_string(var const&) noexcept;
		wchar_t* array_as_wide_string(var const&) noexcept;
		wchar_t* subroutine_as_wide_string(var const&) LIBLETLIB_NOEXCEPT;
		wchar_t* function_as_wide_string(var const&) noexcept;

	#if (__cplusplus >= 201103L)

		wchar_t* null_as_wide_string(var const&) noexcept;

	#endif

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		char8_t* boolean_as_bit8_string(var const&) noexcept;
		char8_t* character_as_bit8_string(var const&) noexcept;
		char8_t* signed_character_as_bit8_string(var const&) noexcept;
		char8_t* unsigned_character_as_bit8_string(var const&) noexcept;
		char8_t* wide_character_as_bit8_string(var const&) noexcept;
		char8_t* bit8_character_as_bit8_string(var const&) noexcept;
		char8_t* bit16_character_as_bit8_string(var const&) noexcept;
		char8_t* bit32_character_as_bit8_string(var const&) noexcept;
		char8_t* short_as_bit8_string(var const&) noexcept;
		char8_t* unsigned_short_as_bit8_string(var const&) noexcept;
		char8_t* integer_as_bit8_string(var const&) noexcept;
		char8_t* unsigned_integer_as_bit8_string(var const&) noexcept;
		char8_t* long_as_bit8_string(var const&) noexcept;
		char8_t* unsigned_long_as_bit8_string(var const&) noexcept;
		char8_t* long_long_as_bit8_string(var const&) noexcept;
		char8_t* unsigned_long_long_as_bit8_string(var const&) noexcept;
		char8_t* float_as_bit8_string(var const&) noexcept;
		char8_t* double_as_bit8_string(var const&) noexcept;
		char8_t* long_double_as_bit8_string(var const&) noexcept;
		char8_t* string_as_bit8_string(var const&) noexcept;
		char8_t* wide_string_as_bit8_string(var const&) noexcept;
		char8_t* bit8_string_as_bit8_string(var const&) noexcept;
		char8_t* bit16_string_as_bit8_string(var const&) noexcept;
		char8_t* bit32_string_as_bit8_string(var const&) noexcept;
		char8_t* pointer_as_bit8_string(var const&) noexcept;
		char8_t* array_as_bit8_string(var const&) noexcept;
		char8_t* subroutine_as_bit8_string(var const&) LIBLETLIB_NOEXCEPT;
		char8_t* function_as_bit8_string(var const&) noexcept;
		char8_t* null_as_bit8_string(var const&) noexcept;
		#endif

		char16_t* boolean_as_bit16_string(var const&) noexcept;
		char16_t* character_as_bit16_string(var const&) noexcept;
		char16_t* signed_character_as_bit16_string(var const&) noexcept;
		char16_t* unsigned_character_as_bit16_string(var const&) noexcept;
		char16_t* wide_character_as_bit16_string(var const&) noexcept;
		#if (__cplusplus >= 202002L)
		char16_t* bit8_character_as_bit16_string(var const&) noexcept;
		#endif
		char16_t* bit16_character_as_bit16_string(var const&) noexcept;
		char16_t* bit32_character_as_bit16_string(var const&) noexcept;
		char16_t* short_as_bit16_string(var const&) noexcept;
		char16_t* unsigned_short_as_bit16_string(var const&) noexcept;
		char16_t* integer_as_bit16_string(var const&) noexcept;
		char16_t* unsigned_integer_as_bit16_string(var const&) noexcept;
		char16_t* long_as_bit16_string(var const&) noexcept;
		char16_t* unsigned_long_as_bit16_string(var const&) noexcept;
		char16_t* long_long_as_bit16_string(var const&) noexcept;
		char16_t* unsigned_long_long_as_bit16_string(var const&) noexcept;
		char16_t* float_as_bit16_string(var const&) noexcept;
		char16_t* double_as_bit16_string(var const&) noexcept;
		char16_t* long_double_as_bit16_string(var const&) noexcept;
		char16_t* string_as_bit16_string(var const&) noexcept;
		char16_t* wide_string_as_bit16_string(var const&) noexcept;
		#if (__cplusplus >= 202002L)
		char16_t* bit8_string_as_bit16_string(var const&) noexcept;
		#endif
		char16_t* bit16_string_as_bit16_string(var const&) noexcept;
		char16_t* bit32_string_as_bit16_string(var const&) noexcept;
		char16_t* pointer_as_bit16_string(var const&) noexcept;
		char16_t* array_as_bit16_string(var const&) noexcept;
		char16_t* subroutine_as_bit16_string(var const&) LIBLETLIB_NOEXCEPT;
		char16_t* function_as_bit16_string(var const&) noexcept;
		char16_t* null_as_bit16_string(var const&) noexcept;

		char32_t* boolean_as_bit32_string(var const&) noexcept;
		char32_t* character_as_bit32_string(var const&) noexcept;
		char32_t* signed_character_as_bit32_string(var const&) noexcept;
		char32_t* unsigned_character_as_bit32_string(var const&) noexcept;
		char32_t* wide_character_as_bit32_string(var const&) noexcept;
		#if (__cplusplus >= 202002L)
		char32_t* bit8_character_as_bit32_string(var const&) noexcept;
		#endif
		char32_t* bit16_character_as_bit32_string(var const&) noexcept;
		char32_t* bit32_character_as_bit32_string(var const&) noexcept;
		char32_t* short_as_bit32_string(var const&) noexcept;
		char32_t* unsigned_short_as_bit32_string(var const&) noexcept;
		char32_t* integer_as_bit32_string(var const&) noexcept;
		char32_t* unsigned_integer_as_bit32_string(var const&) noexcept;
		char32_t* long_as_bit32_string(var const&) noexcept;
		char32_t* unsigned_long_as_bit32_string(var const&) noexcept;
		char32_t* long_long_as_bit32_string(var const&) noexcept;
		char32_t* unsigned_long_long_as_bit32_string(var const&) noexcept;
		char32_t* float_as_bit32_string(var const&) noexcept;
		char32_t* double_as_bit32_string(var const&) noexcept;
		char32_t* long_double_as_bit32_string(var const&) noexcept;
		char32_t* string_as_bit32_string(var const&) noexcept;
		char32_t* wide_string_as_bit32_string(var const&) noexcept;
		#if (__cplusplus >= 202002L)
		char32_t* bit8_string_as_bit32_string(var const&) noexcept;
		#endif
		char32_t* bit16_string_as_bit32_string(var const&) noexcept;
		char32_t* bit32_string_as_bit32_string(var const&) noexcept;
		char32_t* pointer_as_bit32_string(var const&) noexcept;
		char32_t* array_as_bit32_string(var const&) noexcept;
		char32_t* subroutine_as_bit32_string(var const&) LIBLETLIB_NOEXCEPT;
		char32_t* function_as_bit32_string(var const&) noexcept;
		char32_t* null_as_bit32_string(var const&) noexcept;

	#endif
#endif

		void* boolean_as_pointer(var const&) noexcept;
		void* character_as_pointer(var const&) noexcept;
		void* signed_character_as_pointer(var const&) noexcept;
		void* unsigned_character_as_pointer(var const&) noexcept;
		void* wide_character_as_pointer(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		void* bit8_character_as_pointer(var const&) noexcept;
	#endif
		void* bit16_character_as_pointer(var const&) noexcept;
		void* bit32_character_as_pointer(var const&) noexcept;

#endif

		void* short_as_pointer(var const&) noexcept;
		void* unsigned_short_as_pointer(var const&) noexcept;
		void* integer_as_pointer(var const&) noexcept;
		void* unsigned_integer_as_pointer(var const&) noexcept;
		void* long_as_pointer(var const&) noexcept;
		void* unsigned_long_as_pointer(var const&) noexcept;

#if (__cplusplus >= 201103L)

		void* long_long_as_pointer(var const&) noexcept;
		void* unsigned_long_long_as_pointer(var const&) noexcept;

#endif

		void* float_as_pointer(var const&) noexcept;
		void* double_as_pointer(var const&) noexcept;
		void* long_double_as_pointer(var const&) noexcept;
		void* string_as_pointer(var const&) noexcept;
		void* wide_string_as_pointer(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		void* bit8_string_as_pointer(var const&) noexcept;
	#endif
		void* bit16_string_as_pointer(var const&) noexcept;
		void* bit32_string_as_pointer(var const&) noexcept;

#endif

		void* pointer_as_pointer(var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		void* array_as_pointer(var const&) noexcept;
		void* subroutine_as_pointer(var const&) LIBLETLIB_NOEXCEPT;
		void* function_as_pointer(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		void* null_as_pointer(var const&) noexcept;

#endif

		subroutine_t boolean_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t signed_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t unsigned_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t wide_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		subroutine_t bit8_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
	#endif
		subroutine_t bit16_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t bit32_character_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

#endif

		subroutine_t short_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t unsigned_short_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t integer_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t unsigned_integer_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t long_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t unsigned_long_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t long_long_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t unsigned_long_long_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t float_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t double_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t long_double_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t string_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t wide_string_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		subroutine_t bit8_string_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;
	#endif
		subroutine_t bit16_string_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t bit32_string_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

#endif

		subroutine_t pointer_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t subroutine_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t function_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t array_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		subroutine_t null_as_subroutine(var const&) LIBLETLIB_NOEXCEPT;

		function_t boolean_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t character_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t signed_character_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t unsigned_character_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t wide_character_as_function(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		function_t bit8_character_as_function(var const&) LIBLETLIB_NOEXCEPT;
	#endif
		function_t bit16_character_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t bit32_character_as_function(var const&) LIBLETLIB_NOEXCEPT;

#endif

		function_t short_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t unsigned_short_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t integer_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t unsigned_integer_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t long_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t unsigned_long_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t long_long_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t unsigned_long_long_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t float_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t double_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t long_double_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t string_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t wide_string_as_function(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		function_t bit8_string_as_function(var const&) LIBLETLIB_NOEXCEPT;
	#endif
		function_t bit16_string_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t bit32_string_as_function(var const&) LIBLETLIB_NOEXCEPT;

#endif

		function_t pointer_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t subroutine_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t function_as_function(var const&) noexcept;

		function_t array_as_function(var const&) LIBLETLIB_NOEXCEPT;

		function_t null_as_function(var const&) LIBLETLIB_NOEXCEPT;

		var boolean_as_array(var const&) noexcept;

		var character_as_array(var const&) noexcept;

		var signed_character_as_array(var const&) noexcept;

		var unsigned_character_as_array(var const&) noexcept;

		var wide_character_as_array(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_as_array(var const&) noexcept;
	#endif
		var bit16_character_as_array(var const&) noexcept;

		var bit32_character_as_array(var const&) noexcept;

#endif

		var short_as_array(var const&) noexcept;

		var unsigned_short_as_array(var const&) noexcept;

		var integer_as_array(var const&) noexcept;

		var unsigned_integer_as_array(var const&) noexcept;

		var long_as_array(var const&) noexcept;

		var unsigned_long_as_array(var const&) noexcept;

		var long_long_as_array(var const&) noexcept;

		var unsigned_long_long_as_array(var const&) noexcept;

		var float_as_array(var const&) noexcept;

		var double_as_array(var const&) noexcept;

		var long_double_as_array(var const&) noexcept;

		var string_as_array(var const&) noexcept;

		var wide_string_as_array(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_as_array(var const&) noexcept;
	#endif
		var bit16_string_as_array(var const&) noexcept;

		var bit32_string_as_array(var const&) noexcept;

#endif

		var pointer_as_array(var const&) noexcept;


		var subroutine_as_array(var const&) noexcept;

		var function_as_array(var const&) noexcept;

		var array_as_array(var const&) noexcept;

#if (__cplusplus >= 201103L)

		var null_as_array(var const&) noexcept;

#endif

#if (__cplusplus >= 201103L)

		std::nullptr_t boolean_as_null(var const&) noexcept;

		std::nullptr_t character_as_null(var const&) noexcept;

		std::nullptr_t signed_character_as_null(var const&) noexcept;

		std::nullptr_t unsigned_character_as_null(var const&) noexcept;

		std::nullptr_t wide_character_as_null(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		std::nullptr_t bit8_character_as_null(var const&) noexcept;
		#endif
		std::nullptr_t bit16_character_as_null(var const&) noexcept;

		std::nullptr_t bit32_character_as_null(var const&) noexcept;

	#endif

		std::nullptr_t short_as_null(var const&) noexcept;

		std::nullptr_t unsigned_short_as_null(var const&) noexcept;

		std::nullptr_t integer_as_null(var const&) noexcept;

		std::nullptr_t unsigned_integer_as_null(var const&) noexcept;

		std::nullptr_t long_as_null(var const&) noexcept;

		std::nullptr_t unsigned_long_as_null(var const&) noexcept;

		std::nullptr_t long_long_as_null(var const&) noexcept;

		std::nullptr_t unsigned_long_long_as_null(var const&) noexcept;

		std::nullptr_t float_as_null(var const&) noexcept;

		std::nullptr_t double_as_null(var const&) noexcept;

		std::nullptr_t long_double_as_null(var const&) noexcept;

		std::nullptr_t string_as_null(var const&) noexcept;

		std::nullptr_t wide_string_as_null(var const&) noexcept;

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		std::nullptr_t bit8_string_as_null(var const&) noexcept;
		#endif
		std::nullptr_t bit16_string_as_null(var const&) noexcept;

		std::nullptr_t bit32_string_as_null(var const&) noexcept;

	#endif

		std::nullptr_t pointer_as_null(var const&) noexcept;

	#ifndef LIBLETLIB_FREESTANDING

		std::nullptr_t array_as_null(var const&) noexcept;

	#endif

		std::nullptr_t subroutine_as_null(var const&) noexcept;

		std::nullptr_t function_as_null(var const&) noexcept;

		std::nullptr_t null_as_null(var const&) noexcept;

#endif


		var boolean_negative(var const&) noexcept;

		var character_negative(var const&) noexcept;

		var signed_character_negative(var const&) noexcept;

		var unsigned_character_negative(var const&) noexcept;

		var wide_character_negative(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_negative(var const&) noexcept;
	#endif
		var bit16_character_negative(var const&) noexcept;

		var bit32_character_negative(var const&) noexcept;

#endif

		var short_negative(var const&) noexcept;

		var unsigned_short_negative(var const&) noexcept;

		var integer_negative(var const&) noexcept;

		var unsigned_integer_negative(var const&) noexcept;

		var long_negative(var const&) noexcept;

		var unsigned_long_negative(var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_negative(var const&) noexcept;

		var unsigned_long_long_negative(var const&) noexcept;

#endif

		var float_negative(var const&) noexcept;

		var double_negative(var const&) noexcept;

		var long_double_negative(var const&) noexcept;

		var string_negative(var const&) noexcept;

		var wide_string_negative(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_negative(var const&) noexcept;
	#endif
		var bit16_string_negative(var const&) noexcept;

		var bit32_string_negative(var const&) noexcept;

#endif

		var pointer_negative(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_negative(var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_negative(var const&) LIBLETLIB_NOEXCEPT;

		var function_negative(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		var null_negative(var const&) noexcept;

#endif

		var boolean_positive(var const&) noexcept;

		var character_positive(var const&) noexcept;

		var signed_character_positive(var const&) noexcept;

		var unsigned_character_positive(var const&) noexcept;

		var wide_character_positive(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_positive(var const&) noexcept;
	#endif
		var bit16_character_positive(var const&) noexcept;

		var bit32_character_positive(var const&) noexcept;

#endif

		var short_positive(var const&) noexcept;

		var unsigned_short_positive(var const&) noexcept;

		var integer_positive(var const&) noexcept;

		var unsigned_integer_positive(var const&) noexcept;

		var long_positive(var const&) noexcept;

		var unsigned_long_positive(var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_positive(var const&) noexcept;

		var unsigned_long_long_positive(var const&) noexcept;

#endif

		var float_positive(var const&) noexcept;

		var double_positive(var const&) noexcept;

		var long_double_positive(var const&) noexcept;

		var string_positive(var const&) noexcept;

		var wide_string_positive(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_positive(var const&) noexcept;
	#endif
		var bit16_string_positive(var const&) noexcept;

		var bit32_string_positive(var const&) noexcept;

#endif

		var pointer_positive(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_positive(var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_positive(var const&) LIBLETLIB_NOEXCEPT;

		var function_positive(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		var null_positive(var const&) noexcept;

#endif

		var boolean_increment(var const&) noexcept;

		var character_increment(var const&) noexcept;

		var signed_character_increment(var const&) noexcept;

		var unsigned_character_increment(var const&) noexcept;

		var wide_character_increment(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_increment(var const&) noexcept;
	#endif
		var bit16_character_increment(var const&) noexcept;

		var bit32_character_increment(var const&) noexcept;

#endif

		var short_increment(var const&) noexcept;

		var unsigned_short_increment(var const&) noexcept;

		var integer_increment(var const&) noexcept;

		var unsigned_integer_increment(var const&) noexcept;

		var long_increment(var const&) noexcept;

		var unsigned_long_increment(var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_increment(var const&) noexcept;

		var unsigned_long_long_increment(var const&) noexcept;

#endif

		var float_increment(var const&) noexcept;

		var double_increment(var const&) noexcept;

		var long_double_increment(var const&) noexcept;

		var string_increment(var const&) noexcept;

		var wide_string_increment(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_increment(var const&) noexcept;
	#endif
		var bit16_string_increment(var const&) noexcept;

		var bit32_string_increment(var const&) noexcept;

#endif

		var pointer_increment(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_increment(var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_increment(var const&) LIBLETLIB_NOEXCEPT;

		var function_increment(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		var null_increment(var const&) noexcept;

#endif

		var boolean_decrement(var const&) noexcept;

		var character_decrement(var const&) noexcept;

		var signed_character_decrement(var const&) noexcept;

		var unsigned_character_decrement(var const&) noexcept;

		var wide_character_decrement(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_decrement(var const&) noexcept;
	#endif
		var bit16_character_decrement(var const&) noexcept;

		var bit32_character_decrement(var const&) noexcept;

#endif

		var short_decrement(var const&) noexcept;

		var unsigned_short_decrement(var const&) noexcept;

		var integer_decrement(var const&) noexcept;

		var unsigned_integer_decrement(var const&) noexcept;

		var long_decrement(var const&) noexcept;

		var unsigned_long_decrement(var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_decrement(var const&) noexcept;

		var unsigned_long_long_decrement(var const&) noexcept;

#endif

		var float_decrement(var const&) noexcept;

		var double_decrement(var const&) noexcept;

		var long_double_decrement(var const&) noexcept;

		var string_decrement(var const&) noexcept;

		var wide_string_decrement(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_decrement(var const&) noexcept;
	#endif
		var bit16_string_decrement(var const&) noexcept;

		var bit32_string_decrement(var const&) noexcept;

#endif

		var pointer_decrement(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_decrement(var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_decrement(var const&) LIBLETLIB_NOEXCEPT;

		var function_decrement(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		var null_decrement(var const&) noexcept;

#endif

		var boolean_negation(var const&) noexcept;

		var character_negation(var const&) noexcept;

		var signed_character_negation(var const&) noexcept;

		var unsigned_character_negation(var const&) noexcept;

		var wide_character_negation(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_negation(var const&) noexcept;
	#endif
		var bit16_character_negation(var const&) noexcept;

		var bit32_character_negation(var const&) noexcept;

#endif

		var short_negation(var const&) noexcept;

		var unsigned_short_negation(var const&) noexcept;

		var integer_negation(var const&) noexcept;

		var unsigned_integer_negation(var const&) noexcept;

		var long_negation(var const&) noexcept;

		var unsigned_long_negation(var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_negation(var const&) noexcept;

		var unsigned_long_long_negation(var const&) noexcept;

#endif

		var float_negation(var const&) noexcept;

		var double_negation(var const&) noexcept;

		var long_double_negation(var const&) noexcept;

		var string_negation(var const&) noexcept;

		var wide_string_negation(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_negation(var const&) noexcept;
	#endif
		var bit16_string_negation(var const&) noexcept;

		var bit32_string_negation(var const&) noexcept;

#endif

		var pointer_negation(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_negation(var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_negation(var const&) LIBLETLIB_NOEXCEPT;

		var function_negation(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		var null_negation(var const&) noexcept;

#endif

		var boolean_complement(var const&) noexcept;

		var character_complement(var const&) noexcept;

		var signed_character_complement(var const&) noexcept;

		var unsigned_character_complement(var const&) noexcept;

		var wide_character_complement(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_complement(var const&) noexcept;
	#endif
		var bit16_character_complement(var const&) noexcept;

		var bit32_character_complement(var const&) noexcept;

#endif

		var short_complement(var const&) noexcept;

		var unsigned_short_complement(var const&) noexcept;

		var integer_complement(var const&) noexcept;

		var unsigned_integer_complement(var const&) noexcept;

		var long_complement(var const&) noexcept;

		var unsigned_long_complement(var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_complement(var const&) noexcept;

		var unsigned_long_long_complement(var const&) noexcept;

#endif

		var float_complement(var const&) noexcept;

		var double_complement(var const&) noexcept;

		var long_double_complement(var const&) noexcept;

		var string_complement(var const&) noexcept;

		var wide_string_complement(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_complement(var const&) noexcept;
	#endif
		var bit16_string_complement(var const&) noexcept;

		var bit32_string_complement(var const&) noexcept;

#endif

		var pointer_complement(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_complement(var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_complement(var const&) LIBLETLIB_NOEXCEPT;

		var function_complement(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		var null_complement(var const&) noexcept;

#endif

		var boolean_indirection(var const&) noexcept;

		var character_indirection(var const&) noexcept;

		var signed_character_indirection(var const&) noexcept;

		var unsigned_character_indirection(var const&) noexcept;

		var wide_character_indirection(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_indirection(var const&) noexcept;
	#endif
		var bit16_character_indirection(var const&) noexcept;

		var bit32_character_indirection(var const&) noexcept;

#endif

		var short_indirection(var const&) noexcept;

		var unsigned_short_indirection(var const&) noexcept;

		var integer_indirection(var const&) noexcept;

		var unsigned_integer_indirection(var const&) noexcept;

		var long_indirection(var const&) noexcept;

		var unsigned_long_indirection(var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_indirection(var const&) noexcept;

		var unsigned_long_long_indirection(var const&) noexcept;

#endif

		var float_indirection(var const&) noexcept;

		var double_indirection(var const&) noexcept;

		var long_double_indirection(var const&) noexcept;

		var string_indirection(var const&) noexcept;

		var wide_string_indirection(var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_indirection(var const&) noexcept;
	#endif
		var bit16_string_indirection(var const&) noexcept;

		var bit32_string_indirection(var const&) noexcept;

#endif

		var pointer_indirection(var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_indirection(var const&) noexcept;

		var subroutine_indirection(var const&) LIBLETLIB_NOEXCEPT;

		var function_indirection(var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		var null_indirection(var const&) noexcept;

#endif

		var boolean_index(var const&, var const&) noexcept;

		var character_index(var const&, var const&) noexcept;

		var signed_character_index(var const&, var const&) noexcept;

		var unsigned_character_index(var const&, var const&) noexcept;

		var wide_character_index(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_index(var const&, var const&) noexcept;
	#endif
		var bit16_character_index(var const&, var const&) noexcept;

		var bit32_character_index(var const&, var const&) noexcept;

#endif

		var short_index(var const&, var const&) noexcept;

		var unsigned_short_index(var const&, var const&) noexcept;

		var integer_index(var const&, var const&) noexcept;

		var unsigned_integer_index(var const&, var const&) noexcept;

		var long_index(var const&, var const&) noexcept;

		var unsigned_long_index(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_index(var const&, var const&) noexcept;

		var unsigned_long_long_index(var const&, var const&) noexcept;

#endif

		var float_index(var const&, var const&) noexcept;

		var double_index(var const&, var const&) noexcept;

		var long_double_index(var const&, var const&) noexcept;

		var string_index(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var wide_string_index(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_index(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
		var bit16_string_index(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var bit32_string_index(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var pointer_index(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_index(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_index(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var function_index(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#if (__cplusplus >= 201103L)

		var null_index(var const&, var const&) noexcept;

#endif

		var boolean_subtraction(var const&, var const&) noexcept;

		var character_subtraction(var const&, var const&) noexcept;

		var signed_character_subtraction(var const&, var const&) noexcept;

		var unsigned_character_subtraction(var const&, var const&) noexcept;

		var wide_character_subtraction(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_subtraction(var const&, var const&) noexcept;
	#endif
		var bit16_character_subtraction(var const&, var const&) noexcept;

		var bit32_character_subtraction(var const&, var const&) noexcept;

#endif

		var short_subtraction(var const&, var const&) noexcept;

		var unsigned_short_subtraction(var const&, var const&) noexcept;

		var integer_subtraction(var const&, var const&) noexcept;

		var unsigned_integer_subtraction(var const&, var const&) noexcept;

		var long_subtraction(var const&, var const&) noexcept;

		var unsigned_long_subtraction(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_subtraction(var const&, var const&) noexcept;

		var unsigned_long_long_subtraction(var const&, var const&) noexcept;

#endif

		var float_subtraction(var const&, var const&) noexcept;

		var double_subtraction(var const&, var const&) noexcept;

		var long_double_subtraction(var const&, var const&) noexcept;

		var string_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var wide_string_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
		var bit16_string_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var bit32_string_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var pointer_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var function_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#if (__cplusplus >= 201103L)

		var null_subtraction(var const&, var const&) noexcept;

#endif

		var boolean_sum(var const&, var const&) noexcept;

		var character_sum(var const&, var const&) noexcept;

		var signed_character_sum(var const&, var const&) noexcept;

		var unsigned_character_sum(var const&, var const&) noexcept;

		var wide_character_sum(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_sum(var const&, var const&) noexcept;
	#endif
		var bit16_character_sum(var const&, var const&) noexcept;

		var bit32_character_sum(var const&, var const&) noexcept;

#endif

		var short_sum(var const&, var const&) noexcept;

		var unsigned_short_sum(var const&, var const&) noexcept;

		var integer_sum(var const&, var const&) noexcept;

		var unsigned_integer_sum(var const&, var const&) noexcept;

		var long_sum(var const&, var const&) noexcept;

		var unsigned_long_sum(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_sum(var const&, var const&) noexcept;

		var unsigned_long_long_sum(var const&, var const&) noexcept;

#endif

		var float_sum(var const&, var const&) noexcept;

		var double_sum(var const&, var const&) noexcept;

		var long_double_sum(var const&, var const&) noexcept;

		var string_sum(var const&, var const&) noexcept;

		var wide_string_sum(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_sum(var const&, var const&) noexcept;
	#endif
		var bit16_string_sum(var const&, var const&) noexcept;

		var bit32_string_sum(var const&, var const&) noexcept;

#endif

		var pointer_sum(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_sum(var const&, var const&) noexcept;

		var subroutine_sum(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var function_sum(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#if (__cplusplus >= 201103L)

		var null_sum(var const&, var const&) noexcept;

#endif

		var boolean_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var signed_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var unsigned_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var wide_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
		var bit16_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var bit32_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var short_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var unsigned_short_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var integer_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var unsigned_integer_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var long_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var unsigned_long_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#if (__cplusplus >= 201103L)

		var long_long_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var unsigned_long_long_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var float_division(var const&, var const&) noexcept;

		var double_division(var const&, var const&) noexcept;

		var long_double_division(var const&, var const&) noexcept;

		var string_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var wide_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
		var bit16_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var bit32_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var pointer_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var function_division(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#if (__cplusplus >= 201103L)

		var null_division(var const&, var const&) noexcept;

#endif

		var boolean_multiplication(var const&, var const&) noexcept;

		var character_multiplication(var const&, var const&) noexcept;

		var signed_character_multiplication(var const&, var const&) noexcept;

		var unsigned_character_multiplication(var const&, var const&) noexcept;

		var wide_character_multiplication(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_multiplication(var const&, var const&) noexcept;
	#endif
		var bit16_character_multiplication(var const&, var const&) noexcept;

		var bit32_character_multiplication(var const&, var const&) noexcept;

#endif

		var short_multiplication(var const&, var const&) noexcept;

		var unsigned_short_multiplication(var const&, var const&) noexcept;

		var integer_multiplication(var const&, var const&) noexcept;

		var unsigned_integer_multiplication(var const&, var const&) noexcept;

		var long_multiplication(var const&, var const&) noexcept;

		var unsigned_long_multiplication(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_multiplication(var const&, var const&) noexcept;

		var unsigned_long_long_multiplication(var const&, var const&) noexcept;

#endif

		var float_multiplication(var const&, var const&) noexcept;

		var double_multiplication(var const&, var const&) noexcept;

		var long_double_multiplication(var const&, var const&) noexcept;

		var string_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var wide_string_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
		var bit16_string_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var bit32_string_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var pointer_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var function_multiplication(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#if (__cplusplus >= 201103L)

		var null_multiplication(var const&, var const&) noexcept;

#endif

		var boolean_modulo(var const&, var const&) noexcept;

		var character_modulo(var const&, var const&) noexcept;

		var signed_character_modulo(var const&, var const&) noexcept;

		var unsigned_character_modulo(var const&, var const&) noexcept;

		var wide_character_modulo(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_modulo(var const&, var const&) noexcept;
	#endif
		var bit16_character_modulo(var const&, var const&) noexcept;

		var bit32_character_modulo(var const&, var const&) noexcept;

#endif

		var short_modulo(var const&, var const&) noexcept;

		var unsigned_short_modulo(var const&, var const&) noexcept;

		var integer_modulo(var const&, var const&) noexcept;

		var unsigned_integer_modulo(var const&, var const&) noexcept;

		var long_modulo(var const&, var const&) noexcept;

		var unsigned_long_modulo(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_modulo(var const&, var const&) noexcept;

		var unsigned_long_long_modulo(var const&, var const&) noexcept;

#endif

		var float_modulo(var const&, var const&) noexcept;

		var double_modulo(var const&, var const&) noexcept;

		var long_double_modulo(var const&, var const&) noexcept;

		var string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var wide_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
		var bit16_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var bit32_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var pointer_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var function_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#if (__cplusplus >= 201103L)

		var null_modulo(var const&, var const&) noexcept;

#endif

		var boolean_exponentiation(var const&, var const&) noexcept;

		var character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var signed_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var unsigned_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var wide_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
		var bit16_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var bit32_character_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var short_exponentiation(var const&, var const&) noexcept;

		var unsigned_short_exponentiation(var const&, var const&) noexcept;

		var integer_exponentiation(var const&, var const&) noexcept;

		var unsigned_integer_exponentiation(var const&, var const&) noexcept;

		var long_exponentiation(var const&, var const&) noexcept;

		var unsigned_long_exponentiation(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_exponentiation(var const&, var const&) noexcept;

		var unsigned_long_long_exponentiation(var const&, var const&) noexcept;

#endif

		var float_exponentiation(var const&, var const&) noexcept;

		var double_exponentiation(var const&, var const&) noexcept;

		var long_double_exponentiation(var const&, var const&) noexcept;

		var string_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var wide_string_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
		var bit16_string_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var bit32_string_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var pointer_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var function_exponentiation(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

#if (__cplusplus >= 201103L)

		var null_exponentiation(var const&, var const&) noexcept;

#endif

		var boolean_binary_and(var const&, var const&) noexcept;

		var character_binary_and(var const&, var const&) noexcept;

		var signed_character_binary_and(var const&, var const&) noexcept;

		var unsigned_character_binary_and(var const&, var const&) noexcept;

		var wide_character_binary_and(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_binary_and(var const&, var const&) noexcept;
	#endif
		var bit16_character_binary_and(var const&, var const&) noexcept;

		var bit32_character_binary_and(var const&, var const&) noexcept;

#endif

		var short_binary_and(var const&, var const&) noexcept;

		var unsigned_short_binary_and(var const&, var const&) noexcept;

		var integer_binary_and(var const&, var const&) noexcept;

		var unsigned_integer_binary_and(var const&, var const&) noexcept;

		var long_binary_and(var const&, var const&) noexcept;

		var unsigned_long_binary_and(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_binary_and(var const&, var const&) noexcept;

		var unsigned_long_long_binary_and(var const&, var const&) noexcept;

#endif

		var float_binary_and(var const&, var const&) noexcept;

		var double_binary_and(var const&, var const&) noexcept;

		var long_double_binary_and(var const&, var const&) noexcept;

		var string_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var wide_string_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
		var bit16_string_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var bit32_string_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var pointer_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var function_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#if (__cplusplus >= 201103L)

		var null_binary_and(var const&, var const&) noexcept;

#endif

		var boolean_binary_or(var const&, var const&) noexcept;

		var character_binary_or(var const&, var const&) noexcept;

		var signed_character_binary_or(var const&, var const&) noexcept;

		var unsigned_character_binary_or(var const&, var const&) noexcept;

		var wide_character_binary_or(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_binary_or(var const&, var const&) noexcept;
	#endif
		var bit16_character_binary_or(var const&, var const&) noexcept;

		var bit32_character_binary_or(var const&, var const&) noexcept;

#endif

		var short_binary_or(var const&, var const&) noexcept;

		var unsigned_short_binary_or(var const&, var const&) noexcept;

		var integer_binary_or(var const&, var const&) noexcept;

		var unsigned_integer_binary_or(var const&, var const&) noexcept;

		var long_binary_or(var const&, var const&) noexcept;

		var unsigned_long_binary_or(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_binary_or(var const&, var const&) noexcept;

		var unsigned_long_long_binary_or(var const&, var const&) noexcept;

#endif

		var float_binary_or(var const&, var const&) noexcept;

		var double_binary_or(var const&, var const&) noexcept;

		var long_double_binary_or(var const&, var const&) noexcept;

		var string_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var wide_string_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
		var bit16_string_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var bit32_string_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var pointer_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var function_binary_or(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

#if (__cplusplus >= 201103L)

		var null_binary_or(var const&, var const&) noexcept;

#endif

		var boolean_binary_xor(var const&, var const&) noexcept;

		var character_binary_xor(var const&, var const&) noexcept;

		var signed_character_binary_xor(var const&, var const&) noexcept;

		var unsigned_character_binary_xor(var const&, var const&) noexcept;

		var wide_character_binary_xor(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_character_binary_xor(var const&, var const&) noexcept;
	#endif
		var bit16_character_binary_xor(var const&, var const&) noexcept;

		var bit32_character_binary_xor(var const&, var const&) noexcept;

#endif

		var short_binary_xor(var const&, var const&) noexcept;

		var unsigned_short_binary_xor(var const&, var const&) noexcept;

		var integer_binary_xor(var const&, var const&) noexcept;

		var unsigned_integer_binary_xor(var const&, var const&) noexcept;

		var long_binary_xor(var const&, var const&) noexcept;

		var unsigned_long_binary_xor(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

		var long_long_binary_xor(var const&, var const&) noexcept;

		var unsigned_long_long_binary_xor(var const&, var const&) noexcept;

#endif

		var float_binary_xor(var const&, var const&) noexcept;

		var double_binary_xor(var const&, var const&) noexcept;

		var long_double_binary_xor(var const&, var const&) noexcept;

		var string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var wide_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		var bit8_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;
	#endif
		var bit16_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var bit32_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif

		var pointer_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

#ifndef LIBLETLIB_FREESTANDING

		var array_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var subroutine_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

		var function_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT;

#endif
#if (__cplusplus >= 201103L)

		var null_binary_xor(var const&, var const&) noexcept;

#endif

		int boolean_comparison(var const&, var const&) noexcept;

		int character_comparison(var const&, var const&) noexcept;

		int signed_character_comparison(var const&, var const&) noexcept;

		int unsigned_character_comparison(var const&, var const&) noexcept;

		int wide_character_comparison(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		int bit8_character_comparison(var const&, var const&) noexcept;
	#endif

		int bit16_character_comparison(var const&, var const&) noexcept;

		int bit32_character_comparison(var const&, var const&) noexcept;

#endif

		int short_comparison(var const&, var const&) noexcept;

		int unsigned_short_comparison(var const&, var const&) noexcept;

		int integer_comparison(var const&, var const&) noexcept;

		int unsigned_integer_comparison(var const&, var const&) noexcept;

		int long_comparison(var const&, var const&) noexcept;

		int unsigned_long_comparison(var const&, var const&) noexcept;

#if (__cplusplus >= 201103L)

		int long_long_comparison(var const&, var const&) noexcept;

		int unsigned_long_long_comparison(var const&, var const&) noexcept;

#endif

		int float_comparison(var const&, var const&) noexcept;

		int double_comparison(var const&, var const&) noexcept;

		int long_double_comparison(var const&, var const&) noexcept;

		int string_comparison(var const&, var const&) noexcept;

		int wide_string_comparison(var const&, var const&) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		int bit8_string_comparison(var const&, var const&) noexcept;
	#endif

		int bit16_string_comparison(var const&, var const&) noexcept;

		int bit32_string_comparison(var const&, var const&) noexcept;

#endif

		int pointer_comparison(var const&, var const&) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		int array_comparison(var const&, var const&) noexcept;

		int subroutine_comparison(var const&, var const&) noexcept;

		int function_comparison(var const&, var const&) noexcept;

#endif
#if (__cplusplus >= 201103L)

		int null_comparison(var const&, var const&) noexcept;

#endif


		/// \brief Helper struct to contain behaviour of each type.
		///
		///	Contains function pointers that individually determine
		///	the behaviour of any given fundamental type interacting
		/// with another.
		class type_behaviour final
		{
		public:
#if __cplusplus < 201103L

			/// \brief This horribleness brought to you by C++98.
			///
			///
			///
			type_behaviour() noexcept
			{
				rank                  = enum_void_pointer_type;
				deallocate            = stack_deallocate;
				as_boolean            = pointer_as_boolean;
				as_character          = pointer_as_character;
				as_signed_character   = pointer_as_signed_character;
				as_unsigned_character = pointer_as_unsigned_character;
	#ifndef LIBLETLIB_FREESTANDING
				as_wide_character = pointer_as_wide_character;
	#endif
				as_short            = pointer_as_short;
				as_unsigned_short   = pointer_as_unsigned_short;
				as_integer          = pointer_as_integer;
				as_unsigned_integer = pointer_as_unsigned_integer;
				as_long             = pointer_as_long;
				as_unsigned_long    = pointer_as_unsigned_long;
				as_float            = pointer_as_float;
				as_double           = pointer_as_double;
				as_long_double      = pointer_as_long_double;
	#ifndef LIBLETLIB_FREESTANDING
				as_string      = pointer_as_string;
				as_wide_string = pointer_as_wide_string;
	#endif
				as_pointer = pointer_as_pointer;
	#ifndef LIBLETLIB_FREESTANDING
				as_subroutine = pointer_as_subroutine;
				as_function   = pointer_as_function;
				as_array      = pointer_as_array;
	#endif
				positive    = pointer_positive;
				negative    = pointer_negative;
				complement  = pointer_complement;
				increment   = pointer_increment;
				decrement   = pointer_decrement;
				negation    = pointer_negation;
				indirection = pointer_indirection;
	#ifndef LIBLETLIB_FREESTANDING
				index = pointer_index;
	#endif
				subtraction    = pointer_subtraction;
				sum            = pointer_sum;
				multiplication = pointer_multiplication;
				division       = pointer_division;
				exponentiation = pointer_exponentiation;
				modulo         = pointer_modulo;
				binary_and     = pointer_binary_and;
				binary_or      = pointer_binary_or;
				binary_xor     = pointer_binary_xor;
				comparison     = pointer_comparison;
			}
#else

			type_behaviour() noexcept
			{
				rank                  = enum_nullptr_type;
				deallocate            = stack_deallocate;
				as_boolean            = null_as_boolean;
				as_character          = null_as_character;
				as_signed_character   = null_as_signed_character;
				as_unsigned_character = null_as_unsigned_character;
	#ifndef LIBLETLIB_FREESTANDING
				as_wide_character     = null_as_wide_character;
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
				as_bit8_character     = null_as_bit8_character;
			#endif
				as_bit16_character    = null_as_bit16_character;
				as_bit32_character    = null_as_bit32_character;
		#endif
	#endif
				as_short              = null_as_short;
				as_unsigned_short     = null_as_unsigned_short;
				as_integer            = null_as_integer;
				as_unsigned_integer   = null_as_unsigned_integer;
				as_long               = null_as_long;
				as_unsigned_long      = null_as_unsigned_long;
				as_long_long          = null_as_long_long;
				as_unsigned_long_long = null_as_unsigned_long_long;
				as_float              = null_as_float;
				as_double             = null_as_double;
				as_long_double        = null_as_long_double;
	#ifndef LIBLETLIB_FREESTANDING
				as_string             = null_as_string;
				as_wide_string        = null_as_wide_string;
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
				as_bit8_string        = null_as_bit8_string;
			#endif
				as_bit16_string       = null_as_bit16_string;
				as_bit32_string       = null_as_bit32_string;
		#endif
	#endif
				as_pointer            = null_as_pointer;
	#ifndef LIBLETLIB_FREESTANDING
				as_subroutine         = null_as_subroutine;
				as_function           = null_as_function;
				as_array              = null_as_array;
	#endif
				as_null               = null_as_null;
				positive              = null_positive;
				negative              = null_negative;
				complement            = null_complement;
				increment             = null_increment;
				decrement             = null_decrement;
				negation              = null_negation;
				indirection           = null_indirection;
	#ifndef LIBLETLIB_FREESTANDING
				index                 = null_index;
	#endif
				subtraction           = null_subtraction;
				sum                   = null_sum;
				multiplication        = null_multiplication;
				division              = null_division;
				exponentiation        = null_exponentiation;
				modulo                = null_modulo;
				binary_and            = null_binary_and;
				binary_or             = null_binary_or;
				binary_xor            = null_binary_xor;
				comparison            = null_comparison;
			}

#endif

			/// \brief This horribleness brought to you by C++98.
			type_behaviour(enum rank_enumeration _rank, void (*_deallocate)(var const&),
			               bool (*_as_boolean)(var const&), char (*_as_character)(var const&),
			               signed char (*_as_signed_character)(var const&),
			               unsigned char (*_as_unsigned_character)(var const&),
#ifndef LIBLETLIB_FREESTANDING
			               wchar_t (*_as_wide_character)(var const&),
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			               char8_t (*_as_bit8_character)(var const&),
		#endif
			               char16_t (*_as_bit16_character)(var const&), char32_t (*_as_bit32_character)(var const&),
	#endif
#endif
			               short (*_as_short)(var const&), unsigned short (*_as_unsigned_short)(var const&),
			               int (*_as_integer)(var const&), unsigned (*_as_unsigned_integer)(var const&),
			               long (*_as_long)(var const&), unsigned long (*_as_unsigned_long)(var const&),
#if (__cplusplus >= 201103L)
			               long long (*_as_long_long)(var const&),
			               unsigned long long (*_as_unsigned_long_long)(var const&),
#endif
			               float (*_as_float)(var const&), double (*_as_double)(var const&),
			               long double (*_as_long_double)(var const&),
#ifndef LIBLETLIB_FREESTANDING
			               char* (*_as_string)(var const&), wchar_t* (*_as_wide_string)(var const&),
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			               char8_t* (*_as_bit8_string)(var const&),
		#endif
			               char16_t* (*_as_bit16_string)(var const&), char32_t* (*_as_bit32_string)(var const&),
	#endif
#endif
			               void* (*_as_pointer)(var const&),
#ifndef LIBLETLIB_FREESTANDING
			               subroutine_t (*_as_subroutine)(var const&), function_t (*_as_function)(var const&),
			               var (*_as_array)(var const&),
#endif
#if (__cplusplus >= 201103L)
			               std::nullptr_t (*_as_null)(var const&),
#endif
			               var (*_positive)(var const&), var (*_negative)(var const&), var (*_complement)(var const&),
			               var (*_increment)(var const&), var (*_decrement)(var const&), var (*_negation)(var const&),
			               var (*_indirection)(var const&),
#ifndef LIBLETLIB_FREESTANDING
			               var (*_index)(var const&, var const&),
#endif
			               var (*_subtraction)(var const&, var const&), var (*_sum)(var const&, var const&),
			               var (*_multiplication)(var const&, var const&), var (*_division)(var const&, var const&),
			               var (*_exponentiation)(var const&, var const&), var (*_modulo)(var const&, var const&),
			               var (*_binary_and)(var const&, var const&), var (*_binary_or)(var const&, var const&),
			               var (*_binary_xor)(var const&, var const&),
			               int (*_comparison)(var const&, var const&)) noexcept
			{
				rank                  = _rank;
				deallocate            = _deallocate;
				as_boolean            = _as_boolean;
				as_character          = _as_character;
				as_signed_character   = _as_signed_character;
				as_unsigned_character = _as_unsigned_character;
#ifndef LIBLETLIB_FREESTANDING
				as_wide_character = _as_wide_character;
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
				as_bit8_character = _as_bit8_character;
		#endif
				as_bit16_character = _as_bit16_character;
				as_bit32_character = _as_bit32_character;
	#endif
#endif
				as_short            = _as_short;
				as_unsigned_short   = _as_unsigned_short;
				as_integer          = _as_integer;
				as_unsigned_integer = _as_unsigned_integer;
				as_long             = _as_long;
				as_unsigned_long    = _as_unsigned_long;
#if (__cplusplus >= 201103L)
				as_long_long          = _as_long_long;
				as_unsigned_long_long = _as_unsigned_long_long;
#endif
				as_float       = _as_float;
				as_double      = _as_double;
				as_long_double = _as_long_double;
#ifndef LIBLETLIB_FREESTANDING
				as_string      = _as_string;
				as_wide_string = _as_wide_string;
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
				as_bit8_string = _as_bit8_string;
		#endif
				as_bit16_string = _as_bit16_string;
				as_bit32_string = _as_bit32_string;
	#endif
#endif
				as_pointer = _as_pointer;
#ifndef LIBLETLIB_FREESTANDING
				as_subroutine = _as_subroutine;
				as_function   = _as_function;
				as_array      = _as_array;
#endif
#if (__cplusplus >= 201103L)
				as_null = _as_null;
#endif
				positive    = _positive;
				negative    = _negative;
				complement  = _complement;
				increment   = _increment;
				decrement   = _decrement;
				negation    = _negation;
				indirection = _indirection;
#ifndef LIBLETLIB_FREESTANDING
				index = _index;
#endif
				subtraction    = _subtraction;
				sum            = _sum;
				multiplication = _multiplication;
				division       = _division;
				exponentiation = _exponentiation;
				modulo         = _modulo;
				binary_and     = _binary_and;
				binary_or      = _binary_or;
				binary_xor     = _binary_xor;
				comparison     = _comparison;
			}

			void (*deallocate)(var const&);                    ///< Deallocation function.
			bool (*as_boolean)(var const&);                    ///< bool conversion function.
			char (*as_character)(var const&);                  ///< char conversion function.
			signed char (*as_signed_character)(var const&);    ///< signed char conversion function.
			unsigned char (*as_unsigned_character)(var const&);///< unsigned char conversion function.
#ifndef LIBLETLIB_FREESTANDING

			wchar_t (*as_wide_character)(var const&);///< wchar_t conversion function.
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			char8_t (*as_bit8_character)(var const&);///< char8_t conversion function.
		#endif
			char16_t (*as_bit16_character)(var const&);///< char16_t conversion function.
			char32_t (*as_bit32_character)(var const&);///< char32_t conversion function.
	#endif
#endif

			short (*as_short)(var const&);                  ///< short conversion function.
			unsigned short (*as_unsigned_short)(var const&);///< unsigned short conversion function.
			int (*as_integer)(var const&);                  ///< int conversion function.
			unsigned (*as_unsigned_integer)(var const&);    ///< unsigned int conversion function.
			long (*as_long)(var const&);                    ///< long conversion function.
			unsigned long (*as_unsigned_long)(var const&);  ///< unsigned long conversion function.
#if (__cplusplus >= 201103L)

			long long (*as_long_long)(var const&);                  ///< long long conversion function.
			unsigned long long (*as_unsigned_long_long)(var const&);///< unsigned long long conversion function.
#endif

			float (*as_float)(var const&);            ///< float conversion function.
			double (*as_double)(var const&);          ///< double conversion function.
			long double (*as_long_double)(var const&);///< long double conversion function.
#ifndef LIBLETLIB_FREESTANDING

			char* (*as_string)(var const&);        ///< char* conversion function.
			wchar_t* (*as_wide_string)(var const&);///< wchar_t* conversion function.
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			char8_t* (*as_bit8_string)(var const&);///< char8_t* conversion function.
		#endif
			char16_t* (*as_bit16_string)(var const&);///< char16_t* conversion function.
			char32_t* (*as_bit32_string)(var const&);///< char32_t* conversion function.
	#endif
#endif

			void* (*as_pointer)(var const&);///< void* conversion function.
#ifndef LIBLETLIB_FREESTANDING

			subroutine_t (*as_subroutine)(var const&);///< subroutine conversion function.
			function_t (*as_function)(var const&);    ///< function conversion function.
			var (*as_array)(var const&);              ///< array conversion function.
#endif
#if (__cplusplus >= 201103L)
			std::nullptr_t (*as_null)(var const&);///< std::nullptr_t conversion function.
#endif

			var (*positive)(var const&);   ///< Positive operator function.
			var (*negative)(var const&);   ///< Negative operator function.
			var (*complement)(var const&); ///< Complement operator function.
			var (*increment)(var const&);  ///< Increment operator function.
			var (*decrement)(var const&);  ///< Decrement operator function.
			var (*negation)(var const&);   ///< Negation operator function.
			var (*indirection)(var const&);///< Indirection operator function.
#ifndef LIBLETLIB_FREESTANDING

			var (*index)(var const&, var const&);///< Index-of operator function.
#endif

			var (*subtraction)(var const&, var const&);   ///< Subtraction operator function.
			var (*sum)(var const&, var const&);           ///< Sum operator function.
			var (*multiplication)(var const&, var const&);///< Multiplication operator function.
			var (*division)(var const&, var const&);      ///< Division operator function.
			var (*exponentiation)(var const&, var const&);///< Exponentiation operator function.
			var (*modulo)(var const&, var const&);        ///< Modulo operator function.
			var (*binary_and)(var const&, var const&);    ///< Binary and operator function.
			var (*binary_or)(var const&, var const&);     ///< Binary or operator function.
			var (*binary_xor)(var const&, var const&);    ///< Binary xor operator function.
			int (*comparison)(var const&, var const&);    ///< Comparison operator function.
			enum rank_enumeration rank;                   ///< Rank of this behaviour.
		};

		/// \brief Helper struct to contain behaviour of bool type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const boolean_behaviour = type_behaviour(
		    enum_bool_type, stack_deallocate, boolean_as_boolean, boolean_as_character, boolean_as_signed_character,
		    boolean_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		    boolean_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    boolean_as_bit8_character,
		#endif
		    boolean_as_bit16_character, boolean_as_bit32_character,
	#endif
#endif
		    boolean_as_short, boolean_as_unsigned_short, boolean_as_integer, boolean_as_unsigned_integer,
		    boolean_as_long, boolean_as_unsigned_long,
#if (__cplusplus >= 201103L)
		    boolean_as_long_long, boolean_as_unsigned_long_long,
#endif
		    boolean_as_float, boolean_as_double, boolean_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		    boolean_as_string, boolean_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    boolean_as_bit8_string,
		#endif
		    boolean_as_bit16_string, boolean_as_bit32_string,
	#endif
#endif
		    boolean_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		    boolean_as_subroutine, boolean_as_function, boolean_as_array,
#endif
#if (__cplusplus >= 201103L)
		    boolean_as_null,
#endif
		    boolean_positive, boolean_negative, boolean_complement, boolean_increment, boolean_decrement,
		    boolean_negation, boolean_indirection,
#ifndef LIBLETLIB_FREESTANDING
		    boolean_index,
#endif
		    boolean_subtraction, boolean_sum, boolean_multiplication, boolean_division, boolean_exponentiation,
		    boolean_modulo, boolean_binary_and, boolean_binary_or, boolean_binary_xor, boolean_comparison);

		/// \brief Helper struct to contain behaviour of char type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const character_behaviour =
		    type_behaviour(enum_char_type, stack_deallocate, character_as_boolean, character_as_character,
		                   character_as_signed_character, character_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		                   character_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		                   character_as_bit8_character,
		#endif
		                   character_as_bit16_character, character_as_bit32_character,
	#endif
#endif
		                   character_as_short, character_as_unsigned_short, character_as_integer,
		                   character_as_unsigned_integer, character_as_long, character_as_unsigned_long,
#if (__cplusplus >= 201103L)
		                   character_as_long_long, character_as_unsigned_long_long,
#endif
		                   character_as_float, character_as_double, character_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		                   character_as_string, character_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		                   character_as_bit8_string,
		#endif
		                   character_as_bit16_string, character_as_bit32_string,
	#endif
#endif
		                   character_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		                   character_as_subroutine, character_as_function, character_as_array,
#endif
#if (__cplusplus >= 201103L)
		                   character_as_null,
#endif
		                   character_positive, character_negative, character_complement, character_increment,
		                   character_decrement, character_negation, character_indirection,
#ifndef LIBLETLIB_FREESTANDING
		                   character_index,
#endif
		                   character_subtraction, character_sum, character_multiplication, character_division,
		                   character_exponentiation, character_modulo, character_binary_and, character_binary_or,
		                   character_binary_xor, character_comparison);

		/// \brief Helper struct to contain behaviour of signed char type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const signed_character_behaviour = type_behaviour(
		    enum_signed_char_type, stack_deallocate, signed_character_as_boolean, signed_character_as_character,
		    signed_character_as_signed_character, signed_character_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		    signed_character_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    signed_character_as_bit8_character,
		#endif
		    signed_character_as_bit16_character, signed_character_as_bit32_character,
	#endif
#endif
		    signed_character_as_short, signed_character_as_unsigned_short, signed_character_as_integer,
		    signed_character_as_unsigned_integer, signed_character_as_long, signed_character_as_unsigned_long,
#if (__cplusplus >= 201103L)
		    signed_character_as_long_long, signed_character_as_unsigned_long_long,
#endif
		    signed_character_as_float, signed_character_as_double, signed_character_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		    signed_character_as_string, signed_character_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    signed_character_as_bit8_string,
		#endif
		    signed_character_as_bit16_string, signed_character_as_bit32_string,
	#endif
#endif
		    signed_character_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		    signed_character_as_subroutine, signed_character_as_function, signed_character_as_array,
#endif
#if (__cplusplus >= 201103L)
		    signed_character_as_null,
#endif
		    signed_character_positive, signed_character_negative, signed_character_complement,
		    signed_character_increment, signed_character_decrement, signed_character_negation,
		    signed_character_indirection,
#ifndef LIBLETLIB_FREESTANDING
		    signed_character_index,
#endif
		    signed_character_subtraction, signed_character_sum, signed_character_multiplication,
		    signed_character_division, signed_character_exponentiation, signed_character_modulo,
		    signed_character_binary_and, signed_character_binary_or, signed_character_binary_xor,
		    signed_character_comparison);

		/// \brief Helper struct to contain behaviour of unsigned char type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const unsigned_character_behaviour = type_behaviour(
		    enum_unsigned_char_type, stack_deallocate, unsigned_character_as_boolean, unsigned_character_as_character,
		    unsigned_character_as_signed_character, unsigned_character_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_character_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    unsigned_character_as_bit8_character,
		#endif
		    unsigned_character_as_bit16_character, unsigned_character_as_bit32_character,
	#endif
#endif
		    unsigned_character_as_short, unsigned_character_as_unsigned_short, unsigned_character_as_integer,
		    unsigned_character_as_unsigned_integer, unsigned_character_as_long, unsigned_character_as_unsigned_long,
#if (__cplusplus >= 201103L)
		    unsigned_character_as_long_long, unsigned_character_as_unsigned_long_long,
#endif
		    unsigned_character_as_float, unsigned_character_as_double, unsigned_character_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_character_as_string, unsigned_character_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    unsigned_character_as_bit8_string,
		#endif
		    unsigned_character_as_bit16_string, unsigned_character_as_bit32_string,
	#endif
#endif
		    unsigned_character_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_character_as_subroutine, unsigned_character_as_function, unsigned_character_as_array,
#endif
#if (__cplusplus >= 201103L)
		    unsigned_character_as_null,
#endif
		    unsigned_character_positive, unsigned_character_negative, unsigned_character_complement,
		    unsigned_character_increment, unsigned_character_decrement, unsigned_character_negation,
		    unsigned_character_indirection,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_character_index,
#endif
		    unsigned_character_subtraction, unsigned_character_sum, unsigned_character_multiplication,
		    unsigned_character_division, unsigned_character_exponentiation, unsigned_character_modulo,
		    unsigned_character_binary_and, unsigned_character_binary_or, unsigned_character_binary_xor,
		    unsigned_character_comparison);

#ifndef LIBLETLIB_FREESTANDING
		/// \brief Helper struct to contain behaviour of wchar_t type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const wide_character_behaviour = type_behaviour(
		    enum_wchar_type, stack_deallocate, wide_character_as_boolean, wide_character_as_character,
		    wide_character_as_signed_character, wide_character_as_unsigned_character, wide_character_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    wide_character_as_bit8_character,
		#endif
		    wide_character_as_bit16_character, wide_character_as_bit32_character,
	#endif
		    wide_character_as_short, wide_character_as_unsigned_short, wide_character_as_integer,
		    wide_character_as_unsigned_integer, wide_character_as_long, wide_character_as_unsigned_long,
	#if (__cplusplus >= 201103L)
		    wide_character_as_long_long, wide_character_as_unsigned_long_long,
	#endif
		    wide_character_as_float, wide_character_as_double, wide_character_as_long_double, wide_character_as_string,
		    wide_character_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    wide_character_as_bit8_string,
		#endif
		    wide_character_as_bit16_string, wide_character_as_bit32_string,
	#endif
		    wide_character_as_pointer,
	#ifndef LIBLETLIB_FREESTANDING
		    wide_character_as_subroutine, wide_character_as_function, wide_character_as_array,
	#endif
	#if (__cplusplus >= 201103L)
		    wide_character_as_null,
	#endif
		    wide_character_positive, wide_character_negative, wide_character_complement, wide_character_increment,
		    wide_character_decrement, wide_character_negation, wide_character_indirection, wide_character_index,
		    wide_character_subtraction, wide_character_sum, wide_character_multiplication, wide_character_division,
		    wide_character_exponentiation, wide_character_modulo, wide_character_binary_and, wide_character_binary_or,
		    wide_character_binary_xor, wide_character_comparison);

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Helper struct to contain behaviour of char16_t type.
		///
		///	See description for behaviour_s struct.
		const type_behaviour bit8_character_behaviour = type_behaviour(
		    enum_char8_type, stack_deallocate, bit8_character_as_boolean, bit8_character_as_character,
		    bit8_character_as_signed_character, bit8_character_as_unsigned_character, bit8_character_as_wide_character,
		    bit8_character_as_bit8_character, bit8_character_as_bit16_character, bit8_character_as_bit32_character,
		    bit8_character_as_short, bit8_character_as_unsigned_short, bit8_character_as_integer,
		    bit8_character_as_unsigned_integer, bit8_character_as_long, bit8_character_as_unsigned_long,
		    bit8_character_as_long_long, bit8_character_as_unsigned_long_long, bit8_character_as_float,
		    bit8_character_as_double, bit8_character_as_long_double, bit8_character_as_string,
		    bit8_character_as_wide_string, bit8_character_as_bit8_string, bit8_character_as_bit16_string,
		    bit8_character_as_bit32_string, bit8_character_as_pointer, bit8_character_as_subroutine,
		    bit8_character_as_function, bit8_character_as_array, bit8_character_as_null, bit8_character_positive,
		    bit8_character_negative, bit8_character_complement, bit8_character_increment, bit8_character_decrement,
		    bit8_character_negation, bit8_character_indirection, bit8_character_index, bit8_character_subtraction,
		    bit8_character_sum, bit8_character_multiplication, bit8_character_division, bit8_character_exponentiation,
		    bit8_character_modulo, bit8_character_binary_and, bit8_character_binary_or, bit8_character_binary_xor,
		    bit8_character_comparison);
		#endif

		/// \brief Helper struct to contain behaviour of char16_t type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const bit16_character_behaviour = type_behaviour(
		    enum_char16_type, stack_deallocate, bit16_character_as_boolean, bit16_character_as_character,
		    bit16_character_as_signed_character, bit16_character_as_unsigned_character,
		    bit16_character_as_wide_character,
		#if (__cplusplus >= 202002L)
		    bit16_character_as_bit8_character,
		#endif
		    bit16_character_as_bit16_character, bit16_character_as_bit32_character, bit16_character_as_short,
		    bit16_character_as_unsigned_short, bit16_character_as_integer, bit16_character_as_unsigned_integer,
		    bit16_character_as_long, bit16_character_as_unsigned_long, bit16_character_as_long_long,
		    bit16_character_as_unsigned_long_long, bit16_character_as_float, bit16_character_as_double,
		    bit16_character_as_long_double, bit16_character_as_string, bit16_character_as_wide_string,
		#if (__cplusplus >= 202002L)
		    bit16_character_as_bit8_string,
		#endif
		    bit16_character_as_bit16_string, bit16_character_as_bit32_string, bit16_character_as_pointer,
		    bit16_character_as_subroutine, bit16_character_as_function, bit16_character_as_array,
		    bit16_character_as_null, bit16_character_positive, bit16_character_negative, bit16_character_complement,
		    bit16_character_increment, bit16_character_decrement, bit16_character_negation, bit16_character_indirection,
		    bit16_character_index, bit16_character_subtraction, bit16_character_sum, bit16_character_multiplication,
		    bit16_character_division, bit16_character_exponentiation, bit16_character_modulo,
		    bit16_character_binary_and, bit16_character_binary_or, bit16_character_binary_xor,
		    bit16_character_comparison);

		/// \brief Helper struct to contain behaviour of char32_t type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const bit32_character_behaviour = type_behaviour(
		    enum_char32_type, stack_deallocate, bit32_character_as_boolean, bit32_character_as_character,
		    bit32_character_as_signed_character, bit32_character_as_unsigned_character,
		    bit32_character_as_wide_character,
		#if (__cplusplus >= 202002L)
		    bit32_character_as_bit8_character,
		#endif
		    bit32_character_as_bit16_character, bit32_character_as_bit32_character, bit32_character_as_short,
		    bit32_character_as_unsigned_short, bit32_character_as_integer, bit32_character_as_unsigned_integer,
		    bit32_character_as_long, bit32_character_as_unsigned_long, bit32_character_as_long_long,
		    bit32_character_as_unsigned_long_long, bit32_character_as_float, bit32_character_as_double,
		    bit32_character_as_long_double, bit32_character_as_string, bit32_character_as_wide_string,
		#if (__cplusplus >= 202002L)
		    bit32_character_as_bit8_string,
		#endif
		    bit32_character_as_bit16_string, bit32_character_as_bit32_string, bit32_character_as_pointer,
		    bit32_character_as_subroutine, bit32_character_as_function, bit32_character_as_array,
		    bit32_character_as_null, bit32_character_positive, bit32_character_negative, bit32_character_complement,
		    bit32_character_increment, bit32_character_decrement, bit32_character_negation, bit32_character_indirection,
		    bit32_character_index, bit32_character_subtraction, bit32_character_sum, bit32_character_multiplication,
		    bit32_character_division, bit32_character_exponentiation, bit32_character_modulo,
		    bit32_character_binary_and, bit32_character_binary_or, bit32_character_binary_xor,
		    bit32_character_comparison);
	#endif
#endif

		/// \brief Helper struct to contain behaviour of short type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const short_behaviour =
		    type_behaviour(enum_short_type, stack_deallocate, short_as_boolean, short_as_character,
		                   short_as_signed_character, short_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		                   short_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		                   short_as_bit8_character,
		#endif
		                   short_as_bit16_character, short_as_bit32_character,
	#endif
#endif
		                   short_as_short, short_as_unsigned_short, short_as_integer, short_as_unsigned_integer,
		                   short_as_long, short_as_unsigned_long,
#if (__cplusplus >= 201103L)
		                   short_as_long_long, short_as_unsigned_long_long,
#endif
		                   short_as_float, short_as_double, short_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		                   short_as_string, short_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		                   short_as_bit8_string,
		#endif
		                   short_as_bit16_string, short_as_bit32_string,
	#endif
#endif
		                   short_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		                   short_as_subroutine, short_as_function, short_as_array,
#endif
#if (__cplusplus >= 201103L)
		                   short_as_null,
#endif
		                   short_positive, short_negative, short_complement, short_increment, short_decrement,
		                   short_negation, short_indirection,
#ifndef LIBLETLIB_FREESTANDING
		                   short_index,
#endif
		                   short_subtraction, short_sum, short_multiplication, short_division, short_exponentiation,
		                   short_modulo, short_binary_and, short_binary_or, short_binary_xor, short_comparison);

		/// \brief Helper struct to contain behaviour of unsigned short type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const unsigned_short_behaviour = type_behaviour(
		    enum_unsigned_short_type, stack_deallocate, unsigned_short_as_boolean, unsigned_short_as_character,
		    unsigned_short_as_signed_character, unsigned_short_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_short_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    unsigned_short_as_bit8_character,
		#endif
		    unsigned_short_as_bit16_character, unsigned_short_as_bit32_character,
	#endif
#endif
		    unsigned_short_as_short, unsigned_short_as_unsigned_short, unsigned_short_as_integer,
		    unsigned_short_as_unsigned_integer, unsigned_short_as_long, unsigned_short_as_unsigned_long,
#if (__cplusplus >= 201103L)
		    unsigned_short_as_long_long, unsigned_short_as_unsigned_long_long,
#endif
		    unsigned_short_as_float, unsigned_short_as_double, unsigned_short_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_short_as_string, unsigned_short_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    unsigned_short_as_bit8_string,
		#endif
		    unsigned_short_as_bit16_string, unsigned_short_as_bit32_string,
	#endif
#endif
		    unsigned_short_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_short_as_subroutine, unsigned_short_as_function, unsigned_short_as_array,
#endif
#if (__cplusplus >= 201103L)
		    unsigned_short_as_null,
#endif
		    unsigned_short_positive, unsigned_short_negative, unsigned_short_complement, unsigned_short_increment,
		    unsigned_short_decrement, unsigned_short_negation, unsigned_short_indirection,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_short_index,
#endif
		    unsigned_short_subtraction, unsigned_short_sum, unsigned_short_multiplication, unsigned_short_division,
		    unsigned_short_exponentiation, unsigned_short_modulo, unsigned_short_binary_and, unsigned_short_binary_or,
		    unsigned_short_binary_xor, unsigned_short_comparison);

		/// \brief Helper struct to contain behaviour of int type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const integer_behaviour = type_behaviour(
		    enum_int_type, stack_deallocate, integer_as_boolean, integer_as_character, integer_as_signed_character,
		    integer_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		    integer_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    integer_as_bit8_character,
		#endif
		    integer_as_bit16_character, integer_as_bit32_character,
	#endif
#endif
		    integer_as_short, integer_as_unsigned_short, integer_as_integer, integer_as_unsigned_integer,
		    integer_as_long, integer_as_unsigned_long,
#if (__cplusplus >= 201103L)
		    integer_as_long_long, integer_as_unsigned_long_long,
#endif
		    integer_as_float, integer_as_double, integer_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		    integer_as_string, integer_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    integer_as_bit8_string,
		#endif
		    integer_as_bit16_string, integer_as_bit32_string,
	#endif
#endif
		    integer_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		    integer_as_subroutine, integer_as_function, integer_as_array,
#endif
#if (__cplusplus >= 201103L)
		    integer_as_null,
#endif
		    integer_positive, integer_negative, integer_complement, integer_increment, integer_decrement,
		    integer_negation, integer_indirection,
#ifndef LIBLETLIB_FREESTANDING
		    integer_index,
#endif
		    integer_subtraction, integer_sum, integer_multiplication, integer_division, integer_exponentiation,
		    integer_modulo, integer_binary_and, integer_binary_or, integer_binary_xor, integer_comparison);

		/// \brief Helper struct to contain behaviour of unsigned int type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const unsigned_integer_behaviour = type_behaviour(
		    enum_unsigned_int_type, stack_deallocate, unsigned_integer_as_boolean, unsigned_integer_as_character,
		    unsigned_integer_as_signed_character, unsigned_integer_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_integer_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    unsigned_integer_as_bit8_character,
		#endif
		    unsigned_integer_as_bit16_character, unsigned_integer_as_bit32_character,
	#endif
#endif
		    unsigned_integer_as_short, unsigned_integer_as_unsigned_short, unsigned_integer_as_integer,
		    unsigned_integer_as_unsigned_integer, unsigned_integer_as_long, unsigned_integer_as_unsigned_long,
#if (__cplusplus >= 201103L)
		    unsigned_integer_as_long_long, unsigned_integer_as_unsigned_long_long,
#endif
		    unsigned_integer_as_float, unsigned_integer_as_double, unsigned_integer_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_integer_as_string, unsigned_integer_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    unsigned_integer_as_bit8_string,
		#endif
		    unsigned_integer_as_bit16_string, unsigned_integer_as_bit32_string,
	#endif
#endif
		    unsigned_integer_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_integer_as_subroutine, unsigned_integer_as_function, unsigned_integer_as_array,
#endif
#if (__cplusplus >= 201103L)
		    unsigned_integer_as_null,
#endif
		    unsigned_integer_positive, unsigned_integer_negative, unsigned_integer_complement,
		    unsigned_integer_increment, unsigned_integer_decrement, unsigned_integer_negation,
		    unsigned_integer_indirection,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_integer_index,
#endif
		    unsigned_integer_subtraction, unsigned_integer_sum, unsigned_integer_multiplication,
		    unsigned_integer_division, unsigned_integer_exponentiation, unsigned_integer_modulo,
		    unsigned_integer_binary_and, unsigned_integer_binary_or, unsigned_integer_binary_xor,
		    unsigned_integer_comparison);

		/// \brief Helper struct to contain behaviour of long type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const long_behaviour =
		    type_behaviour(enum_long_type, stack_deallocate, long_as_boolean, long_as_character,
		                   long_as_signed_character, long_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		                   long_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		                   long_as_bit8_character,
		#endif
		                   long_as_bit16_character, long_as_bit32_character,
	#endif
#endif
		                   long_as_short, long_as_unsigned_short, long_as_integer, long_as_unsigned_integer,
		                   long_as_long, long_as_unsigned_long,
#if (__cplusplus >= 201103L)
		                   long_as_long_long, long_as_unsigned_long_long,
#endif
		                   long_as_float, long_as_double, long_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		                   long_as_string, long_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		                   long_as_bit8_string,
		#endif
		                   long_as_bit16_string, long_as_bit32_string,
	#endif
#endif
		                   long_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		                   long_as_subroutine, long_as_function, long_as_array,
#endif
#if (__cplusplus >= 201103L)
		                   long_as_null,
#endif
		                   long_positive, long_negative, long_complement, long_increment, long_decrement, long_negation,
		                   long_indirection,
#ifndef LIBLETLIB_FREESTANDING
		                   long_index,
#endif
		                   long_subtraction, long_sum, long_multiplication, long_division, long_exponentiation,
		                   long_modulo, long_binary_and, long_binary_or, long_binary_xor, long_comparison);

		/// \brief Helper struct to contain behaviour of unsigned long type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const unsigned_long_behaviour = type_behaviour(
		    enum_unsigned_long_type, stack_deallocate, unsigned_long_as_boolean, unsigned_long_as_character,
		    unsigned_long_as_signed_character, unsigned_long_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_long_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    unsigned_long_as_bit8_character,
		#endif
		    unsigned_long_as_bit16_character, unsigned_long_as_bit32_character,
	#endif
#endif
		    unsigned_long_as_short, unsigned_long_as_unsigned_short, unsigned_long_as_integer,
		    unsigned_long_as_unsigned_integer, unsigned_long_as_long, unsigned_long_as_unsigned_long,
#if (__cplusplus >= 201103L)
		    unsigned_long_as_long_long, unsigned_long_as_unsigned_long_long,
#endif
		    unsigned_long_as_float, unsigned_long_as_double, unsigned_long_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_long_as_string, unsigned_long_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    unsigned_long_as_bit8_string,
		#endif
		    unsigned_long_as_bit16_string, unsigned_long_as_bit32_string,
	#endif
#endif
		    unsigned_long_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_long_as_subroutine, unsigned_long_as_function, unsigned_long_as_array,
#endif
#if (__cplusplus >= 201103L)
		    unsigned_long_as_null,
#endif
		    unsigned_long_positive, unsigned_long_negative, unsigned_long_complement, unsigned_long_increment,
		    unsigned_long_decrement, unsigned_long_negation, unsigned_long_indirection,
#ifndef LIBLETLIB_FREESTANDING
		    unsigned_long_index,
#endif
		    unsigned_long_subtraction, unsigned_long_sum, unsigned_long_multiplication, unsigned_long_division,
		    unsigned_long_exponentiation, unsigned_long_modulo, unsigned_long_binary_and, unsigned_long_binary_or,
		    unsigned_long_binary_xor, unsigned_long_comparison);

#if (__cplusplus >= 201103L)

		/// \brief Helper struct to contain behaviour of long long type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const long_long_behaviour = type_behaviour(
		    enum_long_long_type, stack_deallocate, long_long_as_boolean, long_long_as_character,
		    long_long_as_signed_character, long_long_as_unsigned_character,
	#ifndef LIBLETLIB_FREESTANDING
		    long_long_as_wide_character,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		    long_long_as_bit8_character,
			#endif
		    long_long_as_bit16_character, long_long_as_bit32_character,
		#endif
	#endif
		    long_long_as_short, long_long_as_unsigned_short, long_long_as_integer, long_long_as_unsigned_integer,
		    long_long_as_long, long_long_as_unsigned_long, long_long_as_long_long, long_long_as_unsigned_long_long,
		    long_long_as_float, long_long_as_double, long_long_as_long_double,
	#ifndef LIBLETLIB_FREESTANDING
		    long_long_as_string, long_long_as_wide_string,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		    long_long_as_bit8_string,
			#endif
		    long_long_as_bit16_string, long_long_as_bit32_string,
		#endif
	#endif
		    long_long_as_pointer,
	#ifndef LIBLETLIB_FREESTANDING
		    long_long_as_subroutine, long_long_as_function,
	#endif
	#ifndef LIBLETLIB_FREESTANDING
		    long_long_as_array,
	#endif
		    long_long_as_null, long_long_positive, long_long_negative, long_long_complement, long_long_increment,
		    long_long_decrement, long_long_negation, long_long_indirection,
	#ifndef LIBLETLIB_FREESTANDING
		    long_long_index,
	#endif
		    long_long_subtraction, long_long_sum, long_long_multiplication, long_long_division,
		    long_long_exponentiation, long_long_modulo, long_long_binary_and, long_long_binary_or, long_long_binary_xor,
		    long_long_comparison);

		/// \brief Helper struct to contain behaviour of unsigned long long type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const unsigned_long_long_behaviour = type_behaviour(
		    enum_unsigned_long_long_type, stack_deallocate, unsigned_long_long_as_boolean,
		    unsigned_long_long_as_character, unsigned_long_long_as_signed_character,
		    unsigned_long_long_as_unsigned_character,
	#ifndef LIBLETLIB_FREESTANDING
		    unsigned_long_long_as_wide_character,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		    unsigned_long_long_as_bit8_character,
			#endif
		    unsigned_long_long_as_bit16_character, unsigned_long_long_as_bit32_character,
		#endif
	#endif
		    unsigned_long_long_as_short, unsigned_long_long_as_unsigned_short, unsigned_long_long_as_integer,
		    unsigned_long_long_as_unsigned_integer, unsigned_long_long_as_long, unsigned_long_long_as_unsigned_long,
		    unsigned_long_long_as_long_long, unsigned_long_long_as_unsigned_long_long, unsigned_long_long_as_float,
		    unsigned_long_long_as_double, unsigned_long_long_as_long_double,
	#ifndef LIBLETLIB_FREESTANDING
		    unsigned_long_long_as_string, unsigned_long_long_as_wide_string,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		    unsigned_long_long_as_bit8_string,
			#endif
		    unsigned_long_long_as_bit16_string, unsigned_long_long_as_bit32_string,
		#endif
	#endif
		    unsigned_long_long_as_pointer,
	#ifndef LIBLETLIB_FREESTANDING
		    unsigned_long_long_as_subroutine, unsigned_long_long_as_function,
	#endif
	#ifndef LIBLETLIB_FREESTANDING
		    unsigned_long_long_as_array,
	#endif
		    unsigned_long_long_as_null, unsigned_long_long_positive, unsigned_long_long_negative,
		    unsigned_long_long_complement, unsigned_long_long_increment, unsigned_long_long_decrement,
		    unsigned_long_long_negation, unsigned_long_long_indirection,
	#ifndef LIBLETLIB_FREESTANDING
		    unsigned_long_long_index,
	#endif
		    unsigned_long_long_subtraction, unsigned_long_long_sum, unsigned_long_long_multiplication,
		    unsigned_long_long_division, unsigned_long_long_exponentiation, unsigned_long_long_modulo,
		    unsigned_long_long_binary_and, unsigned_long_long_binary_or, unsigned_long_long_binary_xor,
		    unsigned_long_long_comparison);
#endif

		/// \brief Helper struct to contain behaviour of float type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const float_behaviour =
		    type_behaviour(enum_float_type, stack_deallocate, float_as_boolean, float_as_character,
		                   float_as_signed_character, float_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		                   float_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		                   float_as_bit8_character,
		#endif
		                   float_as_bit16_character, float_as_bit32_character,
	#endif
#endif
		                   float_as_short, float_as_unsigned_short, float_as_integer, float_as_unsigned_integer,
		                   float_as_long, float_as_unsigned_long,
#if (__cplusplus >= 201103L)
		                   float_as_long_long, float_as_unsigned_long_long,
#endif
		                   float_as_float, float_as_double, float_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		                   float_as_string, float_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		                   float_as_bit8_string,
		#endif
		                   float_as_bit16_string, float_as_bit32_string,
	#endif
#endif
		                   float_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		                   float_as_subroutine, float_as_function, float_as_array,
#endif
#if (__cplusplus >= 201103L)
		                   float_as_null,
#endif
		                   float_positive, float_negative, float_complement, float_increment, float_decrement,
		                   float_negation, float_indirection,
#ifndef LIBLETLIB_FREESTANDING
		                   float_index,
#endif
		                   float_subtraction, float_sum, float_multiplication, float_division, float_exponentiation,
		                   float_modulo, float_binary_and, float_binary_or, float_binary_xor, float_comparison);

		/// \brief Helper struct to contain behaviour of double type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const double_behaviour = type_behaviour(
		    enum_double_type, stack_deallocate, double_as_boolean, double_as_character, double_as_signed_character,
		    double_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		    double_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    double_as_bit8_character,
		#endif
		    double_as_bit16_character, double_as_bit32_character,
	#endif
#endif
		    double_as_short, double_as_unsigned_short, double_as_integer, double_as_unsigned_integer, double_as_long,
		    double_as_unsigned_long,
#if (__cplusplus >= 201103L)
		    double_as_long_long, double_as_unsigned_long_long,
#endif
		    double_as_float, double_as_double, double_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		    double_as_string, double_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    double_as_bit8_string,
		#endif
		    double_as_bit16_string, double_as_bit32_string,
	#endif
#endif
		    double_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		    double_as_subroutine, double_as_function, double_as_array,
#endif
#if (__cplusplus >= 201103L)
		    double_as_null,
#endif
		    double_positive, double_negative, double_complement, double_increment, double_decrement, double_negation,
		    double_indirection,
#ifndef LIBLETLIB_FREESTANDING
		    double_index,
#endif
		    double_subtraction, double_sum, double_multiplication, double_division, double_exponentiation,
		    double_modulo, double_binary_and, double_binary_or, double_binary_xor, double_comparison);

		/// \brief Helper struct to contain behaviour of long double type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const long_double_behaviour =
		    type_behaviour(enum_long_double_type, stack_deallocate, long_double_as_boolean, long_double_as_character,
		                   long_double_as_signed_character, long_double_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		                   long_double_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		                   long_double_as_bit8_character,
		#endif
		                   long_double_as_bit16_character, long_double_as_bit32_character,
	#endif
#endif
		                   long_double_as_short, long_double_as_unsigned_short, long_double_as_integer,
		                   long_double_as_unsigned_integer, long_double_as_long, long_double_as_unsigned_long,
#if (__cplusplus >= 201103L)
		                   long_double_as_long_long, long_double_as_unsigned_long_long,
#endif
		                   long_double_as_float, long_double_as_double, long_double_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		                   long_double_as_string, long_double_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		                   long_double_as_bit8_string,
		#endif
		                   long_double_as_bit16_string, long_double_as_bit32_string,
	#endif
#endif
		                   long_double_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		                   long_double_as_subroutine, long_double_as_function, long_double_as_array,
#endif
#if (__cplusplus >= 201103L)
		                   long_double_as_null,
#endif
		                   long_double_positive, long_double_negative, long_double_complement, long_double_increment,
		                   long_double_decrement, long_double_negation, long_double_indirection,
#ifndef LIBLETLIB_FREESTANDING
		                   long_double_index,
#endif
		                   long_double_subtraction, long_double_sum, long_double_multiplication, long_double_division,
		                   long_double_exponentiation, long_double_modulo, long_double_binary_and,
		                   long_double_binary_or, long_double_binary_xor, long_double_comparison);

#ifndef LIBLETLIB_FREESTANDING
		/// \brief Helper struct to contain behaviour of raw string type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const string_behaviour = type_behaviour(
		    enum_string_type, string_deallocate, string_as_boolean, string_as_character, string_as_signed_character,
		    string_as_unsigned_character, string_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    string_as_bit8_character,
		#endif
		    string_as_bit16_character, string_as_bit32_character,
	#endif
		    string_as_short, string_as_unsigned_short, string_as_integer, string_as_unsigned_integer, string_as_long,
		    string_as_unsigned_long,
	#if (__cplusplus >= 201103L)
		    string_as_long_long, string_as_unsigned_long_long,
	#endif
		    string_as_float, string_as_double, string_as_long_double, string_as_string, string_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    string_as_bit8_string,
		#endif
		    string_as_bit16_string, string_as_bit32_string,
	#endif
		    string_as_pointer, string_as_subroutine, string_as_function, string_as_array,
	#if (__cplusplus >= 201103L)
		    string_as_null,
	#endif
		    string_positive, string_negative, string_complement, string_increment, string_decrement, string_negation,
		    string_indirection, string_index, string_subtraction, string_sum, string_multiplication, string_division,
		    string_exponentiation, string_modulo, string_binary_and, string_binary_or, string_binary_xor,
		    string_comparison);

		/// \brief Helper struct to contain behaviour of wide string type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const wide_string_behaviour = type_behaviour(
		    enum_wide_string_type, wide_string_deallocate, wide_string_as_boolean, wide_string_as_character,
		    wide_string_as_signed_character, wide_string_as_unsigned_character, wide_string_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    wide_string_as_bit8_character,
		#endif
		    wide_string_as_bit16_character, wide_string_as_bit32_character,
	#endif
		    wide_string_as_short, wide_string_as_unsigned_short, wide_string_as_integer,
		    wide_string_as_unsigned_integer, wide_string_as_long, wide_string_as_unsigned_long,
	#if (__cplusplus >= 201103L)
		    wide_string_as_long_long, wide_string_as_unsigned_long_long,
	#endif
		    wide_string_as_float, wide_string_as_double, wide_string_as_long_double, wide_string_as_string,
		    wide_string_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    wide_string_as_bit8_string,
		#endif
		    wide_string_as_bit16_string, wide_string_as_bit32_string,
	#endif
		    wide_string_as_pointer, wide_string_as_subroutine, wide_string_as_function, wide_string_as_array,
	#if (__cplusplus >= 201103L)
		    wide_string_as_null,
	#endif
		    wide_string_positive, wide_string_negative, wide_string_complement, wide_string_increment,
		    wide_string_decrement, wide_string_negation, wide_string_indirection, wide_string_index,
		    wide_string_subtraction, wide_string_sum, wide_string_multiplication, wide_string_division,
		    wide_string_exponentiation, wide_string_modulo, wide_string_binary_and, wide_string_binary_or,
		    wide_string_binary_xor, wide_string_comparison);

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Helper struct to contain behaviour of 16 bit string type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const bit8_string_behaviour = type_behaviour(
		    enum_bit8_string_type, bit8_string_deallocate, bit8_string_as_boolean, bit8_string_as_character,
		    bit8_string_as_signed_character, bit8_string_as_unsigned_character, bit8_string_as_wide_character,
		    bit8_string_as_bit8_character, bit8_string_as_bit16_character, bit8_string_as_bit32_character,
		    bit8_string_as_short, bit8_string_as_unsigned_short, bit8_string_as_integer,
		    bit8_string_as_unsigned_integer, bit8_string_as_long, bit8_string_as_unsigned_long,
		    bit8_string_as_long_long, bit8_string_as_unsigned_long_long, bit8_string_as_float, bit8_string_as_double,
		    bit8_string_as_long_double, bit8_string_as_string, bit8_string_as_wide_string, bit8_string_as_bit8_string,
		    bit8_string_as_bit16_string, bit8_string_as_bit32_string, bit8_string_as_pointer, bit8_string_as_subroutine,
		    bit8_string_as_function, bit8_string_as_array, bit8_string_as_null, bit8_string_positive,
		    bit8_string_negative, bit8_string_complement, bit8_string_increment, bit8_string_decrement,
		    bit8_string_negation, bit8_string_indirection, bit8_string_index, bit8_string_subtraction, bit8_string_sum,
		    bit8_string_multiplication, bit8_string_division, bit8_string_exponentiation, bit8_string_modulo,
		    bit8_string_binary_and, bit8_string_binary_or, bit8_string_binary_xor, bit8_string_comparison);
		#endif

		/// \brief Helper struct to contain behaviour of 16 bit string type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const bit16_string_behaviour = type_behaviour(
		    enum_bit16_string_type, bit16_string_deallocate, bit16_string_as_boolean, bit16_string_as_character,
		    bit16_string_as_signed_character, bit16_string_as_unsigned_character, bit16_string_as_wide_character,
		#if (__cplusplus >= 202002L)
		    bit16_string_as_bit8_character,
		#endif
		    bit16_string_as_bit16_character, bit16_string_as_bit32_character, bit16_string_as_short,
		    bit16_string_as_unsigned_short, bit16_string_as_integer, bit16_string_as_unsigned_integer,
		    bit16_string_as_long, bit16_string_as_unsigned_long, bit16_string_as_long_long,
		    bit16_string_as_unsigned_long_long, bit16_string_as_float, bit16_string_as_double,
		    bit16_string_as_long_double, bit16_string_as_string, bit16_string_as_wide_string,
		#if (__cplusplus >= 202002L)
		    bit16_string_as_bit8_string,
		#endif
		    bit16_string_as_bit16_string, bit16_string_as_bit32_string, bit16_string_as_pointer,
		    bit16_string_as_subroutine, bit16_string_as_function, bit16_string_as_array, bit16_string_as_null,
		    bit16_string_positive, bit16_string_negative, bit16_string_complement, bit16_string_increment,
		    bit16_string_decrement, bit16_string_negation, bit16_string_indirection, bit16_string_index,
		    bit16_string_subtraction, bit16_string_sum, bit16_string_multiplication, bit16_string_division,
		    bit16_string_exponentiation, bit16_string_modulo, bit16_string_binary_and, bit16_string_binary_or,
		    bit16_string_binary_xor, bit16_string_comparison);

		/// \brief Helper struct to contain behaviour of 32 bit string type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const bit32_string_behaviour = type_behaviour(
		    enum_bit32_string_type, bit32_string_deallocate, bit32_string_as_boolean, bit32_string_as_character,
		    bit32_string_as_signed_character, bit32_string_as_unsigned_character, bit32_string_as_wide_character,
		#if (__cplusplus >= 202002L)
		    bit32_string_as_bit8_character,
		#endif
		    bit32_string_as_bit16_character, bit32_string_as_bit32_character, bit32_string_as_short,
		    bit32_string_as_unsigned_short, bit32_string_as_integer, bit32_string_as_unsigned_integer,
		    bit32_string_as_long, bit32_string_as_unsigned_long, bit32_string_as_long_long,
		    bit32_string_as_unsigned_long_long, bit32_string_as_float, bit32_string_as_double,
		    bit32_string_as_long_double, bit32_string_as_string, bit32_string_as_wide_string,
		#if (__cplusplus >= 202002L)
		    bit32_string_as_bit8_string,
		#endif
		    bit32_string_as_bit16_string, bit32_string_as_bit32_string, bit32_string_as_pointer,
		    bit32_string_as_subroutine, bit32_string_as_function, bit32_string_as_array, bit32_string_as_null,
		    bit32_string_positive, bit32_string_negative, bit32_string_complement, bit32_string_increment,
		    bit32_string_decrement, bit32_string_negation, bit32_string_indirection, bit32_string_index,
		    bit32_string_subtraction, bit32_string_sum, bit32_string_multiplication, bit32_string_division,
		    bit32_string_exponentiation, bit32_string_modulo, bit32_string_binary_and, bit32_string_binary_or,
		    bit32_string_binary_xor, bit32_string_comparison);
	#endif
#endif

		/// \brief Helper struct to contain behaviour of void pointer type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const pointer_behaviour = type_behaviour(
		    enum_void_pointer_type, object_deallocate, pointer_as_boolean, pointer_as_character,
		    pointer_as_signed_character, pointer_as_unsigned_character,
#ifndef LIBLETLIB_FREESTANDING
		    pointer_as_wide_character,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    pointer_as_bit8_character,
		#endif
		    pointer_as_bit16_character, pointer_as_bit32_character,
	#endif
#endif
		    pointer_as_short, pointer_as_unsigned_short, pointer_as_integer, pointer_as_unsigned_integer,
		    pointer_as_long, pointer_as_unsigned_long,
#if (__cplusplus >= 201103L)
		    pointer_as_long_long, pointer_as_unsigned_long_long,
#endif
		    pointer_as_float, pointer_as_double, pointer_as_long_double,
#ifndef LIBLETLIB_FREESTANDING
		    pointer_as_string, pointer_as_wide_string,
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		    pointer_as_bit8_string,
		#endif
		    pointer_as_bit16_string, pointer_as_bit32_string,
	#endif
#endif
		    pointer_as_pointer,
#ifndef LIBLETLIB_FREESTANDING
		    pointer_as_subroutine, pointer_as_function, pointer_as_array,
#endif
#if (__cplusplus >= 201103L)
		    pointer_as_null,
#endif
		    pointer_positive, pointer_negative, pointer_complement, pointer_increment, pointer_decrement,
		    pointer_negation, pointer_indirection,
#ifndef LIBLETLIB_FREESTANDING
		    pointer_index,
#endif
		    pointer_subtraction, pointer_sum, pointer_multiplication, pointer_division, pointer_exponentiation,
		    pointer_modulo, pointer_binary_and, pointer_binary_or, pointer_binary_xor, pointer_comparison);

#ifndef LIBLETLIB_FREESTANDING
		/// \brief Helper struct to contain behaviour of var array type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const array_behaviour =
		    type_behaviour(enum_array_type, array_deallocate, array_as_boolean, array_as_character,
		                   array_as_signed_character, array_as_unsigned_character,
	#ifndef LIBLETLIB_FREESTANDING
		                   array_as_wide_character,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		                   array_as_bit8_character,
			#endif
		                   array_as_bit16_character, array_as_bit32_character,
		#endif
	#endif
		                   array_as_short, array_as_unsigned_short, array_as_integer, array_as_unsigned_integer,
		                   array_as_long, array_as_unsigned_long,
	#if (__cplusplus >= 201103L)
		                   array_as_long_long, array_as_unsigned_long_long,
	#endif
		                   array_as_float, array_as_double, array_as_long_double,
	#ifndef LIBLETLIB_FREESTANDING
		                   array_as_string, array_as_wide_string,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		                   array_as_bit8_string,
			#endif
		                   array_as_bit16_string, array_as_bit32_string,
		#endif
	#endif
		                   array_as_pointer, array_as_subroutine, array_as_function, array_as_array,
	#if (__cplusplus >= 201103L)

		                   array_as_null,
	#endif
		                   array_positive, array_negative, array_complement, array_increment, array_decrement,
		                   array_negation, array_indirection,
	#ifndef LIBLETLIB_FREESTANDING
		                   array_index,
	#endif
		                   array_subtraction, array_sum, array_multiplication, array_division, array_exponentiation,
		                   array_modulo, array_binary_and, array_binary_or, array_binary_xor, array_comparison);

		/// \brief Helper struct to contain behaviour of subroutine type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const subroutine_behaviour =
		    type_behaviour(enum_subroutine_type, stack_deallocate, subroutine_as_boolean, subroutine_as_character,
		                   subroutine_as_signed_character, subroutine_as_unsigned_character,
	#ifndef LIBLETLIB_FREESTANDING
		                   subroutine_as_wide_character,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		                   subroutine_as_bit8_character,
			#endif
		                   subroutine_as_bit16_character, subroutine_as_bit32_character,
		#endif
	#endif
		                   subroutine_as_short, subroutine_as_unsigned_short, subroutine_as_integer,
		                   subroutine_as_unsigned_integer, subroutine_as_long, subroutine_as_unsigned_long,
	#if (__cplusplus >= 201103L)
		                   subroutine_as_long_long, subroutine_as_unsigned_long_long,
	#endif
		                   subroutine_as_float, subroutine_as_double, subroutine_as_long_double,
	#ifndef LIBLETLIB_FREESTANDING
		                   subroutine_as_string, subroutine_as_wide_string,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		                   subroutine_as_bit8_string,
			#endif
		                   subroutine_as_bit16_string, subroutine_as_bit32_string,
		#endif
	#endif
		                   subroutine_as_pointer, subroutine_as_subroutine, subroutine_as_function, subroutine_as_array,
	#if (__cplusplus >= 201103L)
		                   subroutine_as_null,
	#endif
		                   subroutine_positive, subroutine_negative, subroutine_complement, subroutine_increment,
		                   subroutine_decrement, subroutine_negation, subroutine_indirection,
	#ifndef LIBLETLIB_FREESTANDING
		                   subroutine_index,
	#endif
		                   subroutine_subtraction, subroutine_sum, subroutine_multiplication, subroutine_division,
		                   subroutine_exponentiation, subroutine_modulo, subroutine_binary_and, subroutine_binary_or,
		                   subroutine_binary_xor, subroutine_comparison);

		/// \brief Helper struct to contain behaviour of function type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const function_behaviour = type_behaviour(
		    enum_function_type, stack_deallocate, function_as_boolean, function_as_character,
		    function_as_signed_character, function_as_unsigned_character,
	#ifndef LIBLETLIB_FREESTANDING
		    function_as_wide_character,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		    function_as_bit8_character,
			#endif
		    function_as_bit16_character, function_as_bit32_character,
		#endif
	#endif
		    function_as_short, function_as_unsigned_short, function_as_integer, function_as_unsigned_integer,
		    function_as_long, function_as_unsigned_long,
	#if (__cplusplus >= 201103L)
		    function_as_long_long, function_as_unsigned_long_long,
	#endif
		    function_as_float, function_as_double, function_as_long_double,
	#ifndef LIBLETLIB_FREESTANDING
		    function_as_string, function_as_wide_string,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		    function_as_bit8_string,
			#endif
		    function_as_bit16_string, function_as_bit32_string,
		#endif
	#endif
		    function_as_pointer, function_as_subroutine, subroutine_as_function, function_as_array,
	#if (__cplusplus >= 201103L)
		    function_as_null,
	#endif
		    function_positive, function_negative, function_complement, function_increment, function_decrement,
		    function_negation, function_indirection,
	#ifndef LIBLETLIB_FREESTANDING
		    function_index,
	#endif
		    function_subtraction, function_sum, function_multiplication, function_division, function_exponentiation,
		    function_modulo, function_binary_and, function_binary_or, function_binary_xor, function_comparison);
#endif
#if (__cplusplus >= 201103L)
		/// \brief Helper struct to contain behaviour of nullptr_t type.
		///
		///	See description for behaviour_s struct.
		type_behaviour const null_behaviour =
		    type_behaviour(enum_nullptr_type, stack_deallocate, null_as_boolean, null_as_character,
		                   null_as_signed_character, null_as_unsigned_character,
	#ifndef LIBLETLIB_FREESTANDING
		                   null_as_wide_character,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		                   null_as_bit8_character,
			#endif
		                   null_as_bit16_character, null_as_bit32_character,
		#endif
	#endif
		                   null_as_short, null_as_unsigned_short, null_as_integer, null_as_unsigned_integer,
		                   null_as_long, null_as_unsigned_long, null_as_long_long, null_as_unsigned_long_long,
		                   null_as_float, null_as_double, null_as_long_double,
	#ifndef LIBLETLIB_FREESTANDING
		                   null_as_string, null_as_wide_string,
		#ifndef LIBLETLIB_DISABLE_UCHAR
			#if (__cplusplus >= 202002L)
		                   null_as_bit8_string,
			#endif
		                   null_as_bit16_string, null_as_bit32_string,
		#endif
	#endif
		                   null_as_pointer,
	#ifndef LIBLETLIB_FREESTANDING
		                   null_as_subroutine, null_as_function, null_as_array,
	#endif
		                   null_as_null, null_positive, null_negative, null_complement, null_increment, null_decrement,
		                   null_negation, null_indirection,
	#ifndef LIBLETLIB_FREESTANDING
		                   null_index,
	#endif
		                   null_subtraction, null_sum, null_multiplication, null_division, null_exponentiation,
		                   null_modulo, null_binary_and, null_binary_or, null_binary_xor, null_comparison);
#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_BEHAVIOUR_HPP
