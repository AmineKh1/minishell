/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:02:34 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/13 14:59:24 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr_d;
	char	*ptr_s;

	i = 0;
	ptr_d = (char *) dest;
	ptr_s = (char *) src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*ptr_d++ = *ptr_s++;
		i++;
	}
	return (dest);
}
