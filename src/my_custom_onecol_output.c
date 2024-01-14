#include "uls.h"

void my_custom_onecol_output(t_list *elements_data, t_flags *flags) {
    while (elements_data != NULL) {
        my_custom_element_inf_output(elements_data->data, flags);
        my_custom_printchar('\n');
        elements_data = elements_data->next;
    }
}