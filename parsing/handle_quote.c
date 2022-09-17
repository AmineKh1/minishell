/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:26:32 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/07 22:55:23 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	node_tokens(t_quote *q, char *cmd)
{
	if (cmd[q->i] == '|')
	{
		g_glb.ex = 0;
		g_glb.er = 0;
	}
	q->j = q->i;
	q->i++;
	if (cmd[q->i] != '|' && cmd[q->i] == cmd[q->i - 1])
		q->i++;
	q->str = ft_substr(&cmd[q->j], 0, q->i - q->j);
	q->tmp = ft_lstnew(q->str);
	q->tmp->type = 0;
	ft_lstadd_back(&q->list_cmd, q->tmp);
	q->str = NULL;
}

int	handle_er_expend(char *cmd, t_quote *q, t_env *env)
{
	if (cmd[q->i] == '\0')
	{
		write(2, "minishell: syntax error need end `", 34);
		write(2, &q->c, 1);
		write(2, "`\n", 2);
		g_glb.ex = 258;
		ft_lstclear(&q->list_cmd);
		return (1);
	}
	q->str = ft_substr(&cmd[q->j], 0, q->i - q->j);
	if (q->c == '"' && (q->list_cmd == NULL
			|| ft_memcmp(q->tmp->content, "<<", 3) != 0))
		q->str = expend_add(q->str, env);
	if (q->list_cmd != NULL && ft_memcmp(q->tmp->content, "<<", 3) == 0)
		q->tmp->type = HERDOCX;
	q->tmp = ft_lstnew(q->str);
	q->i++;
	return (0);
}

int	quote_conditions(char *cmd, t_quote *q, t_env *env)
{
	q->j = q->i + 1;
	q->c = cmd[q->i];
	q->i++;
	while (cmd[q->i] && cmd[q->i] != q->c)
		q->i++;
	if (handle_er_expend(cmd, q, env) == 1)
		return (1);
	if (is_space(cmd[q->i]) == 0 || !cmd[q->i] || cmd[q->i] == '<'
		|| cmd[q->i] == '|' || cmd[q->i] == '>')
		q->tmp->type = -1;
	else
		q->tmp->type = 1;
	ft_lstadd_back(&q->list_cmd, q->tmp);
	q->str = NULL;
	return (0);
}

void	normal_condition(char *cmd, t_quote *q, t_env *env)
{
	if (is_space(cmd[q->i]) == 0)
		q->i++;
	q->j = q->i;
	while (cmd [q->i] && is_space(cmd[q->i]) != 0 && cmd[q->i] != '"'
		&& cmd[q->i] != '\'' && cmd[q->i] != '<'
		&& cmd[q->i] != '|' && cmd[q->i] != '>')
		q->i++;
	q->str = ft_substr(&cmd[q->j], 0, q->i - q->j);
	if (q->list_cmd == NULL || ft_memcmp(q->tmp->content, "<<", 3) != 0)
		q->str = expend_add(q->str, env);
	q->ss = ft_split(q->str, ' ');
	q->icr = 0;
	while (q->ss[q->icr] != 0)
	{
		q->tmp = ft_lstnew(q->ss[q->icr]);
		if ((cmd[q->i] == '\'' || cmd[q->i] == '"') && q->ss[q->icr + 1] == 0)
			q->tmp->type = 1;
		else
			q->tmp->type = 0;
		ft_lstadd_back(&q->list_cmd, q->tmp);
		q->icr++;
	}
	free(q->ss);
	free(q->str);
	q->str = NULL;
}

t_list	*command_string(char *cmd, t_env *env)
{
	t_quote	q;

	init_value(&q);
	if (!cmd)
		return (NULL);
	while (cmd[q.i])
	{
		if (cmd[q.i] == '<' || cmd[q.i] == '|' || cmd[q.i] == '>')
			node_tokens(&q, cmd);
		else if (cmd[q.i] == '\'' || cmd[q.i] == '"')
		{
			if (quote_conditions(cmd, &q, env) == 1)
				return (NULL);
		}
		else
			normal_condition(cmd, &q, env);
	}
	return (q.list_cmd);
}
