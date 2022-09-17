/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:01:30 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/11 14:42:07 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_heredoc(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[l++] = s1[i++];
	i = 0;
	while (s2[i])
		str[l++] = s2[i++];
	str[l] = '\0';
	return (&str[0]);
}

static void	open_herdoc(char *s, char **str, t_files *lst)
{
	char	*herdoc;

	s = ft_strjoin_heredoc(s, "\n");
	herdoc = ft_strjoin_heredoc(lst->name, "\n");
	while (ft_strncmp(herdoc, s, ft_strlen(herdoc)) != 0)
	{
		*str = ft_strjoin(*str, s);
		s = readline("> ");
		if (s == NULL)
		{
			free(*str);
			*str = NULL;
			break ;
		}
		s = ft_strjoin_heredoc(s, "\n");
	}
	if (s != NULL)
		free(s);
	free(herdoc);
}

void	herdoc(t_files *lst, t_env *env)
{
	char	*s;
	char	*str;

	str = ft_strdup("");
	s = readline("> ");
	if (s == NULL)
	{
		free(str);
		str = NULL;
	}
	else
		open_herdoc(s, &str, lst);
	free(lst->name);
	lst->name = str;
	if (lst->type == HERDOC)
		lst->name = expend_add(lst->name, env);
}

char	*add_char(char *tmp, char c)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(tmp) + 2));
	while (tmp[i])
	{
		new[i] = tmp[i];
		i++;
	}
	new[i] = c;
	i = i + 1;
	new[i] = 0;
	return (new);
}

char	*read_fd(int fd)
{
	char	c;
	int		r;
	char	*str;
	char	*tmp;

	str = ft_strdup("");
	r = read(fd, &c, 1);
	if (r)
	{
		while (r)
		{
			tmp = str;
			str = add_char(tmp, c);
			if (tmp)
				free(tmp);
			r = read(fd, &c, 1);
		}
	}
	else
	{
		free(str);
		str = NULL;
	}
	return (str);
}
