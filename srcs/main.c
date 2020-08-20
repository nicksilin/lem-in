/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <fwiley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 09:46:40 by fwiley            #+#    #+#             */
/*   Updated: 2020/03/10 14:38:57 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_error(void)
{
	write(1, "\n", 1);
	write(2, "ERROR\n", 6);
}

int		main(void)
{
	t_buff		*buff;
	t_farm		*farm;

	buff = create_buff(BUFF_MEMORY);
	farm = create_farm();
	if (!valid_map(buff, farm) || !solve(farm))
		print_error();
	delete_buff(&buff);
	delete_farm(&farm);
	return (0);
}
