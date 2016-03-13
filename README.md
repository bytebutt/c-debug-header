## About

The repo contains header files that can be included into a C source file
to enable several different debugging macros. There is a header file for both
C89 [`debug89.h`](debug89.h) and C99+ [`debug.h`](debug.h). Both of these
header files include the same macros, but require slightly different usage.


## Macros

There are five different macros defined in the header:

* `debug()` is used for general purpose debugging statements.
* `debug_w()` is used for warning messages.
* `debug_e()` is used for error messages.
* `debug_wtf()` is used for things that should never ever happen. (What a Terrible Failure!)
* `assert()` is used to check the truth of some boolean expression.

All of the debug statements support printf-style format strings (excluding `assert()`).
Additionally, a newline is automatically written after each message, so you
don't need to add `\n` to the end of your debug statements.

By default, these macros produce no output. Output must be explicitly enabled by
including the `-DDEBUG` flag during compilation.

```
gcc -DDEBUG foobar.c -o foobar
```

### Usage: C89 / ANSI C

Include the [`debug89.h`](debug89.h) header in your code.
Due to the lack of `__VA_ARGS__` in C89, the macro calls must be
wrapped in two sets of parentheses to cope with a variable number of
parameters. The exception to this rule is the `assert()` macro, which only
uses a single set of parentheses.

```c
/* Two sets of parentheses. */
debug(("A debug message!"));
debug_w(("Parameter x has a negative value: %d", x));

/* Single set of parentheses. */
assert(x != 3);
```

See [`demo89.c`](demo89.c) for example usage.

### Usage: C99 or Later

Include the [`debug.h`](debug.h) header in your code.
Use all of the macros with a single set of parentheses.

```c
/* Single set of parentheses. */
debug("A debug message!");
debug_w("Parameter x has negative value: %d", x);

/* Single set of parentheses. */
assert(x != 3);
```

See [`demo.c`](demo.c) for example usage.

### ANSI Colors

ANSI color escape sequences can be enabled to make the output of the debugging
statements more visible. Simply add the `-DDEBUG_COLOR` flag to your
compilation command along with `-DDEBUG`. This option will only work correctly
if your terminal supports ANSI escape sequences (i.e. not `cmd.exe` on Windows).

## Example Output

Here's an example of colorized output from the demo program.

![Demo Output](demo.png "Demo Output")

## (Un)license

This project is released into the public domain under the terms of
[The Unlicense](UNLICENSE).
