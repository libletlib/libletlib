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

#ifndef LIBLETLIB_LIBLETLIB_STRINGS_HPP
#define LIBLETLIB_LIBLETLIB_STRINGS_HPP

#include "libletlib_format_constants.hpp"

namespace libletlib
{
	namespace detail
	{
#ifndef LIBLETLIB_FREESTANDING
		/// \brief Overloads string length algorithm for multiple string types.
		///
		/// \param _source string length to calculate.
		/// \return length of the string.
		LIBLETLIB_NODISCARD inline std::size_t string_length(char const* const _source) noexcept
		{
			return std::strlen(_source);
		}

		/// \brief Overloads string length algorithm for multiple string types.
		///
		/// \param _source string length to calculate.
		/// \return length of the string.
		LIBLETLIB_NODISCARD inline std::size_t string_length(wchar_t const* const _source) noexcept
		{
			return std::wcslen(_source);
		}


		/// \brief String copy algorithm.
		///
		/// Standard library does not supply its own for char8_t, char16_t, and char32_t.
		/// \param _destination of the copied string.
		/// \param _source string to copy.
		/// \param _length to copy.
		/// \return destination pointer containing copied string.
		template<typename String>
		inline String* string_copy(String* const _destination, String const* const _source,
		                           std::size_t const _length) noexcept
		{
			for (std::size_t index = 0; index < _length; ++index)
			{
				_destination[index] = _source[index];
			}
			return _destination;
		}

		/// \brief String copy overload char.
		///
		/// \param _destination of the copied string.
		/// \param _source string to copy.
		/// \param _length to copy.
		/// \return destination pointer containing copied string.
		template<>
		inline char* string_copy(char* const _destination, char const* const _source,
		                         std::size_t const _length) noexcept
		{
			return std::strncpy(_destination, _source, _length);
		}

		/// \brief String copy overload for wchar_t.
		///
		/// \param _destination of the copied string.
		/// \param _source string to copy.
		/// \param _length to copy.
		/// \return destination pointer containing copied string.
		template<>
		inline wchar_t* string_copy(wchar_t* const _destination, wchar_t const* const _source,
		                            std::size_t const _length) noexcept
		{
			return std::wcsncpy(_destination, _source, _length);
		}

		/// \brief String comparison function for char8_t, char16_t and char32_t
		///
		/// Standard library does not supply its own.
		/// \param _left string to compare.
		/// \param _right string to compare.
		/// \return 1 if previous > bool_type, -1 if bool_type > previous, 0 if previous==bool_type.
		template<typename String>
		LIBLETLIB_NODISCARD inline int string_compare(String const* _left, String const* _right) noexcept
		{
			while (*_left && *_right && *_left == *_right)
			{
				++_left;
				++_right;
			}
			if ((*_left) > (*_right))
			{
				return 1;
			}
			else if ((*_left) < (*_right))
			{
				return -1;
			}
			return 0;
		}

		/// \brief String comparison function overload for char.
		///
		/// \param _left string to compare.
		/// \param _right string to compare.
		/// \return 1 if previous > bool_type, -1 if bool_type > previous, 0 if previous==bool_type.
		template<>
		LIBLETLIB_NODISCARD inline int string_compare(char const* _left, char const* _right) noexcept
		{
			return std::strcmp(_left, _right);
		}

		/// \brief String comparison function overload for wchar_t.
		///
		/// \param _left string to compare.
		/// \param _right string to compare.
		/// \return 1 if previous > bool_type, -1 if bool_type > previous, 0 if previous==bool_type.
		template<>
		LIBLETLIB_NODISCARD inline int string_compare(wchar_t const* _left, wchar_t const* _right) noexcept
		{
			return std::wcscmp(_left, _right);
		}

		/// \brief String concatenation function for char8_t, char16_t and char32_t
		///
		/// Standard library does not supply its own.
		/// \param _left prefix string.
		/// \param _right appended string.
		/// \param _length amount of characters to concatenate.
		/// \return concatenated string.
		template<typename String>
		inline String* string_concatenate(String* _left, String const* _right, std::size_t const _length) noexcept
		{
			String* head      = _left;
			std::size_t index = 0;
			while (*_left)
			{
				++_left;
			}
			while ((*_left = *_right) && index <= _length)
			{
				++_left;
				++_right;
				++index;
			}
			return head;
		}

