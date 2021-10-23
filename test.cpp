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

#include "libletlib/libletlib.hpp"
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace libletlib;

template<typename Value>
inline void TestCasting(Value value)
{
	var v = value;

	assert(v.operator bool() == true);

	assert(v.operator char() == '\1');
	assert(v.operator signed char() == '\1');
	assert(v.operator unsigned char() == '\1');
	assert(v.operator wchar_t() == L'\1');
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		//assert(v.operator char8_t() == u8'\1'); // Type conversion functions still unsupported.
	#endif
	#if (__cplusplus >= 201103L)
	assert(v.operator char16_t() == u'\1');
	assert(v.operator char32_t() == U'\1');
	#endif
#endif

	assert(v.operator short() == 1);
	assert(v.operator unsigned short() == 1);
	assert(v.operator int() == 1);
	assert(v.operator unsigned int() == 1u);
	assert(v.operator long() == 1l);
	assert(v.operator unsigned long() == 1ul);
	assert(v.operator long long() == 1ll);
	assert(v.operator unsigned long long() == 1ull);
	assert(v.operator float() == 1.0f);
	assert(v.operator double() == 1.0);
	assert(v.operator long double() == 1.0l);

	assert(v == "1");
	assert(v == L"1");
#if (__cplusplus >= 202002L)
	//assert(v == u8"1"); // Type conversion functions still unsupported.
#endif
#if (__cplusplus >= 201103L)
	assert(v == u"1");
	assert(v == U"1");
	assert(v.operator std::nullptr_t() == nullptr);
#endif
	assert(*reinterpret_cast<Value*>(v.operator void*()) == 1);
	assert(v.to_list() == list(1));
}

template<>
inline void TestCasting<bool>(bool value)
{
	var v = value;

	assert(v.operator bool() == true);

	assert(v.operator char() == '1');
	assert(v.operator signed char() == '1');
	assert(v.operator unsigned char() == '1');
	assert(v.operator wchar_t() == L'1');
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		//assert(v.operator char8_t() == u8'1'); // Type conversion functions still unsupported.
	#endif
	#if (__cplusplus >= 201103L)
	assert(v.operator char16_t() == u'1');
	assert(v.operator char32_t() == U'1');
	#endif
#endif
	assert(v.operator short() == 1);
	assert(v.operator unsigned short() == 1);
	assert(v.operator int() == 1);
	assert(v.operator unsigned int() == 1u);
	assert(v.operator long() == 1l);
	assert(v.operator unsigned long() == 1ul);
#if (__cplusplus >= 201103L)
	assert(v.operator long long() == 1ll);
	assert(v.operator unsigned long long() == 1ull);
#endif
	assert(v.operator float() == 1.0f);
	assert(v.operator double() == 1.0);
	assert(v.operator long double() == 1.0l);

	assert(v == "true");
	assert(v == L"true");
#if (__cplusplus >= 202002L)
	//assert(v == u8"true"); // Type conversion functions still unsupported.
#endif
#if (__cplusplus >= 201103L)
	assert(v == u"true");
	assert(v == U"true");
	assert(v.operator std::nullptr_t() == nullptr);
#endif
	assert(*reinterpret_cast<bool*>(v.operator void*()) == true);
	assert(v.to_list() == list(true));
}

template<typename Value>
inline void TestFloatingCasting(Value value)
{
	var v = value;

	assert(v.operator bool() == true);

	assert(v.operator char() == '\1');
	assert(v.operator signed char() == '\1');
	assert(v.operator unsigned char() == '\1');
	assert(v.operator wchar_t() == L'\1');
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		//assert(v.operator char8_t() == u8'\1'); // Type conversion functions still unsupported.
	#endif
	#if (__cplusplus >= 201103L)
	assert(v.operator char16_t() == u'\1');
	assert(v.operator char32_t() == U'\1');
	#endif
#endif
	assert(v.operator short() == 1);
	assert(v.operator unsigned short() == 1);
	assert(v.operator int() == 1);
	assert(v.operator unsigned int() == 1u);
	assert(v.operator long() == 1l);
	assert(v.operator unsigned long() == 1ul);
#if (__cplusplus >= 201103L)
	assert(v.operator long long() == 1ll);
	assert(v.operator unsigned long long() == 1ull);
#endif
	assert(v.operator float() == 1.0f);
	assert(v.operator double() == 1.0);
	assert(v.operator long double() == 1.0l);

	assert(v == "1.000000");
	assert(v == L"1.000000");
#if (__cplusplus >= 202002L)
	//assert(v == u8"1.000000"); // Type conversion functions still unsupported.
#endif
#if (__cplusplus >= 201103L)
	assert(v == u"1.000000");
	assert(v == U"1.000000");
	assert(v.operator std::nullptr_t() == nullptr);
#endif
	assert(libletlib::detail::float_equals(*reinterpret_cast<Value*>(v.operator void*()), static_cast<Value>(1.0)));
	assert(v.to_list() == list(1.0));
}

