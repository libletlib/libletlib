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

#ifndef LIBLETLIB_LIBLETLIB_AS_VOID_POINTER_HPP
#define LIBLETLIB_LIBLETLIB_AS_VOID_POINTER_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Function to return void pointer value of previous bool type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* boolean_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.bool_type);
		}

		/// \brief Function to return void pointer value of previous char type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* character_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.char_type);
		}

		/// \brief Function to return void pointer value of previous signed char type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* signed_character_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.signed_char_type);
		}

		/// \brief Function to return void pointer value of an unsigned char type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* unsigned_character_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.unsigned_char_type);
		}

		/// \brief Function to return void pointer value of previous wchar_t type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* wide_character_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.wchar_type);
		}

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		/// \brief Function to return void pointer value of previous char8_t type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* bit8_character_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.char8_type);
		}
	#endif

		/// \brief Function to return void pointer value of previous char16_t type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* bit16_character_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.char16_type);
		}

		/// \brief Function to return void pointer value of previous char32_t type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* bit32_character_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.char32_type);
		}

#endif

		/// \brief Function to return void pointer value of previous short type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* short_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.short_type);
		}

		/// \brief Function to return void pointer value of an unsigned short type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* unsigned_short_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.unsigned_short_type);
		}

		/// \brief Function to return void pointer value of an int type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* integer_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.int_type);
		}

		/// \brief Function to return void pointer value of an unsigned int type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* unsigned_integer_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.unsigned_int_type);
		}

		/// \brief Function to return void pointer value of previous long type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* long_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.long_type);
		}

		/// \brief Function to return void pointer value of an unsigned long type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* unsigned_long_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.unsigned_long_type);
		}

#if (__cplusplus >= 201103L)

		/// \brief Function to return void pointer value of previous long long type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* long_long_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.long_long_type);
		}

		/// \brief Function to return void pointer value of an unsigned long long type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* unsigned_long_long_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.unsigned_long_long_type);
		}

#endif

		/// \brief Function to return void pointer value of previous float type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* float_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.float_type);
		}

		/// \brief Function to return void pointer value of previous double type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* double_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.double_type);
		}

		/// \brief Function to return void pointer value of previous long double type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* long_double_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.long_double_type);
		}

		/// \brief Function to return void pointer value of previous raw string type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* string_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.string_type);
		}

		/// \brief Function to return void pointer value of previous wide string type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* wide_string_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.wide_string_type);
		}

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		/// \brief Function to return void pointer value of previous 8 bit string type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* bit8_string_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void* const>(&_value.value.bit8_string_type);
		}
	#endif

		/// \brief Function to return void pointer value of previous 16 bit string type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* bit16_string_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.bit16_string_type);
		}

		/// \brief Function to return void pointer value of previous 32 bit string type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* bit32_string_as_pointer(var const& _value) noexcept
		{
			return reinterpret_cast<void*>(&_value.value.bit32_string_type);
		}

#endif

		/// \brief Function to return void pointer value of previous void pointer type.
		///
		/// \param _value to convert.
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* pointer_as_pointer(var const& _value) noexcept
		{
			return _value.value.void_pointer_type;
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Function to return pointer value of previous array type.
		///
		/// \return pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* array_as_pointer(var const& _value) noexcept
		{
			return (*_value.value.array_type).behaviour->as_pointer(_value);
		}

		/// \brief Function to return pointer value of previous subroutine type.
		///
		/// \return pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* subroutine_as_pointer(var const&) LIBLETLIB_NOEXCEPT
		{
			return reinterpret_cast<void*>(NULL);
		}

		/// \brief Function to return pointer value of previous function type.
		///
		/// \return pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* function_as_pointer(var const& _value) noexcept
		{
			var result = var(_value.value.function_type)();
			return result.behaviour->as_pointer(result);
		}

#endif
#if (__cplusplus >= 201103L)

		/// \brief Function to return void pointer value of previous nullptr_t type.
		///
		/// \return void pointer value of the argument.
		LIBLETLIB_NODISCARD inline void* null_as_pointer(var const&) noexcept
		{
			return reinterpret_cast<void*>(NULL);
		}

#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_AS_VOID_POINTER_HPP
