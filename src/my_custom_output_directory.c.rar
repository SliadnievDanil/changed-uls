#include "uls.h"

bool my_custom_output_directory(t_element *element_data, t_flags *flags, bool my_custom_element_name_output) {
    if (my_custom_element_name_output) {
        mx_printstr(element_data->name);
        mx_printstr(":\n");
    }

    t_list *elements_data = NULL;
    bool result = my_custom_take_dir_info(&elements_data, element_data->path, flags);

    if (flags->format == L_OUTPUT
        && elements_data != NULL) {
        mx_printstr("total ");
        mx_printint(my_custom_block_num(elements_data));
        mx_printchar('\n');
    }

    if (!result) {
        my_custom_error_output(element_data->name);
        return false;
    }

    my_custom_sort_by_parameters(elements_data, flags->sort_type, flags->is_rev);
    my_custom_output_type(elements_data, flags);

    if (flags->is_R) {
        t_list *directories = NULL;

        while (elements_data != NULL) {
            t_element *entry = elements_data->data;

            if (S_ISDIR(entry->stat.st_mode)
                && !my_custom_is_hidden(entry->name, DOTS)) {
                free(entry->name);
                entry->name = mx_strdup(entry->path);
                mx_push_back(&directories, entry);
            }

            elements_data = elements_data->next;
        }

        if (directories != NULL) {
            mx_printchar('\n');
        }

        if (!my_custom_output_directories(directories, flags, true)) {
            result = false;
        }

        mx_clear_list(&directories);
    }

    mx_free_elements(elements_data);

    return result;
}