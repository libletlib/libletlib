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

#ifndef LIBLETLIB_LIBLETLIB_RANK_ENUM_HPP
#define LIBLETLIB_LIBLETLIB_RANK_ENUM_HPP

namespace libletlib
{
	namespace detail
	{

		/// \brief Type hierarchy for the var class.
		///
		/// Excludes types that don't exist in previous specific standard.
		enum
#if (__cplusplus >= 201103L)
		    class
#endif
		    rank_enumeration
		{
			bool_type = 0,
			///< bool type
			char_type = 1,
			///< char type
			signed_char_type = 2,
			///< signed char type
			unsigned_char_type = 3,
			///< unsigned char type
			wchar_type = 4,
			///< wchar_t type
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
			char8_type = 5,
	#endif
			char16_type = 6,
			///< char16_t type
			char32_type = 7,
				///< char32_t type
#endif
			short_type = 8,
			///< short type
			unsigned_short_type = 9,
			///< unsigned short type
			int_type = 10,
			///< int type
			unsigned_int_type = 11,
			///< unsigned int type
			long_type = 12,
			///< long type
			unsigned_long_type = 13,
			///< unsigned long type
#if (__cplusplus >= 201103L)
			long_long_type = 14,
			///< long long type
			unsigned_long_long_type = 15,
				///< unsigned long long type
#endif
			float_type = 16,
			///< float type
			double_type = 17,
			///< double type
			long_double_type = 18,
			///< long double type
			string_type = 19,
			///< char* type
			wide_string_type = 20,
			///< wchar_t* type
#if (__cplusplus >= 201103L)
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			bit8_string_type = 21,
		#endif
			bit16_string_type = 22,
			///< char16_t* type
			bit32_string_type = 23,
					///< char32_t* type
	#endif
	#ifndef LIBLETLIB_FREESTANDING
			subroutine_type = 24,
			///< subroutine type (void (*subr) (var, var*))
			function_type = 25,
			///< function type (var (*fn) (var, var*))
			array_type = 26,
					///< var[] type
	#endif
			void_pointer_type = 27,
			///< void* type
			nullptr_type = 28///< std::nullptr_t type
#else
	#ifndef LIBLETLIB_FREESTANDING
			subroutine_type   = 24,///< subroutine type (void (*subr) (var, var*))
			function_type     = 25,///< function type (var (*fn) (var, var*))
			array_type        = 27,///< var[] type
	#endif
			void_pointer_type = 27 ///< void* type
#endif
		};

	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_RANK_ENUM_HPP
