#include "uls.h"

void my_custom_print_l_str(char *string, int width, bool align_right) {
    int len = width - mx_strlen(string);

    if (!align_right) {
        my_custom_printstr(string);
    }

    for (int i = 0; i < len; i++) {
        my_custom_printchar(' ');
    }

    if (align_right) {
        my_custom_printstr(string);
    }
}