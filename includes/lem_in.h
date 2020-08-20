/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 09:47:31 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/12 13:58:37 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFF_MEMORY 4096
# define READ_SIZE 64
# define INT_LIMIT "2147483648"
# define FD_INPUT 0

# include <stdlib.h>
# include "../libft/libft.h"

/*
********************************************************************************
**		Struct		Dynamic array of pointers
********************************************************************************
*/

typedef struct		s_arr
{
	void			**data;
	size_t			size;
	size_t			mem;
}					t_arr;

t_arr				*create_arr(size_t mem);
void				delete_arr(t_arr **arr);
int					add_arr(t_arr *arr, void *val);

/*
********************************************************************************
**		Struct		Dynamic buffer of string
********************************************************************************
*/

typedef struct		s_buff
{
	char			*data;
	size_t			i;
	size_t			size;
	size_t			mem;
}					t_buff;

t_buff				*create_buff(size_t mem);
void				delete_buff(t_buff **buff);
int					resize_buff(t_buff *buff, size_t new_size);
void				copy_buff_line(t_buff *from, t_buff *to);

/*
********************************************************************************
**		Struct		Node of graph
********************************************************************************
*/

typedef struct		s_node
{
	char			*name;
	size_t			name_len;
	t_arr			*connect;
	struct s_node	*in;
	struct s_node	*out;
	unsigned		mark;
	int				ant;
}					t_node;

t_node				*create_node(char *name);
t_node				**create_node_array(size_t size, t_arr *name);
void				delete_node(t_node **node);
void				*delete_node_array(t_node ***array, size_t size);

/*
********************************************************************************
**		Struct		Ant farm
********************************************************************************
*/

typedef struct		s_farm
{
	int				ant;
	t_node			**node;
	t_node			*start;
	t_node			*end;
	size_t			n_node;
}					t_farm;

t_farm				*create_farm(void);
void				delete_farm(t_farm **farm);

/*
********************************************************************************
**		Struct		Queue BFS
********************************************************************************
*/

typedef struct		s_queue
{
	t_node			**node;
	size_t			*prev;
	size_t			i_begin;
	size_t			i_end;
	size_t			mem;
	char			*revs;
}					t_queue;

t_queue				*create_queue(size_t mem);
void				delete_queue(t_queue **queue);

/*
********************************************************************************
**		Struct		Way
********************************************************************************
*/

typedef struct		s_way
{
	t_node			**in;
	t_node			**out;
	size_t			size;
	size_t			mem;
}					t_way;

t_way				*create_way(size_t mem);
void				delete_way(t_way **way);

/*
********************************************************************************
**		Struct		Coordinates
********************************************************************************
*/

typedef struct		s_coordinates
{
	int				x;
	int				y;
}					t_coordinates;

t_coordinates		*create_coordinates(size_t size);
void				delete_coordinates(t_coordinates **coordinates);

/*
********************************************************************************
**					Support
********************************************************************************
*/

size_t				min(size_t nbr1, size_t nbr2);
size_t				max(size_t nbr1, size_t nbr2);
void				merge_sort_xy(t_coordinates *array, t_coordinates *buff,
					size_t left, size_t right);
void				merge_sort(void **arr, void **buff, size_t l, size_t r);
t_node				*find_node(char *name, t_farm *farm);

/*
********************************************************************************
**					GNL in dynamic buff
********************************************************************************
*/

int					gnl_buff(t_buff *buff);

/*
********************************************************************************
**					Validation
********************************************************************************
*/

int					is_number(t_buff *buff);
int					is_comment(t_buff *buff);
int					is_node(t_buff *buff, t_arr *name, t_farm *farm);
int					valid_names(t_buff *buff, t_arr *name, t_farm *farm);
int					valid_coordinates(t_farm *farm);
void				get_nodes(t_node **node1, t_node **node2, t_farm *farm,
					t_buff *buff);
int					valid_line(t_buff *buff, t_farm *farm);
int					valid_map(t_buff *buff, t_farm *farm);

/*
********************************************************************************
**					Solve
********************************************************************************
*/

int					bfs(t_farm *farm, t_queue *queue);
void				way_rebuilding(t_farm *farm, t_queue *queue);
size_t				len_way(t_farm *farm, t_node *node);
void				update_way_lens(t_farm *farm, t_arr *way_lens);
size_t				get_n_steps(t_farm *farm, t_arr *way_lens);
void				way_save(t_way *way, t_queue *queue);
void				delete_last_way(t_way *way, t_queue *queue);
void				print(t_node **way_start, size_t *way_len_arr, int n_way);
int					print_way(t_farm *farm, int n_way);
int					solve(t_farm *farm);

#endif