template<typename Value>
inline void TestStringCasting(Value value)
{
	var v = value;

	assert(v.operator bool() == true);

	assert(v.operator char() == '1');
	assert(v.operator signed char() == '1');
	assert(v.operator unsigned char() == '1');
	assert(v.operator wchar_t() == L'1');
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		//assert(v.operator char8_t() == u8'1'); // Type conversion functions still unsupported.
	#endif
	#if (__cplusplus >= 201103L)
	assert(v.operator char16_t() == u'1');
	assert(v.operator char32_t() == U'1');
	#endif
#endif
	assert(v.operator short() == 1);
	assert(v.operator unsigned short() == 1);
	assert(v.operator int() == 1);
	assert(v.operator unsigned int() == 1u);
	assert(v.operator long() == 1l);
	assert(v.operator unsigned long() == 1ul);
#if (__cplusplus >= 201103L)
	assert(v.operator long long() == 1ll);
	assert(v.operator unsigned long long() == 1ull);
#endif
	assert(v.operator float() == 1.0f);
	assert(v.operator double() == 1.0);
	assert(v.operator long double() == 1.0l);

	assert(v == "1");
	assert(v == L"1");
#if (__cplusplus >= 202002L)
	//assert(v == u8"1"); // Type conversion functions still unsupported.
#endif
#if (__cplusplus >= 201103L)
	#ifndef LIBLETLIB_DISABLE_UCHAR
	assert(v == u"1");
	assert(v == U"1");
	#endif
	assert(v.operator std::nullptr_t() == nullptr);
#endif
	assert(var(*reinterpret_cast<Value*>(v.operator void*())) == "1");
	assert(v.to_list() == list('1'));
}

template<typename Value>
inline void TestCharacterCasting(Value value)
{
	var v = value;

	assert(v.operator bool() == true);

	assert(v.operator char() == '1');
	assert(v.operator signed char() == '1');
	assert(v.operator unsigned char() == '1');
	assert(v.operator wchar_t() == L'1');
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		//assert(v.operator char8_t() == u8'1'); // Type conversion functions still unsupported.
	#endif
	#if (__cplusplus >= 201103L)
	assert(v.operator char16_t() == u'1');
	assert(v.operator char32_t() == U'1');
	#endif
#endif
	assert(v.operator short() - '0' == 1);
	assert(v.operator unsigned short() - '0' == 1);
	assert(v.operator int() - '0' == 1);
	assert(v.operator unsigned int() - '0' == 1u);
	assert(v.operator long() - '0' == 1l);
	assert(v.operator unsigned long() - '0' == 1ul);
#if (__cplusplus >= 201103L)
	assert(v.operator long long() - '0' == 1ll);
	assert(v.operator unsigned long long() - '0' == 1ull);
#endif
	assert(v.operator float() - '0' == 1.0f);
	assert(v.operator double() - '0' == 1.0);
	assert(v.operator long double() - '0' == 1.0l);

	assert(v == "1");
	assert(v == L"1");
#if (__cplusplus >= 202002L)
	//assert(v == u8"1"); // Type conversion functions still unsupported.
#endif
#if (__cplusplus >= 201103L)
	#ifndef LIBLETLIB_DISABLE_UCHAR
	assert(v == u"1");
	assert(v == U"1");
	#endif
	assert(v.operator std::nullptr_t() == nullptr);
#endif
	assert(*reinterpret_cast<Value*>(v.operator void*()) == '1');
	assert(v.to_list() == list('1'));
}

