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

#ifndef LIBLETLIB_LIBLETLIB_BINARY_AND_HPP
#define LIBLETLIB_LIBLETLIB_BINARY_AND_HPP

namespace libletlib
{
	namespace detail
	{
		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var boolean_binary_and(var const& _left, var const& _right) noexcept
		{
			if (_left && _right)
				return true;
			return false;
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var character_binary_and(var const& _left, var const& _right) noexcept
		{
			if (_left == _right)
				return var(_left);
			return var();
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var signed_character_binary_and(var const& _left, var const& _right) noexcept
		{
			if (_left == _right)
				return var(_left);
			return var();
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_character_binary_and(var const& _left, var const& _right) noexcept
		{
			if (_left == _right)
				return var(_left);
			return var();
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_character_binary_and(var const& _left, var const& _right) noexcept
		{
			if (_left == _right)
				return var(_left);
			return var();
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_character_binary_and(var const& _left, var const& _right) noexcept
		{
			if (_left == _right)
				return var(_left);
			return var();
		}
		#endif

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_character_binary_and(var const& _left, var const& _right) noexcept
		{
			if (_left == _right)
				return var(_left);
			return var();
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_character_binary_and(var const& _left, var const& _right) noexcept
		{
			if (_left == _right)
				return var(_left);
			return var();
		}

	#endif
#endif

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var short_binary_and(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned short() & _right.operator unsigned short());
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_short_binary_and(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned short() & _right.operator unsigned short());
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var integer_binary_and(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned() & _right.operator unsigned());
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_integer_binary_and(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned() & _right.operator unsigned());
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_binary_and(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long() & _right.operator unsigned long());
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_binary_and(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long() & _right.operator unsigned long());
		}

#if (__cplusplus >= 201103L)

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_long_binary_and(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long long() & _right.operator unsigned long long());
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var unsigned_long_long_binary_and(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long long() & _right.operator unsigned long long());
		}

#endif

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var float_binary_and(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned() & _right.operator unsigned());
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var double_binary_and(var const& _left, var const& _right) noexcept
		{
			return var(_left.operator unsigned long() & _right.operator unsigned long());
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var long_double_binary_and(var const& _left, var const& _right) noexcept
		{
#if (__cplusplus >= 201103L)
			return var(_left.operator unsigned long long() & _right.operator unsigned long long());
#else
			return var(_left.operator unsigned long() & _right.operator unsigned long());
#endif
		}

		/// \brief Binary and operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var string_binary_and(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			char* buffer;
			if (_left.behaviour->rank == enum_string_type)
			{
				char* l = _left.value.string_type;
				char* r;
				if (_right.behaviour->rank == enum_string_type)
				{
					r = _right.value.string_type;
				}
				else
				{
					r = _right.behaviour->as_string(_right);
				}
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<char>(buffer_length + sizeof(char));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				if (_right.behaviour->rank != enum_string_type)
				{
					deallocate(r);
				}
			}
			else if (_right.behaviour->rank == enum_string_type)
			{
				char* l                   = _left.behaviour->as_string(_left);
				char* r                   = _right.value.string_type;
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<char>(buffer_length + sizeof(char));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				deallocate(l);
			}
			else
			{
				char* l                   = _left.behaviour->as_string(_left);
				char* r                   = _right.behaviour->as_string(_right);
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<char>(buffer_length + sizeof(char));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				deallocate(l);
				deallocate(r);
			}
			var result = var(buffer);
			deallocate(buffer);
			return result;
		}

		/// \brief Binary and operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var wide_string_binary_and(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			wchar_t* buffer;
			if (_left.behaviour->rank == enum_wide_string_type)
			{
				wchar_t* l = _left.value.wide_string_type;
				wchar_t* r;
				if (_right.behaviour->rank == enum_wide_string_type)
				{
					r = _right.value.wide_string_type;
				}
				else
				{
					r = _right.behaviour->as_wide_string(_right);
				}
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<wchar_t>(buffer_length + sizeof(wchar_t));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				if (_right.behaviour->rank != enum_wide_string_type)
				{
					deallocate(r);
				}
			}
			else if (_right.behaviour->rank == enum_wide_string_type)
			{
				wchar_t* l                = _left.behaviour->as_wide_string(_left);
				wchar_t* r                = _right.value.wide_string_type;
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<wchar_t>(buffer_length + sizeof(wchar_t));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				deallocate(l);
			}
			else
			{
				wchar_t* l                = _left.behaviour->as_wide_string(_left);
				wchar_t* r                = _right.behaviour->as_wide_string(_right);
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<wchar_t>(buffer_length + sizeof(wchar_t));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				deallocate(l);
				deallocate(r);
			}
			var result = var(buffer);
			deallocate(buffer);
			return result;
		}

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		/// \brief Binary and operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit8_string_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string binary and", static_cast<int>(LIBLETLIB_ENOTSUP))
		#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
		#endif
		}
	#endif
		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit16_string_binary_and(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			char16_t* buffer;
			if (_left.behaviour->rank == enum_bit16_string_type)
			{
				char16_t* l = _left.value.bit16_string_type;
				char16_t* r;
				if (_right.behaviour->rank == enum_bit16_string_type)
				{
					r = _right.value.bit16_string_type;
				}
				else
				{
					r = _right.behaviour->as_bit16_string(_right);
				}
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<char16_t>(buffer_length + sizeof(char16_t));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				if (_right.behaviour->rank != enum_bit16_string_type)
				{
					deallocate(r);
				}
			}
			else if (_right.behaviour->rank == enum_bit16_string_type)
			{
				char16_t* l               = _left.behaviour->as_bit16_string(_left);
				char16_t* r               = _right.value.bit16_string_type;
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<char16_t>(buffer_length + sizeof(char16_t));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				deallocate(l);
			}
			else
			{
				char16_t* l               = _left.behaviour->as_bit16_string(_left);
				char16_t* r               = _right.behaviour->as_bit16_string(_right);
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<char16_t>(buffer_length + sizeof(char16_t));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				deallocate(l);
				deallocate(r);
			}
			var result = var(buffer);
			deallocate(buffer);
			return result;
		}

		/// \brief Binary and operator.
		///
		/// \param _left hand side of operation.
		/// \param _right hand side of operation.
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var bit32_string_binary_and(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
			char32_t* buffer;
			if (_left.behaviour->rank == enum_bit32_string_type)
			{
				char32_t* l = _left.value.bit32_string_type;
				char32_t* r;
				if (_right.behaviour->rank == enum_bit32_string_type)
				{
					r = _right.value.bit32_string_type;
				}
				else
				{
					r = _right.behaviour->as_bit32_string(_right);
				}
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<char32_t>(buffer_length + sizeof(char32_t));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				if (_right.behaviour->rank != enum_bit32_string_type)
				{
					deallocate(r);
				}
			}
			else if (_right.behaviour->rank == enum_bit32_string_type)
			{
				char32_t* l               = _left.behaviour->as_bit32_string(_left);
				char32_t* r               = _right.value.bit32_string_type;
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<char32_t>(buffer_length + sizeof(char32_t));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				deallocate(l);
			}
			else
			{
				char32_t* l               = _left.behaviour->as_bit32_string(_left);
				char32_t* r               = _right.behaviour->as_bit32_string(_right);
				std::size_t buffer_length = string_length(l);
				std::size_t filter_length = string_length(r);
				buffer                    = allocate<char32_t>(buffer_length + sizeof(char32_t));
				for (std::size_t index = 0; index < buffer_length; ++index)
				{
					for (std::size_t jindex = 0; jindex < filter_length; ++jindex)
					{
						if (l[index] == r[jindex])
							buffer[index] = l[index];
					}
				}
				deallocate(l);
				deallocate(r);
			}
			var result = var(buffer);
			deallocate(buffer);
			return result;
		}

#endif

		/// \brief Binary and operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var pointer_binary_and(var const& _left, var const& _right) LIBLETLIB_NOEXCEPT
		{
#ifndef LIBLETLIB_FREESTANDING
	#if (__cplusplus >= 201103L)
			if (_left.behaviour->rank == enum_void_pointer_type && _right.behaviour->rank == enum_void_pointer_type)
			{
				if (_left.value.void_pointer_type)
					return _left.message("&")(_left, _right);
			}
			else if (_right.behaviour->rank == enum_void_pointer_type)
			{
				if (_right.value.void_pointer_type)
					return _right.message("&")(_left, _right);
			}
			else
			{
				if (_left.value.void_pointer_type)
					return _left.message("&")(_left, _right);
			}
	#endif
#endif
			LIBLETLIB_ERROR("Operator modulo unimplemented.", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Binary and operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var array_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: string binary and", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}


		/// \brief Binary and operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var subroutine_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Illegal operation: subroutine binary and", static_cast<int>(LIBLETLIB_EDOM))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

		/// \brief Binary and operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var function_binary_and(var const&, var const&) LIBLETLIB_NOEXCEPT
		{
			LIBLETLIB_ERROR("Unsupported operation: function binary and", static_cast<int>(LIBLETLIB_ENOTSUP))
#ifndef LIBLETLIB_ERROR_EXCEPTION
			return var();
#endif
		}

#if (__cplusplus >= 201103L)

		/// \brief Binary and operator.
		///
		/// \return result of operation.
		LIBLETLIB_NODISCARD inline var null_binary_and(var const&, var const&) noexcept
		{
			return var();
		}

#endif
	}// namespace detail
}// namespace libletlib


#endif//LIBLETLIB_LIBLETLIB_BINARY_AND_HPP
