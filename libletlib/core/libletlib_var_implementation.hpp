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

#ifndef LIBLETLIB_LIBLETLIB_VAR_IMPLEMENTATION_HPP
#define LIBLETLIB_LIBLETLIB_VAR_IMPLEMENTATION_HPP

namespace libletlib
{
	namespace detail
	{

		/// \brief Copy assignment operator.
		/// \param _other var to copy from.
		/// \return copy of _other.
		var& var::operator=(var const& _other) noexcept
		{
			if (this != address_of(_other))
			{
				this->behaviour->deallocate(*this);
#ifndef LIBLETLIB_FREESTANDING
				if (_other.behaviour->rank == enum_string_type || _other.behaviour->rank == enum_wide_string_type
				    || _other.behaviour->rank == enum_array_type || _other.behaviour->rank == enum_void_pointer_type
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
				    || _other.behaviour->rank == enum_bit8_string_type
		#endif
				    || _other.behaviour->rank == enum_bit16_string_type
				    || _other.behaviour->rank == enum_bit32_string_type
	#endif
				)
				{
					switch (_other.behaviour->rank)
					{
						case enum_string_type:
							this->value = value_union(_other.value.string_type);
							break;
						case enum_wide_string_type:
							this->value = value_union(_other.value.wide_string_type);
							break;
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
						case enum_bit8_string_type:
							this->value = value_union(_other.value.bit8_string_type);
							break;
		#endif
						case enum_bit16_string_type:
							this->value = value_union(_other.value.bit16_string_type);
							break;
						case enum_bit32_string_type:
							this->value = value_union(_other.value.bit32_string_type);
							break;
	#endif
						case enum_array_type:
							this->value =
							    value_union(_other.value.array_type, _other.size.in_use, _other.size.allocated);
							break;
	#if (__cplusplus >= 201103L)
						case enum_void_pointer_type:

							if (_other.value.void_pointer_type)
							{
								this->value.void_pointer_type = _other.objectify()->clone();
								break;
							}
							else
							{
								goto not_pointer;
							}
	#endif
						default:
							goto not_pointer;
					}
				}
				else
				{
				not_pointer:
#endif
					this->value = _other.value;
#ifndef LIBLETLIB_FREESTANDING
				}
#endif
				this->size      = _other.size;
				this->behaviour = _other.behaviour;
			}
			return *this;
		}

		/// \brief Copy constructor.
		/// \param _other to construct copy of.
		var::var(var const& _other) noexcept
		{
#ifndef LIBLETLIB_FREESTANDING
			if (_other.behaviour->rank == enum_string_type || _other.behaviour->rank == enum_wide_string_type
			    || _other.behaviour->rank == enum_array_type || _other.behaviour->rank == enum_void_pointer_type
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			    || _other.behaviour->rank == enum_bit8_string_type
		#endif
			    || _other.behaviour->rank == enum_bit16_string_type || _other.behaviour->rank == enum_bit32_string_type
	#endif
			)
			{
				switch (_other.behaviour->rank)
				{
					case enum_string_type:
						this->value = value_union(_other.value.string_type);
						break;
					case enum_wide_string_type:
						this->value = value_union(_other.value.wide_string_type);
						break;
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
					case enum_bit8_string_type:
						this->value = value_union(_other.value.bit8_string_type);
						break;
		#endif
					case enum_bit16_string_type:
						this->value = value_union(_other.value.bit16_string_type);
						break;
					case enum_bit32_string_type:
						this->value = value_union(_other.value.bit32_string_type);
						break;
	#endif
					case enum_array_type:
						this->value = value_union(_other.value.array_type, _other.size.in_use, _other.size.allocated);
						break;
	#if (__cplusplus >= 201103L)
					case enum_void_pointer_type:
						if (_other.value.void_pointer_type)
						{
							this->value.void_pointer_type = _other.objectify()->clone();
						}
						else
						{
							goto not_pointer;
						}
						break;
	#endif
					default:
						goto not_pointer;
				}
			}
			else
			{
			not_pointer:
#endif
				this->value = _other.value;
#ifndef LIBLETLIB_FREESTANDING
			}
#endif
			this->size      = _other.size;
			this->behaviour = _other.behaviour;
		}

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Output-stream operator overload to print wrapped value.
		///
		/// \param _out stream to output to.
		/// \param _item to output.
		/// \return the outputting stream.
		std::ostream& operator<<(std::ostream& _out, var const& _item) noexcept
		{
			if (_item.behaviour->rank == enum_string_type)
			{
				_out << _item.value.string_type;
			}
			else if (_item.behaviour->rank == enum_array_type)
			{
				_out << '[';
				for (std::size_t index = 0; index < _item.size.in_use; ++index)
				{
					_out << _item.value.array_type[index];
					if (index + 1 < _item.size.in_use)
					{
						_out << ", ";
					}
				}
				_out << ']';
			}
	#if (__cplusplus >= 201103L)
			else if (_item.behaviour->rank == enum_void_pointer_type)
			{
				MetaRoot* mr = _item.objectify();
				_out << '{' << std::endl;
				for (std::size_t index = 0; index < mr->inner.size.in_use; ++index)
				{
					_out << mr->inner.value.array_type[index][0] << " => "
					     << backing::type_string(mr->inner.value.array_type[index][1]) << std::endl;
				}
				_out << '}';
			}
			else if (_item.behaviour->rank == enum_subroutine_type)
			{
				_out << "subroutine@" << &_item.value;
			}
			else if (_item.behaviour->rank == enum_function_type)
			{
				_out << "function@" << &_item.value;
			}
	#endif
			else
			{
				char* const temporary = _item.behaviour->as_string(_item);
				_out << temporary;
				deallocate(temporary);
			}
			return _out;
		}