template<typename Left, typename Right>
inline void TestOperation(Left left, Right right)
{
	var l = left;
	var r = right;

	assert(l + r == 4);
	assert(l - r == 0);
	assert(l * r == 4);
	assert(l / r == 1);
	assert((l ^ r) == 4);
	assert(l.bit_xor(r) == 2 ^ 2);
	assert(l % r == 0);
	assert((l & r) == 2);
	assert((l | r) == 2);
	assert((l ^ 7)[1] == '2');
	assert(~l == (~(2)));
	assert(-l == -2);
	assert(+l == 2);
	assert(!l == false);
	assert(*l == 2);
	assert(l++ == 2);
	assert(--l == 2);
	assert(l-- == 2);
	assert(++l == 2);
	assert(l == r);
}

template<>
inline void TestOperation<bool, bool>(bool left, bool right)
{
	var l = left;
	var r = right;

	assert(l + r == true);
	assert(l - r == false);
	assert(l * r == true);
	assert(l / r == true);
	assert((l ^ r) == true);
	assert(l.bit_xor(r) == false);
	assert(l % r == false);
	assert((l & r) == true);
	assert((l | r) == true);
	assert((l)[0] == true);
	assert(~l == false);
	assert(-l == false);
	assert(+l == true);
	assert(!l == false);
	assert(*l == true);
	assert(l++ == true);
	assert(--l == false);
	assert(l-- == false);
	assert(++l == true);
	assert(l == r);
}

template<typename Left, typename Right>
inline void TestCharacterOperation(Left left, Right right)
{
	var l = left;
	var r = right;

	assert(l + r == "22");
	assert(l - r == "");
	assert(l % r == 0);
	assert((l & r) == '2');
	assert((l | r) == var());
	assert(l.bit_xor(r) == '2' ^ '2');
	assert(l[-1] == '2');
	assert(~l == ~'2');
	assert(-l == -'2');
	assert(+l == '2');
	assert(!l == false);
	assert(*l == '2');
	assert(l++ == '2');
	assert(--l == '2');
	assert(l-- == '2');
	assert(++l == '2');
	assert(l == r);
}

template<typename Left, typename Right>
inline void TestStringOperation(Left left, Right right)
{
	var l = left;
	var r = right;

	assert(l + r == "22");
	assert(l - r == "");
	assert((l & r) == "2");
	assert((l | r) == "");
	assert(l[-1] == '2');
	assert(l == r);
}

template<>
inline void TestCasting<float>(float value)
{
	TestFloatingCasting(value);
}

template<>
inline void TestCasting<double>(double value)
{
	TestFloatingCasting(value);
}

template<>
inline void TestCasting<long double>(long double value)
{
	TestFloatingCasting(value);
}

template<>
inline void TestCasting<char const*>(char const* value)
{
	TestStringCasting(value);
}

template<>
inline void TestCasting<wchar_t const*>(wchar_t const* value)
{
	TestStringCasting(value);
}

#if (__cplusplus >= 202002L)
template<>
inline void TestCasting<char8_t const*>(char8_t const* value)
{
	TestStringCasting(value);
}
#endif
#if (__cplusplus >= 201103L)
template<>
inline void TestCasting<char16_t const*>(char16_t const* value)
{
	TestStringCasting(value);
}

template<>
inline void TestCasting<char32_t const*>(char32_t const* value)
{
	TestStringCasting(value);
}
#endif

template<>
inline void TestCasting<char>(char value)
{
	TestCharacterCasting(value);
}

template<>
inline void TestCasting<unsigned char>(unsigned char value)
{
	TestCharacterCasting(value);
}

template<>
inline void TestCasting<signed char>(signed char value)
{
	TestCharacterCasting(value);
}

template<>
inline void TestCasting<wchar_t>(wchar_t value)
{
	TestCharacterCasting(value);
}

#if (__cplusplus >= 202002L)
template<>
inline void TestCasting<char8_t>(char8_t value)
{
	TestCharacterCasting(value);
}
#endif
#if (__cplusplus >= 201103L)
template<>
inline void TestCasting<char16_t>(char16_t value)
{
	TestCharacterCasting(value);
}

template<>
inline void TestCasting<char32_t>(char32_t value)
{
	TestCharacterCasting(value);
}
#endif

template<>
inline void TestOperation<char, char>(char left, char right)
{
	TestCharacterOperation(left, right);
}

template<>
inline void TestOperation<unsigned char, unsigned char>(unsigned char left, unsigned char right)
{
	TestCharacterOperation(left, right);
}

