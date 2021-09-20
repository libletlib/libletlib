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

#ifndef LIBLETLIB_LIBLETLIB_MATH_HPP
#define LIBLETLIB_LIBLETLIB_MATH_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Return 0.0 as double.
		///
		/// Useful to stop needless truncations for float calculations.
		template<typename Type>
		LIBLETLIB_NODISCARD inline constexpr Type floating_zero() noexcept
		{
			return 0.0;
		}

		/// \brief Return 0.0 as float.
		///
		/// Useful to stop needless truncations for float calculations.
		template<>
		LIBLETLIB_NODISCARD inline constexpr float floating_zero() noexcept
		{
			return 0.0f;
		}

		/// \brief Return 0.0 as long double.
		///
		/// Useful to stop needless truncations for float calculations.
		template<>
		LIBLETLIB_NODISCARD inline constexpr long double floating_zero() noexcept
		{
			return 0.0L;
		}

#ifdef LIBLETLIB_FREESTANDING

		/// \brief Return 1.0 as double.
		///
		/// Useful to stop needless truncuations for float calculations.
		template<typename Type>
		LIBLETLIB_NODISCARD inline constexpr Type floating_one() noexcept
		{
			return 1.0;
		}

		/// \brief Return 1.0 as float.
		///
		/// Useful to stop needless truncuations for float calculations.
		template<>
		LIBLETLIB_NODISCARD inline constexpr float floating_one() noexcept
		{
			return 1.0f;
		}

		/// \brief Return 1.0 as long double.
		///
		/// Useful to stop needless truncuations for float calculations.
		template<>
		LIBLETLIB_NODISCARD inline constexpr long double floating_one() noexcept
		{
			return 1.0L;
		}

		/// \brief Round given floating point number down.
		///
		/// \param _value to round down.
		/// \return value rounded down.
		template<typename Floating>
		LIBLETLIB_NODISCARD inline Floating const floating_floor(Floating const _value) noexcept
		{
			double truncated = static_cast<Floating>(static_cast<long>(_value));
			return (truncated != _value) ? (truncated - floating_one<Floating>()) : truncated;
		}

		/// \brief Round given floating point number down.
		///
		/// \param _value to round down.
		/// \return value rounded down.
		template<>
		LIBLETLIB_NODISCARD inline float const floating_floor<float>(float const _value) noexcept
		{
			float truncated = static_cast<float>(static_cast<int>(_value));
			return (truncated != _value) ? (truncated - 1.0f) : truncated;
		}

		/// \brief Round given floating point number up.
		///
		/// \param _value to round up.
		/// \return value rounded up.
		template<typename Floating>
		LIBLETLIB_NODISCARD inline Floating const floating_ceiling(Floating const _value) noexcept
		{
			double truncated = static_cast<Floating>(static_cast<long>(_value));
			return (truncated != _value) ? (truncated + floating_one<Floating>()) : truncated;
		}

		/// \brief Round given floating point number up.
		///
		/// \param _value to round up.
		/// \return value rounded up.
		template<>
		LIBLETLIB_NODISCARD inline float const floating_ceiling<float>(float const _value) noexcept
		{
			float truncated = static_cast<float>(static_cast<int>(_value));
			return (truncated != _value) ? (truncated + 1.0f) : truncated;
		}

		/// \brief Produce the result of _left mod _right.
		///
		///	Based on the definition given in IEEE754, although works for other representations.
		/// \param _left part of modulo.
		/// \param _right part of modulo.
		/// \return result of _left mod _right.
		template<typename Floating>
		LIBLETLIB_NODISCARD inline Floating const floating_modulo(Floating const _left, Floating const _right) noexcept
		{
			return (_left - _right * float_floor(_left / _right));
		}

		/// \brief Produce the fractional part of a floating point number.
		///
		/// \param _fractional to take fractional part of.
		/// \param _integral for compatibility with std::modf().
		/// \return fractional part of _fractional.
		template<typename Floating>
		LIBLETLIB_NODISCARD inline Floating const floating_fractional_part(Floating const _fractional,
		                                                                   Floating* _integral) noexcept
		{
			long const integral_part = static_cast<long const>(float_floor(_fractional));
			return _fractional - static_cast<Floating const>(integral_part);
		}

		/// \brief Produce the fractional part of a floating point number.
		///
		/// \param _fractional to take fractional part of.
		/// \param _integral for compatibility with std::modf().
		/// \return fractional part of _fractional.
		template<>
		LIBLETLIB_NODISCARD inline float const floating_fractional_part<float>(float const _fractional,
		                                                                       float* _integral) noexcept
		{
			int const integral_part = static_cast<int const>(float_floor(_fractional));
			return _fractional - static_cast<float const>(integral_part);
		}

		/// \brief Produce absolute value of a floating point number.
		///
		/// \param _value to take absolute value of.
		/// \return absolute value of _value.
		template<typename Floating>
		LIBLETLIB_NODISCARD inline Floating const floating_absolute_value(Floating const _value) noexcept
		{
			return _value < floating_zero<Floating>() ? -_value : _value;
		}

		/// \brief Calculate the e^x of a given value.
		///
		/// Uses Taylor series to converge on a value.
		/// \param _exponent of the e^x.
		/// \return value of e^x.
		template<typename Floating>
		LIBLETLIB_NODISCARD inline Floating const euler_power(Floating const _exponent) noexcept
		{
			Floating result, fraction, iterator, reference_point;
			fraction = _exponent;
			result   = (floating_one<Floating>() + _exponent);
			iterator = floating_one<Floating>();
			do
			{
				fraction *= (_exponent / ++iterator);
				reference_point = result;
				result += fraction;
			} while (reference_point != result);
			return result;
		}

		/// \brief Calculate the natural logarithm of a given value.
		///
		/// Uses Taylor series to converge on a value.
		/// \param _value to take natural logarithm of.
		/// \return natural logarithm of _value.
		template<typename Floating>
		LIBLETLIB_NODISCARD inline Floating const natural_logarithm(Floating const _value) noexcept
		{
			Floating result, nominator, previous;
			Floating constexpr euler_constant = 2.71828182845905;
			nominator                         = _value;
			result                            = floating_zero<Floating>();

			// Find integral
			for (; nominator >= euler_constant; ++result)
				nominator /= euler_constant;
			result += (nominator / euler_constant);
			nominator = _value;

			do
			{
				previous = result;
				result   = (((nominator / (euler_power(result - floating_one<Floating>())))
                           + ((result - floating_one<Floating>()) * euler_constant))
                          / euler_constant);
			} while (result != previous);
			return result;
		}

		/// \brief Calculate exponent of any real base and exponent.
		///
		/// Operates on the mathematical principle, that:
		/// a ^ b = e ^ (log_e(a) * b)
		/// \param _base of the exponential function.
		/// \param _exponent of the exponential function.
		/// \return result of the exponential function _base ^ _exponent.
		template<typename Floating>
		LIBLETLIB_NODISCARD inline Floating const floating_power(Floating const _base,
		                                                         Floating const _exponent) noexcept
		{
			return euler_power(natural_logarithm(_base) * _exponent);
		}

