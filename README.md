[![codecov](https://codecov.io/gh/libletlib/libletlib/branch/senpai/graph/badge.svg?token=CRJ2AF03G5)](https://codecov.io/gh/libletlib/libletlib)

[![Clang-Linux](https://github.com/libletlib/libletlib/actions/workflows/clang-linux.yml/badge.svg)](https://github.com/libletlib/libletlib/actions/workflows/clang-linux.yml)
[![Clang-MacOS](https://github.com/libletlib/libletlib/actions/workflows/clang-macos.yml/badge.svg)](https://github.com/libletlib/libletlib/actions/workflows/clang-macos.yml)
[![GCC-Linux](https://github.com/libletlib/libletlib/actions/workflows/gcc-linux.yml/badge.svg)](https://github.com/libletlib/libletlib/actions/workflows/gcc-linux.yml)
[![MSVC-Windows](https://github.com/libletlib/libletlib/actions/workflows/msvc-windows.yml/badge.svg)](https://github.com/libletlib/libletlib/actions/workflows/msvc-windows.yml)

# LibLetLib

Static typing grinding your gears? Want to fail even faster?
```auto``` not automatic enough? LibLetLib is the answer that proudly defies some C++ best practises while upholding
functional programming ones. LibLetLib provides the speed of Smalltalk and the security of C in a single tight package.

LibLetLib is a C++ library/framework/runtime to provide duck typed, functional programming while still being compatible
with all other C++ code. LibLetLib works seamlessly with other C++ code so it can be used only where desired. Supports
all C++ versions from C++98 to C++20 including limited freestanding support. C++11 or later is required for most
advanced features.

# Installation

LibLetLib is header-only. Copy the libletlib folder and  ```#include libletlib/libletlib.hpp``` file.

LibLetLib pollutes the global namespace by default with a few macros.

* ```curry``` (Injects the empty lambda to force unique instantiation of a template)
* ```lambda``` (Lambda capture and conversion to function pointer infrastructure)
* ```subroutine``` (Lambda capture and conversion to function pointer infrastructure)
* ```Subroutine``` (Utility)
* ```function``` (Lambda capture and conversion to function pointer infrastructure)
* ```Function``` (Utility)
* ```type``` (Utility, injects "self" field to every object)
* ```contains``` (Utility in conjuction with ```type```)
* ```member``` (Utility in conjuction with ```type```)
* ```match``` (Utility)
* ```with``` (Utility in conjuction with ```match```)
* ```otherwise``` (Utility in conjuction with ```match```)
* ```st``` (Utility, first argument of function)
* ```nd``` (Utility, second argument of function)
* ```rd``` (Utility, third argument of function)

These can be disabled with defining the macro ```LIBLETLIB_DISABLE_MACRO```, although there are no guarantees that the
underlying definitions of the macros will stay the same between versions.

# Introduction

Library provides the ```var``` class and its const typedef ```let```.
```var``` is designed to be mutable and can be reassigned, but the mutating operators, assignment, decrement and
increment are not const and thus cannot be used on a ```const var``` (or ```let``` for short) object.

LibLetLib allows all C++ fundamental types, lists of ```var```, functions, and even its own object types to be wrapped
by a single object. Functions support variable capture and can be curried. Object types allow operator overloading and
all members use message passing for dynamic dispatch. LibLetLib uses macros to provide a sleek code appearance, but a
more robust (and less macro-y) approach is possible which requires some extra typing.

# Wrapping and unwrapping

```var``` can be assigned single arguments of any of the wrappable types implicitly. In C++11 and later a list can also
created through an initializer list.

```var``` is implicitly coercable to all non-object pointer types it can wrap. ```var``` has implicit conversions
to ```std::string``` and other corresponding string objects for different character arrays. Being implicitly convertable
means that var will usually match multiple types of overloaded functions in which case defining the desired type of var
must be defined either by using the type conversion operator functions or casting (which triggers these functions).

```c++
let a = 1;
let b = 2.0;
let c = "3";
let d = []function(return "2";);
std::cout << std::pow(b.operator double(), d) << std::endl; // 4
```

Functions are automatically called without arguments and their return values converted to the required type. Here
the ```std::pow``` function is using the ```std::pow(double, double)``` variant of the function due to ```b``` being
converted to double. Thus LibLetLib will call d with no arguments, convert the resulting string ```"2"```
to ```double```
and provide it to the ```std::pow```.

# Type priority

From highest to lowest:

1. ```std::nullptr_t``` _(Only C++11 and later)_
2. ```void*``` _(Also holds objects C++11 and later)_
3. ```list``` _(Actual type of ```var*```)_
4. ```function``` _(Actual type of ```var(*)(var const&, var const&)```)_
5. ```subroutine``` _(Actual type of ```void(*)(var const&, var const&)```)_
6. ```char32_t*``` _(Only C++11 and later)_
7. ```char16_t*``` _(Only C++11 and later)_
8. ```char8_t*``` _(Only C++20 and later)_
9. ```wchar_t*```
10. ```char*```
11. ```long double```
12. ```double```
13. ```float```
14. ```unsigned long long``` _(Only C++11 and later)_
15. ```long long``` _(Only C++11 and later)_
16. ```unsigned long```
17. ```long```
18. ```unsigned int```
19. ```int```
20. ```unsigned short```
21. ```short```
22. ```char32_t``` _(Only C++11 and later)_
23. ```char16_t``` _(Only C++11 and later)_
24. ```char8_t``` _(Only C++20 and later)_
25. ```wchar_t```
26. ```unsigned char```
27. ```signed char```
28. ```char```
29. ```bool```

# Functions and Subroutines

LibLetLib functions are divided into two different categories: returning functions and non-returning subroutines.
Functions can be defined as normal functions using the ```Function``` and ```Subroutine``` macros:

```c++
Function(foo) {
    // code
}
```

For C++11 and later, the lambda function macros enable more fluent expressions:

```c++
let foo = [/* capture */]function(/* code */);
let bar = [/* capture */]subroutine(/* code */);
```

and a convenience macro ```lambda``` for simple oneliner functions:

```c++
#define lambda(expression) []function(return expression;) 
```

The actual function signature for LibLetLib functions and subroutines is:

```c++
typedef var (*function) (var const& self, var const& args);
typedef void (*subroutine) (var const& self, var const& args);
```

The ```noexcept``` attribute is defined unless compiling for C++98 which doesn't support ```noexcept``` or using
exceptions as the error handling mechanism (which is the default).

## Arguments

Function and subroutine arguments are the const reference to ```self```, which is the var reference to the function
itself and ```args```, which contains all the actual arguments as a list. This means that all functions and subroutines
can take variable arguments and the arguments are anonymous. Three macros for the first three elements of ```args``` are
provided for quality of life:

```c++
#define st (length(args) > 0 ? args[0] : var()) // 1st
#define nd (length(args) > 1 ? args[1] : var()) // 2nd
#define rd (length(args) > 2 ? args[2] : var()) // 3rd
```

## Currying

LibLetLib functions can be curried with the macro function curry.

```c++
let fun = lambda(st + nd + rd);
let curried = curry(fun, 1, 1);
std::cout << curried(1) << std::endl; // 3
```

The invocation of the curry method requires an unique instantiation of a template function each time, which in turn
involves a macro ```curry``` to provide an empty lambda to the curry method as a dummy. (C++ standard guarantees all
lambdas are unique types and thus lead to unique instantiations of the template function.)

```c++
#define curry(...) libletlib::detail::curry_([](){}, __VA_ARGS__)
```

This is required so that the new curried lambda can remember the now enclosed function pointer as a static variable of
the unique instantiation of ```curry```. This could be made cleaner in C++20 which allows lambdas in unevaluated
contexts, but broad compiler support isn't there yet. Due to this inconvenient required extra parameter to force unique
instantiations the ```libletlib::detail::curry_``` function itself cannot be curried, although every other LibLetLib
utility function can be.

```c++
let SpicyRange = curry(range, 0, 100); // Generates ranges from 0 to 99 with still yet unprovided step.
let FullRange = SpicyRange(1); // 0 - 99, step of 1.
let HalfRange = SpicyRange(2); // 0 - 99, step of 2.
```

# Pattern Matching

Rudimentary pattern matching for comparison between values and array/object layouts.
Comparisons are to be given as predicate functions and results are computed by a
function that is automatically given the arguments of the ```match(...)``` statement
in the order they were given to it.

```c++
let foo = list(1, "2", lambda(3));
let bar = list(1, "3", lambda(2));

let result = match(foo, bar) with // result = [1, "2", function(return 3;)]
    | lambda(st != nd) ->* lambda(st) // This branch will be selected.
    | otherwise ->* lambda(nd);

let oof = 3;
let rab = 2.5;

let result2 = match(oof, rab) with // result2 = 3
	| lambda(st < nd) ->* lambda(nd)
	| otherwise ->* lambda(st); //This branch will be selected, because nd < st.
```

# Classes and Objects

LibLetLib objects have a three level inheritance structure.

```
┌─────────────────────────────┐ // MetaRoot is abstract and eventually all objects are 
│                             │ // cast to MetaRoot when performing operations on them.
│                             │ // 
│           MetaRoot          │ // MetaRoot has only one field: 'inner' which is a var of list type.  
│                             │ // This contains all the members.
└──────────────┬──────────────┘ 
               │                
               │
               │
┌──────────────▼──────────────┐ // Root implements the copy() and clone() methods that allow 
│                             │ // us to create additional instances of Inheritor.
│  template<class Inheritor>  │ //
│  Root : public MetaRoot     │ // This pattern is also known the 
│                             │ // Curiously Recurring Template Pattern (CRTP).
└──────────────┬──────────────┘
               │
               │
               │
┌──────────────▼──────────────┐ // Custom LibLetLib classes only contains the 
│                             │ // user-defined initialization for the MetaRoot 'inner' field that 
│                             │ // provides all the user-defined functionality.
│   Foo : public Root<Foo>    │ 
│                             │ 
└─────────────────────────────┘
```

Classes can be defined using macros or by hand. The declarations for class Foo below are syntactically identical:

```c++
type(Foo)
    contains(
    	    member(msg) = "Hello World!"
    	)

    	
class Foo final : public Root<Foo> {
	Foo() {
		inner = {
			{"name", "Foo"},
			{"msg", "Hello World!"},
		};
	}
};    	
```

## Instantiation

Objects are instantiated through the ```new``` keyword, the var object they are assigned to will manage the memory
according to RAII principles.

```c++
type(Foo)
    contains
    (
        member(func) = lambda(st + nd)
    )
    
int main(void)
{
    let foo = new Foo;
    std::cout << foo.message("func")(2, 2) << std::endl; // 4
    return 0;
}    
```

## Member access

Object members can be accessed through the ```message(char const*)``` method or via the ```[]``` operator. Another way
is to use the ```objectify()``` and then using ```MetaRoot``` method ```message(char const*)```.

```c++
type(Foo)
    contains
    (
        member(msg) = "Hello World!"
    )
    
int main(void) 
{
    let foo = new Foo;
    std::cout << foo.message("msg") << std::endl; // Returns msg by reference.
    std::cout << foo.objectify()->message("msg") << std::endl; // Returns msg by reference.
    
    std::cout << foo["msg"] << std::endl; // Returns msg by value.
}    
```

## Operator overloading

Objects can define members with special names that will be used when the object is a part of a operator sequence. The
operator overload of the left side of binary operators involving multiple objects is always used.

```c++
type(Foo)
    contains(
    	    member(+) = lambda(st.message(name) + nd.message(name))
    	)
    	
int main(void) {
	let x = new Foo;
	let y = new Foo;
	std::cout << x + y << std::endl; // "FooFoo"
	return 0;
}
```

### Operator overloading member names

* ```foo@bar``` only the operator e.g. "+".
* ```@foo``` operator postfixed by "self", e.g. "+self"
* ```foo()``` ()
* ```foo[]``` []
* ```++foo, foo++``` ++ (postfix returns value before increment.)
* ```--foo, foo--``` -- (postfix returns value before decrement.)

# Error Handling

LibLetLib supports four models of error handling.

1. Exceptions via ```var```. _Enabled by default and the only one supported for freestanding._
2. Jump to handler via ```longjmp()```.
3. Error number style a la ```<cerrno>```.
4. No error handling.

These are enabled by their respective macros:

1. ```LIBLETLIB_ERROR_EXCEPTION```
2. ```LIBLETLIB_ERROR_LONGJMP```
3. ```LIBLETLIB_ERROR_ERRNO```
4. ```LIBLETLIB_ERROR_NONE```

all of which undefine the other options when defined.

### Exceptions

Exceptions thrown:

* ```std::domain_error``` _Divide by zero, other logical errors, and forbidden casts._
* ```std::range_error``` _Out of bounds access._
* ```std::runtime_error``` _Indicates possible future support, but no functionality implemented._

Exceptions contain an error message describing the error.

### Longjmp

Longjmp must be initialised before using LibLetLib with the ```LIBLETLIB_INIT(callback)``` macro where
```callback``` must be a LibLetLib subroutine or ```var()```. The subroutine will be provided with an error number out
of:

* ```LIBLETLIB_EDOM``` (Domain Error) _Divide by zero, other logical errors, and forbidden casts._
* ```LIBLETLIB_ERANGE``` (Erraneous Range) _Out of bounds access._
* ```LIBLETLIB_ENOTSUP``` (Not Supported, indicates possible future support.)

which assume any predefined value for ```<cerrno>``` macros ```EDOM```, ```ERANGE```, and ```ENOTSUP```, but define
their own if they are undefined. The default handler attempts to print the error into ```stderr``` and then attempts a
graceful ```std::exit()``` with exit code corresponding to the error code.

### Error Numbers

The ```errno``` macro defined by ```<cerrno>``` will be set to one of the corresponding values defined in
```<cerrno>```:

* ```EDOM``` _Divide by zero, other logical errors, and forbidden casts._
* ```ERANGE``` _Out of bounds access._
* ```ENOTSUP``` _(C++11 or later, indicates possible future support.)_

The LibLetLib error code macros also resolve to the corresponding ```<cerrno>``` macro while
```LIBLETLIB_ERROR_ERRNO``` is enabled.

### No Error Handling

LibLetLib silently ignores errors.

# Freestanding

LibLetLib supports freestanding compilation with the following restrictions:

* No lists, functions, subroutines, strings of any type, or objects. (No heap allocation.)
* No ```wchar_t```, ```char8_t```, ```char16_t```, ```char32_t``` support. (No ```<cwchar>``` and ```<cuchar>```
  available.)
* Uses some self-implemented platform agnostic maths functions. (No ```<cmath>``` available.)

Which basically leaves all numeric types, standard```char``` character types, and ```bool``` for use.

# C++98

LibLetLib supports C++98, but the lack of variadic templates and lambda functions limits the functionality:

* ```list()``` and function calls i.e. ```operator()``` have a 10 argument maximum. (Lists can still be grown
  arbitrarily programmatically.)
* No lambda functions, but regular function pointers can still be assigned to ```var``` and used normally.
* No currying, i.e. ```curry``` (Implementation requires lambda functions.)
* No pattern matching, i.e. ```match```,```with```,```otherwise```. (Implementation requires variadic templates.)
* No objects, i.e. ```type```. (Implementation requires variadic templates.)

# More examples

## Recurse you a factorial

```c++
#include "libletlib/libletlib.hpp"

using namespace libletlib;

let factorial = []function(
	    if(st <= 1)
	    	return 1;
	    return st * self(st - 1); // Because functions are anonymous
	);                            // they can call themselves with 'self'
	

int main(void) {
	std::cout << factorial(5) << std::endl;
}
```

## (Im)mutability

```c++
#include "libletlib.hpp"
#include <cstdlib>
#include <iostream>

using namespace libletlib;

int main(void) {
    let x = 1;
    let y = 2;
    std::cout << x+y << std::endl; // 1 + 2 = 3, then output to std::cout.
    x += y; // Error, no += defined for let (const var).
    x = 2; // Error, no = defined for let (const var).
    var z = 2;
    z += y; // 2 + 2 = 4
    std::cout << z << std::endl; // Prints "4".
    return EXIT_SUCCESS;
}
```

## A scenic route to say Hello World!

```c++
#include "libletlib/libletlib.hpp"
#include <cstdlib>
#include <iostream>

using namespace libletlib;

// A LibLetLib class with name of Foo.
type(Foo) contains(
	// Contains member + that overloads binary + operator for this class.
	// In LibLetLib all function arguments are provided in an array called args.
	// For convenience the first three arguments can be accessed through the macros 
	// st, nd, and rd (1st, 2nd, 3rd argument respectively).
	// the q operator queries an object for a member of given name.
	member(+) = lambda(st.message(msg) + " " + nd.message(msg);)
	
	// Member by the name of "message" and value of "Hello" on initialization of this class.	
	member(msg) = "Hello"	
	)

// PrintFirst is a subroutine (non-returning function) that simply prints the first argument given.	
let PrintFirst = []subroutine(std::cout << st << std::endl;);

int main(void) {
    // Create a pair of Foo instances.
    let foo1 = new Foo;
    let foo2 = new Foo;
    
    // Lets tweak the message on the second one to create our Hello World! message with the + operator.
    foo2.message("msg") = "World!";
    
    // Print our Hello World! (args is an array and thus surrounded by brackets.)
    PrintFirst(foo1 + foo2); // [Hello World!]
    
    return EXIT_SUCCESS;
}
```