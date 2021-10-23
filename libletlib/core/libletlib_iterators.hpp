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

#ifndef LIBLETLIB_LIBLETLIB_ITERATORS_HPP
#define LIBLETLIB_LIBLETLIB_ITERATORS_HPP

#include "libletlib_var.hpp"

namespace libletlib
{
	namespace detail
	{
#if (__cplusplus >= 201103L)
	#ifndef LIBLETLIB_FREESTANDING
		/// \brief Iterator for var lists and strings.
		/// \tparam VarLet iterable type.
		template<typename VarLet>
		class array_iterator
		{
			template<typename>
			friend class array_reverse_iterator;

		public:
			using value_type        = VarLet;
			using pointer           = VarLet*;
			using reference         = VarLet&;
			using const_reference   = VarLet const&;
			using iterator_category = std::random_access_iterator_tag;
			using difference_type   = std::ptrdiff_t;


			/// \brief Constructor from a pointer (nullptr by default).
			/// \param _value to iterate over.
			explicit array_iterator(pointer _value = nullptr) noexcept
			{
				this->position = _value;
			}

			/// \brief Default copy constructor.
			/// \param _other to copy from.
			array_iterator(array_iterator const& _other)
			{
				this->position = _other.position;
			}

			/// \brief Default destructor.
			~array_iterator() noexcept = default;

			/// \brief Assignment operator from another iterator.
			/// \param _other iterator to assign to this iterator.
			/// \return this with _other iterator assignment.
			LIBLETLIB_NODISCARD array_iterator& operator=(array_iterator const& _other)
			{
				this->position = _other.position;
				return *this;
			}

			/// \brief Assignment operator.
			/// \param _value to assign to this iterator.
			/// \return this with _pointer assigned.
			LIBLETLIB_NODISCARD array_iterator& operator=(pointer _value) noexcept
			{
				this->position = _value;
				return *this;
			}

			/// \brief Is this pointer nullptr?
			/// \return Is this pointer nullptr?
			LIBLETLIB_NODISCARD explicit operator bool() const noexcept
			{
				return this->position != nullptr;
			}

			/// \brief Equality operator.
			/// \param _other to compare with.
			/// \return Is this equal with _other.
			LIBLETLIB_NODISCARD bool operator==(array_iterator const& _other) const noexcept
			{
				return this->position == _other.position;
			}

			/// \brief Not-equal operator.
			/// \param _other to compare with.
			/// \return Is this equal with _other?
			LIBLETLIB_NODISCARD bool operator!=(array_iterator const& _other) const noexcept
			{
				return position != _other.position;
			}

			/// \brief Sum assignment operator.
			/// \param _delta difference to add.
			/// \return This with movement added.
			LIBLETLIB_NODISCARD array_iterator& operator+=(difference_type const _delta) noexcept
			{
				this->position += _delta;
				return *this;
			}

			/// \brief Subtraction assignment operator.
			/// \param _delta difference to subtract.
			/// \return This with movement subtracted.
			LIBLETLIB_NODISCARD array_iterator& operator-=(difference_type const _delta) noexcept
			{
				this->position -= _delta;
				return *this;
			}

			/// \brief Prefix increment this iterator.
			/// \return Incremented iterator.
			LIBLETLIB_NODISCARD array_iterator& operator++() noexcept
			{
				++this->position;
				return *this;
			}

			/// \brief Prefix decrement this iterator.
			/// \return Decremented iterator.
			LIBLETLIB_NODISCARD array_iterator& operator--() noexcept
			{
				--this->position;
				return *this;
			}

			/// \brief Postfix increment this iterator.
			/// \return Increment iterator.
			LIBLETLIB_NODISCARD array_iterator const operator++(int) noexcept
			{
				array_iterator temporary(*this);
				++this->position;
				return temporary;
			}

			/// \brief Postfix decrement this iterator.
			/// \return Decremented iterator.
			LIBLETLIB_NODISCARD array_iterator const operator--(int) noexcept
			{
				array_iterator temporary(*this);
				--this->position;
				return temporary;
			}

			/// \brief Get iterator from distance from this iterator.
			/// \param _delta Difference from another calculation.
			/// \return Iterator for the difference.
			LIBLETLIB_NODISCARD array_iterator operator+(difference_type const _delta) noexcept
			{
				pointer old = this->position;
				this->position += _delta;
				array_iterator temporary(*this);
				this->position = old;
				return temporary;
			}

			/// \brief Get iterator from distance from this iterator.
			/// \param _delta Difference from another calculation.
			/// \return Iterator for the difference.
			LIBLETLIB_NODISCARD array_iterator operator-(difference_type const _delta) noexcept
			{
				pointer old = this->position;
				this->position -= _delta;
				array_iterator temporary(*this);
				this->position = old;
				return temporary;
			}

			/// \brief Get difference between two iterators.
			/// \param _other iterator to consider for difference.
			/// \return Difference between this and _other iterator.
			LIBLETLIB_NODISCARD difference_type operator-(array_iterator const& _other) noexcept
			{
				return _other.position - this->position;
			}

