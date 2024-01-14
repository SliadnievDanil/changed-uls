#include "uls.h"

int my_custom_find_space_len(void) {
    if (isatty(1)) {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);

        return w.ws_col;
    }

    return 80;
}