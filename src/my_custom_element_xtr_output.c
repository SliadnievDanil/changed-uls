#include "uls.h"

void my_custom_element_xtr_output(t_element *elements_data, bool is_h) {
    for (char **ptr = elements_data->xattr_keys; *ptr != NULL; ptr++) {
        my_custom_printchar('\t');
        my_custom_printstr(*ptr);
        my_custom_printchar('\t');
        ssize_t value_size = getxattr(elements_data->path, *ptr, NULL, 0, 0, XATTR_NOFOLLOW);

        if (is_h) {
            my_custom_element_size_output(value_size, 5);
        } else {
            my_custom_lnum_out(value_size, 4);
        }

        my_custom_printstr(" \n");
    }
}

