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

#ifndef LIBLETLIB_LIBLETLIB_VALUE_UNION_HPP
#define LIBLETLIB_LIBLETLIB_VALUE_UNION_HPP

#include "../utility/libletlib_strings.hpp"
#include "libletlib_forward_declarations.hpp"

namespace libletlib
{
	namespace detail
	{

		/// \brief Core data structure hold any fundamental type.
		///
		/// Basically holds any fundamental type in an union, contains necessary functions to massage strings as necessary.
		union value_union
		{
			bool bool_type;                  ///< bool type
			char char_type;                  ///< char type
			signed char signed_char_type;    ///< signed char type
			unsigned char unsigned_char_type;///< unsigned char type
			wchar_t wchar_type;              ///< wchar_t type
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			char8_t char8_type;///< char8_t type
	#endif
			char16_t char16_type;///< char16_t type
			char32_t char32_type;///< char32_t type
#endif
			short short_type;                  ///< short type
			unsigned short unsigned_short_type;///< unsigned short type
			int int_type;                      ///< int type
			unsigned unsigned_int_type;        ///< unsigned int type
			long long_type;                    ///< long type
			unsigned long unsigned_long_type;  ///< unsigned long type
#if (__cplusplus >= 201103L)
			long long long_long_type;                  ///< long long type
			unsigned long long unsigned_long_long_type;///< unsigned long long type
#endif
			float float_type;            ///< float type
			double double_type;          ///< double type
			long double long_double_type;///< long double type
			char* string_type;           ///< char* type
			wchar_t* wide_string_type;   ///< wchar_t* type
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			char8_t* bit8_string_type;///< char8_t* type
	#endif
			char16_t* bit16_string_type;///< char16_t* type
			char32_t* bit32_string_type;///< char32_t* type
#endif
			void* void_pointer_type;     ///< void* type
			var* array_type;             ///< var* type
			subroutine_t subroutine_type;///< subroutine_t type
			function_t function_type;    ///< function_t type
#if (__cplusplus >= 201103L)

			std::nullptr_t nullptr_type;///< std::nullptr_t type
#endif

			/// \brief Empty and null constructor.
			///
			///
			value_union() noexcept
			{
#if (__cplusplus >= 201103L)
				nullptr_type = nothing;
#else
				void_pointer_type = nothing;
#endif
			}

			/// \brief Constructor with boolean_ type.
			///
			/// \param _value to use.
			explicit value_union(bool const _value) noexcept
			{
				bool_type = _value;
			}

			/// \brief Constructor with char type.
			///
			/// \param _value to use.
			explicit value_union(char const _value) noexcept
			{
				char_type = _value;
			}

			/// \brief Constructor with signed char type.
			///
			/// \param _value to use.
			explicit value_union(signed char const _value) noexcept
			{
				signed_char_type = _value;
			}

			/// \brief Constructor with unsigned char type.
			///
			/// \param _value to use.
			explicit value_union(unsigned char const _value) noexcept
			{
				unsigned_char_type = _value;
			}

			/// \brief Constructor with wchar_t type.
			///
			/// \param _value to use.
			explicit value_union(wchar_t const _value) noexcept
			{
				wchar_type = _value;
			}

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			/// \brief Constructor with char8_t type.
			///
			/// \param _value to use.
			explicit value_union(char8_t const _value) noexcept
			{
				char8_type = _value;
			}
	#endif
			/// \brief Constructor with char16_t type.
			///
			/// \param _value to use.
			explicit value_union(char16_t const _value) noexcept
			{
				char16_type = _value;
			}

			/// \brief Constructor with char32_t type.
			///
			/// \param _value to use.
			explicit value_union(char32_t const _value) noexcept
			{
				char32_type = _value;
			}

#endif

			/// \brief Constructor with short type.
			///
			/// \param _value to use.
			explicit value_union(short const _value) noexcept
			{
				short_type = _value;
			}

			/// \brief Constructor with unsigned short type.
			///
			/// \param _value to use.
			explicit value_union(unsigned short const _value) noexcept
			{
				unsigned_short_type = _value;
			}

			/// \brief Constructor with int type.
			///
			/// \param _value to use.
			explicit value_union(int const _value) noexcept
			{
				int_type = _value;
			}

			/// \brief Constructor with unsigned int type.
			///
			/// \param _value to use.
			explicit value_union(unsigned const _value) noexcept
			{
				unsigned_int_type = _value;
			}

			/// \brief Constructor with long type.
			///
			/// \param _value to use.
			explicit value_union(long const _value) noexcept
			{
				long_type = _value;
			}

			/// \brief Constructor with unsigned long type.
			///
			/// \param _value to use.
			explicit value_union(unsigned long const _value) noexcept
			{
				unsigned_long_type = _value;
			}

#if (__cplusplus >= 201103L)

			/// \brief Constructor with long long type.
			///
			/// \param _value to use.
			explicit value_union(long long const _value) noexcept
			{
				long_long_type = _value;
			}

			/// \brief Constructor with unsigned long long type.
			///
			/// \param _value to use.
			explicit value_union(unsigned long long const _value) noexcept
			{
				unsigned_long_long_type = _value;
			}

#endif

			/// \brief Constructor with float type.
			///
			/// \param _value to use.
			explicit value_union(float const _value) noexcept
			{
				float_type = _value;
			}