			/// \brief Indirection operator.
			/// \return Type wrapped by this pointer.
			LIBLETLIB_NODISCARD reference operator*() noexcept
			{
				return *position;
			}

			/// \brief Const indirection operator.
			/// \return Type wrapped by this pointer.
			LIBLETLIB_NODISCARD const_reference operator*() const noexcept
			{
				return *this->position;
			}

			/// \brief Pointer access operator.
			/// \return Pointer wrapped by this iterator.
			LIBLETLIB_NODISCARD pointer operator->() noexcept
			{
				return this->position;
			}

		protected:
			pointer position;
		};

		/// \brief Reverse iterator for var lists and strings.
		/// \tparam VarLet iterable type.
		template<typename VarLet>
		class array_reverse_iterator : public array_iterator<VarLet>
		{
		public:
			/// \brief Constructor from a pointer (nullptr by default).
			/// \param _pointer to iterate over.
			explicit array_reverse_iterator(typename array_iterator<VarLet>::pointer _pointer = nullptr) noexcept
			    : array_iterator<VarLet>(_pointer)
			{
			}

			/// \brief Default copy constructor.
			/// \param _other to copy from.
			explicit array_reverse_iterator(array_iterator<VarLet> const& _other) noexcept
			    : array_iterator<VarLet>(_other)
			{
			}

			/// \brief Default copy constructor.
			/// \param _other to copy from.
			array_reverse_iterator(array_reverse_iterator const& _other) noexcept : array_iterator<VarLet>(_other)
			{
			}

			/// \brief Default destructor.
			~array_reverse_iterator() noexcept = default;

			/// \brief Assignment operator from another reverse iterator.
			/// \param _other iterator to assign to this iterator.
			/// \return this with _other iterator assignment.
			LIBLETLIB_NODISCARD array_reverse_iterator& operator=(const array_reverse_iterator& _other) noexcept
			{
				this->position = _other.position;
				return *this;
			}

			/// \brief Assignment operator from another normal iterator.
			/// \param _other iterator to assign to this iterator.
			/// \return this with _other iterator assignment.
			LIBLETLIB_NODISCARD array_reverse_iterator& operator=(array_iterator<VarLet> const& _other) noexcept
			{
				this->position = _other.position;
				return *this;
			}

			/// \brief Assignment operator.
			/// \param _pointer to assign to this iterator.
			/// \return this with _pointer assigned.
			LIBLETLIB_NODISCARD array_reverse_iterator& operator=(
			    typename array_iterator<VarLet>::pointer _pointer) noexcept
			{
				this->position = _pointer;
				return *this;
			}

			/// \brief Sum assignment operator.
			/// \param movement difference to add.
			/// \return This with movement added.
			LIBLETLIB_NODISCARD array_reverse_iterator& operator+=(
			    typename array_iterator<VarLet>::difference_type const movement) noexcept
			{
				this->position -= movement;
				return *this;
			}

			/// \brief Subtraction assignment operator.
			/// \param movement difference to subtract.
			/// \return This with movement subtracted.
			LIBLETLIB_NODISCARD array_reverse_iterator& operator-=(
			    typename array_iterator<VarLet>::difference_type const movement) noexcept
			{
				this->position += movement;
				return *this;
			}

			/// \brief Prefix increment this iterator.
			/// \return Incremented iterator.
			LIBLETLIB_NODISCARD array_reverse_iterator& operator++() noexcept
			{
				--this->position;
				return *this;
			}

			/// \brief Prefix decrement this iterator.
			/// \return Decremented iterator.
			LIBLETLIB_NODISCARD array_reverse_iterator& operator--() noexcept
			{
				++this->position;
				return *this;
			}

			/// \brief Postfix increment this iterator.
			/// \return Increment iterator.
			LIBLETLIB_NODISCARD array_reverse_iterator operator++(int) noexcept
			{
				array_reverse_iterator temp(*this);
				--this->position;
				return temp;
			}

			/// \brief Postfix decrement this iterator.
			/// \return Decremented iterator.
			LIBLETLIB_NODISCARD array_reverse_iterator operator--(int) noexcept
			{
				array_reverse_iterator temp(*this);
				++this->position;
				return temp;
			}

			/// \brief Get iterator from distance from this iterator.
			/// \param _delta Difference from another calculation.
			/// \return Iterator for the difference.
			LIBLETLIB_NODISCARD array_reverse_iterator
			operator+(typename array_iterator<VarLet>::difference_type const _delta) noexcept
			{
				typename array_iterator<VarLet>::pointer old = this->position;
				this->position -= _delta;
				array_reverse_iterator temporary(*this);
				this->position = old;
				return temporary;
			}

			/// \brief Get iterator from distance from this iterator.
			/// \param _delta Difference from another calculation.
			/// \return Iterator for the difference.
			LIBLETLIB_NODISCARD array_reverse_iterator
			operator-(typename array_iterator<VarLet>::difference_type const _delta) noexcept
			{
				typename array_iterator<VarLet>::pointer old = this->position;
				this->position += _delta;
				array_reverse_iterator temporary(*this);
				this->position = old;
				return temporary;
			}

