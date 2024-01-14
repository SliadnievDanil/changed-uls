#include "uls.h"

CustomElement *my_custom_init_element_data(const char *directory, const char *name, t_flags *flags) {
    t_element *object_info = malloc(sizeof(t_element));
    object_info->path = my_custom_strjoin_with_delim(directory, name, '/');
    object_info->name = my_custom_strdup(name);
    object_info->user = NULL;
    object_info->link = NULL;
    object_info->group = NULL;
    object_info->xattr_keys = NULL;
    object_info->acl = NULL;
    int err;

    if (directory == NULL && flags->is_H) {
        err = my_custom_stat(object_info->path, &object_info->stat);
    } else {
        err = my_custom_lstat(object_info->path, &object_info->stat);
    }

    if (err != 0) {
        my_custom_free_element_data(object_info);
        return NULL;
    }

    if (flags->format == L_OUTPUT) {
        object_info->user = my_custom_take_user_info(object_info->stat.st_uid, flags->is_n);
        object_info->group = my_custom_take_group_info(object_info->stat.st_gid, flags->is_n);

        if (S_ISLNK(object_info->stat.st_mode)) {
            object_info->link = malloc(PATH_MAX);
            ssize_t size = my_custom_readlink(object_info->path, object_info->link, PATH_MAX);
            object_info->link[size] = '\0';
        } else {
            object_info->link = NULL;
            object_info->acl = my_custom_acl_get_file(object_info->path, ACL_TYPE_EXTENDED);
        }

        object_info->xattr_keys = my_custom_take_xtr_info(object_info->path);
    }

    object_info->timespec = my_custom_take_time_info(&object_info->stat, flags->time_type);

    return object_info;
}

