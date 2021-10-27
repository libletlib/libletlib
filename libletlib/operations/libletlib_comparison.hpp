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

#ifndef LIBLETLIB_LIBLETLIB_COMPARISON_HPP
#define LIBLETLIB_LIBLETLIB_COMPARISON_HPP

#include "../core/libletlib_var.hpp"

namespace libletlib
{
	namespace detail
	{
		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int boolean_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator int(), _right.operator int());
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int character_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator char(), _right.operator char());
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int signed_character_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator signed char(), _right.operator signed char());
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int unsigned_character_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator unsigned char(), _right.operator unsigned char());
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int wide_character_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator wchar_t(), _right.operator wchar_t());
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int bit8_character_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator char8_t(), _right.operator char8_t());
		}
		#endif
		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int bit16_character_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator char16_t(), _right.operator char16_t());
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int bit32_character_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator char32_t(), _right.operator char32_t());
		}

	#endif
#endif

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int short_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator signed short(), _right.operator signed short());
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int unsigned_short_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator unsigned short(), _right.operator unsigned short());
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int integer_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator int(), _right.operator int());
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int unsigned_integer_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator unsigned(), _right.operator unsigned());
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int long_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator signed long(), _right.operator signed long());
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int unsigned_long_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator unsigned long(), _right.operator unsigned long());
		}

#if (__cplusplus >= 201103L)

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int long_long_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator long long(), _right.operator long long());
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int unsigned_long_long_comparison(var const& _left, var const& _right) noexcept
		{
			return number_compare(_left.operator unsigned long long(), _right.operator unsigned long long());
		}

