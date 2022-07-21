/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:06:20 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/16 22:00:30 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	nbrr(long n)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = n;
	if (n <= 0)
	{
		i++;
		nbr = -1 * n;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*nbr;
	long	nb;

	nb = (long) n;
	i = nbrr(n);
	if (n == 0)
		return (ft_strdup("0"));
	nbr = malloc(sizeof(char) * (i + 1));
	if (!nbr)
		return (NULL);
	nbr[i] = '\0';
	if (nb < 0)
	{
		nbr[0] = '-';
		nb = nb * -1;
	}
	while (i >= 0 && nb > 0)
	{
		nbr[i - 1] = nb % 10 + '0';
		i--;
		nb = nb / 10;
	}
	return (&nbr[0]);
}
