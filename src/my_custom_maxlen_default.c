#include "uls.h"

int my_custom_maxlen_default(t_list *elements_data) {
    int width = 0;

    while (elements_data != NULL) {
        t_element *element_info = elements_data->data;
        int len = my_custom_strlen(element_info->name);

        if (width < len) {
            width = len;
        }

        elements_data = elements_data->next;
    }

    return width;
}