			/// \brief Get difference between two iterators.
			/// \param _other iterator to consider for difference.
			/// \return Difference between this and _other iterator.
			LIBLETLIB_NODISCARD typename array_iterator<VarLet>::difference_type operator-(
			    array_reverse_iterator const& _other) noexcept
			{
				return std::distance(array_iterator<VarLet>::position, _other.position);
			}

			/// \brief Get normal iterator out of this reverse one.
			///
			/// \return Normal iterator.
			LIBLETLIB_NODISCARD array_iterator<VarLet> base() noexcept
			{
				return ++array_iterator<VarLet>(array_iterator<VarLet>::position);
			}
		};

		typedef array_iterator<var> var_iterator;
		typedef array_reverse_iterator<var> var_reverse_iterator;
		typedef array_iterator<var const> let_iterator;
		typedef array_reverse_iterator<var const> let_reverse_iterator;

		/// \brief Get iterator of the start.
		///
		/// As per C++ iterable conventions.
		///
		/// \param _var iterable.
		/// \return Iterator to the start.
		LIBLETLIB_NODISCARD inline var_iterator begin(var const& _var) noexcept
		{
			if (_var.behaviour->rank == enum_array_type)
			{
				return var_iterator(_var.value.array_type);
			}
			return var_iterator(_var.behaviour->as_array(_var).value.array_type);
		}

		/// \brief Get iterator of the end.
		///
		/// As per C++ iterable conventions.
		///
		/// \param _var iterable.
		/// \return Iterator to the end.
		LIBLETLIB_NODISCARD inline var_iterator end(var const& _var) noexcept
		{
			if (_var.behaviour->rank != enum_array_type)
			{
				var array = _var.behaviour->as_array(_var);
				return var_iterator(array.value.array_type + array.size.in_use);
			}
			return var_iterator(_var.value.array_type + _var.size.in_use);
		}

		/// \brief Get constant iterator of the start.
		///
		/// As per C++ iterable conventions.
		///
		/// \param _var iterable.
		/// \return Constant iterator to the start.
		LIBLETLIB_NODISCARD inline let_iterator cbegin(var const& _var) noexcept
		{
			if (_var.behaviour->rank == enum_array_type)
			{
				return let_iterator(_var.value.array_type);
			}
			return let_iterator(_var.behaviour->as_array(_var).value.array_type);
		}

		/// \brief Get constant iterator of the end.
		///
		/// As per C++ iterable conventions.
		///
		/// \param _var iterable.
		/// \return Constant iterator to the end.
		LIBLETLIB_NODISCARD inline let_iterator cend(var const& _var) noexcept
		{
			if (_var.behaviour->rank != enum_array_type)
			{
				var array = backing::list(_var);
				return let_iterator(array.value.array_type + array.size.in_use);
			}
			return let_iterator(_var.value.array_type + _var.size.in_use);
		}

		/// \brief Get reverse iterator of the start.
		///
		/// As per C++ iterable conventions.
		///
		/// \param _var iterable.
		/// \return Reverse iterator to the start.
		LIBLETLIB_NODISCARD inline var_reverse_iterator rbegin(var const& _var) noexcept
		{
			if (_var.behaviour->rank != enum_array_type)
			{
				var array = backing::list(_var);
				return var_reverse_iterator(array.value.array_type + array.size.in_use - 1ul);
			}
			return var_reverse_iterator(_var.value.array_type + _var.size.in_use - 1ul);
		}

		/// \brief Get reverse iterator of the end.
		///
		/// As per C++ iterable conventions.
		///
		/// \param _var iterable.
		/// \return Reverse iterator to the end.
		LIBLETLIB_NODISCARD inline var_reverse_iterator rend(var const& _var) noexcept
		{
			return var_reverse_iterator(_var.value.array_type - 1ul);
		}

		/// \brief Get constant reverse iterator of the start.
		///
		/// As per C++ iterable conventions.
		///
		/// \param _var iterable.
		/// \return Constant reverse iterator to the start.
		LIBLETLIB_NODISCARD inline let_reverse_iterator crbegin(var const& _var) noexcept
		{
			if (_var.behaviour->rank != enum_array_type)
			{
				var array = backing::list(_var);
				return let_reverse_iterator(array.value.array_type + array.size.in_use - 1ul);
			}
			return let_reverse_iterator(_var.value.array_type + _var.size.in_use - 1ul);
		}

		/// \brief Get constant reverse iterator of the end.
		///
		/// As per C++ iterable conventions.
		///
		/// \param _var iterable.
		/// \return Constant reverse iterator to the end.
		LIBLETLIB_NODISCARD inline let_reverse_iterator crend(var const& _var) noexcept
		{
			return let_reverse_iterator(_var.behaviour->as_array(_var).value.array_type - 1ul);
		}
	#endif
#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_ITERATORS_HPP
