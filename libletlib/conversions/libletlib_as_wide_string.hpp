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
#ifndef LIBLETLIB_LIBLETLIB_AS_WIDE_STRING_HPP
#define LIBLETLIB_LIBLETLIB_AS_WIDE_STRING_HPP

namespace libletlib
{
	namespace detail
	{
#ifndef LIBLETLIB_FREESTANDING
		/// \brief Function to return wide string value of previous bool type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* boolean_as_wide_string(var const& _value) noexcept
		{
			return _value.value.bool_type ? to_wide_string(L"true", 4) : to_wide_string(L"false", 5);
		}

		/// \brief Function to return wide string value of previous char type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* character_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(&_value.value.char_type, 1);
		}

		/// \brief Function to return wide string value of previous signed char type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* signed_character_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.signed_char_type);
		}

		/// \brief Function to return wide string value of an unsigned char type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* unsigned_character_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.unsigned_char_type);
		}

		/// \brief Function to return wide string value of previous wchar_t type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* wide_character_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.wchar_type);
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Function to return wide string value of previous char8_t type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* bit8_character_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.char8_type);
		}
		#endif

		/// \brief Function to return wide string value of previous char16_t type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* bit16_character_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(&_value.value.char16_type, 1);
		}

		/// \brief Function to return wide string value of previous char32_t type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* bit32_character_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(&_value.value.char32_type, 1);
		}

	#endif

		/// \brief Function to return wide string value of previous short type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* short_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.short_type);
		}

		/// \brief Function to return wide string value of an unsigned short type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* unsigned_short_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.unsigned_short_type);
		}

		/// \brief Function to return wide string value of an int type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* integer_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.int_type);
		}

		/// \brief Function to return wide string value of an unsigned int type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* unsigned_integer_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.unsigned_int_type);
		}

		/// \brief Function to return wide string value of previous long type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* long_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.long_type);
		}

		/// \brief Function to return wide string value of an unsigned long type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* unsigned_long_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.unsigned_long_type);
		}

	#if (__cplusplus >= 201103L)

		/// \brief Function to return wide string value of previous long long type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* long_long_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.long_long_type);
		}

		/// \brief Function to return wide string value of an unsigned long long type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* unsigned_long_long_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.unsigned_long_long_type);
		}

	#endif

		/// \brief Function to return wide string value of previous float type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* float_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(static_cast<double>(_value.value.float_type));
		}

		/// \brief Function to return wide string value of previous double type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* double_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.double_type);
		}

		/// \brief Function to return wide string value of previous long double type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* long_double_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.long_double_type);
		}

		/// \brief Function to return wide string value of previous raw string type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* string_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.string_type, string_length(_value.value.string_type));
		}

		/// \brief Function to return wide string value of previous wide string type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* wide_string_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.wide_string_type, string_length(_value.value.wide_string_type));
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Function to return wide string value of previous 8 bit string type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* bit8_string_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.bit8_string_type, string_length(_value.value.bit8_string_type));
		}
		#endif

		/// \brief Function to return wide string value of previous 16 bit string type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* bit16_string_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.bit16_string_type, string_length(_value.value.bit16_string_type));
		}

		/// \brief Function to return wide string value of previous 32 bit string type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* bit32_string_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(_value.value.bit32_string_type, string_length(_value.value.bit32_string_type));
		}

	#endif

		/// \brief Function to return wide string value of previous void pointer type.
		///
		/// \param _value to convert.
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* pointer_as_wide_string(var const& _value) noexcept
		{
			return to_wide_string(reinterpret_cast<wchar_t*>(_value.value.void_pointer_type),
			                      string_length(reinterpret_cast<wchar_t*>(_value.value.void_pointer_type)));
		}


		/// \brief Function to return wide string value of previous array type.
		///
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* array_as_wide_string(var const& _value) noexcept
		{
			return (*_value.value.array_type).behaviour->as_wide_string(_value);
		}


		/// \brief Function to return wide string value of previous subroutine type.
		///
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* subroutine_as_wide_string(var const&) LIBLETLIB_NOEXCEPT
		{
			return to_wide_string(L"\0", 1);
		}

		/// \brief Function to return wide string value of previous function type.
		///
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* function_as_wide_string(var const& _value) noexcept
		{
			var result = var(_value.value.function_type)();
			return result.behaviour->as_wide_string(result);
		}

	#if (__cplusplus >= 201103L)
		/// \brief Function to return wide string value of previous nullptr_t type.
		///
		/// \return wide string value of the argument.
		LIBLETLIB_NODISCARD inline wchar_t* null_as_wide_string(var const&) noexcept
		{
			return to_wide_string(L"\0", 1);
		}

	#endif
#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_AS_WIDE_STRING_HPP
