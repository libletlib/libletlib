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

#ifndef LIBLETLIB_LIBLETLIB_DECREMENT_HPP
#define LIBLETLIB_LIBLETLIB_DECREMENT_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Decrement operator.
		///
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var boolean_decrement(var const&) noexcept
		{
			return var(false);
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var character_decrement(var const& _value) noexcept
		{
			return var(_value.value.char_type - 1);
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var signed_character_decrement(var const& _value) noexcept
		{
			return var(_value.value.signed_char_type - 1);
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var unsigned_character_decrement(var const& _value) noexcept
		{
			return var(_value.value.unsigned_char_type - 1u);
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var wide_character_decrement(var const& _value) noexcept
		{
			return var(_value.value.wchar_type - 1);
		}

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var bit8_character_decrement(var const& _value) noexcept
		{
			return var(_value.value.char8_type - 1u);
		}
	#endif
		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var bit16_character_decrement(var const& _value) noexcept
		{
			return var(_value.value.char16_type - 1u);
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var bit32_character_decrement(var const& _value) noexcept
		{
			return var(_value.value.char32_type - 1u);
		}

#endif

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var short_decrement(var const& _value) noexcept
		{
			return var(static_cast<short>(_value.value.short_type - 1));
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var unsigned_short_decrement(var const& _value) noexcept
		{
			return var(static_cast<unsigned short>(_value.value.unsigned_short_type - 1));
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var integer_decrement(var const& _value) noexcept
		{
			return var(_value.value.int_type - 1);
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var unsigned_integer_decrement(var const& _value) noexcept
		{
			return var(_value.value.unsigned_int_type - 1u);
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var long_decrement(var const& _value) noexcept
		{
			return var(_value.value.long_type - 1l);
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var unsigned_long_decrement(var const& _value) noexcept
		{
			return var(_value.value.unsigned_long_type - 1ul);
		}

#if (__cplusplus >= 201103L)

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var long_long_decrement(var const& _value) noexcept
		{
			return var(_value.value.long_long_type - 1ll);
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var unsigned_long_long_decrement(var const& _value) noexcept
		{
			return var(_value.value.unsigned_long_long_type - 1ull);
		}

#endif

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var float_decrement(var const& _value) noexcept
		{
			return var(_value.value.float_type - 1.0f);
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var double_decrement(var const& _value) noexcept
		{
			return var(_value.value.double_type - 1.0);
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var long_double_decrement(var const& _value) noexcept
		{
			return var(_value.value.long_double_type - 1.0l);
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var string_decrement(var const& _value) noexcept
		{
			return var("--", _value.value.string_type, 2, string_length(_value.value.string_type));
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var wide_string_decrement(var const& _value) noexcept
		{
			return var(L"--", _value.value.wide_string_type, 2, string_length(_value.value.wide_string_type));
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var bit8_string_decrement(var const& _value) noexcept
		{
			return var(u8"--", _value.value.bit8_string_type, 2, string_length(_value.value.bit8_string_type));
		}
		#endif
		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var bit16_string_decrement(var const& _value) noexcept
		{
			return var(u"--", _value.value.bit16_string_type, 2, string_length(_value.value.bit16_string_type));
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var bit32_string_decrement(var const& _value) noexcept
		{
			return var(U"--", _value.value.bit32_string_type, 2, string_length(_value.value.bit32_string_type));
		}

	#endif
#endif

		/// \brief Decrement operator.
		///
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var pointer_decrement(var const& _value) LIBLETLIB_NOEXCEPT
		{
#if !defined LIBLETLIB_FREESTANDING && (__cplusplus >= 201103L)
			return _value.message("--")(_value);
#else
			LIBLETLIB_ERROR("Operator complement unimplemented.", LIBLETLIB_EDOM);
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
#endif
		}

#ifndef LIBLETLIB_FREESTANDING
		/// \brief Decrement operator.
		///
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var array_decrement(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: array increment", static_cast<int>(LIBLETLIB_ENOTSUP))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

		/// \brief Decrement operator.
		///
		/// \return Decremented value.
		LIBLETLIB_NODISCARD inline var subroutine_decrement(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: subroutine increment", static_cast<int>(LIBLETLIB_EDOM))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

		/// \brief Decrement operator.
		///
		/// \param _value to decrement.
		/// \return Decremented value.
		LIBLETLIB_NODISCARD inline var function_decrement(var const& _value) noexcept
		{
			return --var(_value.value.function_type)();
		}

#endif
#if (__cplusplus >= 201103L)

		/// \brief Decrement operator.
		///
		/// \return decremented value.
		LIBLETLIB_NODISCARD inline var null_decrement(var const&) noexcept
		{
			return var();
		}

#endif
	}// namespace detail
}// namespace libletlib


#endif//LIBLETLIB_LIBLETLIB_DECREMENT_HPP
