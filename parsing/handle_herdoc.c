/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:01:30 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/23 11:45:00 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	char *newl;
	
	str = ft_strdup("");
	s = readline("> ");	
	if(s != NULL)
	{
		
		newl = ft_strdup("\n");
		s = ft_strjoin(s, newl);
		herdoc = ft_strjoin_heredoc(lst->name, "\n");
		while (ft_strncmp(herdoc, s, ft_strlen(herdoc)) != 0)
		{
			// write(0, "> ", 2);
			str = ft_strjoin(str, s);
			s = readline("> ");
			if(s == NULL)
				break ;
			newl = ft_strdup("\n");
			s = ft_strjoin(s, newl);
		}
		if (s != NULL)
			free(s);
		free(herdoc);
		
	}
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
void	check_herdoc(t_minishell *lst, t_env *env)
{
    while(lst)
    {
		parcours_file(lst->in, env);
        lst = lst->next;
    }
	return ;
}