			/// \brief Constructor with double type.
			///
			/// \param _value to use.
			explicit value_union(double const _value) noexcept
			{
				double_type = _value;
			}

			/// \brief Constructor with long double type.
			///
			/// \param _value to use.
			explicit value_union(long double const _value) noexcept
			{
				long_double_type = _value;
			}

#ifndef LIBLETLIB_FREESTANDING

			/// \brief Constructor with raw string type.
			///
			///	Deep copies the given string.
			///
			/// \param _value to use.
			explicit value_union(char const* const _value) noexcept
			{
				std::size_t const length = string_length(_value);
				string_type              = allocate<char>(length + 1ul);
				string_copy(string_type, _value, length);
			}

			/// \brief Constructor with wide string type.
			///
			///	Deep copies the given string.
			/// \param _value to use.
			explicit value_union(wchar_t const* const _value) noexcept
			{
				std::size_t const length = string_length(_value);
				wide_string_type         = allocate<wchar_t>(length + 1ul);
				string_copy(wide_string_type, _value, length);
			}

			/// \brief Constructor with raw string type with length and padding.
			///
			///	Deep copies the given string.
			/// \param _value the string to use as value.
			/// \param _length of the _value string.
			/// \param _padding desired for the _value string.
			value_union(char const* const _value, std::size_t const _length, std::size_t const _padding) noexcept
			{
				std::size_t const length = _length + _padding;
				string_type              = allocate<char>(length + 1ul);
				string_copy(string_type, _value, _length);
			}

			/// \brief Constructor with wide string type with length and padding.
			///
			///	Deep copies the given string.
			/// \param _value the string to use as value.
			/// \param _length of the _value string.
			/// \param _padding desired for the _value string.
			value_union(wchar_t const* const _value, std::size_t const _length, std::size_t const _padding) noexcept
			{
				std::size_t const length = _length + _padding;
				wide_string_type         = allocate<wchar_t>(length + 1ul);
				string_copy(wide_string_type, _value, _length);
			}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			/// \brief Constructor with char8_t string type.
			///
			///	Deep copies the given string.
			/// \param _value to use.
			explicit value_union(char8_t const* const _value) noexcept
			{
				std::size_t const length = string_length(_value);
				bit8_string_type         = allocate<char8_t>(length + 1ul);
				string_copy(bit8_string_type, _value, length);
			}

			/// \brief Constructor with char8_t string type with length and padding.
			///
			///	Deep copies the given string.
			/// \param _value the string to use as value.
			/// \param _length of the _value string.
			/// \param _padding desired for the _value string.
			value_union(char8_t const* const _value, std::size_t const _length, std::size_t const _padding) noexcept
			{
				std::size_t const length = _length + _padding;
				bit8_string_type         = allocate<char8_t>(length + 1ul);
				string_copy(bit8_string_type, _value, _length);
			}
		#endif

			/// \brief Constructor with char16_t string type.
			///
			///	Deep copies the given string.
			/// \param _value to use.
			explicit value_union(char16_t const* const _value) noexcept
			{
				std::size_t const length = string_length(_value);
				bit16_string_type        = allocate<char16_t>(length + 1ul);
				string_copy(bit16_string_type, _value, length);
			}

			/// \brief Constructor with char16_t string type with length and padding.
			///
			///	Deep copies the given string.
			/// \param _value the string to use as value.
			/// \param _length of the _value string.
			/// \param _padding desired for the _value string.
			value_union(char16_t const* const _value, std::size_t const _length, std::size_t const _padding) noexcept
			{
				std::size_t const length = _length + _padding;
				bit16_string_type        = allocate<char16_t>(length + 1ul);
				string_copy(bit16_string_type, _value, _length);
			}

			/// \brief Constructor with char32_t string type.
			///
			///	Deep copies the given string.
			/// \param _value the string to use as value.
			explicit value_union(char32_t const* const _value) noexcept
			{
				std::size_t const length = string_length(_value);
				bit32_string_type        = allocate<char32_t>(length + 1ul);
				string_copy(bit32_string_type, _value, length);
			}

			/// \brief Constructor with char32_t string type with length and padding.
			///
			///	Deep copies the given string.
			/// \param _value the string to use as value.
			/// \param _length of the _value string.
			/// \param _padding desired for the _value string.
			value_union(char32_t const* const _value, std::size_t const _length, std::size_t const _padding) noexcept
			{
				std::size_t const length = _length + _padding;
				bit32_string_type        = allocate<char32_t>(length + 1ul);
				string_copy(bit32_string_type, _value, _length);
			}

	#endif
#endif

#ifndef LIBLETLIB_FREESTANDING

			explicit value_union(subroutine_t _value) noexcept
			{
				subroutine_type = _value;
			}

			explicit value_union(function_t _value) noexcept
			{
				function_type = _value;
			}

			value_union(var* _value, std::size_t _in_use, std::size_t _allocated) noexcept
			{
				array_type = array_clone(_value, _in_use, _allocated);
			}

#endif

#if (__cplusplus >= 201103L)
	#ifndef LIBLETLIB_FREESTANDING

			explicit value_union(std::initializer_list<var> _list) noexcept;

			/// \brief Constructor with standard null pointer type.
			///
			/// \param _value to use.
			explicit value_union(std::nullptr_t const _value) noexcept
			{
				nullptr_type = _value;
			}
	#endif
#endif
		};

	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_VALUE_UNION_HPP
