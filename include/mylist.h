/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** mylist.h
*/


#ifndef MY_LIST
    #define MY_LIST
    typedef struct linked_list_s {
        void *data;
        struct linked_list_s *next;
    } linked_list_t;

int my_list_size(linked_list_t *begin);
linked_list_t *my_params_to_list(int ac, char** av);
int my_apply_on_nodes(linked_list_t *begin, int(*f)(void*));
char **linked_list_to_word_array(linked_list_t *linked_list);
linked_list_t* my_add_node(linked_list_t** list, void *value);
char **my_linked_list_to_word_array(linked_list_t *linked_list);
void my_concat_list(linked_list_t **begin1, linked_list_t *begin2);
int my_delete_nodes(linked_list_t **begin,void const *data_ref, int (*cmp)());
linked_list_t *my_find_node(linked_list_t *begin, void *data_ref, int (*cmp)());
int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
                            void const *data_ref, int (*cmp)());
#endif
