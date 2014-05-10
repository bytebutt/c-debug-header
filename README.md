## About

The `debug.h` header file can be included into a C source file to enable
several different debugging macros. Support for all versions of C greater than
or equal to C89 is provided with slightly different syntax.

## Usage

There are five different macros included in the header:

* `debug()` is used for general purpose debugging statements
* `debug_w()` is used for warning messages
* `debug_e()` is used for error messages
* `debug_wtf()` is used for things that should never ever happen
* `assert()` is used to check the truth of some boolean expression

### C89 or Later

Add the `-DDEBUG89` flag to your compilation command to enable the
C89-compatible debug statements.

```
gcc -DDEBUG89 program.c -o program
```

Due to the lack of `__VA_ARGS__` in C89, the macro function calls must be
wrapped in two sets of parentheses to cope with a variable number of
parameters. The exception to this rule is the `assert()` macro, which only
uses a single set of parentheses.

```c
debug(("A debug message!"));
debug_w(("Parameter x has negative value: %d", x));

assert(x != 3);
```

### C99 or Later

Add the `-DDEBUG` flag to your compilation command to enable the regular
debug statements.

```
gcc -DDEBUG program.c -o program
```

All of the macros use only a single set of parenthesis using this option.

```c
debug("A debug message!");
debug_w("Parameter x has negative value: %d", x);

assert(x != 3);
```

### ANSI Colors

ANSI color escape sequences can be enabled to make the output of the debugging
statements more visible. Simply add the `-DDEBUG_COLOR` flag to your
compilation command along with one of the above options. Windows users should
note that this option will not work correctly in the command prompt without
the aid of additional software.

## (Un)license

This header file is released under
[The Unlicense](https://raw.githubusercontent.com/msrichar/c-debug-header/master/UNLICENSE),
a fancy way of saying this code is hereby released into the Public Domain.
