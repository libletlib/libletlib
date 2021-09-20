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

#ifndef LIBLETLIB_LIBLETLIB_FORMAT_CONSTANTS_HPP
#define LIBLETLIB_LIBLETLIB_FORMAT_CONSTANTS_HPP

namespace libletlib
{
	namespace detail
	{
#ifndef LIBLETLIB_FREESTANDING
		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<typename Type>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format() noexcept
		{
			return "%d";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<char>() noexcept
		{
			return "%c";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<signed char>() noexcept
		{
			return "%c";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<unsigned char>() noexcept
		{
			return "%c";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<wchar_t>() noexcept
		{
			return "%lc";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<unsigned short>() noexcept
		{
			return "%hu";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<unsigned int>() noexcept
		{
			return "%u";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<long>() noexcept
		{
			return "%ld";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<unsigned long>() noexcept
		{
			return "%lu";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<float>() noexcept
		{
			return "%f";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<double>() noexcept
		{
			return "%f";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<long double>() noexcept
		{
			return "%Lf";
		}

	#if (__cplusplus >= 201103L)

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexpr char const* numeric_format<long long>() noexcept
		{
			return "%lld";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexpr char const* numeric_format<unsigned long long>() noexcept
		{
			return "%llu";
		}

	#endif

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<char*>() noexcept
		{
			return "%s";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<wchar_t*>() noexcept
		{
			return "%ls";
		}

		/// \brief Returns appropriate format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst char* numeric_format<void*>() noexcept
		{
			return "%p";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<typename Type>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format() noexcept
		{
			return L"%d";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<char>() noexcept
		{
			return L"%c";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<signed char>() noexcept
		{
			return L"%c";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<unsigned char>() noexcept
		{
			return L"%c";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<wchar_t>() noexcept
		{
			return L"%lc";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<unsigned short>() noexcept
		{
			return L"%hu";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<unsigned int>() noexcept
		{
			return L"%u";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<long>() noexcept
		{
			return L"%ld";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<unsigned long>() noexcept
		{
			return L"%lu";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<float>() noexcept
		{
			return L"%f";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<double>() noexcept
		{
			return L"%f";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<long double>() noexcept
		{
			return L"%Lf";
		}

	#if (__cplusplus >= 201103L)

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexpr wchar_t const* wide_numeric_format<long long>() noexcept
		{
			return L"%lld";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexpr wchar_t const* wide_numeric_format<unsigned long long>() noexcept
		{
			return L"%llu";
		}

	#endif

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<char*>() noexcept
		{
			return L"%s";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<wchar_t*>() noexcept
		{
			return L"%ls";
		}

		/// \brief Returns appropriate wide format print specifier for given type.
		///
		/// \return Appropriate format string for the template specialization.
		template<>
		LIBLETLIB_NODISCARD inline constexprconst wchar_t* wide_numeric_format<void*>() noexcept
		{
			return L"%p";
		}

		/// \brief Returns maximum amount of digits possible in given numeric type.
		///
		/// Used to allocate appropriate amount of memory for string representations
		/// without calculating length at runtime.
		///
		/// \return Maximum string length of previous number.
		template<typename Type>
		LIBLETLIB_NODISCARD inline std::size_t constexpr max_digits() noexcept
		{
			return std::numeric_limits<Type>::digits10 + 2ul;
		}

		/// \brief Returns maximum amount of digits possible in given numeric type.
		///
		/// Used to allocate appropriate amount of memory for wide string representations
		/// without calculating length at runtime.
		///
		/// \return Maximum string length of previous number.
		template<typename Type>
		LIBLETLIB_NODISCARD inline std::size_t constexpr wide_max_digits() noexcept
		{
			return sizeof(wchar_t) * std::numeric_limits<Type>::digits10 + sizeof(wchar_t) * 2ul;
		}
#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_FORMAT_CONSTANTS_HPP