		/// \brief Output-stream operator overload to print wrapped value.
		///
		/// \param _out stream to output to.
		/// \param _item to output.
		/// \return the outputting stream.
		std::wostream& operator<<(std::wostream& _out, var const& _item) noexcept
		{
			if (_item.behaviour->rank == enum_wide_string_type)
			{
				_out << _item.value.wide_string_type;
			}
			else if (_item.behaviour->rank == enum_array_type)
			{
				_out << L'[';
				for (std::size_t index = 0; index < _item.size.in_use; ++index)
				{
					_out << _item.value.array_type[index];
					if (index + 1 < _item.size.in_use)
					{
						_out << L", ";
					}
				}
				_out << L']';
			}
	#if (__cplusplus >= 201103L)
			else if (_item.behaviour->rank == enum_void_pointer_type)
			{
				MetaRoot* metaroot = _item.objectify();
				_out << L'{' << std::endl;
				for (std::size_t index = 0; index < metaroot->inner.size.in_use; ++index)
				{
					_out << metaroot->inner.value.array_type[index][0] << L" => "
					     << metaroot->inner.value.array_type[index][1] << std::endl;
				}
				_out << L'}';
			}
			else if (_item.behaviour->rank == enum_subroutine_type)
			{
				_out << L"subroutine@" << &_item.value;
			}
			else if (_item.behaviour->rank == enum_function_type)
			{
				_out << L"function@" << &_item.value;
			}
	#endif
			else
			{
				wchar_t* const temporary = _item.behaviour->as_wide_string(_item);
				_out << temporary;
				deallocate(temporary);
			}
			return _out;
		}

		/// \brief Function that returns a null-initialized var.
		/// \return null-initialized var.
		var LIBLETLIB_EMPTY_FUNCTION(var const&, var const&)
		{
			return var();
		}

	#if (__cplusplus >= 201103L)
		/// \brief Objectify current value (should be void pointer)
		/// \return Current value casted to MetaRoot*.
		LIBLETLIB_NODISCARD inline MetaRoot* var::objectify() const noexcept
		{
			if (this->behaviour->rank == enum_void_pointer_type)
				return reinterpret_cast<MetaRoot*>(this->value.void_pointer_type);
			return nothing;
		}

		/// \brief Objectify current value (should be void pointer)
		/// \return Current value casted to MetaRoot*.
		LIBLETLIB_NODISCARD inline MetaRoot* var::objectify() noexcept
		{
			if (this->behaviour->rank == enum_void_pointer_type)
				return reinterpret_cast<MetaRoot*>(this->value.void_pointer_type);
			*this = new Var(*this);
			return reinterpret_cast<MetaRoot*>(this->value.void_pointer_type);
		}

		/// \brief Send a message to an object.
		/// \tparam String type of string to send.
		/// \param string message to send.
		/// \return the result of the message call.
		template<typename String>
		LIBLETLIB_NODISCARD inline var& var::message(String const string) noexcept
		{
			return this->objectify()->message(string);
		}


		/// \brief Send a message to an object.
		/// \tparam String type of string to send.
		/// \param string message to send.
		/// \return the result of the message call.
		template<typename String>
		LIBLETLIB_NODISCARD inline var& var::message(String const string) const noexcept
		{
			return this->objectify()->message(string);
		}

		/// \brief Send a message to a object.
		/// \param string field to contact.
		/// \return the result of the message call.
		template<>
		LIBLETLIB_NODISCARD inline var& var::message<var const&>(var const& string) const noexcept
		{
			return this->objectify()->message(string);
		}
	#endif

		/// \brief Copy memory from one pointer to another.
		/// \param low pointer to start copying from.
		/// \param high pointer to copy to (exclusive).
		/// \return var containing the copied memory as string.
		template<>
		LIBLETLIB_NODISCARD inline var var::slice(char const* low, char const* const high) const LIBLETLIB_NOEXCEPT {
			var part = "";
			for(; low != high; ++low)
				part += *low;
			return part;
		}

#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_VAR_IMPLEMENTATION_HPP
