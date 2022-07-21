/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:51:51 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/16 21:59:05 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	j = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (ft_strlen(needle) == 0 || needle == haystack)
		return ((char *)haystack);
	while (haystack[j] && ft_strlen(needle) + j <= len)
	{
		if (ft_strncmp(&haystack[j], needle, ft_strlen(needle)) == 0)
			return ((char *)haystack + j);
		j++;
	}
	return (NULL);
}
