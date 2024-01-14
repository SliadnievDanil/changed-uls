#include "uls.h"

void my_custom_element_color_output(mode_t mode) {
    if ((mode & S_IFMT) == S_IFBLK) {
        my_custom_printstr("\033[34;46m");
    } else if ((mode & S_IFMT) == S_IFCHR) {
        my_custom_printstr("\033[34;43m");
    } else if ((mode & S_IFMT) == S_IFDIR) {
        if (mode & S_IWOTH) {
            if (mode & S_ISTXT) {
                my_custom_printstr("\033[30;42m");
            } else {
                my_custom_printstr("\033[30;43m");
            }
        } else {
            my_custom_printstr("\033[34m");
        }
    } else if ((mode & S_IFMT) == S_IFIFO) {
        my_custom_printstr("\033[33m");
    } else if ((mode & S_IFMT) == S_IFLNK) {
        my_custom_printstr("\033[35m");
    } else if ((mode & S_IFMT) == S_IFSOCK) {
        my_custom_printstr("\033[32m");
    } else {
        if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
            if (mode & S_ISUID) {
                my_custom_printstr("\033[30;41m");
            } else if (mode & S_ISGID) {
                my_custom_printstr("\033[30;46m");
            } else {
                my_custom_printstr("\033[31m");
            }
        }
    }
}