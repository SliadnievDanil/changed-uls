#include "uls.h"

void my_custom_element_acl_output(acl_t acl) {
    char *str = acl_to_text(acl, NULL);
    char **rows = my_custom_strsplit(str, '\n');

    for (int i = 1; rows[i] != NULL; i++) {
        my_custom_printchar(' ');
        my_custom_printint(i - 1);
        my_custom_printstr(": ");
        char **parts = my_custom_strsplit(rows[i], ':');
        my_custom_printstr(parts[0]);
        my_custom_printchar(':');
        my_custom_printstr(parts[2]);
        my_custom_printchar(' ');
        my_custom_printstr(parts[4]);
        my_custom_printchar(' ');
        my_custom_printstr(parts[5]);
        my_custom_printchar('\n');
        my_custom_del_strarr(&parts);
    }

    my_custom_del_strarr(&rows);
    free(str);
}

