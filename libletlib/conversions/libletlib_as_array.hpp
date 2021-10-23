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

#ifndef LIBLETLIB_LIBLETLIB_AS_ARRAY_HPP
#define LIBLETLIB_LIBLETLIB_AS_ARRAY_HPP

namespace libletlib
{
	namespace detail
	{
#ifndef LIBLETLIB_FREESTANDING
		/// \brief Function to return array value of previous bool type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var boolean_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.bool_type);
		}

		/// \brief Function to return array value of previous char type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var character_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.char_type);
		}

		/// \brief Function to return array value of previous signed char type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var signed_character_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.signed_char_type);
		}

		/// \brief Function to return array value of an unsigned char type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var unsigned_character_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.unsigned_char_type);
		}

		/// \brief Function to return array value of previous wchar_t type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var wide_character_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.wchar_type);
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Function to return array value of previous char8_t type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var bit8_character_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.char8_type);
		}
		#endif

		/// \brief Function to return array value of previous char16_t type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var bit16_character_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.char16_type);
		}

		/// \brief Function to return array value of previous char32_t type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var bit32_character_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.char32_type);
		}

	#endif

		/// \brief Function to return array value of previous short type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var short_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.short_type);
		}

		/// \brief Function to return array value of an unsigned short type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var unsigned_short_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.unsigned_short_type);
		}

		/// \brief Function to return array value of an int type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var integer_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.int_type);
		}

		/// \brief Function to return array value of an unsigned int type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var unsigned_integer_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.unsigned_int_type);
		}

		/// \brief Function to return array value of previous long type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var long_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.long_type);
		}

		/// \brief Function to return array value of an unsigned long type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var unsigned_long_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.unsigned_long_type);
		}

	#if (__cplusplus >= 201103L)
		/// \brief Function to return array value of previous long long type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var long_long_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.long_long_type);
		}

		/// \brief Function to return array value of an unsigned long long type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var unsigned_long_long_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.unsigned_long_long_type);
		}

	#endif
		/// \brief Function to return array value of previous float type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var float_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.float_type);
		}

		/// \brief Function to return array value of previous double type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var double_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.double_type);
		}

		/// \brief Function to return array value of previous long double type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var long_double_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.long_double_type);
		}

		/// \brief Function to return array value of previous raw string type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var string_as_array(var const& _value) noexcept
		{
			size_struct size = size_struct(_value.size.in_use);
			var* array       = allocate<var>(size.allocated);
			for (std::size_t index = 0; index < size.in_use; ++index)
			{
				array[index] = var(_value.value.string_type[index]);
			}
			return var(array, size);
		}

		/// \brief Function to return array value of previous wide string type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var wide_string_as_array(var const& _value) noexcept
		{
			size_struct size = size_struct(_value.size.in_use / sizeof(wchar_t));
			var* array       = allocate<var>(size.allocated);
			for (std::size_t index = 0; index < size.in_use; ++index)
			{
				array[index] = var(_value.value.string_type[index]);
			}
			return var(array, size);
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Function to return array value of previous 16 bit string type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var bit8_string_as_array(var const& _value) noexcept
		{
			size_struct size = size_struct(_value.size.in_use / sizeof(char8_t));
			var* array       = allocate<var>(size.allocated);
			for (std::size_t index = 0; index < size.in_use; ++index)
			{
				array[index] = var(_value.value.bit8_string_type[index]);
			}
			return var(array, size);
		}
		#endif

		/// \brief Function to return array value of previous 16 bit string type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var bit16_string_as_array(var const& _value) noexcept
		{
			size_struct size = size_struct(_value.size.in_use / sizeof(char16_t));
			var* array       = allocate<var>(size.allocated);
			for (std::size_t index = 0; index < size.in_use; ++index)
			{
				array[index] = var(_value.value.bit16_string_type[index]);
			}
			return var(array, size);
		}

		/// \brief Function to return array value of previous 32 bit string type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var bit32_string_as_array(var const& _value) noexcept
		{
			size_struct size = size_struct(_value.size.in_use / sizeof(char32_t));
			var* array       = allocate<var>(size.allocated);
			for (std::size_t index = 0; index < size.in_use; ++index)
			{
				array[index] = var(_value.value.bit32_string_type[index]);
			}
			return var(array, size);
		}

	#endif

		/// \brief Function to return array value of previous void pointer type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var pointer_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.void_pointer_type);
		}


		/// \brief Function to return array value of previous subroutine type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var subroutine_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.function_type);
		}

		/// \brief Function to return array of previous function type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var function_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.function_type);
		}

		/// \brief Function to return array value of previous array type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var array_as_array(var const& _value) noexcept
		{
			return _value;
		}

	#if (__cplusplus >= 201103L)
		/// \brief Function to return array value of previous nullptr_t type.
		///
		/// \return array value of the argument.
		LIBLETLIB_NODISCARD inline var null_as_array(var const& _value) noexcept
		{
			return backing::list(_value.value.nullptr_type);
		}

	#endif
#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_AS_ARRAY_HPP
