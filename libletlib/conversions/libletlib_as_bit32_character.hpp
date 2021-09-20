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

#ifndef LIBLETLIB_LIBLETLIB_AS_BIT32_CHARACTER_HPP
#define LIBLETLIB_LIBLETLIB_AS_BIT32_CHARACTER_HPP

namespace libletlib
{
	namespace detail
	{

#ifndef LIBLETLIB_DISABLE_UCHAR
	#ifdef LIBLETLIB_HOSTED

		/// \brief Function to return char32_t value of previous bool type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t boolean_as_bit32_character(var const& _value) noexcept
		{
			return _value.value.bool_type ? U'1' : U'0';
		}

		/// \brief Function to return char32_t value of previous char type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t character_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.char_type);
		}

		/// \brief Function to return char32_t value of previous signed char type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t signed_character_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.signed_char_type);
		}

		/// \brief Function to return char32_t value of an unsigned char type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t unsigned_character_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.unsigned_char_type);
		}

		/// \brief Function to return char32_t value of previous wchar_t type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t wide_character_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.wchar_type);
		}

		#if (__cplusplus >= 202002L)
		/// \brief Function to return char32_t value of previous char8_t type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t bit8_character_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.char8_type);
		}
		#endif

		/// \brief Function to return char32_t value of previous char16_t type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t bit16_character_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.char16_type);
		}

		/// \brief Function to return char32_t value of previous char32_t type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t bit32_character_as_bit32_character(var const& _value) noexcept
		{
			return _value.value.char32_type;
		}

		/// \brief Function to return char32_t value of previous short type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t short_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.short_type);
		}

		/// \brief Function to return char32_t value of an unsigned short type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t unsigned_short_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.unsigned_short_type);
		}

		/// \brief Function to return char32_t value of an int type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t integer_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.int_type);
		}

		/// \brief Function to return char32_t value of an unsigned int type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t unsigned_integer_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.unsigned_int_type);
		}

		/// \brief Function to return char32_t value of previous long type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t long_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.long_type);
		}

		/// \brief Function to return char32_t value of an unsigned long type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t unsigned_long_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.unsigned_long_type);
		}

		/// \brief Function to return char32_t value of previous long long type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t long_long_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.long_long_type);
		}

		/// \brief Function to return char32_t value of an unsigned long long type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t unsigned_long_long_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.unsigned_long_long_type);
		}

		/// \brief Function to return char32_t value of previous float type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t float_as_bit32_character(var const& _value) noexcept
		{
			return float_round<float, char32_t>(_value.value.float_type);
		}

		/// \brief Function to return char32_t value of previous double type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t double_as_bit32_character(var const& _value) noexcept
		{
			return float_round<double, char32_t>(_value.value.double_type);
		}

		/// \brief Function to return char32_t value of previous long double type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t long_double_as_bit32_character(var const& _value) noexcept
		{
			return float_round<long double, char32_t>(_value.value.long_double_type);
		}

		/// \brief Function to return char32_t value of previous raw string type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t string_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.string_type[0]);
		}

		/// \brief Function to return char32_t value of previous wchar_t type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t wide_string_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.wide_string_type[0]);
		}

		#if (__cplusplus >= 202002L)
		/// \brief Function to return char32_t value of previous 8 bit string type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t bit8_string_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.bit8_string_type[0]);
		}
		#endif

		/// \brief Function to return char32_t value of previous 16 bit string type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t bit16_string_as_bit32_character(var const& _value) noexcept
		{
			return static_cast<char32_t>(_value.value.bit16_string_type[0]);
		}

		/// \brief Function to return char32_t value of previous 32 bit string type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t bit32_string_as_bit32_character(var const& _value) noexcept
		{
			return _value.value.bit32_string_type[0];
		}

		/// \brief Function to return char32_t value of previous void pointer type.
		///
		/// \param _value to convert.
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t pointer_as_bit32_character(var const& _value) noexcept
		{
			return *(reinterpret_cast<char32_t*>(_value.value.void_pointer_type));
		}

		/// \brief Function to return char32_t value of previous array type.
		///
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t array_as_bit32_character(var const& _value) noexcept
		{
			return (*_value.value.array_type).behaviour->as_bit32_character(_value);
		}

		/// \brief Function to return char32_t value of previous subroutine type.
		///
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t subroutine_as_bit32_character(var const&) LIBLETLIB_NOEXCEPT
		{
			return U'\0';
		}

		/// \brief Function to return char32_t value of previous function type.
		///
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t function_as_bit32_character(var const& _value) noexcept
		{
			var result = _value.value.function_type(_value.value.function_type, nullptr);
			return result.behaviour->as_bit32_character(result);
		}

		/// \brief Function to return char32_t value of previous nullptr_t type.
		///
		/// \return 32 bit character value of the argument.
		LIBLETLIB_NODISCARD inline char32_t null_as_bit32_character(var const&) noexcept
		{
			return U'\0';
		}
	#endif
#endif

	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_AS_BIT32_CHARACTER_HPP
