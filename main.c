#include <stdio.h>
#include "dynarray.h"

GENERATE_DYNARRAY(int);
GENERATE_DYNARRAY(char);

int main(void)
{
    int i;

    struct dynarray_int *int_dynarray = new_dynarray_int(2);

    for (i = 0; i < 10; i++)
    {
        append_dynarray_int(int_dynarray, i);
    }
    print_dynarray(int_dynarray, "%d");

    pop_dynarray_int(int_dynarray);
    print_dynarray(int_dynarray, "%d");

    shift_dynarray_int(int_dynarray);
    print_dynarray(int_dynarray, "%d");

    free_dynarray(int_dynarray);

    struct dynarray_char *char_dynarr = new_dynarray_char(2);

    for (i = 0; i < 10; i++)
    {
        append_dynarray_char(char_dynarr, 'a' + i);
    }
    print_dynarray(char_dynarr, "%c");

    free_dynarray(char_dynarr);

    return 0;
}
