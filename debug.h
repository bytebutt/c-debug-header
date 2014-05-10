#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <stdio.h>

#ifdef DEBUG_COLOR /* Colorize with ANSI escape sequences. */

#  define DEBUG_COLOR_BLACK  "[1;30m"
#  define DEBUG_COLOR_RED    "[1;31m"
#  define DEBUG_COLOR_GREEN  "[1;32m"
#  define DEBUG_COLOR_YELLOW "[1;33m"
#  define DEBUG_COLOR_BLUE   "[1;34m"
#  define DEBUG_COLOR_PURPLE "[1;35m"
#  define DEBUG_COLOR_RESET  "[m"

#else

#  define DEBUG_COLOR_BLACK  ""
#  define DEBUG_COLOR_RED    ""
#  define DEBUG_COLOR_GREEN  ""
#  define DEBUG_COLOR_YELLOW ""
#  define DEBUG_COLOR_BLUE   ""
#  define DEBUG_COLOR_PURPLE ""
#  define DEBUG_COLOR_RESET  ""

#endif /* DEBUG_COLOR */

#define colorize(text,color) color text DEBUG_COLOR_RESET

#define debug_label(color) \
    printf(colorize("Debug[", color) "%s" colorize("|", color) "%d" colorize("|", color) "%s" colorize("]: ", color), \
        __FILE__, __LINE__, __func__)

#define debug_type(type,color) \
    printf(colorize(type ":", color) " ")

#ifdef DEBUG89 /* C >= C89 */

#  define debug(msg)      do { debug_label(DEBUG_COLOR_BLUE);                                            printf msg; printf("\n"); } while(0)
#  define debug_w(msg)    do { debug_label(DEBUG_COLOR_BLUE); debug_type("WARNING", DEBUG_COLOR_YELLOW); printf msg; printf("\n"); } while(0)
#  define debug_e(msg)    do { debug_label(DEBUG_COLOR_BLUE); debug_type("ERROR",   DEBUG_COLOR_RED);    printf msg; printf("\n"); } while(0)
#  define debug_wtf(msg)  do { debug_label(DEBUG_COLOR_BLUE); debug_type("WTF",     DEBUG_COLOR_GREEN);  printf msg; printf("\n"); } while(0)

#  define assert(expr)    do { if (!(expr)) { debug_label(DEBUG_COLOR_BLUE); debug_type("ASSERTION FAILED", DEBUG_COLOR_PURPLE); printf(#expr); printf("\n"); } } while(0)

#elif defined DEBUG /* C >= C99 */

#  define debug(...)      do { debug_label(DEBUG_COLOR_BLUE);                                            printf(__VA_ARGS__); printf("\n"); } while(0)
#  define debug_w(...)    do { debug_label(DEBUG_COLOR_BLUE); debug_type("WARNING", DEBUG_COLOR_YELLOW); printf(__VA_ARGS__); printf("\n"); } while(0)
#  define debug_e(...)    do { debug_label(DEBUG_COLOR_BLUE); debug_type("ERROR",   DEBUG_COLOR_RED);    printf(__VA_ARGS__); printf("\n"); } while(0)
#  define debug_wtf(...)  do { debug_label(DEBUG_COLOR_BLUE); debug_type("WTF",     DEBUG_COLOR_GREEN);  printf(__VA_ARGS__); printf("\n"); } while(0)

#  define assert(expr)    do { if (!(expr)) { debug_label(DEBUG_COLOR_BLUE); debug_type("ASSERTION FAILED", DEBUG_COLOR_PURPLE); printf(#expr); printf("\n"); } } while(0)

#else

#  define debug(args)      ((void) 0)
#  define debug_w(args)    ((void) 0)
#  define debug_e(args)    ((void) 0)
#  define debug_wtf(args)  ((void) 0)
#  define assert(expr)     ((void) 0)

#endif /* DEBUG */
#endif /* DEBUG_H_INCLUDED */
