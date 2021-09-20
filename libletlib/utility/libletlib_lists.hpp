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

#ifndef LIBLETLIB_LIBLETLIB_LISTS_HPP
#define LIBLETLIB_LIBLETLIB_LISTS_HPP

#ifndef LIBLETLIB_FREESTANDING
namespace libletlib
{
	namespace detail
	{
		/// \brief Clone a var array.
		///
		/// \param _source array to copy.
		/// \param _in_use amount of memory in use.
		/// \param _allocated amount of memory allocated.
		/// \return Pointer to copy of _source.
		LIBLETLIB_NODISCARD inline var* array_clone(var const* const _source, std::size_t const _in_use,
		                                            std::size_t const _allocated) noexcept
		{
			var* destination = allocate<var>(_in_use + _allocated);
			for (std::size_t i = 0; i < _in_use; ++i)
			{
				destination[i] = _source[i];
			}
			return destination;
		}

		namespace backing
		{
	#if (__cplusplus < 201103L)
			inline var list() noexcept
			{
				size_struct size = size_struct(0);
				var* array       = nothing;
				return var(array, size);
			}

			template<typename Type>
			inline var list(Type item) noexcept
			{
				var array = list();
				array += item;
				return array;
			}

			template<typename Type1, typename Type2>
			inline var list(Type1 item1, Type2 item2) noexcept
			{
				var array = list();
				array += item1;
				array += item2;
				return array;
			}

			template<typename Type1, typename Type2, typename Type3>
			inline var list(Type1 item1, Type2 item2, Type3 item3) noexcept
			{
				var array = list();
				array += item1;
				array += item2;
				array += item3;
				return array;
			}

			template<typename Type1, typename Type2, typename Type3, typename Type4>
			inline var list(Type1 item1, Type2 item2, Type3 item3, Type4 item4) noexcept
			{
				var array = list();
				array += item1;
				array += item2;
				array += item3;
				array += item4;
				return array;
			}

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5>
			inline var list(Type1 item1, Type2 item2, Type3 item3, Type4 item4, Type5 item5) noexcept
			{
				var array = list();
				array += item1;
				array += item2;
				array += item3;
				array += item4;
				array += item5;
				return array;
			}

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6>
			inline var list(Type1 item1, Type2 item2, Type3 item3, Type4 item4, Type5 item5, Type6 item6) noexcept
			{
				var array = list();
				array += item1;
				array += item2;
				array += item3;
				array += item4;
				array += item5;
				array += item6;
				return array;
			}

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7>
			inline var list(Type1 item1, Type2 item2, Type3 item3, Type4 item4, Type5 item5, Type6 item6,
			                Type7 item7) noexcept
			{
				var array = list();
				array += item1;
				array += item2;
				array += item3;
				array += item4;
				array += item5;
				array += item6;
				array += item7;
				return array;
			}

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7, typename Type8>
			inline var list(Type1 item1, Type2 item2, Type3 item3, Type4 item4, Type5 item5, Type6 item6, Type7 item7,
			                Type8 item8) noexcept
			{
				var array = list();
				array += item1;
				array += item2;
				array += item3;
				array += item4;
				array += item5;
				array += item6;
				array += item7;
				array += item8;
				return array;
			}

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7, typename Type8, typename Type9>
			inline var list(Type1 item1, Type2 item2, Type3 item3, Type4 item4, Type5 item5, Type6 item6, Type7 item7,
			                Type8 item8, Type9 item9) noexcept
			{
				var array = list();
				array += item1;
				array += item2;
				array += item3;
				array += item4;
				array += item5;
				array += item6;
				array += item7;
				array += item8;
				array += item9;
				return array;
			}

			template<typename Type1, typename Type2, typename Type3, typename Type4, typename Type5, typename Type6,
			         typename Type7, typename Type8, typename Type9, typename Type10>
			inline var list(Type1 item1, Type2 item2, Type3 item3, Type4 item4, Type5 item5, Type6 item6, Type7 item7,
			                Type8 item8, Type9 item9, Type10 item10) noexcept
			{
				var array = list();
				array += item1;
				array += item2;
				array += item3;
				array += item4;
				array += item5;
				array += item6;
				array += item7;
				array += item8;
				array += item9;
				array += item10;
				return array;
			}
		}
	#else

			/// \brief Make a list.
			///
			/// \tparam Arguments to make list out of
			/// \param element any fundamental type or var/let.
			/// \return List with elements given included.
			template<typename... Arguments>
			LIBLETLIB_NODISCARD inline var list(Arguments const&... element) noexcept
			{
				return var(std::initializer_list<var> {element...});
			}
		}

	#endif

