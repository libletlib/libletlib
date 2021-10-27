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

#ifndef LIBLETLIB_LIBLETLIB_AS_NULL_HPP
#define LIBLETLIB_LIBLETLIB_AS_NULL_HPP

namespace libletlib
{
	namespace detail
	{
#if (__cplusplus >= 201103L)

		/// \brief Function to return nullptr_t value of previous bool type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t boolean_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous char type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t character_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous signed char type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t signed_character_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of an unsigned char type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t unsigned_character_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous wchar_t type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t wide_character_as_null(var const&) noexcept
		{
			return nullptr;
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Function to return nullptr_t value of previous char8_t type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t bit8_character_as_null(var const&) noexcept
		{
			return nullptr;
		}
		#endif
		/// \brief Function to return nullptr_t value of previous char16_t type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t bit16_character_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous char32_t type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t bit32_character_as_null(var const&) noexcept
		{
			return nullptr;
		}

	#endif

		/// \brief Function to return nullptr_t value of previous short type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t short_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of an unsigned short type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t unsigned_short_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of an int type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t integer_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of an unsigned int type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t unsigned_integer_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous long type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t long_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of an unsigned long type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t unsigned_long_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous long long type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t long_long_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of an unsigned long long type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t unsigned_long_long_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous float type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t float_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous double type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t double_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous long double type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t long_double_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous raw string type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t string_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous wide string type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t wide_string_as_null(var const&) noexcept
		{
			return nullptr;
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Function to return nullptr_t value of previous 8 bit string type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t bit8_string_as_null(var const&) noexcept
		{
			return nullptr;
		}
		#endif
		/// \brief Function to return nullptr_t value of previous 16 bit string type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t bit16_string_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous 32 bit string type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t bit32_string_as_null(var const&) noexcept
		{
			return nullptr;
		}

	#endif

		/// \brief Function to return nullptr_t value of previous void pointer type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t pointer_as_null(var const&) noexcept
		{
			return nullptr;
		}

	#ifndef LIBLETLIB_FREESTANDING

		/// \brief Function to return nullptr_t value of previous array type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t array_as_null(var const&) noexcept
		{
			return nullptr;
		}

	#endif

		/// \brief Function to return nullptr_t value of previous subroutine type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t subroutine_as_null(var const&) noexcept
		{
			return nullptr;
		}

		/// \brief Function to return nullptr_t value of previous function type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t function_as_null(var const& _value) noexcept
		{
	#ifndef LIBLETLIB_FREESTANDING
			var result = var(_value.value.function_type)();
			return result.behaviour->as_null(result);
	#else
			return nullptr;
	#endif
		}

		/// \brief Function to return nullptr_t value of previous nullptr_t type.
		///
		/// \return nullptr_t value of the argument.
		LIBLETLIB_NODISCARD inline std::nullptr_t null_as_null(var const&) noexcept
		{
			return nullptr;
		}

#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_AS_NULL_HPP
