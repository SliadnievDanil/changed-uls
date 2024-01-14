#include "uls.h"

void my_custom_arrange_elements(t_list *objects_names, CustomSort sort_type) {
    if (sort_type != CUSTOM_NONE) {
        my_custom_sort_list_objects(objects_names, my_custom_strings_cmp, false);
    }
}