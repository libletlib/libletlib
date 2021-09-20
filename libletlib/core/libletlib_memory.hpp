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

#ifndef LIBLETLIB_LIBLETLIB_MEMORY_HPP
#define LIBLETLIB_LIBLETLIB_MEMORY_HPP

#include "libletlib_roots.hpp"
#include "libletlib_var.hpp"
#include <cstdlib>

namespace libletlib
{
	namespace detail
	{

		/// \brief No-op function as dummy deallocator for stack allocated types.
		///
		inline void stack_deallocate(var const&) noexcept
		{
		}

#if (__cplusplus < 201103L) || defined LIBLETLIB_FREESTANDING
		/// \brief void* type deallocation.
		/// \param _value to deallocate.
		inline void object_deallocate(var const&) noexcept
		{
		}
#else
		/// \brief Deallocate object types.
		/// \param _value to deallocate.
		inline void object_deallocate(var const& _value) noexcept
		{
			deallocate<MetaRoot>(reinterpret_cast<MetaRoot*>(_value.value.void_pointer_type));
		}
#endif

#ifndef LIBLETLIB_FREESTANDING

		/// \brief Wrapper for std::calloc with allocation failure exit hatch.
		///
		/// Checks if the allocation was valid before returning allocated memory,
		/// program exits with EXIT_FAILURE, if the allocation did not succeed.
		/// Might have to realloc memory for efficiency later, thus using calloc.
		/// \param _amount to allocate.
		/// \result pointer to the allocated memory.
		template<typename Type>
		LIBLETLIB_NODISCARD inline Type* allocate(std::size_t const _amount) noexcept
		{
			Type* const pointer = reinterpret_cast<Type*>(std::calloc(_amount, sizeof(Type)));
			if (pointer)
			{
				return pointer;
			}
			std::exit(EXIT_FAILURE);
		}

		/// \brief Special allocator for var.
		/// \param _amount of vars to allocate.
		/// \return pointer to allocated memory.
		template<>
		LIBLETLIB_NODISCARD inline var* allocate<var>(std::size_t const _amount) noexcept
		{
			return new var[_amount];
		}

		template<typename Type>
		LIBLETLIB_NODISCARD inline Type* reallocate(Type* _previous, std::size_t _new_size) noexcept
		{
			Type* const reallocated = reinterpret_cast<Type*>(std::realloc(_previous, _new_size));
			if (reallocated)
			{
				return reallocated;
			}
			std::exit(EXIT_FAILURE);
		}

		/// \brief Wrapper for std::free()
		///
		///
		/// \param _pointer to deallocate.
		template<typename Type>
		inline void deallocate(Type* _pointer) noexcept
		{
			std::free(reinterpret_cast<void*>(_pointer));
		}

	#if (__cplusplus >= 201103L)
		/// \brief Special deallocator for void pointer types that are not null.
		/// \param _pointer (MetaRoot*) to deallocate.
		template<>
		inline void deallocate<MetaRoot>(MetaRoot* _pointer) noexcept
		{
			delete _pointer;
		}
	#endif

		/// \brief Special deallocator for var lists.
		/// \param _pointer to deallocate.
		template<>
		inline void deallocate<var>(var* _pointer) noexcept
		{
			delete[] _pointer;
		}

		/// \brief Deallocator for raw string type.
		///
		/// \param _value the value union with the string to deallocate.
		inline void string_deallocate(var const& _value) noexcept
		{
			deallocate<char>(_value.value.string_type);
		}

		/// \brief Deallocator for wide string type.
		///
		/// \param _value the value union with the string to deallocate.
		inline void wide_string_deallocate(var const& _value) noexcept
		{
			deallocate<wchar_t>(_value.value.wide_string_type);
		}

		/// \brief Deallocate array types.
		/// \param _value to deallocate.
		inline void array_deallocate(var const& _value) noexcept
		{
			deallocate<var>(_value.value.array_type);
		}

	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
		/// \brief Deallocator for char8_t string type.
		///
		/// \param _value the value union with the string to deallocate.
		inline void bit8_string_deallocate(var const& _value) noexcept
		{
			deallocate<char8_t>(_value.value.bit8_string_type);
		}
		#endif

		/// \brief Deallocator for char16_t string type.
		///
		/// \param _value the value union with the string to deallocate.
		inline void bit16_string_deallocate(var const& _value) noexcept
		{
			deallocate<char16_t>(_value.value.bit16_string_type);
		}

		/// \brief Deallocator for char32_t string type.
		///
		/// \param _value the value union with the string to deallocate.
		inline void bit32_string_deallocate(var const& _value) noexcept
		{
			deallocate<char32_t>(_value.value.bit32_string_type);
		}

	#endif
#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_MEMORY_HPP
