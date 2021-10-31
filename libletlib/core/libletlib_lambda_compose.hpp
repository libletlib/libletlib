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

#ifndef LIBLETLIB_LIBLETLIB_LAMBDA_COMPOSE_HPP
#define LIBLETLIB_LIBLETLIB_LAMBDA_COMPOSE_HPP

namespace libletlib
{
	namespace detail
	{
	#if (__cplusplus >= 201103L)
		/// \brief Composes N amount of functions right-to-left.
		/// \tparam UniqueDummy unique type to trigger arbitrary amount of template instantiations.
		/// \tparam Arguments functions to compose.
		/// \param _arguments functions to compose.
		/// \return var containing the composed function.
		template<typename UniqueDummy, typename... Arguments>
		LIBLETLIB_NODISCARD inline var compose_(LIBLETLIB_MAYBE_UNUSED UniqueDummy&&, Arguments const&... _arguments) noexcept
		{
			var const composables = backing::list(_arguments...);

			if(sizeof...(_arguments) < 2)
				return composables[0];

			static function_t composing[sizeof...(_arguments)];

			for (std::size_t index = 0; index < sizeof...(_arguments); ++index)
				composing[index] = composables.value.array_type[index].value.function_type;

			var composed = var(capture([](LIBLETLIB_MAYBE_UNUSED var const& self, var const& args) LIBLETLIB_NOEXCEPT -> var {
				function_t const* composing_end = composing + sizeof...(_arguments) - 1;
				var result = (*composing_end)((*composing_end), args);
				--composing_end;
				for(;composing_end >= composing; --composing_end)
					result = (*composing_end)((*composing_end), backing::list(result));
				return result;
			}));

			return composed;
		}
	#endif

	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_LAMBDA_COMPOSE_HPP
