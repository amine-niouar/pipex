/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:12:36 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/06 01:39:59 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	**pipe_feach_proc(int len)
{
	int	i;
	int	**fds;

	fds = malloc(sizeof(int *) * len);
	if (!fds)
		custom_error("Memory Allocation", 1);
	i = -1;
	while (++i < len)
	{
		fds[i] = malloc(sizeof(int) * 2);
		if (!fds[i])
			custom_error("Memory Allocation", 1);
		pipe(fds[i]);
	}
	return (fds);
}

void	close_except_me(int ***cfds, int len_cmd, int except)
{
	int	i;
	int	**fds;

	fds = *cfds;
	i = -1;
	while (++i < len_cmd)
	{
		if (except != i)
		{
			close(fds[i][0]);
			close(fds[i][1]);
		}
	}
}

void	close_except(int ***cfds, int len_cmd, int except)
{
	int	i;
	int	**fds;

	fds = *cfds;
	i = -1;
	while (++i < len_cmd)
	{
		if (except != i)
			close(fds[i][0]);
		if (except + 1 != i)
			close(fds[i][1]);
	}
}
