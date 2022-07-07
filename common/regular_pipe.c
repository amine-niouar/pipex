/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:11:09 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/06 03:32:12 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	custom_error(char *s, int mod)
{
	ft_putstr_endl(2, s);
	if (mod == 1)
		exit (1);
}

char	***fill_array_env(char **env)
{
	char	***array_env;

	array_env = malloc(sizeof(char **) * 3);
	if (!array_env)
		custom_error("Memory Allocation", 1);
	array_env[0] = get_path_env(env);
	array_env[1] = env;
	return (array_env);
}

void	regular_pipe(char **av, char ***array_env)
{
	int		fds[2];
	int		child_id;
	int		id;

	pipe(fds);
	id = fork();
	if (id == 0)
		fchild_proc(av[1], av[2], array_env, fds);
	child_id = fork();
	if (child_id == 0)
		schild_proc(av[4], av[3], array_env, fds);
	parent_proc(fds, id, child_id);
}
