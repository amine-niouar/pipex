/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:58:48 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/07 09:13:13 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_correct_path(char **paths, char *cmd)
{
	char	*full_path;
	int		len_path;
	int		i;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	len_path = max_len_tab(paths) + ft_strlen(cmd) + 2;
	full_path = malloc(len_path);
	if (!full_path)
		custom_error("Memory Allocation", 1);
	ft_bzero(full_path, len_path);
	i = -1;
	while (paths[++i])
	{
		if (append(&full_path, paths[i], cmd, len_path))
			return (full_path);
	}
	return (0);
}

char	*get_path_from_env(char **env, char *env_name)
{
	int	i;
	int	size_env;

	size_env = ft_strlen(env_name);
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], env_name, size_env) == 0)
			return (env[i]);
	}
	return (0);
}

void	catch_bad_fd(int fd)
{
	if (fd == -1)
	{
		perror("");
		exit (1);
	}
}
