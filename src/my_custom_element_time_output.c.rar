#include "uls.h"

void my_custom_element_time_output(time_t ptime, bool full) {
    char *str = ctime(&ptime);
    char **arr = my_custom_strsplit(str, ' ');
    time_t current = time(NULL);
    time_t sec_6_mon = (365 / 2) * 24 * 60 * 60;
    arr[4][4] = '\0';

    if (full) {
        for (int i = 1; arr[i] != NULL; i++) {
            my_custom_print_l_str(arr[i], 2, true);

            if (arr[i + 1] != NULL) {
                my_custom_printchar(' ');
            }
        }
    } else if (ptime + sec_6_mon <= current || ptime >= current + sec_6_mon) {
        my_custom_printstr(arr[1]);
        my_custom_printchar(' ');
        my_custom_print_l_str(arr[2], 2, true);
        my_custom_printstr("  ");
        my_custom_printstr(arr[4]);
    } else {
        my_custom_printstr(arr[1]);
        my_custom_printchar(' ');
        my_custom_print_l_str(arr[2], 2, true);
        my_custom_printchar(' ');
        char **arr_time = my_custom_strsplit(arr[3], ':');
        my_custom_printstr(arr_time[0]);
        my_custom_printchar(':');
        my_custom_printstr(arr_time[1]);
        my_custom_del_strarr(&arr_time);
    }

    my_custom_del_strarr(&arr);
}