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

#ifndef LIBLETLIB_LIBLETLIB_MODULO_HPP
#define LIBLETLIB_LIBLETLIB_MODULO_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Modulo operator.
		///
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var boolean_modulo(var const&, var const& _right) noexcept
		{
			if (!_right.operator bool())
#if defined LIBLETLIB_FREESTANDING
				std::exit(EXIT_FAILURE);
#else
			{
				std::raise(SIGFPE);
			}
#endif
			return var(false);
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var character_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator char() % _right.operator char());
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var signed_character_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator signed char() % _right.operator signed char());
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_character_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned char() % _right.operator unsigned char());
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_character_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator wchar_t() % _right.operator wchar_t());
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_character_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator char8_t() % _right.operator char8_t());
		}
		#endif

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_character_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator char16_t() % _right.operator char16_t());
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_character_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator char32_t() % _right.operator char32_t());
		}

	#endif
#endif

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var short_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator short() % _right.operator short());
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_short_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned short() % _right.operator unsigned short());
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var integer_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator int() % _right.operator int());
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_integer_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned() % _right.operator unsigned());
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator long() % _right.operator long());
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long() % _right.operator unsigned long());
		}

#if (__cplusplus >= 201103L)

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_long_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator long long() % _right.operator long long());
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_long_modulo(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long long() % _right.operator unsigned long long());
		}

#endif

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var float_modulo(var const& _left, var const& _right) noexcept
		{
			return var(float_remainder(_left.operator float(), _right.operator float()));
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var double_modulo(var const& _left, var const& _right) noexcept
		{
			return var(float_remainder(_left.operator double(), _right.operator double()));
		}

		/// \brief Modulo operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_double_modulo(var const& _left, var const& _right) noexcept
		{
			return var(float_remainder(_left.operator long double(), _right.operator long double()));
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Modulo operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string modulo", static_cast<int>(LIBLETLIB_ENOTSUP))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

		/// \brief Modulo operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string modulo", static_cast<int>(LIBLETLIB_ENOTSUP))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Modulo operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string modulo", static_cast<int>(LIBLETLIB_ENOTSUP))
			return var();
		}
		#endif

		/// \brief Modulo operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string modulo", static_cast<int>(LIBLETLIB_ENOTSUP))
			return var();
		}

		/// \brief Modulo operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_string_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string modulo", static_cast<int>(LIBLETLIB_ENOTSUP))
			return var();
		}

	#endif
#endif

		/// \brief Modulo operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var pointer_modulo(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
#ifndef LIBLETLIB_FREESTANDING
	#if (__cplusplus >= 201103L)
			if (_left.behaviour->rank == enum_void_pointer_type && _right.behaviour->rank == enum_void_pointer_type)
			{
				if (_left.value.void_pointer_type)
					return _left.message("%")(_left, _right);
			}
			else if (_right.behaviour->rank == enum_void_pointer_type)
			{
				if (_right.value.void_pointer_type)
					return _right.message("%")(_left, _right);
			}
			else
			{
				if (_left.value.void_pointer_type)
					return _left.message("%")(_left, _right);
			}
	#endif
#endif
			LIBLETLIB_ERROR("Operator modulo unimplemented.", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Modulo operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var array_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: array modulo", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Modulo operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var subroutine_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: subroutine modulo", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Modulo operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var function_modulo(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: function modulo", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

#if (__cplusplus >= 201103L)
		/// \brief Modulo operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var null_modulo(var const&, var const&) noexcept
		{
			return var();
		}

#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_MODULO_HPP
