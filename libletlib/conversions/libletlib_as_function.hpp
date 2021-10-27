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

#ifndef LIBLETLIB_LIBLETLIB_AS_FUNCTION_HPP
#define LIBLETLIB_LIBLETLIB_AS_FUNCTION_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Function to return function value of previous bool type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t boolean_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous char type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t character_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous signed char type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t signed_character_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of an unsigned char type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t unsigned_character_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous wchar_t type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t wide_character_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		/// \brief Function to return function value of previous char8_t type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t bit8_character_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
		#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
		#endif
		}
	#endif

		/// \brief Function to return function value of previous char16_t type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t bit16_character_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
	#endif
		}

		/// \brief Function to return function value of previous char32_t type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t bit32_character_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
	#endif
		}

#endif

		/// \brief Function to return function value of previous short type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t short_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of an unsigned short type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t unsigned_short_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of an int type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t integer_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of an unsigned int type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t unsigned_integer_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous long type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t long_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of an unsigned long type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t unsigned_long_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous long long type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t long_long_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of an unsigned long long type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t unsigned_long_long_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous float type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t float_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous double type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t double_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous long double type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t long_double_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous raw string type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t string_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous wide string type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t wide_string_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		/// \brief Function to return function value of previous 8 bit string type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t bit8_string_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
		#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
		#endif
		}
	#endif

		/// \brief Function to return function value of previous 16 bit string type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t bit16_string_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
	#endif
		}

		/// \brief Function to return function value of previous 32 bit string type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t bit32_string_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
	#endif
		}

#endif

		/// \brief Function to return function value of previous void pointer type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t pointer_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous subroutine type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t subroutine_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous function type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t function_as_function(var const& _value) noexcept
		{
			return _value.value.function_type;
		}

		/// \brief Function to return function value of previous array type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t array_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}

		/// \brief Function to return function value of previous nullptr_t type.
		///
		/// \return function value of the argument.
		LIBLETLIB_NODISCARD inline function_t null_as_function(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: conversion to function", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return LIBLETLIB_EMPTY_FUNCTION;
#endif
		}
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_AS_FUNCTION_HPP
