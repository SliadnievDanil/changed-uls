#include "uls.h"

void my_custom_lnum_out(long long number, int width) {
    char *string = my_custom_lltoa(number);
    my_custom_print_l_str(string, width, true);
    free(string);
}