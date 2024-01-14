#include "uls.h"

int my_custom_output_elements(t_list *elements, t_flags *flags) {
    t_list *files = NULL;
    t_list *directories = NULL;
    bool print_elements_names = mx_list_size(elements) > 1;
    int result = 0;
    my_custom_arrange_elements(elements, flags->sort_type);

    while (elements != NULL) {
        char *object = elements->data;
        elements = elements->next;
        t_element *element_data = my_custom_init_element_data(NULL, object, flags);

        if (element_data == NULL) {
            my_custom_error_output(object);
            result = 1;
            continue;
        }

        if (S_ISDIR(element_data->stat.st_mode)) {
            mx_push_back(&directories, element_data);
        } else {
            mx_push_back(&files, element_data);
        }
    }

    my_custom_output_files(files, flags);

    if (files != NULL
        && directories != NULL) {
        mx_printchar('\n');
    }

    if (!my_custom_output_directories(directories, flags, print_elements_names)) {
        result = 1;
    }

    mx_free_elements(files);
    mx_free_elements(directories);

    return result;
}