#ifndef MY_CUSTOM_HEADER_H
#define MY_CUSTOM_HEADER_H

#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <time.h>
#include <unistd.h>
#include "libmx.h"

/* Custom configuration pack */
typedef enum {
    CUSTOM_ONECOL_OUTPUT,
    CUSTOM_DEFAULT_OUTPUT,
    CUSTOM_ONEROW_OUTPUT,
    CUSTOM_L_OUTPUT,
} t_output;

typedef enum {
    CUSTOM_MOD,
    CUSTOM_STAT,
    CUSTOM_ACC,
    CUSTOM_CREATE,
} t_time;

typedef enum {
    CUSTOM_NAME,
    CUSTOM_TIME,
    CUSTOM_SIZE,
    CUSTOM_NONE,
} t_sort;

typedef enum {
    CUSTOM_HIDDEN,
    CUSTOM_DOTS,
    CUSTOM_ZERO,
} t_hidden;

typedef struct {
    t_output format;
    t_time time_type;
    t_sort sort_type;
    t_hidden omit;
    bool is_R;
    bool is_G;
    bool is_F;
    bool is_p;
    bool is_rev;
    bool is_h;
    bool is_e;
    bool is_T;
    bool is_at;
    bool is_g;
    bool is_o;
    bool is_x;
    bool is_n;
    bool is_q;
    bool is_H;
} t_flags;

t_flags *my_custom_make_flags(void);
t_flags *my_custom_init_flags(int argc, char *argv[]);

/* Custom Objects (files and directories) information pack */
typedef struct {
    char *path;
    char *name;
    char *user;
    char *link;
    char *group;
    char **xattr_keys;
    acl_t acl;
    struct stat stat;
    struct timespec timespec;
} t_element;

char *my_custom_take_user_info(uid_t uid, bool number);
char *my_custom_take_group_info(gid_t gid, bool number);
struct timespec my_custom_take_time_info(struct stat *stat, t_time time_type);
char **my_custom_take_xtr_info(const char *filename);
t_element *my_custom_init_element_data(const char *directory, const char *name, t_flags *config);
bool my_custom_is_hidden(const char *name, t_hidden ignore_type);
bool my_custom_take_dir_info(t_list **objects, const char *name, t_flags *config);
void my_custom_free_element_data(t_element *element_data);
blkcnt_t my_custom_block_num(t_list *elements);

/* Custom File information sorting pack */
bool my_custom_strings_cmp(void *data1, void *data2);
void my_custom_arrange_elements(t_list *objects_names, t_sort sort_type);
bool my_custom_name_cmp(void *data1, void *data2);
bool my_custom_time_cmp(void *data1, void *data2);
bool my_custom_size_cmp(void *data1, void *data2);
void my_custom_sort_by_parameters(t_list *elements_data, t_sort sort_type, bool reverse);

/* Custom Outputs packages */
typedef struct {
    int links;
    int user;
    int group;
    int size;
} t_width;

/* Custom Formatted output pack */
void my_custom_element_color_output(mode_t mode);
int my_custom_element_class_output(mode_t mode, bool slash_only);
char *my_custom_change_unprintable(const char *name);
void my_custom_element_name_output(const char *name, bool replace_non_graphic);
int my_custom_element_inf_output(t_element *element_data, t_flags *config);
void my_custom_onecol_output(t_list *elements_data, t_flags *config);
void my_custom_onerow_output(t_list *elements_data, t_flags *config);
void my_custom_output_type(t_list *elements_data, t_flags *config);

/* Custom Long formatted output pack */
void my_custom_element_type_output(mode_t mode);
void my_custom_element_perm_output(mode_t mode);
void my_custom_print_l_str(char *string, int width, bool align_right);
void my_custom_lnum_out(long long number, int width);
void my_custom_element_time_output(time_t ptime, bool full);
double my_custom_long_round(double number);
void my_custom_element_size_output(off_t size, int width);
void my_custom_element_xtr_output(t_element *element_data, bool human_readable);
void my_custom_element_acl_output(acl_t acl);
void my_custom_L_output_single(t_element *elements_data, t_width *width, t_flags *config);
t_width my_custom_maxlen_l(t_list *elements_data, t_flags *config);
void my_custom_L_output(t_list *elements_data, t_flags *config);

/* Custom Multicolumn formatted output pack */
int my_custom_maxlen_default(t_list *elements_data);
int my_custom_find_space_len(void);
void my_custom_cols_output(int width, int tab_width);
t_element **my_custom_create_arr_from_list(t_list *elements_data, int *count);
void my_custom_default_output(t_list *elements_data, t_flags *config);

/* Custom main pack */
t_list *my_custom_take_elements(int argc, char *argv[]);
void my_custom_error_output(const char *file);
void my_custom_free_elements(t_list *elements_data);
void my_custom_output_files(t_list *files, t_flags *config);
bool my_custom_output_directory(t_element *element_data, t_flags *config, bool print_object_name);
bool my_custom_output_directories(t_list *directories, t_flags *config, bool print_objects_names);
int my_custom_output_elements(t_list *elements, t_flags *config);

char *my_custom_lltoa(long long number);
t_list *my_custom_sort_list_objects(t_list *list, bool (*cmp)(void *, void *), bool reverse);
char *my_custom_strjoin_with_delim(const char *s1, const char *s2, char delim);
int my_custom_validate_elements(t_list* elements);
int my_custom_validate_flags(t_flags *flags);

void my_custom_clear_list(t_list **list); 

#endif

