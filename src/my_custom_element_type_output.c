#include "uls.h"

void my_custom_element_type_output(mode_t mode) {
    if ((mode & S_IFMT) == S_IFBLK) {
        my_custom_printchar('b');
    } else if ((mode & S_IFMT) == S_IFCHR) {
        my_custom_printchar('c');
    } else if ((mode & S_IFMT) == S_IFDIR) {
        my_custom_printchar('d');
    } else if ((mode & S_IFMT) == S_IFIFO) {
        my_custom_printchar('p');
    } else if ((mode & S_IFMT) == S_IFLNK) {
        my_custom_printchar('l');
    } else if ((mode & S_IFMT) == S_IFSOCK) {
        my_custom_printchar('s');
    } else {
        my_custom_printchar('-');
    }
}

