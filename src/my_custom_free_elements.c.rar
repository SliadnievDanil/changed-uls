#include "uls.h"

void my_custom_free_elements(CustomList *elements_data) {
    CustomList *helper = elements_data;

    while (helper != NULL) {
        CustomElement *element_data = helper->data;
        my_custom_free_element_data(element_data);
        helper = helper->next;
    }

    my_custom_clear_list(&elements_data);
}