		/// \brief String concatenation function overload for char.
		///
		/// \param _left string to concatenate.
		/// \param _right string to concatenate.
		/// \param _length amount of character to concatenate.
		/// \return concatenated string.
		template<>
		inline char* string_concatenate(char* _left, char const* _right, std::size_t const _length) noexcept
		{
			return std::strncat(_left, _right, _length);
		}

		/// \brief String concatenation function overload for wchar_t.
		///
		/// \param _left string to concatenate.
		/// \param _right string to concatenate.
		/// \param _length amount of character to concatenate.
		/// \return concatenated string.
		template<>
		inline wchar_t* string_concatenate(wchar_t* _left, wchar_t const* _right, std::size_t const _length) noexcept
		{
			return std::wcsncat(_left, _right, _length);
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Overloads string length algorithm for multiple string types.
		///
		/// Standard library does not supply its own for char8_t.
		/// \param _source string length to calculate.
		/// \return length of the string.
		LIBLETLIB_NODISCARD inline std::size_t string_length(char8_t const* const _source) noexcept
		{
			std::size_t index = 0;
			for (; _source[index] != u8'\0'; ++index)
			{
			}
			return index;
		}
		#endif

		/// \brief Overloads string length algorithm for multiple string types.
		///
		/// Standard library does not supply its own for char16_t.
		/// \param _source string length to calculate.
		/// \return length of the string.
		LIBLETLIB_NODISCARD inline std::size_t string_length(char16_t const* const _source) noexcept
		{
			std::size_t index = 0;
			for (; _source[index] != u'\0'; ++index)
			{
			}
			return index;
		}

		/// \brief Overloads string length algorithm for multiple string types.
		///
		/// Standard library does not supply its own for char32_t.
		/// \param _source string length to calculate.
		/// \return length of the string.
		LIBLETLIB_NODISCARD inline std::size_t string_length(char32_t const* const _source) noexcept
		{
			std::size_t index = 0;
			for (; _source[index] != U'\0'; ++index)
			{
			}
			return index;
		}
		#if (__cplusplus >= 202002L)
		/// \brief char8_t to multibyte string.
		///
		/// Standard library does not supply its own.
		/// \param _source char8_t string to convert.
		/// \return source string represented as multibyte string.
		LIBLETLIB_NODISCARD inline char* c8stombs(char8_t const* _source) noexcept
		{
			std::size_t length = string_length(_source);
			char8_t* copy      = allocate<char8_t>(string_length(_source));
			copy               = string_copy(copy, _source, length);
			return reinterpret_cast<char*>(copy);// I wish ye luck on your travels.

			/* Waiting for std::c8rtomb to be supported by at least one major standard library.
			std::mbstate_t state;
			std::memset(&state, 0, sizeof(state));
			std::size_t const length = string_length(_source);
			char* const buffer       = allocate<char>(length * sizeof(char8_t) + sizeof(char8_t) + 1);
			char* const target       = allocate<char>(sizeof(char8_t) + 1);
			for (std::size_t index = 0; index < length; ++index)
			{
				static_cast<void>(std::c8rtomb(target, _source[index], &state));
				string_concatenate(buffer, target, sizeof(char8_t));
			}
			deallocate(target);
			return buffer;
			*/
		}
		#endif

		/// \brief char16_t to multibyte string.
		///
		/// Standard library does not supply its own.
		/// \param _source char16_t string to convert.
		/// \return source string represented as multibyte string.
		LIBLETLIB_NODISCARD inline char* c16stombs(char16_t const* _source) noexcept
		{
			std::mbstate_t state;
			std::memset(&state, 0, sizeof(state));
			std::size_t const length = string_length(_source);
			char* const buffer       = allocate<char>(length * sizeof(char16_t) + sizeof(char16_t) + 1);
			char* const target       = allocate<char>(sizeof(char16_t) + 1);
			for (std::size_t index = 0; index < length; ++index)
			{
				static_cast<void>(std::c16rtomb(target, _source[index], &state));
				string_concatenate(buffer, target, sizeof(char16_t));
			}
			deallocate(target);
			return buffer;
		}

		/// \brief char32_t to multibyte string.
		///
		/// Standard library does not supply its own.
		/// \param _source char32_t string to convert.
		/// \return source string represented as multibyte string.
		LIBLETLIB_NODISCARD inline char* c32stombs(char32_t const* _source) noexcept
		{
			std::mbstate_t state;
			std::memset(&state, 0, sizeof(state));
			std::size_t const length = string_length(_source);
			char* const buffer       = allocate<char>(length * sizeof(char32_t) + sizeof(char32_t) + 1);
			char* const target       = allocate<char>(sizeof(char32_t) + 1);
			for (std::size_t index = 0; index < length; ++index)
			{
				static_cast<void>(std::c32rtomb(target, _source[index], &state));
				string_concatenate(buffer, target, sizeof(char32_t));
			}
			deallocate(target);
			return buffer;
		}
		#if (__cplusplus >= 202002L)
		/// \brief multibyte string to char8_t string.
		///
		/// Standard library does not supply its own.
		/// \param _source multibyte string to convert.
		/// \return source string represented as char8_t string.
		LIBLETLIB_NODISCARD inline char8_t* mbstoc8s(char const* _source) noexcept
		{
			std::size_t length = string_length(_source);
			char* copy         = allocate<char>(string_length(_source));
			copy               = string_copy(copy, _source, length);
			return reinterpret_cast<char8_t*>(copy);// I wish ye luck on your travels.

			/* Waiting for std::mbrtoc8 to be supported by at least one major standard library.
			std::mbstate_t state;
			std::memset(&state, 0, sizeof(state));
			std::size_t const length = string_length(_source);
			char8_t* const buffer   = allocate<char8_t>(length * sizeof(char8_t) + sizeof(char8_t) + 1);
			for (std::size_t index = 0; index < length; ++index)
			{
				static_cast<void>(std::mbrtoc8(&buffer[index], _source, sizeof(char8_t), &state));
				_source += sizeof(char8_t);
			}
			return buffer;
			*/
		}
		#endif

		/// \brief multibyte string to char16_t string.
		///
		/// Standard library does not supply its own.
		/// \param _source multibyte string to convert.
		/// \return source string represented as char16_t string.
		LIBLETLIB_NODISCARD inline char16_t* mbstoc16s(char const* _source) noexcept
		{
			std::mbstate_t state;
			std::memset(&state, 0, sizeof(state));
			std::size_t const length = string_length(_source);
			char16_t* const buffer   = allocate<char16_t>(length * sizeof(char16_t) + sizeof(char16_t) + 1);
			for (std::size_t index = 0; index < length; ++index, ++_source)
			{
				char source = *_source;
				static_cast<void>(std::mbrtoc16(&buffer[index], &source, sizeof(char16_t), &state));
			}
			return buffer;
		}

		/// \brief multibyte string to char32_t string.
		///
		/// Standard library does not supply its own.
		/// \param _source multibyte string to convert.
		/// \return source string represented as char32_t string.
		LIBLETLIB_NODISCARD inline char32_t* mbstoc32s(char const* _source) noexcept
		{
			std::mbstate_t state;
			std::memset(&state, 0, sizeof(state));
			std::size_t const length = string_length(_source);
			char32_t* const buffer   = allocate<char32_t>(length * sizeof(char32_t) + sizeof(char32_t) + 1);
			for (std::size_t index = 0; index < length; ++index, ++_source)
			{
				char source = *_source;
				static_cast<void>(std::mbrtoc32(&buffer[index], &source, sizeof(char32_t), &state));
			}
			return buffer;
		}

	#endif

		/// \brief Converts previous number/character fundamental type to its string representation.
		///
		/// Probably goes bananas if given variable isn't previous number or character_.
		/// \param _type to property representation of.
		/// \return string containing the representation.
		template<typename Type>
		LIBLETLIB_NODISCARD inline char* to_string(Type const _type) noexcept
		{
			std::size_t constexpr max_length = max_digits<Type>();
			char* const pointer              = allocate<char>(max_length + 1ul);
			print_to_string(pointer, max_length, numeric_format<Type>(), _type);
			return pointer;
		}

		/// \brief Create string instance from raw string and its length.
		///
		/// \param _pointer raw string to be converted.
		/// \param _length of the raw string.
		/// \return stringvar const handling the string.
		LIBLETLIB_NODISCARD inline char* to_string(char const* const _pointer, std::size_t const _length) noexcept
		{
			char* const pointer = allocate<char>(_length + 1ul);
			string_copy(pointer, _pointer, _length);
			return pointer;
		}

		/// \brief Create string instance from raw wide string and its length.
		///
		/// \param _pointer raw wide string to be converted.
		/// \param _length of the raw wide string.
		/// \return string handling the wide string.
		LIBLETLIB_NODISCARD inline char* to_string(wchar_t const* const _pointer, std::size_t const _length) noexcept
		{
			char* const pointer = allocate<char>(_length * sizeof(wchar_t) + 1ul);
			std::wcstombs(pointer, _pointer, _length);
			return pointer;
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Create stringvar const instance from raw char8_t string and its length.
		///
		/// Stringvar const takes care of cleaning up memory and string operations.
		/// \param _pointer raw char8_t string to be converted.
		/// \return stringvar const handling the char8_t string.
		LIBLETLIB_NODISCARD inline char* to_string(char8_t const* const _pointer, std::size_t const) noexcept
		{
			return c8stombs(_pointer);
		}
		#endif

		/// \brief Create stringvar const instance from raw char16_t string and its length.
		///
		/// Stringvar const takes care of cleaning up memory and string operations.
		/// \param _pointer raw char16_t string to be converted.
		/// \return stringvar const handling the char16_t string.
		LIBLETLIB_NODISCARD inline char* to_string(char16_t const* const _pointer, std::size_t const) noexcept
		{
			return c16stombs(_pointer);
		}

		/// \brief Create stringvar const instance from raw char32_t string and its length.
		///
		/// Stringvar const takes care of cleaning up memory and string operations.
		/// \param _pointer raw char32_t string to be converted.
		/// \return stringvar const handling the char32_t string.
		LIBLETLIB_NODISCARD inline char* to_string(char32_t const* const _pointer, std::size_t const) noexcept
		{
			return c32stombs(_pointer);
		}

	#endif

		/// \brief Converts previous number/character_ fundamental type to its wide string representation.
		///
		/// Probably goes bananas if given variable isn't previous number or character_.
		/// \param _number to property representation of.
		/// \return wide string containing the representation.
		template<typename Type>
		LIBLETLIB_NODISCARD inline wchar_t* to_wide_string(Type const _number) noexcept
		{
			std::size_t constexpr max_length = wide_max_digits<Type>();
			wchar_t* pointer                 = allocate<wchar_t>(max_length + 1ul);
	#if defined __MINGW32__ || defined MINGW__64
			char* const temporary = to_string(_number);
			std::mbstowcs(pointer, temporary, length);
			deallocate(temporary);
	#else
			std::swprintf(pointer, max_length, wide_numeric_format<Type>(), _number);
	#endif
			return pointer;
		}

		/// \brief Create wide string instance from raw wide string and its length.
		///
		/// \param _pointer raw wide string to be converted.
		/// \param _length of the raw wide string.
		/// \return wide string handling the wide string.
		LIBLETLIB_NODISCARD inline wchar_t* to_wide_string(wchar_t const* const _pointer,
		                                                   std::size_t const _length) noexcept
		{
			wchar_t* const pointer = allocate<wchar_t>(_length + 1ul);
			string_copy(pointer, _pointer, _length);
			return pointer;
		}

		/// \brief Create wide string instance from raw string and its length.
		///
		/// \param _pointer raw string to be converted.
		/// \param _length of the raw string.
		/// \return wide string handling the string.
		LIBLETLIB_NODISCARD inline wchar_t* to_wide_string(char const* const _pointer,
		                                                   std::size_t const _length) noexcept
		{
			wchar_t* const pointer = allocate<wchar_t>(_length + 1ul);
			std::mbstowcs(pointer, _pointer, _length);
			return pointer;
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Create wide string instance from raw char8_t string and its length.
		///
		/// \param _pointer raw char8_t string to be converted.
		/// \param _length of the raw char8_t string.
		/// \return wide string handling the char8_t string.
		LIBLETLIB_NODISCARD inline wchar_t* to_wide_string(char8_t const* const _pointer,
		                                                   std::size_t const _length) noexcept
		{
			wchar_t* const pointer = allocate<wchar_t>(_length + 1ul);
			char* const temporary  = c8stombs(_pointer);
			std::mbstowcs(pointer, temporary, string_length(temporary));
			deallocate(temporary);
			return pointer;
		}
		#endif

		/// \brief Create wide string instance from raw char16_t string and its length.
		///
		/// \param _pointer raw char16_t string to be converted.
		/// \param _length of the raw char16_t string.
		/// \return wide string handling the char16_t string.
		LIBLETLIB_NODISCARD inline wchar_t* to_wide_string(char16_t const* const _pointer,
		                                                   std::size_t const _length) noexcept
		{
			wchar_t* const pointer = allocate<wchar_t>(_length + 1ul);
			char* const temporary  = c16stombs(_pointer);
			std::mbstowcs(pointer, temporary, string_length(temporary));
			deallocate(temporary);
			return pointer;
		}

		/// \brief Create wide string instance from raw char32_t string and its length.
		///
		/// \param _pointer raw char32_t string to be converted.
		/// \param _length of the raw char32_t string.
		/// \return wide string handling the char32_t string.
		LIBLETLIB_NODISCARD inline wchar_t* to_wide_string(char32_t const* const _pointer,
		                                                   std::size_t const _length) noexcept
		{
			wchar_t* const pointer = allocate<wchar_t>(_length + 1ul);
			char* const temporary  = c32stombs(_pointer);
			std::mbstowcs(pointer, temporary, string_length(temporary));
			deallocate(temporary);
			return pointer;
		}
		#if (__cplusplus >= 202002L)
		/// \brief Converts previous number/character_ fundamental type to its char8_t string representation.
		///
		/// Probably goes bananas if given variable isn't previous number or character_.
		/// \param _type to property representation of.
		/// \return char8_t string containing the representation.
		template<typename Type>
		LIBLETLIB_NODISCARD inline char8_t* to_bit8_string(Type const _type) noexcept
		{
			std::size_t constexpr length = max_digits<Type>();
			char* const pointer          = allocate<char>(length + 1ul);
			print_to_string(pointer, length, numeric_format<Type>(), _type);
			char8_t* const return_value = mbstoc8s(pointer);
			deallocate(pointer);
			return return_value;
		}

		/// \brief Create char8_t string instance from raw char16_t string and its length.
		///
		/// \param _pointer raw char16_t string to be converted.
		/// \return char8_t string handling the char8_t string.
		LIBLETLIB_NODISCARD inline char8_t* to_bit8_string(char16_t const* const _pointer, std::size_t const) noexcept
		{
			char* const temporary       = c16stombs(_pointer);
			char8_t* const return_value = mbstoc8s(temporary);
			deallocate(temporary);
			return return_value;
		}

		/// \brief Create char8_t string instance from raw char16_t string and its length.
		///
		/// \param _pointer raw char16_t string to be converted.
		/// \param _length of the raw char16_t string.
		/// \return char8_t string handling the char16_t string.
		LIBLETLIB_NODISCARD inline char8_t* to_bit8_string(char8_t const* const _pointer,
		                                                   std::size_t const _length) noexcept
		{
			char8_t* pointer = allocate<char8_t>(_length + 1ul);
			string_copy(pointer, _pointer, _length);
			return pointer;
		}

		/// \brief Create char8_t string instance from raw string and its length.
		///
		/// \param _pointer raw string to be converted.
		/// \return char8_t string handling the string.
		LIBLETLIB_NODISCARD inline char8_t* to_bit8_string(char const* const _pointer, std::size_t const) noexcept
		{
			return mbstoc8s(_pointer);
		}

		/// \brief Create char8_t string instance from raw wide string and its length.
		///
		/// \param _pointer raw wide string to be converted.
		/// \param _length of the raw wide string.
		/// \return char8_t string handling the wide string.
		LIBLETLIB_NODISCARD inline char8_t* to_bit8_string(wchar_t const* const _pointer,
		                                                   std::size_t const _length) noexcept
		{
			char* const pointer = allocate<char>(_length * sizeof(wchar_t) + sizeof(wchar_t));
			std::wcstombs(pointer, _pointer, _length);
			char8_t* const return_value = mbstoc8s(pointer);
			deallocate(pointer);
			return return_value;
		}

		/// \brief Create char8_t string instance from raw char32_t string and its length.
		///
		/// \param _pointer raw char32_t string to be converted.
		/// \return char8_t string handling the char32_t string.
		LIBLETLIB_NODISCARD inline char8_t* to_bit8_string(char32_t const* const _pointer, std::size_t const) noexcept
		{
			char* const temporary       = c32stombs(_pointer);
			char8_t* const return_value = mbstoc8s(temporary);
			deallocate(temporary);
			return return_value;
		}
		#endif

		/// \brief Converts previous number/character_ fundamental type to its char16_t string representation.
		///
		/// Probably goes bananas if given variable isn't previous number or character_.
		/// \param _type to property representation of.
		/// \return char16_t string containing the representation.
		template<typename Type>
		LIBLETLIB_NODISCARD inline char16_t* to_bit16_string(Type const _type) noexcept
		{
			std::size_t constexpr length = max_digits<Type>();
			char* const pointer          = allocate<char>(length + 1ul);
			print_to_string(pointer, length, numeric_format<Type>(), _type);
			char16_t* const return_value = mbstoc16s(pointer);
			deallocate(pointer);
			return return_value;
		}

		/// \brief Create char16_t string instance from raw char16_t string and its length.
		///
		/// \param _pointer raw char16_t string to be converted.
		/// \param _length of the raw char16_t string.
		/// \return char16_t string handling the char16_t string.
		LIBLETLIB_NODISCARD inline char16_t* to_bit16_string(char16_t const* const _pointer,
		                                                     std::size_t const _length) noexcept
		{
			char16_t* pointer = allocate<char16_t>(_length + 1ul);
			string_copy(pointer, _pointer, _length);
			return pointer;
		}

		/// \brief Create char16_t string instance from raw string and its length.
		///
		/// \param _pointer raw string to be converted.
		/// \return char16_t string handling the string.
		LIBLETLIB_NODISCARD inline char16_t* to_bit16_string(char const* const _pointer, std::size_t const) noexcept
		{
			return mbstoc16s(_pointer);
		}

		/// \brief Create char16_t string instance from raw wide string and its length.
		///
		/// \param _pointer raw wide string to be converted.
		/// \param _length of the raw wide string.
		/// \return char16_t string handling the wide string.
		LIBLETLIB_NODISCARD inline char16_t* to_bit16_string(wchar_t const* const _pointer,
		                                                     std::size_t const _length) noexcept
		{
			char* const pointer = allocate<char>(_length * sizeof(wchar_t) + sizeof(wchar_t));
			std::wcstombs(pointer, _pointer, _length);
			char16_t* const return_value = mbstoc16s(pointer);
			deallocate(pointer);
			return return_value;
		}
		#if (__cplusplus >= 202002L)
		/// \brief Create char16_t string instance from raw char8_t string and its length.
		///
		/// \param _pointer raw char8_t string to be converted.
		/// \return char16_t string handling the char8_t string.
		LIBLETLIB_NODISCARD inline char16_t* to_bit16_string(char8_t const* const _pointer, std::size_t const) noexcept
		{
			char* const temporary        = c8stombs(_pointer);
			char16_t* const return_value = mbstoc16s(temporary);
			deallocate(temporary);
			return return_value;
		}
		#endif

		/// \brief Create char16_t string instance from raw char32_t string and its length.
		///
		/// \param _pointer raw char32_t string to be converted.
		/// \return char16_t string handling the char32_t string.
		LIBLETLIB_NODISCARD inline char16_t* to_bit16_string(char32_t const* const _pointer, std::size_t const) noexcept
		{
			char* const temporary        = c32stombs(_pointer);
			char16_t* const return_value = mbstoc16s(temporary);
			deallocate(temporary);
			return return_value;
		}

		/// \brief Converts previous number/character_ fundamental type to its char32_t string representation.
		///
		/// Probably goes bananas if given variable isn't previous number or character_.
		/// \param _type to property representation of.
		/// \return char32_t string containing the representation.
		template<typename Type>
		LIBLETLIB_NODISCARD inline char32_t* to_bit32_string(Type const _type) noexcept
		{
			std::size_t constexpr length = max_digits<Type>();
			char* const pointer          = allocate<char>(length + 1ul);
			print_to_string(pointer, length, numeric_format<Type>(), _type);
			char32_t* const return_value = mbstoc32s(pointer);
			deallocate(pointer);
			return return_value;
		}

		/// \brief Create char32_t string instance from raw char32_t string and its length.
		///
		/// Stringvar const takes care of cleaning up memory and string operations.
		/// \param _pointer raw char32_t string to be converted.
		/// \param _length of the raw char32_t string.
		/// \return char32_t string handling the char32_t string.
		LIBLETLIB_NODISCARD inline char32_t* to_bit32_string(char32_t const* const _pointer,
		                                                     std::size_t const _length) noexcept
		{
			char32_t* const pointer = allocate<char32_t>(_length + 1ul);
			string_copy(pointer, _pointer, _length);
			return pointer;
		}

		/// \brief Create char32_t string instance from raw  string and its length.
		///
		/// Stringvar const takes care of cleaning up memory and string operations.
		/// \param _pointer raw string to be converted.
		/// \return char32_t string handling the string.
		LIBLETLIB_NODISCARD inline char32_t* to_bit32_string(char const* const _pointer, std::size_t const) noexcept
		{
			return mbstoc32s(_pointer);
		}


		/// \brief Create char16_t string instance from raw char32_t string and its length.
		///
		/// Stringvar const takes care of cleaning up memory and string operations.
		/// \param _pointer raw wide string to be converted.
		/// \param _length of the raw wide string.
		/// \return char32_t string handling the wide string.
		LIBLETLIB_NODISCARD inline char32_t* to_bit32_string(wchar_t const* const _pointer,
		                                                     std::size_t const _length) noexcept
		{
			char* const pointer = allocate<char>(_length * sizeof(wchar_t) + sizeof(wchar_t));
			std::wcstombs(pointer, _pointer, _length);
			char32_t* const return_value = mbstoc32s(pointer);
			deallocate(pointer);
			return return_value;
		}
		#if (__cplusplus >= 202002L)
		/// \brief Create char32_t string instance from raw char8_t string and its length.
		///
		/// Stringvar const takes care of cleaning up memory and string operations.
		/// \param _pointer raw char8_t string to be converted.
		/// \return char32_t string handling the char8_t string.
		LIBLETLIB_NODISCARD inline char32_t* to_bit32_string(char8_t const* const _pointer, std::size_t const) noexcept
		{
			char* const temporary        = c8stombs(_pointer);
			char32_t* const return_value = mbstoc32s(temporary);
			deallocate(temporary);
			return return_value;
		}

		#endif

		/// \brief Create char32_t string instance from raw char16_t string and its length.
		///
		/// Stringvar const takes care of cleaning up memory and string operations.
		/// \param _pointer raw char16_t string to be converted.
		/// \return char32_t string handling the char16_t string.
		LIBLETLIB_NODISCARD inline char32_t* to_bit32_string(char16_t const* const _pointer, std::size_t const) noexcept
		{
			char* const temporary        = c16stombs(_pointer);
			char32_t* const return_value = mbstoc32s(temporary);
			deallocate(temporary);
			return return_value;
		}

	#endif

		/// \brief Get previous number at the index of requested number as if represented as previous string.
		///
		/// Used for indexes of numbers.
		/// \param _number to property index from.
		/// \param _index index to look at.
		/// \return number located at that index.
		template<typename Number>
		LIBLETLIB_NODISCARD inline char index_of_number(Number _number, long const _index) noexcept
		{
			char* const string       = to_string(_number);
			char result              = '\0';
			long const number_length = static_cast<long>(string_length(string));
			if (_index >= 0l && _index <= number_length)
			{
				result = string[_index];
			}
			if (_index > number_length)
			{
				result = string[number_length];
			}
			long const absolute_index = std::labs(_index);
			if (_index < 0l && absolute_index < number_length)
			{
				result = string[number_length - absolute_index];
			}
			deallocate(string);
			return result;
		}

		/// \brief Replacement for std::strstr to char8_t, char16_t, and char32_t.
		/// \tparam String type
		/// \param haystack to search
		/// \param needle to find
		/// \return pointer to needle if exists, else NULL.
		template<typename String>
		String* substring_search(String* haystack, String const* needle)
		{
			if (haystack == nothing || needle == nothing)
				return nothing;

			for (; *haystack; ++haystack)
			{
				String const* h;
				String const* n;

				for (h = haystack, n = needle; *h && *n && (*h == *n); ++h, ++n)
				{
				}

				if (*n == '\0')
					return haystack;
			}
			return nothing;
		}

		/// \brief Specialize substring_search to use standard library functions.
		/// \param haystack to search.
		/// \param needle to find.
		/// \return pointer to needle if exists, else NULL.
		template<>
		char* substring_search<char>(char* haystack, char const* needle)
		{
			return std::strstr(haystack, needle);
		}

		/// \brief Specialize substring_search to use standard library functions.
		/// \param haystack to search.
		/// \param needle to find.
		/// \return pointer to needle if exists, else NULL.
		template<>
		wchar_t* substring_search<wchar_t>(wchar_t* haystack, wchar_t const* needle)
		{
			return std::wcsstr(haystack, needle);
		}

#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_STRINGS_HPP
