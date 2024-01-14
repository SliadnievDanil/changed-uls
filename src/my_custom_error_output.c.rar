#include "uls.h"

void my_custom_error_output(const char *file) {
    my_custom_printerr("uls: ");
    my_custom_printerr(file);
    my_custom_printerr(": ");
    my_custom_printerr(my_custom_strerror(errno));
    my_custom_printerr("\n");
}