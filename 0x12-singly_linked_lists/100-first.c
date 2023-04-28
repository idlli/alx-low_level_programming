#include <stdio.h>

/**
 * my_startup_fun - Function executed before main
 */
void my_startup_fun(void) __attribute__ ((constructor));

void my_startup_fun(void)
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}
