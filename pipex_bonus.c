/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:03:08 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/07 08:49:22 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_bash	*bash;
	int		len;
	int		**fds;

	if (ac < 5)
		custom_error("Program needs more arguments", 1);
	bash = malloc(sizeof(t_bash));
	if (!bash)
		custom_error("Memory Allocation", 1);
	heredoc_check(ac, av, &bash);
	if (bash->herdoc->status)
		bash->cmd = fill_cmds(ac, av, env, 3);
	else
		bash->cmd = fill_cmds(ac, av, env, 2);
	len = len_cmds(bash->cmd);
	bash->env = env;
	fds = pipe_feach_proc(len - 1);
	herdoc_main(av, &bash);
	multi_pipes(bash, av, &fds);
	return (0);
}
