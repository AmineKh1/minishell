/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluator_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:01:30 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/21 19:29:45 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	herdoc(t_files *lst, t_env *env)
{
	char	*s;
	char	*herdoc;
	char *str;

	str = ft_strdup("");
	write(0, "> ", 2);
	s = get_next_line(0);
	herdoc = ft_strjoin_heredoc(lst->name, "\n");
	while (ft_strncmp(herdoc, s, ft_strlen(herdoc)) != 0)
	{
		write(0, "> ", 2);
		str = ft_strjoin(str, s);
		s = get_next_line(0);
	}
	if (ft_strncmp("", s, 1) == 0)
	{
		free(s);
		free(herdoc);
		free(lst->name);
		lst->name = str;
		if(lst->type == HERDOC)
			lst->name = expend_add(lst->name, env);
		return ;
	}
	free(s);
	free(herdoc);
	free(lst->name);
	lst->name = str;
	if(lst->type == HERDOC)
		lst->name = expend_add(lst->name, env);
	return ;
}

void	parcours_file(t_files *lst, t_env *env)
{
	while(lst)
	{
		if(lst->type == HERDOC || lst->type == HERDOCX)
		{
			herdoc(lst, env);
			lst->type = HERDOC;
		}
		lst = lst->next;
	}
}
t_mnshellPa *check_herdoc(t_minishell *lst, t_env *env)
{
    t_mnshellPa *list;

	
    list = NULL;
    while(lst)
    {
		parcours_file(lst->in, env);
        lst = lst->next;
    }
	return list;
}