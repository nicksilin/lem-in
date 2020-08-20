/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_lem_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:06:30 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/12 16:33:31 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_LEM_IN_H
# define V_LEM_IN_H

# define MAX(a, b) (a > b ? a : b)
# define FINISH 0xFF4500
# define START 0x008000
# define ANT 0xFF0000
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct			s_vis
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					color;
	int					i;
	int					index;
	int					error;
	float				x;
	float				y;
}						t_vis;

typedef struct			s_array
{
	int					*data;
	unsigned			id;
	unsigned			size;
}						t_array;

t_array					*create(unsigned size);
int						add(t_array *array, int data);
int						del(t_array *array, int *data);
int						resize(t_array *array, unsigned new_size);

typedef struct			s_vertices
{
	char				*name;
	int					x;
	int					y;
	int					index;
	t_array				*adjacent;
	int					haveadj;
	struct s_vertices	*next;
}						t_vertices;

typedef struct			s_steps
{
	int					*rooms;
	struct s_steps		*next;
	struct s_steps		*prev;
}						t_steps;

typedef struct			s_graph
{
	int					start;
	int					end;
	t_array				**connects;
	char				**name;
	int					*x;
	int					*y;
	int					*visit;
	int					ants;
	int					indexes;
	struct s_vis		*vis;
	struct s_steps		*steps;
	int					space;
	int					transfer;
}						t_graph;

void					ft_print_map(t_graph *graph);
int						ft_press(int key, t_graph *graph);
void					ft_press_left(t_graph *graph);
void					ft_press_right(t_graph *graph);
void					ft_black_rooms(t_graph *graph);
void					ft_print_links(t_graph *graph, t_vis *vis);
void					ft_change_y(t_graph *graph);
void					ft_move_y_to_start2(t_graph *graph, long long int min,
		long long int max);
void					ft_move_negative_y2(t_graph *graph, long long int min,
		long long int max);
void					ft_centre_y(t_graph *graph, int min, int max);
void					ft_change_x(t_graph *graph);
void					ft_move_x_to_start2(t_graph *graph, long long int min,
		long long int max);
void					ft_move_negative_x2(t_graph *graph, long long int min,
		long long int max);
void					ft_centre_x(t_graph *graph, long long int min,
		long long int max);
long long int			ft_find_max_x(t_graph *graph);
long long int			ft_find_min_x(t_graph *graph);
long long int			ft_find_max_y(t_graph *graph);
long long int			ft_find_min_y(t_graph *graph);
void					ft_draw_room(t_vis *vis, int x1, int y1);
void					ft_draw_circle(t_vis *vis, int y, int x1, int y1);
void					ft_draw_line(float x1, float y1, t_vis *vis);
int						mod(int i);
int						ft_find_end(t_vertices *vert, t_vertices *tmp,
		t_graph *graph, int *counter);
int						ft_check_links(char *str, t_vertices *vert);
int						ft_parse_link(char *str, t_vertices *vert);
int						ft_find_room(char *str, int i, t_vertices *vert);
int						ft_check_links_onedash(char *str, t_vertices *vert);
int						ft_check_spaces(char *str);
int						ft_check_dash(char *str);
int						ft_name_not_dub(t_vertices *vert, char *value);
int						resize(t_array *array, unsigned new_size);
void					ft_copy(int *to, const int *from, unsigned size);
int						del(t_array *array, int *data);
int						add(t_array *array, int data);
t_array					*create(unsigned size);
char					*ft_strcpy_no_spaces(char *dst, const char *src, int i);
void					ft_refresh_vert(t_vertices *vert);
void					ft_refresh_graph(t_graph *graph);
int						ft_malloc_vert(t_vertices **vert);
int						ft_malloc_graph(t_graph **graph);
int						ft_start_parsing(t_graph *graph);
int						ft_check_map(char *map, t_graph *graph,
		t_vertices *vert);
int						ft_help_l(t_graph *graph, t_vertices *vert);
int						ft_push_steps(char *str, t_graph *graph);
t_steps					*ft_last_step(t_steps *step);
t_steps					*ft_create_new_step(char *str, t_graph *graph);
int						ft_mark_rooms(int *istr, char *str, t_graph *graph);
int						ft_find_index(char *str, char **all, int j);
int						ft_strlen_space(char *str);
void					ft_fill_rooms_zero(int *str, int index);
int						ft_check_string(char *str, t_graph *graph,
		t_vertices *vert);
int						ft_check_string_2(char *str, t_graph *graph,
		t_vertices *vert);
int						ft_read_map(t_graph *graph, t_vertices *vert);
t_vertices				*vert_push_back(char *str, t_vertices *vert,
		t_graph *graph);
t_vertices				*ft_create_new_vert(char *str, t_graph *graph);
int						ft_add_info_in_vert(char *str, t_vertices *new);
t_vertices				*ft_last_vert(t_vertices *vert);
void					ft_vert_to_graph(t_vertices *vert, t_graph *graph);
void					ft_vert_to_graph_connects(t_vertices *vert,
		t_graph *graph);
void					ft_vert_to_graph_connects_help(t_array *from,
		t_array *to);
void					ft_vert_to_graph_names(t_vertices *vert,
		t_graph *graph);
void					ft_vert_to_graph_y(t_vertices *vert, t_graph *graph);
void					ft_vert_to_graph_x(t_vertices *vert, t_graph *graph);
int						ft_write_links(t_vertices *vert, char *x, char *y);
int						ft_find_ind(t_vertices *vert, char *i);
int						ft_add_adj_x(t_vertices *vert, int ind_x, int ind_y);
int						ft_add_adj_help(t_vertices *vert, int ind_x, int ind_y);
void					ft_change_coords(t_graph *graph);
void					ft_help_print(t_graph *graph, t_vis *vis, int n, int j);
int						ft_help_check(char *map, t_graph *graph,
		t_vertices *vert);

#endif
