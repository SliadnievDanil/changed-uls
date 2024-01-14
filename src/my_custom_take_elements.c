#include "uls.h"

t_list *my_custom_take_elements(int argc, char *argv[]) {
    t_list *elements = NULL;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-'
            || elements != NULL) {
            my_custom_push_back(&elements, argv[i]);
        }
    }

    if (elements == NULL) {
        my_custom_push_back(&elements, ".");
    }

    return elements;
}

