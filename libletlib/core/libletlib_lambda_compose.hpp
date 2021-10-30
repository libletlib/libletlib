//
// Created by tietun on 30/10/2021.
//

#ifndef LIBLETLIB_LIBLETLIB_LAMBDA_COMPOSE_HPP
#define LIBLETLIB_LIBLETLIB_LAMBDA_COMPOSE_HPP

namespace libletlib
{
	namespace detail
	{
	#if (__cplusplus >= 201103L)
		/// \brief Composes N amount of functions right-to-left.
		/// \tparam UniqueDummy unique type to trigger arbitrary amount of template instantiations.
		/// \tparam Arguments functions to compose.
		/// \param _arguments functions to compose.
		/// \return var containing the composed function.
		template<typename UniqueDummy, typename... Arguments>
		LIBLETLIB_NODISCARD inline var compose_(LIBLETLIB_MAYBE_UNUSED UniqueDummy&&, Arguments const&... _arguments) noexcept
		{
			var const composables = backing::list(_arguments...);

			if(sizeof...(_arguments) < 2)
				return composables[0];

			static function_t composing[sizeof...(_arguments)];

			for (std::size_t index = 0; index < sizeof...(_arguments); ++index)
				composing[index] = composables.value.array_type[index].value.function_type;

			var composed = var(capture([](LIBLETLIB_MAYBE_UNUSED var const& self, var const& args) LIBLETLIB_NOEXCEPT -> var {
				function_t const* composing_end = composing + sizeof...(_arguments) - 1;
				var result = (*composing_end)((*composing_end), args);
				--composing_end;
				for(;composing_end >= composing; --composing_end)
					result = (*composing_end)((*composing_end), backing::list(result));
				return result;
			}));

			return composed;
		}
	#endif

	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_LAMBDA_COMPOSE_HPP