		LIBLETLIB_NODISCARD inline var list_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			return args;
		}

		/// \brief Left fold a list.
		///
		/// !param folder bifunction ((x, y) -> z).
		/// !param foldable list to fold.
		/// !param initial value for folding.
		/// \return resulting list.
		LIBLETLIB_NODISCARD inline var foldl_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			var const& folder   = args[0];
			var const& foldable = args[1];
			var const& initial  = backing::length(args) > 2 ? args[2] : var();

			if (foldable.behaviour->rank != enum_array_type)
			{
				var array = foldable.behaviour->as_array(foldable);
				if (array.size.in_use < 1)
				{
					return initial;
				}
				var folded;
				std::size_t index = 0;
				if (initial == var())
				{
					folded = array[0];
					index  = 1;
				}
				else
				{
					folded = initial;
				}
				for (; index < array.size.in_use; ++index)
				{
					folded = folder(array[index], folded);
				}
				return folded;
			}
			else
			{
				if (foldable.size.in_use < 1)
				{
					return initial;
				}
				var folded;
				std::size_t index = 0;
				if (initial == var())
				{
					folded = foldable[0];
					index  = 1;
				}
				else
				{
					folded = initial;
				}
				for (; index < foldable.size.in_use; ++index)
				{
					folded = folder(foldable[index], folded);
				}
				return folded;
			}
		}

		/// \brief Right fold a list.
		///
		/// !param folder bifunction ((x, y) -> z).
		/// !param foldable list to fold.
		/// !param initial value for folding.
		/// \return resulting list.
		LIBLETLIB_NODISCARD inline var foldr_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			var const& folder   = args[0];
			var const& foldable = args[1];
			var const& initial  = backing::length(args) > 2 ? args[2] : var();

			if (foldable.behaviour->rank != enum_array_type)
			{
				var array = foldable.behaviour->as_array(foldable);
				if (array.size.in_use < 1)
				{
					return initial;
				}
				var folded;
				std::size_t index = 0;
				if (initial == var())
				{
					folded = array[0];
					index  = 1;
				}
				else
				{
					folded = initial;
				}
				for (; index < array.size.in_use; ++index)
				{
					folded = folder(folded, array[index]);
				}
				return folded;
			}
			else
			{
				if (foldable.size.in_use < 1)
				{
					return initial;
				}
				var folded;
				std::size_t index = 0;
				if (initial == var())
				{
					folded = foldable[0];
					index  = 1;
				}
				else
				{
					folded = initial;
				}
				for (; index < foldable.size.in_use; ++index)
				{
					folded = folder(folded, foldable[index]);
				}
				return folded;
			}
		}


		/// \brief Map over values with mapper (function).
		///
		/// In functional terms: (a -> b) -> [a] -> [b]
		///
		/// !param mapper (a -> b)
		/// !param mappable list.
		/// \return resulting list.
		LIBLETLIB_NODISCARD inline var map_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			var const& mapper   = args[0];
			var const& mappable = args[1];

			var result = backing::list();
			if (mappable.behaviour->rank != enum_array_type)
			{
				var array = mappable.behaviour->as_array(mappable);
				for (std::size_t index = 0; index < array.size.in_use; ++index)
				{
					result += mapper(array[index]);
				}
			}
			else
			{
				for (std::size_t index = 0; index < mappable.size.in_use; ++index)
				{
					result += mapper(mappable[index]);
				}
			}
			return result;
		}

		/// \brief Filter based on a filterer function.
		///
		/// In functional terms: (a -> bool) -> [a] -> [a]
		///
		/// !param filterer (predicate).
		/// !param filterable list.
		/// \return resulting list.
		LIBLETLIB_NODISCARD inline var filter_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			var const& filterer   = args[0];
			var const& filterable = args[1];

			var result = backing::list();
			var truth;
			if (filterable.behaviour->rank != enum_array_type)
			{
				var array = filterable.behaviour->as_array(filterable);
				for (std::size_t index = 0; index < array.size.in_use; ++index)
				{
					if (filterer(array[index]))
					{
						result += array[index];
					}
				}
			}
			else
			{
				for (std::size_t index = 0; index < filterable.size.in_use; ++index)
				{
					if (filterer(filterable[index]))
					{
						result += filterable[index];
					}
				}
			}
			return result;
		}

		/// \brief Peek "for each" element in this var.
		///
		/// In functional terms: (a -> void) -> [a] -> [a]
		///
		/// !param peeker (function to view the elements).
		/// !param peekable list.
		/// \return self.
		inline var peek_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			var const& peeker   = args[0];
			var const& peekable = args[1];

			if (peekable.behaviour->rank != enum_array_type)
			{
				var array = peekable.behaviour->as_array(peekable);
				for (std::size_t index = 0; index < array.size.in_use; ++index)
				{
					peeker(array[index]);
				}
			}
			else
			{
				for (std::size_t index = 0; index < peekable.size.in_use; ++index)
				{
					peeker(peekable[index]);
				}
			}
			return peekable;
		}

		/// \brief Get head of an iterable.
		///
		/// !param iterable (array or string type).
		/// \return head of given iterable.
		LIBLETLIB_NODISCARD inline var head_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			var const& iterable = args[0];

			if (iterable.behaviour->rank == enum_array_type || iterable.behaviour->rank == enum_string_type
			    || iterable.behaviour->rank == enum_wide_string_type
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			    || iterable.behaviour->rank == enum_bit8_string_type
		#endif
			    || iterable.behaviour->rank == enum_bit16_string_type
			    || iterable.behaviour->rank == enum_bit32_string_type
	#endif
			)
			{
				return iterable.operator[](0);
			}
			return iterable;
		}

		/// \brief Get tail of an iterable.
		///
		/// !param iterable (array or string type).
		/// \return Tail of given iterable.
		LIBLETLIB_NODISCARD inline var tail_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			var const& iterable = args[0];

			if (iterable.behaviour->rank == enum_array_type || iterable.behaviour->rank == enum_string_type
			    || iterable.behaviour->rank == enum_wide_string_type
	#ifndef LIBLETLIB_DISABLE_UCHAR
		#if (__cplusplus >= 202002L)
			    || iterable.behaviour->rank == enum_bit8_string_type
		#endif
			    || iterable.behaviour->rank == enum_bit16_string_type
			    || iterable.behaviour->rank == enum_bit32_string_type
	#endif
			)
			{
				size_struct new_size = size_struct(backing::length(iterable));
				var* pointer         = allocate<var>(new_size.allocated);
				for (std::size_t index = 1; index < new_size.in_use; ++index)
				{
					pointer[index - 1] = iterable[index];
				}
				return var(pointer, new_size);
			}
			size_struct new_size = size_struct(1, LIBLETLIB_ARRAY_GROWTH);
			var* pointer         = allocate<var>(LIBLETLIB_ARRAY_GROWTH);
			pointer[0]           = iterable;
			return var(pointer, new_size);
		}

		/// \brief Zips 2 to N lists to align their elements in sublists in a list.
		///
		/// zip(list(1, 2, 3), list(4, 5, 6)) -> [[1, 4], [2, 5], [3, 6]]
		///
		/// \param args arguments to this function.
		/// \return list of arguments zipped.
		LIBLETLIB_NODISCARD inline var zip_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			if (backing::length(args) < 1)
				return var();

			size_struct new_size = size_struct(backing::length(args[0]));
			var* pointer         = allocate<var>(new_size.allocated);
			for (std::size_t index = 0; index < new_size.in_use; ++index)
			{
				pointer[index] = backing::list();
	#if (__cplusplus >= 201103L)
				for (var const& element : args)
				{
					pointer[index] += element.behaviour->as_array(element)[index];
				}
	#else
				std::size_t length = backing::length(args);
				for (std::size_t jindex = 0; jindex < length; ++jindex)
				{
					pointer[index] += args[jindex].behaviour->as_array(args[jindex])[index];
				}
	#endif
			}
			return var(pointer, new_size);
		}

		/// \brief Unzips a zipped list into a list of the original lists.
		///
		/// unzip(list(list(1, 4), list(2, 5), list(3, 6)) -> [[1, 2, 3], [4, 5, 6]]
		///
		/// \param args arguments to this function.
		/// \return Unzipped lists.
		LIBLETLIB_NODISCARD inline var unzip_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			var const& unzippable = args[0];

			size_struct new_size = size_struct(backing::length(unzippable[0]));
			var* pointer         = allocate<var>(new_size.allocated);
			std::size_t index    = 0;
			for (; index < new_size.in_use; ++index)
			{
				pointer[index] = backing::list();
			}
	#if (__cplusplus >= 201103L)
			for (var const& element : unzippable)
			{
				index = 0;
				for (var const& subelement : element)
				{
					pointer[index] += subelement;
					++index;
				}
			}
	#else
			std::size_t length = backing::length(unzippable);
			for (std::size_t jindex = 0; jindex < length; ++jindex)
			{
				index = 0;
				std::size_t sub_length = backing::length(unzippable[jindex]);
				for (std::size_t kindex = 0; kindex < sub_length; ++kindex)
				{
					pointer[index] += unzippable[jindex][kindex];
					++index;
				}
			}
	#endif
			return var(pointer, new_size);
		}

		/// \brief Flatten a list to a single dimension.
		///
		/// [1, [2, [3]]] -> [1, 2, 3]
		///
		/// \param args arguments to this function.
		/// \return Flattened list.
		LIBLETLIB_NODISCARD inline var flatten_(var const&, var const& args) LIBLETLIB_NOEXCEPT
		{
			var result = args[0];
		deeply_nested:
			var const deeply_nested = result;
			result                  = backing::list();
			for (var const& element : deeply_nested)
				result = result << element;

			for (var const& element : result)
				if (backing::is_list(element))
					goto deeply_nested;

			return result;
		}

	}// namespace detail
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const zip     = libletlib::detail::zip_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const unzip   = libletlib::detail::unzip_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const foldl   = libletlib::detail::foldl_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const foldr   = libletlib::detail::foldr_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const map     = libletlib::detail::map_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const filter  = libletlib::detail::filter_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const peek    = libletlib::detail::peek_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const head    = libletlib::detail::head_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const tail    = libletlib::detail::tail_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const list    = libletlib::detail::list_;
	LIBLETLIB_MAYBE_UNUSED libletlib::detail::var const flatten = libletlib::detail::flatten_;
}// namespace libletlib

#endif

#endif//LIBLETLIB_LIBLETLIB_LISTS_HPP
