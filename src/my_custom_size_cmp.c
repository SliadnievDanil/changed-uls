#include "uls.h"

bool my_custom_size_cmp(void *data1, void *data2) {
    t_element *element_data1 = data1;
    t_element *element_data2 = data2;

    if (element_data1->stat.st_size == element_data2->stat.st_size) {
        return mx_strcmp(element_data1->name, element_data2->name) > 0;
    }

    return element_data1->stat.st_size < element_data2->stat.st_size;
}

