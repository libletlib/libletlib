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

#ifndef LIBLETLIB_LIBLETLIB_SUM_HPP
#define LIBLETLIB_LIBLETLIB_SUM_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var boolean_sum(var const& _left, var const& _right) noexcept
		{
			if (_left.operator bool() || _right.operator bool())
			{
				return var(true);
			}
			return var(false);
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var character_sum(var const& _left, var const& _right) noexcept
		{
			return string_sum(_left, _right);
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var signed_character_sum(var const& _left, var const& _right) noexcept
		{
			return string_sum(_left, _right);
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_character_sum(var const& _left, var const& _right) noexcept
		{
			return string_sum(_left, _right);
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_character_sum(var const& _left, var const& _right) noexcept
		{
			return wide_string_sum(_left, _right);
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_character_sum(var const& _left, var const& _right) noexcept
		{
			return bit8_string_sum(_left, _right);
		}
		#endif

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_character_sum(var const& _left, var const& _right) noexcept
		{
			return bit16_string_sum(_left, _right);
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_character_sum(var const& _left, var const& _right) noexcept
		{
			return bit32_string_sum(_left, _right);
		}

	#endif
#endif

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var short_sum(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator short() + _right.operator short());
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_short_sum(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned short() + _right.operator unsigned short());
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var integer_sum(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator int() + _right.operator int());
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_integer_sum(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned() + _right.operator unsigned());
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_sum(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator long() + _right.operator long());
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_sum(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long() + _right.operator unsigned long());
		}

#if (__cplusplus >= 201103L)

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_long_sum(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator long long() + _right.operator long long());
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_long_sum(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long long() + _right.operator unsigned long long());
		}

#endif

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var float_sum(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator float() + _right.operator float());
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var double_sum(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator double() + _right.operator double());
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_double_sum(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator long double() + _right.operator long double());
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var string_sum(var const& _left, var const& _right) noexcept
		{
			char *l, *r;
			if (_left.behaviour->rank == enum_string_type)
			{
				l = _left.value.string_type;
				if (_right.behaviour->rank == enum_string_type)
				{
					r = _right.value.string_type;
					return var(l, r, string_length(l), string_length(r));
				}
				r             = _right.behaviour->as_string(_right);
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(r);
				return temporary;
			}
			else if (_right.behaviour->rank == enum_string_type)
			{
				l             = _left.behaviour->as_string(_left);
				r             = _right.value.string_type;
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(l);
				return temporary;
			}
			else
			{
				l             = _left.behaviour->as_string(_left);
				r             = _right.behaviour->as_string(_right);
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(r);
				deallocate(l);
				return temporary;
			}
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_string_sum(var const& _left, var const& _right) noexcept
		{
			wchar_t *l, *r;
			if (_left.behaviour->rank == enum_wide_string_type)
			{
				l = _left.value.wide_string_type;
				if (_right.behaviour->rank == enum_wide_string_type)
				{
					r = _right.value.wide_string_type;
					return var(l, r, string_length(l), string_length(r));
				}
				r             = _right.behaviour->as_wide_string(_right);
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(r);
				return temporary;
			}
			else if (_right.behaviour->rank == enum_wide_string_type)
			{
				l             = _left.behaviour->as_wide_string(_left);
				r             = _right.value.wide_string_type;
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(l);
				return temporary;
			}
			else
			{
				l             = _left.behaviour->as_wide_string(_left);
				r             = _right.behaviour->as_wide_string(_right);
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(r);
				deallocate(l);
				return temporary;
			}
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_string_sum(var const& _left, var const& _right) noexcept
		{
			char8_t *l, *r;
			if (_left.behaviour->rank == enum_bit8_string_type)
			{
				l = _left.value.bit8_string_type;
				if (_right.behaviour->rank == enum_bit8_string_type)
				{
					r = _right.value.bit8_string_type;
					return var(l, r, string_length(l), string_length(r));
				}
				r             = _right.behaviour->as_bit8_string(_right);
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(r);
				return temporary;
			}
			else if (_right.behaviour->rank == enum_bit8_string_type)
			{
				l             = _left.behaviour->as_bit8_string(_left);
				r             = _right.value.bit8_string_type;
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(l);
				return temporary;
			}
			else
			{
				l             = _left.behaviour->as_bit8_string(_left);
				r             = _right.behaviour->as_bit8_string(_right);
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(r);
				deallocate(l);
				return temporary;
			}
		}
		#endif

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_string_sum(var const& _left, var const& _right) noexcept
		{
			char16_t *l, *r;
			if (_left.behaviour->rank == enum_bit16_string_type)
			{
				l = _left.value.bit16_string_type;
				if (_right.behaviour->rank == enum_bit16_string_type)
				{
					r = _right.value.bit16_string_type;
					return var(l, r, string_length(l), string_length(r));
				}
				r             = _right.behaviour->as_bit16_string(_right);
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(r);
				return temporary;
			}
			else if (_right.behaviour->rank == enum_bit16_string_type)
			{
				l             = _left.behaviour->as_bit16_string(_left);
				r             = _right.value.bit16_string_type;
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(l);
				return temporary;
			}
			else
			{
				l             = _left.behaviour->as_bit16_string(_left);
				r             = _right.behaviour->as_bit16_string(_right);
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(r);
				deallocate(l);
				return temporary;
			}
		}

		/// \brief Sum operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_string_sum(var const& _left, var const& _right) noexcept
		{
			char32_t* l;
			char32_t* r;
			if (_left.behaviour->rank == enum_bit32_string_type)
			{
				l = _left.value.bit32_string_type;
				if (_right.behaviour->rank == enum_bit32_string_type)
				{
					r = _right.value.bit32_string_type;
					return var(l, r, string_length(l), string_length(r));
				}
				r             = _right.behaviour->as_bit32_string(_right);
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(r);
				return temporary;
			}
			else if (_right.behaviour->rank == enum_bit32_string_type)
			{
				l             = _left.behaviour->as_bit32_string(_left);
				r             = _right.value.bit32_string_type;
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(l);
				return temporary;
			}
			else
			{
				l             = _left.behaviour->as_bit32_string(_left);
				r             = _right.behaviour->as_bit32_string(_right);
				var temporary = var(l, r, string_length(l), string_length(r));
				deallocate(r);
				deallocate(l);
				return temporary;
			}
		}

	#endif
#endif

		/// \brief Sum operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var pointer_sum(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
#ifndef LIBLETLIB_FREESTANDING
	#if (__cplusplus >= 201103L)
			if (_left.behaviour->rank == enum_void_pointer_type && _right.behaviour->rank == enum_void_pointer_type)
			{
				if (_left.value.void_pointer_type)
					return _left.message("+")(_left, _right);
			}
			else if (_right.behaviour->rank == enum_void_pointer_type)
			{
				if (_right.value.void_pointer_type)
					return _left.message("+")(_left, _right);
			}
			else
			{
				if (_left.value.void_pointer_type)
					return _left.message("+")(_left, _right);
			}
	#endif
#endif
			LIBLETLIB_ERROR("Operator sum unimplemented.", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

#ifndef LIBLETLIB_FREESTANDING
		/// \brief Sum operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var array_sum(var const& _left, var const& _right) noexcept
		{
			if (_left.behaviour->rank == enum_array_type)
			{
				size_struct size  = size_struct(1ul + _left.size.in_use);
				var* pointer      = allocate<var>(size.allocated);
				std::size_t index = 0;
				for (; index < _left.size.in_use; ++index)
				{
					pointer[index] = _left.value.array_type[index];
				}
				pointer[index] = _right;
				return var(pointer, size);
			}
			else
			{
				size_struct size = size_struct(1ul + _right.size.in_use);
				var* pointer     = allocate<var>(size.allocated);
				pointer[0]       = _left;
				for (std::size_t index = 0; index < _right.size.in_use; ++index)
				{
					pointer[index + 1] = _right.value.array_type[index];
				}
				return var(pointer, size);
			}
		}

		/// \brief Sum operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var subroutine_sum(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: subroutine sum", static_cast<int>(LIBLETLIB_EDOM))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

		/// \brief Sum operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var function_sum(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: function subtraction", static_cast<int>(LIBLETLIB_ENOTSUP))
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
		}

#endif
#if (__cplusplus >= 201103L)

		/// \brief Sum operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var null_sum(var const&, var const&) noexcept
		{
			return var();
		}

#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_SUM_HPP
