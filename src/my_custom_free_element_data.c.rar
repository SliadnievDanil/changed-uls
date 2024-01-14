#include "uls.h"

void my_custom_free_element_data(CustomElement *element_data) {
    free(element_data->path);
    free(element_data->name);
    my_custom_strdel(&element_data->user);
    my_custom_strdel(&element_data->link);
    my_custom_strdel(&element_data->group);
    my_custom_del_strarr(&element_data->xattr_keys);
    my_custom_acl_free(element_data->acl);
    free(element_data);
}