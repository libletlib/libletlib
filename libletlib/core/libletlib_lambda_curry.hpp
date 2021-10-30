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


#ifndef LIBLETLIB_LIBLETLIB_LAMBDA_CURRY_HPP
#define LIBLETLIB_LIBLETLIB_LAMBDA_CURRY_HPP

namespace libletlib
{
	namespace detail
	{
	#if (__cplusplus >= 201103L)
		/// \brief Curries functions by creating static versions with the arguments injected into the lambda.
		/// \tparam UniqueDummy unique type to trigger arbitrary amount of template instantiations.
		/// \tparam Arguments to curry with.
		/// \param _invokable to curry.
		/// \param _arguments to curry with.
		/// \return var containing the curried function/subroutine.
		template<typename UniqueDummy, typename... Arguments>
		LIBLETLIB_NODISCARD inline var curry_(LIBLETLIB_MAYBE_UNUSED UniqueDummy&&, var const& _invokable,
		                                      Arguments const&... _arguments) noexcept
		{
			if (_invokable.behaviour->rank == enum_function_type)
			{
				static function_t original = _invokable.value.function_type;
				return var(capture([_arguments...](LIBLETLIB_MAYBE_UNUSED var const& self, var const& args) -> var {
					           return original(original, backing::list(_arguments...) << args);
				           }),
				           _invokable.size.in_use + sizeof...(_arguments));
			}
			if (_invokable.behaviour->rank == enum_subroutine_type)
			{
				static subroutine_t original = _invokable.value.subroutine_type;
				return var(capture([_arguments...](LIBLETLIB_MAYBE_UNUSED var const& self, var const& args) -> void {
					           original(original, backing::list(_arguments...) << args);
				           }),
				           _invokable.size.in_use + sizeof...(_arguments));
			}
			return nothing;
		}
	#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_LAMBDA_CURRY_HPP
