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

#ifndef LIBLETLIB_LIBLETLIB_MATH_IMPLEMENTATION_HPP
#define LIBLETLIB_LIBLETLIB_MATH_IMPLEMENTATION_HPP

namespace libletlib
{
	namespace detail
	{

		/// \brief Divide two numbers, return an integer if possible without remaineder, otherwise a floating point number.
		/// \tparam Floating type to convert to if needed.
		/// \tparam Numerator type.
		/// \tparam Denominator type.
		/// \param _numerator numerator.
		/// \param _denominator denominator.
		/// \return integer type if _numerator % _denominator == 0, else floating point number of Floating type.
		template<typename Floating, typename Numerator, typename Denominator>
		LIBLETLIB_NODISCARD inline var divide(Numerator _numerator, Denominator _denominator) noexcept
		{
			if (_numerator % _denominator == 0)
				return _numerator / _denominator;

			return static_cast<Floating>(_numerator) / static_cast<Floating>(_denominator);
		}

		/// \brief Exponent operation.
		/// \tparam Floating type to use, if needed.
		/// \tparam Base type.
		/// \tparam Exponent type.
		/// \param _base base of the exponent.
		/// \param _exponent of the operation.
		/// \return integer type if _exponent >= 0, else floating point number of Floating type.
		template<typename Floating, typename Base, typename Exponent>
		LIBLETLIB_NODISCARD inline var power(Base _base, Exponent _exponent) noexcept
		{
			if (_exponent >= 0)
				return unsigned_integer_power(_base, _exponent);
			return float_power(static_cast<Floating>((_base)), static_cast<Floating>((_exponent)));
		}

	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_MATH_IMPLEMENTATION_HPP
