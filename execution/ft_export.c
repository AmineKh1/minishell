/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:28:08 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/10 15:42:22 by aabouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_and_free(t_export *p)
{
	int	j;

	while (p->exp)
	{
		printf("declare -x ");
		j = 0;
		while (p->exp[j])
		{
			if (p->exp[j] == '=')
			{
				if (!p->exp[j + 1] && p->dx == 1 && lord_save_me())
					break ;
				printf("=\"");
				while (p->exp[++j])
					printf("%c", p->exp[j]);
				printf("\"\n");
			}
			else
				printf("%c", p->exp[j++]);
		}
		free(p->exp);
		p++;
	}
}

void	sort_strings(t_export *p)
{
	int			i;
	int			j;
	int			len;
	t_export	tmp;

	i = 0;
	len = ft_strlen_export(p);
	if (len <= 1)
		return ;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(p[i].exp, p[j].exp) > 0)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	print_export(t_env *env)
{
	t_env		*tmp;
	int			i;
	t_export	*p;
	char		*tab;

	i = 0;
	tmp = env;
	p = malloc(sizeof(t_export) * (t_env_size(env) + 1));
	while (tmp)
	{
		if (tmp->dx == 1 || tmp->dx == 2)
		{
			tab = libft_strjoin(tmp->key, "=");
			p[i].exp = libft_strjoin(tab, tmp->value);
			p[i].dx = tmp->dx;
			free(tab);
			i++;
		}
		tmp = tmp->next;
	}
	p[i].exp = NULL;
	p[i].dx = -1;
	sort_strings(p);
	print_and_free(p);
	free(p);
}

int	ft_pos_char(char *tab, char c)
{
	int	i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_export(t_env **env, char **exp)
{
	int	index;
	int	i;

	i = 1;
	g_glb.ex = 0;
	if (!exp[i])
	{
		print_export(*env);
		return ;
	}
	while (exp[i])
	{
		index = ft_pos_char(exp[i], '=');
		if (!condition_name(exp[i]))
			export_error(exp[i]);
		else if (index != -1)
			export_equal(env, exp[i], index);
		else if (!check_existance(env, exp[i]))
			export_no_equal(env, exp[i]);
		i++;
	}
}
