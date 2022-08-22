/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:05:35 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/22 11:16:35 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char **stringTable_push(char **str, char *s)
{
    int i;
    char **ret;
    i = 0;
    ret = NULL;
    if(str == NULL)
    {
        ret = malloc(sizeof(char *) * 2);
        if (!ret)
            return NULL;
        ret[0] = ft_strdup(s);
        ret[1] = 0;
        // free(s);
        return ret;
    }
    
    while (str[i++]);
    ret = malloc((i + 1) * sizeof(char *));
    if (!ret)
        return NULL;
        
    i = -1;
    while(str[++i])
        ret[i] = ft_strdup(str[i]);
    ret[i++] = ft_strdup(s);
    ret[i] = 0;
    frealltab(str);
    free(str);
    return ret;
}
t_minishell *parser_job(t_list *lst)
{
    t_minishell *list;
    t_minishell *tmpM;
    char **command;
    t_files *in;
    t_files *out;
    t_files *tmpF;
    
    list = NULL;
    command = NULL;
    in = NULL;
    out = NULL;
    tmpF = NULL;
    tmpM = NULL;
    
    while(lst)
    {
        if (lst->type == STRING)
            command = stringTable_push(command, lst->content);
        else if (lst->type == IN || lst->type == HERDOC || lst->type == HERDOCX)
        {
            tmpF = ft_lstnew_file(lst->content, lst->type);
            ft_lstadd_back_files(&in, tmpF);
            tmpF = NULL;
        }
        else if (lst->type == OUT || lst->type == OUTP)
        {
            tmpF = ft_lstnew_file(lst->content, lst->type);
            ft_lstadd_back_files(&out, tmpF);
            tmpF = NULL;
        }
        else
        {
            tmpM = ft_lstnew_minishell(command, in, out);
            ft_lstadd_back_minishell(&list, tmpM);
            in = NULL;
            out = NULL;
            tmpM = NULL;
            command = NULL;
        }
        lst = lst->next;
    }
    tmpM = ft_lstnew_minishell(command, in, out);
    ft_lstadd_back_minishell(&list, tmpM);
    in = NULL;
    out = NULL;
    tmpM = NULL;
    command = NULL;
    return list;
}