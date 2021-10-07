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

#ifndef LIBLETLIB_LIBLETLIB_INDEX_HPP
#define LIBLETLIB_LIBLETLIB_INDEX_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var boolean_index(var const& _value, var const&) noexcept
		{
			return var(_value.value.bool_type);
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var character_index(var const& _value, var const&) noexcept
		{
			return var(_value.value.char_type);
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var signed_character_index(var const& _value, var const&) noexcept
		{
			return var(_value.value.signed_char_type);
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var unsigned_character_index(var const& _value, var const&) noexcept
		{
			return var(_value.value.unsigned_char_type);
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var wide_character_index(var const& _value, var const& _index) noexcept
		{
			char buffer[sizeof(wchar_t) + 1] = {0};
			std::wctomb(buffer, _value.value.wchar_type);
			std::size_t const absolute_index = static_cast<std::size_t>(std::labs(_index));
			std::size_t const buffer_length  = string_length(buffer);
			if (absolute_index > buffer_length)
			{
				return var(buffer[buffer_length - 1]);
			}
			if (_index < 0l && absolute_index < buffer_length)
			{
				return var(buffer[buffer_length - absolute_index]);
			}
			return var(buffer[0]);
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Index-of operator.
		///
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var bit8_character_index(var const&, var const& _index) noexcept
		{
			char buffer[sizeof(char8_t) * 2 + 1] = {0};
			mbstate_t state;
			std::memset(&state, 0, sizeof(state));
			//static_cast<void>(std::c8rtomb(buffer, _value.value.char8_type, &state)); std::c8rtomb Not supported by any of the "Big Three".
			std::size_t const absolute_index = static_cast<std::size_t>(std::labs(_index));
			std::size_t const buffer_length  = string_length(buffer);
			if (absolute_index > buffer_length)
			{
				return var(buffer[buffer_length - 1]);
			}
			if (_index < 0l && absolute_index < buffer_length)
			{
				return var(buffer[buffer_length - absolute_index]);
			}
			return var(buffer[0]);
		}
		#endif

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var bit16_character_index(var const& _value, var const& _index) noexcept
		{
			char buffer[sizeof(char16_t) * 2 + 1] = {0};
			mbstate_t state;
			std::memset(&state, 0, sizeof(state));
			static_cast<void>(std::c16rtomb(buffer, _value.value.char16_type, &state));
			std::size_t const absolute_index = static_cast<std::size_t>(std::labs(_index));
			std::size_t const buffer_length  = string_length(buffer);
			if (absolute_index > buffer_length)
			{
				return var(buffer[buffer_length - 1]);
			}
			if (_index < 0l && absolute_index < buffer_length)
			{
				return var(buffer[buffer_length - absolute_index]);
			}
			return var(buffer[0]);
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var bit32_character_index(var const& _value, var const& _index) noexcept
		{
			char buffer[sizeof(char32_t) * 2 + 1] = {0};
			mbstate_t state;
			std::memset(&state, 0, sizeof(state));
			static_cast<void>(std::c32rtomb(buffer, _value.value.char32_type, &state));
			std::size_t const absolute_index = static_cast<std::size_t>(std::labs(_index));
			std::size_t const buffer_length  = string_length(buffer);
			if (absolute_index > buffer_length)
			{
				return var(buffer[buffer_length - 1]);
			}
			if (_index < 0l && absolute_index < buffer_length)
			{
				return var(buffer[buffer_length - absolute_index]);
			}
			return var(buffer[0]);
		}

	#endif

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var short_index(var const& _value, var const& _index) noexcept
		{
			return var(index_of_number(_value.value.short_type, _index));
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var unsigned_short_index(var const& _value, var const& _index) noexcept
		{
			return var(index_of_number(_value.value.unsigned_short_type, _index));
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var integer_index(var const& _value, var const& _index) noexcept
		{
			return var(index_of_number(_value.value.int_type, _index));
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var unsigned_integer_index(var const& _value, var const& _index) noexcept
		{
			return var(index_of_number(_value.value.unsigned_int_type, _index));
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var long_index(var const& _value, var const& _index) noexcept
		{
			return var(index_of_number(_value.value.long_type, _index));
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var unsigned_long_index(var const& _value, var const& _index) noexcept
		{
			return var(index_of_number(_value.value.unsigned_long_type, _index));
		}

	#if (__cplusplus >= 201103L)

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var long_long_index(var const& _value, var const& _index) noexcept
		{
			return var(index_of_number(_value.value.long_long_type, _index));
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var unsigned_long_long_index(var const& _value, var const& _index) noexcept
		{
			return var(index_of_number(_value.value.unsigned_long_long_type, _index));
		}

	#endif

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var float_index(var const& _value, var const& _index) noexcept
		{
			return var(index_of_number(static_cast<double>(_value.value.float_type), _index));
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var double_index(var const& _value, var const& _index) noexcept
		{
			return var(index_of_number(_value.value.double_type, _index));
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var long_double_index(var const& _value, var const& _index) noexcept
		{
			return var(index_of_number(_value.value.long_double_type, _index));
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var string_index(var const& _value, var const& _index) noexcept
		{
			long const length = static_cast<long>(string_length(_value.value.string_type));
			if (_index >= 0l && _index < length)
			{
				return _value.value.string_type[_index];
			}
			if (_index >= length)
			{
				return _value.value.string_type[length - 1];
			}
			long const absolute_index = std::labs(_index);
			return _value.value.string_type[length - absolute_index];
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var wide_string_index(var const& _value, var const& _index) noexcept
		{
			long const length = static_cast<long>(string_length(_value.value.wide_string_type));
			if (_index >= 0l && _index < length)
			{
				return _value.value.wide_string_type[_index];
			}
			if (_index >= length)
			{
				return _value.value.wide_string_type[length - 1];
			}
			long const absolute_index = std::labs(_index);
			return _value.value.wide_string_type[length - absolute_index];
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var bit8_string_index(var const& _value, var const& _index) noexcept
		{
			long const length = static_cast<long>(string_length(_value.value.bit8_string_type));
			if (_index >= 0l && _index < length)
			{
				return _value.value.bit8_string_type[_index];
			}
			if (_index >= length)
			{
				return _value.value.bit8_string_type[length - 1];
			}
			long const absolute_index = std::labs(_index);
			return _value.value.bit8_string_type[length - absolute_index];
		}
		#endif

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var bit16_string_index(var const& _value, var const& _index) noexcept
		{
			long const length = static_cast<long>(string_length(_value.value.bit16_string_type));
			if (_index >= 0l && _index < length)
			{
				return _value.value.bit16_string_type[_index];
			}
			if (_index >= length)
			{
				return _value.value.bit16_string_type[length - 1];
			}
			long const absolute_index = std::labs(_index);
			return _value.value.bit16_string_type[length - absolute_index];
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var bit32_string_index(var const& _value, var const& _index) noexcept
		{
			long const length = static_cast<long>(string_length(_value.value.bit32_string_type));
			if (_index >= 0l && _index <= length)
			{
				return _value.value.bit32_string_type[_index];
			}
			if (_index > length)
			{
				return _value.value.bit32_string_type[length - 1];
			}
			long const absolute_index = std::labs(_index);
			return _value.value.bit32_string_type[length - absolute_index];
		}

	#endif

#endif

		/// \brief Index-of operator.
		///
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var pointer_index(var const& _value, var const& _index) LIBLETLIB_NOEXCEPT
		{
#if (__cplusplus >= 201103L)
	#ifndef LIBLETLIB_FREESTANDING
			if (_value.behaviour->rank == enum_void_pointer_type)
			{
				var& overload = _value.objectify()->message("[]");
				if (overload != EMPTY_VALUE)
				{
					return overload(_value, _index);
				}
				if (_index.behaviour->rank == enum_string_type)
				{
					for (std::size_t index = 0; index < _value.objectify()->inner.size.in_use; ++index)
					{
						if (_value.objectify()->inner[index][0] == _index)
						{
							return _value.objectify()->inner[index][1];
						}
					}
				}
				return _value.objectify()->inner[_index.behaviour->as_unsigned_long(_index)];
			}
	#endif
#endif
			return nothing;
		}

#ifndef LIBLETLIB_FREESTANDING
		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var array_index(var const& _value, var const& _index) noexcept
		{
			long const length = static_cast<long>(backing::length(_value));
			if (_index >= 0l && _index < length)
			{
				return _value.value.array_type[_index];
			}
			if (_index >= length)
			{
				return _value.value.array_type[length - 1];
			}
			long const absolute_index = std::labs(_index);
			return _value.value.array_type[length - absolute_index];
		}

		/// \brief Index-of operator.
		///
		/// \return Var at index.
		LIBLETLIB_NODISCARD inline var subroutine_index(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: accessing subroutine by index", static_cast<int>(LIBLETLIB_EDOM))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

		/// \brief Index-of operator.
		///
		/// \param _value to property index of.
		/// \param _index to retrieve.
		/// \return Var at index.
		LIBLETLIB_NODISCARD inline var function_index(var const& _value, var const& _index) noexcept
		{
			return var(_value.value.function_type)()[_index];
		}

#endif
#if (__cplusplus >= 201103L)

		/// \brief Index-of operator.
		///
		/// \return value at index.
		LIBLETLIB_NODISCARD inline var null_index(var const&, var const&) noexcept
		{
			return var();
		}

#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_INDEX_HPP
