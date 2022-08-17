/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:00:06 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/17 07:18:55 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
#include "libft/libft.h"
char	*get_next_line(int fd);
typedef struct s_files{
    char *name;
    int type;
    struct s_files *next;
}   t_files;


typedef struct s_minishell {
    char **command;
    t_files *in;
    t_files *out;
    struct s_minishell *next;
} t_minishell;


char	*get_next_line(int fd);

typedef struct s_env {
    char *key;
    char *value;
    struct s_env *next;
} t_env;
#endif