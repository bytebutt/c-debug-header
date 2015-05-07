#include <stdio.h>
#include <stdlib.h>

#include "debug.h"

void add_numbers(const int, const int);
void subtract_numbers(const int, const int);
void multiply_numbers(const int, const int);
void divide_numbers(const int, const int);
void print_usage(const char *);

int
main(int argc, char ** argv)
{
    debug(("Checking for correct number of parameters."));

    if (argc < 3) {
        debug_e(("Incorrect parameter count."));
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    } else if (argc > 3) {
        debug_w(("Extra parameters. Only using first two."));
    }

    debug(("Parsing '%s' to integer: %d", argv[1], atoi(argv[1])));

    int a = atoi(argv[1]);

    debug(("Parsing '%s' to integer: %d", argv[2], atoi(argv[2])));

    int b = atoi(argv[2]);

    debug(("Beginning calculations: a = %d, b = %d", a, b));

    add_numbers(a, b);
    subtract_numbers(a, b);
    multiply_numbers(a, b);
    divide_numbers(a, b);

    debug(("Finished all calculations."));

    exit(EXIT_SUCCESS);
}

void
print_usage(const char * name)
{
    printf("USAGE %s a b\n", name);
}

void
add_numbers(const int a, const int b)
{
    debug(("Calculating: %d + %d", a, b));

    if ((a + b) == 777) {
        debug_wtf(("You hit the jackpot!"));
    }

    printf("%d + %d = %d\n", a, b, a + b);
}

void
subtract_numbers(const int a, const int b)
{
    debug(("Calculating: %d - %d", a, b));

    if (a < b) {
        debug_w(("Negative result"));
    }

    if ((a - b) == 777) {
        debug_wtf(("You hit the jackpot!"));
    }

    printf("%d - %d = %d\n", a, b, a - b);
}

void
multiply_numbers(const int a, const int b)
{
    debug(("Calculating: %d * %d", a, b));

    if ((a * b) == 777) {
        debug_wtf(("You hit the jackpot!"));
    }

    printf("%d * %d = %d\n", a, b, a * b);
}

void
divide_numbers(const int a, const int b)
{
    debug(("Calculating: %d / %d", a, b));

    assert(b != 0);

    if (b == 0) {
        debug_e(("Division by zero. Skipping."));
        return;
    }

    if ((a / b) == 777) {
        debug_wtf(("You hit the jackpot!"));
    }

    printf("%d / %d = %d\n", a, b, a / b);
}
