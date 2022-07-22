/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:47:49 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/10 21:47:50 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	*k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			k = (s + i);
		i++;
	}
	if (c == 0)
		return (s + i);
	if (k != 0)
		return (k);
	return (0);
}
