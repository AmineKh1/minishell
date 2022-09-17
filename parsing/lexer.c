/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:17:52 by akhouya           #+#    #+#             */
/*   Updated: 2022/09/07 22:47:01 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list	*put_token(t_list *lexer)
{
	t_list	*h;

	h = lexer;
	while (lexer)
	{
		if (lexer->type == -1)
			lexer->type = STRING;
		else if (lexer->type == 7)
			lexer->type = HERDOCX;
		else if (ft_memcmp(lexer->content, "|", 2) == 0)
			lexer->type = (int)PIPE;
		else if (ft_memcmp(lexer->content, ">>", 3) == 0)
			lexer->type = (int)OUTP;
		else if (ft_memcmp(lexer->content, ">", 2) == 0)
			lexer->type = (int)OUT;
		else if (ft_memcmp(lexer->content, "<", 2) == 0)
			lexer->type = (int)IN;
		else if (ft_memcmp(lexer->content, "<<", 3) == 0)
			lexer->type = (int)HERDOC;
		else
			lexer->type = (int)STRING;
		lexer = lexer->next;
	}
	return (h);
}

static int	skip_node(t_list *lexer, t_list *h, t_list *fre)
{
	if (lexer->next == NULL)
	{
		ft_putendl_fd(ERROR_NEWLINE, 2);
		g_glb.ex = 258;
		g_glb.er = 69;
		ft_lstclear(&h);
		return (1);
	}
	else if (lexer->next->type != 6)
	{
		ft_putstr_fd(ERROR_TOKEN, 2);
		ft_putstr_fd(lexer->next->content, 2);
		ft_putendl_fd("'", 2);
		g_glb.ex = 258;
		g_glb.er = 69;
		ft_lstclear(&h);
		return (1);
	}
	fre = lexer->next;
	free(lexer->content);
	lexer->content = lexer->next->content;
	lexer->next = lexer->next->next;
	free(fre);
	return (0);
}

static int	token_codition_cut(t_list *lexer)
{
	if (lexer->type == OUTP || lexer->type == OUT || lexer->type == IN
		|| lexer->type == HERDOC || lexer->type == HERDOCX)
		return (0);
	return (1);
}

static void	print_error_t(t_list *lexer, t_list *h)
{
	ft_putstr_fd("minishell: syntax error near unexpected token`", 2);
	ft_putstr_fd(lexer->content, 2);
	ft_putstr_fd("'\n", 2);
	g_glb.ex = 258;
	g_glb.er = 69;
	ft_lstclear(&h);
}

t_list	*lexer_list(t_list *lexer)
{
	t_list	*h;
	t_list	*fre;

	fre = NULL;
	h = lexer;
	lexer = put_token(lexer);
	while (lexer != NULL)
	{
		if (token_codition_cut(lexer) == 0 && skip_node(lexer, h, fre) == 1)
			return (NULL);
		else if (lexer->type == PIPE && ((lexer->next != NULL
					&& lexer->next->type == PIPE) || lexer->next == NULL
				|| lexer == h))
		{
			print_error_t(lexer, h);
			return (NULL);
		}
		lexer = lexer->next;
	}
	lexer = h;
	return (lexer);
}
