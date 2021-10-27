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
#ifndef LIBLETLIB_LIBLETLIB_ERROR_HPP
#define LIBLETLIB_LIBLETLIB_ERROR_HPP

namespace libletlib
{
	namespace detail
	{
#ifdef LIBLETLIB_ERROR_LONGJMP
		std::jmp_buf LIBLETLIB_JMP_BUF;

	#if (__cplusplus >= 201103L)
		[[noreturn]]
	#endif
		void
		default_callback(var const&, var const&) noexcept;

		inline void init(subroutine_t callback = default_callback) noexcept;
#endif

		enum
#if (__cplusplus >= 201103L)
		    class
#endif
		    error_enumeration
		{
#ifdef ENOTSUP
			not_supported = ENOTSUP,
#else
			not_supported    = 501,
#endif
#ifdef EDOM
			erroneous_domain = EDOM,
#else
			erroneous_domain = 418,
#endif
#ifdef ERANGE
			out_of_range = ERANGE,
#else
			out_of_range     = 416,
#endif
		};

#ifdef LIBLETLIB_ERROR_LONGJMP
	/// \brief Default callback function for std::longjmp errors.
	///
	/// \param argc amount of arguments per libletlib function standards.
	/// \param argv arguments
	/// \return this function is noreturn.
	#if (__cplusplus >= 201103L)
		[[noreturn]]
	#endif
		void
		default_callback(var const& argc, var const& argv) noexcept
		{
			switch (argv[0].operator int())
			{
				case 0:
					break;
				case static_cast<int>(LIBLETLIB_EDOM):
					std::cerr << "Exiting!" << std::endl;
					std::exit(static_cast<int>(LIBLETLIB_EDOM));
				case static_cast<int>(LIBLETLIB_ERANGE):
					std::cerr << "Exiting!" << std::endl;
					std::exit(static_cast<int>(LIBLETLIB_ERANGE));
				case static_cast<int>(LIBLETLIB_ENOTSUP):
					std::cout << "This feature might just be unimplemented." << std::endl;
					std::cerr << "Exiting!" << std::endl;
					std::exit(static_cast<int>(LIBLETLIB_ENOTSUP));
			}
			std::cerr << "Exiting for unknown reason!" << std::endl;
			std::exit(EXIT_FAILURE);
		}


	#define LIBLETLIB_INIT(callback)                                                                                   \
		var LIBLETLIB_LONGJMP_CALLBACK;                                                                                \
		if (callback == var())                                                                                         \
			LIBLETLIB_LONGJMP_CALLBACK = libletlib::detail::default_callback;                                          \
		else                                                                                                           \
			LIBLETLIB_LONGJMP_CALLBACK = callback;                                                                     \
		switch (setjmp(libletlib::detail::LIBLETLIB_JMP_BUF))                                                          \
		{                                                                                                              \
			case 0:                                                                                                    \
				break;                                                                                                 \
			case LIBLETLIB_EDOM:                                                                                       \
				LIBLETLIB_LONGJMP_CALLBACK(LIBLETLIB_EDOM);                                                            \
			case LIBLETLIB_ERANGE:                                                                                     \
				LIBLETLIB_LONGJMP_CALLBACK(LIBLETLIB_ERANGE);                                                          \
			case LIBLETLIB_ENOTSUP:                                                                                    \
				LIBLETLIB_LONGJMP_CALLBACK(LIBLETLIB_ENOTSUP);                                                         \
			default:                                                                                                   \
				LIBLETLIB_LONGJMP_CALLBACK(LIBLETLIB_EDOM);                                                            \
		}
#else
	#define LIBLETLIB_INIT(dummy)
#endif
	}// namespace detail
}// namespace libletlib

#endif//LIBLETLIB_LIBLETLIB_ERROR_HPP
