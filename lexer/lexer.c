/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:17:52 by akhouya           #+#    #+#             */
/*   Updated: 2022/07/06 14:17:52 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdio.h>
int main(int argc, char **argv)
{
    t_list *lexer;
    t_list *add;
    int i;

    i = 1;
    add = NULL;
    while(i < argc)
    {
        add = NULL;
        if (i == 1)
            lexer = ft_lstnew(argv[i]);
        else
        {
            add = ft_lstnew(argv[i]);
            ft_lstadd_back(&lexer, add);
        }
        i++;
    }
    t_list *h;
	t_list *fre;
	fre = NULL;
    h = lexer;
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
	// i need to write a function that take as argment my linked list and the node that i wanna delete then rebuild my linked list withut the node
	// while(1);
}