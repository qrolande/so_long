/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:40:54 by qrolande          #+#    #+#             */
/*   Updated: 2021/09/09 19:40:56 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	ft_length(long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static char	*ft_printnbr(long nbr, char *res)
{
	if (nbr == 0)
		res[0] = '0';
	return (res);
}

char	*ft_itoa(int n)
{
	 long	nbr;
	 int	len;
	 char	*res;

	 nbr = n;
	 len = ft_length(nbr);
	 res = (char *)malloc(sizeof(char) * (len + 1));
	 if (res == NULL)
		return (NULL);
	res[len--] = '\0';
	ft_printnbr(nbr, res);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		res[len--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (res);
}
