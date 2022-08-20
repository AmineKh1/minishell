/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:17:52 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/20 21:02:09 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *putToken(t_list *lexer)
{
    t_list *h;
    h = lexer;
    while(lexer)
    {
        if(lexer->type == - 1)
            lexer->type = STRING;
        else if (ft_memcmp(lexer->content, "|", 2) == 0)
		    lexer->type = (int)PIPE;
	    else if (ft_memcmp(lexer->content, ">>", 3) == 0)
		    lexer->type = (int)OUTP;
	    else if (ft_memcmp(lexer->content, ">", 2) == 0)
		    lexer->type= (int)OUT;
	    else if (ft_memcmp(lexer->content, "<", 2) == 0)
		    lexer->type = (int)IN;
	    else if (ft_memcmp(lexer->content, "<<", 3) == 0)
		    lexer->type = (int)HERDOC;
	    else
		    lexer->type = (int)STRING;
		lexer = lexer->next;
    }
    return h;
}
t_list *lexerList(t_list *lexer)
{
    t_list *h;
	t_list *fre;
	fre = NULL;
    h = lexer;
    lexer = putToken(lexer);
	if (lexer != NULL && lexer->type == PIPE)
		{
		printf("minishell: syntax error near unexpected token`%s'\n", lexer->content);
		ex = 1;
		ft_lstclear(&h);
		return NULL;
		}
    while (lexer != NULL)
    {
		if ((lexer->type == OUTP || lexer->type == OUT || lexer->type == IN || lexer->type == HERDOC))
		{
			if (lexer->next == NULL)
			{
				printf("minishell: syntax error near unexpected token`newline'\n");
				ex = 1;
				ft_lstclear(&h);
				return NULL;
			}
			else if (lexer->next->type != 6)
			{
				printf("minishell: syntax error near unexpected token`%s'\n", lexer->next->content);
				ex = 1;
				ft_lstclear(&h);
				return NULL;
			}
			fre = lexer->next;
			free(lexer->content);
			lexer->content = lexer->next->content;
			lexer->next = lexer->next->next;
			free(fre);
			
		}
		else if (lexer->type == PIPE && ((lexer->next != NULL && lexer->next->type == PIPE) || lexer->next == NULL))
		{
				printf("minishell: syntax error near unexpected token`%s'\n", lexer->content);
				ex = 1;
				ft_lstclear(&h);
				return NULL;
		}
		// printf("%s\n", lexer->content);
		// printf("%d\n", lexer->type);
		lexer = lexer->next;
	}
	lexer = h;
	// ex = 0;
    return lexer;
	// i need to write a function that take as argment my linked list and the node that i wanna delete then rebuild my linked list withut the node
	// while(1);
}