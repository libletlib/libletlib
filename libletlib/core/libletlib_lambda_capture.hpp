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

#ifndef LIBLETLIB_LIBLETLIB_LAMBDA_CAPTURE_HPP
#define LIBLETLIB_LIBLETLIB_LAMBDA_CAPTURE_HPP

namespace libletlib
{
	namespace detail
	{
#if (__cplusplus >= 201103L)
		/// \brief Helper to handle lambda capture
		/// \tparam Lambda to capture.
		template<typename Lambda>
		struct capture_helper : capture_helper<decltype(&Lambda::operator())>
		{
		};

		/// \brief Helper to handle lambda capture.
		/// \tparam Lambda to capture.
		/// \tparam Return type of the lambda
		/// \tparam Arguments of the lambda.
		template<typename Lambda, typename Return, typename... Arguments>
		struct capture_helper<Return (Lambda::*)(Arguments...)> : capture_helper<Return (Lambda::*)(Arguments...) const>
		{
		};

		/// \brief Actual lambda capture struct.
		///
		/// Turns lambdas into static, allowing retaining capture data even when
		/// converted to a pointer.
		/// \tparam Lambda to capture.
		/// \tparam Return type of the lambda
		/// \tparam Arguments of the lambda.
		template<typename Lambda, typename Return, typename... Arguments>
		struct capture_helper<Return (Lambda::*)(Arguments...) const>
		{
			typedef Return (*pointer)(Arguments...);

			static pointer capture(Lambda&& _lambda) noexcept
			{
				static Lambda lambda = static_cast<Lambda&&>(_lambda);
				return [](Arguments... arguments) {
					return lambda(static_cast<Arguments&&>(arguments)...);
				};
			}
		};

		/// \brief Function to create the capturing struct.
		/// \tparam Lambda to capture.
		/// \param lambda to capture.
		/// \return static lambda containing captured data.
		template<typename Lambda>
		inline typename capture_helper<Lambda>::pointer capture(Lambda&& lambda) noexcept
		{
			return capture_helper<Lambda>::capture(static_cast<Lambda&&>(lambda));
		}
#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_LAMBDA_CAPTURE_HPP
