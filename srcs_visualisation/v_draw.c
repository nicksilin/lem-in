/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:57:43 by jgroleo           #+#    #+#             */
/*   Updated: 2020/03/12 16:32:03 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v_lem_in.h"

void	ft_draw_line(float x1, float y1, t_vis *vis)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = x1 - vis->x;
	y_step = y1 - vis->y;
	max = MAX(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(vis->x - x1) || (int)(vis->y - y1))
	{
		mlx_pixel_put(vis->mlx_ptr, vis->win_ptr, vis->x, vis->y, vis->color);
		vis->x += x_step;
		vis->y += y_step;
	}
}

void	ft_draw_circle(t_vis *vis, int y, int x1, int y1)
{
	int		x;
	int		delta;

	x = 0;
	delta = 1 - 2 * y;
	vis->error = 0;
	while (y >= 0)
	{
		mlx_pixel_put(vis->mlx_ptr, vis->win_ptr, x1 + x, y1 + y, vis->color);
		mlx_pixel_put(vis->mlx_ptr, vis->win_ptr, x1 + x, y1 - y, vis->color);
		mlx_pixel_put(vis->mlx_ptr, vis->win_ptr, x1 - x, y1 + y, vis->color);
		mlx_pixel_put(vis->mlx_ptr, vis->win_ptr, x1 - x, y1 - y, vis->color);
		vis->error = 2 * (delta + y) - 1;
		if ((delta < 0) && (vis->error <= 0))
		{
			delta += 2 * ++x + 1;
			continue;
		}
		if ((delta > 0) && (vis->error > 0))
		{
			delta -= 2 * --y + 1;
			continue;
		}
		delta += 2 * (++x - y--);
	}
}

void	ft_draw_room(t_vis *vis, int x1, int y1)
{
	int		flag;

	flag = 0;
	if (vis->color == START || vis->color == FINISH)
		flag = 1;
	ft_draw_circle(vis, 1, x1, y1);
	ft_draw_circle(vis, 2, x1, y1);
	ft_draw_circle(vis, 3, x1, y1);
	ft_draw_circle(vis, 4, x1, y1);
	ft_draw_circle(vis, 5, x1, y1);
	ft_draw_circle(vis, 6, x1, y1);
	ft_draw_circle(vis, 7, x1, y1);
	if (flag == 1)
	{
		ft_draw_circle(vis, 8, x1, y1);
		ft_draw_circle(vis, 9, x1, y1);
		ft_draw_circle(vis, 10, x1, y1);
		ft_draw_circle(vis, 11, x1, y1);
	}
}

void	ft_print_links(t_graph *graph, t_vis *vis)
{
	int		index;
	int		j;
	int		id;
	int		n;

	j = 0;
	index = graph->indexes + 1;
	while (index)
	{
		n = 0;
		id = graph->connects[j]->id;
		while (id)
		{
			ft_help_print(graph, vis, n, j);
			id--;
			n++;
			graph->vis->color = 0xffffff;
		}
		j++;
		index--;
	}
}

void	ft_black_rooms(t_graph *graph)
{
	int		i;

	i = 0;
	while (i < graph->indexes + 1)
	{
		if (i == graph->start)
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
