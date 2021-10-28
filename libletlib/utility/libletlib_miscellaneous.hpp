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

#ifndef LIBLETLIB_LIBLETLIB_MISCELLANEOUS_HPP
#define LIBLETLIB_LIBLETLIB_MISCELLANEOUS_HPP

namespace libletlib
{
	namespace detail
	{
		namespace backing
		{
			/// \brief Get length of this var.
			/// \param value to property length of.
			/// \return Length of given iterable.
			LIBLETLIB_NODISCARD inline std::size_t length(var const& value) noexcept
			{
#ifndef LIBLETLIB_FREESTANDING
				switch (value.behaviour->rank)
				{
					case enum_string_type:
						return string_length(value.value.string_type);
					case enum_wide_string_type:
						return string_length(value.value.wide_string_type);
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
					case enum_bit8_string_type:
						return string_length(value.value.bit8_string_type);
		#endif
					case enum_bit16_string_type:
						return string_length(value.value.bit16_string_type);
					case enum_bit32_string_type:
						return string_length(value.value.bit32_string_type);
	#endif
					default:
#endif
						return value.size.in_use;
#ifndef LIBLETLIB_FREESTANDING
				}
#endif
			}

			/// \brief Return type of the wrapped value as C string.
			/// \return Type of the wrapped value as string.
			LIBLETLIB_NODISCARD inline char const* type_string(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_bool_type:
						return "bool";
					case enum_char_type:
						return "char";
					case enum_signed_char_type:
						return "signed char";
					case enum_unsigned_char_type:
						return "unsigned char";
					case enum_wchar_type:
						return "wchar_t";
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
					case enum_char8_type:
						return "char8_t";
	#endif
					case enum_char16_type:
						return "char16_t";
					case enum_char32_type:
						return "char32_t";
#endif
					case enum_short_type:
						return "short";
					case enum_unsigned_short_type:
						return "unsigned short";
					case enum_int_type:
						return "int";
					case enum_unsigned_int_type:
						return "unsigned int";
					case enum_long_type:
						return "long";
					case enum_unsigned_long_type:
						return "unsigned long";
#if (__cplusplus >= 201103L)
					case enum_long_long_type:
						return "long long";
					case enum_unsigned_long_long_type:
						return "unsigned long long";
#endif
					case enum_float_type:
						return "float";
					case enum_double_type:
						return "double";
					case enum_long_double_type:
						return "long double";
					case enum_string_type:
						return "char*";
					case enum_wide_string_type:
						return "wchar_t*";
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
					case enum_bit8_string_type:
						return "char8_t*";
	#endif
					case enum_bit16_string_type:
						return "char16_t*";
					case enum_bit32_string_type:
						return "char32_t*";
#endif
					case enum_void_pointer_type:
						return "void*";
#ifndef LIBLETLIB_FREESTANDING
					case enum_array_type:
						return "list";
					case enum_subroutine_type:
						return "subroutine";
					case enum_function_type:
						return "function";
#endif
#if (__cplusplus >= 201103L)
					case enum_nullptr_type:
						return "nullptr_t";
#endif
				}
				return "unknown";
			}

			/// \brief Is the value an integer?
			/// \param value to examine
			/// \return true if is integral, otherwise false
			LIBLETLIB_NODISCARD inline bool is_integral(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_short_type:
						LIBLETLIB_FALLTHROUGH
					case enum_unsigned_short_type:
						LIBLETLIB_FALLTHROUGH
					case enum_int_type:
						LIBLETLIB_FALLTHROUGH
					case enum_unsigned_int_type:
						LIBLETLIB_FALLTHROUGH
					case enum_long_type:
						LIBLETLIB_FALLTHROUGH
#if (__cplusplus >= 201103L)
					case enum_long_long_type:
						LIBLETLIB_FALLTHROUGH
					case enum_unsigned_long_long_type:
						LIBLETLIB_FALLTHROUGH
#endif
					case enum_unsigned_long_type:
						return true;
					default:
						return false;
				}
			}

