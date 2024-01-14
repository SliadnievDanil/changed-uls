#include "uls.h"

void my_custom_output_type(t_list *elements_data, t_flags *flags) {
    if (flags->format == ONECOL_OUTPUT) {
        my_custom_onecol_output(elements_data, flags);
    } else if (flags->format == DEFAULT_OUTPUT) {
        my_custom_default_output(elements_data, flags);
    } else if (flags->format == ONEROW_OUTPUT) {
        my_custom_onerow_output(elements_data, flags);
    } else if (flags->format == L_OUTPUT) {
        my_custom_L_output(elements_data, flags);
    }
}

