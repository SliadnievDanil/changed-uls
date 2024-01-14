#include "uls.h"

char *my_custom_take_group_info(gid_t gid, bool number) {
    struct group *group = getgrgid(gid);

    if (group == NULL
        || number) {
        return my_custom_lltoa(gid);
    }

    return my_custom_strdup(group->gr_name);
}