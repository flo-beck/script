# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbeck <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 23:06:12 by fbeck             #+#    #+#              #
#    Updated: 2014/02/23 20:57:32 by fbeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME               = libft.a

CC                 = clang
FLAG               = -Wall -Werror -Wextra -pedantic
INCS               = -I ./includes

SRC                = $(DIR_SRC)/ft_atoi.c \
					 $(DIR_SRC)/ft_bzero.c \
					 $(DIR_SRC)/ft_isalnum.c \
					 $(DIR_SRC)/ft_isalpha.c \
					 $(DIR_SRC)/ft_isascii.c \
					 $(DIR_SRC)/ft_isdigit.c \
					 $(DIR_SRC)/ft_isprint.c \
					 $(DIR_SRC)/ft_itoa.c \
					 $(DIR_SRC)/ft_memalloc.c \
					 $(DIR_SRC)/ft_memccpy.c \
					 $(DIR_SRC)/ft_memchr.c \
					 $(DIR_SRC)/ft_memcmp.c \
					 $(DIR_SRC)/ft_memcpy.c \
					 $(DIR_SRC)/ft_memdel.c \
					 $(DIR_SRC)/ft_memmove.c \
					 $(DIR_SRC)/ft_memset.c \
					 $(DIR_SRC)/ft_putchar.c \
					 $(DIR_SRC)/ft_putchar_fd.c \
					 $(DIR_SRC)/ft_putendl.c \
					 $(DIR_SRC)/ft_putendl_fd.c \
					 $(DIR_SRC)/ft_putnbr_fd.c \
					 $(DIR_SRC)/ft_putstr.c \
					 $(DIR_SRC)/ft_putstr_fd.c \
					 $(DIR_SRC)/ft_strcat.c \
					 $(DIR_SRC)/ft_strchr.c \
					 $(DIR_SRC)/ft_strclr.c \
					 $(DIR_SRC)/ft_strcmp.c \
					 $(DIR_SRC)/ft_strcpy.c \
					 $(DIR_SRC)/ft_strdel.c \
					 $(DIR_SRC)/ft_strdup.c \
					 $(DIR_SRC)/ft_strequ.c \
					 $(DIR_SRC)/ft_striter.c \
					 $(DIR_SRC)/ft_striteri.c \
					 $(DIR_SRC)/ft_strjoin.c \
					 $(DIR_SRC)/ft_strlcat.c \
					 $(DIR_SRC)/ft_strlen.c \
					 $(DIR_SRC)/ft_strmap.c \
					 $(DIR_SRC)/ft_strmapi.c \
					 $(DIR_SRC)/ft_strncat.c \
					 $(DIR_SRC)/ft_strncmp.c \
					 $(DIR_SRC)/ft_strncpy.c \
					 $(DIR_SRC)/ft_strnequ.c \
					 $(DIR_SRC)/ft_strnew.c \
					 $(DIR_SRC)/ft_strnstr.c \
					 $(DIR_SRC)/ft_strrchr.c \
					 $(DIR_SRC)/ft_strsplit.c \
					 $(DIR_SRC)/ft_strstr.c \
					 $(DIR_SRC)/ft_strsub.c \
					 $(DIR_SRC)/ft_strtrim.c \
					 $(DIR_SRC)/ft_tolower.c \
					 $(DIR_SRC)/ft_toupper.c \
					 $(DIR_SRC)/ft_isspace.c \
					 $(DIR_SRC)/ft_putnbr.c \
					 $(DIR_SRC)/ft_lstnew.c \
					 $(DIR_SRC)/ft_lstdnew.c \
					 $(DIR_SRC)/ft_lstdelone.c \
					 $(DIR_SRC)/ft_lstddelone.c \
					 $(DIR_SRC)/ft_lstdel.c \
					 $(DIR_SRC)/ft_lstddel.c \
					 $(DIR_SRC)/ft_lstadd.c \
					 $(DIR_SRC)/ft_lstiter.c \
					 $(DIR_SRC)/ft_lstmap.c \
					 $(DIR_SRC)/ft_swap_ptr.c \
					 $(DIR_SRC)/ft_sort_strs.c \
					 $(DIR_SRC)/ft_swap_lst.c \
					 $(DIR_SRC)/ft_sort_lst.c \
					 $(DIR_SRC)/ft_isblank.c \
					 $(DIR_SRC)/ft_indexof.c \
					 $(DIR_SRC)/ft_lstdel_elem.c \
					 $(DIR_SRC)/ft_lstpush.c \
					 $(DIR_SRC)/ft_lstadd_end.c \
					 $(DIR_SRC)/ft_lstdadd_end.c \
					 $(DIR_SRC)/ft_free_split.c \
					 $(DIR_SRC)/get_next_line.c \
					 $(DIR_SRC)/ft_char_in.c \
					 $(DIR_SRC)/ft_treenew.c \

DIR_SRC            = srcs
DIR_INC            = includes
DIR_OBJ            = .obj

DIR_LIST           = srcs

OBJ                = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

$(addprefix $(DIR_OBJ)/, %.o) : %.c $(DIR_INC)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCS)

$(NAME) : $(DIR_OBJ) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	/bin/rm	-fr $(DIR_OBJ)

fclean : clean
	/bin/rm -fr $(NAME)

re : fclean all

debug : FLAG += -g3 -fno-inline -DD_ERRORS_ON
debug : re
	printf '\033[1;31m%s\033[0m\n' "Debug enabled."

all : $(NAME)

$(DIR_OBJ) :
	/bin/mkdir $(DIR_OBJ); \
		for DIR in $(DIR_LIST); \
		do \
		/bin/mkdir $(DIR_OBJ)/$$DIR; \
		done

.PHONY:	clean fclean re debug
