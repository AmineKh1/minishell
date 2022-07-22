/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:01:25 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/15 18:48:53 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	char	*ptr;

	ptr = (char *)buf;
	while (count > 0)
	{
		*ptr++ = ch;
		count--;
	}
	return (buf);
}
