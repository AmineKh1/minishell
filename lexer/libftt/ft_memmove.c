/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:01:45 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/10 23:02:29 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptrd;
	char	*ptrs;

	ptrd = (char *) dest;
	ptrs = (char *) src;
	if (ptrd > ptrs)
	{
		while (n > 0)
		{
			*(ptrd + n - 1) = *(ptrs + n - 1);
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
