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

#ifndef LIBLETLIB_LIBLETLIB_FORWARD_DECLARATIONS_HPP
#define LIBLETLIB_LIBLETLIB_FORWARD_DECLARATIONS_HPP

namespace libletlib
{
	namespace detail
	{
		class var;

		typedef void (*subroutine_t)(var const&, var const&);
		typedef var (*function_t)(var const&, var const&);

		extern var empty_value;

		void LIBLETLIB_EMPTY_SUBROUTINE(var const&, var const&)
		{
		}

		var LIBLETLIB_EMPTY_FUNCTION(var const&, var const&);

		class MetaRoot;

		template<class>
		class Root;

		class Var;

		template<typename VarLet>
		class array_iterator;

		template<typename VarLet>
		class array_reverse_iterator;

		typedef array_iterator<var> var_iterator;
		typedef array_reverse_iterator<var> var_reverse_iterator;
		typedef array_iterator<var const> let_iterator;
		typedef array_reverse_iterator<var const> let_reverse_iterator;

		template<typename Type>
		Type* allocate(std::size_t _amount) noexcept;
		template<>
		var* allocate(std::size_t _amount) noexcept;
		template<typename Type>
		Type* reallocate(Type* _previous, std::size_t _new_size) noexcept;
		void stack_deallocate(var const&) noexcept;
		void string_deallocate(var const& _value) noexcept;
		void wide_string_deallocate(var const& _value) noexcept;
		void array_deallocate(var const& _value) noexcept;
		void object_deallocate(var const& _value) noexcept;

#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		inline void bit8_string_deallocate(var const& _value) noexcept;
	#endif
		inline void bit16_string_deallocate(var const& _value) noexcept;
		inline void bit32_string_deallocate(var const& _value) noexcept;

#endif
		template<typename Type>
		void deallocate(Type* _pointer) noexcept;
		template<>
		void deallocate(MetaRoot* _pointer) noexcept;

#ifndef LIBLETLIB_FREESTANDING

		var* array_clone(var const*, std::size_t, std::size_t) noexcept;

#endif

		namespace backing
		{
#if (__cplusplus >= 201103L)

			template<typename... Arguments>
			var list(Arguments const&... element) noexcept;

#else
			inline var list() noexcept;
			template<typename Type1>
			inline var list(Type1) noexcept;
			template<typename Type1, typename Type2>
			inline var list(Type1, Type2) noexcept;
			template<typename Type1, typename Type2, typename Type3>
			inline var list(Type1, Type2, Type3) noexcept;
			template<typename Type1, typename Type2, typename Type3, typename Type4>
			inline var list(Type1, Type2, Type3, Type4) noexcept;
			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5>
			inline var list(Type1, Type2, Type3, Type4, Type5) noexcept;
			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6>
			inline var list(Type1, Type2, Type3, Type4, Type5, Type6) noexcept;
			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7>
			inline var list(Type1, Type2, Type3, Type4, Type5, Type6, Type7) noexcept;
			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7, typename Type8>
			inline var list(Type1, Type2, Type3, Type4, Type5, Type6, Type7, Type8) noexcept;
			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7, typename Type8, typename Type9>
			inline var list(Type1, Type2, Type3, Type4, Type5, Type6, Type7, Type8, Type9) noexcept;
			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7, typename Type8, typename Type9, typename Type10>
			inline var list(Type1, Type2, Type3, Type4, Type5, Type6, Type7, Type8, Type9, Type10) noexcept;
#endif

			int rank_compare(var const&, var const&) noexcept;
			char type_id(var const&) noexcept;
			char const* type_string(var const&) noexcept;
			std::size_t length(var const&) noexcept;
#if (__cplusplus >= 201103L)
			template<typename... Arguments>
			var list(Arguments const&...) noexcept;
#else
			inline var list() noexcept;

			template<typename Type>
			inline var list(Type item) noexcept;

			template<typename Type1, typename Type2>
			inline var list(Type1, Type2) noexcept;

			template<typename Type1, typename Type2, typename Type3>
			inline var list(Type1, Type2, Type3) noexcept;

			template<typename Type1, typename Type2, typename Type3, typename Type4>
			inline var list(Type1, Type2, Type3, Type4) noexcept;

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5>
			inline var list(Type1, Type2, Type3, Type4, Type5) noexcept;

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6>
			inline var list(Type1, Type2, Type3, Type4, Type5, Type6) noexcept;

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7>
			inline var list(Type1, Type2, Type3, Type4, Type5, Type6, Type7) noexcept;

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7, typename Type8>
			inline var list(Type1, Type2, Type3, Type4, Type5, Type6, Type7, Type8) noexcept;

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7, typename Type8, typename Type9>
			inline var list(Type1, Type2, Type3, Type4, Type5, Type6, Type7, Type8, Type9) noexcept;

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7, typename Type8, typename Type9, typename Type10>
			inline var list(Type1, Type2, Type3, Type4, Type5, Type6, Type7, Type8, Type9, Type10) noexcept;
#endif
			bool is_list(var const&) noexcept;
			bool is_object(var const&) noexcept;
			bool is_null(var const&) noexcept;
			bool is_empty(var const&) noexcept;
			bool is_string(var const&) noexcept;
			bool is_character(var const&) noexcept;
			bool is_integral(var const&) noexcept;
			bool is_floating_point(var const&) noexcept;
			bool is_boolean(var const&) noexcept;
			bool is_unsigned(var const&) noexcept;
			bool is_signed(var const&) noexcept;
			bool is_invokable(var const&) noexcept;
			bool is_curried(var const&) noexcept;
		}// namespace backing
	}    // namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_FORWARD_DECLARATIONS_HPP
