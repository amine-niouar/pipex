/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_file_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:02:29 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/04 16:34:06 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	append(char **full_path, char *path, char *cmd, int len_path)
{
	ft_strcat(*full_path, path);
	ft_strcat(*full_path, "/");
	ft_strcat(*full_path, cmd);
	if (access(*full_path, F_OK | X_OK) != -1)
		return (1);
	ft_bzero(*full_path, len_path);
	return (0);
}

void	check_empty(char *cmd)
{
	if (ft_strlen(cmd) == 0)
		custom_error("command not found", 1);
}

int	check_pass_path(char *cmd)
{
	if (ft_strpos(cmd, '/') != -1)
	{
		if (access(cmd, F_OK | X_OK) != -1)
			return (1);
		else
		{
			perror("");
			exit (1);
		}
	}
	return (0);
}
