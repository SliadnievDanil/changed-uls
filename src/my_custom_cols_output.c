#include "uls.h"

void my_custom_cols_output(int width, int tab_width) {
    int tab = (width + tab_width - 1) / tab_width;

    for (int i = 0; i < tab; i++) {
        if (tab_width == 1) {
            my_custom_printchar(' ');
        } else {
            my_custom_printchar('\t');
        }
    }
}