			/// \brief Is the value a floating point value?
			/// \param value to examine
			/// \return true if is a floating point value, otherwise false
			LIBLETLIB_NODISCARD inline bool is_floating_point(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_float_type:
						LIBLETLIB_FALLTHROUGH
					case enum_double_type:
						LIBLETLIB_FALLTHROUGH
					case enum_long_double_type:
						return true;
					default:
						return false;
				}
			}

			/// \brief Is the value boolean?
			/// \param value to examine
			/// \return true if is boolean, otherwise false
			LIBLETLIB_NODISCARD inline bool is_boolean(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_bool_type:
						return true;
					default:
						return false;
				}
			}

			/// \brief Is the value a character?
			/// \param value to examine
			/// \return true if is a character, otherwise false
			LIBLETLIB_NODISCARD inline bool is_character(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_char_type:
						LIBLETLIB_FALLTHROUGH
					case enum_signed_char_type:
						LIBLETLIB_FALLTHROUGH
					case enum_unsigned_char_type:
						LIBLETLIB_FALLTHROUGH

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
					case enum_char8_type:
						LIBLETLIB_FALLTHROUGH
	#endif
					case enum_char16_type:
						LIBLETLIB_FALLTHROUGH
					case enum_char32_type:
						LIBLETLIB_FALLTHROUGH
#endif
					case enum_wchar_type:
						return true;
					default:
						return false;
				}
			}

			/// \brief Is the value unsigned?
			/// \param value to examine
			/// \return true if is unsigned, otherwise false
			LIBLETLIB_NODISCARD inline bool is_unsigned(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_unsigned_char_type:
						LIBLETLIB_FALLTHROUGH
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
					case enum_char8_type:
						LIBLETLIB_FALLTHROUGH
	#endif
					case enum_char16_type:
						LIBLETLIB_FALLTHROUGH
					case enum_char32_type:
						LIBLETLIB_FALLTHROUGH
#endif
					case enum_unsigned_short_type:
						LIBLETLIB_FALLTHROUGH
					case enum_unsigned_int_type:
						LIBLETLIB_FALLTHROUGH
#if (__cplusplus >= 201103L)
					case enum_unsigned_long_long_type:
						LIBLETLIB_FALLTHROUGH
#endif
					case enum_unsigned_long_type:
						return true;
					default:
						if (std::numeric_limits<char>::min() == 0)
						{
							return true;
						}
						return false;
				}
			}

			/// \brief Is the value signed?
			/// \param value to examine
			/// \return true if is signed, otherwise false
			LIBLETLIB_NODISCARD inline bool is_signed(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_signed_char_type:
						LIBLETLIB_FALLTHROUGH
					case enum_wchar_type:
						LIBLETLIB_FALLTHROUGH
					case enum_short_type:
						LIBLETLIB_FALLTHROUGH
					case enum_int_type:
						LIBLETLIB_FALLTHROUGH
#if (__cplusplus >= 201103L)
					case enum_long_long_type:
						LIBLETLIB_FALLTHROUGH
#endif
					case enum_long_type:
						return true;
					default:
						if (std::numeric_limits<char>::min() == std::numeric_limits<signed char>::min())
						{
							return true;
						}
						return false;
				}
			}