template<>
inline void TestOperation<signed char, signed char>(signed char left, signed char right)
{
	TestCharacterOperation(left, right);
}

template<>
inline void TestOperation<wchar_t, wchar_t>(wchar_t left, wchar_t right)
{
	TestCharacterOperation(left, right);
}

#if (__cplusplus >= 202002L)
template<>
inline void TestOperation<char8_t, char8_t>(char8_t left, char8_t right)
{
	TestCharacterOperation(left, right);
}
#endif
#if (__cplusplus >= 201103L)
template<>
inline void TestOperation<char16_t, char16_t>(char16_t left, char16_t right)
{
	TestCharacterOperation(left, right);
}

template<>
inline void TestOperation<char32_t, char32_t>(char32_t left, char32_t right)
{
	TestCharacterOperation(left, right);
}
#endif

template<>
inline void TestOperation<char const*, char const*>(char const* left, char const* right)
{
	TestStringOperation(left, right);
}

template<>
inline void TestOperation<wchar_t const*, wchar_t const*>(wchar_t const* left, wchar_t const* right)
{
	TestStringOperation(left, right);
}

#if (__cplusplus >= 202002L)
template<>
inline void TestOperation<char8_t const*, char8_t const*>(char8_t const* left, char8_t const* right)
{
	TestStringOperation(left, right);
}
#endif
#if (__cplusplus >= 201103L)
template<>
inline void TestOperation<char16_t const*, char16_t const*>(char16_t const* left, char16_t const* right)
{
	TestStringOperation(left, right);
}

template<>
inline void TestOperation<char32_t const*, char32_t const*>(char32_t const* left, char32_t const* right)
{
	TestStringOperation(left, right);
}
#endif

type(Foo) contains(
    member(msg) = list("Hello", "World", '!')
    member(println) = []subroutine(std::cout << st + " " + nd + rd << std::endl;)
)

type(Bar) contains(
    member(foo) = "Foo"
	member(bar) = [&]function(return this->self()->message("name");)
)

let print = []subroutine(
	for(let& arg : args) {
		std::cout << arg;
    }
);

let println = []subroutine(
    for(let& arg : args) {
	    std::cout << arg;
    }
    std::cout << std::endl;
);

