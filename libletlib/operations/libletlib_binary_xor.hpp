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

#ifndef LIBLETLIB_LIBLETLIB_BINARY_XOR_HPP
#define LIBLETLIB_LIBLETLIB_BINARY_XOR_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var boolean_binary_xor(var const& _left, var const& _right) noexcept
		{
			if ((_left.operator bool() && _right.operator bool())
			    || (!_left.operator bool() && !_right.operator bool()))
			{
				return var(false);
			}
			return var(true);
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var character_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned char() ^ _right.operator unsigned char());
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var signed_character_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned char() ^ _right.operator unsigned char());
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_character_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned char() ^ _right.operator unsigned char());
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_character_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(static_cast<std::wint_t>(_left.operator wchar_t())
			           ^ static_cast<std::wint_t>(_right.operator wchar_t()));
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_character_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator char8_t() ^ _right.operator char8_t());
		}
		#endif
		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_character_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator char16_t() ^ _right.operator char16_t());
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_character_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator char32_t() ^ _right.operator char32_t());
		}

	#endif
#endif

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var short_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned short() ^ _right.operator unsigned short());
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_short_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned short() ^ _right.operator unsigned short());
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var integer_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned() ^ _right.operator unsigned());
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_integer_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned() ^ _right.operator unsigned());
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long() ^ _right.operator unsigned long());
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long() ^ _right.operator unsigned long());
		}

#if (__cplusplus >= 201103L)

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_long_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long long() ^ _right.operator unsigned long long());
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_long_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long long() ^ _right.operator unsigned long long());
		}

#endif

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var float_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned() ^ _right.operator unsigned());
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var double_binary_xor(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long() ^ _right.operator unsigned long());
		}

		/// \brief Binary xor operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_double_binary_xor(var const& _left, var const& _right) noexcept
		{
#if (__cplusplus >= 201103L)
			return var(_left.operator unsigned long long() ^ _right.operator unsigned long long());
#else
			return var(_left.operator unsigned long() ^ _right.operator unsigned long());
#endif
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Binary xor operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string binary xor", static_cast<int>(LIBLETLIB_ENOTSUP))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

		/// \brief Binary xor operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string binary xor", static_cast<int>(LIBLETLIB_ENOTSUP))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Binary xor operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string binary xor", static_cast<int>(LIBLETLIB_ENOTSUP))
			#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
			#endif
		}
		#endif
		/// \brief Binary xor operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string binary xor", static_cast<int>(LIBLETLIB_ENOTSUP))
		#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
		#endif
		}

		/// \brief Binary xor operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_string_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string binary xor", static_cast<int>(LIBLETLIB_ENOTSUP))
		#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
		#endif
		}

	#endif
#endif

		/// \brief Binary xor operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var pointer_binary_xor(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
#ifndef LIBLETLIB_FREESTANDING
	#if (__cplusplus >= 201103L)
			if (_left.behaviour->rank == enum_void_pointer_type && _right.behaviour->rank == enum_void_pointer_type)
			{
				if (_left.value.void_pointer_type)
					return _left.message("xor")(_left, _right);
			}
			else if (_right.behaviour->rank == enum_void_pointer_type)
			{
				if (_right.value.void_pointer_type)
					return _right.message("xor")(_left, _right);
			}
			else
			{
				if (_left.value.void_pointer_type)
					return _left.message("xor")(_left, _right);
			}
	#endif
#endif
			LIBLETLIB_ERROR("Operator modulo unimplemented.", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Binary xor operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var array_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: array binary xor", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}


		/// \brief Binary xor operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var subroutine_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: subroutine binary xor", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Binary xor operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var function_binary_xor(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: function binary xor", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

#if (__cplusplus >= 201103L)
		/// \brief Binary xor operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var null_binary_xor(var const&, var const&) noexcept
		{
			return var();
		}

#endif
	}// namespace detail
}// namespace libletlib


#endif//LIBLETLIB_LIBLETLIB_BINARY_XOR_HPP
