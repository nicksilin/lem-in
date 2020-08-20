# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwiley <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 15:18:25 by fwiley            #+#    #+#              #
#    Updated: 2020/01/24 10:19:10 by fwiley           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME = ft_get_next_line.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_memalloc.c\
	ft_strnew.c\
	ft_strdup.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isdigit.c\
	ft_isspace.c\
	ft_isalpha.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_memdel.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strndup.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_itoa.c\
	ft_strsplit.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_bubble_sort.c\
	ft_swipe_byte.c\
	ft_reverse_byte.c\
	ft_lstsize.c

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR)$(SRCS_NAME))

#includes
INCLUDES_NAME = libft.h
INCLUDES_DIR = ./
INCLUDES = $(addprefix $(INCLUDES_DIR),$(INCLUDES_NAME))

#objects
OBJS_DIR = ./obj/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR),$(OBJS_NAME))

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJS_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
