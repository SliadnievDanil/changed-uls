#include "uls.h"

bool my_custom_is_hidden(const char *name, t_hidden ommit) {
    if (ommit == HIDDEN
        && name[0] == '.') {
        return true;
    }

    if (ommit == DOTS
        && (my_custom_strcmp(name, ".") == 0
        || my_custom_strcmp(name, "..") == 0)) {
        return true;
    }

    return false;
}

