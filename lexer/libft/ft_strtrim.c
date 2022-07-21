/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:47:44 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/15 18:51:02 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	begin(char const *s1, char const *set)
{
	int	i;
	int	l;
	int	h;

	h = 0;
	i = 0;
	while (s1[i])
	{
		l = 0;
		while (set[l])
		{
			if (set[l] == s1[i])
				h++;
			l++;
		}
		if (h == 0)
			return (i);
		i++;
		h = 0;
	}
	return (0);
}

static int	end(char const *s1, char const *set)
{
	int	i;
	int	l;
	int	h;

	h = 0;
	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		l = 0;
		while (set[l])
		{
			if (set[l] == s1[i])
				h++;
			l++;
		}
		if (h == 0)
			return (i);
		i--;
		h = 0;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		b;
	int		e;
	char	*ptr;

	if (!s1)
		return (NULL);
	b = begin(s1, set);
	e = end(s1, set);
	e = e - b;
	if (b == e)
		return (ft_strdup(""));
	ptr = ft_substr(s1, b, ++e);
	return (ptr);
}
