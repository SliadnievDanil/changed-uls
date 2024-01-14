#include "uls.h"

bool my_custom_output_directories(t_list *directories, t_flags *flags, bool print_objects_names) {
    bool ret = true;
    my_custom_sort_by_parameters(directories, flags->sort_type, flags->is_rev);

    while (directories != NULL) {
        t_element *element_data = directories->data;

        if (!my_custom_output_directory(element_data, flags, print_objects_names)) {
            ret = false;
        }

        if (directories->next != NULL) {
            mx_printchar('\n');
        }

        directories = directories->next;
    }

    return ret;
}