#ifndef LIBLETLIB_FREESTANDING

			/// \brief Is the value invokable?
			/// \param value to examine
			/// \return true if is invokable, otherwise false
			LIBLETLIB_NODISCARD inline bool is_invokable(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_subroutine_type:
						LIBLETLIB_FALLTHROUGH
					case enum_function_type:
						return true;
	#if (__cplusplus >= 201103L)
					case enum_void_pointer_type:
						if (value.objectify()->message("()") != empty_value)
							return true;
						return false;
	#endif
					default:
						return false;
				}
			}

			/// \brief Is the function curried?
			/// \param value to examine
			/// \return true if is curried, otherwise false
			LIBLETLIB_NODISCARD inline bool is_curried(var const& value) noexcept
			{
				if (is_invokable(value) && value.size.in_use > 0)
					return true;
				return false;
			}

			/// \brief Is the value a list?
			/// \param value to examine
			/// \return true if is list, otherwise false
			LIBLETLIB_NODISCARD inline bool is_list(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_array_type:
						return true;
					default:
						return false;
				}
			}

			/// \brief Is the value null?
			/// \param value to examine
			/// \return true if is null, otherwise false
			LIBLETLIB_NODISCARD inline bool is_null(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_string_type:
						if (value.value.string_type)
							return false;
						return true;
					case enum_wide_string_type:
						if (value.value.wide_string_type)
							return false;
						return true;
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
					case enum_bit8_string_type:
						if (value.value.bit8_string_type)
							return false;
						return true;

		#endif
					case enum_bit16_string_type:
						if (value.value.bit16_string_type)
							return false;
						return true;
					case enum_bit32_string_type:
						if (value.value.bit32_string_type)
							return false;
						return true;
	#endif
					case enum_array_type:
						if (value.value.array_type)
							return false;
						return true;
					case enum_void_pointer_type:
						if (value.value.void_pointer_type)
							return false;
						return true;
					case enum_nullptr_type:
						return true;
					default:
						return false;
				}
			}

			/// \brief Is the value empty?
			/// null is empty.
			/// \param value to examine
			/// \return true if is empty, otherwise false
			LIBLETLIB_NODISCARD inline bool is_empty(var const& value) noexcept
			{
				if (is_null(value))
					return true;
				switch (value.behaviour->rank)
				{
					case enum_string_type:
						if (value == "")
							return true;
						return false;
					case enum_wide_string_type:
						if (value == L"")
							return true;
						return false;
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
					case enum_bit8_string_type:
						if (value == u8"")
							return true;
						return false;
		#endif
					case enum_bit16_string_type:
						if (value == u"")
							return false;
						return true;
					case enum_bit32_string_type:
						if (value == U"")
							return false;
						return true;
	#endif
					case enum_array_type:
						if (value.size.in_use == 0)
							return false;
						return true;
	#if (__cplusplus >= 201103L)
					case enum_void_pointer_type:
						if (value.objectify()->inner.size.in_use == 0)
							return true;
						return false;
	#endif
					default:
						return false;
				}
			}

			/// \brief Is the value an object?
			/// \param value to examine
			/// \return true if is object, otherwise false
			LIBLETLIB_NODISCARD inline bool is_object(var const& value) noexcept
			{
	#if (__cplusplus >= 201103L)
				switch (value.behaviour->rank)
				{
					case enum_void_pointer_type:
						if (value.value.void_pointer_type)
							return true;
						return false;
					default:
						return false;
				}
	#else
				return false;
	#endif
			}

			/// \brief Is the value a string?
			/// \param value to examine
			/// \return true if is a string, otherwise false
			LIBLETLIB_NODISCARD inline bool is_string(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_string_type:
						LIBLETLIB_FALLTHROUGH
					case enum_wide_string_type:
						LIBLETLIB_FALLTHROUGH
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
					case enum_bit8_string_type:
						LIBLETLIB_FALLTHROUGH
		#endif
					case enum_bit16_string_type:
						LIBLETLIB_FALLTHROUGH
					case enum_bit32_string_type:
						return true;
	#endif
					default:
						return false;
				}
			}
