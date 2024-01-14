#include "uls.h"

void my_custom_element_name_output(const char *name, bool is_q) {
    if (is_q) {
        char *str = my_custom_change_unprintable(name);
        my_custom_printstr(str);
        free(str);
    } else {
        my_custom_printstr(name);
    }
}

