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
#ifndef LIBLETLIB_LIBLETLIB_ROOTS_HPP
#define LIBLETLIB_LIBLETLIB_ROOTS_HPP

#include "libletlib_iterators.hpp"
#include "libletlib_var.hpp"
#include <ostream>

namespace libletlib
{
	namespace detail
	{

		/// \brief Represents an empty value.
		var const empty_value = var();

#if (__cplusplus >= 201103L)
	#ifndef LIBLETLIB_FREESTANDING
		/// \brief Get a mutable reference to a property.
		/// \param _target object
		/// \param _key of the property
		/// \return A mutable reference to the property in _target denoted by _key.
		LIBLETLIB_NODISCARD inline var& property_reference(var const& _target, char const* const _key) noexcept
		{
			for (var& pair : _target)
			{
				if (pair.at(0) == _key)
				{
					return pair.at(1);
				}
			}
			return const_cast<var&>(empty_value);
		}

		/// \brief Root type all objects are casted to.
		class MetaRoot
		{
			friend class var;

			friend var pattern_(var const&, var const&) LIBLETLIB_NOEXCEPT;
			friend bool backing::is_empty(var const&) noexcept;
			friend std::ostream& operator<<(std::ostream& _out, var const& _item) noexcept;
			friend std::wostream& operator<<(std::wostream& _out, var const& _item) noexcept;
			friend var pointer_index(var const&, var const&) LIBLETLIB_NOEXCEPT;

		protected:
			var inner;
			MetaRoot()                = default;
			MetaRoot(MetaRoot const&) = default;

		public:
			virtual ~MetaRoot() noexcept                                       = default;
			virtual inline MetaRoot* create() const noexcept                   = 0;
			virtual inline MetaRoot* clone() const noexcept                    = 0;

			/// \brief Get a member by its key.
			/// \param key of member to property.
			/// \return reference to the member pointed to by its key.
			LIBLETLIB_NODISCARD inline var& message(char const* const key) noexcept
			{
				var& result = libletlib::detail::property_reference(this->inner, key);
				if (std::addressof(result) == std::addressof(libletlib::detail::empty_value))
					this->inner = this->inner += backing::list(key, var());
				else
					return result;
				return libletlib::detail::property_reference(this->inner, key);
			}

			/// \brief Get a const reference to a member by its key.
			/// \param key of member to property.
			/// \return const reference to the member pointed to by its key.
			LIBLETLIB_NODISCARD inline var const& message(char const* const key) const noexcept
			{
				return libletlib::detail::property_reference(this->inner, key);
			}
		};

		/// \brief "Reverse" inheriting class via Curiously Recurring Template Pattern
		/// \tparam Inheritor the class that inherits this class.
		template<class Inheritor>
		class Root : public MetaRoot
		{
		public:
			Root() noexcept   = default;
			Root(Root const&) = default;

			/// \brief Copy constructor of Inheritor..
			/// \return (A new) copy of Inheritor.
			LIBLETLIB_NODISCARD inline Root<Inheritor>* create() const noexcept override
			{
				return new Inheritor();
			}

			/// \brief Copy of Inheritor.
			/// \return Copy of Inheritor.
			LIBLETLIB_NODISCARD inline Root<Inheritor>* clone() const noexcept override
			{
				return new Inheritor(*static_cast<Inheritor const*>(this));
			}

		};

		class Var final : public Root<Var>
		{
		public:
			Var()
			{
				inner = {{"name", "Var"}, {"value", var()}};
			}

			explicit Var(var const& value)
			{
				inner = {{"name", "Var"}, {"value", value}};
			}
		};

	#endif
#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_ROOTS_HPP
