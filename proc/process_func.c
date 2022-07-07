/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:49:40 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/06 04:25:01 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	fchild_proc(char *infile, char *fcmd, char ***array_env, int *fds)
{
	int		fd;
	char	**options;
	char	*correct_path;

	fd = open(infile, O_RDONLY);
	catch_bad_fd(fd);
	check_empty(fcmd);
	options = ft_split(fcmd, 32);
	correct_path = get_correct_path(array_env[0], options[0]);
	dup2(fd, STDIN_FILENO);
	close(fd);
	close(fds[0]);
	dup2(fds[1], STDOUT_FILENO);
	close(fds[1]);
	if (options[0] != 0)
		check_pass_path(options[0]);
	cmd_errror(correct_path);
	if (execve(correct_path, options, array_env[1]) == -1)
	{
		perror ("");
		exit (1);
	}
}

void	schild_proc(char *outfile, char *secmd, char ***array_env, int *fds)
{
	int		fd;
	char	**options;
	char	*correct_path;

	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	catch_bad_fd(fd);
	check_empty(secmd);
	options = ft_split(secmd, 32);
	correct_path = get_correct_path(array_env[0], options[0]);
	close(fds[1]);
	dup2(fds[0], STDIN_FILENO);
	close(fds[0]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (options[0] != 0)
		check_pass_path(options[0]);
	cmd_errror(correct_path);
	if (execve(correct_path, options, array_env[1]) == -1)
	{
		perror("");
		exit (1);
	}
}

void	parent_proc(int *fds, int fid, int sid)
{
	close(fds[0]);
	close(fds[1]);
	waitpid(fid, 0, 0);
	waitpid(sid, 0, 0);
}
