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

#ifndef LIBLETLIB_LIBLETLIB_SUBTRACTION_HPP
#define LIBLETLIB_LIBLETLIB_SUBTRACTION_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var boolean_subtraction(var const& _left, var const& _right) noexcept
		{
			if (_left.operator bool())
			{
				if (_right.operator bool())
				{
					return var(false);
				}
				else
				{
					return var(true);
				}
			}
			return var(false);
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var character_subtraction(var const& _left, var const& _right) noexcept
		{
			return string_subtraction(_left, _right);
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var signed_character_subtraction(var const& _left, var const& _right) noexcept
		{
			return string_subtraction(_left, _right);
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_character_subtraction(var const& _left, var const& _right) noexcept
		{
			return string_subtraction(_left, _right);
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_character_subtraction(var const& _left, var const& _right) noexcept
		{
			return wide_string_subtraction(_left, _right);
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_character_subtraction(var const& _left, var const& _right) noexcept
		{
			return bit8_string_subtraction(_left, _right);
		}
		#endif

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_character_subtraction(var const& _left, var const& _right) noexcept
		{
			return bit16_string_subtraction(_left, _right);
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_character_subtraction(var const& _left, var const& _right) noexcept
		{
			return bit32_string_subtraction(_left, _right);
		}

	#endif
#endif

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var short_subtraction(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator short() - _right.operator short());
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_short_subtraction(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned short() - _right.operator unsigned short());
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var integer_subtraction(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator int() - _right.operator int());
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_integer_subtraction(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned() - _right.operator unsigned());
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_subtraction(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator long() - _right.operator long());
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_subtraction(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long() - _right.operator unsigned long());
		}

#if (__cplusplus >= 201103L)

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_long_subtraction(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator long long() - _right.operator long long());
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_long_subtraction(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long long() - _right.operator unsigned long long());
		}

#endif

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var float_subtraction(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator float() - _right.operator float());
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var double_subtraction(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator double() - _right.operator double());
		}

		/// \brief Subtraction operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_double_subtraction(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator long double() - _right.operator long double());
		}

#ifndef LIBLETLIB_FREESTANDING
		/// \brief Subtraction operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var string_subtraction(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			char* left = _left.behaviour->as_string(_left);
			char* right;

			if (_right.behaviour->rank != enum_string_type)
				right = _right.behaviour->as_string(_right);
			else
				right = _right.value.string_type;

			char *pointer0, *pointer1, *pointer2;
			if ((pointer1 = pointer2 = substring_search(left, right)) != nothing)
			{
				while ((pointer2 = substring_search(pointer0 = pointer2 + string_length(right), right)) != nothing)
					while (pointer0 < pointer2)
						*pointer1++ = *pointer0++;
				while ((*pointer1++ = *pointer0++) != '\0')
					continue;
			}

			var result = left;
			if (_right.behaviour->rank != enum_string_type)
			{
				deallocate(right);
			}
			deallocate(left);

			return result;
		}

		/// \brief Subtraction operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_string_subtraction(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			wchar_t* left = _left.behaviour->as_wide_string(_left);
			wchar_t* right;

			if (_right.behaviour->rank != enum_wide_string_type)
				right = _right.behaviour->as_wide_string(_right);
			else
				right = _right.value.wide_string_type;

			wchar_t *pointer0, *pointer1, *pointer2;
			if ((pointer1 = pointer2 = substring_search(left, right)) != nothing)
			{
				while ((pointer2 = substring_search(pointer0 = pointer2 + string_length(right), right)) != nothing)
					while (pointer0 < pointer2)
						*pointer1++ = *pointer0++;
				while ((*pointer1++ = *pointer0++) != '\0')
					continue;
			}

			var result = left;
			if (_right.behaviour->rank != enum_wide_string_type)
			{
				deallocate(right);
			}
			deallocate(left);

			return result;
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Subtraction operator.
		///
		/// \param _left argument.
		/// \param _right argument.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_string_subtraction(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			char8_t* left = _left.behaviour->as_bit8_string(_left);
			char8_t* right;

			if (_right.behaviour->rank != enum_bit8_string_type)
				right = _right.behaviour->as_bit8_string(_right);
			else
				right = _right.value.bit8_string_type;

			char8_t *pointer0, *pointer1, *pointer2;
			if ((pointer1 = pointer2 = substring_search(left, right)) != nothing)
			{
				std::size_t length = string_length(right);
				while ((pointer2 = substring_search(pointer0 = pointer2 + length, right)) != nothing)
					while (pointer0 < pointer2)
						*pointer1++ = *pointer0++;
				while ((*pointer1++ = *pointer0++) != '\0')
					continue;
			}

			var result = left;
			if (_right.behaviour->rank != enum_bit8_string_type)
			{
				deallocate(right);
			}
			deallocate(left);

			return result;
		}
		#endif

		/// \brief Subtraction operator.
		///
		/// \param _right argument.
		/// \param _left argument.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_string_subtraction(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			char16_t* left = _left.behaviour->as_bit16_string(_left);
			char16_t* right;

			if (_right.behaviour->rank != enum_bit16_string_type)
				right = _right.behaviour->as_bit16_string(_right);
			else
				right = _right.value.bit16_string_type;

			char16_t *pointer0, *pointer1, *pointer2;
			if ((pointer1 = pointer2 = substring_search(left, right)) != nothing)
			{
				std::size_t length = string_length(right);
				while ((pointer2 = substring_search(pointer0 = pointer2 + length, right)) != nothing)
					while (pointer0 < pointer2)
						*pointer1++ = *pointer0++;
				while ((*pointer1++ = *pointer0++) != '\0')
					continue;
			}

			var result = left;
			if (_right.behaviour->rank != enum_bit16_string_type)
			{
				deallocate(right);
			}
			deallocate(left);

			return result;
		}

		/// \brief Subtraction operator.
		///
		/// \param _left argument.
		/// \param _right argument.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_string_subtraction(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			char32_t* left = _left.behaviour->as_bit32_string(_left);
			char32_t* right;

			if (_right.behaviour->rank != enum_bit32_string_type)
				right = _right.behaviour->as_bit32_string(_right);
			else
				right = _right.value.bit32_string_type;

			char32_t *pointer0, *pointer1, *pointer2;
			if ((pointer1 = pointer2 = substring_search(left, right)) != nothing)
			{
				std::size_t length = string_length(right);
				while ((pointer2 = substring_search(pointer0 = pointer2 + length, right)) != nothing)
					while (pointer0 < pointer2)
						*pointer1++ = *pointer0++;
				while ((*pointer1++ = *pointer0++) != '\0')
					continue;
			}

			var result = left;
			if (_right.behaviour->rank != enum_bit32_string_type)
			{
				deallocate(right);
			}
			deallocate(left);

			return result;
		}

	#endif
#endif

		/// \brief Subtraction operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var pointer_subtraction(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
#ifndef LIBLETLIB_FREESTANDING
	#if (__cplusplus >= 201103L)
			if (_left.behaviour->rank == enum_void_pointer_type && _right.behaviour->rank == enum_void_pointer_type)
			{
				if (_left.value.void_pointer_type)
					return _left.message("-")(_left, _right);
			}
			else if (_right.behaviour->rank == enum_void_pointer_type)
			{
				if (_right.value.void_pointer_type)
					return _right.message("-")(_left, _right);
			}
			else
			{
				if (_left.value.void_pointer_type)
					return _left.message("-")(_left, _right);
			}
	#endif
#endif
			LIBLETLIB_ERROR("Operator subtraction unimplemented.", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Subtraction operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var array_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: array subtraction", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Subtraction operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var subroutine_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: subroutine subtraction", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Subtraction operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var function_subtraction(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: function subtraction", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

#if (__cplusplus >= 201103L)

		/// \brief Subtraction operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var null_subtraction(var const&, var const&) noexcept
		{
			return var();
		}

#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_SUBTRACTION_HPP
