#include "uls.h"

int my_custom_validate_elements(t_list *elements) {
    int counter = 0;
    t_list *node = elements;

    for (; node != NULL;) {
        node = node->next;
        counter++;
    }

    if (counter < 0) {
        counter = -42;
    }

    return counter;
}

