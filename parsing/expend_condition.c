/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_condition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:32:40 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/07 22:46:05 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	exit_code(char *str, t_expend *x)
{
	x->s1 = ft_substr(&str[x->j], 0, x->i - x->j);
	x->i++;
	x->ret = ft_strjoin(x->ret, x->s1);
	x->i++;
	x->j = x->i;
	if (g_glb.er == 69)
		x->s1 = ft_itoa(g_glb.ex);
	else
		x->s1 = ft_itoa(g_glb.ex % 256);
	x->ret = ft_strjoin(x->ret, x->s1);
}

void	expend_number(char *str, t_expend *x, t_env *env)
{
	x->s1 = ft_substr(&str[x->j], 0, x->i - x->j);
	x->i++;
	x->ret = ft_strjoin(x->ret, x->s1);
	x->j = x->i;
	x->i++;
	x->s1 = ft_substr(&str[x->j], 0, x->i - x->j);
	x->j = x->i;
	x->s1 = value_ofd(x->s1, env);
	x->ret = ft_strjoin(x->ret, x->s1);
}

void	expend_envp(char *str, t_expend *x, t_env *env)
{
	x->s1 = ft_substr(&str[x->j], 0, x->i - x->j);
	x->i++;
	x->ret = ft_strjoin(x->ret, x->s1);
	x->j = x->i;
	while (is_endd(str[x->i]) != 0)
		x->i++;
	x->s1 = ft_substr(&str[x->j], 0, x->i - x->j);
	x->j = x->i;
	x->s1 = value_ofd(x->s1, env);
	x->ret = ft_strjoin(x->ret, x->s1);
}
