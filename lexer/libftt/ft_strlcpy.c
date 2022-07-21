/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:52:03 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/10 21:52:04 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	l;

	l = size;
	count = 0;
	while (size-- > 1 && *src)
	{
		*dst++ = *src++;
		count++;
	}
	while (*src++)
		count++;
	if (l > 0)
		*dst = '\0';
	return (count);
}
