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

#ifndef LIBLETLIB_LIBLETLIB_TYPE_ID_ENUM_HPP
#define LIBLETLIB_LIBLETLIB_TYPE_ID_ENUM_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Type ids for the types wrapped by var.
		enum
#if (__cplusplus >= 201103L)
		    class
#endif
		    type_id_enumeration
		{
			bool_type_id = 'b',
			///< bool type
			char_type_id = 'c',
			///< char type
			signed_char_type_id = 'x',
			///< signed char type
			unsigned_char_type_id = 'X',
			///< unsigned char type
			wchar_type_id = 'w',
			///< wchar_t type
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			char8_type_id = '8',
	#endif
			char16_type_id = 'u',
			///< char16_t type
			char32_type_id = 'U',
				///< char32_t type
#endif
			short_type_id = 's',
			///< short type
			unsigned_short_type_id = 'S',
			///< unsigned short type
			int_type_id = 'i',
			///< int type
			unsigned_int_type_id = 'I',
			///< unsigned int type
			long_type_id = 'l',
			///< long type
			unsigned_long_type_id = 'L',
			///< unsigned long type
#if (__cplusplus >= 201103L)
			long_long_type_id = 'q',
			///< long long type
			unsigned_long_long_type_id = 'Q',
				///< unsigned long long type
#endif
			float_type_id = 'f',
			///< float type
			double_type_id = 'd',
			///< double type
			long_double_type_id = 'D',
			///< long double type
			string_type_id = '.',
			///< char* type
			wide_string_type_id = ',',
			///< wchar_t* type
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			bit8_string_type_id = '-',
					///< char8_t* type
	#endif
			bit16_string_type_id = ':',
			///< char16_t* type
			bit32_string_type_id = ';',
				///< char32_t* type
#endif
			subroutine_type_id = '!',
			///< subroutine type (void (*subr) (var, var*))
			function_type_id = '=',
			///< function type (var (*fn) (var, var*))
			array_type_id = '#',
			///< var[] type
			void_pointer_type_id = '@',
			///< void* type
#if (__cplusplus >= 201103L)
			nullptr_type_id = 'n',
				///< std::nullptr_t type
#endif
			any_type_id = '_'
		};
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_TYPE_ID_ENUM_HPP
