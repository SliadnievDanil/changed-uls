#include "uls.h"

void my_custom_element_perm_output(mode_t mode) {
    my_custom_element_type_output(mode);
    my_custom_printchar((mode & S_IRUSR) ? 'r' : '-');
    my_custom_printchar((mode & S_IWUSR) ? 'w' : '-');

    if (mode & S_IXUSR) {
        my_custom_printchar((mode & S_ISUID) ? 's' : 'x');
    } else {
        my_custom_printchar((mode & S_ISUID) ? 'S' : '-');
    }

    my_custom_printchar((mode & S_IRGRP) ? 'r' : '-');
    my_custom_printchar((mode & S_IWGRP) ? 'w' : '-');

    if (mode & S_IXGRP) {
        my_custom_printchar((mode & S_ISGID) ? 's' : 'x');
    } else {
        my_custom_printchar((mode & S_ISGID) ? 'S' : '-');
    }

    my_custom_printchar((mode & S_IROTH) ? 'r' : '-');
    my_custom_printchar((mode & S_IWOTH) ? 'w' : '-');

    if (mode & S_IXOTH) {
        my_custom_printchar((mode & S_ISTXT) ? 't' : 'x');
    } else {
        my_custom_printchar((mode & S_ISTXT) ? 'T' : '-');
    }
}