#endif

			/// \brief Return one character symbol of wrapped type of var.
			/// \param value var to property type id of.
			/// \return character telling the wrapped type of var.
			LIBLETLIB_NODISCARD inline char type_id(var const& value) noexcept
			{
				switch (value.behaviour->rank)
				{
					case enum_bool_type:
						return static_cast<char>(enum_bool_type_id);
					case enum_char_type:
						return static_cast<char>(enum_char_type_id);
					case enum_signed_char_type:
						return static_cast<char>(enum_signed_char_type_id);
					case enum_unsigned_char_type:
						return static_cast<char>(enum_unsigned_char_type_id);
					case enum_wchar_type:
						return static_cast<char>(enum_wide_string_type_id);
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
					case enum_char8_type:
						return static_cast<char>(enum_char8_type_id);
	#endif
					case enum_char16_type:
						return static_cast<char>(enum_char16_type_id);
					case enum_char32_type:
						return static_cast<char>(enum_char32_type_id);
#endif
					case enum_short_type:
						return static_cast<char>(enum_short_type_id);
					case enum_unsigned_short_type:
						return static_cast<char>(enum_unsigned_short_type_id);
					case enum_int_type:
						return static_cast<char>(enum_int_type_id);
					case enum_unsigned_int_type:
						return static_cast<char>(enum_unsigned_int_type_id);
					case enum_long_type:
						return static_cast<char>(enum_long_type_id);
					case enum_unsigned_long_type:
						return static_cast<char>(enum_unsigned_long_type_id);
#if (__cplusplus >= 201103L)
					case enum_long_long_type:
						return static_cast<char>(enum_long_long_type_id);
					case enum_unsigned_long_long_type:
						return static_cast<char>(enum_unsigned_long_long_type_id);
#endif
					case enum_float_type:
						return static_cast<char>(enum_float_type_id);
					case enum_double_type:
						return static_cast<char>(enum_double_type_id);
					case enum_long_double_type:
						return static_cast<char>(enum_long_double_type_id);
					case enum_string_type:
						return static_cast<char>(enum_string_type_id);
					case enum_wide_string_type:
						return static_cast<char>(enum_wide_string_type_id);
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
					case enum_bit8_string_type:
						return static_cast<char>(enum_bit8_string_type_id);
	#endif
					case enum_bit16_string_type:
						return static_cast<char>(enum_bit16_string_type_id);
					case enum_bit32_string_type:
						return static_cast<char>(enum_bit32_string_type_id);
#endif
					case enum_void_pointer_type:
						return static_cast<char>(enum_void_pointer_type_id);
#ifndef LIBLETLIB_FREESTANDING
					case enum_array_type:
						return static_cast<char>(enum_array_type_id);
					case enum_subroutine_type:
						return static_cast<char>(enum_subroutine_type_id);
					case enum_function_type:
						return static_cast<char>(enum_function_type_id);
#endif
#if (__cplusplus >= 201103L)
					case enum_nullptr_type:
						return static_cast<char>(enum_nullptr_type_id);
#endif
					default:
						return static_cast<char>(enum_any_type_id);
				}
			}

		}// namespace backing

#ifdef LIBLETLIB_FREESTANDING
		LIBLETLIB_NODISCARD inline var length(var const& value)
		{
			return backing::length(value);
		}

		LIBLETLIB_NODISCARD inline var is_boolean(var const& value)
		{
			return backing::is_boolean(value);
		}

		LIBLETLIB_NODISCARD inline var is_floating_point(var const& value)
		{
			return backing::is_floating_point(value);
		}

		LIBLETLIB_NODISCARD inline var is_integral(var const& value)
		{
			return backing::is_integral(value);
		}

		LIBLETLIB_NODISCARD inline var is_character(var const& value)
		{
			return backing::is_character(value);
		}

		LIBLETLIB_NODISCARD inline var is_unsigned(var const& value)
		{
			return backing::is_unsigned(value);
		}

		LIBLETLIB_NODISCARD inline var is_signed(var const& value)
		{
			return backing::is_signed(value);
		}
