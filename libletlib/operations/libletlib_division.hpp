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

#ifndef LIBLETLIB_LIBLETLIB_DIVISION_HPP
#define LIBLETLIB_LIBLETLIB_DIVISION_HPP

#include "../core/libletlib_math_implementation.hpp"

namespace libletlib
{
	namespace detail
	{
		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var boolean_division(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			if (!_right.operator bool())
			{
				LIBLETLIB_ERROR("Division by false (zero)!", static_cast<int>(LIBLETLIB_EDOM))
			}
			if (!_left.operator bool())
			{
				return false;
			}
			return true;
		}

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var character_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: character division", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var signed_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: character division", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: character division", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Division operator.R
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: character division", static_cast<int>(LIBLETLIB_ENOTSUP))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: character division", static_cast<int>(LIBLETLIB_ENOTSUP))
			#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
			#endif
		}

		#endif
		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: character division", static_cast<int>(LIBLETLIB_ENOTSUP))
		#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
		#endif
		}

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_character_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: character division", static_cast<int>(LIBLETLIB_ENOTSUP))
		#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
		#endif
		}

	#endif
#endif

		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var short_division(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			short denominator = _right.operator short();
			if (denominator == 0)
			{
				LIBLETLIB_ERROR("Divide by zero", static_cast<int>(LIBLETLIB_EDOM))
			}
			return divide<double>(_left.operator short(), denominator);
		}

		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_short_division(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			unsigned short denominator = _right.operator unsigned short();
			if (denominator == 0)
			{
				LIBLETLIB_ERROR("Divide by zero", static_cast<int>(LIBLETLIB_EDOM))
			}
			return divide<double>(_left.operator unsigned short(), denominator);
		}

		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var integer_division(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			int denominator = _right.operator int();
			if (denominator == 0)
			{
				LIBLETLIB_ERROR("Divide by zero", static_cast<int>(LIBLETLIB_EDOM))
			}
			return divide<double>(_left.operator int(), denominator);
		}

		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_integer_division(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			unsigned denominator = _right.operator unsigned();
			if (denominator == 0u)
			{
				LIBLETLIB_ERROR("Divide by zero", static_cast<int>(LIBLETLIB_EDOM))
			}
			return divide<double>(_left.operator unsigned(), denominator);
		}

		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_division(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			long denominator = _right.operator long();
			if (denominator == 0l)
			{
				LIBLETLIB_ERROR("Divide by zero", static_cast<int>(LIBLETLIB_EDOM))
			}
			return divide<double>(_left.operator long(), denominator);
		}

		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_division(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			unsigned long denominator = _right.operator unsigned long();
			if (denominator == 0ul)
			{
				LIBLETLIB_ERROR("Divide by zero", static_cast<int>(LIBLETLIB_EDOM))
			}
			return divide<double>(_left.operator unsigned long(), denominator);
		}

#if (__cplusplus >= 201103L)

		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_long_division(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			long long denominator = _right.operator long long();
			if (denominator == 0ll)
			{
				LIBLETLIB_ERROR("Divide by zero", static_cast<int>(LIBLETLIB_EDOM))
			}
			return divide<long double>(_left.operator long long(), denominator);
		}

		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_long_division(var const& _left,
		                                                           var const& _right) LIBLETLIB_NOEXCEPT
		{
			unsigned long long denominator = _right.operator unsigned long long();
			if (denominator == 0ull)
			{
				LIBLETLIB_ERROR("Divide by zero", static_cast<int>(LIBLETLIB_EDOM))
			}
			return divide<long double>(_left.operator unsigned long long(), denominator);
		}

#endif

		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var float_division(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator float() / _right.operator float());
		}

		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var double_division(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator double() / _right.operator double());
		}

		/// \brief Division operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_double_division(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator long double() / _right.operator long double());
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var string_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string division", static_cast<int>(LIBLETLIB_ENOTSUP))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string division", static_cast<int>(LIBLETLIB_ENOTSUP))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string division", static_cast<int>(LIBLETLIB_ENOTSUP))
			#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
			#endif
		}
		#endif
		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string division", static_cast<int>(LIBLETLIB_ENOTSUP))
		#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
		#endif
		}

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_string_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string division", static_cast<int>(LIBLETLIB_ENOTSUP))
		#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
		#endif
		}

	#endif
#endif

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var pointer_division(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
#ifndef LIBLETLIB_FREESTANDING
	#if (__cplusplus >= 201103L)
			if (_left.behaviour->rank == enum_void_pointer_type && _right.behaviour->rank == enum_void_pointer_type)
			{
				if (_left.value.void_pointer_type)
					return _left.message("/")(_left, _right);
			}
			else if (_right.behaviour->rank == enum_void_pointer_type)
			{
				if (_right.value.void_pointer_type)
					return _right.message("/")(_left, _right);
			}
			else
			{
				if (_left.value.void_pointer_type)
					return _left["/"](_left, _right);
			}
	#endif
#endif
			LIBLETLIB_ERROR("Operator division unimplemented.", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var array_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: array division", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var subroutine_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: subroutine division", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var function_division(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: function division", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

#if (__cplusplus >= 201103L)

		/// \brief Division operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var null_division(var const&, var const&) noexcept
		{
			return var();
		}

#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_DIVISION_HPP
