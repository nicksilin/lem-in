/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwiley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:25:09 by fwiley            #+#    #+#             */
/*   Updated: 2019/09/21 19:57:47 by fwiley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int nb)
{
	size_t count;

	count = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count + 1);
}

static char		*get_itoa(char *itoa, int n, size_t i)
{
	if (n <= -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		n *= -1;
		itoa[0] = '-';
	}
	if (n >= 10)
		itoa = get_itoa(itoa, n / 10, i - 1);
	itoa[i] = ((n % 10) + '0');
	return (itoa);
}

char			*ft_itoa(int n)
{
	char	*itoa;
	size_t	len;

	if (n == -2147483648)
	{
		if (!(itoa = ft_strdup("-2147483648")))
			return (NULL);
		return (itoa);
	}
	len = get_len(n);
	if (!(itoa = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	itoa = get_itoa(itoa, n, len - 1);
	itoa[len] = '\0';
	return (itoa);
}
