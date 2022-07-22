/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:57:39 by akhouya           #+#    #+#             */
/*   Updated: 2021/11/16 22:07:10 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrarray(char const *s, char c)
{
	int	i;
	int	j;
	int	nbrstr;

	i = 0;
	nbrstr = 0;
	while (s[i])
	{
		j = i;
		while (s[j] != c && s[j])
			j++;
		if (j > i)
		{
			i = j;
			nbrstr++;
			continue ;
		}
		i++;
	}
	return (nbrstr);
}

void	frealltab(char **str)
{
	int	l;

	l = 0;
	while (str[l])
	{
		free(str[l++]);
	}
	return ;
}

static int	checkimpli(char const *s, char **str, char c)
{
	int	i;
	int	j;
	int	l;

	i = -1;
	l = 0;
	while (s[++i])
	{
		j = i;
		while (s[j] != c && s[j])
			j++;
		if (j > i)
		{
			str[l] = ft_substr(&s[i], 0, j - i);
			if (!str[l++])
			{
				frealltab(str);
				return (1);
			}
			i = j - 1;
		}
	}
	str[l] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	if (!s)
		return (NULL);
	str = malloc((nbrarray(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = checkimpli(s, str, c);
	if (i == 1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
