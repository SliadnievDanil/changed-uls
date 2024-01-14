#include "uls.h"

void my_custom_onerow_output(t_list *elements_data, t_flags *flags) {
    while (elements_data != NULL) {
        my_custom_element_inf_output(elements_data->data, flags);

        if (elements_data->next != NULL) {
            my_custom_printstr(", ");
        }

        elements_data = elements_data->next;
    }

    my_custom_printchar('\n');
}

