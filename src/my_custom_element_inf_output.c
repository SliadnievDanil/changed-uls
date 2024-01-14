#include "uls.h"

int my_custom_element_inf_output(t_element *object_info, t_flag *flags) {
    if (flags->is_G) {
        my_custom_element_color_output(object_info->stat.st_mode);
    }

    my_custom_element_name_output(object_info->name, flags->is_q);

    if (flags->is_G) {
        my_custom_printstr("\033[0m");
    }

    int counter = my_custom_strlen(object_info->name);

    if (flags->is_F || flags->is_p) {
        counter += my_custom_element_class_output(object_info->stat.st_mode, flags->is_p);
    }

    return counter;
}

