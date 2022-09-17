/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhouya <akhouya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:29:15 by aabouzid          #+#    #+#             */
/*   Updated: 2022/09/07 23:07:32 by akhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	read_herdoc(char **cmd, t_files *tmp)
{
	int	k[2];

	if (cmd)
	{
		pipe(k);
		dup2(k[0], 0);
		if (tmp->name)
			write(k[1], tmp->name, ft_strlen(tmp->name));
		close(k[1]);
		close(k[0]);
	}
}

void	in_ptr_assign(t_files *tmp)
{
	int	fd;

	fd = open(tmp->name, O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR");
		exit(1);
	}
	if (tmp->next)
		close(fd);
	else
		dup2(fd, 0);
}

void	input_commande(t_files *in, t_extra ptr, char **cmd)
{
	t_files	*tmp;

	tmp = in;
	if (!in)
	{
		if (ptr.i != 0)
			dup2(ptr.tube[ptr.i - 1][0], 0);
		return ;
	}
	while (tmp)
	{
		if (tmp->type == IN)
			in_ptr_assign(tmp);
		else if (tmp->type == HERDOC && !tmp->next)
			read_herdoc(cmd, tmp);
		tmp = tmp->next;
	}
}

int	out_fd_assign(t_files *tmp, int	*fd)
{
	if (tmp->type == OUT)
		*fd = open(tmp->name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (tmp->type == OUTP)
		*fd = open(tmp->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*fd == -1)
	{
		perror("ERROR");
		return (0);
	}
	return (1);
}

void	output_commande(t_files *out, t_extra ptr)
{
	t_files	*tmp;
	int		fd;

	tmp = out;
	if (!out)
	{
		condition_dup(ptr);
		return ;
	}
	while (tmp)
	{
		if ((tmp->type == OUT || tmp->type == OUTP) && out_fd_assign(tmp, &fd))
		{
			if (tmp->next)
				close(fd);
			else
			{
				dup2(fd, 1);
				close(fd);
			}
		}
		else
			exit(1);
		tmp = tmp->next;
	}
}
