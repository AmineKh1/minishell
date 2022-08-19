/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:17:52 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/19 13:04:50 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>

t_list *putToken(t_list *lexer)
{
    t_list *h;
    h = lexer;
    while(lexer)
    {
        if(lexer->type == - 1)
            lexer = STRING;
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
    }
    return h;
}
t_list *lexer_list(t_list *lexer)
{
    t_list *h;
	t_list *fre;
	fre = NULL;
    h = lexer;
    lexer = putToken(lexer);
    while (lexer != NULL)
    {
    if ((ft_memcmp(lexer->content, "|", 2) == 0 || ft_memcmp(lexer->content, ">>", 3) == 0 || ft_memcmp(lexer->content, ">", 2) == 0 || ft_memcmp(lexer->content, "<", 2) == 0 || ft_memcmp(lexer->content, "<<", 3) == 0) && lexer->next != NULL && lexer->next->type == STRING)
	{
		fre = lexer->next;
		lexer->content = lexer->next->content;
		lexer->next = lexer->next->next;
		// ft_lstdelone(fre);
	}
	printf("%s\n", lexer->content);
	printf("%d\n", lexer->type);
	lexer = lexer->next;
	}
	lexer = h;
    return lexer;
	// i need to write a function that take as argment my linked list and the node that i wanna delete then rebuild my linked list withut the node
	// while(1);
}