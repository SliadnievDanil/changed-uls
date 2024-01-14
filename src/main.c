#include "uls.h"

int main(int argc, char *argv[]) {

    t_list *elements = my_custom_take_elements(argc, argv);

    int val1 = my_custom_validate_elements(elements);

    if (val1 < 0)
    {
        return -1;
    }

    t_flags *flags = my_custom_init_flags(argc, argv);

    int val2 = 0;
    val2 = my_custom_validate_flags(flags);

    if (val2 < 0)
    {
        return -1;
    }

    int result = my_custom_output_elements(elements, flags);

    my_custom_clear_list(&elements);

    free(flags);

    return result;
}

