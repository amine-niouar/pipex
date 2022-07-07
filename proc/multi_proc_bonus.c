/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_proc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:06:14 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/06 04:17:05 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	main_proc(int pipes_count, int ***cfds, int *procs)
{
	int	x;
	int	**fds;

	fds = *cfds;
	x = 0;
	while (x < pipes_count)
	{
		close(fds[x][0]);
		close(fds[x][1]);
		x++;
	}
	x = 0;
	while (x < pipes_count + 1)
	{
		waitpid(procs[x], 0, 0);
		x++;
	}
}

t_cmd	*get_cmd(t_cmd *cmd, int pos)
{
	int		i;
	t_cmd	*current;

	current = cmd;
	i = 0;
	while (current != 0)
	{
		if (i == pos)
			return (current);
		i++;
		current = current->next;
	}
	return (0);
}

void	exec_bash(t_bash *bash, int i)
{
	t_cmd	*current;
	int		status;

	current = get_cmd(bash->cmd, i);
	if (current->options[0] != 0)
		status = check_pass_path(current->options[0]);
	cmd_errror(current->correct_path);
	if (execve(current->correct_path, current->options, bash->env) == -1)
	{
		perror("");
		exit(1);
	}
}

void	more_mp(t_bash *bash, int ***fds, char **av, int i)
{
	int	len;

	len = len_cmds(bash->cmd);
	if (i == 0)
	{
		if (bash->herdoc->status)
			first_proc(fds, 0, bash->herdoc->tempo);
		else
			first_proc(fds, 0, av[1]);
	}
	else if ((i >= 1 && i < len - 1 && len > 2))
	{
		close_except(fds, len - 1, i - 1);
		medium_proc(fds, i);
	}
	else if (i == (len - 1))
	{
		if (bash->herdoc->status)
		{
			last_proc(fds, i, av[len + 3], 1);
			unlink(bash->herdoc->tempo);
		}
		else
			last_proc(fds, i, av[len + 2], 0);
	}
}

void	multi_pipes(t_bash *bash, char **av, int ***fds)
{
	int	len;
	int	*procs;
	int	i;

	len = len_cmds(bash->cmd);
	procs = malloc(sizeof(int) * len);
	if (!procs)
		custom_error("Memory Allocation", 1);
	i = -1;
	while (++i < len)
	{
		procs[i] = fork();
		if (procs[i] == 0)
		{
			if (i == 0)
				close_except_me(fds, len - 1, i);
			else if (i == (len - 1))
				close_except_me(fds, len - 1, i - 1);
			more_mp(bash, fds, av, i);
			exec_bash(bash, i);
		}
	}
	main_proc(len - 1, fds, procs);
	free(procs);
}
