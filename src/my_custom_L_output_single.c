#include "uls.h"

void my_custom_L_output_single(t_element *elements_data, t_width *width, t_flags *flags) {
    my_custom_element_perm_output(elements_data->stat.st_mode);

    if (elements_data->xattr_keys != NULL) {
        mx_printchar('@');
    } else if (elements_data->acl != NULL) {
        mx_printchar('+');
    } else {
        mx_printchar(' ');
    }

    mx_printchar(' ');
    my_custom_lnum_out(elements_data->stat.st_nlink, width->links);
    mx_printchar(' ');

    if (!flags->is_g) {
        my_custom_print_l_str(elements_data->user, width->user, false);
        mx_printstr("  ");
    }

    if (!flags->is_o) {
        my_custom_print_l_str(elements_data->group, width->group, false);
        mx_printstr("  ");
    }

    if (flags->is_g
        && flags->is_o) {
        mx_printstr("  ");
    }

    if (S_ISCHR(elements_data->stat.st_mode)
        || S_ISBLK(elements_data->stat.st_mode)) {
        char *hex = mx_nbr_to_hex(elements_data->stat.st_rdev);
        char *str;

        if (elements_data->stat.st_rdev == 0) {
            str = mx_strdup(hex);
        } else {
            str = mx_strjoin("0x", hex);
        }

        my_custom_print_l_str(str, width->size, true);
        free(str);
        free(hex);
    } else if (flags->is_h) {
        my_custom_element_size_output(elements_data->stat.st_size, width->size);
    } else {
        my_custom_lnum_out(elements_data->stat.st_size, width->size);
    } 

    mx_printchar(' ');
    my_custom_element_time_output(elements_data->timespec.tv_sec, flags->is_T);
    mx_printchar(' ');
    my_custom_element_inf_output(elements_data, flags);

    if (elements_data->link != NULL) {
        mx_printstr(" -> ");
        mx_printstr(elements_data->link);
    }

    mx_printchar('\n');

    if (flags->is_at
        && elements_data->xattr_keys != NULL) {
        my_custom_element_xtr_output(elements_data, flags->is_h);
    }

    if (flags->is_e
        && elements_data->acl != NULL) {
        my_custom_element_acl_output(elements_data->acl);
    }
}