int main()
{
	TestOperation<bool, bool>(true, true);
	TestOperation<char, char>('2', '2');
	TestOperation<signed char, signed char>('2', '2');
	TestOperation<unsigned char, unsigned char>('2', '2');
	TestOperation<wchar_t, wchar_t>(L'2', L'2');
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		//TestOperation<char8_t, char8_t>(u8'2', u8'2'); // Type conversion functions still unsupported.
	#endif
	#if (__cplusplus >= 201103L)
	TestOperation<char16_t, char16_t>(u'2', u'2');
	TestOperation<char32_t, char32_t>(U'2', U'2');
	#endif
#endif
	TestOperation<short, short>(2, 2);
	TestOperation<unsigned short, unsigned short>(2, 2);
	TestOperation<int, int>(2, 2);
	TestOperation<unsigned, unsigned>(2u, 2u);
	TestOperation<long, long>(2l, 2l);
	TestOperation<unsigned long, unsigned long>(2ul, 2ul);
#if (__cplusplus >= 201103L)
	TestOperation<long long, long long>(2ll, 2ll);
	TestOperation<unsigned long long, unsigned long long>(2ull, 2ull);
#endif
	TestOperation<float, float>(2.0f, 2.0f);
	TestOperation<double, double>(2.0, 2.0);
	TestOperation<long double, long double>(2.0l, 2.0l);

	TestOperation<char const*, char const*>("2", "2");
	TestOperation<wchar_t const*, wchar_t const*>(L"2", L"2");
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		//TestOperation<char8_t const*, char8_t const*>(u8"2", u8"2"); // Type conversion functions still unsupported.
	#endif
	#if (__cplusplus >= 201103L)
	TestOperation<char16_t const*, char16_t const*>(u"2", u"2");
	TestOperation<char32_t const*, char32_t const*>(U"2", U"2");
	#endif
#endif

	TestCasting<bool>(true);
	TestCasting<char>('1');
	TestCasting<signed char>('1');
	TestCasting<unsigned char>('1');
	TestCasting<wchar_t>(L'1');
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		//TestCasting<char8_t, char8_t>(u8'2'); // Type conversion functions still unsupported.
	#endif
	#if (__cplusplus >= 201103L)
	TestCasting<char16_t>(u'1');
	TestCasting<char32_t>(U'1');
	#endif
#endif
	TestCasting<short>(1);
	TestCasting<unsigned short>(1);
	TestCasting<int>(1);
	TestCasting<unsigned>(1u);
	TestCasting<long>(1l);
	TestCasting<unsigned long>(1ul);
#if (__cplusplus >= 201103L)
	TestCasting<long long>(1ll);
	TestCasting<unsigned long long>(1ull);
#endif
	TestCasting<float>(1.0f);
	TestCasting<double>(1.0);
	TestCasting<long double>(1.0l);

	TestCasting<char const*>("1");
	TestCasting<wchar_t const*>(L"1");
#ifndef LIBLETLIB_DISABLE_UCHAR
	#if (__cplusplus >= 202002L)
		//TestCasting<char8_t const*>(u8"2", u8"2"); // Type conversion functions still unsupported.
	#endif
	#if (__cplusplus >= 201103L)
	TestCasting<char16_t const*>(u"1");
	TestCasting<char32_t const*>(U"1");
	#endif
#endif

#ifdef LIBLETLIB_HOSTED
	var foo = new Foo;
	foo.message("println").apply<3>(foo.message("msg"));
	var spicyRange = curry(range, 1, 10);
	println(spicyRange(2));
	let list0 = list(1, 2, 3);
	let list1 = list(3, 2, 1, 4);

	let match_test = match(list0, list1) with
	                 | lambda(st != nd) ->* lambda(st)
	                 | otherwise ->* lambda(nd);

	std::cout << "Pattern: " << match_test << std::endl;

	std::cout << filter(lambda(st > 10), foldr(lambda(st + nd), spicyRange(1))) << std::endl;

	let iter = {1, 2, 3};
	let map2 = foldl(lambda(nd += (st + 1)), iter, list());
	std::cout << map2 << std::endl;

	let list_sum    = iter + iter;
	let list_append = iter << iter;
	std::cout << list_sum << std::endl;
	std::cout << list_append << std::endl;

	let iterable = {1, 2, 3};
	let zipped   = zip(iterable, iterable, iterable);
	std::cout << zipped << std::endl;
	let unzipped = unzip(zipped);
	std::cout << unzipped << std::endl;

	var x = 1;
	std::cout << x.message("value") << std::endl;

	var nested = {1, {"2", {3.0, lambda('4')}}};
	std::cout << flatten(nested) << std::endl << foo << std::endl;

	let str = "0123456789";
	let arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << str.slice(-1, 2) << std::endl; // "901"
	std::cout << arr.slice(8, 11) << std::endl; // [8, 9, 9]

	let bar = new Bar;
	println(bar["bar"]());

	let nil = list();
#ifdef LIBLETLIB_ERROR_EXCEPTION
	try {
		println(nil[1]);
	} catch(std::domain_error const&) {
	}
#endif

	let ptrn1 = list(1, 2, 3, 4, 5, 6);
	let ptrn2 = list(list(1, 2, 3), list(1, 2, 3));
	let ptrn3 = list(list(1, 2), list(1, 2, 3));
	let ptrn4 = list(list(1), 1l, 1ul, 1ll, 1ull, 1.0f, 1.0, 1.0L);

	let rslt1 = match(ptrn1) with
	           | "#[(i)]" ->* var(1)
	           | otherwise ->* 0;

	let rslt2 = match(ptrn2) with
	            | "#[(#[iii])]" ->* var(1)
	            | otherwise ->* 0;

	let rslt3 = match(ptrn3) with
	            | "#[(#[(i)])]" ->* var(1)
	            | otherwise ->* 0;

	let rslt4 = match(ptrn4) with
	            | "#[(DfdQqIlL#[i])]" ->* var(1)
	            | otherwise ->* 0;

	std::cout << (rslt1 == 1 ? "YEY" : "NAY") << std::endl;
	std::cout << (rslt2 == 1 ? "YEY" : "NAY") << std::endl;
	std::cout << (rslt3 == 1 ? "YEY" : "NAY") << std::endl;
	std::cout << (rslt4 == 1 ? "YEY" : "NAY") << std::endl;
#endif

	return EXIT_SUCCESS;
}