#endif

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int float_comparison(var const& _left, var const& _right) noexcept
		{
			if (float_equals(_left.operator float(), _right.operator float()))
				return 0;
			if (_left.operator float() > _right.operator float())
				return 1;
			return -1;
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int double_comparison(var const& _left, var const& _right) noexcept
		{
			if (float_equals(_left.operator double(), _right.operator double()))
				return 0;
			if (_left.operator double() > _right.operator double())
				return 1;
			return -1;
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int long_double_comparison(var const& _left, var const& _right) noexcept
		{
			if (float_equals(_left.operator long double(), _right.operator long double()))
				return 0;
			if (_left.operator long double() > _right.operator long double())
				return 1;
			return -1;
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int string_comparison(var const& _left, var const& _right) noexcept
		{
			char *l, *r;
			if (_left.behaviour->rank == enum_string_type)
			{
				l = _left.value.string_type;
				if (_right.behaviour->rank == enum_string_type)
				{
					r = _right.value.string_type;
					return string_compare(l, r);
				}
				r                = _right.behaviour->as_string(_right);
				int const result = string_compare(l, r);
				deallocate(r);
				return result;
			}
			else if (_right.behaviour->rank == enum_string_type)
			{
				l                = _left.behaviour->as_string(_left);
				r                = _right.value.string_type;
				int const result = string_compare(l, r);
				deallocate(l);
				return result;
			}
			else
			{
				l                = _left.behaviour->as_string(_left);
				r                = _right.behaviour->as_string(_right);
				int const result = string_compare(l, r);
				deallocate(l);
				deallocate(r);
				return result;
			}
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int wide_string_comparison(var const& _left, var const& _right) noexcept
		{
			wchar_t *l, *r;
			if (_left.behaviour->rank == enum_wide_string_type)
			{
				l = _left.value.wide_string_type;
				if (_right.behaviour->rank == enum_wide_string_type)
				{
					r = _right.value.wide_string_type;
					return string_compare(l, r);
				}
				r                = _right.behaviour->as_wide_string(_right);
				int const result = string_compare(l, r);
				deallocate(r);
				return result;
			}
			else if (_right.behaviour->rank == enum_wide_string_type)
			{
				l                = _left.behaviour->as_wide_string(_left);
				r                = _right.value.wide_string_type;
				int const result = string_compare(l, r);
				deallocate(l);
				return result;
			}
			else
			{
				l                = _left.behaviour->as_wide_string(_left);
				r                = _right.behaviour->as_wide_string(_right);
				int const result = string_compare(l, r);
				deallocate(l);
				deallocate(r);
				return result;
			}
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int bit8_string_comparison(var const& _left, var const& _right) noexcept
		{
			char8_t *left, *right;
			if (_left.behaviour->rank == enum_bit8_string_type)
			{
				left = _left.value.bit8_string_type;
				if (_right.behaviour->rank == enum_bit8_string_type)
				{
					right = _right.value.bit8_string_type;
					return string_compare(left, right);
				}
				right            = _right.behaviour->as_bit8_string(_right);
				int const result = string_compare(left, right);
				deallocate(right);
				return result;
			}
			else if (_right.behaviour->rank == enum_bit16_string_type)
			{
				left             = _left.behaviour->as_bit8_string(_left);
				right            = _right.value.bit8_string_type;
				int const result = string_compare(left, right);
				deallocate(left);
				return result;
			}
			else
			{
				left             = _left.behaviour->as_bit8_string(_left);
				right            = _right.behaviour->as_bit8_string(_right);
				int const result = string_compare(left, right);
				deallocate(left);
				deallocate(right);
				return result;
			}
		}
		#endif
		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int bit16_string_comparison(var const& _left, var const& _right) noexcept
		{
			char16_t *left, *right;
			if (_left.behaviour->rank == enum_bit16_string_type)
			{
				left = _left.value.bit16_string_type;
				if (_right.behaviour->rank == enum_bit16_string_type)
				{
					right = _right.value.bit16_string_type;
					return string_compare(left, right);
				}
				right            = _right.behaviour->as_bit16_string(_right);
				int const result = string_compare(left, right);
				deallocate(right);
				return result;
			}
			else if (_right.behaviour->rank == enum_bit16_string_type)
			{
				left             = _left.behaviour->as_bit16_string(_left);
				right            = _right.value.bit16_string_type;
				int const result = string_compare(left, right);
				deallocate(left);
				return result;
			}
			else
			{
				left             = _left.behaviour->as_bit16_string(_left);
				right            = _right.behaviour->as_bit16_string(_right);
				int const result = string_compare(left, right);
				deallocate(left);
				deallocate(right);
				return result;
			}
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int bit32_string_comparison(var const& _left, var const& _right) noexcept
		{
			char32_t *l, *r;
			if (_left.behaviour->rank == enum_bit32_string_type)
			{
				l = _left.value.bit32_string_type;
				if (_right.behaviour->rank == enum_bit32_string_type)
				{
					r = _right.value.bit32_string_type;
					return string_compare(l, r);
				}
				r                = _right.behaviour->as_bit32_string(_right);
				int const result = string_compare(l, r);
				deallocate(r);
				return result;
			}
			else if (_right.behaviour->rank == enum_bit32_string_type)
			{
				l                = _left.behaviour->as_bit32_string(_left);
				r                = _right.value.bit32_string_type;
				int const result = string_compare(l, r);
				deallocate(l);
				return result;
			}
			else
			{
				l                = _left.behaviour->as_bit32_string(_left);
				r                = _right.behaviour->as_bit32_string(_right);
				int const result = string_compare(l, r);
				deallocate(l);
				deallocate(r);
				return result;
			}
		}

	#endif
#endif

		/// \brief Comparison operator.
		///
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int pointer_comparison(var const& _left, var const& _right) noexcept
		{
#ifndef LIBLETLIB_FREESTANDING
	#if (__cplusplus >= 201103L)
			if (_left.behaviour->rank == enum_void_pointer_type && _right.behaviour->rank == enum_void_pointer_type)
			{
				if (_left.value.void_pointer_type)
					return _left.message("<=>")(_left, _right);
			}
			else if (_right.behaviour->rank == enum_void_pointer_type)
			{
				if (_right.value.void_pointer_type)
					return _right.message("<=>")(_left, _right);
			}
			else
			{
				if (_left.value.void_pointer_type)
					return _left.message("<=>")(_left, _right);
			}
	#endif
			if (_left.behaviour->rank == enum_void_pointer_type && _right.behaviour->rank == enum_void_pointer_type)
			{
				return 0;
			}
			else if (_left.behaviour->rank == enum_void_pointer_type)
			{
				return 1;
			}
			return -1;
#else
			if (_left.value.void_pointer_type == _right.value.void_pointer_type)
				return 0;
			if (_left.value.void_pointer_type > _right.value.void_pointer_type)
				return 1;
			return 0;
	#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
	#endif
#endif
		}

#ifndef LIBLETLIB_FREESTANDING
		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int array_comparison(var const& _left, var const& _right) noexcept
		{
			if (_left.behaviour->rank < enum_array_type)
			{
				return -1;
			}
			if (_right.behaviour->rank < enum_array_type)
			{
				return 1;
			}

			if (_left.size.in_use > _right.size.in_use)
			{
				return 1;
			}
			else if (_right.size.in_use > _left.size.in_use)
			{
				return -1;
			}

			for (std::size_t index = 0; index < _left.size.in_use; ++index)
			{
				if (_left.value.array_type[index] != _right.value.array_type[index])
				{
					if (_left.value.array_type[index] > _right.value.array_type[index])
					{
						return 1;
					}
					else
					{
						return -1;
					}
				}
				else
				{
					continue;
				}
			}

			return 0;
		}

		/// \brief Comparison operator.
		///
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int subroutine_comparison(var const& _left, var const& _right) noexcept
		{
			if (_left.behaviour->rank > _right.behaviour->rank)
			{
				return 1;
			}
			else if (_right.behaviour->rank > _left.behaviour->rank)
			{
				return -1;
			}
			return 0;
		}

		/// \brief Comparison operator.
		///
		/// \param _left hand side of the comparison.
		/// \param _right hand side of the comparison.
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int function_comparison(var const& _left, var const& _right) noexcept
		{
			if (_left.behaviour->rank > _right.behaviour->rank)
			{
				return 1;
			}
			else if (_right.behaviour->rank > _left.behaviour->rank)
			{
				return -1;
			}
			return _left() == _right();
		}
#endif

#if (__cplusplus >= 201103L)
		/// \brief Comparison operator.
		///
		/// \return 1 if _left greater, 0 if equal, -1 if _right greater.
		LIBLETLIB_NODISCARD inline int null_comparison(var const& _left, var const& _right) noexcept
		{
			if (_left.behaviour->rank != enum_nullptr_type)
			{
				return -1;
			}
			else if (_right.behaviour->rank != enum_nullptr_type)
			{
				return 1;
			}
			return 0;
		}
#endif
	}// namespace detail
}// namespace libletlib


#endif//LIBLETLIB_LIBLETLIB_COMPARISON_HPP
