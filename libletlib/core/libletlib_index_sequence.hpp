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

#ifndef LIBLETLIB_LIBLETLIB_INDEX_SEQUENCE_HPP
#define LIBLETLIB_LIBLETLIB_INDEX_SEQUENCE_HPP

namespace libletlib
{
	namespace detail
	{
#if (__cplusplus >= 201103L)
		/// \brief Return amount of arguments this function was called with.
		/// \tparam Arguments called with.
		/// \param _arguments called with.
		/// \return amount of arguments called with.
		template<typename... Arguments>
		constexpr std::size_t count_arguments(Arguments&&... _arguments) noexcept
		{
			return sizeof...(_arguments);
		}

		/// \brief Hold compile time range of sequential indices as per C++14 std::integer_sequence
		template<std::size_t... Indices>
		struct index_sequence
		{
		};

		/// \brief Create compile time range of sequential indices as per C++14 std::make_integer_sequence
		template<std::size_t N, std::size_t... Indices>
		struct make_index_sequence : make_index_sequence<N - 1, N - 1, Indices...>
		{
		};

		/// \brief Create compile time range of sequential indices as per C++14 std::make_integer_sequence
		template<std::size_t... Indices>
		struct make_index_sequence<0, Indices...> : index_sequence<Indices...>
		{
		};
#endif

	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_INDEX_SEQUENCE_HPP
