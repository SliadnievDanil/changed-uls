#include "uls.h"

CustomElement **my_custom_create_arr_from_list(t_list *objects_info, int *counter) {
    *counter = my_custom_list_size(objects_info);

    if (*counter == 0) {
        return NULL;
    }

    CustomElement **array = malloc(sizeof(CustomElement *) * (*counter));

    for (int i = 0; i < *counter; i++) {
        array[i] = objects_info->data;
        objects_info = objects_info->next;
    }

    return array;
}