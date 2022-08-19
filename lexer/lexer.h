/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:09:26 by akhouya           #+#    #+#             */
/*   Updated: 2022/08/19 13:06:14 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "../libft/libft.h"
# define PIPE 1
# define IN 2
# define OUT 3
# define HERDOC 4
# define OUTP 5
# define STRING 6
t_list *lexer_list(t_list *lexer);
#endif