#include "uls.h"

void my_custom_L_output(t_list *elements_data, t_flags *flags) {
    t_width width = my_custom_maxlen_l(elements_data, flags);

    while (elements_data != NULL) {
        my_custom_L_output_single(elements_data->data, &width, flags);
        elements_data = elements_data->next;
    }
}