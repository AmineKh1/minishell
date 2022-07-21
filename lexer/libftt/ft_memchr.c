/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:06:02 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/10 23:06:03 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*k;
	unsigned char	*str;

	str = (unsigned char *) s;
	k = NULL;
	while (n-- > 0)
	{
		if (*str == (unsigned char) c)
		{
			k = str;
			break ;
		}
		str++;
	}
	return (k);
}
