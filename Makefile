# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/10 18:28:08 by jgroleo           #+#    #+#              #
#    Updated: 2020/03/12 14:19:00 by fwiley           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re lem-in

NAME_VS = vs
NAME = lem-in

CC = gcc
FLAGS = -Wall -Werror -Wextra

#sources files
SRCS_NAME = bfs.c \
			get_n_steps.c \
			gnl_buff.c \
			main.c \
			print_line.c \
			print_way.c \
			search.c \
			solve.c \
			sort.c \
			struct_array_dynamic.c \
			struct_buff_dynamic.c \
			struct_coordinates.c \
			struct_farm.c \
			struct_node.c \
			struct_queue.c \
			struct_way.c \
			support.c \
			valid_coordinates.c \
			valid_line.c \
			valid_line_dashes.c \
			valid_map.c \
			valid_node.c \
			valid_node_names.c \
			valid_number.c \
			way_rebuild.c
SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR),$(SRCS_NAME))

#includes
INCLUDES_NAME = lem_in.h
INCLUDES_DIR = ./includes/
INCLUDES = $(addprefix $(INCLUDES_DIR),$(INCLUDES_NAME))

#objects
OBJS_DIR = ./obj/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR),$(OBJS_NAME))

#libft
LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_NAME))

LIBRARIES_VS = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
INCLUDES_VS = -I$(HEADERS_DIRECTORY) -I$(LIBFT_DIR) -I$(MINILIBX_HEADERS)

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIR)

HEADERS_LIST = v_lem_in.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./srcs_visualisation/
SRCS_VISUAL = v_dynamic_array.c main.c v_steps.c v_draw.c\
	v_check_links.c v_checks.c v_press.c v_find_xy.c v_move_xy.c\
	v_ft_strcpy_no_spaces.c v_mallocs.c v_parsing.c v_read_map.c\
	v_vert_to_graph_all.c v_vert.c v_write_links.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SRCS_VISUAL))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SRCS_VISUAL))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

#color
GREEN = \033[0;32m
RED = \033[0;31m
EOC = \033[m
RESET = \033[0m

all: $(NAME) $(NAME_VS)

$(NAME): $(OBJS) $(LIBFT_DIR) $(INCLUDES)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(EOC)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -I $(INCLUDES_DIR) -o $@ -c $<

$(NAME_VS): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES_VS) $(INCLUDES_VS) $(OBJECTS) -o $(NAME_VS)
	@echo "$(GREEN)$(NAME) visualisation created$(EOC)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES_VS) $< -o $@

$(MINILIBX):
	@make -C $(MINILIBX_DIR)

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean
	@/bin/rm -rf $(OBJS_DIR)
	@echo "$(RED)✗ Deletion of object files$(EOC)"

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(NAME_VS)
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)
	@echo "$(RED)✗ Deletion of $(NAME)$(EOC)"

re: fclean all