#endif

		/// \brief Perform unsigned/positive signed integer exponentiation by squaring.
		///
		/// Exponentiation by squaring is generally faster than iterative.
		/// \param _base for exponentiation.
		/// \param _exponent for exponentiation.
		/// \return result of exponentiation.
		template<typename Integer>
		LIBLETLIB_NODISCARD inline Integer unsigned_integer_power(Integer _base, Integer _exponent) noexcept
		{
			Integer result = 1;
			while (true)
			{
				if (_exponent & 1)
					result *= _base;
				_exponent >>= 1;
				if (!_exponent)
					break;
				_base *= _base;
			}
			return result;
		}

		/// \brief Implements different floating point rounding behaviours.
		///
		/// Behaviour based on FLT_ROUNDS, defaulting to rounding to nearest if
		/// value is not in range 0-3.
		/// \param _floating point number to round.
		/// \return signed_integer_ type value produced by rounding.
		template<typename Floating, typename Integer>
		LIBLETLIB_NODISCARD inline Integer float_round(Floating const _floating) noexcept
		{
			switch (std::numeric_limits<Floating>::round_style)
			{
				case std::round_toward_zero:
					if (_floating < floating_zero<Floating>())
					{
						return static_cast<Integer>(float_ceiling(_floating));
					}
					return static_cast<Integer>(float_floor(_floating));
				case std::round_to_nearest:
				nearest:
					double integral, fractional;
					fractional = float_fractional_part(static_cast<double>(_floating), &integral);
					if (fractional >= 0.5)
					{
						return static_cast<Integer>(float_ceiling(_floating));
					}
					return static_cast<Integer>(float_floor(_floating));
				case std::round_toward_infinity:
					return static_cast<Integer>(float_ceiling(_floating));
				case std::round_toward_neg_infinity:
					return static_cast<Integer>(float_floor(_floating));
				case std::round_indeterminate:
					goto nearest;
			}
			goto nearest;
		}

#if (__cplusplus < 201103L) || defined LIBLETLIB_FREESTANDING

		/// \brief Address-of using casting to char with cv-qualifiers.
		///
		/// Casting any pointer to char* is explicitly allowed in the standard.
		/// First cast to const char* to satisfy the cv-qualifiers and then
		/// const_cast to plain char*.
		///
		/// \param _type to property address of.
		/// \return pointer to (address of) the object.
		template<class Type>
		LIBLETLIB_NODISCARD inline Type* address_of(Type& _type) noexcept
		{
			return reinterpret_cast<Type*>(&const_cast<char&>(reinterpret_cast<const char&>(_type)));
		}
#endif

#if defined LIBLETLIB_APPROXIMATELY_FLOAT_EQUAL

		/// \brief Less strict floating point equality function
		///
		/// Implemented as described in Art of Computer Programming by Knuth.
		///
		/// \param _left left hand float to test.
		/// \param _right right hand float to test.
		/// \return boolean_ are floating point numbers approximately equal.
		template<typename Floating>
		LIBLETLIB_NODISCARD inline bool float_equals(Floating const _left, Floating const _right) noexcept
		{
			Floating absolute_left = float_absolute_value(_left), absolute_right = float_absolute_value(_right);
			return float_absolute_value(_left - _right)
			       <= ((absolute_left < absolute_right ? absolute_right : absolute_left)
			           * std::numeric_limits<Floating>::epsilon());
		}
#else

		/// \brief More strict floating point equality function
		///
		/// Implemented as described in Art of Computer Programming by Knuth.
		///
		/// \param _left left hand float to test.
		/// \param _right right hand float to test.
		/// \return boolean_ are floating point numbers essentially equal.
		template<typename Floating>
		LIBLETLIB_NODISCARD inline bool float_equals(Floating const _left, Floating const _right) noexcept
		{
			Floating absolute_left = float_absolute_value(_left), absolute_right = float_absolute_value(_right);
			return float_absolute_value(_left - _right)
			       <= ((absolute_left > absolute_right ? absolute_right : absolute_left)
			           * std::numeric_limits<Floating>::epsilon());
		}

#endif

	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_MATH_HPP
