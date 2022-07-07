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
    while (lexer != NULL)
    {
        printf("%s\n", lexer->content);
    // if (ft_memcmp(lexer->content, "|", 2) == 0 && lexer->next->type == STRING)
	// 	lexer->content = lexer->next->content;
	// else if (ft_memcmp(lexer->content, ">>", 3) == 0 && lexer->next->type == STRING)
	// 	lexer->content = lexer->next->content;
	// else if (ft_memcmp(lexer->content, ">", 2) == 0 && lexer->next->type == STRING)
	// 	lexer->content = lexer->next->content;
	// else if (ft_memcmp(lexer->content, "<", 2) == 0 && lexer->next->type == STRING)
	// 	lexer->content = lexer->next->content;
	// else if (ft_memcmp(lexer->content, "<<", 3) == 0 && lexer->next->type == STRING)
	// 	lexer->content = lexer->next->content;
	
	// ft_lstdelone(lexer->next);
    printf("%d\n", lexer->type);
    lexer = lexer->next;
    }
}