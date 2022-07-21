/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:52:05 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/16 23:22:23 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lentdst;
	size_t	lentsrc;
	size_t	i;

	i = 0;
	lentsrc = ft_strlen(src);
	if (dst == NULL && size == 0)
		lentdst = 0;
	else
		lentdst = ft_strlen(dst);
	if (size < lentdst + 1)
		return (lentsrc + size);
	while (i < size - lentdst - 1 && src[i])
	{
		dst[lentdst + i] = src[i];
		i++;
	}
	dst[lentdst + i] = '\0';
	return (lentsrc + lentdst);
}
