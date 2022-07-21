/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:12:50 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/15 18:25:11 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	calcule(const char *nptr, int signe)
{
	unsigned long	r;
	unsigned long	l;

	l = 9223372036854775808UL;
	r = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		r = r * 10;
		if (r > 9223372036854775807 && signe == 1)
			return (-1);
		if (r > l && signe == -1)
			return (0);
		r = r + (*nptr - '0');
		nptr++;
	}
	return ((int)r * signe);
}

int	ft_atoi(const char *nptr)
{
	unsigned long	r;
	int				signe;

	r = 0;
	signe = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\v' || *nptr == '\r'
		|| *nptr == '\n' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
	{
		signe = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	return (calcule(nptr, signe));
}
