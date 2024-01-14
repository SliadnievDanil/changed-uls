#include "uls.h"

void my_custom_element_size_output(off_t size, int width) {
    const char *all_s[] = {"B", "K", "M", "G", "T", "P"};
    double f_size = size;
    int suf = 0;

    while (f_size >= 1000) {
        f_size /= 1024;
        suf++;
    }

    double size_r = my_custom_long_round(f_size * 10) / 10;
    char buf[5] = {'\0'};

    if (size_r >= 10 || suf == 0) {
        char *str = my_custom_lltoa(my_custom_long_round(f_size));
        my_custom_strcat(buf, str);
        free(str);
    } else {
        char *str = my_custom_lltoa(size_r);
        my_custom_strcat(buf, str);
        free(str);
        my_custom_strcat(buf, ".");
        str = my_custom_lltoa((long long)(size_r * 10) % 10);
        my_custom_strcat(buf, str);
        free(str);
    }

    my_custom_strcat(buf, all_s[suf]);
    my_custom_print_l_str(buf, width, true);
}