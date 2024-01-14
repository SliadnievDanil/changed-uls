#include "uls.h"

bool my_custom_take_dir_info(t_list **objects, const char *name, t_flags *flags) {
    DIR *directory = opendir(name);
    struct dirent *object = NULL;

    if (directory == NULL) {
        return false;
    }

    while ((object = readdir(directory)) != NULL) {
        if (!my_custom_is_hidden(object->d_name, flags->ommit)) {
            my_custom_push_back(objects, my_custom_init_element_data(name, object->d_name, flags));
        }
    }

    closedir(directory);

    return true;
}

