##
## EPITECH PROJECT, 2022
## lib my
## File description:
## Makefile for my lib
##

SRC =	./my_list_size.c				\
        ./my_str_islower.c				\
        ./my_is_prime.c					\
        ./my_find_prime_sup.c			\
        ./my_params_to_list.c			\
        ./my_str_isalpha.c				\
        ./my_put_nbr.c					\
        ./my_strcmp.c					\
        ./my_sort_int_array.c			\
        ./my_putchar.c					\
        ./my_get_env.c					\
        ./my_strncat.c					\
        ./my_delete_nodes.c				\
        ./my_strcpy.c					\
        ./my_strncmp.c					\
        ./my_apply_on_nodes.c			\
        ./my_concat_list.c				\
        ./my_strlen.c					\
        ./my_strcat.c					\
        ./my_compute_square_root.c		\
        ./my_array_size.c				\
        ./my_strstr.c					\
        ./my_strncpy.c					\
        ./my_revstr.c					\
        ./my_str_to_word_array.c		\
        ./my_get_color.c				\
        ./my_str_isnum.c				\
        ./my_putstr.c					\
        ./my_str_isprintable.c			\
        ./my_find_node.c				\
        ./my_strlowcase.c				\
        ./my_swap.c						\
        ./my_str_dup.c					\
        ./my_strcapitalize.c			\
        ./my_strupcase.c				\
        ./my_isneg.c					\
        ./my_str_isupper.c				\
        ./my_add_node.c					\
        ./my_getnbr.c					\
        ./my_compute_power_rec.c		\
        ./my_free_linked_list.c			\
        ./my_apply_on_matching_nodes.c	\
        ./my_realloc.c	\
        ./my_memcpy.c	\
        ./string/my_string_copy.c	\
        ./string/my_string_init.c	\
        ./string/my_string_destroy.c	\
        ./string/my_string_add_char.c	\
        ./string/my_string_clear.c	\
        ./string/my_str_contains.c	\
        ./my_linked_list_to_word_array.c	\
        ./linked_list_to_word_array.c	\
        ./my_int_to_str.c	\
        ./my_put_error.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc
CFLAGS	= -W -Wall -Wextra -I ../../include/ -g

LIB_FOLDER	=	../
LIB_FILE =	libmy.a

build_lib:	$(LIB_FILE)
	ar rc $(LIB_FILE) $(OBJ)
	cp $(LIB_FILE) $(LIB_FOLDER)$(LIB_FILE)

$(LIB_FILE):	$(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(LIB_FILE)
	rm -rf $(LIB_FOLDER)$(LIB_FILE)

re:	fclean build_lib
