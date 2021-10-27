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

#ifndef LIBLETLIB_LIBLETLIB_COMPLEMENT_HPP
#define LIBLETLIB_LIBLETLIB_COMPLEMENT_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var boolean_complement(var const& _value) noexcept
		{
			if (_value.value.bool_type)
			{
				return var(false);
			}
			return var(true);
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var character_complement(var const& _value) noexcept
		{
			return var(~character_as_unsigned_character(_value));
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var signed_character_complement(var const& _value) noexcept
		{
			return var(~signed_character_as_unsigned_character(_value));
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var unsigned_character_complement(var const& _value) noexcept
		{
			return var(~_value.value.unsigned_char_type);
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var wide_character_complement(var const& _value) noexcept
		{
			return var(~static_cast<std::wint_t>(_value.value.wchar_type));
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var bit8_character_complement(var const& _value) noexcept
		{
			return var(~_value.value.char8_type);
		}
		#endif
		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var bit16_character_complement(var const& _value) noexcept
		{
			return var(~_value.value.char16_type);
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var bit32_character_complement(var const& _value) noexcept
		{
			return var(~_value.value.char32_type);
		}

	#endif
#endif

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var short_complement(var const& _value) noexcept
		{
			return var(~short_as_unsigned_short(_value));
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var unsigned_short_complement(var const& _value) noexcept
		{
			return var(~_value.value.unsigned_short_type);
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var integer_complement(var const& _value) noexcept
		{
			return var(~integer_as_unsigned_integer(_value));
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var unsigned_integer_complement(var const& _value) noexcept
		{
			return var(~_value.value.unsigned_int_type);
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var long_complement(var const& _value) noexcept
		{
			return var(~long_as_unsigned_long(_value));
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var unsigned_long_complement(var const& _value) noexcept
		{
			return var(~_value.value.unsigned_long_type);
		}

#if (__cplusplus >= 201103L)

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var long_long_complement(var const& _value) noexcept
		{
			return var(~long_long_as_unsigned_long_long(_value));
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var unsigned_long_long_complement(var const& _value) noexcept
		{
			return var(~_value.value.unsigned_long_long_type);
		}

#endif

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var float_complement(var const& _value) noexcept
		{
			return var(~float_as_unsigned_integer(_value));
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var double_complement(var const& _value) noexcept
		{
			return var(~double_as_unsigned_long(_value));
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var long_double_complement(var const& _value) noexcept
		{
#if (__cplusplus >= 201103L)
			return var(~long_double_as_unsigned_long_long(_value));
#else
			return var(~long_double_as_unsigned_long(_value));
#endif
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var string_complement(var const& _value) noexcept
		{
			return var("~", _value.value.string_type, 1, string_length(_value.value.string_type));
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var wide_string_complement(var const& _value) noexcept
		{
			return var(L"~", _value.value.wide_string_type, 1, string_length(_value.value.wide_string_type));
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var bit8_string_complement(var const& _value) noexcept
		{
			return var(u8"~", _value.value.bit8_string_type, 1, string_length(_value.value.bit8_string_type));
		}

		#endif
		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var bit16_string_complement(var const& _value) noexcept
		{
			return var(u"~", _value.value.bit16_string_type, 1, string_length(_value.value.bit16_string_type));
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var bit32_string_complement(var const& _value) noexcept
		{
			return var(U"~", _value.value.bit32_string_type, 1, string_length(_value.value.bit32_string_type));
		}

	#endif
#endif

		/// \brief Complement operator.
		///
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var pointer_complement(var const& _value) LIBLETLIB_NOEXCEPT
		{
#if !defined LIBLETLIB_FREESTANDING && (__cplusplus >= 201103L)
			return _value.message("~")(_value);
#else
			LIBLETLIB_ERROR("Operator complement unimplemented.", LIBLETLIB_EDOM);
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
#endif
		}

#ifndef LIBLETLIB_FREESTANDING
		/// \brief Complement operator.
		///
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var array_complement(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: array complement", static_cast<int>(LIBLETLIB_ENOTSUP))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

		/// \brief Complement operator.
		///
		/// \return Complement value.
		LIBLETLIB_NODISCARD inline var subroutine_complement(var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: subroutine complement", static_cast<int>(LIBLETLIB_EDOM))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

		/// \brief Complement operator.
		///
		/// \param _value to complement.
		/// \return Complement value.
		LIBLETLIB_NODISCARD inline var function_complement(var const& _value) noexcept
		{
			return ~var(_value.value.function_type)();
		}

#endif
#if (__cplusplus >= 201103L)

		/// \brief Complement operator.
		///
		/// \return Complemented value.
		LIBLETLIB_NODISCARD inline var null_complement(var const&) noexcept
		{
			return var();
		}

#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_COMPLEMENT_HPP
