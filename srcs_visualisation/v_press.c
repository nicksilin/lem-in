/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_press.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/12 16:32:07 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

void	ft_press_right(t_graph *graph)
{
	int		i;

	ft_black_rooms(graph);
	if (graph->steps)
	{
		graph->steps = graph->steps->next;
		if (graph->steps == NULL)
			exit(0);
		i = 0;
		while (i < graph->indexes + 1)
		{
			if (graph->steps->rooms[i] == 1)
				graph->vis->color = ANT;
			else if (i == graph->start)
				graph->vis->color = START;
			else if (i == graph->end)
				graph->vis->color = FINISH;
			else if (graph->visit[i] == 0)
				graph->vis->color = 0x696969;
			ft_draw_room(graph->vis, graph->x[i], graph->y[i]);
			graph->vis->color = 0xffffff;
			i++;
		}
	}
}

void	ft_press_left(t_graph *graph)
{
	int i;

	ft_black_rooms(graph);
	if (graph->steps->prev)
	{
		graph->steps = graph->steps->prev;
		i = 0;
		while (i < graph->indexes + 1)
		{
			if (graph->steps->rooms[i] == 1)
				graph->vis->color = ANT;
			else if (i == graph->start)
				graph->vis->color = START;
			else if (i == graph->end)
				graph->vis->color = FINISH;
			else if (graph->visit[i] == 0)
				graph->vis->color = 0x696969;
			ft_draw_room(graph->vis, graph->x[i], graph->y[i]);
			graph->vis->color = 0xffffff;
			i++;
		}
	}
}

int		ft_press(int key, t_graph *graph)
{
	if (key == 53)
		exit(0);
	else if (key == 124)
		ft_press_right(graph);
	else if (key == 123)
		ft_press_left(graph);
	else
	{
		write(1, "USAGE: right arrow: next step; ", 31);
		write(1, "left arrow:previous step; esc: exit\n", 36);
	}
	return (1);
}

void	ft_change_coords(t_graph *graph)
{
	ft_change_x(graph);
	ft_change_y(graph);
}

void	ft_print_map(t_graph *graph)
{
	graph->vis = (t_vis *)malloc(sizeof(t_vis));
	graph->vis->color = 0xffffff;
	graph->vis->mlx_ptr = mlx_init();
	graph->vis->win_ptr = mlx_new_window(graph->vis->mlx_ptr, 1200,
			800, "lem-in");
	ft_change_coords(graph);
	ft_print_links(graph, graph->vis);
	graph->vis->i = 0;
	graph->vis->index = graph->indexes + 1;
	while (graph->vis->index)
	{
		if (graph->vis->i == graph->start)
			graph->vis->color = START;
		else if (graph->vis->i == graph->end)
			graph->vis->color = FINISH;
		else if (graph->visit[graph->vis->i] == 0)
			graph->vis->color = 0x696969;
		ft_draw_room(graph->vis, graph->x[graph->vis->i],
				graph->y[graph->vis->i]);
		graph->vis->i++;
		graph->vis->index--;
		graph->vis->color = 0xffffff;
	}
	mlx_key_hook(graph->vis->win_ptr, ft_press, graph);
	mlx_loop(graph->vis->mlx_ptr);
}