#else

		/// \brief integral checking function.
		/// \param args arguments to this function.
		/// \return true if the value is integral, otherwise false.
		LIBLETLIB_NODISCARD inline var is_integral_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_integral(args[0]);
		}

		/// \brief boolean checking function.
		/// \param args arguments to this function.
		/// \return true if the value is boolean, otherwise false.
		LIBLETLIB_NODISCARD inline var is_boolean_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_boolean(args[0]);
		}

		/// \brief character checking function.
		/// \param args arguments to this function.
		/// \return true if the value is character, otherwise false.
		LIBLETLIB_NODISCARD inline var is_character_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_character(args[0]);
		}

		/// \brief signedness checking function.
		/// \param args arguments to this function.
		/// \return true if the value is signed, otherwise false.
		LIBLETLIB_NODISCARD inline var is_signed_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_signed(args[0]);
		}

		/// \brief unsignedness checking function.
		/// \param args arguments to this function.
		/// \return true if the value is unsigned, otherwise false.
		LIBLETLIB_NODISCARD inline var is_unsigned_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_unsigned(args[0]);
		}

		/// \brief list checking function.
		/// \param args arguments to this function.
		/// \return true if the value is list, otherwise false.
		LIBLETLIB_NODISCARD inline var is_list_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_list(args[0]);
		}

		/// \brief object checking function.
		/// \param args arguments to this function.
		/// \return true if the value is object, otherwise false.
		LIBLETLIB_NODISCARD inline var is_object_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_object(args[0]);
		}

		/// \brief invokable checking function.
		/// \param args arguments to this function.
		/// \return true if the value is invokable, otherwise false.
		LIBLETLIB_NODISCARD inline var is_invokable_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_invokable(args[0]);
		}

		/// \brief curry checking function.
		/// \param args arguments to this function.
		/// \return true if the value is curried, otherwise false.
		LIBLETLIB_NODISCARD inline var is_curried_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_curried(args[0]);
		}

		/// \brief floating point number checking function.
		/// \param args arguments to this function.
		/// \return true if the value is floating point number, otherwise false.
		LIBLETLIB_NODISCARD inline var is_floating_point_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_floating_point(args[0]);
		}

		/// \brief string checking function.
		/// \param args arguments to this function.
		/// \return true if the value is string, otherwise false.
		LIBLETLIB_NODISCARD inline var is_string_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_null(args[0]);
		}

		/// \brief null checking function.
		/// \param args arguments to this function.
		/// \return true if the value is null, otherwise false.
		LIBLETLIB_NODISCARD inline var is_null_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_null(args[0]);
		}

		/// \brief emptiness checking function.
		/// \param args arguments to this function.
		/// \return true if the value is empty, otherwise false.
		LIBLETLIB_NODISCARD inline var is_empty_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::is_empty(args[0]);
		}

		/// \brief Length implementation.
		/// \param args arguments to this function.
		/// \return length of first argument.
		LIBLETLIB_NODISCARD inline var length_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::length(args[0]);
		}

		/// \brief Type string implementation.
		/// \param args arguments to this function.
		/// \return type of wrapped type by var as a string.
		LIBLETLIB_NODISCARD inline var type_string_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::type_string(args[0]);
		}

		/// \brief Return type of the wrapped value as char.
		/// \return Type of the wrapped value as char.
		LIBLETLIB_NODISCARD inline var type_id_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return backing::type_id(args[0]);
		}

		/// \brief Construct a pattern of enclosed var type.
		/// \param self this function.
		/// \param args arguments to this function.
		/// \return string containing the pattern of the wrapped value of var.
		LIBLETLIB_NODISCARD inline var pattern_(var const& self, var const& args) LIBLETLIB_NOEXCEPT
		{
			var const& value = args[0];

			if (value.behaviour->rank == enum_array_type)
			{
				var pattern_string = "#[";
				for (std::size_t index = 0; index < value.size.in_use; ++index)
				{
					pattern_string += self(value.value.array_type[index]);
				}
				pattern_string += ']';
				return pattern_string;
			}
	#if (__cplusplus >= 201103L)
			if (value.behaviour->rank == enum_void_pointer_type)
			{
				var pattern_string = "@{";
				for (std::size_t index = 1; index < value.objectify()->inner.size.in_use; ++index)
				{
					pattern_string += self(value.objectify()->inner.value.array_type[index][1]);
				}
				pattern_string += '}';
				return pattern_string;
			}
	#endif
			return backing::type_id(value);
		}
#endif

	}// namespace detail
#ifndef LIBLETLIB_FREESTANDING
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const pattern           = libletlib::detail::pattern_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const type_id           = libletlib::detail::type_id_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const length            = libletlib::detail::length_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const type_string       = libletlib::detail::type_string_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_integral       = libletlib::detail::is_integral_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_floating_point = libletlib::detail::is_floating_point_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_boolean        = libletlib::detail::is_boolean_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_character      = libletlib::detail::is_character_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_signed         = libletlib::detail::is_signed_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_unsigned       = libletlib::detail::is_unsigned_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_string         = libletlib::detail::is_string_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_invokable      = libletlib::detail::is_invokable_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_curried        = libletlib::detail::is_curried_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_list           = libletlib::detail::is_list_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_object         = libletlib::detail::is_object_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_null           = libletlib::detail::is_null_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const is_empty          = libletlib::detail::is_empty_;
#endif
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_MISCELLANEOUS_HPP
